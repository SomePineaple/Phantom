#include "JavaList.h"

JavaList::JavaList(UDP * udp, jobject list) : AbstractClass::AbstractClass(udp, "List") {
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