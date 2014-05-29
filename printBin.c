#include<stdio.h>

void printBin(int value, int length){

	int max = 1 <<(length -1);
	while (max>0){
		if (value >= max){
			printf("%d",1);
			value = value - max;
		}else{
			printf("%d",0);
		}
		max = max / 2;
	}

}
