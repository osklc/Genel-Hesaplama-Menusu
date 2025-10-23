#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

void basic_calc() //Basit Hesap Makinesi fonksiyonu
{
	char islem;
	printf("L�tfen ��lem Giriniz(+,-,*,/): ");
	scanf(" %c",&islem);
	
	if(islem != '+' && islem != '-' && islem != '*' && islem != '/')
	{
		printf("--------------------------------\n");
		printf("Hatal� ��lem Giri�i!");
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
		case '+':
			printf("--------------------------------\n");
			
			sonuc = sayi1+sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonu�: %.2f",sonuc);
			}
			else
			{
				printf("Sonu�: %d",tam_sayi_sonuc);
			}
			break;
			
		case '-':
			printf("--------------------------------\n");
			
			sonuc = sayi1-sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonu�: %.2f",sonuc);
			}
			else
			{
				printf("Sonu�: %d",tam_sayi_sonuc);
			}
			break;
		case '*':
			printf("--------------------------------\n");
			
			sonuc = sayi1*sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonu�: %.2f",sonuc);
			}
			else
			{
				printf("Sonu�: %d",tam_sayi_sonuc);
			}
			break;

		case '/':
			printf("--------------------------------\n");
			sonuc = sayi1/sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonu�: %.2f",sonuc);
			}
			else
			{
				printf("Sonu�: %d",tam_sayi_sonuc);
			}
			break;
	}


	
}

void factorial_calc() //Fakt�riyel Hesaplama Makinesi fonksiyonu
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
	}
	
	if (sayi<0)
	{
		printf("--------------------------------");
		printf("\nL�tfen Pozitif Bir Tam Say� Giriniz!");
	}
	
	if (sayi>MAX_FAKTORIYEL_SINIRI)
	{
		printf("--------------------------------");
		printf("\nBu Program 20'den B�y�k Say�lar�n Fakt�riyelini Alamaz!");
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
	printf("\nSonu�: %llu",faktoriyel_sonucu);

}

void sqrt_calc()
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
		printf("Say�n�n Karesi: %d",tam_karesi_sonuc);
	}
	
}
int main() 
{
	setlocale(LC_ALL,"Turkish"); //T�rk�e i�in yerelle�tirme
	setlocale(LC_NUMERIC, "C");  //Hesaplamalarda ',' '.' �ak��mas� istemiyoruz
	//Tan�mlamalar�m�z
	int menu_secim;
	int i = 1; 
	
	printf("\r\x1b[1;31mGENEL HESAPLAMA MEN�S�\x1b[0m\n"); //Ba�l�k Yazd�rma
	printf("--------------------------------");
	printf("\nHesaplama Men�s�ne Ho� Geldiniz.");
	//Sleep(1000); //1sn Bekletme
	printf("\x1b[2J"); //Terminali sil
	printf("\x1b[H"); //�mleci konumu s�f�rla
	printf("\r\x1b[1;31mGENEL HESAPLAMA MEN�S�\x1b[0m\n");
	printf("--------------------------------");
	//Sleep(1000);
	printf("\nHangi Hesaplamay� Yapmak �stersiniz?\n");
	//Sleep(500);
	printf("--------------------------------\n");
	printf("1-Temel D�rt Fonksiyonlu Hesap Makinesi.\n2-Fakt�riyel Hesaplama Makinesi.\n3-Kare Hesaplama Makinesi\n");
	
	while(i)
	{
		printf("--------------------------------\n");
		printf("Men� Giri�i: ");
		scanf("%d",&menu_secim);
		if (menu_secim==1)
		{
			printf("\x1b[2J"); //Terminali sil
			printf("\x1b[H"); //�mleci konumu s�f�rla
			printf("\r\x1b[1;31mGENEL HESAPLAMA MEN�S�\x1b[0m\n"); //Ba�l�k Yazd�rma
			printf("--------------------------------");
			printf("\n\x1b[1;32mTemel D�rt Fonksiyonlu Hesap Makinesi\x1b[0m");
			printf("\n--------------------------------\n");
			i = 0; //D�ng�y� bitir
			basic_calc(); //Fonksiyonu �a��r
		}
		else if (menu_secim==2)
		{
			printf("\x1b[2J"); //Terminali sil
			printf("\x1b[H"); //�mleci konumu s�f�rla
			printf("\r\x1b[1;31mGENEL HESAPLAMA MEN�S�\x1b[0m\n"); //Ba�l�k Yazd�rma
			printf("--------------------------------");
			printf("\n\x1b[1;32mFakt�riyel Hesaplama Makinesi\x1b[0m");
			printf("\n--------------------------------\n");
			i = 0;
			factorial_calc();
		}
		else if (menu_secim==3)
		{
			printf("\x1b[2J"); //Terminali sil
			printf("\x1b[H"); //�mleci konumu s�f�rla
			printf("\r\x1b[1;31mGENEL HESAPLAMA MEN�S�\x1b[0m\n"); //Ba�l�k Yazd�rma
			printf("--------------------------------");
			printf("\n\x1b[1;32mKare Hesaplama Makinesi\x1b[0m");
			printf("\n--------------------------------\n");
			i = 0;
			sqrt_calc();
		}
		
		else
		{
		printf("\r\x1b[1;31mHatal� Giri� \x1b[0mL�tfen Yukar�daki Se�eneklerden Birini Kullan�n!\n");
		}	
	}
	
	
	return 0;
}
