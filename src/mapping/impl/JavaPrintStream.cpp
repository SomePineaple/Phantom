//
// Created by somepineaple on 1/29/22.
//

#include "JavaPrintStream.h"

JavaPrintStream::JavaPrintStream(UDP *udp, jobject printStream) : AbstractClass(udp, "PrintStream") {
    mdPrintln = getMethodID("println");

    this->printStream = printStream;
}

void JavaPrintStream::println(jstring data) {
    callMethod(printStream, mdPrintln, data);
}
