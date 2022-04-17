#include "Solution_LengthofLastWord.h"
int Solution_LengthofLastWord::lengthOfLastWord(string s)
{
	unsigned int length = 0;
	size_t s_length = s.length();
	if (s_length < 0)
		return 0;
	unsigned int i;
	for (i = s_length - 1; ; i--)
	{

		if (s[i] == (' '))
		{


			if (length != 0)
				break;
		}
		else
			length += 1;

	}
	return length;
}

int Solution_LengthofLastWord::driver_Fucntion()
{
	Solution_LengthofLastWord s;
	int length = s.lengthOfLastWord("Hello World Ans ");
	std::cout << length;
	return 0;
}