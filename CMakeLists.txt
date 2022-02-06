cmake_minimum_required(VERSION 3.21)
project(phantom)

set(CMAKE_CXX_STANDARD 14)

find_package(JNI REQUIRED)
find_package (Threads REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${X11_INCLUDE_DIR})
link_libraries(${JNI_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${SDL2_LIBRARIES} ${CMAKE_DL_LIBS} ${OPENGL_gl_LIBRARY} OpenGL::GL ${X11_LIBRARIES})

set(PHANTOM_SOURCE_FILES src/mapping/impl/KeyBinding.cpp src/mapping/impl/KeyBinding.h src/mapping/impl/Mouse.cpp src/mapping/impl/Mouse.h src/ui/PhantomWindow.cpp src/ui/PhantomWindow.h src/cheats/AimBot.cpp src/cheats/AimBot.h src/library.cpp src/mapping/Mem.h src/mapping/CM.h src/mapping/AbstractClass.cpp src/mapping/AbstractClass.h src/Phantom.cpp src/Phantom.h src/mapping/Mapping.cpp src/mapping/Mapping.h src/mapping/impl/Entity.cpp src/mapping/impl/EntityPlayerSP.cpp src/mapping/impl/JavaList.cpp src/mapping/impl/JavaSet.cpp src/mapping/impl/Minecraft.cpp src/mapping/impl/WorldClient.cpp src/utils/MathHelper.cpp src/utils/MathHelper.h src/mapping/impl/JavaSystem.cpp src/mapping/impl/JavaSystem.h src/mapping/impl/JavaPrintStream.cpp src/mapping/impl/JavaPrintStream.h src/utils/JvmUtils.cpp src/utils/JvmUtils.h src/cheats/AutoClicker.cpp src/cheats/AutoClicker.h src/mapping/impl/GameSettings.cpp src/mapping/impl/GameSettings.h src/cheats/Cheat.cpp src/cheats/Cheat.h src/utils/MiscUtils.h src/utils/MiscUtils.cpp src/utils/XUtils.h src/utils/XUtils.cpp src/utils/MSTimer.cpp src/utils/MSTimer.h src/utils/ImGuiUtils.cpp src/utils/ImGuiUtils.h src/mapping/impl/EntityPlayer.cpp src/mapping/impl/EntityPlayer.h src/cheats/AimAssist.cpp src/cheats/AimAssist.h src/mapping/impl/EntityLivingBase.cpp src/mapping/impl/EntityLivingBase.h src/mapping/impl/Vec3.cpp src/mapping/impl/Vec3.h)

set(IMGUI_SOURCE_FILES src/vendor/imgui/imgui.cpp src/vendor/imgui/imgui_impl_opengl3.cpp src/vendor/imgui/imgui_impl_sdl.cpp src/vendor/imgui/imgui_draw.cpp src/vendor/imgui/imgui_tables.cpp src/vendor/imgui/imgui_widgets.cpp src/vendor/imgui/imgui_demo.cpp)

add_library(phantom SHARED ${IMGUI_SOURCE_FILES} ${PHANTOM_SOURCE_FILES})
