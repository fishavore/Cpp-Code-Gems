#pragma once

//The description of this problem is explained inside:
//ParadoxInteractivePathfindingProblem.txt


/*
TODO notes:
http://theory.stanford.edu/~amitp/GameProgramming/ImplementationNotes.html#source-code-and-demos
http://www.redblobgames.com/pathfinding/a-star/implementation.html

*/

#include <iostream>

namespace Paradox
{
	int FindPath(const int nStartX, const int nStartY,
		const int nTargetX, const int nTargetY,
		const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
		int* pOutBuffer, const int nOutBufferSize)
	{
		

		return -1;
	}

	inline void print(const unsigned char* pMap, const int  mapSizeX, const int  MAPSIZE)
	{
		std::cout << "Paradox Pathfinding print(): " << endl;

		int incr = 0;
		for (int i = MAPSIZE; i > 0; i-= mapSizeX)
		{
			for (int j = mapSizeX; j >0; j--)
			{

				std::cout << (int)pMap[i-j];
				incr++;
			}
			
			if (incr == mapSizeX)
			{
				incr = 0;
				std::cout << endl;
			}
		}
	}

	inline void start()
	{
		const int mapSizeX = 4;
		const int mapSizeY = 3;
		const int MAPSIZE = mapSizeX * mapSizeY;
		unsigned char pMap[MAPSIZE] = { 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 };
		int pOutBuffer[MAPSIZE];

		print(pMap, mapSizeX, MAPSIZE);
		


		const int startPosX = 0;
		const int startPosY = 0;
		const int targetX = 1;
		const int targetY = 2;

		FindPath(startPosX, startPosY, targetX, targetY, pMap, mapSizeX, mapSizeY, pOutBuffer, MAPSIZE);
	}
}

/*
unsigned char pMap[] = { 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 };
int pOutBuffer[12];
FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);

Should generate the result of: 3 and the first three positions of pOutBuffer must be populated with 1,5,9.

The map looks like:

0 1 1 1
0 1 0 1
1 1 1 1 
////////
where the expected path is:

0  [1]* 1 1
0  [1]  0 1
1* [1]  1 1

Test cases to be check is:

(0,0) to (3,2). Result: 1, 2, 3, 8.
(0,0) to (2, 3). Result: 1, 5, 9, 10.


unsigned char pMap[] = {0, 0, 1, 0, 1, 1, 1, 0, 1};
int pOutBuffer[7];
FindPath(2, 0, 0, 2, pMap, 3, 3, pOutBuffer, 7);

returns -1.

*/