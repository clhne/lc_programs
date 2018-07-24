#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *name;
	char *address;
	char *sex;
	int age;
}PROFILE;

PROFILE A;

void PROFILE_Init(){
	A.name = (char *)"July";
	A.address = (char *)"ShangHai";
	A.sex = (char *)"male";
	A.age = 27;
}

int main()
{
	PROFILE_Init();
	printf("name = %s\naddress = %s\nsex = %s\nage = %d\n", A.name, A.address, A.sex, A.age);
	return 0;
}
