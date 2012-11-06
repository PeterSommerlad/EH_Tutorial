#ifndef MYMIN_H_
#define MYMIN_H_

template <typename T>
inline T const &
min(T const &a, T const &b){
	return (a < b)? a : b ;
}

template <typename T>
inline T const * const &
min(T const * const &a, T const *const& b){
	return (*a < *b)? a : b ;
}
#include <cstring>
inline char const * const &
min( char const * const &a, char const * const &b){
	return std::strcmp(a,b) < 0? a : b;
}
#endif /*MYMIN_H_*/
