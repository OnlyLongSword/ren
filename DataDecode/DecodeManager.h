#ifndef DECODE_MANAGER_H
#define DECODE_MANAGER_H

class DecodeManager
{
private:
	DecodeManager() = default;
	~DecodeManager() = default;
	DecodeManager(DecodeManager&) = delete;
	DecodeManager& operator=(const DecodeManager&) = delete;

public:
	static DecodeManager* getInstance();
};
#endif // !DECODE_MANAGER_H
