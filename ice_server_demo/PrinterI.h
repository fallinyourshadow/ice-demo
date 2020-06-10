#pragma once
#include "printer.h"
#include <Ice/Ice.h>
using namespace Demo;
class PrinterI :
    public Printer
{
public:
    virtual void pprintString(std::string str, const Ice::Current&);
};

