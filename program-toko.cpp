#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int jmlitm = 1;
void ketemu(int i);
struct item{
	char nama[30], stok;
	unsigned int banyak , no;
	int harga;
	};

item barang[1000];

void inputbaru(){
	int loop;
	system("cls");
	cout << "==| Input Data Baru >" << endl;
	cout << "Jumlah data baru : ";
	cin >> loop;
	
	for(int i =0 ; i < loop; i++){
		cout << "\nBarang Baru ke -" << i+1;
		cout << "\nNama barang : ";
		cin.ignore();
		cin.getline(barang[jmlitm+i].nama,30);
		cout << "Jumlah stok : "; 
		cin >> barang[jmlitm+i].banyak;
			if(barang[jmlitm+i].banyak > 0)
				barang[jmlitm+i].stok = 'A';
			else 
				barang[jmlitm+i].stok = 'T';
		cout << "Harga\t : ";
		cin >> barang[jmlitm+i].harga;
		barang[jmlitm+i].no = jmlitm+i;
	}
	jmlitm += loop;
}

void database(){
	cout << "No." << setw(2)<< " " << "Nama Barang" << setw(20) << ' ' <<"Harga";
	cout << setw(11) << ' ' << "Stok" << setw(4)<<' '<< "Banyak";
	cout << endl;
	for(int i = 1; i < jmlitm ; i++)
	{
		ketemu(i);
	}
	cout << endl;
	system("pause");
}

void editdata(){
	system("cls");
	unsigned int search;
	bool found = false;
	cout << "==| Input Data - Edit >" << endl;
	cout << "No. Barang : ";
	cin >> search;
	unsigned int i = 1;
	while(i <= search)
	{
	if(i == barang[i].no) found = true;
	
	if(found){
		cout << "\nNama barang : ";
		cin.ignore();
		cin.getline(barang[i].nama,30);
		cout << "Jumlah stok : "; 
		cin >> barang[i].banyak;
			if(barang[i].banyak > 0)
				barang[i].stok = 'A';
			else 
				barang[i].stok = 'T';
		cout << "Harga\t : ";
		cin >> barang[i].harga;
	}
		i++;
	}
	
}

void ketemu(int i){
	int pjgno,pjgnama,pjgharga;
			int j = barang[i].no;
			pjgno = 0;
			while(j > 0){
				j = (j - (j%10))/10;
				pjgno++;
			}
			int k = barang[i].harga;
			pjgharga = 0;
			while(k > 0){
				k = (k-k%10)/10;
				pjgharga++;
			} 
			pjgnama = strlen(barang[i].nama);
			cout << barang[i].no << setw(4-pjgno) << ' ' << barang[i].nama << setw(30-pjgnama) << ' ' << "Rp." ;
			cout << barang[i].harga << setw(15-pjgharga) << ' ' << barang[i].stok << setw(7)<<' ' << barang[i].banyak;
			cout << endl;
}
void searchharga(){
	int search;
	system("cls");
	cout << "==0 Cari barang - Harga 0==" << endl;
	cout << "Harga Barang : ";
	cin >> search;
	int i=1;
	
	cout << "No." << setw(2)<< " " << "Nama Barang" << setw(20) << ' ' <<"Harga";
	cout << setw(11) << ' ' << "Stok" << setw(4)<<' '<< "Banyak";
	cout << endl;
	while(i < jmlitm){
		if(barang[i].harga == search){
			ketemu(i);
		}
	i++;
	}
	cout << endl;
	system("pause");
}

string convertToString(char* a, int size) 
{ 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
} 

void searchnama(){
	string search;
	system("cls");
	cout << "==0 Cari barang - Nama 0==" << endl;
	cout << "Nama Barang : ";
	cin.ignore();
	getline(cin, search);
	int i=1;
	
	cout << "No." << setw(2)<< " " << "Nama Barang" << setw(20) << ' ' <<"Harga";
	cout << setw(11) << ' ' << "Stok" << setw(4)<<' '<< "Banyak";
	cout << endl;
	
	while(i < jmlitm){
		bool ada = false;
		int s_size = sizeof(barang[i].nama)/sizeof(char);
		string s_s = convertToString(barang[i].nama,s_size);
		int found =0 ;
		int z=0;
		while(z < 30 && found == 0)
		{
			
			found = s_s.find(search,found+z); //untuk mencari lokasi jika ada kata yang sama
			//fungsi find selalu mengembalikan nilai -1 jika telah mencapai
			//akhir dari kalimat, olehkarenanya perlu pengendalian untuk keluar
			//dari perulangan ketika find telah mencapai akhir kalimat.
			if(found == -1) z=30;
			else ada = true;
			z++;
		}
		if(ada){
			ketemu(i);
		}
	i++;
	}
	cout << endl;
	system("pause");
	
}

void searchjml(){
	unsigned int search;
	system("cls");
	cout << "==0 Cari barang - Jumlah 0==" << endl;
	cout << "Jumlah Stok Barang : ";
	cin >> search;
	int i=1;
	
	cout << "No." << setw(2)<< " " << "Nama Barang" << setw(20) << ' ' <<"Harga";
	cout << setw(11) << ' ' << "Stok" << setw(4)<<' '<< "Banyak";
	cout << endl;
	while(i < jmlitm){
		if(barang[i].banyak == search){
			ketemu(i);
		}
		i++;
	}
	cout << endl;
	system("pause");
}


main(){
	char menu1;
do{
	do{
		system("cls");
		cout << "\t\t    ______________" << endl;
		cout << "\t\t===| Program Toko |==="<<endl;
		cout << "\t\t    --------------" << endl;
		cout << "\t\t1. Input Data" << endl;
		cout << "\t\t2. Cari Barang" << endl;
		cout << "\t\t3. Urutkan Barang" << endl;
		cout << "\t\t4. Database" << endl;
		cout << "\n\n0. Exit" << endl;
		cout << "Pilih : ";
		cin >> menu1;
		if(menu1 == '0') exit(0);
	}while(menu1 !='1' && menu1 !='2' && menu1 !='3' && menu1 !='4');
	switch(menu1){
		case '1' :
		{
			char menu11;
			do{
				do{
					system("cls");
					cout << "==| Input Data >" << endl;
					cout << "  1. Input baru" << endl;
					cout << "  2. Edit data" << endl;
					cout << "  3. Hapus data" << endl;
					cout << "\n\n0. Kembali" << endl;
					cout << "Pilih : ";
					cin >> menu11;
				}while(menu11 != '1' && menu11 != '2' && menu11 != '3' && menu11 != '0');
				switch(menu11){
					case '1':
					{
						inputbaru();
						break;
					}
					case '2':
					{
						editdata();
						break;
					}
					case '3':
					{
						system("cls");
						cout << "==| Delete >" << endl;
						cout << "Nama Barang : ";
						break;
					}
					case '0':
					{
						break;
					}
				
				}
			}while(menu11 != '0');
			break;
		}
		case '2' :
		{	char menu21;
			do{	
				do{
					system("cls");
					cout << "==0 Cari barang 0==" << endl;
					cout << "  1. Berdasar harga" << endl;
					cout << "  2. Berdasar nama" << endl;
					cout << "  3. Berdasar stok" << endl;
					cout << "\n\n0.Kembali" << endl;
					cout << "Pilih : ";
					cin >> menu21;
				}while(menu21 != '1' && menu21 != '2' && menu21 != '3' && menu21 != '0');
				switch(menu21){
					case '1':
					{
						searchharga();
						break;
					}
					case '2':
					{
						searchnama();
						break;
					}
					case '3':
					{	
						searchjml();
						break;
					}
					case '0' :
					{
						break;
					}
				}
			cout << endl;
			}while(menu21 != '0');
			break;
		}
		case '3' :
		{
			char menu31;
			do{
				do{
					system("cls");
					cout << "=||\\|| Pengurutan Barang ||/||=" << endl ;
					cout << "1. Harga Tertinggi" << endl ; 
					cout << "2. Harga Terendah" << endl ;
					cout << "\n\n0. Kembali" << endl;
					cout << "Pilih : "; 
					cin >> menu31;
				}while( menu31 != '1' && menu31 != '2' && menu31 != '0');
				switch(menu31){
					case '1':
					{
						break;
					}
					case '2':
					{
						break;
					}
					case '0':
					{
						break;
					}
					
				}
			cout << endl;
			}while(menu31 != '0');
			break;
		}
		case '4' :
		{
			database();
			break;
		}
	}
}while(5);
}
