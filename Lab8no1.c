#include <stdio.h>
int findMax(int num[],int size);
void printAr(int myAr[],int size);
void addthree(int number[], int pos[][2],int size); 


main() {
	int number[5] = {20,50,100,99,9};
	int size = sizeof(number)/sizeof(number[0]);
	int plus[3][2];
	int max,position,value;

	max = findMax(number,size);
	printAr(number,size);
	printf("Maximum of these number is %d\n",max);
	addthree(number,plus,size);
	printAr(number,size);
	
	return 0;
}


void addthree(int number[], int pos[][2],int size){
	int i;
	printf("position and value you want to add\n");
	for (i=0;i<3;i++){
		printf("%d)plus[position][value]=",i+1);
		scanf("%d %d",&pos[i][0],&pos[i][1]);
	}	
	for(i=0;i<3;i++){
	    int position = pos[i][0];
	    int value = pos[i][1];
		
		if(position>=0&&position<size)
	    	number[position] += value;
	}	
}
void printAr(int myAr[],int size){
	int i;
	for (i=0;i<size;i++)
		printf("number[%d] : %d\n",i,myAr[i]);
}
int findMax(int num[],int size) {
	int maximum,i=0;
	maximum = num[i];
	for(i=0;i<size;i++) {
		if(num[i] > maximum)
			maximum = num[i];
	}
	return maximum;
}

