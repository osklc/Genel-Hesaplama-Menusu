#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
//Program� Geli�tireceksen d�ng� mant���n� b�t�n fonksiyonlara sonra koy!!

int basic_calc() //Basit Hesap Makinesi fonksiyonu
{
	char islem;
	printf("L�tfen ��lem Giriniz(+,-,*,/): ");
	scanf(" %c",&islem);
	
	if(islem != '+' && islem != '-' && islem != '*' && islem != '/')
	{
		printf("--------------------------------\n");
		printf("\x1b[1;31mHATA: \x1b[0mL�tfen tan�mlanm�� bir i�lem giriniz.");
		return 1;
	}
	
	double sayi1,sayi2,sonuc;
	int tam_sayi_sonuc;
	int okuma_sonucu_double;
	
	printf("--------------------------------");
	do
	{
		printf("\nL�tfen 1. say�y� giriniz: ");
		okuma_sonucu_double = scanf("%lf",&sayi1);
		
		if (okuma_sonucu_double!=1)
		{
			printf("--------------------------------\n");
			printf("\x1b[1;31mHATA: \x1b[0mL�tfen say�sal bir de�er giriniz.");
			printf("\n--------------------------------");
			while (getchar() != '\n');
		}
	}while (okuma_sonucu_double != 1);
	
	printf("--------------------------------");
	do
	{
		
		printf("\nL�tfen 2. say�y� giriniz: ");
		okuma_sonucu_double = scanf("%lf",&sayi2);
		
		if(okuma_sonucu_double!=1)
		{
			printf("--------------------------------\n");
			printf("\x1b[1;31mHATA: \x1b[0mL�tfen say�sal bir de�er giriniz.");
			printf("\n--------------------------------");
			while (getchar() != '\n');
		}
	}while(okuma_sonucu_double!=1);
	
	
	
	switch(islem)
	{
		case '+': sonuc = sayi1+sayi2; break;
		case '-': sonuc = sayi1-sayi2; break;
		case '*': sonuc = sayi1*sayi2; break;
		case '/':	
			if(sayi2==0){printf("--------------------------------\n\x1b[1;31mHATA: \x1b[0mB�l�m 0 olamaz.");return 1;}
			sonuc = sayi1/sayi2;
			break;
	}
			
		printf("--------------------------------\n");
		tam_sayi_sonuc = (int)floor(sonuc);
		
		if (sonuc!=tam_sayi_sonuc) 
		{
			printf("B�lme Sonucu: %.2f",sonuc);
		}
		else
		{
			printf("B�lme Sonucu: %d",tam_sayi_sonuc);
		}

	return 0;
}

int factorial_calc() //Fakt�riyel Hesaplama Makinesi fonksiyonu
{
	int sayi;
	unsigned long long int faktoriyel_sonucu=1;
	const int MAX_FAKTORIYEL_SINIRI = 20;
	int okuma_sonucu_fac;
	
	printf("L�tfen Fakt�riyel Hesab� ��in 0-20 Aras�nda Bir Tam Say� Giriniz (Ondal�k Say�n�n Tam K�sm� Kullan�lacakt�r): ");
	okuma_sonucu_fac = scanf("%d",&sayi);
	
	if (okuma_sonucu_fac!=1)
	{	
		printf("--------------------------------\n");
		printf("\x1b[1;31mHATA: \x1b[0mL�tfen say�sal bir de�er giriniz.");
		while (getchar() != '\n');
		return 1;
	}
	
	
	if(sayi==0 || sayi==1)
	{
		printf("--------------------------------");
		printf("\nSonu�: %llu",faktoriyel_sonucu);
		return 0;
	}
	
	if (sayi<0 && okuma_sonucu_fac==1)
	{
		printf("--------------------------------");
		printf("\n\x1b[1;31mHATA: \x1b[0mL�tfen Pozitif Bir Tam Say� Giriniz!");
		return 1;
	}
	
	if (sayi>MAX_FAKTORIYEL_SINIRI && okuma_sonucu_fac==1)
	{
		printf("--------------------------------");
		printf("\n\x1b[1;31mHATA: \x1b[0mBu Program 20'den B�y�k Say�lar�n Fakt�riyelini Alamaz!");
		return 1;
	}
	printf("--------------------------------\n");
	int i = sayi;
	while (1<i)
	{
		faktoriyel_sonucu=i*faktoriyel_sonucu;
		i--;
		printf("%llu\n",faktoriyel_sonucu);
		Sleep(100);
	}
		
	printf("--------------------------------");
	printf("\nFakt�riyel Sonucu: %llu",faktoriyel_sonucu);
	return 0;

}

int squaring_calc() //Kare Alma fonksiyonu
{
	double kare_alinacak_sayi, karesi_sonuc;
	int tam_karesi_sonuc;
	int i = 1;
	
	do
	{
		int okuma_sonucu_squaring;
		printf("L�tfen Karesi Al�nacak Say�y� Giriniz: ");
		okuma_sonucu_squaring = scanf(" %lf",&kare_alinacak_sayi);
		
		if(okuma_sonucu_squaring == 1)
		{
			karesi_sonuc = pow(kare_alinacak_sayi,2);
			tam_karesi_sonuc = (int)floor(karesi_sonuc);
			
			if (karesi_sonuc!=tam_karesi_sonuc) 
			{
				printf("--------------------------------\n");
				printf("Sonu�: %.2lf",karesi_sonuc);
				i=0;
			}
			else
			{
				printf("--------------------------------\n");
				printf("Kare ��lemi Sonucu: %d",tam_karesi_sonuc);
				i=0;
			}		
		}
		
		else if(okuma_sonucu_squaring !=1)
		{
			printf("--------------------------------\n");
			printf("\r\x1b[1;31mHATA:\x1b[0m L�tfen say�sal bir de�er girin!\n");
			printf("--------------------------------\n");
			while (getchar() != '\n'); //tampon temizleme
			i=1;
			
		}
		
	}while(i);
	
}

int menu() //Men� fonksiyonu
{
	//Tan�mlamalar�m�z
	const int menu_sayisi = 3;
	int menu_secim;
	int i = 1; 
	int okuma_sonucu_menu;
	
	do 
	{
		printf("--------------------------------\n");
		printf("Men� Giri�i: ");
		okuma_sonucu_menu = scanf("%d",&menu_secim);
		
		if (okuma_sonucu_menu !=1)
		{
			printf("--------------------------------\n");
			printf("\r\x1b[1;31mHATA:\x1b[0m L�tfen say�sal bir de�er girin!\n");
			while (getchar() != '\n'); //tampon temizleme
			menu_secim = -1; //ge�ersiz atama a�a��daki if'e tak�lmas� i�in
		}
		
		if(menu_secim>=1 && menu_secim<=menu_sayisi)
		{
			printf("\x1b[2J"); //Terminali sil	
			printf("\x1b[H"); //�mleci konumu s�f�rla
			printf("\r\x1b[1;34mGENEL HESAPLAMA MEN�S�\x1b[0m\n"); //Ba�l�k Yazd�rma
			printf("--------------------------------");
			
			switch(menu_secim)
			{
			
			case 1:
				printf("\n\x1b[1;32mTemel D�rt Fonksiyonlu Hesap Makinesi\x1b[0m");
				printf("\n--------------------------------\n");
				i = 0;
				basic_calc();
				break;
			case 2:
				printf("\n\x1b[1;32mFakt�riyel Hesaplama Makinesi\x1b[0m");
				printf("\n--------------------------------\n");
				i = 0;
				factorial_calc();
				break;
			case 3:
				printf("\n\x1b[1;32mKare Hesaplama Makinesi\x1b[0m");
				printf("\n--------------------------------\n");
				i = 0;
				squaring_calc();
				break;
			}
			i=0;
		

		}
		else if (menu_secim !=-1)
		{
			printf("--------------------------------\n");
			printf("\r\x1b[1;31mHATA: \x1b[0mL�tfen Yukar�daki Se�eneklerden Birini Kullan�n!\n");
			i=1;
		}
		
	}while(i);

}

int main() //Ana fonksiyon
{
	setlocale(LC_ALL,"Turkish"); //T�rk�e i�in yerelle�tirme
	setlocale(LC_NUMERIC, "C");  //Hesaplamalarda ',' '.' �ak��mas� istemiyoruz
	const int animasyon_suresi = 700;
	
	printf("\r\x1b[1;34mGENEL HESAPLAMA MEN�S�\x1b[0m\n"); //Ba�l�k Yazd�rma
	printf("--------------------------------");
	printf("\nHesaplama Men�s�ne Ho� Geldiniz.");
	Sleep(animasyon_suresi); //1sn Bekletme //Debug s�recinde-aktif de�il
	printf("\x1b[2J"); //Terminali sil
	printf("\x1b[H"); //�mleci konumu s�f�rla
	printf("\r\x1b[1;34mGENEL HESAPLAMA MEN�S�\x1b[0m\n");
	printf("--------------------------------");
	Sleep(animasyon_suresi);
	printf("\nHangi Hesaplamay� Yapmak �stersiniz?\n");
	Sleep(animasyon_suresi);
	printf("--------------------------------\n");
	printf("1-Temel D�rt Fonksiyonlu Hesap Makinesi.\n2-Fakt�riyel Hesaplama Makinesi.\n3-Kare Hesaplama Makinesi\n");
	
	menu();
	
	
	return 0;
}
