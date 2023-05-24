#ifndef __ERROR_MANAGER_H__
#define __ERROR_MANAGER_H__

#include <stdio.h>
#include <map>
#include <stdarg.h>

#include "Manager.h"
#include <fstream>
#include <iostream>
#include<exception>
#define EM me::ErrorManager::getInstance()

using namespace std;
namespace me {

	

	class ErrorManager : public Manager {

	private:
		ErrorManager();                     // Private since a singleton.
		ErrorManager(ErrorManager const&);    // Don't allow copy.
		void operator=(ErrorManager const&);// Don't allow assignment.
	
		
	public:
		// If logfile is open, close it.
		~ErrorManager() {};

		// Get the one and only instance of the LogManager.
		static ErrorManager& getInstance();

		const char* what(const std::exception& e);


	};

} // end of namespace df
#endif 
