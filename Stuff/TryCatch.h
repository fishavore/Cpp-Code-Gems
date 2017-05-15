#pragma once

#include <exception>
#include <string>
#include <iostream>

namespace TryCatch
{
	inline void start()
	{
		//First Catch
		auto funcThatThrows = []() { string val[1] = { "hello" }; val[2].push_back('A'); };
		
		//Second Catch
		//Only "Throw String.\n" will probably convert as a const char* and result in the "all other throws". 
		auto funcThatThrowsString = []() { throw std::string("Throw String.\n"); };
		
		//Third Catch
		//In this example, we only handle string throws, but you can handle int as well. This will be thrown as
		//in to the "all other throws" as it isn't type specified.
		auto funcThatThrowsInt = []() { throw 42; };

		try {
			//funcThatThrows();
			//funcThatThrowsString();
			//funcThatThrowsInt(); 
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << '\n';
		}
		catch (const std::string& ex) {
			std::cout << ex << '\n';
		}
		catch (...) {
			std::cout << "All other throws.\n";
		}
	}
}