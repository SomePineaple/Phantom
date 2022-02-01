//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_MEM_H
#define PHANTOM_MEM_H

struct Mem {
	const char* name;
	const char* desc;
	bool isStatic;
	Mem(const char* memName, const char* memDesc, bool stat) : name(memName), desc(memDesc), isStatic(stat) {}
};

#endif //PHANTOM_MEM_H
