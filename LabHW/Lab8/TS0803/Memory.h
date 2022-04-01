#include <iostream>
#include <vector>
#include <string>
#define ERROR_MSM "Violation Access."
using namespace std;

class Memory {
private:
	int SIZE;
	char* MEM;
public:
	Memory(int size);
	~Memory();
	void set(int pos);
	void get(int pos);
};
