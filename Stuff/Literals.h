#pragma once

#include <iostream>
#include <chrono>

/*

	1. user-defined literals //C++11
	2. user-defined literals for standard library types //C++14
	3. binary literals //c++14
	4. utf-8 character literals //c++17

	Source of all 4: https://github.com/AnthonyCalandra/modern-cpp-features#user-defined-literals
*/

namespace Literals
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//1. user-defined literals //C++11

	// `unsigned long long` parameter required for integer literal.
	long long operator "" _celsius(unsigned long long tempCelsius) {
		return std::llround(tempCelsius * 1.8 + 32);
	}

	int operator "" _int(const char* str, std::size_t) {
		return std::stoi(str);
	}

	void userDefinedLiterals()
	{
		/*
		
		User-defined literals allow you to extend the language and add your own syntax. To create a literal, 
		define a T operator "" X(...) { ... } function that returns a type T, with a name X. Note that the 
		name of this function defines the name of the literal. Any literal names not starting with an 
		underscore are reserved and won't be invoked. There are rules on what parameters a user-defined 
		literal function should accept, according to what type the literal is called on.
		
		*/

		24_celsius; // == 75
		"123"_int; // == 123, with type `int`
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//2. user-defined literals for standard library types //C++14

	void userDefinedLiteralsStandardLibraryTypes()
	{
		/*
		
		New user-defined literals for standard library types, including new built-in literals for chrono 
		and basic_string. These can be constexpr meaning they can be used at compile-time. Some uses for 
		these literals include compile-time integer parsing, binary literals, and imaginary number literals.

		*/
		using namespace std::chrono_literals;
		auto day = 24h; //use auto cuz you dont want to watch what it actually corresponds lol.
		day.count(); // == 24
		std::chrono::duration_cast<std::chrono::minutes>(day).count(); // == 1440
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//3. binary literals //c++14

	void utf8character()
	{
		/*
		
		Binary literals provide a convenient way to represent a base-2 number. It is possible to separate digits with '.
		
		*/
		//0b110 // == 6
		//0b1111'1111 // == 255
		
		int val = 0b101; //5
		std::cout << "Binary value: "<< val << '\n';
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//4. utf-8 character literals //c++17

	void binaryLiterals()
	{
		/*
		
		A character literal that begins with u8 is a character literal of type char. The value of a UTF-8 character 
		literal is equal to its ISO 10646 code point value.
		
		*/
		char x = u8'x';
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void start()
	{
		userDefinedLiterals();
		userDefinedLiteralsStandardLibraryTypes();
		binaryLiterals();
		utf8character();
	}
}