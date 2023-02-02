#include "Oyun.h"

Oyun oyun_olustur( char* dosyaAdi){
	Oyun this;
	this = (Oyun)malloc(sizeof(struct OYUN));
	this->oyun_basla = &oyun_basla;
	//this->sil=&dosyayiSil;
	//(*
	return this;
	
}

void oyun_basla(struct KISI* oyuncular,int* lucky_number, int size_kisi,int size_number){
	
	printf("%d\n",size_kisi );
	int i,j;
	double kasa = 0;
	double toplam_kazanan_para = 0;
	double toplam_kaybeden_para = 0;
	double bahis;
	struct KISI en_zengin = oyuncular[0];
	for (i = 0; i <size_number ; ++i)//278
	{
		system("cls");
		for (j = 0; j < size_kisi; ++j)//1000 kisi
		{
			if (oyuncular[j].money >= 1000)
			{
				bahis = oyuncular[j].money*oyuncular[j].percantage;
				oyuncular[j].money = oyuncular[j].money - bahis;
				kasa += bahis;
				if (oyuncular[j].played_number == lucky_number[i]) //kazanan
				{
					bahis = bahis*10;
					oyuncular[j].money = oyuncular[j].money + bahis;
					kasa -= bahis;
				}
			}
		}
		en_zengin = oyuncular[0];
		for (j = 0; j < size_kisi; ++j)//1000
		{
			if (en_zengin.money < oyuncular[j].money)
			{
				en_zengin = oyuncular[j];
			}
		}


		printf("\n" );
		printf("\n" );
		printf("\n" );
		if (i <= 276)
		{
			printf("\t\t ##################################################\n" );
			printf("\t\t ##\t\t SANSLI SAYI: %d \t\t ##\n",lucky_number[i] );
			printf("\t\t ##################################################\n" );
		}
		printf("\t\t ##################################################\n" );
		printf("\t\t ##\t\t TUR: %d \t\t\t ##\n",i+1 );
		printf("\t\t ##\t\t MASA BAKIYE: %.2lf TL\t ##\n",kasa );
		printf("\t\t ##\t\t\t\t\t\t ##\n" );
		printf("\t\t ##----------------------------------------------##\n" );
		if (i <= 276)
		{
			printf("\t\t ##\t\t EN ZENGIN KISI \t\t ##\n" );
			printf("\t\t ##\t\t %.12s \t\t\t ##\n",en_zengin.player_name );
			if (en_zengin.money > 99999)
				printf("\t\t ##\t\t %.0lf         \t\t ##\n",(en_zengin.money) );
			else
				printf("\t\t ##\t\t %.0lf \t\t\t\t ##\n",(en_zengin.money) );
			printf("\t\t ##\t\t\t\t\t\t ##\n" );
			printf("\t\t ##################################################\n" );
		}
		else{
			printf("\t\t ##\t\t OYUN BITTI \t\t\t ##\n" );
			printf("\t\t ##\t\t\t\t\t\t ##\n" );
			printf("\t\t ##\t\t\t\t\t\t ##\n" );
			printf("\t\t ##\t\t\t\t\t\t ##\n" );
			printf("\t\t ##################################################\n" );
		}		
	}
	return;
}
