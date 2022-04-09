cmake_minimum_required(VERSION 3.21)
project(phantom)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE -O3)
set(CMAKE_CXX_FLAGS_DEBUG -Wall -Wextra)

find_package(JNI REQUIRED)
find_package (Threads REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${X11_INCLUDE_DIR} src/mapping/impl)
link_libraries(${JNI_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${SDL2_LIBRARIES} ${CMAKE_DL_LIBS} ${OPENGL_gl_LIBRARY} OpenGL::GL ${X11_LIBRARIES})

set(PHANTOM_SOURCE_FILES src/mapping/impl/net/minecraft/client/settings/KeyBinding.cpp src/mapping/impl/net/minecraft/client/settings/KeyBinding.h src/mapping/impl/org/lwjgl/input/Mouse.cpp src/mapping/impl/org/lwjgl/input/Mouse.h src/ui/PhantomWindow.cpp src/ui/PhantomWindow.h src/cheats/AimBot.cpp src/cheats/AimBot.h src/library.cpp src/mapping/Mem.h src/mapping/CM.h src/mapping/AbstractClass.cpp src/mapping/AbstractClass.h src/Phantom.cpp src/Phantom.h src/mapping/Mapping.cpp src/mapping/Mapping.h src/mapping/impl/net/minecraft/entity/Entity.cpp src/mapping/impl/net/minecraft/entity/EntityPlayerSP.cpp src/mapping/impl/java/util/JavaList.cpp src/mapping/impl/java/util/JavaSet.cpp src/mapping/impl/net/minecraft/client/Minecraft.cpp src/mapping/impl/net/minecraft/client/multiplayer/WorldClient.cpp src/utils/MathHelper.cpp src/utils/MathHelper.h src/mapping/impl/java/lang/JavaSystem.cpp src/mapping/impl/java/lang/JavaSystem.h src/mapping/impl/java/io/JavaPrintStream.cpp src/mapping/impl/java/io/JavaPrintStream.h src/utils/JvmUtils.cpp src/utils/JvmUtils.h src/cheats/AutoClicker.cpp src/cheats/AutoClicker.h src/mapping/impl/net/minecraft/client/settings/GameSettings.cpp src/mapping/impl/net/minecraft/client/settings/GameSettings.h src/cheats/Cheat.cpp src/cheats/Cheat.h src/utils/MiscUtils.h src/utils/MiscUtils.cpp src/utils/XUtils.h src/utils/XUtils.cpp src/utils/MSTimer.cpp src/utils/MSTimer.h src/utils/ImGuiUtils.cpp src/utils/ImGuiUtils.h src/mapping/impl/net/minecraft/entity/player/EntityPlayer.cpp src/mapping/impl/net/minecraft/entity/player/EntityPlayer.h src/cheats/AimAssist.cpp src/cheats/AimAssist.h src/mapping/impl/net/minecraft/entity/EntityLivingBase.cpp src/mapping/impl/net/minecraft/entity/EntityLivingBase.h src/mapping/impl/net/minecraft/util/Vec3.cpp src/mapping/impl/net/minecraft/util/Vec3.h src/mapping/impl/net/minecraft/util/AxisAlignedBB.cpp src/mapping/impl/net/minecraft/util/AxisAlignedBB.h src/mapping/impl/net/minecraft/util/MovingObjectPosition.cpp src/mapping/impl/net/minecraft/util/MovingObjectPosition.h src/utils/MCUtils.cpp src/utils/MCUtils.h src/cheats/Reach.cpp src/cheats/Reach.h src/mapping/impl/net/minecraft/util/Timer.cpp src/mapping/impl/net/minecraft/util/Timer.h src/mapping/impl/net/minecraft/client/renderer/EntityRenderer.cpp src/mapping/impl/net/minecraft/client/renderer/EntityRenderer.h)

set(IMGUI_SOURCE_FILES src/vendor/imgui/imgui.cpp src/vendor/imgui/imgui_impl_opengl3.cpp src/vendor/imgui/imgui_impl_sdl.cpp src/vendor/imgui/imgui_draw.cpp src/vendor/imgui/imgui_tables.cpp src/vendor/imgui/imgui_widgets.cpp src/vendor/imgui/imgui_demo.cpp)

add_library(phantom SHARED ${IMGUI_SOURCE_FILES} ${PHANTOM_SOURCE_FILES})
