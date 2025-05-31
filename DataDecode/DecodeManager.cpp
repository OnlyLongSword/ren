#include "DecodeManager.h"

DecodeManager* DecodeManager::getInstance()
{
    static DecodeManager instance;
    return &instance;
}
