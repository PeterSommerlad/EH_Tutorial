#include <iostream>
#include <string>
using namespace std;
#include "MyMin.h"

int main(){
	int i = 88;
	cout << "min(i,42) = " << ::min(i,42) << endl;
	double e = 2.7182;
	double pi = 3.1415;
	cout << "min(e,pi) = " << ::min(e,pi) << endl;
	string s1 = "Hallo";
	string s2 = "Hallihallo";
	cout << "min(Hallo,Hallihallo) = " << ::min(s1,s2)<<endl;
	//::min(2,pi); // compilefehler
	::min<double>(2,pi); // explizite instantiierung
	double const *ep=&e;
	double const *pip=&pi;
	cout << "min(&e,&pi) = " << *::min(ep,pip)<<endl;
	cout << "min(Fredy,Peter) = " 
	     << ::min(static_cast<char const *>("Peter"),
	    		 static_cast<char const *>("Fredy")) << endl;
	cout << "min<string>(Fredy,Peter) = " << ::min<string>("Fredy","Peter") << endl;
	char const *paul="Paul";
	char const *peter="Peter";
	cout << "min(Paul,Peter) = " << ::min(paul,peter) << endl;
	cout << "min(Peter,Paul) = " << ::min(peter,paul) << endl;
	cout << "min(&e,&pi) = " << *::min<double>(&e,&pi)<<endl;
}
