//
// Created by somepineaple on 1/29/22.
//

#ifndef PHANTOM_JAVAPRINTSTREAM_H
#define PHANTOM_JAVAPRINTSTREAM_H

#include "../../../AbstractClass.h"

class JavaPrintStream : public AbstractClass {
public:
    JavaPrintStream(Phantom *phantom, jobject printStream);
    void println(jstring data);
    jobject getPrintStream();
private:
    jobject printStream;

    jmethodID mdPrintln;
};


#endif //PHANTOM_JAVAPRINTSTREAM_H
