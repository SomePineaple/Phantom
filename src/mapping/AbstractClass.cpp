//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "AbstractClass.h"

AbstractClass::AbstractClass(Phantom * phantom, const char * clsName) {
    this->phantom = phantom;
    this->clsKey = clsName;

    //Find each class that inherits AbstractClass by the class name provided
    cls = phantom->getEnv()->FindClass(Mapping::getClassName(clsName));

    //Check for exceptions. I got lazy, and this is the only time I actually check for errors
    //Basically, checks if there's an error, prints the stack trace to the console, then clears the error
    if (phantom->getEnv()->ExceptionCheck()) {
        phantom->getEnv()->ExceptionDescribe();
        phantom->getEnv()->ExceptionClear();
    }
}
