#include "..\includes\DLLExampleCode.h"
#include <iostream>
#include <string>



#ifdef __cplusplus  
extern "C" {  // only need to export C interface if used by C++ source code
#endif

	namespace DLLExampleCode
	{
		FORC DECLDIR void Print()
		{
			std::cout << "Printed from inside the DLLExample.\n";
		}
		FORC DECLDIR void GetString(unsigned char* str, int size)
		{
			std::string var = "String obtained from within DLLExample.dll";
			if (var.size() > size)
				return;
			memset(str, 0, size);
			memcpy(str, &var, var.size());
		}
	}


#ifdef __cplusplus  
}
#endif 