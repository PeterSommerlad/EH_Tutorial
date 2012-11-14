#include "sevensegmentdigit.h"
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

void testZero() {
	std::ostringstream out;
	printLargeDigit(0u,out);
	ASSERT_EQUAL(" - \n"
				 "| |\n"
			 	 "   \n"
		     	 "| |\n"
				 " - \n",out.str());
}
void testOne() {
	std::ostringstream out;
	printLargeDigit(1u,out);
	ASSERT_EQUAL("   \n"
				 "  |\n"
			 	 "   \n"
		     	 "  |\n"
				 "   \n",out.str());
}
void testTwo() {
	std::ostringstream out;
	printLargeDigit(2u,out);
	ASSERT_EQUAL(" - \n"
				 "  |\n"
			 	 " - \n"
		     	 "|  \n"
				 " - \n",out.str());
}
void testThree() {
	std::ostringstream out;
	printLargeDigit(3u,out);
	ASSERT_EQUAL(" - \n"
				 "  |\n"
			 	 " - \n"
		     	 "  |\n"
				 " - \n",out.str());
}
void testFour() {
	std::ostringstream out;
	printLargeDigit(4u,out);
	ASSERT_EQUAL("   \n"
				 "| |\n"
			 	 " - \n"
		     	 "  |\n"
				 "   \n",out.str());
}
void testFive() {
	std::ostringstream out;
	printLargeDigit(5u,out);
	ASSERT_EQUAL(" - \n"
				 "|  \n"
			 	 " - \n"
		     	 "  |\n"
				 " - \n",out.str());
}
void testSix() {
	std::ostringstream out;
	printLargeDigit(6u,out);
	ASSERT_EQUAL(" - \n"
				 "|  \n"
			 	 " - \n"
		     	 "| |\n"
				 " - \n",out.str());
}
void testSeven() {
	std::ostringstream out;
	printLargeDigit(7u,out);
	ASSERT_EQUAL(" - \n"
				 "  |\n"
			 	 "   \n"
		     	 "  |\n"
				 "   \n",out.str());
}
void testEight() {
	std::ostringstream out;
	printLargeDigit(8u,out);
	ASSERT_EQUAL(" - \n"
				 "| |\n"
			 	 " - \n"
		     	 "| |\n"
				 " - \n",out.str());
}
void testNine() {
	std::ostringstream out;
	printLargeDigit(9u,out);
	ASSERT_EQUAL(" - \n"
				 "| |\n"
			 	 " - \n"
		     	 "  |\n"
				 " - \n",out.str());
}
void testLargeEight() {
	std::ostringstream out;
	printLargeDigit(8u,2,out);
	ASSERT_EQUAL(	" -- \n"
					"|  |\n"
					"|  |\n"
					" -- \n"
					"|  |\n"
					"|  |\n"
					" -- \n", out.str());
}
void testVeryLargeEight() {
	std::ostringstream out;
	printLargeDigit(8u,4u,out);
	ASSERT_EQUAL(	" ---- \n"
					"|    |\n"
					"|    |\n"
					"|    |\n"
					"|    |\n"
					" ---- \n"
					"|    |\n"
					"|    |\n"
					"|    |\n"
					"|    |\n"
					" ---- \n", out.str());
}
void testNumber1234(){
	std::ostringstream out;
	printLargeNumber(1234,1,out);
	ASSERT_EQUAL("    -  -    \n"
			     "  |  |  || |\n"
			     "    -  -  - \n"
			     "  ||    |  |\n"
			     "    -  -    \n",out.str());
}


void runSuite(){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testZero));
	s.push_back(CUTE(testOne));
	s.push_back(CUTE(testTwo));
	s.push_back(CUTE(testThree));
	s.push_back(CUTE(testFour));
	s.push_back(CUTE(testFive));
	s.push_back(CUTE(testSix));
	s.push_back(CUTE(testSeven));
	s.push_back(CUTE(testEight));
	s.push_back(CUTE(testNine));
	s.push_back(CUTE(testLargeEight));
	s.push_back(CUTE(testNumber1234));
	s.push_back(CUTE(testVeryLargeEight));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
    runSuite();
    return 0;
}



