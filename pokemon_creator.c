/* 2019 SPRING CSE102 HW1 
Student: Zeynep Goksoy*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3
#define SQUARE 1
#define RECTENGULAR 2
#define CIRCULAR 3
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4


double CreateBody (int shape);
int SetColor (int color);
double LoadMoves(int shape, double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);

int main ()
{
	int shape, color, attack_power;
	double size_of_body, move_length;

	shape = CIRCULAR; //CIRCULAR/RECTENGULAR/SQUARE Pick one of them
	size_of_body = CreateBody(shape);
	color = 798;
	color = SetColor(color);
	move_length = LoadMoves(shape, size_of_body);
	attack_power = SetAttackPower (0, 150);
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);

}

double CreateBody (int shape){

	double side1,side2,radius,area;


		if(shape==SQUARE){
			printf("enter a side value for Square\n");
			scanf("%lf",&side1);
			area=side1*side1;
		}

		else if(shape==RECTENGULAR){
			printf("enter side values for rectangular\n");
			printf("row:");
			scanf("%lf",&side1);
			printf("column:");
			scanf("%lf",&side2);
			area=side1*side2;
		}

		else if(shape==CIRCULAR){
			printf("Please enter radius value\n");
			scanf("%lf",&radius);
			area=PI*radius*radius;
		}

	return area;
}

int SetColor (int color){

	if(color>=0 && color<=1000){
		color=color%5;
	}
	else 
		color=1;
	
	return color;//with return color the function return whatever the color is 
}

double LoadMoves(int shape, double body_size){
	
	double side,move,radius;
	//We calculate the sides of each shape by looking their body_size
	if(shape==SQUARE){
		side=sqrt(body_size);
		move=side*4;
	}

	else if(shape==RECTENGULAR){
		side=body_size/5.0;
		move=2*(side+5.0);
	}

	else if(shape==CIRCULAR){
		radius=sqrt(body_size/PI);
		move=2*PI*radius;
	}

	return move;
}

int SetAttackPower(int lower_bound, int upper_bound){

	int random_attack_power;

	srand(time(NULL));
	random_attack_power=lower_bound+rand()%(upper_bound-lower_bound);
	//if we want a number between 5-25 we write 5+rand()%20 so by looking this example i subtract lower_bound from upper_bound
	
	return random_attack_power;

}

void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){

	int side,radius,row,column,row_circular,space,number_of_tab,reverse_number_of_tab,i,k,n;

	//??emberin sat??r say??s?? ald??????m??z radius ??ift ise radiusun bir fazlas?? , radius tek ise ald??????m??z radius say??s?? kadar oluyor
	radius=sqrt(body_size/PI);//cemberi cizerken ??emberin ??st k??sm??n?? ve alt k??sm??n?? iki parcaya ay??r??p ??izdim
	row_circular=(radius/2)+1;//taban kabul etti??imiz sat??r ile(R-1'in bulundu??u sat??r) ??emberin yukar??s??nda her zaman (radius/2)+1 kadar sat??r bulunuyor   
	n=radius;//n'i iki X aras??ndaki bo??u??u belirlerken kullanmak i??in tan??mlad??m ve radiusu n'e atad??m
	number_of_tab=row_circular-2;//ba??lang????tan ilk x'e kadar olan tab say??s?? radius/2-1 ile ba??l??yor ve tabana do??ru birer birer azal??yor  
	reverse_number_of_tab=1;//reverse_number_of_tab ??emberin ??st b??lgesi i??in uygulad??????m??z tab b??rakma i??leminin alt ??ember i??in uygulanmas?? 
	
	if(shape==RECTENGULAR){
		
		side=body_size/5.0;

			for(row=1 ; row<=5 ; row++){
				for(column=1 ; column<=side ; column++){
					printf("X");
				}
				printf("\n");
			}	
		printf("Name: Rectangular Pok??mon\n");
	}

	if(shape==SQUARE){
		
		side=sqrt(body_size);

			for(row=1 ; row<=side ; row++){
				for(column=1 ; column<=side ; column++){
					printf("X");
				}
				printf("\n");
			}	
		
		printf("Name: Square Pok??mon\n");
	}
	if(shape==CIRCULAR){

		for(i=1 ; i<=row_circular ; i++){

			if(i==1){
				
				for(space=(number_of_tab) ; space>0 ; space--){
					printf("\t");
				}
				printf("    ");
				printf("X");
			}
			else{

				for(space=(number_of_tab) ; space>0 ; space--){
					printf("\t");
				}	
				printf("X");
				for(k=0 ; k<radius-(n-1) ; k++){
					printf("\t");
				}
				printf("X" );
				n=n-2;
				number_of_tab--;
			}

			printf("\n");	
		}

		for(i=1 ; i<=row_circular-1 ; i++){

			if(i==row_circular-1){
				
				for(space=1 ; space<reverse_number_of_tab  ; space++){
					printf("\t");
				}
				printf("    ");
				printf("X");
			}
			else{

				for(space=0 ; space<reverse_number_of_tab  ; space++){
					printf("\t");
				}	
				printf("X");
				for(k=0 ; k<radius-(n+3) ; k++){
					printf("\t");
				}
				printf("X" );
				n=n+2;
				reverse_number_of_tab++;
			}

		printf("\n");
		}
	printf("Name: Circular Pok??mon\n");
	}

	printf("Size:%.2lf\n",body_size );

/* red is 0, yellow is
1, blue is 2, black is 3 and white is 4. */
	if(color==0){
		printf("Color:RED\n");
	}
	else if(color==1){
		printf("Color:YELLOW\n");	
	}
	else if(color==2){
		printf("Color:BLUE\n");
	}
	else if(color==3){
		printf("Color:BLACK\n");	
	}
	else if(color==4){
		printf("Color:WHITE\n");
	}
	printf("Move:%.2lf\n",move_length);
	printf("Attack_power:%d\n",attack_power);
}




