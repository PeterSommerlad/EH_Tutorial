#ifndef SACK_H_
#define SACK_H_
#include <vector> // implementation detail, might change...
#include <stdexcept>
template <typename T>
class Sack
{
	typedef std::vector<T> SackType;
	typedef typename SackType::size_type size_type;
	SackType theSack;
public:
	bool empty() const { return theSack.empty() ; }
	size_type size() const { return theSack.size();}
	void putInto(T const &item) { theSack.push_back(item);}
	T getOut() ;
	template <typename Elt>
	std::vector<Elt> asVector() const {
		std::vector<Elt> res(theSack.begin(),theSack.end());
		return res;
	}
};
template <class T>
inline
T Sack<T>::getOut(){
		if (! size()) throw std::logic_error("empty Sack");
		size_type index = static_cast<size_type>(rand()%size()); // rand() from cstdlib
		T retval = theSack.at(index);
		theSack.erase(theSack.begin()+index);
		return retval;
}

#include "SackSpecializations.h"
#endif /*SACK_H_*/
