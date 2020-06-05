#include <iostream>
#include <Ice/Ice.h>
#include "helloI.h"
using namespace std;
int main(int arg, char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try{
        //初始化Ice, 获取通信指针，智能指针
        ic = Ice::initialize(arg,argv);
        //在通信器ic上创建对象适配器,协议TCP，端口10000
        //   Ice::ObjectPtr object =  new HelloI;
        Ice::ObjectAdapterPtr adapter = 
        ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter","default -p 10000");
        //创建服务者类对象
        Ice::ObjectPtr object =  new HelloI;
        string sayHello = "sayHello"; 
        //将服务者对象添加到适配器中，客户端必须以同样的名字来请求服务者的操作
        adapter->add(object,ic->stringToIdentity(sayHello));
        
        adapter->activate();
        ic->waitForShutdown();
    }
    catch(const Ice::Exception& e)
    {
        status = -1;
        cerr << e << endl;
    }
    catch(const char* msg)
    {
        status = -1;
        cerr << msg << endl;
    }

    if(ic)
    {
        try
        {
            ic->destroy();
        }
        catch(const std::exception& e)
        {
            status = -1;
            std::cerr << e.what() << '\n';
        }
    
    }

    return status;
}

