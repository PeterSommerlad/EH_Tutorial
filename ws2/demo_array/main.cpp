#include <iostream>
#include <iterator>
#include <array>
int main(int argc, char*argv[]){
	using namespace std;
	array<int,10> a={{1,1,2,3,5,8,}};
	array<double,4> d{{0.0,1.1,2.2,3.3}};

	ostream_iterator<int> out{cout,", "};
	copy( a.begin(), a.end(), out );
	cout << endl;
	ostream_iterator<double> outd{cout," - "};
	for(auto x:d){
		cout << x << "-";
	}
	cout << endl;
}
