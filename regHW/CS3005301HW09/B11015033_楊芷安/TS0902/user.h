#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace Authenticate {
	void inputUserName();
	string getUserName();
}

namespace {
	bool isValid();
}