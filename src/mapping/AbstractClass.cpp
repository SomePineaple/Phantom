//
// Created by somepineaple on 1/25/22.
//

#include "AbstractClass.h"

AbstractClass::AbstractClass(UDP * udp, const char * clsName)
{
    this->udp = udp;
    this->clsKey = clsName;

    //Find each class that inherits AbstractClass by the class name provided
    cls = udp->getEnv()->FindClass(Mapping::getClassName(clsName));

    //Check for exceptions. I got lazy, and this is the only time I actually check for errors
    //Basically, checks if there's an error, prints the stack trace to the console, then clears the error
    if (udp->getEnv()->ExceptionCheck()) {
        udp->getEnv()->ExceptionDescribe();
        udp->getEnv()->ExceptionClear();
    }
}
