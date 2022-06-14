# Phantom

Fully C++ Minecraft injection client for linux. Mapping code is based off of
[UDP](https://github.com/UnknownDetectionParty/UDP-CPP), and [Dear ImGui](https://github.com/ocornut/imgui) is used
for the window, but the cheats and stuff are my own.

We also now have a [discord server](https://discord.gg/2pZYVqnV)

### Different MC Versions

By default, Phantom is configured to build for version 1.8.9 forge. If you want other versions, edit the `Mapping.cpp` 
file in the `src/mappings` directory.

### Building

To build, make sure you have cmake installed, as well as a JDK. I was having issues with openjdk 1.8, I would recommend 
installing the latest version of openjdk. CMake will automatically find the files associated and link with them. You 
also need the development headers for SDL2 and OpenGL.

### Injecting into Minecraft

To inject, you need some form of shared object / dll injector for linux. I made one specifically for this project which
you can find [here](https://github.com/SomePineaple/Phantom-Injector).

## Video Tutorial
If you want a video on how to use the client, check [this](https://youtu.be/NoA4psrEZsQ) out.
