/*********HW7********
*****ZEYNEP GOKSOY***
********************/
/****MONOPOLY GAME****/

#include <stdio.h>

typedef enum{noone,cap,car}player_type;
typedef enum{start,property,tax,punish}block_type;
typedef struct{
	player_type type;//Holds type of the player. The player_type must be defined as enumerated type which consist of noone, cap and car values.
	int current_block_id;//Holds player location as block id.
	int owned_block_ids[11];//Holds property block ids that are owned by the user.
	int account;// Holds amount of the current money of the player.
	int turn_to_wait;//Holds number of turns to wait if the player got a punishment.
	char * name;// Holds the name of the player.
}player;

typedef struct{
	int block_id;// Holds id of the block.
	char *name;// Holds text of the block that is shown on the top of the block.
	int price;// If the block is property, holds the price of property.If the block is a tax block than holds the tax fee and if the block is punishment block, then holds the number of
				//turns to wait
	int rent;//Holds the default rent of a property (no house).
	int rent_1;// Holds the rent of a property with one house.
	int rent_2;//Holds the rent of a property with two houses.
	int rent_3;//Holds the rent of a property with three houses.
	int house_price;//Holds price of building a house on the block.
	int house_count;//Holds the number of the houses on the block that are already built.
	player owner;//Holds the owner of the block.
	block_type type;//Holds type of the block. The block_type must be defined as enumerated type which consist of start, property, tax, punish values.
}block;

void init_the_board( block board[20]);
void show_board( block board[20],player player_one, player player_two);
void show_properties( block board[20]);
void buy_property( block* current_block, player* current_player);
void sell_property( block board[20], player* current_player);
void gameplay( block board[20], player player_one, player player_two);
void buy_house( block* current_block, player* current_player);

int main(){

	block board[20];

	player player_one;
	player_one.account=100000;
	player player_two;
	player_two.account=100000;
		
	player_one.current_block_id=start;
	player_two.current_block_id=start;
	init_the_board(board);
	show_board(board,player_one,player_two);
	show_properties(board);

}

void init_the_board( block board[20]){

	board[0].name="Start";
	board[0].block_id=0;
	board[0].price=0;
	board[0].rent=0;
	board[0].rent_1=0;
	board[0].rent_2=0;
	board[0].rent_3=0;
	board[0].house_price=0;
	board[0].type=start;
	board[0].house_count=0;
	board[0].owner.type=noone;

	board[1].name="Esenyurt";
	board[1].block_id=1;
	board[1].price=16000;
	board[1].rent=800;
	board[1].rent_1=4000;
	board[1].rent_2=9000;
	board[1].rent_3=25000;
	board[1].house_price=10000;
	board[1].type=property;
	board[1].house_count=0;	
	board[1].owner.type=noone;

	board[2].name="Car Park";
	board[2].block_id=2;
	board[2].price=0;
	board[2].rent=1500;
	board[2].rent_1=0;
	board[2].rent_2=0;
	board[2].rent_3=0;
	board[2].house_price=0;
	board[2].type=tax;
	board[2].house_count=0;
	board[2].owner.type=noone;

	board[3].name="Tuzla";
	board[3].block_id=3;
	board[3].price=16500;
	board[3].rent=850;
	board[3].rent_1=4250;
	board[3].rent_2=9500;
	board[3].rent_3=26000;
	board[3].house_price=12000;
	board[3].type=property;
	board[3].house_count=0;
	board[3].owner.type=noone;

	board[4].name="Arnavutkoy";
	board[4].block_id=4;
	board[4].price=17000;
	board[4].rent=875;
	board[4].rent_1=4500;
	board[4].rent_2=10000;
	board[4].rent_3=28000;
	board[4].house_price=12000;
	board[4].type=property;
	board[4].house_count=0;	
	board[4].owner.type=noone;

	board[5].name="Wait 2 Turn";
	board[5].block_id=5;
	board[5].price=0;
	board[5].rent=2;
	board[5].rent_1=0;
	board[5].rent_2=0;
	board[5].rent_3=0;
	board[5].house_price=0;
	board[5].type=punish;
	board[5].house_count=0;
	board[5].owner.type=noone;

	board[6].name="Catalca";
	board[6].block_id=6;
	board[6].price=20000;
	board[6].rent=1000;
	board[6].rent_1=5000;
	board[6].rent_2=12000;
	board[6].rent_3=30000;
	board[6].house_price=13000;
	board[6].type=property;
	board[6].house_count=0;
	board[6].owner.type=noone;

	board[7].name="Beykoz";
	board[7].block_id=7;
	board[7].price=23000;
	board[7].rent=1100;
	board[7].rent_1=5500;
	board[7].rent_2=12500;
	board[7].rent_3=33000;
	board[7].house_price=13000;
	board[7].type=property;
	board[7].house_count=0;	
	board[7].owner.type=noone;

	board[8].name="Car Fix";
	board[8].block_id=8;
	board[8].price=0;
	board[8].rent=1750;
	board[8].rent_1=0;
	board[8].rent_2=0;
	board[8].rent_3=0;
	board[8].house_price=0;
	board[8].type=tax;
	board[8].house_count=0;
	board[8].owner.type=noone;

	board[9].name="Maltepe";
	board[9].block_id=9;
	board[9].price=30000;
	board[9].rent=1350;
	board[9].rent_1=7000;
	board[9].rent_2=15000;
	board[9].rent_3=40000;
	board[9].house_price=15000;
	board[9].type=property;
	board[9].house_count=0;
	board[9].owner.type=noone;

	board[10].name="Bills";
	board[10].block_id=10;
	board[10].price=0;
	board[10].rent=2000;
	board[10].rent_1=0;
	board[10].rent_2=0;
	board[10].rent_3=0;
	board[10].house_price=0;
	board[10].type=tax;
	board[10].house_count=0;
	board[10].owner.type=noone;

	board[11].name="Sisli";
	board[11].block_id=11;
	board[11].price=33000;
	board[11].rent=1500;
	board[11].rent_1=8000;
	board[11].rent_2=16000;
	board[11].rent_3=42000;
	board[11].house_price=16000;
	board[11].type=property;
	board[11].house_count=0;
	board[11].owner.type=noone;

	board[12].name="Oil";
	board[12].block_id=12;
	board[12].price=0;
	board[12].rent=2250;
	board[12].rent_1=0;
	board[12].rent_2=0;
	board[12].rent_3=0;
	board[12].house_price=0;
	board[12].type=tax;
	board[12].house_count=0;
	board[12].owner.type=noone;

	board[13].name="Atasehir";
	board[13].block_id=13;
	board[13].price=35000;
	board[13].rent=1600;
	board[13].rent_1=8500;
	board[13].rent_2=17000;
	board[13].rent_3=45000;
	board[13].house_price=17000;
	board[13].type=property;
	board[13].house_count=0;
	board[13].owner.type=noone;

	board[14].name="Sariyer";
	board[14].block_id=14;
	board[14].price=40000;
	board[14].rent=1750;
	board[14].rent_1=9500;
	board[14].rent_2=19000;
	board[14].rent_3=48000;
	board[14].house_price=19000;
	board[14].type=property;
	board[14].house_count=0;
	board[14].owner.type=noone;

	board[15].name="Wait 1 Turn";
	board[15].block_id=15;
	board[15].price=0;
	board[15].rent=1;
	board[15].rent_1=0;
	board[15].rent_2=0;
	board[15].rent_3=0;
	board[15].house_price=0;
	board[15].type=punish;
	board[15].house_count=0;
	board[15].owner.type=noone;

	board[16].name="Kadikoy";
	board[16].block_id=16;
	board[16].price=43000;
	board[16].rent=1900;
	board[16].rent_1=11000;
	board[16].rent_2=21500;
	board[16].rent_3=55000;
	board[16].house_price=23000;
	board[16].type=property;
	board[16].house_count=0;
	board[16].owner.type=noone;

	board[17].name="Besiktas";
	board[17].block_id=17;
	board[17].price=60000;
	board[17].rent=2500;
	board[17].rent_1=15000;
	board[17].rent_2=28000;
	board[17].rent_3=60000;
	board[17].house_price=30000;
	board[17].type=property;
	board[17].house_count=0;
	board[17].owner.type=noone;

	board[18].name="Vocation";
	board[18].block_id=18;
	board[18].price=0;
	board[18].rent=5000;
	board[18].rent_1=0;
	board[18].rent_2=0;
	board[18].rent_3=0;
	board[18].house_price=0;
	board[18].type=tax;
	board[18].house_count=0;
	board[18].owner.type=noone;

	board[19].name="Bebek";
	board[19].block_id=19;
	board[19].price=70000;
	board[19].rent=3500;
	board[19].rent_1=20000;
	board[19].rent_2=35500;
	board[19].rent_3=65000;
	board[19].house_price=35000;
	board[19].type=property;
	board[19].house_count=0;
	board[19].owner.type=noone;
}

void show_board( block board[20], player player_one, player player_two) {

	int i,k=6;
	char temp_1[3]="car" , temp_2[3]="cap" , temp_3[5]="noone"; //Since we should print car/cap i create temp array for print them easily 
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|");
	for(i=0 ; i<6 ; i++){

		printf("\t%-11s\t|" ,board[i].name);
	}
	printf("\n|");
	for(i=0 ; i<6 ; i++){
		printf("\t%-6d$\t\t|",board[i].price);
	}
	printf("\n|");
	for(i=0 ; i<6 ; i++){
		if(player_one.current_block_id==i){
			if(player_one.type==car){
				printf("\t%-11s\t|",temp_1);
			}
			else if(player_one.type==cap){
				printf("\t%-11s\t",temp_2);
			}
			else if(player_one.type==noone){
				printf("\t\t\t|");
			}
		}

		else if(player_two.current_block_id==i){
			if(player_one.type==car){
				printf("\t%-11s\t|",temp_1);
			}
			else if(player_one.type==cap){
				printf("\t%-11s\t|",temp_2);
			}
			else if(player_one.type==noone){
				printf("\t\t\t|");
			}

		}

		else if(player_two.current_block_id != i && player_one.current_block_id != i){
			printf("\t\t\t|");
		}

	}
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	for(i=19 ; i>15 ; i--){ //i for left side(bebek/vocation..)  k for right side(catalca/beykoz..)
		
		printf("|\t%-11s\t|" ,board[i].name);
		printf("\t\t\t\t\t\t\t\t\t\t\t\t|\t%-11s\t|\n" ,board[k].name);
		printf("|\t%-6d$\t\t|",board[i].price);
		printf("\t\t\t\t\t\t\t\t\t\t\t\t|\t%-6d$\t\t|\n",board[k].price);
		
		if(player_one.current_block_id==i){

			if(player_one.type==car){
				printf("|\t%-11s\t|",temp_1);
				printf("\t\t\t\t\t\t\t\t\t\t\t\t-------------------------");

			}
			else if(player_one.type==cap){
				printf("|\t%-11s\t",temp_2);
				printf("\t\t\t\t\t\t\t\t\t\t\t\t-------------------------");
			}
		}
		if(player_two.current_block_id==i){
				if(player_one.type==car){
					printf("|\t%-11s\t|",temp_1);
					printf("\t\t\t\t\t\t\t\t\t\t\t\t\n-------------------------\n");
				}
				else if(player_one.type==cap){
					printf("|\t%-11s\t|",temp_2);
					printf("\t\t\t\t\t\t\t\t\t\t\t\t\n-------------------------\n");
				}
			}

		else if(player_two.current_block_id != i && player_one.current_block_id != i){
				printf("|\t\t\t|");
				printf("\t\t\t\t\t\t\t\t\t\t\t\t");
			
			}


		if(player_one.current_block_id==k){

			if(player_one.type==car){
				printf("|\t%-11s\t|",temp_1);
			}
			else if(player_one.type==cap){
				printf("|\t%-11s\t",temp_2);
			}
		}

		if(player_two.current_block_id==k){
			
			if(player_one.type==car){
				printf("|\t%-11s\t|",temp_1);
			}
			else if(player_one.type==cap){
				printf("|\t%-11s\t|",temp_2);
			}
		}

		else if(player_two.current_block_id != k && player_one.current_block_id != k){
			printf("|\t\t\t|\n");
			printf("-------------------------\n");
			
		}
		k++;			
	}		

	for(i=15 ; i>9 ; i--){
		printf("\t%-11s\t|" ,board[i].name);
	}
	printf("\n|");
	for(i=15 ; i>9 ; i--){
		printf("\t%-6d$\t\t|",board[i].price);
	}
	printf("\n|");
	for(i=15 ; i>9 ; i--){
		if(player_one.current_block_id==i){
			if(player_one.type==car){
				printf("\t%-11s\t|",temp_1);
			}
			else if(player_one.type==cap){
				printf("\t%-11s\t",temp_2);
			}
			else if(player_one.type==noone){
				printf("\t\t\t|");
			}
		}

		else if(player_two.current_block_id==i){
			if(player_one.type==car){
				printf("\t%-11s\t|",temp_1);
			}
			else if(player_one.type==cap){
				printf("\t%-11s\t|",temp_2);
			}
			else if(player_one.type==noone){
				printf("\t\t\t|");
			}

		}

		else if(player_two.current_block_id != i && player_one.current_block_id != i){
			printf("\t\t\t|");
		}

	}
}

void show_properties( block board[20]){

	int selection;

	do{
		printf("\nPlease select a property to see details:\n");
		printf("1-\tEsenyurt\n");
		printf("4-\tArnavutkoy\n");
		printf("6-\tCatalca\n");
		printf("7-\tBeykoz\n");
		printf("9-\tMaltepe\n");
		printf("11-\tSisli\n");
		printf("13-\tAtasehir\n");
		printf("14-\tSariyer\n");
		printf("16-\tKadikoy\n");
		printf("17-\tBesiktas\n");
		printf("19-\tBebek\n");
		printf("0-\tExit\n");
		
		scanf("%d",&selection);
		
		if(selection ==0)
			printf("Quiting...\n");

		else if(selection ==1 || selection == 4 || selection == 6 || selection == 7 || selection ==9 || selection ==11 || selection == 13 || selection ==14 || selection ==16 || selection ==17 || selection ==19){
			printf("--------------------------------\n");
			printf("|\t%-11s\t|\t|\n",board[selection].name );
			printf("--------------------------------\n");
			printf("| \tRent 		%-6d$\t|\n",board[selection].rent);
			printf("| \tRent 1 H 	%-6d$\t|\n",board[selection].rent_1 );
			printf("| \tRent 2 H 	%-6d$\t|\n",board[selection].rent_2);
			printf("| \tRent 3 H 	%-6d$\t|\n",board[selection].rent_3);
			printf("--------------------------------\n");
			printf("| \tHouse Price  %-6d$\t|\n",board[selection].house_price);
			printf("--------------------------------\n");
		}

		if(selection !=0 && selection !=1 && selection != 4 && selection != 6 && selection != 7 && selection !=9 && selection !=11 && selection != 13 && selection !=14 && selection !=16 && selection !=17 && selection !=19){
			printf("invalid choice!!! Please choose another property\n");
		}
		
	}while(selection != 0 );

}

void buy_property( block* current_block, player* current_player){

	if(current_block->owner.type==noone && current_block->type==property){
		if(current_player->account >= current_block->price){//if user have enough money for buy the property then we buy it

			current_block->owner.type=current_player->type;//current block's owner became our current users's type so we assign it to current_block->owner.type
			current_player->account=current_player->account - current_block->price;
		}
	buy_house(current_block, current_player);	//asking to user buying house	
	}
	else{
		printf("The block is not avaible for buying process");
	}

}

void buy_house( block* current_block, player* current_player){

	int selection,sentinel=1;
	while(sentinel != 0){	
		printf("Do you want to buy a house (select '1' for YES , '2' for NO)");
		printf("1-Yes");
		printf("2-No");
		scanf("%d",&selection);
		
		if(selection==1){
			if(current_player->account >= current_block->house_price){
				current_block->house_count++;
				current_player->account = current_player->account - current_block->house_price;
			}
			else{
				printf("Your money not enough for this house\n");
				sentinel=0;
			}
		}
		else if(selection==2){
			sentinel=0;
		}
	}
}