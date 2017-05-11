#pragma once

namespace OverloadingOperator
{
	// http://stackoverflow.com/documentation/c%2b%2b/562/operator-overloading#t=201704231653142892616

	struct Float3
	{
		float x, y, z;

		Float3() {};
		Float3(const float x, const float y, const float y)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Float3 operator+(const Float3& val)
		{
			return { this->x + val.x, this->y + val.y, this->z + val.z };
		}
		Float3 operator-(const Float3& val)
		{
			return { this->x - val.x, this->y - val.y, this->z - val.z };
		}
		Float3 operator*(const int mult)
		{
			return Float3(this->x * mult, this->y * mult, this->z * mult);
		}
		Float3& operator+=(const Float3& val)
		{
			this->x += val.x;
			this->y += val.y;
			this->z += val.z;
			return *this;
		}
		Float3& operator-=(const Float3& val)
		{
			this->x -= val.x;
			this->y -= val.y;
			this->y -= val.y;
			return *this;
		}
	};


	inline void start()
	{

	}
}