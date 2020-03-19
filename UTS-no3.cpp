#include <iostream>
#include <stdlib.h>
using namespace std;
float s(int n);

int main(){
	cout << "\nS(3)= ";
	cout << " = " << s(3);
	cout << endl;
	system("pause");
	return(0);
}


float s(int n){
	float deret = 0,x,p,q;
	int i=n;
	if(i > 0)
	{
		p=2*i; q = 3*i+1;
		x = p/q;
		if(i==1) cout << p << "/" << q;
		else cout << p << "/" << q << " + ";
		deret = x + s(n-1) ;
		return(deret);
	}
	else
		return(0);
}
