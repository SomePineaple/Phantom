//
// Created by somepineaple on 1/25/22.
//

#ifndef MC_INJECTION_MAPPING_H
#define MC_INJECTION_MAPPING_H

#include <map>
#include <string>
#include "CM.h"
#include "Mem.h"
#include <iostream>

// Map of class names to mapping structures
extern std::map<std::string, CM*> lookup;

class Mapping {
public:
    Mapping() {
        // Populate the map
        setup();
    }

    static CM* getClass(const char* key) {
        CM* cm = lookup.at(std::string(key));
        return cm;
    }

    static const char* getClassName(const char* key) {
        return getClass(key)->name;
    }
    static void setup() {
        // How to define mappings:
        // --- Unobfuscated classes:
        //
        //   Creating mappings for a class:
        //
        //                SimpleID,    InternalName
        //       m = make("Set",       "java/util/Set");
        //
        //   Adding a member to the class:
        //              MappingInst,   MethodName,  InternalDescriptor,       IsStatic
        //       method(m,             "get",       "(I)Ljava/lang/Object;",  false);
        //
        // -------------------------
        //
        // base - normal jvm classes
        struct CM* m = make("List", "java/util/List");
        method(m, "get", "(I)Ljava/lang/Object;", false);
        method(m, "toArray", "()[Ljava/lang/Object;", false);
        method(m, "size", "()I", false);
        m = make("Set", "java/util/Set");
        method(m, "toArray", "()[Ljava/lang/Object;", false);
        method(m, "size", "()I", false);
        m = make("System", "java/lang/System");
        field(m, "out", "Ljava/io/PrintStream;", true);
        m = make("PrintStream", "java/io/PrintStream");
        method(m, "println", "(Ljava/lang/String;)V", false);
        // How to define mappings:
        // --- Obfuscated classes:
        //
        //   Creating mappings for a class:
        //
        //                SimpleID,    ObfuscatedName
        //       m = make("Entity",    "v");
        //
        //   Adding a member to the class:
        //              MappingInst,   SimpleID, ObfuscatedName, ObfuscatedDescriptor,  IsStatic
        //       method(m,             "getID",  "S",            "()I",                 false);
        //
        // -----------------------------------
        //
        // obfuscated minecraft classes - 1.12
        m = make("Entity", "ve");
        field(m, "x", "p", "D", false);
        field(m, "y", "q", "D", false);
        field(m, "z", "r", "D", false);
        method(m, "getID", "S", "()I", false);
        method(m, "getName", "h_", "()Ljava/lang/String;", false);
        m = make("WorldClient", "brz");
        field(m, "entities", "K", "Ljava/util/Set;", false);
        method(m, "setTime", "b", "(J)V", false);
        m = make("PlayerSP", "bub");
        field(m, "x", "p", "D", false);
        field(m, "y", "q", "D", false);
        field(m, "z", "r", "D", false);
        field(m, "yaw", "v", "F", false);
        field(m, "pitch", "w", "F", false);
        method(m, "getID", "S", "()I", false);
        method(m, "getName", "h_", "()Ljava/lang/String;", false);
        method(m, "setSprint", "f", "(Z)V", false);
        m = make("Minecraft", "bhz");
        field(m, "player", "h", "Lbub;", false);
        field(m, "world", "f", "Lbrz;", false);
        method(m, "getMinecraft", "z", "()Lbhz;", true);
    }
private:
    static void field(CM *cm, const char* name, const char* desc, bool isStatic) {
        field(cm, name, name, desc, isStatic);
    }

    static void method(CM *cm, const char* name, const char* desc, bool isStatic) {
        method(cm, name, name, desc, isStatic);
    }

    static void field(CM *cm, const char* keyName, const char* obName, const char* desc, bool isStatic) {
        std::cout << "  Mapping " << obName << " to " << keyName << std::endl;
        Mem *m = new Mem(obName, desc, isStatic);
        cm->fields.insert(std::make_pair(std::string(keyName), *m));
    }

    static void method(CM *cm, const char* keyName, const char* obName, const char* desc, bool isStatic) {
        std::cout << "  Mapping " << obName << desc << " to " << keyName << std::endl;
        Mem *m = new Mem(obName, desc, isStatic);
        cm->methods.insert(std::make_pair(std::string(keyName), *m));
    }

    static CM* make(const char* key, const char* name) {
        //struct CM cm(name);
        auto *cm = new CM(name);
        std::cout << "Mapping " << name << " to " << key << std::endl;
        lookup.insert(std::make_pair(std::string(key), cm));
        return cm;
    }
};


#endif //MC_INJECTION_MAPPING_H
