#ifndef PHANTOM_PLAYERCONTROLLERMP_H
#define PHANTOM_PLAYERCONTROLLERMP_H

#include "../../../../../AbstractClass.h"

class Minecraft;
class PlayerControllerMP : public AbstractClass {
public:
	PlayerControllerMP(Phantom *phantom, Minecraft * mc);
    jobject getPlayerController();

    jboolean getIsHittingBlock();
private:
    jmethodID mdGetIsHittingBlock;

	Minecraft *mc;
};

#endif //PHANTOM_PLAYERCONTROLLERMP_H

