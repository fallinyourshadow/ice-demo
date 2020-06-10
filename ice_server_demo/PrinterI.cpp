#include "PrinterI.h"

void PrinterI::pprintString(std::string str,const Ice::Current&)
{
	printf("%s\n", str);
}