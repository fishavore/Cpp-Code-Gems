#include "..\includes\DLLExampleCode.h"
#include <iostream>



#ifdef __cplusplus  
extern "C" {  // only need to export C interface if used by C++ source code
#endif

	namespace DLLExampleCode
	{
		FORC DECLDIR void Print()
		{
			std::cout << "Printed from inside the DLLExample.\n";
		}
	}


#ifdef __cplusplus  
}
#endif 