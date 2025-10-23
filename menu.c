#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

//Problemler:
//basit hesap makinesi 2 sayý giriþi alýrken str için sapýtýyor

int basic_calc() //Basit Hesap Makinesi fonksiyonu
{
	char islem;
	printf("Lütfen Ýþlem Giriniz(+,-,*,/): ");
	scanf(" %c",&islem);
	
	if(islem != '+' && islem != '-' && islem != '*' && islem != '/')
	{
		printf("--------------------------------\n");
		printf("\x1b[1;31mHatalý Ýþlem Giriþi!\x1b[0m");
		return 1;
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
				printf("Toplama Sonucu: %.2f",sonuc);
			}
			else
			{
				printf("Toplama Sonucu: %d",tam_sayi_sonuc);
			}
			break;
			
		case '-':
			printf("--------------------------------\n");
			
			sonuc = sayi1-sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Çýkartma Sonucu: %.2f",sonuc);
			}
			else
			{
				printf("Çýkartma Sonucu: %d",tam_sayi_sonuc);
			}
			break;
		case '*':
			printf("--------------------------------\n");
			
			sonuc = sayi1*sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Çarpma Sonucu: %.2f",sonuc);
			}
			else
			{
				printf("Çarpma Sonucu: %d",tam_sayi_sonuc);
			}
			break;

		case '/':
			printf("--------------------------------\n");
			sonuc = sayi1/sayi2;
			tam_sayi_sonuc = (int)floor(sonuc);
			
			if(sayi2==0)
			{
				printf("\x1b[1;31mHATA: \x1b[0mBölüm 0 olamaz.");
				return 1;
			}
			
			if (sonuc!=tam_sayi_sonuc) 
			{
				printf("Bölme Sonucu: %.2f",sonuc);
			}
			else
			{
				printf("Bölme Sonucu: %d",tam_sayi_sonuc);
			}
			break;
	}


	
}

int factorial_calc() //Faktöriyel Hesaplama Makinesi fonksiyonu
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
		return 0;
	}
	
	if (sayi<0)
	{
		printf("--------------------------------");
		printf("\nLütfen Pozitif Bir Tam Sayý Giriniz!");
		return 1;
	}
	
	if (sayi>MAX_FAKTORIYEL_SINIRI)
	{
		printf("--------------------------------");
		printf("\nBu Program 20'den Büyük Sayýlarýn Faktöriyelini Alamaz!");
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
	printf("\nFaktöriyel Sonucu: %llu",faktoriyel_sonucu);

}

void pow_calc() //Kare Alma fonksiyonu
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
		printf("Kare Ýþlemi Sonucu: %d",tam_karesi_sonuc);
	}
	
}

int menu()
{
	//Tanýmlamalarýmýz
	const int animasyon_suresi = 500;
	int menu_secim;
	int i = 1; 
	int okuma_sonucu;
	
	do 
	{
		printf("--------------------------------\n");
		printf("Menü Giriþi: ");
		okuma_sonucu = scanf("%d",&menu_secim);
		
		if (okuma_sonucu !=1)
		{
			printf("--------------------------------\n");
			printf("\r\x1b[1;31mHATA: Lütfen sayýsal bir deðer girin!\x1b[0m\n");
			while (getchar() != '\n'); //tampon temizleme
			menu_secim = -1; //geçersiz atama aþaðýdaki if'e takýlmasý için
		}
		
		else if(menu_secim!=1 && menu_secim!=2 && menu_secim!=3)
		{
			printf("--------------------------------\n");
			printf("\r\x1b[1;31mHatalý Giriþ \x1b[0mLütfen Yukarýdaki Seçeneklerden Birini Kullanýn!\n");
			i=1;
		}
		
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
		if (menu_secim==2)
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
			pow_calc();
		}
		
	}while(i);

}

int main() 
{
	setlocale(LC_ALL,"Turkish"); //Türkçe için yerelleþtirme
	setlocale(LC_NUMERIC, "C");  //Hesaplamalarda ',' '.' çakýþmasý istemiyoruz
	
	printf("\r\x1b[1;31mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n"); //Baþlýk Yazdýrma
	printf("--------------------------------");
	printf("\nHesaplama Menüsüne Hoþ Geldiniz.");
	//Sleep(animasyon_suresi); //1sn Bekletme //Debug sürecinde-aktif deðil
	printf("\x1b[2J"); //Terminali sil
	printf("\x1b[H"); //Ýmleci konumu sýfýrla
	printf("\r\x1b[1;31mGENEL HESAPLAMA MENÜSÜ\x1b[0m\n");
	printf("--------------------------------");
	//Sleep(animasyon_suresi);
	printf("\nHangi Hesaplamayý Yapmak Ýstersiniz?\n");
	//Sleep(animasyon_suresi);
	printf("--------------------------------\n");
	printf("1-Temel Dört Fonksiyonlu Hesap Makinesi.\n2-Faktöriyel Hesaplama Makinesi.\n3-Kare Hesaplama Makinesi\n");
	
	menu();
	
	
	return 0;
}
