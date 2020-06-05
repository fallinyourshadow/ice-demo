#include "helloI.h"

string HelloI::SayHello(const string& str, const Ice::Current&)
{
    string ret = "hello";
    cout << "server receive msg: " << str << endl;
    return ret;
}