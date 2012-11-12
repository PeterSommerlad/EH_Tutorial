#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <fstream>
#include <stdexcept>
using wl=std::set<std::string>;

wl generateAnagrams(std::string w){
	sort(w.begin(),w.end());
	wl res{};
	res.insert(w);
	while(std::next_permutation(w.begin(),w.end()))
		res.insert(w);
	return res;
}

wl readDictionary(std::string filename){
	std::ifstream in(filename);
	if (!in) throw std::logic_error{filename + ": file not found"};
	wl res{};
	std::string word{};
	while(in>>word){
		res.insert(word);
	}
	return res;
}

int main(){
	std::string w{"listen"};
	auto anas=generateAnagrams(w);
	auto dict=readDictionary("/usr/share/dict/words");
	std::ostream_iterator<std::string> out{std::cout,"\n"};
	set_intersection(anas.begin(),anas.end(),dict.begin(),dict.end(),out);
	std::cout << "..................\n";
	copy(anas.begin(),anas.end(),out);
}

