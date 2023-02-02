#include "Dosya.h"
#define MAX_LENG 1000
// ; *

Dosya dosyaOlustur( char* dosyaAdi){
	Dosya this;
	this = (Dosya)malloc(sizeof(struct DOSYA));
	this->dosyaAdi=dosyaAdi;
	this->dosyaOku=&dosyaOku;
	this->sayioku=&sayioku;
	return this;
	
}

char** dosyaOku (const Dosya this, int* size){ 
	
	char str[MAX_LENG];
	char** arr;
	int row=0,column,row_index=0;
	
	FILE* fp;
	
	fp = fopen(this->dosyaAdi,"r");

	if(fp == NULL){
		printf("file can't be opened \n");
	}
	else{

		while(fscanf(fp," %[^\n]",str )==1){
			row++;
		}
	}
	fclose(fp);

	arr = (char**)calloc(row,sizeof(char*));

	fp = fopen(this->dosyaAdi,"r"); // her satırdaki sütun sayılarını ve verileri almak icin dosyayi tekrar açtık

	if(fp == NULL){
		printf("file can't be opened \n");
	}
	else{

		while(fscanf(fp," %[^\n]",str )==1){
			//printf("str : %s  ", str);
			column=0;
			for(int i=0; *(str+i) != '\0' ; i++){
				column++;
			}
			arr[row_index]=(char*)calloc((column+1),sizeof(char));
			strcpy(*(arr+row_index),str);
			row_index++;
		}
	}
	fclose(fp);

	*size=row;

	return arr;
}

int* sayioku(const Dosya this, int* size){
	FILE *fp;
	int i=0,num;
	int* lucky_number;

	fp = fopen(this->dosyaAdi,"r");
	while(fscanf(fp,"%d",&num)==1){
		i++;
	}
	lucky_number = (int**)calloc(i,sizeof(int*));
	fclose(fp);
	*size = i;
	i = 0;
	fp = fopen(this->dosyaAdi,"r");
	while(fscanf(fp,"%d",&num)==1){
		lucky_number[i] = num;
		i++;
	}
	return lucky_number;

}
