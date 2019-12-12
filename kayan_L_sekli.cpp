/*				*********************************************
				**                                         **
				** ÖĞRENCİ ADI......: Alihan SARAÇ         **
				** ÖĞRENCİ NUMARASI. : G191210057          **
				**DERS GRUBU....... : A(İÖ)                **
				**                                         **
				*********************************************  */

#include <iostream>
#include<windows.h>//Sleep() fonksiyonu için
#include<time.h>//random sayi icin
using namespace std;
struct sahne
{
	int genislik;
	int yukseklik;
	char karakter;
};
struct Lsekli
{
	int x;
	int y;
	int boyut;
	char karakter;
};
void git(int x, int y);//imec konumunu degistirir
sahne sahneolustur(sahne s1);//sahne degerlerini atar
void sahneciz(sahne s1);//girilen dere gore sahneyi cizer
Lsekli lsekliolustur(Lsekli l1);
void LSekliCizme(Lsekli l1);
Lsekli LSekliAsagiGotur(Lsekli l1);

int main()
{
	sahne s1 = { 10,10,'*' };
	Lsekli l1 = { 0,'a',2,2 };
	s1 = sahneolustur(s1);//sekil progrm acikken degismez
	while (1)
	{
		system("cls");//ekrani temizler
		cout << endl;
		l1 = lsekliolustur(l1);
		do{system("cls");
		git(0, 1);
			sahneciz(s1);
			LSekliCizme(l1);
			l1 = LSekliAsagiGotur(l1);
			Sleep(100);
		} while (l1.y +2*l1.boyut< s1.yukseklik);	
	}
}

void git(int x, int y)//imec koordinat degisimi
{
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),koordinat);
}
sahne sahneolustur(sahne s1)
{
	srand(time(NULL));
	char karakterdizi[5] = { '*','#','$','+','@' };
	int rndm = rand() % 10+1;//random 0-10 arasi sayi verir
	if (rndm % 3 == 0)
		s1.genislik = 30;
	else if (rndm % 3 == 1)
		s1.genislik = 40;
	else
		s1.genislik = 50;
	
	s1.yukseklik = 20 + rand() % 10 + 1;//yukseklige 20-30 arasi sayi atar
	s1.karakter = karakterdizi[rand() % 5];//karakterdizisindeki elemanalrdan birini rndm degerine gore atar
		return s1;
}
void sahneciz(sahne s1)
{
	for (int i = 0; i < s1.genislik; i++)//ilk satira genislik kadar atanan karakteri cizer
		cout << s1.karakter;
	cout<< endl;
	
	for (int i = 0; i < s1.yukseklik - 2; i++)//ikinci satirdan sondan bir onceki satira kadar satir degisimi
	{
		cout << s1.karakter;//satirdaki ilk karakter
		git(s1.genislik -1, i+1);
		cout << s1.karakter<< endl;//satirdaki son karakter ve satir bitisi
	}

	for (int i = 0; i < s1.genislik; i++)//son satira genislik kadar atanan karakteri cizer
		cout << s1.karakter;
}
Lsekli lsekliolustur(Lsekli l1)
{
	srand(time(NULL));
	char karakterdizi[5] = { '*','#','$','+','@' };
	int rndm = 0, boyut = 0;
	do
	{
		 rndm = rand() % 25 + 1;
	} while (rndm < 5 || rndm>25);//5-25 arasi sayiyi x e atar
	l1.x = rndm;
	l1.y = 3;

	do
	{
		rndm = rand() % 7+ 1;	
	} while (rndm < 2 || rndm > 7);// 2- 7arasi sayiyi  atar
	l1.boyut = rndm;
	l1.karakter = karakterdizi[(rand()+3) % 5];

		return l1;
}
void LSekliCizme(Lsekli l1)
{
	for (int i = 0; i < l1.boyut; i++)//seklin ilk satiri
	{
		git(l1.x + i, l1.y);
		cout << l1.karakter;
	}

	for (int i = 0; i < l1.boyut; i++)//L seklindeki |_    _ ' ye kadarki uzun yer
	{
		git(l1.x, l1.y + i);
		cout << l1.karakter;
		git(l1.x+l1.boyut-1,l1.y + i);
		cout << l1.karakter;
	}
	for (int i = 0; i < l1.boyut; i++)//seklin solundaki karenin ust kismi
		cout << l1.karakter;
	for (int i = 0; i < l1.boyut - 1; i++)//seklin en solu ve sekildeki karenin en sagi
	{
		git(l1.x, l1.y+ l1.boyut+i);
		cout << l1.karakter;
		git(l1.x + 2*l1.boyut - 1, l1.y +l1.boyut + i);
		cout << l1.karakter;
	}
	for (int i = 0; i < 2 * l1.boyut; i++)//seklin en alt satiri;
	{
		git(l1.x+i, l1.y + 2 * l1.boyut - 1);
		cout << l1.karakter;
	}
}
Lsekli LSekliAsagiGotur(Lsekli l1)
{
	LSekliCizme(l1);
	l1.y++;
		return l1;
}
