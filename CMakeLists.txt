cmake_minimum_required(VERSION 3.21)
project(mc_injection)

set(CMAKE_CXX_STANDARD 14)

find_package(JNI REQUIRED)
find_package (Threads REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
link_libraries(${JNI_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_library(mc_injection SHARED src/library.cpp src/mapping/Mem.h src/mapping/CM.h src/mapping/AbstractClass.cpp src/mapping/AbstractClass.h src/Phantom.cpp src/Phantom.h src/mapping/Mapping.cpp src/mapping/Mapping.h src/mapping/impl/Entity.cpp src/mapping/impl/EntityPlayerSP.cpp src/mapping/impl/JavaList.cpp src/mapping/impl/JavaSet.cpp src/mapping/impl/Minecraft.cpp src/mapping/impl/WorldClient.cpp src/utils/MathHelper.cpp src/utils/MathHelper.h src/mapping/impl/JavaSystem.cpp src/mapping/impl/JavaSystem.h src/mapping/impl/JavaPrintStream.cpp src/mapping/impl/JavaPrintStream.h src/utils/JvmUtils.cpp src/utils/JvmUtils.h)
