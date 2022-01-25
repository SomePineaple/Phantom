#include "library.h"

#include <iostream>

__attribute__((constuctor)) void dllLoad() {

}

void hello() {
    std::cout << "Hello, World!" << std::endl;
}
