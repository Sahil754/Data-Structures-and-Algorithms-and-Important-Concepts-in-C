/*Define a new data structure, named "person", which contains a string (pointer to char) called name, and an integer called age.*/

#include <stdio.h>

struct person
{
	char *name;
	int age;
};

int main()
{
	struct person a= {"Sam",23};
	printf("Person name: %s\nPerson age: %d\n",a.name,a.age);
	return 0;
}
