#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSTRLEN 100

char leString();

int main()
{
	
	return 0;
}

char leString(){
	char str[MAXSTRLEN], c;
	int i = 0;

	if ((c = getchar()) == '\n')
		c = getchar();
	while (c != '\n' && c != EOF){
		str[i++] = c;
		c = getchar();
	}
	str[i] = '\0';
	
	return str;
}