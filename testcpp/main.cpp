#include <stdio.h>
#include <string>
#include <iostream>

#include "test.h"

using namespace::std;

int main(int argc, char **argv)
{
	int retval = 0;

	cout<<"test begin!"<<endl;

	test(argc, argv);

	cout<<"test end!"<<endl;
	return retval;
}
