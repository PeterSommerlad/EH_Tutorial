#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <vector>
#include <array>
#include <functional>
#include <set>
template <typename T>
struct Vector{
	typedef std::vector<T> cont;
	std::vector<T> c;
	Vector(){}
template <typename ITER>
	Vector(ITER b, ITER e);
	typedef typename std::vector<T>::iterator iterator;
	typedef typename cont::const_iterator const_iterator;
	iterator begin() { return c.begin(); }
	const_iterator begin() const { return c.begin(); }
	typedef typename cont::size_type size_type;
	size_type size() const { return c.size(); }
	T & front() { return c.front(); }
	T const & front() const { return c.front(); }
};
template <typename T>
template <typename ITER>
	Vector<T>::Vector(ITER b, ITER e)
	:c(b,e){}



void newTestFunction(){
	using std::set;
	set<int> const vc;
	for (set<int>::const_iterator it=vc.begin(); it != vc.end(); ++it){

	}
	ASSERTM("start writing tests", false);
}


void thisIsATest() {
	std::array<int,6> a={{1,2,3,4,5,6}};
	Vector<int> v(a.begin(),a.end());
	Vector<int> x(7,42);
	ASSERT_EQUAL(6,v.size());
	ASSERT_EQUAL(7,x.size());
	ASSERT_EQUAL(42,x.front());
}

void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(newTestFunction));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



