#include "sevensegmentdigit.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

namespace {
std::vector<std::vector<std::string>> const nums = {
			{" - ","| |","   ","| |"," - "},
			{"   ","  |","   ","  |","   "},
			{" - ","  |"," - ","|  "," - "},
			{" - ","  |"," - ","  |"," - "},
			{"   ","| |"," - ","  |","   "},
			{" - ","|  "," - ","  |"," - "},
			{" - ","|  "," - ","| |"," - "},
			{" - ","  |","   ","  |","   "},
			{" - ","| |"," - ","| |"," - "},
			{" - ","| |"," - ","  |"," - "}
	};
}
std::vector<std::vector<std::string>> const numsz = {
		{" - ","   "," - "},
		{"| |","  |","  |"},
		{"   ","   "," - "},
		{"| |","  |","|  "},
		{" - ","   "," - "}};
void printLargeDigit(unsigned i, std::ostream& out) {
	std::ostream_iterator<std::string const> os{out,"\n"};
	copy(nums.at(i).begin(),nums.at(i).end(),os);

}
// version loops only and complex logic
void printLargeDigit1(unsigned i, unsigned scale, std::ostream& out) {
	for (size_t row = 0; row < nums.at(i).size(); ++row) {
		for (size_t vsc = 0; vsc < (row % 2 ? scale : 1); ++vsc) {
			out << nums.at(i).at(row).at(0);
			for (size_t sc = 0; sc < scale; ++sc) {
				out << nums.at(i).at(row).at(1);
			}
			out << nums.at(i).at(row).at(0);
			out << '\n';
		}
	}
}
namespace{
void printRowScaled(std::string row,unsigned scale,std::ostream &out){
	out << row.front();
	std::ostream_iterator<char> oi{out};
	fill_n(oi,scale,row[1]);
	out << row.back();
}
void printRowScaled(std::string row,unsigned scale,std::ostream &out,bool scaled,std::string sep="\n"){
	for (size_t i=0; i<(scaled?scale:1); ++i) {
		printRowScaled(row,scale,out);
		out << sep;
	};
}
}
void printLargeDigit(unsigned digit, unsigned scale, std::ostream & out) {
	bool odd=false;
	for_each(nums.at(digit).begin(),nums.at(digit).end(),[&](std::string row){
		printRowScaled(row,scale,out,odd);
		odd = !odd;
	});
}
void printLargeNumber(unsigned number, unsigned scale, std::ostream &out) {
	auto s = std::to_string(number);
	for (size_t row = 0; row < nums.front().size(); ++row) {
		for_each(s.begin(), s.end(), [&](char c) {
			printRowScaled(nums.at(c-'0').at(row),scale,out,row%2,"");
		});
		out << '\n';
	}
}

