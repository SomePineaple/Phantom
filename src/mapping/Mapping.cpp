//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "Mapping.h"
#include "../Platform.h"

std::map<std::string, CM*> lookup;

CM *Mapping::getClass(const char *key)  {
    CM* cm = lookup.at(std::string(key));
    return cm;
}

const char *Mapping::getClassName(const char *key)  {
    return getClass(key)->name;
}

void Mapping::setup() {
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
    m = make("Mouse", "org/lwjgl/input/Mouse");
    method(m, "isButtonDown", "(I)Z", true);

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
#ifdef MC_1_12
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
    m = make("KeyBinding", "bhw");
    method(m, "setKeyBindState", "a", "(IZ)V", true);
    method(m, "onTick", "a", "(I)V", true);
    method(m, "getKeyCode", "j", "()I", false);
    m = make("GameSettings", "bib");
    field(m, "keyBindAttack", "ae", "Lbhw;", false);
    m = make("Minecraft", "bhz");
    field(m, "player", "h", "Lbub;", false);
    field(m, "world", "f", "Lbrz;", false);
    field(m, "gameSettings", "t", "Lbib;", false);
    method(m, "getMinecraft", "z", "()Lbhz;", true);
#endif
    // obfuscated minecraft classes - 1.8.8
#ifdef MC_1_8_8
    m = make("Entity", "pk");
    field(m, "x", "s", "D", false);
    field(m, "y", "t", "D", false);
    field(m, "z", "u", "D", false);
    method(m, "getID", "F", "()I", false);
    method(m, "getName", "e_", "()Ljava/lang/String;", false);
    m = make("WorldClient", "bdb");
    field(m, "entities", "c", "Ljava/util/Set;", false);
    method(m, "setTime", "b", "(J)V", false);
    m = make("PlayerSP", "bew");
    field(m, "x", "s", "D", false);
    field(m, "y", "t", "D", false);
    field(m, "z", "u", "D", false);
    field(m, "yaw", "y", "F", false);
    field(m, "pitch", "z", "F", false);
    method(m, "getID", "F", "()I", false);
    method(m, "getName", "e_", "()Ljava/lang/String;", false);
    method(m, "setSprint", "d", "(Z)V", false);
    m = make("KeyBinding", "avb");
    method(m, "setKeyBindState", "a", "(IZ)V", true);
    method(m, "onTick", "a", "(I)V", true);
    method(m, "getKeyCode", "i", "()I", false);
    m = make("GameSettings", "avh");
    field(m, "keyBindAttack", "ah", "Lavb;", false);
    m = make("Minecraft", "ave");
    field(m, "player", "h", "Lbew;", false);
    field(m, "world", "f", "Lbdb;", false);
    field(m, "gameSettings", "t", "Lavh;", false);
    method(m, "getMinecraft", "A", "()Lave;", true);
#endif
}

void Mapping::field(CM *cm, const char* name, const char* desc, bool isStatic) {
    field(cm, name, name, desc, isStatic);
}

void Mapping::method(CM *cm, const char* name, const char* desc, bool isStatic) {
    method(cm, name, name, desc, isStatic);
}

void Mapping::field(CM *cm, const char* keyName, const char* obName, const char* desc, bool isStatic) {
    std::cout << "  Mapping " << obName << " to " << keyName << std::endl;
    Mem *m = new Mem(obName, desc, isStatic);
    cm->fields.insert(std::make_pair(std::string(keyName), *m));
}

void Mapping::method(CM *cm, const char* keyName, const char* obName, const char* desc, bool isStatic) {
    std::cout << "  Mapping " << obName << desc << " to " << keyName << std::endl;
    Mem *m = new Mem(obName, desc, isStatic);
    cm->methods.insert(std::make_pair(std::string(keyName), *m));
}

CM* Mapping::make(const char* key, const char* name) {
    //struct CM cm(name);
    auto *cm = new CM(name);
    std::cout << "Mapping " << name << " to " << key << std::endl;
    lookup.insert(std::make_pair(std::string(key), cm));
    return cm;
}
