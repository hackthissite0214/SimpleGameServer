#include "../ServerCore/Common.h"
#include "../ServerCore/CriticalSection.h"

#pragma comment(lib, "../x64/Debug/ServerCore.lib")

class Test
{
public:
	void incre()
	{
		LockGuard guard(_cs);
		a++;
	}

public:
	int a = 0;
	CriticalSection _cs;
};

int main()
{
	Test t;
	t.incre();
	std::cout << t.a << std::endl;
}