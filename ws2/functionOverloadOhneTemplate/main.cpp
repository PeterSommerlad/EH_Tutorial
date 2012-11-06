#include "MyMin.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	int i = 88;
	cout << "min(i,42) = " << ::min(i,42) << endl;
	double pi = 3.1415;
	double e = 2.7182;
	cout << "min(e,pi) = " << ::min(e,pi) << endl;
	string s1 = "Hallo";
	string s2 = "Hallihallo";
	cout << "min(Hallo,Hallihallo) = " << ::min(s1,s2)<<endl;
	//::min(2,pi); // compilefehler
	::min(static_cast<double>(2),pi); 
	cout << "min(Fredy,Peter) = " << ::min("Fredy","Peter") << endl;
}
