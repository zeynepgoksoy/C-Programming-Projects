Kod C dilinde yazılmış olup Diffie-Hellman anahtar değişimini yapmaktadır.
Anahtar değişimi ile birlikte şifreleme ve şifre çözme işlemlerini ise Sezar algoritmasına göre yapmaktadır.

İçerisinde bulunan fonksiyonlar:
	
	long long int power(int a,int b,int mod) : a ^ b mod P işlemini hesaplayan fonksiyon
	
	void sifrele_coz(long long int anahtar) : kullanıcıdan şifrelemesi için bir metin girilmesi istenir ve girilen metine şifreleme ve çözme işlemlerini yapar
	
	int asal_mi(int sayi) : parametre olarak gelen sayının asal sayı olup olmadığını kontrol eder
	
	int main() : main fonksiyonunda, anahtar oluşturma fonksiyonları ve diğer fonksiyonlar çağrılır.
	
Kodu derlemek için terminale aşağıdaki komutları giriniz :

	gcc -o diffie_hellman diffie_hellman.c
	./diffie_hellman