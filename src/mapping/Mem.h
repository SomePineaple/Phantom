//
// Created by somepineaple on 1/25/22.
//

#ifndef MC_INJECTION_MEM_H
#define MC_INJECTION_MEM_H

struct Mem {
	const char* name;
	const char* desc;
	bool isStatic;
	Mem(const char* memName, const char* memDesc, bool stat) : name(memName), desc(memDesc), isStatic(stat) {}
};

#endif //MC_INJECTION_MEM_H
