//
// Created by somepineaple on 1/25/22.
//

#ifndef MC_INJECTION_ABSTRACTCLASS_H
#define MC_INJECTION_ABSTRACTCLASS_H

#include "jvmti.h"
#include "CM.h"
#include "../UDP.h"

class AbstractClass {
public:
    AbstractClass(UDP * udp, const char * clsName);

    //This stuff is just to make using JNI easier (it's already easy, just likes to be easier)
    //It doesn't cover everything, but covers most basic shit

    //Boolean
    template <class T> jboolean getBoolean(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallBooleanMethod(parent, method, values); }
    template <class T> jboolean getBoolean(jmethodID method, T values...) { return udp->getEnv()->CallStaticBooleanMethod(cls, method, values); }
    jboolean getBoolean(jobject parent, jmethodID method) { return udp->getEnv()->CallBooleanMethod(parent, method); }
    jboolean getBoolean(jmethodID method) { return udp->getEnv()->CallStaticBooleanMethod(cls, method); }
    jboolean getBoolean(jobject parent, jfieldID field) { return udp->getEnv()->GetBooleanField(parent, field); }
    jboolean getBoolean(jfieldID field) { return udp->getEnv()->GetStaticBooleanField(cls, field); }

    //Byte
    template <class T> jbyte getByte(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallByteMethod(parent, method, values); }
    template <class T> jbyte getByte(jmethodID method, T values...) { return udp->getEnv()->CallStaticByteMethod(cls, method, values); }
    jbyte getByte(jobject parent, jmethodID method) { return udp->getEnv()->CallByteMethod(parent, method); }
    jbyte getByte(jmethodID method) { return udp->getEnv()->CallStaticByteMethod(cls, method); }
    jbyte getByte(jobject parent, jfieldID field) { return udp->getEnv()->GetByteField(parent, field); }
    jbyte getByte(jfieldID field) { return udp->getEnv()->GetStaticByteField(cls, field); }

    //Char
    template <class T> jchar getChar(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallCharMethod(parent, method, values); }
    template <class T> jchar getChar(jmethodID method, T values...) { return udp->getEnv()->CallStaticCharMethod(cls, method, values); }
    jchar getChar(jobject parent, jmethodID method) { return udp->getEnv()->CallCharMethod(parent, method); }
    jchar getChar(jmethodID method) { return udp->getEnv()->CallStaticCharMethod(cls, method); }
    jchar getChar(jobject parent, jfieldID field) { return udp->getEnv()->GetCharField(parent, field); }
    jchar getChar(jfieldID field) { return udp->getEnv()->GetStaticCharField(cls, field); }

    //Short
    template <class T> jshort getShort(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallShortMethod(parent, method, values); }
    template <class T> jshort getShort(jmethodID method, T values...) { return udp->getEnv()->CallStaticShortMethod(cls, method, values); }
    jshort getShort(jobject parent, jmethodID method) { return udp->getEnv()->CallShortMethod(parent, method); }
    jshort getShort(jmethodID method) { return udp->getEnv()->CallStaticShortMethod(cls, method); }
    jshort getShort(jobject parent, jfieldID field) { return udp->getEnv()->GetShortField(parent, field); }
    jshort getShort(jfieldID field) { return udp->getEnv()->GetStaticShortField(cls, field); }

    //Int
    template <class T> jint getInt(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallIntMethod(parent, method, values); }
    template <class T> jint getInt(jmethodID method, T values...) { return udp->getEnv()->CallStaticIntMethod(cls, method, values); }
    jint getInt(jobject parent, jmethodID method) { return udp->getEnv()->CallIntMethod(parent, method); }
    jint getInt(jmethodID method) { return udp->getEnv()->CallStaticIntMethod(cls, method); }
    jint getInt(jobject parent, jfieldID field) { return udp->getEnv()->GetIntField(parent, field); }
    jint getInt(jfieldID field) { return udp->getEnv()->GetStaticIntField(cls, field); }

    //Long
    template <class T> jlong getLong(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallLongMethod(parent, method, values); }
    template <class T> jlong getLong(jmethodID method, T values...) { return udp->getEnv()->CallStaticLongMethod(cls, method, values); }
    jlong getLong(jobject parent, jmethodID method) { return udp->getEnv()->CallLongMethod(parent, method); }
    jlong getLong(jmethodID method) { return udp->getEnv()->CallStaticLongMethod(cls, method); }
    jlong getLong(jobject parent, jfieldID field) { return udp->getEnv()->GetLongField(parent, field); }
    jlong getLong(jfieldID field) { return udp->getEnv()->GetStaticLongField(cls, field); }

    //Float
    template <class T> jfloat getFloat(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallFloatMethod(parent, method, values); }
    template <class T> jfloat getFloat(jmethodID method, T values...) { return udp->getEnv()->CallStaticFloatMethod(cls, method, values); }
    jfloat getFloat(jobject parent, jmethodID method) { return udp->getEnv()->CallFloatMethod(parent, method); }
    jfloat getFloat(jmethodID method) { return udp->getEnv()->CallStaticFloatMethod(cls, method); }
    jfloat getFloat(jobject parent, jfieldID field) { return udp->getEnv()->GetFloatField(parent, field); }
    jfloat getFloat(jfieldID field) { return udp->getEnv()->GetStaticFloatField(cls, field); }

    //Double
    template <class T> jdouble getDouble(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallDoubleMethod(parent, method, values); }
    template <class T> jdouble getDouble(jmethodID method, T values...) { return udp->getEnv()->CallStaticDoubleMethod(cls, method, values); }
    jdouble getDouble(jobject parent, jmethodID method) { return udp->getEnv()->CallDoubleMethod(parent, method); }
    jdouble getDouble(jmethodID method) { return udp->getEnv()->CallStaticDoubleMethod(cls, method); }
    jdouble getDouble(jobject parent, jfieldID field) { return udp->getEnv()->GetDoubleField(parent, field); }
    jdouble getDouble(jfieldID field) { return udp->getEnv()->GetStaticDoubleField(cls, field); }

    //Object
    template <class T> jobject getObject(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallObjectMethod(parent, method, values); }
    template <class T> jobject getObject(jmethodID method, T values...) { return udp->getEnv()->CallStaticObjectMethod(cls, method, values); }
    jobject getObject(jobject parent, jmethodID method) { return udp->getEnv()->CallObjectMethod(parent, method); }
    jobject getObject(jmethodID method) { return udp->getEnv()->CallStaticObjectMethod(cls, method); }
    jobject getObject(jobject parent, jfieldID field) { return udp->getEnv()->GetObjectField(parent, field); }
    jobject getObject(jfieldID field) { return udp->getEnv()->GetStaticObjectField(cls, field); }

    //Array
    int getArrayLength(jobjectArray arr) { return udp->getEnv()->GetArrayLength(arr); }
    jobject getArrayElement(jobjectArray arr, jsize index) { return udp->getEnv()->GetObjectArrayElement(arr, index); }

    //Void
    template <class T> void callMethod(jobject parent, jmethodID method, T values...) { return udp->getEnv()->CallVoidMethod(parent, method, values); }
    template <class T> void callMethod(jmethodID method, T values...) { return udp->getEnv()->CallStaticVoidMethod(cls, method, values); }
    void callMethod(jobject parent, jmethodID method) { return udp->getEnv()->CallVoidMethod(parent, method); }
    void callMethod(jmethodID method) { return udp->getEnv()->CallStaticVoidMethod(cls, method); }

    void setBoolean(jobject parent, jfieldID field, jboolean value) { udp->getEnv()->SetBooleanField(parent, field, value); }
    void setBoolean(jfieldID field, jboolean value) { udp->getEnv()->SetStaticBooleanField(cls, field, value); }

    void setByte(jobject parent, jfieldID field, jbyte value) { udp->getEnv()->SetByteField(parent, field, value); }
    void setByte(jfieldID field, jbyte value) { udp->getEnv()->SetStaticByteField(cls, field, value); }

    void setChar(jobject parent, jfieldID field, jchar value) { udp->getEnv()->SetCharField(parent, field, value); }
    void setChar(jfieldID field, jchar value) { udp->getEnv()->SetStaticCharField(cls, field, value); }

    void setShort(jobject parent, jfieldID field, jshort value) { udp->getEnv()->SetShortField(parent, field, value); }
    void setShort(jfieldID field, jshort value) { udp->getEnv()->SetStaticShortField(cls, field, value); }

    void setInt(jobject parent, jfieldID field, jint value) { udp->getEnv()->SetIntField(parent, field, value); }
    void setInt(jfieldID field, jint value) { udp->getEnv()->SetStaticIntField(cls, field, value); }

    void setLong(jobject parent, jfieldID field, jlong value) { udp->getEnv()->SetLongField(parent, field, value); }
    void setLong(jfieldID field, jlong value) { udp->getEnv()->SetStaticLongField(cls, field, value); }

    void setFloat(jobject parent, jfieldID field, jfloat value) { udp->getEnv()->SetFloatField(parent, field, value); }
    void setFloat(jfieldID field, jfloat value) { udp->getEnv()->SetStaticFloatField(cls, field, value); }

    void setDouble(jobject parent, jfieldID field, jdouble value) { udp->getEnv()->SetDoubleField(parent, field, value); }
    void setDouble(jfieldID field, jdouble value) { udp->getEnv()->SetStaticDoubleField(cls, field, value); }

protected:
    const char* clsKey;
    UDP * udp;
    jclass cls;
    // Field getter that uses the mapping class so only a clear-text name needs to be defined.
    // "name" : Clear-text name used by 'Mapping.h' to define the field.
    // Return: JNI field wrapper
    jfieldID getFieldID(const char * name) {
        CM* cm = Mapping::getClass(clsKey);
        Mem field = cm->fields.at(std::string(name));
        return getFieldID(field.name, field.desc, field.isStatic);
    }
    // Method getter that uses the mapping class so only a clear-text name needs to be defined.
    // "name" : Clear-text name used by 'Mapping.h' to define the method.
    // Return: JNI method wrapper
    jmethodID getMethodID(const char * name) {
        CM* cm = Mapping::getClass(clsKey);
        Mem method = cm->methods.at(std::string(name));
        return getMethodID(method.name, method.desc, method.isStatic);
    }
private:
    // Return: JNI field wrapper
    jfieldID getFieldID(const char * name,
                        const char * sig, bool _static) {
        return _static ? udp->getEnv()->GetStaticFieldID(cls, name, sig) : udp->getEnv()->GetFieldID(cls, name, sig);
    }
    // Return: JNI method wrapper
    jmethodID getMethodID(const char * name,
                          const char * sig, bool _static) {
        return _static ? udp->getEnv()->GetStaticMethodID(cls, name, sig) : udp->getEnv()->GetMethodID(cls, name, sig);
    }
};


#endif //MC_INJECTION_ABSTRACTCLASS_H
