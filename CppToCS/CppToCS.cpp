#include <iostream>
#include "msclr\marshal_cppstd.h" //C/C++/Language/Conformance mode -> No.

int main()
{
    std::cout << "Hello World!\n";

	System::String^ textHellu = gcnew System::String("Inside");
	System::String^ textLol = gcnew System::String("C#");

	System::String^ managedReturnText = CSLibExample::Class1::InsideCS(textHellu, textLol);
	std::string unmanagedReturnText = msclr::interop::marshal_as<std::string>(managedReturnText);
	std::cout << unmanagedReturnText << '\n';

	system("pause");
	return 0;
}
