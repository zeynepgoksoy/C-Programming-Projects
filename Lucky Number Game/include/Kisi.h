#ifndef KISI_H
#define KISI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct KISI
{
	char* player_name;
	double money;
	double percantage;
	int played_number;

};
typedef struct KISI* Kisi;
Kisi kisiolustur(char* name, double money,double percantage, int played_number);

#endif