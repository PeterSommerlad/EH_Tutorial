#ifndef MYMIN_H_
#define MYMIN_H_

inline int min(int a, int b){
	return (a < b)? a : b ;
}
inline double min(double a, double b){
	return (a < b)? a : b ;
}
#include <string>
inline std::string const &min(std::string const & a, std::string const & b){
	return (a < b)? a : b ;
}
#endif /*MYMIN_H_*/
