/*						*********************************************
						**                                         **
						**     ÖĞRENCİ ADI......: Alihan SARAÇ     **
						**     ÖĞRENCİ NUMARASI.: G191210057       **
						**     DERS GRUBU.......: A	(İÖ)           **
						**                                         **
						*********************************************

 Tüm programdaki i ve j değişkenleri sırasıyla x ve y eksenlerini (satır-sutun) temsil etmektedir.		
Matrisi yazma işlemi " diziyaz(int matris[][],int matris_boyutu) " fonksiyonuyla yapılmıştır.
ctrl kontrol değişkenidir , matris ve menünün tekrar yazılmasına karar verir.
Elemanı oluşturan rakam sayısına göre boşluklar azalır ve sayı dört rakamdan oluşuyorsa boşluk 
kalmaz,sayının son hanesitablodaki sutun numarasının hemen altında olacaktır.
*/
#include <iostream>
#include <time.h>//rastgele sayılar için
void diziyaz(int dizi[25][25], int boyut);//verilen diziyi boyutuna göre yazar 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");//Türkçe karakterler için.
	int boyut, islem, islem2, satir, sutun, geçici, toplam = 0, ctrl = 1;
	int matris[25][25], matris2[25][25], satır[25], geçicid[25];
													//--------|BOYUT GİRİŞİ|--------\\

	do //Boyutun 5-25 arasında olmasını sağlar
	{
		cout << "Matris Boyutu : ";
		cin >> boyut;
		while (boyut < 5 || boyut>25)
		{
			cout << "Matris boyutu 25'den küçük , 5'den büyük olmalıdır!\nMatris Boyutu : ";
			cin >> boyut;

		}
	} while (boyut < 5 || boyut>25);

	srand(time(NULL));//Frklı random sayılar için
												    //--------| DİZİYİ ATAMA |--------\\

	for (int i = 0; i < boyut; i++) //Satır değişimi						
	{
		for (int j = 0; j < boyut; j++)
		{
			matris[i][j] = rand() % 9 + 1;// i ve j ye göre matrise 1-9 arası rakam atar 
		}
	}
											    	//--------| DİZİYİ YAZMA |--------\\
	
	do
    {
	diziyaz(matris, boyut);
											    	//--------| MENÜ İŞLEMELERİ |--------\\
	
	cout << "\n\n\a1-Sutun Satır Değiştir\n2-Tekleri Başa Al\n3-Ters Çevir(Sutun)\n4-Toplamarı Yazdır\n\a";
	cin >> islem;
	
		switch (islem)
		{
		case 1:
			cout << "Satır Sutun : ";
			cin >> satir >> sutun;

			if (satir <= boyut && sutun <= boyut && sutun != 0 && satir != 0)//Satır ve sutunun boyuttan küçük ve sıfırdan büyük olmasını sağlar
			{
				for (int j = 0; j < boyut; j++)//Seçilen satırı satır adlı diziye atar
					satır[j] = matris[satir - 1][j];

				geçici = matris[sutun - 1][sutun - 1];
				for (int j = 0; j < boyut; j++)//Satıra seçilen sutunu aktarır
					matris[satir - 1][j] = matris[j][sutun - 1];
				for (int j = 0; j < boyut; j++)//Satır dizisini matris dizisine atar
					matris[j][sutun - 1] = satır[j];
				matris[satir - 1][sutun - 1] = satır[0] + geçici;//Kesişim noktalarını toplar
				diziyaz(matris, boyut);
				ctrl--;
			}
			else
				cout << "Satır ve sutun matris boyutundan büyük ve sıfır olamaz!\n";
		break;
		case 2:
			cout << "Satır numarası :";
			cin >> satir;

			if (satir <= boyut &&satir != 0)//Satırın boyuttan küçük olmasını sağlar
			{
				for (int j = 0; j < boyut; j++)
				{
					if (matris[satir - 1][j] % 2 == 0) //Eleman çift sayı ise
						geçicid[boyut - 1 - j] = matris[satir - 1][j];//Boyuttna j sayısını çıkararak dizinin sonuna yazar
					else
						geçicid[j] = matris[satir - 1][j];// 0. elemandan başlayarak dizer
				}
				for (int j = 0; j < boyut; j++)
					matris[satir - 1][j] = geçicid[j];
				diziyaz(matris, boyut);
				ctrl--;
			}
			else//Hata verir ve en başa döner
				cout << "Satır sayısı boyuttan küçük , sıfırdan büyük olmalıdır!\n";
		break;
		case 3:
			cout << "Sutun numarası : ";
			cin >> sutun;

			if (sutun <= boyut && sutun != 0)//Sutun sayısını sıfırdan farklı ve boyuttan küçük olmasını sağlar
			{
				for (int i = 0; i < boyut; i++)//Sutunlar geçici olarak satır dizisine atar
					satır[i] = matris[boyut - i - 1][sutun - 1];//Ters olarak atar
				for (int i = 0; i < boyut; i++)
					matris[i][sutun - 1] = satır[i];
				diziyaz(matris, boyut);
				ctrl--;
			}
			else
				cout << "Sutun sayısı boyuttan küçük , sıfırdan büyük olmalıdır!\n";
		break;
		case 4:
			for (int i = 0; i < boyut; i++)//Genel toplamı hesaplar
			{
				for (int j = 0; j < boyut; j++)
					toplam += matris[i][j];//Kendini bir önceki elemanla toplar
			}
			for (int i = 0; i < boyut; i++)//Toplamdan kendini çıkartır
			{
				for (int j = 0; j < boyut; j++)
				{
					matris2[i][j] = toplam - matris[i][j];//matris2'nin i ve j elemanına (toplam - matris)  atar
					toplam = toplam - matris[i][j];//Toplamdan kendini çıkarır
				}
			}matris2[0][0] += matris[0][0]; //İlk elemana genel toplamı atar
			diziyaz(matris2, boyut);//matris2 yi yazdırır
			ctrl--;		
			break;
		default:
			cout << "ISLEM HATASI!\n\a";
		}
	} while (ctrl);
	system("pause");
	return 0;
}
											    	//--------| FONKSİYON |--------\\

void diziyaz(int matris[25][25], int boyut)
{
	cout << "\t";
	for (int sutsay = 1; sutsay <= boyut; sutsay++)//İlk satıra sutun sayısnı yazar
		if (sutsay > 9)//Sutun sayısı yazılırken 9 u geçince sayı iki haneye geçtiği için kaymayı engeller
			cout << sutsay <<"  ";
		else
			cout << sutsay << "   ";
	cout << endl << "     ";
	for (int sutsay = 1; sutsay <= boyut * 4; sutsay++)//Sutun sayısı kadar _ yazar
		cout << "_";

	for (int i = 0; i < boyut; i++) //Satır değişimi
	{
		cout << endl << endl;
		cout << " " << i + 1; //İlk boşluk ve satır numarası
		if(i+1<10)//Sutundaki sayı rakamasa üç boşluk bırakır
			cout<<"  "<<"|";
		else//Sutundaki sayı iki rakama çıkıyorsa boşluk sayısını iki ye indirir
			cout <<" "<< "|";
		for (int j = 0; j < boyut; j++)//Matrisin elemanlarının değerlerine göre boşluk sayısını ayarlar
		{
			if (matris[i][j] >= 10 && matris[i][j] <= 99)//İki rakamdan(10-99) oluşuyorsa boşluk sayısını azaltarak şekli korur 
				cout << "  ";
			else if (matris[i][j] <= 10)//Sadece rakamsa(1-9)
				cout << "   ";
			else if (matris[i][j] >= 100 && matris[i][j] < 1000)//Üç rakamdan oluşuyorsa(100-999)
				cout << " ";
			else//Dört rakamdan(1000-9999) oluşuyorsa
				cout << "";
			cout << matris[i][j];//ElemanI yazar
		}
	}
	cout << endl;//Satır sonu
} 

