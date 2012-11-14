#ifndef SEVENSEGMENTDIGIT_H_
#define SEVENSEGMENTDIGIT_H_
#include <iosfwd>
void printLargeDigit(unsigned digit, std::ostream &out);
void printLargeDigit(unsigned digit, unsigned scale, std::ostream &out);
void printLargeNumber(unsigned number, unsigned scale, std::ostream &out);

#endif /* SEVENSEGMENTDIGIT_H_ */
