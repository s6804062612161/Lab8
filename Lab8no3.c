#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random1to100();
void printAr(int numAr[],int numArSize);
int checkNum(int numAr[],int numArSize);
int searchNum(int numAr[],int numArSize,int target);
void sortAr(int numAr[], int numArSize);


int main() {
    int N,i;
    int A[100];
    scanf("%d",&N);
    if (N>100) 
        N=100;
    srand(time(NULL));
    for (i=0;i<N;i++){
        A[i]=checkNum(A,i);
        sortAr(A, i + 1);	
	}    
    printf("\n********\n");
    printAr(A,N);
    
    return 0;
}



void printAr(int numAr[],int numArSize) {
    int i;
    for (i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
} 

int checkNum(int numAr[],int numArSize) {
    int rnum;
    rnum=random1to100();
    while (searchNum(numAr,numArSize,rnum)) {
        rnum=random1to100();
    }
    return rnum;
}

void sortAr(int numAr[], int numArSize) {
    int i, j, min_index, temp;
    for (i = 0; i < numArSize - 1; i++) {
        min_index = i;
        for (j = i + 1; j < numArSize; j++)
            if (numAr[j] < numAr[min_index])
                min_index = j;
        temp = numAr[min_index];
        numAr[min_index] = numAr[i];
        numAr[i] = temp;
    }
}

int searchNum(int numAr[],int numArSize, int target) {
		//sol2 use binary search  see.Lab6no9-10 
        int i,found=0;
        int low=0;
        int high = numArSize-1;
        while (low<=high){
        	int mid = low + (high-low) /2;
        	if (numAr[mid]==target)
        		found = 1;
        	if (numAr[mid]<target)
        		low = mid +1;
        	else
        		high = mid-1;
		}
        return found;
}

int random1to100() {
    int random_num = (rand() % 100) + 1;
    printf("%d ", random_num);
    return random_num;
}

