#include "PhantomWindow.h"

#include <SDL_opengl.h>
#include "../utils/ImGuiUtils.h"

#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_opengl3.h>

PhantomWindow::PhantomWindow(int width, int height, const char *title) {
    this->width = width;
    this->height = height;
    this->title = title;

    style = 0;

    window = nullptr;
    glContext = nullptr;
}

void Colors( ) {
    ImGuiStyle& style = ImGui::GetStyle();

    style.Colors[ImGuiCol_WindowBg] = ImColor(48, 37, 70);
    style.Colors[ImGuiCol_ChildBg] = ImColor(40, 31, 56);
    style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
    style.Colors[ImGuiCol_Button] = ImColor(160, 65, 84);
    
}
void Title( ) {
    std::string text = "Phantom";
    ImGui::SetWindowFontScale(2);
    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth   = ImGui::CalcTextSize(text.c_str()).x;
    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);

    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0,255,0,255));

    ImGui::Text("Phantom");
    ImGui::SetWindowFontScale(1);
    ImGui::PopStyleColor();
}
void AlignForWidth(float width, float alignment = 0.5f) {
    ImGuiStyle& style = ImGui::GetStyle();
    float avail = ImGui::GetContentRegionAvail().x;
    float off = (avail - width) * alignment;
    if (off > 0.0f)
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
}
void PhantomWindow::setup() {
    // Setup SDL
    // (Some versions of SDL before <2.0.10 appears to have performance/stalling issues on a minority of Windows systems,
    // depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL is recommended!)
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        printf("Error: %s\n", SDL_GetError());
        exit(1);
    }

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    auto window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);
    glContext = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, glContext);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGuiUtils::styleColorsGold();
    ImGui::GetStyle().WindowRounding = 0.0f;

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    ImGui_ImplOpenGL3_Init(glsl_version);
    
}
std::string CurrentMenu = "Nothing";
int Tab = 2;
void PhantomWindow::update(const std::vector<Cheat*>& cheats, bool &running, bool inGame) {
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);
        if (event.type == SDL_QUIT)
            running = false;
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
            running = false;
    }

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
    
    // Draw widgets
    {
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y));
        ImGui::Begin("Phantom Settings", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
        ImGui::SetCursorPos(ImVec2(35,90));
        ImGui::BeginChild("Sidebar", ImVec2(140,344), true);
        if (Tab == 1 && inGame){
            for (Cheat *cheat : cheats) {
            if(ImGui::Button(cheat->getName(), ImVec2(130,25))) {
                CurrentMenu = cheat->getName();
            }
            if (ImGui::IsItemHovered()) {
                ImGui::SameLine();
                ImGuiUtils::drawHelper(cheat->getDescription());
            }
                    
            }
        }
        ImGui::EndChild();
        
        ImGui::SetCursorPos(ImVec2(185,90));
        ImGui::BeginChild("Settings", ImVec2(495,344), true);
        if (Tab == 1) {
            if (inGame) {
                ImGui::Text("Cheats:");
                for (Cheat *cheat : cheats) {
                    
                    if (CurrentMenu == cheat->getName()) {
                        ImGui::Checkbox(cheat->getName(), &cheat->enabled);
                        std::string description = cheat->getName();
                        description.append(": Settings");
                        
                        // if (ImGui::CollapsingHeader(description.c_str())) {
                        //    ImGui::Indent(15);
                        cheat->renderSettings();
                        if (ImGui::Button("Bind")){
                            cheat->binding = true;
                        }
                        ImGui::SameLine();
                        if (cheat->binding){
                            ImGui::Text("Bind: <...>");
                        }else{
                            ImGui::Text("Bind: <%d>", cheat->bind);
                        }
                        //
                        
                    }
                } }   
            } else {
                ImGui::Text("Please join a world");
            }

            
        if (Tab == 2) {
            XUtils::renderMouseSelector();
            XUtils::renderKeyboardSelector();
            if (ImGui::Combo("Style", &style, "Gold\0Cinder\0Light\0Dark\0Classic\0Custom\0")) {
                switch(style) {
                    case 0:
                        ImGuiUtils::styleColorsGold();
                        break;
                    case 1:
                        ImGui::StyleColorsCinder();
                        break;
                    case 2:
                        ImGui::StyleColorsLight();
                        break;
                    case 3:
                        ImGui::StyleColorsDark();
                        break;
                    case 4:
                        ImGui::StyleColorsClassic();
                        break;
                    case 5:
                        Colors();
                        break;
                }

            ImGui::GetStyle().WindowRounding = 0;
            }
            }
        ImGui::EndChild();

        ImGui::SetCursorPos(ImVec2(200,35));
        ImGui::BeginChild("Topbar", ImVec2(282,49), true);
        ImGuiStyle& Style = ImGui::GetStyle();
        float width = 0.0f;
        width += ImGui::CalcTextSize("Cheats").x;
        width += Style.ItemSpacing.x;
        width += ImGui::CalcTextSize("Settings").x;
        AlignForWidth(width);
        if (ImGui::Button("Cheats")) {
            Tab = 1;
        }
        ImGui::SameLine();
        if (ImGui::Button("Settings")) {
            Tab = 2;
        }

        ImGui::EndChild();

        ImGui::SetCursorPos(ImVec2(50,50));
        ImGui::Text("Phantom");
        ImGui::End();
    }
/*   Title();
        ImGui::Dummy(ImVec2(0, 10));
        ImGui::BeginChild("Buttons", ImVec2(0.0f, 0.0f));
        ImGuiStyle& Style = ImGui::GetStyle();
        float width = 0.0f;
        ImGui::SetWindowFontScale(1.2f);
        width += ImGui::CalcTextSize("Cheats").x;
        width += Style.ItemSpacing.x;
        width += ImGui::CalcTextSize("Settings").x;
        AlignForWidth(width);
        if (ImGui::Button("Cheats")) {
            Tab = 1;
        } Style.ItemSpacing.x = 1;
       
        ImGui::SameLine();
        if (ImGui::Button("Settings")) {
            Tab = 2;
        }

        ImGui::SetWindowFontScale(1);
        ImGui::Dummy(ImVec2(0,10.0f));
    
        ImGui::EndChild();


        


        
        ImGui::End();
    
 */
        
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
}

void PhantomWindow::destruct() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}