//
// Created by somepineaple on 1/29/22.
//

#ifndef MC_INJECTION_JAVAPRINTSTREAM_H
#define MC_INJECTION_JAVAPRINTSTREAM_H

#include "../AbstractClass.h"

class JavaPrintStream : public AbstractClass {
public:
    JavaPrintStream(UDP *udp, jobject printStream);
    void println(jstring data);
private:
    jobject printStream;

    jmethodID mdPrintln;
};


#endif //MC_INJECTION_JAVAPRINTSTREAM_H
