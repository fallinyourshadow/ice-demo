// ice_server_demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Ice/Ice.h>
#include "helloI.h"
using namespace std;
int main(int arg, char* argv[])
{
    int status = 0;
    Ice::CommunicatorHolder ic(arg,argv);
    try {
        //初始化Ice, 获取通信指针，智能指针
        //在通信器ic上创建对象适配器,协议TCP，端口10000
        //   Ice::ObjectPtr object =  new HelloI;
        Ice::ObjectAdapterPtr adapter =
            ic->createObjectAdapterWithEndpoints("SimplePrinterAdapter", "default -p 10000");
        //创建服务者类对象
        Ice::ObjectPtr object = new HelloI;
;
        //将服务者对象添加到适配器中，客户端必须以同样的名字来请求服务者的操作
        adapter->add(object, Ice::stringToIdentity("sayHello"));
        //激活
        adapter->activate();
        //等待ctrl c中断信号
        ic->waitForShutdown();
    }
    catch (const Ice::Exception& e)
    {
        status = -1;
        cerr << e << endl;
    }
    catch (const char* msg)
    {
        status = -1;
        cerr << msg << endl;
    }
    //销毁通信器
    if (ic)
    {
        try
        {
            ic->destroy();
        }
        catch (const std::exception& e)
        {
            status = -1;
            std::cerr << e.what() << '\n';
        }
    }
    return status;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
