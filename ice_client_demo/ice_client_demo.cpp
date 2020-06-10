// ice_client_demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Ice/Ice.h>
#include "hello.h"
using namespace std;
using namespace Test;
int main(int argc, char* argv[])
{
    int status = 0;
	Ice::CommunicatorHolder ich(argc, argv);
	try
	{
		//字符转代理基对象
		Ice::ObjectPrx base = ich->stringToProxy("sayHello:default -p 10000");
		//查找远端是否由该服务对象，成功返回该对象的代理
		HelloPrx printer = HelloPrx::checkedCast(base);
		if (!printer)//如果不为空则调用sayhello服务器应做出相应反应
		{
			
			throw "invalid proxy";
		}
		else
		{
			printer->SayHello("hello");
		}
		return status;
	}
	catch (const Ice::Exception& e)
	{
		cerr << e << '\n';
		status = 1;
	}
	catch (const char* msg)
	{
		status = 1;
		cerr << msg << endl;
	}
	//销毁通信器
	if (ich)
	{
		try {
			ich->destroy();
		}
		catch(const Ice::Exception& ex){
			cerr << ex << endl;
			status = 1;
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
