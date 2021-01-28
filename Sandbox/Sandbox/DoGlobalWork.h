#pragma once
#include"uti.h"
#include<string>

using namespace std;


class DoGlobalWork {
	Resource Resource;

public:
	string usingGlobalVariableName = Resource.CURRENT_NAME;
	string usingGlobalVariableVersion = Resource.CURRENT_VERSION;


};
