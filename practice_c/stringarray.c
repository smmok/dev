#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	//char string[3][30] = {"StringOne", "StringTwo", "StringThree"};
	char* string[] = {"StringOne", "StringTwo", "StringThree"};

	for (int i=0; i<3; i++)
	{
		printf("String[%d]=%s\n", i, string[i]);
	}
	
	return 0;
}


