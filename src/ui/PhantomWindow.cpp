//
// Created by somepineaple on 1/30/22.
//

#include "PhantomWindow.h"

#include <SDL_opengl.h>
#include "../utils/ImGuiUtils.h"
#include "../utils/XUtils.h"

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

        XUtils::renderMouseSelector();
        XUtils::renderKeyboardSelector();

        if (ImGui::Combo("Style", &style, "Gold\0Cinder\0Light\0Dark\0Classic\0")) {
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
            }

            ImGui::GetStyle().WindowRounding = 0;
        }

        if (inGame) {
            ImGui::Text("Cheats:");

            for (Cheat *cheat : cheats) {
                ImGui::Checkbox(cheat->getName(), &cheat->enabled);
                if (strlen(cheat->getDescription()) > 0) {
                    ImGui::SameLine();
                    ImGuiUtils::drawHelper(cheat->getDescription());
                }

                if (cheat->enabled) {
                    std::string description = cheat->getName();
                    description.append(": Settings");

                    if (ImGui::CollapsingHeader(description.c_str())) {
                        ImGui::Indent(15);
                        cheat->renderSettings();
                        ImGui::Unindent(15);
                    }
                }
            }
        } else {
            ImGui::Text("Please join a world");
        }

        if (ImGui::Button("Destruct"))
            running = false;

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }

    // Rendering
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
