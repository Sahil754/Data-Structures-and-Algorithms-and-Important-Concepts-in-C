#include<stdio.h>

int main(){
	int math;
	int physics;
	int grades[2][6]= {{10,20,30,40,50},
			   {60,70,80,90,10}};
	math = (grades[0][0]+grades[0][1]+grades[0][2]+grades[0][3]+grades[0][4]+grades[0][5])/5;
	physics = (grades[1][0]+grades[1][1]+grades[1][2]+grades[1][3]+grades[1][4]+grades[1][5])/5;

	printf("The average for math is:%d,\nThe average for physics is:%d\n",math,physics);
	return 0;
}
