#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

//Problemler:
//basit hesap makinesi 2 say� giri�i al�rken str i�in sap�t�yor

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
	
	printf("--------------------------------\n");
	printf("L�tfen 1. say�y� giriniz: ");
	scanf("%lf",&sayi1);
	printf("--------------------------------\n");
	printf("L�tfen 2. say�y� giriniz: ");
	scanf("%lf",&sayi2);
	
	
	
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
	setlocale(LC_ALL,"Turkish");
	
	printf("L�tfen Fakt�riyel Hesab� ��in 0-20 Aras�nda Bir Tam Say� Giriniz (Ondal�k Say�n�n Tam K�sm� Kullan�lacakt�r): ");
	scanf("%d",&sayi);
	
	if(sayi==0 || sayi==1)
	{
		printf("--------------------------------");
		printf("\nSonu�: %llu",faktoriyel_sonucu);
		return 0;
	}
	
	if (sayi<0)
	{
		printf("--------------------------------");
		printf("\n\x1b[1;31mHATA: \x1b[0mL�tfen Pozitif Bir Tam Say� Giriniz!");
		return 1;
	}
	
	if (sayi>MAX_FAKTORIYEL_SINIRI)
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
	printf("L�tfen Karesi Al�nacak Say�y� Giriniz: ");
	scanf(" %lf",&kare_alinacak_sayi);
	
	karesi_sonuc = pow(kare_alinacak_sayi,2);
	tam_karesi_sonuc = (int)floor(karesi_sonuc);
	
	if (karesi_sonuc!=tam_karesi_sonuc) 
	{
		printf("--------------------------------\n");
		printf("Sonu�: %.2lf",karesi_sonuc);
	}
	else
	{
		printf("--------------------------------\n");
		printf("Kare ��lemi Sonucu: %d",tam_karesi_sonuc);
	}
	return 0;
}

int menu()
{
	//Tan�mlamalar�m�z
	const int animasyon_suresi = 500;
	const int menu_sayisi = 3;
	int menu_secim;
	int i = 1; 
	int okuma_sonucu;
	
	do 
	{
		printf("--------------------------------\n");
		printf("Men� Giri�i: ");
		okuma_sonucu = scanf("%d",&menu_secim);
		
		if (okuma_sonucu !=1)
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

int main() 
{
	setlocale(LC_ALL,"Turkish"); //T�rk�e i�in yerelle�tirme
	setlocale(LC_NUMERIC, "C");  //Hesaplamalarda ',' '.' �ak��mas� istemiyoruz
	
	printf("\r\x1b[1;34mGENEL HESAPLAMA MEN�S�\x1b[0m\n"); //Ba�l�k Yazd�rma
	printf("--------------------------------");
	printf("\nHesaplama Men�s�ne Ho� Geldiniz.");
	//Sleep(animasyon_suresi); //1sn Bekletme //Debug s�recinde-aktif de�il
	printf("\x1b[2J"); //Terminali sil
	printf("\x1b[H"); //�mleci konumu s�f�rla
	printf("\r\x1b[1;34mGENEL HESAPLAMA MEN�S�\x1b[0m\n");
	printf("--------------------------------");
	//Sleep(animasyon_suresi);
	printf("\nHangi Hesaplamay� Yapmak �stersiniz?\n");
	//Sleep(animasyon_suresi);
	printf("--------------------------------\n");
	printf("1-Temel D�rt Fonksiyonlu Hesap Makinesi.\n2-Fakt�riyel Hesaplama Makinesi.\n3-Kare Hesaplama Makinesi\n");
	
	menu();
	
	
	return 0;
}
