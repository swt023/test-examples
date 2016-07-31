#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#include <stdarg.h> 

#include "test.h"

using namespace::std;

class Solution;

void testCompareVersion();

typedef int (*TestFun)(TestCase&);

typedef int (*TestSetup)(list<TestCase>&);


int testCompareVersion(TestCase&);
int compareCaseSetup(list<TestCase> &cases);
int twoSumSetup(list<TestCase> &cases);
int twoSumTest(TestCase&);
int threeSumSetup(list<TestCase> &cases);
int threeSumTest(TestCase& tc);



template<typename T>
void printVec(vector<T> &v);


int test(int argc, char **argv)
{
	int retval;
	TestFun testFun;
	TestSetup testSetup;
	list<TestCase> cases;

	// function init
	
	//testSetup = compareCaseSetup;
	//testFun = testCompareVersion;
	
	//testSetup = twoSumSetup;
	//testFun = twoSumTest;	

	testSetup = threeSumSetup;
	testFun = threeSumTest;

	// test cases setup
	retval = testSetup(cases);

	// excute cases one by one
	list<TestCase>::iterator it;
	for(it = cases.begin(); it != cases.end(); it++)
	{
		retval = testFun(*it);
	}


	// execute single test function
	
	return retval;
}



#define END 0x80000001
void initCaseVec(list<TestCase> &tcs, int arg, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, arg);
	
	int nArgValue = arg;
	int nArgCout = 0;
	
	TestCase tc;
	tc.vInt.clear();

	do {
		nArgCout++;
		printf("the %d th arg: %d\n", nArgCout, nArgValue);
		tc.vInt.push_back(nArgValue);
		
		nArgValue = va_arg(arg_ptr, int);
	} while (nArgValue != END);
	
	va_end(arg_ptr);

	tcs.push_back(tc);
}


void initCaseVec(list<TestCase> &tcs, const char *arg, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, arg);
	
	const char *argValue = arg;
	int nArgCout = 0;
	
	TestCase tc;
	tc.vStr.clear();

	do {
		nArgCout++;
		printf("the %d th arg: %s\n", nArgCout, argValue);
		tc.vStr.push_back((char *)argValue);
		
		argValue = (char *)va_arg(arg_ptr, long);
	} while ((long)argValue != END);
	
	va_end(arg_ptr);

	tcs.push_back(tc);
}

template<typename T>
void printVec(vector<T> &v)
{
	typename vector<T>::iterator it;
	cout<<"<<<------vector members, size = "<<v.size()<<endl;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout<<*it<<"   ";
	}
	cout<<endl<<"--->>>"<<endl;
}

int twoSumSetup(list<TestCase> &cases)
{
	initCaseVec(cases, 0, 0, 4, 3, 0, END);
	initCaseVec(cases, 9, 1, 3, 6, 12, END);
	initCaseVec(cases, 8, 3, 5, 9, END);
	initCaseVec(cases, 12, 2, 4, 7, 9, 10, END);
	initCaseVec(cases, 16, 2, 4, 7, 8, 9, END);
	
	initCaseVec(cases, 16, 2, 4, 7, 11, 19, END);
	initCaseVec(cases, 1, 2, 4, 7, 9, END);
	initCaseVec(cases, 10, 2, 4, 7, 9, END);

	return 0;
}
int twoSumTest(TestCase& tc)
{
	Solution s;

	printVec(tc.vInt);
	
	int target;
	if (!tc.vInt.empty())
	{
		target = *tc.vInt.begin();
		tc.vInt.erase(tc.vInt.begin());
		//printVec(tc.vInt);
	
		vector<int> v = s.twoSum(tc.vInt, target);
		if (!v.empty()) {
			cout<<*v.begin()<<", "<<*(v.begin()+1)<<endl;
		} else {
			cout<<"no two numbers sum to "<<target<<endl;
		}
	}
	return 0;
}


int threeSumSetup(list<TestCase> &cases)
{
	initCaseVec(cases, 0, -1, -1, 1, 2, END);
	initCaseVec(cases, 0, 1, -2, -3, 2, END);
	initCaseVec(cases, 0, 0, 0, END);
	initCaseVec(cases, -1, -1, -1, 1, 1, 2, END);
	initCaseVec(cases, 5, -4, -1, -5, 4, 1, END);
	
	initCaseVec(cases, 16, 2, 4, 7, 11, 19, END);
/**/
	return 0;
}
int threeSumTest(TestCase& tc)
{
	Solution s;

	cout<<"input:"<<endl;
	printVec(tc.vInt);
	
	if (!tc.vInt.empty())
	{
		vector<vector<int> > v = s.threeSum(tc.vInt);
		for (vector<vector<int> >::iterator it = v.begin(); it != v.end(); it++) {
			printVec(*it);
		}
	}
	return 0;
}



int compareCaseSetup(list<TestCase> &cases)
{
	initCaseVec(cases, "1.0", "1.01", END);
	initCaseVec(cases, "0.0.0.1", "1", END);
	initCaseVec(cases, "1.1", "2.0", END);
	/*
	TestCase tcs[] = {{"1.0", "1.01"},
					  {"0.0.0.1", "1"},
					  {"1.1", "2.0"},
					  {"0.1", "2.0"},
					  {"10.1", "10.02.0"},
					  {"10.1", "10.1.1"},
					  
					  {"10.1.1.1.1", "10.1.1"},
					  {"10.1", "2.0"},
					  {"10.1", "10.0.2"},
					  {"10.1.0.1", "10.1"},
					  {"20.1.", "05.2"},
					  
					  {"1.0", "1"},
					  {"1.0", "01"},
					  {"01.0", "1.0.0"},
					  {"0.0.0", "0"},
					  {"10.1", "10.1.0"}};

	size_t size = sizeof(tcs)/sizeof(TestCase);
	for (size_t i = 0; i < size; i++)
	{
		cases.push_back(tcs[i]);
	}
*/
}



int testCompareVersion(TestCase &tc)
{
	Solution s;
	int ret = 0;
	string v1 = tc.str1; // tc.vStr[0];
	string v2 = tc.str2;  // tc.vStr[1];

	ret = s.compareVersion(v1, v2);
	cout<<"result = "<<ret<<", v1 = "<<v1<<", v2 = "<<v2<<endl;
}

int Solution::compareVersion(string version1, string version2) {
	vector<int> v1, v2;

	// covert versions to int array
	char buf[256] = {0};
	char *p;
	const char *sem = ".";
	
	snprintf(buf, sizeof(buf), "%s", version1.c_str());
	p = strtok(buf, sem);
	while (p != NULL)
	{
		v1.push_back(atoi(p));
		p = strtok(NULL, sem);
	}

	memset(buf, 0, sizeof(buf));
	snprintf(buf, sizeof(buf), "%s", version2.c_str());
	p = strtok(buf, sem);
	while (p != NULL)
	{
		v2.push_back(atoi(p));
		p = strtok(NULL, sem);
	}

	// compare int array elements
	
	size_t i = 0;
	cout<<"v1.size(): "<<v1.size()<<", v2.size():" <<v2.size()<<endl;
	for (; i < v1.size() && i < v2.size(); i++)
	{
		//cout<<"v1["<<i<<"]: "<<v1[i]<<", v2["<<i<<"]: "<<v2[i]<<endl;
		if (v1[i] < v2[i])
		{
			return -1;
		}
		else if (v1[i] > v2[i])
		{
			return 1;
		}
	}

	if(v1.size() == v2.size() && i == v1.size())
	{
		return 0;
	}
	else if(i == v2.size())
	{
		for (size_t ii = i; ii < v1.size(); ii++)
		{
			//cout<<"v1["<<ii<<"]: "<<v1[ii]<<endl;
			if (v1[ii] != 0)
			{
				return 1;
			}
		}
		return 0;
	}
	else if (i == v1.size())
	{
		for (size_t ii = i; ii < v2.size(); ii++)
		{
			//cout<<"v2["<<ii<<"]: "<<v2[ii]<<endl;
			if (v2[ii] != 0)
			{
				return -1;
			}
		}
		return 0;
	}
}

vector<int> Solution::twoSum(vector<int> &numbers, int target)
{
	vector<int> v;
	size_t i, size;
	size = numbers.size();

	typedef multimap<int, int> MMAP_NUM;
	MMAP_NUM mmNumIdx;

	for (i = 0; i < size; i++) {
		mmNumIdx.insert(pair<int, int>(numbers[i], i));
	}
	
	for (i = 0; i < size; i++) {
		pair<MMAP_NUM::iterator, MMAP_NUM::iterator> ret;
		ret = mmNumIdx.equal_range(target - numbers[i]);

		for (MMAP_NUM::iterator it = ret.first; it != ret.second; it++) {
			if (it->second != i) {
				v.push_back(i + 1);
				v.push_back(it->second + 1);
				return v;
			}
		}
	}
	return v;
}

vector<vector<int> > Solution::twoSumV(vector<int> &numbers, int target)
{
	vector<vector<int> > vv;
	vector<int> v;
	size_t i, size;
	size = numbers.size();

	typedef multimap<int, int> MMAP_NUM;
	MMAP_NUM mmNumIdx;

	for (i = 0; i < size; i++) {
		mmNumIdx.insert(pair<int, int>(numbers[i], i));
	}
	
	for (i = 0; i < size; i++) {
		pair<MMAP_NUM::iterator, MMAP_NUM::iterator> ret;

		ret = mmNumIdx.equal_range(target - numbers[i]);
		
		for (MMAP_NUM::iterator it = ret.first; it != ret.second; it++) {
			
			if (it->second != i) {
				v.push_back(-target);
				v.push_back(numbers[i]);
				v.push_back(target - numbers[i]);
				sort(v.begin(), v.end());
				
				vv.push_back(v);
				v.clear();
				break;
			}
		}
		mmNumIdx.erase(ret.first, ret.second);
		ret = mmNumIdx.equal_range(numbers[i]);
		mmNumIdx.erase(ret.first, ret.second);
	}
		
	return vv;
}


vector<vector<int> > Solution::threeSum(vector<int> &num) {
	vector<vector<int> > vv, ret;
	
	for (int i = 0; i < num.size(); i++) {
		vector<int> v(num.begin()+i+1, num.end());
		if (!v.empty()) {
			vv = twoSumV(v, -num[i]);
			ret.insert(ret.end(), vv.begin(), vv.end());
		}
	}
		
	return ret;
}




