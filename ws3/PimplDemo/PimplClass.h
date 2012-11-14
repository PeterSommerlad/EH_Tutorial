#ifndef PIMPLCLASS_H_
#define PIMPLCLASS_H_

#include <memory>

struct PimplClass{
	std::unique_ptr<class Impl> pimpl;
	~PimplClass();
	PimplClass();
//	PimplClass(PimplClass &&)=delete;
//	void operator=(PimplClass &&)=delete;
};
#endif /* PIMPLCLASS_H_ */
