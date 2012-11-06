#ifndef SACKSPECIALIZATIONS_H_
#define SACKSPECIALIZATIONS_H_
// assume we are inluded only in Sack.h
#include <tr1/memory>
template <typename T>
class Sack<T*>
{
public:
	typedef std::tr1::shared_ptr<T> value_type;
	typedef std::vector<value_type> SackType;
	typedef typename SackType::size_type size_type;
	bool empty() { return theSack.empty() ; }
	size_type size() { return theSack.size();}
	void putInto(T *item) { theSack.push_back(value_type(item));}
	void putInto(value_type item) { theSack.push_back(item);}
	value_type getOut() {
		size_type index = static_cast<size_type>(rand()%size()); // rand() from cstdlib
		value_type retval = theSack.at(index);
		theSack.erase(theSack.begin()+index);
		return retval;
	}
private:
	SackType theSack;
};
//-----

#include <string>
template <>
class Sack<char *> {
	typedef std::vector<std::string> SackType;
	typedef SackType::size_type size_type;
	SackType theSack;
public:
	// no explicit ctor/dtor required
	bool empty() { return theSack.empty() ; }
	size_type size() { return theSack.size();}
	void putInto(char const *item) { theSack.push_back(item);}
	std::string getOut() {
		std::string result=theSack.back();
		theSack.pop_back();
		return result;
	}
};
#endif /*SACKSPECIALIZATIONS_H_*/
