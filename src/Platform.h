//
// Created by somepineaple on 1/29/22.
//

#ifndef PHANTOM_PLATFORM_H
#define PHANTOM_PLATFORM_H

// Can either be MC_1_8_8 or MC_1_12, depending on what version you want to build for
#define MC_1_8_8

#ifdef MC_1_8_8
#ifdef MC_1_12
#error Cannot build for both MC_1_8_8 and MC_1_12, please remove the definition of one of these
#endif
#endif

#endif //PHANTOM_PLATFORM_H
