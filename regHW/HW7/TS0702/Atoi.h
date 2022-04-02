#include <string>
using namespace std;

class Atoi {

private:
	std::string beTrans;
	
public:
	Atoi();
	Atoi(std::string s);
	void SetString(std::string s);
	const std::string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();

};
