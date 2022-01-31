#include "JavaSet.h"

JavaSet::JavaSet(Phantom *phantom, jobject set) : AbstractClass(phantom, "Set") {
	mdSize = getMethodID("size");
	mdToArray = getMethodID("toArray");

	this->set = set;
}

int JavaSet::size() {
	return getInt(set, mdSize);
}

jobjectArray JavaSet::toArray() {
	return (jobjectArray)getObject(set, mdToArray);
}

jobject JavaSet::get(int index) {
	return getArrayElement(toArray(), index);
}
