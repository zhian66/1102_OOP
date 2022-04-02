#include "Atoi.h"

Atoi::Atoi() {
	beTrans = "";
}

Atoi::Atoi(std::string s) {
	beTrans = s;
}

void Atoi::SetString(std::string s) {
	beTrans = s;
}

const std::string Atoi::GetString() {
	return beTrans;
}

int Atoi::Length() {
	return beTrans.size() - (int)(beTrans[0] == '-');
}

bool Atoi::IsDigital() {
	for (const auto& s : beTrans) {
		if (s < '0' || s>'9') {
			if (s != '-')
				return false;
		}
	}
	return true;
}

int Atoi::StringToInteger() {
	int result = 0;
	for (const auto& s : beTrans) {
		if (s != '-') {
			result *= 10;
			result += (s - '0');
		} 
	}
	if (beTrans[0] == '-') result *= -1;
	return result;
}