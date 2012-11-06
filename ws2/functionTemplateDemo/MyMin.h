#ifndef MYMIN_H_
#define MYMIN_H_

template <typename T>
inline T const &
min(T const &a, T const &b){
	return (a < b)? a : b ;
}
#endif /*MYMIN_H_*/
