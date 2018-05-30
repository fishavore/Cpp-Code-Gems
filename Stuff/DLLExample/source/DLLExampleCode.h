#include <iostream>
#include <string>


class MainClass
{
public:
	MainClass();
	~MainClass();

	void Print()
	{
		std::cout << "Printed from inside the DLLExample.\n";
	}
	void GetString(unsigned char* str, int size)
	{
		std::string var = "String obtained from within DLLExample.dll";
		if (var.size() > size)
			return;
		memset(str, 0, size);
		memcpy(str, &var, var.size());
	}


private:

};

MainClass::MainClass()
{
}

MainClass::~MainClass()
{
}
