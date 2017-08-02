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

	inline void start()
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

		//not found
		size_t notFound = c.find('K'); //Generates a huge value.
		if (std::string::npos == notFound)
			std::cout << "Not found is not found. OK.\n";

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

		//insert with iteration
		string f = "1234567890";
		
		for (auto it = f.begin(); it < f.end(); it += 2)
			it = (it == f.begin() ? it : f.insert(it, ' ') + 1);
		//outputs 12 34 56 78 90

		cout << f << '\n';

		//Substring - Get a portion of the string.
		//Note: We can't use g[0] for example because that would either return an int or a char depending on compiler/version.
		//Same as g.at() which returns char. We have to use substr.

		string g = "1234567890";
		string outputG = g.substr(0, 2);
		cout << outputG << '\n';

		//isdigit
		string h = "1ab2c34d567890c";
		string outputH = "";
		for (int i = 0; i < h.size(); i++)
		{
			if (isdigit(h[i]))
			{
				outputH.push_back(h[i]);
			}
		}
		cout << outputH << '\n';

		//You can do the same with all nums and chars. A-Z, a-z, 0-9
		string o = "!1/23A&BC@";
		string outputO = "";
		for (int i = 0; i < o.size(); i++)
		{
			if (isalnum(o[i]))
			{
				outputO.push_back(o[i]);
			}
		}
		cout << outputO << '\n';

		//empty
		string p = "";
		string q = "Alex";
		if (p.empty())
			cout << "p is empty.\n";
		if (q.empty())
			cout << "q is not empty.\n";
	}
}