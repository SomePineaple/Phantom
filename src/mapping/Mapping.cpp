//
// Some of this code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "Mapping.h"

std::map<std::string, CM*> lookup;

CM *Mapping::getClass(const char *key)  {
    CM* cm = lookup.at(std::string(key));
    return cm;
}

const char *Mapping::getClassName(const char *key)  {
    return getClass(key)->name;
}

void Mapping::setup() {
    // PLEASE USE https://github.com/bspkrs/MCPMappingViewer 1.8.9 stable!!!!!!!!!!!!

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


    struct CM* m = make("List", "java.util.List");
    method(m, "get", "(I)Ljava/lang/Object;", false);
    method(m, "toArray", "()[Ljava/lang/Object;", false);
    method(m, "size", "()I", false);

    m = make("Set", "java.util.Set");
    method(m, "toArray", "()[Ljava/lang/Object;", false);
    method(m, "size", "()I", false);

    m = make("System", "java.lang.System");
    field(m, "out", "Ljava/io/PrintStream;", true);

    m = make("PrintStream", "java.io.PrintStream");
    method(m, "println", "(Ljava/lang/String;)V", false);

    m = make("Mouse", "org.lwjgl.input.Mouse");
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
    // obfuscated minecraft classes - 1.8.9 forge

    m = make("Entity", "net.minecraft.entity.Entity");
    field(m, "x", "field_70165_t", "D", false);
    field(m, "lastTickPosX", "field_70142_S", "D", false);
    field(m, "y", "field_70163_u", "D", false);
    field(m, "z", "field_70161_v", "D", false);
    field(m, "lastTickPosZ", "field_70136_U", "D", false);
    field(m, "ridingEntity", "field_70154_o", "Lnet/minecraft/entity/Entity;", false);
    method(m, "getEyeHeight", "func_70047_e", "()F", false);
    method(m, "getID", "func_145782_y", "()I", false);
    method(m, "getName", "func_70005_c_", "()Ljava/lang/String;", false);
    method(m, "rayTrace", "func_174822_a", "(FD)Lnet/minecraft/util/math/RayTraceResult;", false);
    method(m, "getPositionEyes", "func_174824_e", "(F)Lnet/minecraft/util/Vec3;", false);
    method(m, "getLook", "func_70676_i", "(F)Lnet/minecraft/util/Vec3;", false);
    method(m, "getEntityBoundingBox", "func_174813_aQ", "()Lnet/minecraft/util/AxisAlignedBB;", false);
    method(m, "getCollisionBorderSize", "func_70111_Y", "()F", false);
    method(m, "canBeCollidedWith", "func_70067_L", "()Z", false);
    // For some reason this method doesn't appear to be obfuscated. IDK why
    method(m, "canRiderInteract", "()Z", false);

    m = make("WorldClient", "net.minecraft.client.multiplayer.WorldClient");
    field(m, "entities", "field_72996_f", "Ljava/util/List;", false);
    field(m, "players", "field_73010_i", "Ljava/util/List;", false);
    method(m, "setTime", "func_72877_b", "(J)V", false);
    method(m, "getEntitiesWithinAABBExcluding", "func_72839_b", "(Lnet/minecraft/entity/Entity;Lnet/minecraft/util/AxisAlignedBB;)Ljava/util/List;", false);

    m = make("PlayerControllerMP", "net.minecraft.client.multiplayer.PlayerControllerMP");
    /* field(m, "isHittingBlock" "field_78778_j", "Z", false); */
    /* method(m, "getIsHittingBlock", "func_181040_m", "()Z", false); */

    m = make("PlayerSP", "net.minecraft.client.entity.EntityPlayerSP");
    // field_70138_W, field_70145_X do these later
    field(m, "x", "field_70165_t", "D", false);
    field(m, "y", "field_70163_u", "D", false);
    field(m, "z", "field_70161_v", "D", false);
    field(m, "yaw", "field_70177_z", "F", false);
    field(m, "pitch", "field_70125_A", "F", false);
    field(m, "width", "field_70130_N", "F", false);
    field(m, "height", "field_70131_O", "F", false);
    field(m, "motionX", "field_70159_w", "D", false);
    field(m, "motionY", "field_70181_x", "D", false);
    field(m, "motionZ", "field_70179_y", "D", false);
    field(m, "hurtTime", "field_70737_aN", "I", false);
    field(m, "maxHurtTime", "field_70738_aO", "I", false);
    method(m, "setPosition", "func_70107_b", "(DDD)V", false);
    method(m, "setVelocity", "func_70016_h", "(DDD)V", false); // maybe shoudl be in entity
    method(m, "getPositionVector", "func_174791_d", "()Lnet/minecraft/util/Vec3;", false);
    method(m, "getLook", "func_70676_i", "(F)Lnet/minecraft/util/Vec3;", false);
    method(m, "getID", "func_145782_y", "()I", false);
    method(m, "getEyeHeight", "func_70047_e", "()F", false);
    method(m, "getName", "func_70005_c_", "()Ljava/lang/String;", false);
    method(m, "setSprint", "func_70031_b", "(Z)V", false);
    method(m, "getDisplayName", "func_145748_c_", "()Lnet/minecraft/util/IChatComponent;", false);

    m = make("KeyBinding", "net.minecraft.client.settings.KeyBinding");
    method(m, "setKeyBindState", "func_74510_a", "(IZ)V", true);
    method(m, "onTick", "func_74507_a", "(I)V", true);
    method(m, "getKeyCode", "func_151463_i", "()I", false);

    m = make("GameSettings", "net.minecraft.client.settings.GameSettings");
    field(m, "keyBindAttack", "field_74312_F", "Lnet/minecraft/client/settings/KeyBinding;", false);
    field(m, "keyBindBack", "field_74368_y", "Lnet/minecraft/client/settings/KeyBinding;", false);

    m = make("Minecraft", "net.minecraft.client.Minecraft");
    field(m, "player", "field_71439_g", "Lnet/minecraft/client/entity/EntityPlayerSP;", false);
    field(m, "world", "field_71441_e", "Lnet/minecraft/client/multiplayer/WorldClient;", false);
    field(m, "playerController", "field_71442_b", "Lnet/minecraft/client/multiplayer/PlayerControllerMP", false);
    field(m, "gameSettings", "field_71474_y", "Lnet/minecraft/client/settings/GameSettings;", false);
    field(m, "inGameHasFocus", "field_71415_G", "Z", false);
    field(m, "pointedEntity", "field_147125_j", "Lnet/minecraft/entity/Entity;", false);
    field(m, "objectMouseOver", "field_71476_x", "Lnet/minecraft/util/math/RayTraceResult;", false);
    field(m, "timer", "field_71428_T", "Lnet/minecraft/util/Timer;", false);
    field(m, "rightClickDelayTimer", "field_71467_ac", "I", false);
    field(m, "entityRenderer", "field_71460_t", "Lnet/minecraft/client/renderer/EntityRenderer;", false);
    field(m, "leftClickMouse", "field_71429_W", "I", false);
    method(m, "getRenderViewEntity", "func_175606_aa", "()Lnet/minecraft/entity/Entity;", false);
    method(m, "getMinecraft", "func_71410_x", "()Lnet/minecraft/client/Minecraft;", true);

    m = make("EntityLivingBase", "net.minecraft.entity.EntityLivingBase");
    field(m, "x", "field_70165_t", "D", false);
    field(m, "lastTickPosX", "field_70142_S", "D", false);
    field(m, "y", "field_70163_u", "D", false);
    field(m, "z", "field_70161_v", "D", false);
    field(m, "lastTickPosZ", "field_70136_U", "D", false);
    method(m, "getEyeHeight", "func_70047_e", "()F", false);
    method(m, "getID", "func_145782_y", "()I", false);
    method(m, "getName", "func_70005_c_", "()Ljava/lang/String;", false);

    m = make("EntityPlayer", "net.minecraft.entity.player.EntityPlayer");
    field(m, "x", "field_70165_t", "D", false);
    field(m, "lastTickPosX", "field_70142_S", "D", false);
    field(m, "y", "field_70163_u", "D", false);
    field(m, "z", "field_70161_v", "D", false);
    field(m, "lastTickPosZ", "field_70136_U", "D", false);
    field(m, "yaw", "field_70177_z", "F", false);
    field(m, "pitch", "field_70125_A", "F", false);
    method(m, "getEyeHeight", "func_70047_e", "()F", false);
    method(m, "getID", "func_145782_y", "()I", false);
    method(m, "getName", "func_70005_c_", "()Ljava/lang/String;", false);
    method(m, "setSprint", "func_70031_b", "(Z)V", false);
    method(m, "getDisplayName", "func_145748_c_", "()Lnet/minecraft/util/IChatComponent;", false);
    method(m, "getEntityBoundingBox", "func_174813_aQ", "()Lnet/minecraft/util/AxisAlignedBB;", false);

    m = make("Vec3", "net.minecraft.util.Vec3");
    field(m, "xCoord", "field_72450_a", "D", false);
    field(m, "yCoord", "field_72448_b", "D", false);
    field(m, "zCoord", "field_72449_c", "D", false);
    method(m, "addVector", "func_72441_c", "(DDD)Lnet/minecraft/util/Vec3;", false);
    method(m, "distanceTo", "func_72438_d", "(Lnet/minecraft/util/Vec3;)D", false);

    m = make("AxisAlignedBB", "net.minecraft.util.AxisAlignedBB");
    method(m, "addCoord", "func_72321_a", "(DDD)Lnet/minecraft/util/AxisAlignedBB;", false);
    method(m, "expand", "func_72314_b", "(DDD)Lnet/minecraft/util/AxisAlignedBB;", false);
    method(m, "calculateIntercept", "func_72327_a", "(Lnet/minecraft/util/Vec3;Lnet/minecraft/util/Vec3;)Lnet/minecraft/util/MovingObjectPosition;", false);
    method(m, "isVecInside", "func_72318_a", "(Lnet/minecraft/util/Vec3;)Z", false);
    field(m, "maxX", "field_72336_d", "D", false);
    field(m, "maxY", "field_72337_e", "D", false);
    field(m, "maxZ", "field_72334_f", "D", false);
    field(m, "minX", "field_72340_a", "D", false);
    field(m, "minY", "field_72338_b", "D", false);
    field(m, "minZ", "field_72339_c", "D", false);

    m = make("MovingObjectPosition", "net.minecraft.util.MovingObjectPosition");
    field(m, "hitVec", "field_72307_f", "Lnet/minecraft/util/Vec3;", false);

    m = make("Timer", "net.minecraft.util.Timer");
    field(m, "partialTicks", "field_74281_c", "F", false);

    m = make("EntityRenderer", "net.minecraft.client.renderer.EntityRenderer");
    field(m, "pointedEntity", "field_78528_u", "Lnet/minecraft/entity/Entity;");
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
