//
// This code was copied from UDP-CPP: https://github.com/UnknownDetectionParty/UDP-CPP
//

#include "JavaList.h"

JavaList::JavaList(Phantom * phantom, jobject list) : AbstractClass::AbstractClass(phantom, "List") {
	mdGet = getMethodID("get");
	mdSize = getMethodID("size");
	mdToArray = getMethodID("toArray");

	this->list = list;
}

jobject JavaList::get(jint index) {
	return getObject(list, mdGet, index);
}

int JavaList::size() {
	return getInt(list, mdSize);
}

jobjectArray JavaList::toArray() {
	return (jobjectArray) getObject(list, mdToArray);
}

jobject JavaList::getList() {
    return list;
}
