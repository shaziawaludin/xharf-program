#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;


struct jenis{
	char j_nama[15];
	unsigned int harga;
	unsigned int seat;
};

struct kereta{
	jenis k_jenis[4];
	
	char k_nama[30];
	char k_berangkat[6];
	char k_datang[6];
	
	
};

kereta ka_inf[50];

struct penumpang{
	char p_nama[30];
	char p_berangkat[5];
	char p_datang[5];
	char st_asal[30];
	char st_tujuan[30];
	unsigned int dewasa,infant;
	kereta ka_p_inf;
};


main(){
	char menu;
		char str1[] = {"09:00"};
		strcpy(ka_inf[0].k_berangkat,str1);
		strcpy(ka_inf[0].k_datang,"17:11");
		strcpy(ka_inf[0].k_nama,"BOGOWONTO");
	
		strcpy(ka_inf[0].k_jenis[0].j_nama,"Eko(C)");
		strcpy(ka_inf[0].k_jenis[1].j_nama,"Eko(P)");
		strcpy(ka_inf[0].k_jenis[2].j_nama,"Eko(Q)");
		strcpy(ka_inf[0].k_jenis[3].j_nama,"Eko(S)");
		ka_inf[0].k_jenis[0].harga = 220000;
		ka_inf[0].k_jenis[1].harga = 200000;
		ka_inf[0].k_jenis[2].harga = 165000;
		ka_inf[0].k_jenis[3].harga = 150000;
		ka_inf[0].k_jenis[0].seat=20;
		ka_inf[0].k_jenis[1].seat=20;
		ka_inf[0].k_jenis[2].seat=0;
		ka_inf[0].k_jenis[3].seat=0;
		
		strcpy(ka_inf[1].k_nama,"KRAKATAU");
		strcpy(ka_inf[1].k_berangkat,"12:43");
		strcpy(ka_inf[1].k_datang,"21:42");
		strcpy(ka_inf[1].k_jenis[0].j_nama,"Eko(C)");
		strcpy(ka_inf[1].k_jenis[1].j_nama,"Eko(P)");
		strcpy(ka_inf[1].k_jenis[2].j_nama,"Eko(Q)");
		strcpy(ka_inf[1].k_jenis[3].j_nama,"Eko(S)");
		ka_inf[1].k_jenis[0].harga = 270000;
		ka_inf[1].k_jenis[1].harga = 255000;
		ka_inf[1].k_jenis[2].harga = 220000;
		ka_inf[1].k_jenis[3].harga = 205000;
		ka_inf[1].k_jenis[0].seat=20;
		ka_inf[1].k_jenis[1].seat=0;
		ka_inf[1].k_jenis[2].seat=20;
		ka_inf[1].k_jenis[3].seat=0; 

		
		do{
			cout << "\t\t\t\tBOOKING TICKET";
			cout << "\n\t\t1. Beli tiket";
			cout << "\n\t\t2. Cari Kereta";
			cout << "\n\t\t3. Keluar";
			cout << "\n\t\t";
			cin >> menu;
			system("cls");
			switch(menu)
			{
				case '2':
				{
					bool found[2][4];
					bool found2[2];
					int banyak = 0;
					for(int j = 0; j < 2 ; j++){
					int i = 0;
					int check = 0;
						while( i < 4)
						{
							if(ka_inf[j].k_jenis[i].seat != 0)
							{
								found[j][i] = true;
								check++;
							}
							else 
							found[j][i] = false;
							
							i++;
						}
						if(check > 0)
						{
							found2[j] = true;
							banyak++;
						}
						else
						found2[j] = false;
					}
					
					cout << "Banyak Kereta tersedia : " << banyak;
					cout << endl;
					int j = 0;
					while(found2[j] && j < 2)
					{ 
					int i = 0;
					cout << endl << setfill('-') << setw(70)<<' ' << endl;
					cout << setfill('-') << setw(70)<<' ' << endl;
					cout << setfill(' ');
					cout << setw(28) << ' ' << "Datang" << "\t\tBerangkat" << endl;
					cout << ka_inf[j].k_nama << setw(30-strlen(ka_inf[j].k_nama)) << ' ' << ka_inf[j].k_datang << setw(20-strlen(ka_inf[j].k_datang)) <<' ' << ka_inf[j].k_berangkat<<endl;
					cout << setfill('-') << setw(70)<<' ' << endl;
						cout << setfill(' ');
					cout << "Kelas" << setw(15) << ' ' << "Harga" << setw(10) << ' ' << "Seat" << endl;
					
						while(i < 4)
						{	
							if(found[j][i])
							cout << endl << ka_inf[j].k_jenis[i].j_nama << setw(18-strlen(ka_inf[j].k_jenis[i].j_nama)) << ' ' << "Rp." << ka_inf[j].k_jenis[i].harga <<  setw(10) << ' ' << ka_inf[j].k_jenis[i].seat;
							i++;
						}
					j++;
					}
					break;
				}
			}
			cout << endl;
			system("pause");
		}while(5);
}
