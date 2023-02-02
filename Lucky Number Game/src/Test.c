#include "Dosya.h"
#include "Kisi.h"
#include "Oyun.h"

int main(){
	
	struct KISI* oyuncular;
	char* players_filename= "Kisiler.txt";
	char* numbers_filename= "Sayilar.txt";


	int size,size2,i=0,num;
	char** kisiArr;
	int* lucky_number;

	Dosya d1 = dosyaOlustur(players_filename);
	Dosya d2 = dosyaOlustur(numbers_filename);
	kisiArr=(d1->dosyaOku(d1,&size));
	lucky_number = (d2->sayioku(d2,&size2));

	oyuncular = (struct KISI*)calloc(size, sizeof(struct KISI));

	Oyun o1 = oyun_olustur();


	const char s[2] = "#";
	char *token;
	int part = 1;
	for(int i=0 ; i<size ;i++){
		part = 1;
		token = strtok(kisiArr[i], s);
		while( token != NULL ) {
			if (part == 1){
				oyuncular[i].player_name = (char*) malloc(sizeof(char)*30);
				strcpy(oyuncular[i].player_name, token);
			}
			if (part == 2){
				oyuncular[i].money = atof(token);
			}
			if (part == 3){
				oyuncular[i].percantage = atof(token);
			}
			if (part == 4){
				oyuncular[i].played_number = atoi(token);
			}
			
			part++;
			token = strtok(NULL, s);
		}
	}

	o1->oyun_basla(oyuncular,lucky_number,size,size2);
	free(d1);
	free(d2);
	free(o1);

}