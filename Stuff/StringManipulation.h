#pragma once

#include <iostream>
#include <string>

//for Split.
#include <sstream>
#include <vector>
#include <iterator>

namespace StringManipulation
{
	namespace Split
	{
		/*
		Source: http://stackoverflow.com/a/236803/2359879
		Author note: 
			Note that this solution does not skip empty tokens, so the following will find 4 items, one of which is empty:
			std::vector<std::string> x = split("one:two::three", ':');
		*/
		template<typename Out>
		void split(const std::string &s, char delim, Out result) {
			std::stringstream ss;
			ss.str(s);
			std::string item;
			while (std::getline(ss, item, delim)) {
				*(result++) = item;
			}
		}

		std::vector<std::string> split(const std::string &s, char delim) {
			std::vector<std::string> elems;
			split(s, delim, std::back_inserter(elems));
			return elems;
		}
	}

	inline void main()
	{
		using namespace std;

		string a = "Hello";
		string b = "World!";
		string c = "You're Welcome.";
		string d = "I am Yoda";

		//Add
		a += ' ';
		cout << a + b << '\n'; //Hello World!
		size_t pos = c.find('c');

		//Subtract
		string str = c.substr(pos);//come.
		//string str = c.substr(pos, 4); //come
		str.pop_back();//come
		cout << str << b[4] << c[0] << '\n'; //comedY

		//split
		vector<string> out = Split::split(d, ' ');
		string e = out[2] + ' ' + out[0] + ' ' + out[1] + '\n';
		cout << e; //Yoda I am

		//erase
		string toRemove = "da";
		pos = e.find(toRemove);
		e.erase(pos, toRemove.size());
		cout << e;
	}
}