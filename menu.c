#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
//Programý Geliþtireceksen döngü mantýðýný bütün fonksiyonlara sonra koy!!

int basic_calc() //Basit Hesap Makinesi fonksiyonu
{
	char islem;
	printf("Lütfen Ýþlem Giriniz\x1b[0;33m (+,-,*,/)\x1b[0m: ");
	scanf(" %c",&islem);
	
	if(islem != '+' && islem != '-' && islem != '*' && islem != '/')
	{
		printf("--------------------------------\n");
		printf("\x1b[1;31mHATA: \x1b[0mLütfen tanýmlanmýþ bir iþlem giriniz.");
		return 1;
	}
	
	double sayi1,sayi2,sonuc;
	int tam_sayi_sonuc;
	int okuma_sonucu_double;
	
	printf("--------------------------------");
	do
	{
		printf("\nLütfen \x1b[0;33m1. \x1b[1;0msayýyý giriniz: ");
		okuma_sonucu_double = scanf("%lf",&sayi1);
		
		if (okuma_sonucu_double!=1)
		{
			printf("--------------------------------\n");
			printf("\x1b[0;31mHATA: \x1b[1;0mLütfen sayýsal bir deðer giriniz.");
			printf("\n--------------------------------");
			while (getchar() != '\n');
		}
	}while (okuma_sonucu_double != 1);
	
	printf("--------------------------------");
	do
	{
		
		printf("\nLütfen \x1b[0;33m2. \x1b[1;0msayýyý giriniz: ");
		okuma_sonucu_double = scanf("%lf",&sayi2);
		
		if(okuma_sonucu_double!=1)
		{
			printf("--------------------------------\n");
			printf("\x1b[1;31mHATA: \x1b[0mLütfen sayýsal bir deðer giriniz.");
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
			if(sayi2==0){printf("--------------------------------\n\x1b[1;31mHATA: \x1b[0mBölüm 0 olamaz.");return 1;}
			sonuc = sayi1/sayi2;
			break;
	}
			
		printf("--------------------------------\n");
		tam_sayi_sonuc = (int)floor(sonuc);
		
		if (sonuc!=tam_sayi_sonuc) 
		{
			printf("\x1b[0;32mHesaplama Ýþlemi Sonucu: %.2f\x1b[1;0m",sonuc);
		}
		else
		{
			printf("\x1b[0;32mHesaplama Ýþlemi Sonucu: %d\x1b[1;0m",tam_sayi_sonuc);
		}

	return 0;
}

int factorial_calc() //Faktöriyel Hesaplama Makinesi fonksiyonu
{
	int sayi;
	unsigned long long int faktoriyel_sonucu=1;
	const int MAX_FAKTORIYEL_SINIRI = 20;
	int okuma_sonucu_fac;
	
	printf("Lütfen Faktöriyel Hesabý Ýçin 0-20 Arasýnda Bir Tam Sayý Giriniz \x1b[0;33m(Ondalýk Sayýnýn Tam Kýsmý Kullanýlacaktýr)\x1b[0m: ");
	okuma_sonucu_fac = scanf("%d",&sayi);
	
	if (okuma_sonucu_fac!=1)
	{	
		printf("--------------------------------\n");
		printf("\x1b[1;31mHATA: \x1b[0mLütfen sayýsal bir deðer giriniz.");
		while (getchar() != '\n');
		return 1;
	}
	
	
	if(sayi==0 || sayi==1)
	{
		printf("--------------------------------");
		printf("\nSonuç: %llu",faktoriyel_sonucu);
		return 0;
	}
	
	if (sayi<0 && okuma_sonucu_fac==1)
	{
		printf("--------------------------------");
		printf("\n\x1b[1;31mHATA: \x1b[0mLütfen Pozitif Bir Tam Sayý Giriniz!");
		return 1;
	}
	
	if (sayi>MAX_FAKTORIYEL_SINIRI && okuma_sonucu_fac==1)
	{
		printf("--------------------------------");
		printf("\n\x1b[1;31mHATA: \x1b[0mBu Program 20'den Büyük Sayýlarýn Faktöriyelini Alamaz!");
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
	printf("\n\x1b[0;32mFaktöriyel Sonucu: %llu\x1b[1;0m",faktoriyel_sonucu);
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
		printf("Lütfen Karesi Alýnacak Sayýyý Giriniz: ");
		okuma_sonucu_squaring = scanf(" %lf",&kare_alinacak_sayi);
		
		if(okuma_sonucu_squaring == 1)
		{
			karesi_sonuc = pow(kare_alinacak_sayi,2);
			tam_karesi_sonuc = (int)floor(karesi_sonuc);
			
			if (karesi_sonuc!=tam_karesi_sonuc) 
			{
				printf("--------------------------------\n");
				printf("Sonuç: %.2lf",karesi_sonuc);
				i=0;
			}
			else
			{
				printf("--------------------------------\n");
				printf("\x1b[0;32mKare Alma Ýþlemi Sonucu: %d\x1b[1;0m",tam_karesi_sonuc);
				i=0;
			}		
		}
		
		else if(okuma_sonucu_squaring !=1)
		{
			printf("--------------------------------\n");
			printf("\r\x1b[1;31mHATA:\x1b[0m Lütfen sayýsal bir deðer girin!\n");
			printf("--------------------------------\n");
			while (getchar() != '\n'); //tampon temizleme
			i=1;
			
		}
		
	}while(i);
	
}

int menu() //Menü fonksiyonu
{
	//Tanýmlamalarýmýz
	const int menu_sayisi = 3;
	int menu_secim;
	int i = 1; 
	int okuma_sonucu_menu;
	
	do 
	{
		printf("--------------------------------\n");
		printf("\x1b[0;35mMenü Giriþi: \x1b[1;0m");
		okuma_sonucu_menu = scanf("%d",&menu_secim);
		
		if (okuma_sonucu_menu !=1)
		{
			printf("--------------------------------\n");
			printf("\r\x1b[1;31mHATA:\x1b[0m Lütfen sayýsal bir deðer girin!\n");
			while (getchar() != '\n'); //tampon temizleme
			menu_secim = -1; //geçersiz atama aþaðýdaki if'e takýlmasý için
		}
		
		if(menu_secim>=1 && menu_secim<=menu_sayisi)
		{
			printf("\x1b[2J"); //Terminali sil	
			printf("\x1b[H"); //Ýmleci konumu sýfýrla
			printf("\r\x1b[1;34mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n"); //Baþlýk Yazdýrma
			printf("--------------------------------");
			
			switch(menu_secim)
			{
			
			case 1:
				printf("\n\x1b[1;35mTemel Dört Fonksiyonlu Hesap Makinesi\x1b[0m");
				printf("\n--------------------------------\n");
				i = 0;
				basic_calc();
				break;
			case 2:
				printf("\n\x1b[1;35mFaktöriyel Hesaplama Makinesi\x1b[0m");
				printf("\n--------------------------------\n");
				i = 0;
				factorial_calc();
				break;
			case 3:
				printf("\n\x1b[1;35mKare Hesaplama Makinesi\x1b[0m");
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
			printf("\r\x1b[1;31mHATA: \x1b[0mLütfen Yukarýdaki Seçeneklerden Birini Kullanýn!\n");
			i=1;
		}
		
	}while(i);

}

int main() //Ana fonksiyon
{
	setlocale(LC_ALL,"Turkish"); //Türkçe için yerelleþtirme
	setlocale(LC_NUMERIC, "C");  //Hesaplamalarda ',' '.' çakýþmasý istemiyoruz
	const int animasyon_suresi = 700;
	
	printf("\r\x1b[1;34mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n"); //Baþlýk Yazdýrma
	printf("--------------------------------");
	printf("\nHesaplama Menüsüne Hoþ Geldiniz.");
	//Sleep(animasyon_suresi); //1sn Bekletme //Debug sürecinde-aktif deðil
	printf("\x1b[2J"); //Terminali sil
	printf("\x1b[H"); //Ýmleci konumu sýfýrla
	printf("\r\x1b[1;34mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n");
	printf("--------------------------------");
	//Sleep(animasyon_suresi);
	printf("\nHangi Hesaplamayý Yapmak Ýstersiniz?\n");
	//Sleep(animasyon_suresi);
	printf("--------------------------------\n");
	printf("\x1b[1;36m1 \x1b[0m- Temel Dört Fonksiyonlu Hesap Makinesi.\n");
	printf("\x1b[1;36m2 \x1b[0m- Faktöriyel Hesaplama Makinesi.\n");
	printf("\x1b[1;36m3 \x1b[0m- Kare Hesaplama Makinesi\n");
	
	menu();
	
	
	return 0;
}
