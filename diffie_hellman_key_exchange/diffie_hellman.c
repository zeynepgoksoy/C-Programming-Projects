#include<stdio.h>
#include<stdlib.h>
#include<string.h>


long long int power(int a,int b,int mod){ // a ^ b mod P işlemini hesaplayan fonksiyon

 long long int t;
 
 if(b==1)
  	return a;
  
  t=power(a,b/2,mod);
  	
  	if(b%2==0)
   		return (t*t)%mod;
  	else
   		return (((t*t)%mod)*a)%mod;
 }
 
 void sifrele_coz(long long int anahtar){ // bu fonksiyonda kullanıcıdan şifrelemesi için bir metin girmesini istiyoruz ve girilen metine şifreleme ve çözme işlemlerini yapıyoruz
 	
 	char mesaj[256];
 	char sifreli_mesaj[256]="";
 	char cozulmus_mesaj[256]="";
 	char alfabe[26]={ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 	int mesaj_boyutu=0;
 	
 	printf("Lütfen şifrelemek istediğini mesajı giriniz:");
 	scanf(" %[^\n]",mesaj);
 	
 	if(anahtar == 0 ){ // alice ve bob'un hesapadıkları anahtar değerinin 0 çıkması durumunda şifreleme yapabilmek için anahtarı 1 arttırdık.
 		anahtar=+1;
 	}
 	 	
	mesaj_boyutu= strlen(mesaj);
	int k=0;
	for (int i=0 ; i<mesaj_boyutu ; i++){
	
		for(int j=0; j<26 ; j++){
			if(mesaj[i]==alfabe[j]){
				sifreli_mesaj[k]=alfabe[(j+anahtar)%26] ;
				k++;
			}
		}	
	}
	
	printf("şifrelenmiş metin:  %s\n",sifreli_mesaj);
	
	for (int i=0 ; i<mesaj_boyutu ; i++){
	
		for(int j=0; j<26 ; j++){
			if(sifreli_mesaj[i]==alfabe[j]){
				if(j-anahtar<0){
					cozulmus_mesaj[i]=alfabe[(j-anahtar)+26] ;
				}
				else{
					cozulmus_mesaj[i]=alfabe[(j-anahtar)%26] ;
				}
				
			}
		}	
	}
	printf("çözülmüş metin:  %s\n",cozulmus_mesaj);
 }
 
int asal_mi(int sayi)  // bu fonskiyonda parametre olarak gelen sayının asal sayı olup olmadığını kontrol ediyoruz
{
     if (sayi <= 1) return 0;
     if (sayi % 2 == 0 && sayi > 2) return 0;
     for(int i = 3; i < sayi / 2; i+= 2)
     {
         if (sayi % i == 0)
             return 0;
     }
     return 1;
}
 
 
 int main(){
 
  int P,G,x,a,y,b;
  long long int alice_anahtar, bob_anahtar;  

  do{ 
		printf("\nLütfen asal bir sayı giriniz(P):");
		scanf(" %d",&P);
	
  }while(!asal_mi(P)); // kullanıcı asal sayı girene kadar kullanıcıdan sayı alır
  
  
  printf("\nLütfen bir sayı giriniz(G):");
  scanf(" %d",&G);   

  x = rand()%26; //alice için random bir sayı seçiyoruz
  a=power(G,x,P);    

  y = rand()%26; //bob için random bir sayı seçiyoruz 
  b=power(G,y,P);
  
  alice_anahtar = power(b,x,P);
  bob_anahtar = power(a,y,P);
  printf("alice'in özel şifresi : %lld\n",alice_anahtar);
  printf("bob'un özel şifresi : %lld\n",bob_anahtar);
  
  sifrele_coz(alice_anahtar);
  
  return 0;
 }
