#pragma once

#include <iostream>
#include <string>

namespace Polymorphism
{
	class Base
	{
	public:
		Base() {};
		~Base() { std::cout << "Inside destructor Base.\n"; };
		void Print() { std::cout << "Inside print Base" << endl; AwesomeFunc(); };
		virtual void AwesomeFunc() = 0;
	};

	class A : public Base
	{
	public:
		A() {};
		~A() { std::cout << "Inside destructor A.\n"; };
		void AwesomeFunc() { cout << "AwesomeFunc: A. \n"; };
	};

	class B : public Base
	{
	private:
		int value;
		int otherValue;
	public:
		B() {};
		~B() { std::cout << "Inside destructor B.\n"; };
		void AwesomeFunc() { cout << "AwesomeFunc: B. \n"; };

		void setValue(const int val) { otherValue = val;};
		int getOtherValue() const {return otherValue;};
	};

	class C : public B
	{
	private:
		int value;
		int otherValue;
	public:
		C() {};
		virtual ~C() { std::cout << "Inside destructor C.\n"; };
		void AwesomeFunc() { cout << "AwesomeFunc: C. \n"; };

		void setValue(const int val) { otherValue = val; };
		int getOtherValue() const { return otherValue; };
	};

	inline void start()
	{
		//setup
		Base* base = nullptr;
		Base* b = nullptr;
		B* c = nullptr;

		base = new A();
		b = new B();
		c = new C();

		//Basic usage
		((A*)base)->Print();
		((B*)b)->Print();

		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		//Question!
		//Which virtual destructors are used if you place them a little randomly?
		
		//If only virtual function of all deconstructors is: virtual ~Base()
		delete base; // A + Base.
		delete b; // B + Base.
		delete c; // C + B + Base.

		//if only: virtual ~C()
		// Base.
		// Base.
		// B + Base.
	}
}