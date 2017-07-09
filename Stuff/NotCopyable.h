#pragma once


namespace NotCopyable
{
	//Wrong way, old way:
	class foo_not_copiable
	{
	public:
		foo_not_copiable() {};
	private:
		foo_not_copiable(foo_not_copiable const&);
		foo_not_copiable& operator=(foo_not_copiable const&);
	};

	//Right way, new way since C++11:
	class bar_not_copiable
	{
	public:
		bar_not_copiable() = default; //More info on default: https://stackoverflow.com/a/20828970

		bar_not_copiable(bar_not_copiable const &) = delete;
		bar_not_copiable& operator=(bar_not_copiable const&) = delete;
	};
	

	void start()
	{
		{
			//foo_not_copiable var1, var2;
			//foo_not_copiable var = var1; // error on var1
			//var1 = var2; // error on =
		}

		{
			//bar_not_copiable var1, var2;
			//foo_not_copiable var = var1; // error on var1
			//var1 = var2; // error on =     
		}
	}
}