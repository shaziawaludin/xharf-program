#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;

main(){
	
	int x[10];
	int i, nilaicari,j,k;
	bool found;
	char menu;
	int indeks = 0;
do{
	
	
	cout << "MENU";
	cout << "\n1. Tambah data";
	cout << "\n2. Cari data";
	cout << endl;
	cin >> menu;
	switch(menu)
	{
		case '1':
		{
			int banyak;
			cout << "Banyak data baru : ";
			cin >> banyak;
		
			for(int z = 0; z < banyak; z++)
			{
				cout << "Input nilai ke- " << z+1 << " : ";
				cin >> x[indeks+z];
				
			}
			indeks +=banyak;
		break;
		}
		
		case '2':
		{
			int temp;
			for(int z = 0; z < indeks-1 ; z++)
			{
				for(int y = 0 ; y < indeks-1-z; y++)
				{
					if(x[y] > x[y+1])
					{
						temp = x[y];
						x[y] = x[y+1];
						x[y+1] = temp;
					}
				}
			}
			cout << "nilai yang dicari: ";
			cin >> nilaicari;
			
			found = false;
			i = 0;
			j = indeks;
			while((!found) && i <= j)
			{
				k = (i + j) / 2;
				if(nilaicari == x[k])
					found = true;
				else
				{
					if(nilaicari < x[k])
						j = k-1;
					else
						i = k+1;
				}
				//cout << k << ',';
			}
			
			if(found)
				cout << nilaicari << " Ditemukan di indeks ke-" << k << endl;
			else 
				cout << "Tidak ada " << nilaicari << " dalam array" << endl;
		break;
		}
	}
		system("pause");
		system("cls");
}while(5);
}
