#include <iostream>
#include "msclr\marshal_cppstd.h" //C/C++/Language/Conformance mode -> No.


/*
	Add the C# project to References.
	Add the .NET framework version to the Properties\General\.NET Target Framework version
*/

int main()
{
    std::cout << "Hello World!\n";

	System::String^ textHellu = gcnew System::String("Inside");
	System::String^ textLol = gcnew System::String("C#");
	
	System::String^ managedReturnText = CSharpExampleUsingCpp::CppToCS::InsideCS(textHellu, textLol);
	std::string unmanagedReturnText = msclr::interop::marshal_as<std::string>(managedReturnText); //#include "msclr\marshal_cppstd.h"
	std::cout << unmanagedReturnText << '\n';

	system("pause");
	return 0;
}
