#include "PimplClass.h"

struct Impl{};

PimplClass::~PimplClass() {
}

PimplClass::PimplClass()
:pimpl(new Impl){
}
