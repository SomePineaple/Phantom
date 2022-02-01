//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#ifndef PHANTOM_JAVASET_H
#define PHANTOM_JAVASET_H

#include "../AbstractClass.h"

class JavaSet : public AbstractClass {
public:
	JavaSet(Phantom *phantom, jobject set);

	int size();
	jobjectArray toArray();

	jobject get(int index);
private:
	jmethodID mdSize;
	jmethodID mdToArray;

	jobject set;
};

#endif //PHANTOM_JAVASET_H
