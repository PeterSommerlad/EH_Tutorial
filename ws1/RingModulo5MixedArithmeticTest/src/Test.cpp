#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Ring5.h"
void testDefaultCtor() {
    Ring5 v{};
    ASSERT_EQUAL(0,v.value());
}
void testValueCtor(){
    Ring5 four{4};
    ASSERT_EQUAL(4,four.value());
}
// operator==, operator<< for failures
void testValueCtorWithLargeInput(){
    Ring5 four{19};
    ASSERT_EQUAL(Ring5{4},four);
}
// define operator<< format
void testOutputOperator(){
    std::ostringstream out;
    out << Ring5{4};
    ASSERT_EQUAL("Ring5{4}",out.str());
}

void testAddition() {
    Ring5 two{2};
    Ring5 four = two+two;
    ASSERT_EQUAL(4,four.value());
}
void testAdditionWrap(){
    Ring5 four{4};
    Ring5 three = four + four;
    ASSERT_EQUAL(3,three.value());
}

void testMultiplication(){
    Ring5 four{4};
    Ring5 three{3};
    Ring5 two = four * three;
    ASSERT_EQUAL(Ring5{2},two);
}
void testAddAssignWithInteger(){
    Ring5 x{6};
    x += 8;
    ASSERT_EQUAL(Ring5{4},x);
}
void testAddWithInteger(){
    Ring5 x{6};
    x = x + 8;
    ASSERT_EQUAL(Ring5{4},x);
    x = 8 + x;
    ASSERT_EQUAL(Ring5{2},x);
}







void testAdditionWithInt(){
//*
    Ring5 two{2};
    auto four=two+2u;
    ASSERT_EQUAL(Ring5{4},four);
    ASSERT_EQUAL(typeid(Ring5).name(),
                 typeid(decltype(four)).name());
//*/
}

void testAssignmentBackToInt(){
    Ring5 three{8};
    unsigned u3=static_cast<unsigned>(three);
//*
    unsigned eight( u3+5u );
    ASSERT_EQUAL(8u,eight);
//*/
    ASSERT_EQUAL(Ring5{3},three);
    ASSERT_EQUAL(3u,u3);
}

void testAdditionWithIntExplicitCtor(){
    Ring5 two{2};
    auto four=two+Ring5{2u};
    ASSERT_EQUAL(Ring5{4},four);
    ASSERT_EQUAL(typeid(Ring5).name(),
                 typeid(decltype(four)).name());
}






void runSuite(){
    cute::suite s;
    //TODO add your test here
    s.push_back(CUTE(testDefaultCtor));
    s.push_back(CUTE(testValueCtor));
    s.push_back(CUTE(testValueCtorWithLargeInput));
    s.push_back(CUTE(testAddition));
    s.push_back(CUTE(testAdditionWrap));
    s.push_back(CUTE(testOutputOperator));
    s.push_back(CUTE(testMultiplication));
    s.push_back(CUTE(testAdditionWithInt));
    s.push_back(CUTE(testAssignmentBackToInt));
    s.push_back(CUTE(testAdditionWithIntExplicitCtor));
	s.push_back(CUTE(testAddAssignWithInteger));
	s.push_back(CUTE(testAddWithInteger));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



