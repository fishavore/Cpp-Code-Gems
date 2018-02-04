#pragma once


/*

Generally char versus strings:

There is a big difference between a char array and a string array. A string array is just a char array
where you have put a null char: \0 - that marks the end of the string. If you were to put therefore an
array of: A, B, C, \0, D, \0. A string would only take ABC.

Now I would imagine some would ask, why the hell would we ever want to store a null char?

Well... because it is not about what is actually stored in terms of characters but more to the actual
bits. Let's assume you wish to send network data where each bit represent something, like a flag, then
it wouldn't really matter what you tinker around with.

*/

/*

Chars has apparently undergone a rather significant change in the past 20 years. In the past companies
has real issues with memory rather than computation power. This has lead to that systems may have bisarr
C implementations which compute in char arrays rather than using basic strings. What that also means is
that these old systems do not use modern functions of char implementations. You see, chars are very error
prone. You have to be very careful not to exceed writing over your char array size. The majority of the
char functions have been expanded upon with "_s" to indicate that they are "_safe". Also, additional
functions may have been added to do the exact same thing but differently. 

Example: strcpy (bad), strncpy (good alternative), strcpy_s (good?(haven't actually used yet)). //todo? lul

*/


namespace DealingWithChars
{
	void start()
	{
		
	}
}