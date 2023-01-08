#include "../ServerCore/Common.h"
#include "../ServerCore/Singleton.h"
#pragma comment(lib, "../x64/Debug/ServerCore.lib")

/*
void InvalidParameterHandler(const wchar_t* expression, const wchar_t* function, const wchar_t* file, unsigned int line, uintptr_t pReserved)
{
	wprintf(L"Invalid parameter Detected in Function %s, File: %s, Line: %d\n", function, file, line);
	wprintf(L"Expression: %s\n", expression);
}

int main()
{
	char* string;

	_invalid_parameter_handler oldHandler, newHandler;
	newHandler = InvalidParameterHandler;
	oldHandler = _set_invalid_parameter_handler(newHandler);

	_CrtSetReportMode(_CRT_ASSERT, 0);

	string = NULL;
	printf(string);

	return 0;
}
*/

class Test : public Singleton
{
public:
	void s()
	{
		std::cout << "t" << std::endl;
	}

	DECLEAR_SINGLETON(Test);
};

IMPLEMENT_SINGLETON(Test);

int main()
{
	Test::Instance()->s();
	return 0;
}