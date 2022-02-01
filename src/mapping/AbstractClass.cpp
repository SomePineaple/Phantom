//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "AbstractClass.h"

#include "../utils/JvmUtils.h"

AbstractClass::AbstractClass(Phantom *phantom, const char *clsName) {
    this->phantom = phantom;
    this->clsKey = clsName;

    //Find each class that inherits AbstractClass by the class name provided
    cls = getClass(Mapping::getClassName(clsName));

    //Check for exceptions. I got lazy, and this is the only time I actually check for errors
    //Basically, checks if there's an error, prints the stack trace to the console, then clears the error
    JvmUtils::checkJavaErrors(phantom);
}

jobject AbstractClass::getClassLoader() {
    jclass launch = phantom->getEnv()->FindClass("net/minecraft/launchwrapper/Launch");
    jfieldID sfid = phantom->getEnv()->GetStaticFieldID(launch, "classLoader", "Lnet/minecraft/launchwrapper/LaunchClassLoader;");
    jobject classLoader = phantom->getEnv()->GetStaticObjectField(launch, sfid);

    return classLoader;
}

jclass AbstractClass::getClass(const char *clsName) {
    jstring name = phantom->getEnv()->NewStringUTF(clsName);
    jobject classLoader = getClassLoader();
    jmethodID mid = phantom->getEnv()->GetMethodID(phantom->getEnv()->GetObjectClass(classLoader), "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
    return (jclass)phantom->getEnv()->CallObjectMethod(classLoader, mid, name);
}

jclass AbstractClass::getClass() {
    return cls;
}
