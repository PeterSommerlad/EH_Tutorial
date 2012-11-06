#ifndef SACK_H_
#define SACK_H_
#include <vector>
template <typename E>
class Sack {
	std::vector<E> sack;
	typedef typename std::vector<E>::size_type size_type;
public:
	Sack(){}
	void putInto(E const &elt){
		sack.push_back(elt);
	}
	E getOut(){
		E elt=*sack.begin();
		sack.erase(sack.begin());
		return elt;
	}
};

#endif /* SACK_H_ */
