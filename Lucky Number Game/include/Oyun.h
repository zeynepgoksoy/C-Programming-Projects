#ifndef OYUN_H
#define OYUN_H
#include <stdio.h>
#include <stdlib.h>

#include "Kisi.h"

struct OYUN
{
	
	void* (*oyun_basla)(struct KISI*, int*, int,int);

};

typedef struct OYUN* Oyun;

Oyun oyun_olustur();

void oyun_basla(struct KISI* oyuncular,int* lucky_number,int size_kisi,int size_number);

#endif