// stackdump.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <Windows.h>
#include "stdafx.h"
#include <iostream>
#include <stdio.h>

#include "dbgtool.h"

using namespace std;

void my_last_call()
{
	printf("%s\n", __FUNCTION__);
	DBGTOOL::dbgtool::printStack();
}

void my_second_call()
{
	int *p;

	printf("%s\n", __FUNCTION__);
	my_last_call();

	p = 0;
	*p = 10;
}

void my_first_call()
{
	my_second_call();
}

int _tmain(int argc, _TCHAR* argv[])
{
	DBGTOOL::dbgtool::regExcepHandler();

	my_first_call();
	return 0;
}