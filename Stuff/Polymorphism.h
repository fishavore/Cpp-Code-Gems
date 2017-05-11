#pragma once

#include <iostream>
#include <string>

namespace Polymorphism
{
	class Car
	{
	public:
		Car() {};
		~Car() {};
		void Print() { std::cout << "Inside Car" << endl; Brand(); };
		virtual void Brand() = 0;
	};

	class Seat : public Car
	{
	public:
		Seat() {};
		~Seat() {};
		void Brand() { cout << "Need for seat." << endl; };
	};

	class Wheel : public Car
	{
	private:
		int value;
		int otherValue;
	public:
		Wheel() {};
		~Wheel() {};
		void Brand() { cout << "Hjul." << endl; };

		void setValue(const int val) { otherValue = val;};
		int getOtherValue() const {return otherValue;};
	};

	inline void start()
	{
		Car* seat = nullptr;
		Car* wheel = nullptr;

		seat = new Seat();
		wheel = new Wheel();

		((Seat*)seat)->Print();
		((Wheel*)wheel)->Print();

		delete seat;
		delete wheel;
	}
}