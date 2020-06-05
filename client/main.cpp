#include "hello.h"
#include <Ice/Ice.h>


int main(int argc,char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;
    try
    {
        {
            ic = Ice::initialize(argc,argv);
            //代理基类对象
            Ice::ObjectPrx base = ic->stringToProxy("sayHello:defulat -p 10000");
            //向下转型代理类，使用该方法会向服务器发送请求
            //成功返回接口的代理，失败返回null
            Test::HelloPrx sayHello = Test::HelloPrx::checkedCast(base);
            if(!sayHello)
                throw "Invaild proxy";
            //调用代理操作
            sayHello->SayHello("client");

        }
    }
    catch(const std::exception& ex)
    {
        status = -1;
        std::cerr << ex.what() << '\n';
    }
    catch(const char* msg)
    {
        status = -1;
        std::cerr << msg << '\n';
    }
    
    return status;
}
