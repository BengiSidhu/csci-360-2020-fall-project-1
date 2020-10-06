#ifndef DATACONVERTER_H
#define DATACONVERTER_H

#include <string>
#include <iomanip>
#include <bitset>
#include <vector>

using namespace std;


class DataConverter
{
	public:
		static int binarytointeger(string data);
		static string integertobinary(int value);
		static void split(const string &txt, vector<string> &strs, char ch);
	protected:
};

#endif
