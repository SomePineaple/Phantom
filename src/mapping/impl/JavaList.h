#pragma once

#include "../AbstractClass.h"

class JavaList : public AbstractClass
{
public:
	JavaList(UDP * udp, jobject list);
	
	jobject get(jint index);
	int size();
	jobjectArray toArray();
private:
	jmethodID mdGet;
	jmethodID mdSize;
	jmethodID mdToArray;

	jobject list;
};

