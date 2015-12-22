#ifndef	_TEST_H_
#define _TEST_H_

#include <string>
#include <list>
#include <set>
#include <map>
#include <vector>

using namespace::std;


int test(int, char**);

class TestCase{
public:
	TestCase(){}
	TestCase(string s1, string s2):str1(s1),str2(s2){}
	TestCase(vector<int> v):vInt(v){}
	TestCase(vector<string> v):vStr(v){}
	string str1;
	string str2;

	vector<int> vInt;
	vector<string> vStr;
};

class Solution {
public:
    int compareVersion(string version1, string version2);
	vector<int> twoSum(vector<int> &numbers, int target);
	vector<vector<int> > twoSumV(vector<int> &numbers, int target);
    vector<vector<int> > threeSum(vector<int> &num);	
};


#endif
