#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
int HashSize=0;

typedef struct List{
	char name[50];
}Name_list;	



void HashSizeCalculating(int n){
	int i,flag;
	for(n;n<n*2;n++){ 
		flag=1;
		for (i=2;i<n;i++){
			if (n%i==0){
				flag=0;
			}
		}								//this function calculating HashSize as a prime number.
		
		if (flag==1){
			HashSize=n;
			break;
		}
	}	
}

int HashCalculate(char *name){

	int x,y,z,total;
	x=name[3]-48;
	y=name[5]-48;					// It belongs me .
	z=name[15]-48;
	total=pow(abs(x+y-z),3);
	
	return total%HashSize;
}

	
int main(int argc, char *argv[]) {
	

	srand(time(NULL));
	FILE *fp;
	fp=fopen("liste.txt","r");
	int name_counter=1;
	char ch;
	
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n')
		{												//Calculating how many names are there in the text.
		    name_counter++;
		}
	}
	
	HashSizeCalculating(name_counter);				// HashValue has to be prime number and bigger than DataSize so it's calculating Hashsize.
	Name_list HashTable[HashSize];					//Names struct array is taking names from text and HashTable is our hashtable.
	


	int j=0;
	for(j;j<HashSize;j++){
		strcpy(HashTable[j].name,"");						//Creating hashtable
	}
	
	
	FILE *file;
	file=fopen("liste.txt","r");				//Again file is opened bcs it was closed above
	int t=0;
	int value_of_names;
	for(t;t<name_counter;t++){
		char c[50];
		fgets(c,50,file);
		value_of_names =  HashCalculate(c);
		if(strcmp(HashTable[value_of_names].name,"")==0){
			strcpy(HashTable[value_of_names].name,c);							//Located names into hashtable.
		}
		else
		{
			int coll=1;											//collision part.
			while(coll<HashSize){
				
				value_of_names=value_of_names + coll*coll;
				value_of_names = value_of_names % HashSize;						//Located names into hashtable.
			
				if(strcmp(HashTable[value_of_names].name,"")==0){
					strcpy(HashTable[value_of_names].name,c);
					break;
				}
			
				coll++;
			}
		}
	}
	
	
/*	int m=0;
    for(m;m<HashSize;m++){
		printf("%s \n",HashTable[m].name);					//Controlling Hashtable
	}*/
	
	int member;
	printf("There are %d members in list.  How many people will win from draw ? = ",name_counter);
	scanf("%d",&member);
	
	int y=0;
	int result=0;
	for(y;y<member;y++){
		result = rand() % HashSize;
		printf("%d. Winner names : %s\n",y+1,HashTable[result]);
	}
	
	
	
}
