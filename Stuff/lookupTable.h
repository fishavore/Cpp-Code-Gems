#pragma once


#include <iostream>
#include <string>
#include "Timer.h"

/*

Author note:
My own tests shows a different result. It might not actually be faster but instead slower.
Make your own tests in order to verify the speed up!


*/



/*

Look up tables can be used in various ways but the point of a lookup table is reducing
computation time to just look up the value. The most simple case would be:

float a; int b;
a = (b == 0) ? 1.0f : 2.5f;

could be changed to:

float a; int b;
const float OneOrTwo5[2] = {1.0f, 2.5f};
a = OneOrTwo5[b & 1];

Why? Well, the branch prediction may cause a lot of misses. But lookupTable() shows a rather more
genious idea of using it.

*/

namespace LookupTable
{
	void explained()
	{
		int n = 5;
		std::string val;

		//Not a look up table. This is a switch statement.
		switch (n)
		{
		case 0:
			val = "Look";
			break;
		case 1:
			val = "up";
			break;
		case 2:
			val = "table";
			break;;
		case 3:
			val = "LUL";
			break;
		case 4:
			val = "OMFG";
			break;
		case 5:
			val = "So nice";
			break;
		case 6:
			val = "Not switch statements tho";
			break;
		default:
			val = "error";
			break;
		}
		std::cout << val << '\n';


		//The lookup table.
		static const std::string stringArray[7] = { "Look", "up", "table", "LUL", "OMFG", "So nice", "Not switchstatements tho" };
		if (n < 6)
		{
			std::cout << stringArray[n] << '\n';
		}
		/*
		//The lookup table. Just a simple const array bruh.
		static const std::string stringArray[7] = { "Look", "up", "table", "LUL", "OMFG", "So nice", "Not switchstatements tho" };
		if (n < 6)
		{
		std::cout << stringArray[n] << '\n';
		}

		//The advantage of using static here is that the list(stringArray) does not need to be initialized when the
		//function is called.The values are simply put there when the program is loaded into memory.
		//If the word static is removed from the above example, then all five values have to be put
		//into the list every time the function is called.
		//This is done by copying the entire list from
		//static memory to stack memory.Copying constant data from static memory to the stack is a
		//waste of time in most cases, but it may be optimal in special cases where the data are used
		//many times in a loop where almost the entire level - 1 cache is used in a number of arrays
		//that you want to keep together on the stack.


		*/
	}

	///////////////////////////////////////////////////////////////////////////

	void switchFunc(int val, int& output)
	{
		switch (val)
		{
		case 0: output = 0; break;
		case 1: output = 1; break;
		case 2:	output = 2; break;
		case 3:	output = 3; break;
		case 4:	output = 4; break;
		case 5:	output = 5; break;
		case 6:	output = 6; break;
		case 7:	output = 7; break;
		case 8:	output = 8; break;
		case 9:	output = 9; break;
		case 10: output = 10; break;
		case 11: output = 11; break;
		case 12: output = 12; break;
		case 13: output = 13; break;
		case 14: output = 14; break;
		case 15: output = 15; break;
		case 16: output = 16; break;
		case 17: output = 17; break;
		case 18: output = 18; break;
		case 19: output = 19; break;
		case 20: output = 20; break;
		case 21: output = 21; break;
		case 22: output = 22; break;
		case 23: output = 23; break;
		case 24: output = 24; break;
		case 25: output = 25; break;
		case 26: output = 26; break;
		case 27: output = 27; break;
		case 28: output = 28; break;
		case 29: output = 29; break;
		case 30: output = 30; break;
		case 31: output = 31; break;
		case 32: output = 32; break;
		case 33: output = 33; break;
		case 34: output = 34; break;
		case 35: output = 35; break;
		case 36: output = 36; break;
		case 37: output = 37; break;
		case 38: output = 38; break;
		case 39: output = 39; break;
		case 40: output = 40; break;
		case 41: output = 41; break;
		case 42: output = 42; break;
		case 43: output = 43; break;
		case 44: output = 44; break;
		case 45: output = 45; break;
		case 46: output = 46; break;
		case 47: output = 47; break;
		case 48: output = 48; break;
		case 49: output = 49; break;
		case 50: output = 50; break;
		case 51: output = 51; break;
		case 52: output = 52; break;
		case 53: output = 53; break;
		case 54: output = 54; break;
		case 55: output = 55; break;
		case 56: output = 56; break;
		case 57: output = 57; break;
		case 58: output = 58; break;
		case 59: output = 59; break;
		case 60: output = 60; break;
		case 61: output = 61; break;
		case 62: output = 62; break;
		case 63: output = 63; break;
		case 64: output = 64; break;
		case 65: output = 65; break;
		case 66: output = 66; break;
		case 67: output = 67; break;
		case 68: output = 68; break;
		case 69: output = 69; break;
		case 70: output = 70; break;
		case 71: output = 71; break;
		case 72: output = 72; break;
		case 73: output = 73; break;
		case 74: output = 74; break;
		case 75: output = 75; break;
		case 76: output = 76; break;
		case 77: output = 77; break;
		case 78: output = 78; break;
		case 79: output = 79; break;
		case 80: output = 80; break;
		case 81: output = 81; break;
		case 82: output = 82; break;
		case 83: output = 83; break;
		case 84: output = 84; break;
		case 85: output = 85; break;
		case 86: output = 86; break;
		case 87: output = 87; break;
		case 88: output = 88; break;
		case 89: output = 89; break;
		case 90: output = 90; break;
		case 91: output = 91; break;
		case 92: output = 92; break;
		case 93: output = 93; break;
		case 94: output = 94; break;
		case 95: output = 95; break;
		case 96: output = 96; break;
		case 97: output = 97; break;
		case 98: output = 98; break;
		case 99: output = 99; break;
		case 100: output = 100; break;
		case 101: output = 101; break;
		case 102: output = 102; break;
		case 103: output = 103; break;
		case 104: output = 104; break;
		case 105: output = 105; break;
		case 106: output = 106; break;
		case 107: output = 107; break;
		case 108: output = 108; break;
		case 109: output = 109; break;
		case 110: output = 110; break;
		case 111: output = 111; break;
		case 112: output = 112; break;
		case 113: output = 113; break;
		case 114: output = 114; break;
		case 115: output = 115; break;
		case 116: output = 116; break;
		case 117: output = 117; break;
		case 118: output = 118; break;
		case 119: output = 119; break;
		case 120: output = 120; break;
		case 121: output = 121; break;
		case 122: output = 122; break;
		case 123: output = 123; break;
		case 124: output = 124; break;
		case 125: output = 125; break;
		case 126: output = 126; break;
		case 127: output = 127; break;
		case 128: output = 128; break;
		case 129: output = 129; break;
		case 130: output = 130; break;
		case 131: output = 131; break;
		case 132: output = 132; break;
		case 133: output = 133; break;
		case 134: output = 134; break;
		case 135: output = 135; break;
		case 136: output = 136; break;
		case 137: output = 137; break;
		case 138: output = 138; break;
		case 139: output = 139; break;
		case 140: output = 140; break;
		case 141: output = 141; break;
		case 142: output = 142; break;
		case 143: output = 143; break;
		case 144: output = 144; break;
		case 145: output = 145; break;
		case 146: output = 146; break;
		case 147: output = 147; break;
		case 148: output = 148; break;
		case 149: output = 149; break;
		case 150: output = 150; break;
		case 151: output = 151; break;
		case 152: output = 152; break;
		case 153: output = 153; break;
		case 154: output = 154; break;
		case 155: output = 155; break;
		case 156: output = 156; break;
		case 157: output = 157; break;
		case 158: output = 158; break;
		case 159: output = 159; break;
		case 160: output = 160; break;
		case 161: output = 161; break;
		case 162: output = 162; break;
		case 163: output = 163; break;
		case 164: output = 164; break;
		case 165: output = 165; break;
		case 166: output = 166; break;
		case 167: output = 167; break;
		case 168: output = 168; break;
		case 169: output = 169; break;
		case 170: output = 170; break;
		case 171: output = 171; break;
		case 172: output = 172; break;
		case 173: output = 173; break;
		case 174: output = 174; break;
		case 175: output = 175; break;
		case 176: output = 176; break;
		case 177: output = 177; break;
		case 178: output = 178; break;
		case 179: output = 179; break;
		case 180: output = 180; break;
		case 181: output = 181; break;
		case 182: output = 182; break;
		case 183: output = 183; break;
		case 184: output = 184; break;
		case 185: output = 185; break;
		case 186: output = 186; break;
		case 187: output = 187; break;
		case 188: output = 188; break;
		case 189: output = 189; break;
		case 190: output = 190; break;
		case 191: output = 191; break;
		case 192: output = 192; break;
		case 193: output = 193; break;
		case 194: output = 194; break;
		case 195: output = 195; break;
		case 196: output = 196; break;
		case 197: output = 197; break;
		case 198: output = 198; break;
		case 199: output = 199; break;
		case 200: output = 200; break;
		case 201: output = 201; break;
		case 202: output = 202; break;
		case 203: output = 203; break;
		case 204: output = 204; break;
		case 205: output = 205; break;
		case 206: output = 206; break;
		case 207: output = 207; break;
		case 208: output = 208; break;
		case 209: output = 209; break;
		case 210: output = 210; break;
		case 211: output = 211; break;
		case 212: output = 212; break;
		case 213: output = 213; break;
		case 214: output = 214; break;
		case 215: output = 215; break;
		case 216: output = 216; break;
		case 217: output = 217; break;
		case 218: output = 218; break;
		case 219: output = 219; break;
		case 220: output = 220; break;
		case 221: output = 221; break;
		case 222: output = 222; break;
		case 223: output = 223; break;
		case 224: output = 224; break;
		case 225: output = 225; break;
		case 226: output = 226; break;
		case 227: output = 227; break;
		case 228: output = 228; break;
		case 229: output = 229; break;
		case 230: output = 230; break;
		case 231: output = 231; break;
		case 232: output = 232; break;
		case 233: output = 233; break;
		case 234: output = 234; break;
		case 235: output = 235; break;
		case 236: output = 236; break;
		case 237: output = 237; break;
		case 238: output = 238; break;
		case 239: output = 239; break;
		case 240: output = 240; break;
		case 241: output = 241; break;
		case 242: output = 242; break;
		case 243: output = 243; break;
		case 244: output = 244; break;
		case 245: output = 245; break;
		case 246: output = 246; break;
		case 247: output = 247; break;
		case 248: output = 248; break;
		case 249: output = 249; break;
		case 250: output = 250; break;
		case 251: output = 251; break;
		case 252: output = 252; break;
		case 253: output = 253; break;
		case 279: output = 279; break;
		case 254: output = 254; break;
		case 255: output = 255; break;
		case 256: output = 256; break;
		case 257: output = 257; break;
		case 258: output = 258; break;
		case 259: output = 259; break;
		case 260: output = 260; break;
		case 261: output = 261; break;
		case 262: output = 262; break;
		case 263: output = 263; break;
		case 264: output = 264; break;
		case 265: output = 265; break;
		case 266: output = 266; break;
		case 267: output = 267; break;
		case 268: output = 268; break;
		case 269: output = 269; break;
		case 270: output = 270; break;
		case 271: output = 271; break;
		case 272: output = 272; break;
		case 273: output = 273; break;
		case 274: output = 274; break;
		case 275: output = 275; break;
		case 276: output = 276; break;
		case 277: output = 277; break;
		case 278: output = 278; break;
		case 280: output = 267; break;
		case 281: output = 268; break;
		case 282: output = 269; break;
		case 283: output = 270; break;
		case 284: output = 271; break;
		case 285: output = 272; break;
		case 286: output = 273; break;
		case 287: output = 274; break;
		case 288: output = 275; break;
		case 289: output = 276; break;
		case 290: output = 277; break;
		case 291: output = 278; break;
		case 292: output = 273; break;
		case 293: output = 274; break;
		case 294: output = 275; break;
		case 295: output = 276; break;
		case 296: output = 277; break;
		case 297: output = 278; break;
		case 298: output = 278; break;
		case 299:
			output = val;
			break;
		default:
			break;
		}
	}

	void lookupTableFunc(int val, int& output)
	{
		static const int arr[300] = {
			0,
			1,
			2,
			3,
			4,
			5,
			6,
			7,
			8,
			9,
			10,
			11,
			12,
			13,
			14,
			15,
			16,
			17,
			18,
			19,
			20,
			21,
			22,
			23,
			24,
			25,
			26,
			27,
			28,
			29,
			30,
			31,
			32,
			33,
			34,
			35,
			36,
			37,
			38,
			39,
			40,
			41,
			42,
			43,
			44,
			45,
			46,
			47,
			48,
			49,
			50,
			51,
			52,
			53,
			54,
			55,
			56,
			57,
			58,
			59,
			60,
			61,
			62,
			63,
			64,
			65,
			66,
			67,
			68,
			69,
			70,
			71,
			72,
			73,
			74,
			75,
			76,
			77,
			78,
			79,
			80,
			81,
			82,
			83,
			84,
			85,
			86,
			87,
			88,
			89,
			90,
			91,
			92,
			93,
			94,
			95,
			96,
			97,
			98,
			99,
			100,
			101,
			102,
			103,
			104,
			105,
			106,
			107,
			108,
			109,
			110,
			111,
			112,
			113,
			114,
			115,
			116,
			117,
			118,
			119,
			120,
			121,
			122,
			123,
			124,
			125,
			126,
			127,
			128,
			129,
			130,
			131,
			132,
			133,
			134,
			135,
			136,
			137,
			138,
			139,
			140,
			141,
			142,
			143,
			144,
			145,
			146,
			147,
			148,
			149,
			150,
			151,
			152,
			153,
			154,
			155,
			156,
			157,
			158,
			159,
			160,
			161,
			162,
			163,
			164,
			165,
			166,
			167,
			168,
			169,
			170,
			171,
			172,
			173,
			174,
			175,
			176,
			177,
			178,
			179,
			180,
			181,
			182,
			183,
			184,
			185,
			186,
			187,
			188,
			189,
			190,
			191,
			192,
			193,
			194,
			195,
			196,
			197,
			198,
			199,
			200,
			201,
			202,
			203,
			204,
			205,
			206,
			207,
			208,
			209,
			210,
			211,
			212,
			213,
			214,
			215,
			216,
			217,
			218,
			219,
			220,
			221,
			222,
			223,
			224,
			225,
			226,
			227,
			228,
			229,
			230,
			231,
			232,
			233,
			234,
			235,
			236,
			237,
			238,
			239,
			240,
			241,
			242,
			243,
			244,
			245,
			246,
			247,
			248,
			249,
			250,
			251,
			252,
			253,
			254,
			255,
			256,
			257,
			258,
			259,
			260,
			261,
			262,
			263,
			264,
			265,
			266,
			267,
			268,
			269,
			270,
			271,
			272,
			273,
			274,
			275,
			276,
			277,
			278,
			279,
			280,
			281,
			282,
			283,
			284,
			285,
			286,
			287,
			288,
			289,
			290,
			291,
			292,
			293,
			294,
			295,
			296,
			297,
			298,
			299
		};
		output = arr[val];
	}

	void example()
	{
		const int iterations = 100000;

		{
			Timer timer(Timer::TimeFrequency::Microseconds);

			int val = 299;
			int output = 0;

			timer.StartClock();
			for (int i = 0; i < iterations; i++)
			{
				switchFunc(val, output);
			}
			timer.StopClock();
			std::cout << "Testing time: " << timer.GetStopClock() << '\n';
		}
		{
			Timer timer(Timer::TimeFrequency::Microseconds);

			int val = 299;
			int output = 0;

			timer.StartClock();
			for (int i = 0; i < iterations; i++)
			{
				lookupTableFunc(val, output);
			}
			timer.StopClock();
			std::cout << "Testing time: " << timer.GetStopClock() << '\n';
		}
	}

	void start()
	{
		explained();
		example();
	}
}

