#pragma once

#include <vector>

namespace Pathfinding
{
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

	class AStar
	{
	private:
		struct Node
		{
			Float3	position;
			Node*	parent;
			float	costFromStart, costToGoal;
			int		tileCost;
			bool	active;

			Node()
			{
				this->position = Float3(0,0,0);
				this->parent = nullptr;
				this->costFromStart = -1;
				this->costToGoal = -1;
				this->tileCost = -1;
				this->active = false;
			}
			~Node()
			{}
			bool operator<(const Node& node)
			{
				return (costFromStart + costToGoal) < (node.costFromStart + node.costToGoal);
			}
			bool operator>(const Node& node)
			{
				return (costFromStart + costToGoal) > (node.costFromStart + node.costToGoal);
			}
		};

	private:
		std::vector<Float3> path;
		Float3 start, goal;

	public:
		AStar();
		~AStar();


	};
}