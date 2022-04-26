#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace Authenticate {
	void inputPassword();
	string getPassword();
}

namespace {
	bool isValid();
}