cmake_minimum_required(VERSION 3.21)
project(mc_injection)

set(CMAKE_CXX_STANDARD 14)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
link_libraries(${JNI_LIBRARIES})

add_library(mc_injection SHARED src/library.cpp src/mapping/Mem.h src/mapping/CM.h src/mapping/AbstractClass.cpp src/mapping/AbstractClass.h src/UDP.cpp src/UDP.h src/mapping/Mapping.cpp src/mapping/Mapping.h src/mapping/impl/Entity.cpp src/mapping/impl/EntityPlayerSP.cpp src/mapping/impl/JavaList.cpp src/mapping/impl/JavaSet.cpp src/mapping/impl/Minecraft.cpp src/mapping/impl/WorldClient.cpp src/utils/MathHelper.cpp src/utils/MathHelper.h)
