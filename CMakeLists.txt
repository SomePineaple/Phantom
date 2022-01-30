cmake_minimum_required(VERSION 3.21)
project(mc_injection)

set(CMAKE_CXX_STANDARD 14)

find_package(JNI REQUIRED)
find_package (Threads REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})
link_libraries(${JNI_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${SDL2_LIBRARIES} ${CMAKE_DL_LIBS} ${OPENGL_gl_LIBRARY} OpenGL::GL)

set(IMGUI_SOURCE_FILES src/vendor/imgui/imgui.cpp src/vendor/imgui/imgui_impl_opengl3.cpp src/vendor/imgui/imgui_impl_sdl.cpp src/vendor/imgui/imgui_draw.cpp src/vendor/imgui/imgui_tables.cpp src/vendor/imgui/imgui_widgets.cpp src/vendor/imgui/imgui_demo.cpp src/ui/Window.cpp src/ui/Window.h)

add_library(mc_injection SHARED ${IMGUI_SOURCE_FILES} src/library.cpp src/mapping/Mem.h src/mapping/CM.h src/mapping/AbstractClass.cpp src/mapping/AbstractClass.h src/Phantom.cpp src/Phantom.h src/mapping/Mapping.cpp src/mapping/Mapping.h src/mapping/impl/Entity.cpp src/mapping/impl/EntityPlayerSP.cpp src/mapping/impl/JavaList.cpp src/mapping/impl/JavaSet.cpp src/mapping/impl/Minecraft.cpp src/mapping/impl/WorldClient.cpp src/utils/MathHelper.cpp src/utils/MathHelper.h src/mapping/impl/JavaSystem.cpp src/mapping/impl/JavaSystem.h src/mapping/impl/JavaPrintStream.cpp src/mapping/impl/JavaPrintStream.h src/utils/JvmUtils.cpp src/utils/JvmUtils.h src/Platform.h)
