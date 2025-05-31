#ifndef STATELLITE_DATAMANAGER_H
#define STATELLITE_DATAMANAGER_H
class SatelliteDataManager
{
private:
	SatelliteDataManager() = default;
	~SatelliteDataManager() = default;
	SatelliteDataManager(SatelliteDataManager&) = delete;
	SatelliteDataManager& operator=(const SatelliteDataManager&) = delete;

public:
	static SatelliteDataManager* getInstance();
};
#endif // !STATELLITE_DATAMANAGER_H
