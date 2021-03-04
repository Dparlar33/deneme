#include <stdio.h>
#include <stdlib.h>
int biggest=0;
int number1=0;
int number2=0;
int number3=0;


void degerlendir(int a ,int b, int c){
	int result;
	result = a*b*c;
	printf("%d - %d -%d \n",a,b,c);					//karsýlastýrma
	if(result>biggest){
		biggest=result;
		number1=a;
		number2=b;
		number3=c;
	}
}


int main(int argc, char *argv[]) {
	int size=9;	
	FILE * fp;
    fp = fopen("data.txt", "r");
	int vector[9][9];				//Dosya açýmý 

	while(!feof(fp)){
		
		int i=0;
		int j=0;
		for(j;j<size;j++){													//dosyadan vektöre deðer atama
			i=0;
			for(i;i<size;i++){
				fscanf(fp,"%d",&vector[j][i]);
			}
		}
	}	
	
	/*int a=0,b=0;
	for(a;a<size;a++){
		b=0;
		for(b;b<size;b++){                                             // veri kontrol 
			printf("%6d",vector[a][b]);
		}
		
		printf("\n\n\n");
	}*/
	
	int x=0,y=0;                   //x satýr y sütün  soldan saða deðil yukarýdan aþaðýya geziniyoruz vectorde. 
	for(x;x<size;x++){
		y=0;
		for(y;y<size;y++){
			
			if((x+1),(x+2) <= size-1 ){
				degerlendir(vector[y][x],vector[y][x+1],vector[y][x+2]);  //sagý
			}
			
			if((x-1),(x-2) >= 0){
				degerlendir(vector[y][x],vector[y][x-1],vector[y][x-2]);	//solu
			}
		
			if((y-1),(y-2) >= 0){
				degerlendir(vector[y][x],vector[y-1][x],vector[y-2][x]);	//üstü
			}
			
			if((y+1),(y+2) <= size-1){
				degerlendir(vector[y][x],vector[y+1][x],vector[y+2][x]);	//asagýyý
			}
		
			if((y+1),(y+2) <= size-1 ){
				if((x+1),(x+2) <= size-1){
						degerlendir(vector[y][x],vector[y+1][x+1],vector[y+2][x+2]);			//sað alt çapraz
				}
				   
			}
		
			if((y+1),(y+2)  <= size -1 ){
				if((x-1),(x-2) >= 0){
					degerlendir(vector[y][x],vector[y+1][x-1],vector[y+2][x-2]);			// sol alt capraz
				}
					
			}
		
			if((y-1),(y-2) >= 0  ){
				if((x-1),(x-2) >= 0){
					degerlendir(vector[y][x],vector[y-1][x-1],vector[y-2][x-2]);		// sol üst capraz
				}
				
			}
			
			if((y-1),(y-2) >= 0  ){
				if((x+1),(x+2) <= size-1){
					degerlendir(vector[y][x],vector[y-1][x+1],vector[y-2][x+2]);		// sað üst capraz
			}
			}
		}
	}
	
	printf("%d",biggest);
	printf(" Three number : %d - %d - %d",number1,number2,number3);
	
	return 0;
}
