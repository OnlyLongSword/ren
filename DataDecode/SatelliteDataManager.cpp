#include "SatelliteDataManager.h"

SatelliteDataManager* SatelliteDataManager::getInstance()
{
	static SatelliteDataManager instance;
	return &instance;
}
