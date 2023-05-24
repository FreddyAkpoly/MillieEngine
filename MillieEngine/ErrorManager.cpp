#include "ErrorManager.h"
#include "LogManager.h"
 namespace me {
	 ErrorManager::ErrorManager()
	 {

	 }
	 ErrorManager& me::ErrorManager::getInstance()
	{
		static ErrorManager instance;
		return instance;
	}

	const char* ErrorManager::what(const std::exception& e)
	{
		LM.writeLog("ERROR: %s %s",e.what(), LM.getTimeString());
		return nullptr;
	}
}

