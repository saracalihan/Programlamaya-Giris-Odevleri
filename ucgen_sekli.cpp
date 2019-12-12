/*		*********************************************			
		**                                         **
		**     ÖĞRENCİ ADI......: Alihan SARAÇ     **
		**     ÖĞRENCİ NUMARASI.: G191210057       **
		**     DERS GRUBU.......: A	(İÖ)           **
		**                                         **
		*********************************************		
Açıklamalar her iki şekil için de şekillerin içini iki üçgene
ve üç boşluğa bölünüp yapılmıştır.İlk şeklin ilk boşluğu haricinde tüm şekilde " Boşluk(a) " fonksiyonu kullanılıp ,
fonksiyon ilk şeklin ilk boşluğu ile aynı şekilde yazılmıştır.  */

#include <iostream>
#include<iomanip>
#include<Windows.h> //Sleep fonksiyonu için.
using namespace std;

void satboyyıl(int sutn);//Bir satıra sutun sayısınca yıldız yazar;
void Boşluk(int a);//boşluklarve yıldızları için yazılmış bir fonksiyon . "a" for içindeki aritmetik işlem için 
int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter kullanımı için.

						//--------| DEĞER ALIMI VE KISITLAMASI |--------\\
	
    int satır, sutun;
	do 
	{
		cout << "Satır....:\n";//Satır değeri alır ve sayının 5-15 arasında olmasını sağlar.
		cin >> satır;
		while (satır > 15 || 5 > satır)
		{
			cout << "\aSatır numarası hatalı...Tekrar deneyin...:\n";
			cin >> satır;
		}

		cout << "Sütun....:\n";//Sütun değeri alır ve sayının 5-45 arasında olmasını sağlar.
		cin >> sutun;
		while (sutun > 45 || 5 > sutun)
		{
			cout << "\aSütun sayısı hatalı...Tekrar deneyin...:\n";
			cout << "Sütun....:\n";
			cin >> sutun;
		}

		if(sutun != 2 * satır)//Sütunun satırın iki katı olduğunun kontrolü
		{
			cout << "\aSütun sayısı satır sayısının iki katı olmalıdır...\n";
		}
	} while (sutun != 2 * satır);//Sutun sayısı satırın iki katına  eşit olana kadar çalışır.

						//--------| İLK ŞEKİL BAŞLANGICI |--------\\

	for (int sut = 1; sut <= sutun; sut++)//Sütun sayısı kadar ilk satıra yıldız yazar.
		//Buradan sonra şekil başına ve sonuna yazılacaklar " satboyyıl(int sutn) " fonksiyonu ile yapılacaktır. 
	{
		cout << "*";
		Sleep(100);
	}

	cout << endl;//İkinci satıra geçiş.
	
	for (int sat = 1; sat <= satır-2; sat++)//Desenin genişliğini satır sayısı kadar tutar.
	{
		cout << "*";//Her satırın başına ilk yıldız.

			for (int boşluk = 1; boşluk < (satır-1 - sat); boşluk++)//İlk boşlukaları bırakır.
			{
				cout << " ";
			}
		cout << "*";//İlk üçgen sonu.
		Sleep(100);
		 
		//		Buradan sonraki boşluk ve üçgen sonundaki yıldız işlemleri " Boşluk(a) " fonksiyonu ile yazılacaktır.     \\
				Fonksiyon yukarıdaki gibi olup , for işlemini a değerine göre yapar.

		Boşluk((2 * sat));//Ortadaki boşlukları bırakır ve ikinci üçgen başlangıcı.
			
		Boşluk(satır-2- sat);//Son boşlukaları bırakır ve yıldız yazar.
		
			cout << "\n";//Satır sonu.
	}

	satboyyıl(sutun);//İlk şeklin sonu.
	cout << endl<<endl;//Şekiller arası boşluklar.

						//--------| İKİNCİ ŞEKİL BAŞLANGICI |--------\\

	satboyyıl(sutun);//İkinci şeklin ilk satırı.
	cout << endl;
	
	for (int sat = 1; sat <= satır - 2; sat++)//Desenin genişliğini satır sayısı kadar tutar.
	{ 
		cout << "*";//Satır başlarına ilk yıldız.
		Sleep(100);

		Boşluk((sat-1));//İlk boşluk ve yıldızı.
		
		Boşluk(sutun-2 * (sat+1));//İkinci boşluk ve yıldızı
			
		Boşluk(sat-1);//Üçüncü boşluk ve yıldızı
		
		cout << "\n";//satır sonu
	}

	satboyyıl(sutun);//İkinci şeklin sonu.

						//--------| SON |--------\\

	cout << "\a\n\n" ;
	cout << "\t\t\t\tÖğrenci bilgilerine ulaşmak için 1 'e basınız...\n";
	int i;
	cin >> i;
	if (i == 1) {
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t*********************************************\n";
		cout << "\t\t\t\t**                                         **\n";
		cout << "\t\t\t\t**     ÖĞRENCİ ADI......: Alihan SARAÇ     **\n";
		cout << "\t\t\t\t**     ÖĞRENCİ NUMARASI.: G191210057       **\n";
		cout << "\t\t\t\t**     DERS GRUBU.......: A	(İÖ)       **\n";
		cout << "\t\t\t\t**                                         **\n";
		cout << "\t\t\t\t*********************************************\a\n\n\n\n";system("pause");
	}

	return 0;
}

void Boşluk(int a)//Boşluklar ve boşluktan sonraki yıldız için yazılmış bir fonksiyon.\\
					a for içindeki değişken.Sekildeki aritmetik kurallara göre verilir.
{
	for (int boşluk = 1; boşluk <= a; boşluk++)//Boşluk.
	{
		cout << " ";	
	}
	cout << "*";//boşluk arkasına  yıldız.
	Sleep(100);
}

void satboyyıl(int sutn)//Bir satır boyunca yıldız yazar;
{
	for (int i = 1; i <= sutn; i++)//Sütun satısı kadar ilk satıra yıldız yazar.
	{
		cout << "*";
		Sleep(100);
	}
}
