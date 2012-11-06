#include <iostream>
#include "Sack.h"
#include <iterator>

int main(){
	using namespace std;
	Sack<int> sack;
	//int i = sack.getOut();
	sack.putInto(42);
	cout << "size of sack: " << sack.size() << endl;
	cout << "get from sack: " << sack.getOut() << endl;
	cout << "size of sack: " << sack.size() << endl;
	for (int i = 0; i < 20; ++i )
		sack.putInto(i);
	cout << "size of sack: " << sack.size() << endl;
	while (!sack.empty()){
		cout << "get from sack: " << sack.getOut() << endl;
	}
	Sack<char> scrabble;
	for (char c='A'; c <= 'Z'; ++c)
		scrabble.putInto(c);
	std::vector<int> values=scrabble.asVector<int>();
	copy(values.begin(),values.end(),ostream_iterator<int>(cout,"; "));
	
	while (!scrabble.empty()){
		cout << "play letter: " << scrabble.getOut() << endl;
	}	
	//---
	Sack<char*> spezial;
	spezial.putInto("Peter");
	//char *out = spezial.getOut(); // compile error
	cout << spezial.getOut() << endl;
	//--- partial spec
	Sack<int *> partialspezial;
	partialspezial.putInto(new int(42));
	cout << * partialspezial.getOut() << endl;
	
}
