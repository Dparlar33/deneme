#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int right_answer[6];
int user_answer[6];

int control(int answer,int soru){
	
	if(right_answer[soru]==answer){
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void questions(int a,int b,int question_order){
	
	printf("\n");
	printf("\n%d) %d x %d = ",question_order+1,a,b);
	scanf("%d",&user_answer[question_order]);
	right_answer[question_order]=a*b;
	
}


int main(int argc, char *argv[]) {

	printf("-----Instruction READ PLS -----\n");
	printf("There are 6 multiplaction questions,you have 7 second on every single question and every single question is 5 point.\n");
	printf("You need at least 4 True answer for success !\n");																	 		//Insturction about test
	printf("To starting enter something . Good luck :) ! ");
	getch();
	
	int t=0;
	int f=0;
	
	srand(time(NULL));
	int number1=rand()%15+15;
	int number2=rand()%10+1;						//Random variables
	
	clock_t time;
	clock_t time2;					//Describing Timing  time is every single question time , time 2 is total time .
	time2=clock();
	
	int j=0;
	for(j;j<6;j++){
		time=clock();
		
		questions(number1,number2,j);		//Questions and Answers
		number1=rand()%15+15;
		number2=rand()%10+1;
	
		time=clock()-time;				
		
		if(((double)time) / CLOCKS_PER_SEC > 7.00){
			printf("Time limit is passed you spent %0.2f second in this question !!\n",((double)time) / CLOCKS_PER_SEC);		//Calculating questions time 
			printf("This question will be invalid !\n");
			break;
		}
		else
		{
			if(control(user_answer[j],j)){
				t++;
			}
			else												//If time is normal ,evaluate point
			{
				f++;
			}
		}
	}
	time2=clock()-time2;
	
	int point= t*5;

	printf("Total point = %d,%d - T , %d -F, %0.2f second total time  ! \n",point,t,f,((double)time2) / CLOCKS_PER_SEC);			//Writiing total point false true answer and time
	
	
	if(t >= 4){
		printf("Congratulations ! ");
	}
	else																						//Evaluate to result 
	{
		printf("Try Again Don't give up !'");
	}
	return 0;
}
