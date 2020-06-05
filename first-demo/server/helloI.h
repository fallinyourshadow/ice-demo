#ifndef __HELLOI_H
#define __HELLOI_H
#include <iostream>
#include "hello.h"
#include <string>
using namespace std;
//骨架类Hello由slice2cpp生成，是一个纯虚类，不允许实例化
//接口处理类HelloI
class HelloI:public Test::Hello
{
public:
    //实现接口
    //@2 Ice::Current对象为服务器中的操作实现提供了有关当前执行请求的信息
    string SayHello(const string& , const Ice::Current&);

};

#endif