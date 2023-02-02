#include "Kisi.h"

Kisi kisiolustur(char* name, double money,double percantage, int played_number){
	Kisi this;
	this = ( Kisi)malloc(sizeof(struct KISI));
	strcpy(this->player_name,name);
	this->money = money;
	this->percantage=percantage;
	this->played_number=played_number;
	
	return this;
}