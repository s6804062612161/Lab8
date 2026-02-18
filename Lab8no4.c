#include <stdio.h>
int checkscore(char std[],char key[]);
void printAr(int numAr[]);
void printBest3(int scores[]);

int main() {
    int i;
    int std[4]={0};
    char ans[4][10]={
			{'D','B','A','B','C','A','E','E','A','D'},//6
			{'E','D','D','A','C','B','E','E','A','D'},//5
			{'C','B','A','E','D','C','E','E','A','D'},//4
			{'A','B','D','C','C','D','E','E','A','D'}};//8

			
	char keys[10]={'D','B','D','C','C','D','A','E','A','D'};
   	for (i=0;i<4;i++){
		std[i]=checkscore(ans[i],keys);
	}
	printf("std[4] = ");
	printAr(std);
	printBest3(std);
	return 0;
}

int checkscore(char std[],char key[]){
	int score=0,i;
	for (i=0;i<10;i++){
		if (std[i]==key[i])
			score++;
	}
	return score;
}
void printAr(int numAr[]) {
    int i;
    for (i=0;i<4;i++)
        printf("%d ",numAr[i]);
    printf("\n");
} 

void printBest3(int scores[]) {
    int i,j,temp;
    for (i=0;i<4-1;i++) {
        for (j=i+1;j<4;j++) {
            if (scores[i] < scores[j]) { 
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
    printf("top 3 scores: %d,%d,%d\n", scores[0], scores[1], scores[2]);
}

