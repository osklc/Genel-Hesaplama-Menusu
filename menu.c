#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

void basic_calc() //Basit Hesap Makinesi fonksiyonu
{
	char islem;
	printf("Lütfen Ýþlem Giriniz(+,-,*,/): ");
	scanf(" %c",&islem);
	
	if(islem != '+' && islem != '-' && islem != '*' && islem != '/')
	{
		printf("--------------------------------\n");
		printf("Hatalý Ýþlem Giriþi!");
	}
	
	double sayi1,sayi2,sonuc;
	int tam_sayi_sonuc;
	
	printf("--------------------------------\n");
	printf("Lütfen 1. sayýyý giriniz: ");
	scanf("%lf",&sayi1);
	printf("--------------------------------\n");
	printf("Lütfen 2. sayýyý giriniz: ");
	scanf("%lf",&sayi2);
	
	switch(islem)
	{
		case '+':
			printf("--------------------------------\n");
			
			sonuc = sayi1+sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonuç: %.2f",sonuc);
			}
			else
			{
				printf("Sonuç: %d",tam_sayi_sonuc);
			}
			break;
			
		case '-':
			printf("--------------------------------\n");
			
			sonuc = sayi1-sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonuç: %.2f",sonuc);
			}
			else
			{
				printf("Sonuç: %d",tam_sayi_sonuc);
			}
			break;
		case '*':
			printf("--------------------------------\n");
			
			sonuc = sayi1*sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonuç: %.2f",sonuc);
			}
			else
			{
				printf("Sonuç: %d",tam_sayi_sonuc);
			}
			break;

		case '/':
			printf("--------------------------------\n");
			sonuc = sayi1/sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Sonuç: %.2f",sonuc);
			}
			else
			{
				printf("Sonuç: %d",tam_sayi_sonuc);
			}
			break;
	}


	
}

void factorial_calc() //Faktöriyel Hesaplama Makinesi fonksiyonu
{
	int sayi;
	unsigned long long int faktoriyel_sonucu=1;
	const int MAX_FAKTORIYEL_SINIRI = 20;
	setlocale(LC_ALL,"Turkish");
	
	printf("Lütfen Faktöriyel Hesabý Ýçin 0-20 Arasýnda Bir Tam Sayý Giriniz (Ondalýk Sayýnýn Tam Kýsmý Kullanýlacaktýr): ");
	scanf("%d",&sayi);
	
	if(sayi==0 || sayi==1)
	{
		printf("--------------------------------");
		printf("\nSonuç: %llu",faktoriyel_sonucu);
	}
	
	if (sayi<0)
	{
		printf("--------------------------------");
		printf("\nLütfen Pozitif Bir Tam Sayý Giriniz!");
	}
	
	if (sayi>MAX_FAKTORIYEL_SINIRI)
	{
		printf("--------------------------------");
		printf("\nBu Program 20'den Büyük Sayýlarýn Faktöriyelini Alamaz!");
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
	printf("\nSonuç: %llu",faktoriyel_sonucu);

}

void sqrt_calc()
{
	double kare_alinacak_sayi, karesi_sonuc;
	int tam_karesi_sonuc;
	printf("Lütfen Karesi Alýnacak Sayýyý Giriniz: ");
	scanf(" %lf",&kare_alinacak_sayi);
	
	karesi_sonuc = pow(kare_alinacak_sayi,2);
	tam_karesi_sonuc = (int)floor(karesi_sonuc);
	
	if (karesi_sonuc!=tam_karesi_sonuc) 
	{
		printf("--------------------------------\n");
		printf("Sonuç: %.2lf",karesi_sonuc);
	}
	else
	{
		printf("--------------------------------\n");
		printf("Sayýnýn Karesi: %d",tam_karesi_sonuc);
	}
	
}
int main() 
{
	setlocale(LC_ALL,"Turkish"); //Türkçe için yerelleþtirme
	setlocale(LC_NUMERIC, "C");  //Hesaplamalarda ',' '.' çakýþmasý istemiyoruz
	//Tanýmlamalarýmýz
	int menu_secim;
	int i = 1; 
	
	printf("\r\x1b[1;31mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n"); //Baþlýk Yazdýrma
	printf("--------------------------------");
	printf("\nHesaplama Menüsüne Hoþ Geldiniz.");
	//Sleep(1000); //1sn Bekletme
	printf("\x1b[2J"); //Terminali sil
	printf("\x1b[H"); //Ýmleci konumu sýfýrla
	printf("\r\x1b[1;31mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n");
	printf("--------------------------------");
	//Sleep(1000);
	printf("\nHangi Hesaplamayý Yapmak Ýstersiniz?\n");
	//Sleep(500);
	printf("--------------------------------\n");
	printf("1-Temel Dört Fonksiyonlu Hesap Makinesi.\n2-Faktöriyel Hesaplama Makinesi.\n3-Kare Hesaplama Makinesi\n");
	
	while(i)
	{
		printf("--------------------------------\n");
		printf("Menü Giriþi: ");
		scanf("%d",&menu_secim);
		if (menu_secim==1)
		{
			printf("\x1b[2J"); //Terminali sil
			printf("\x1b[H"); //Ýmleci konumu sýfýrla
			printf("\r\x1b[1;31mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n"); //Baþlýk Yazdýrma
			printf("--------------------------------");
			printf("\n\x1b[1;32mTemel Dört Fonksiyonlu Hesap Makinesi\x1b[0m");
			printf("\n--------------------------------\n");
			i = 0; //Döngüyü bitir
			basic_calc(); //Fonksiyonu Çaðýr
		}
		else if (menu_secim==2)
		{
			printf("\x1b[2J"); //Terminali sil
			printf("\x1b[H"); //Ýmleci konumu sýfýrla
			printf("\r\x1b[1;31mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n"); //Baþlýk Yazdýrma
			printf("--------------------------------");
			printf("\n\x1b[1;32mFaktöriyel Hesaplama Makinesi\x1b[0m");
			printf("\n--------------------------------\n");
			i = 0;
			factorial_calc();
		}
		else if (menu_secim==3)
		{
			printf("\x1b[2J"); //Terminali sil
			printf("\x1b[H"); //Ýmleci konumu sýfýrla
			printf("\r\x1b[1;31mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n"); //Baþlýk Yazdýrma
			printf("--------------------------------");
			printf("\n\x1b[1;32mKare Hesaplama Makinesi\x1b[0m");
			printf("\n--------------------------------\n");
			i = 0;
			sqrt_calc();
		}
		
		else
		{
		printf("\r\x1b[1;31mHatalý Giriþ \x1b[0mLütfen Yukarýdaki Seçeneklerden Birini Kullanýn!\n");
		}	
	}
	
	
	return 0;
}
