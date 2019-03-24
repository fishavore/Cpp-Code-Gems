#pragma once

#include <iostream>
#include <fstream>

/*
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

Copy and paste for debug

#include <iostream>
#include <fstream>

void LLLOG(std::string text)
{
	std::string path = "C:\\temp";
	std::string filename = "log.txt";
	std::ofstream out;

	//Create directory
	if (CreateDirectory(path.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
		//Create file
		std::string fullpath = path + "\\" + filename;
		out.open(fullpath, std::fstream::in | std::fstream::out | std::fstream::app);
		if (!out)
		{
			out.open(filename, fstream::in | fstream::out | fstream::trunc);
		}
		//Log to the file
		if (out.is_open())
		{
			out << text << std::endl;
			out.close();
		}
	}	
}

*/
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

//For read from file you should use: //Do not use while(!in.eof()){ because the end of file bit will not
//be set until *after* a failed read due to end of file.



namespace ReadWriteToFile
{
	void ReadFromFile(std::string path)
	{
		std::ifstream in;
		
		in.open(path);
		if (in.is_open())
		{
			//Grab each line until the end of line.
			{
				std::vector<std::string> lines;
				std::string line;
				while (getline(in, line))
				{
					lines.push_back(line);
				}
			}
			
			//Setup to read again
			{
				in.clear();
				in.seekg(0, in.beg);
			}

			//Read 
			{
				std::vector<std::string> lines;
				std::string word;
				char achar;
				achar = in.get(); //Read char. This will even read things like \n.
				while (true)
				{
					if (in.good())
					{
						in >> word; //Reads word by word seperated by blank space or \n.
					}
					else
					{
						break;
					}
				}
			}

			in.close();
		}
		else
		{
			std::cout << "Write to file error.\n";
		}
	}

	void WriteToFile(std::string path)
	{
		std::ofstream out;

		out.open(path);
		if (out.is_open())
		{
			out << "1";
			out << "2";
			//outputs: 12
			out << std::endl;
			out << "3\n";
			out << "4\n";

			/*
			12
			3
			4
			*/
			out << "This is a sentence we can use to look at words or specific chars.\n";
			
			out.close();
		}
		else
		{
			std::cout << "Write to file error.\n";
		}
	}

	void start()
	{
		std::string path = "file.txt";
		WriteToFile(path);
		ReadFromFile(path);
	}
}