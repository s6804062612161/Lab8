#include <stdio.h>
int checkscore(char std[],char key[]);
int checkitem(char std[][10],char key[]);
int the_difficult(char std[][10],char key[]);

int main() {
    int i;
    char ans[8][10]={
        	{'A','B','A','C','C','D','E','E','A','D'},//7
			{'D','B','A','B','C','A','E','E','A','D'},//6
			{'E','D','D','A','C','B','E','E','A','D'},//5
			{'C','B','A','E','D','C','E','E','A','D'},//4
			{'A','B','D','C','C','D','E','E','A','D'},//8
			{'B','B','E','C','C','D','E','E','A','D'},//7
			{'B','B','A','C','C','D','E','E','A','D'},//7
			{'E','B','E','C','C','D','E','E','A','D'}};//7
			
	char keys[10]={'D','B','D','C','C','D','A','E','A','D'};
   	for (i=0;i<8;i++){
		printf("std %d => %d\n", (i+1), checkscore(ans[i],keys));
	}
	printf("Number of people who answered question 1 correct is %d\n",checkitem(ans,keys));
	printf("the difficult item is %d\n",the_difficult(ans,keys));
	
	return 0;
}

int the_difficult(char std[][10],char key[]){
	int amount=0;
	int difficult=9; 
	int currentitem,item,result;
	int i,j;
	for (i=0;i<10;i++){
		item = i;	
		amount=0;
		for (j=0;j<8;j++){
			if (std[j][i]==key[i])
				amount++;		
		}
		currentitem=amount;
		if (difficult > currentitem){
			difficult = currentitem;
			result=item+1;	
		}	
	}
	return result;
}

int checkitem(char std[][10],char key[]){
	int amount=0;
	int i;
	for (i=0;i<8;i++){
		if (std[i][0]==key[0])
			amount++;
	}
	return amount;
}
int checkscore(char std[],char key[]){
	int score=0,i;
	for (i=0;i<10;i++){
		if (std[i]==key[i])
			score++;
	}
	
	return score;
}

