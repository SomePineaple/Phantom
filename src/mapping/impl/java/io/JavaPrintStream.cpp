//
// Created by somepineaple on 1/29/22.
//

#include "JavaPrintStream.h"

JavaPrintStream::JavaPrintStream(Phantom *phantom, jobject printStream) : AbstractClass(phantom, "PrintStream") {
    mdPrintln = getMethodID("println");

    this->printStream = printStream;
}

void JavaPrintStream::println(jstring data) {
    callMethod(printStream, mdPrintln, data);
}

jobject JavaPrintStream::getPrintStream() {
    return printStream;
}
