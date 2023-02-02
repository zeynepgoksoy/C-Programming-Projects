#ifndef DOSYA_H
#define DOSYA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Kisi.h"

struct DOSYA{
		char* dosyaAdi;
		
		char** (*dosyaOku)(struct DOSYA*,int *size );
		int* (*sayioku)(struct DOSYA*,int *size);
		void (*sil)(struct DOSYA*);
		
};
typedef struct DOSYA* Dosya;

Dosya dosyaOlustur( char*);
char** dosyaOku(const Dosya this, int* size);
int* sayioku(const Dosya this, int* size);
void dosyayiSil(const Dosya);

#endif