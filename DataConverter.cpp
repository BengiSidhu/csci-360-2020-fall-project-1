#include "DataConverter.h"

/*
	Function: binary to integer
*/
int DataConverter::binarytointeger(string data){
	string num = data; 
    int dec_value = 0; 
    int base = 1; 
    int len = num.length(); 
    for (int i=len-1;i>=0;i--) 
    { 
        if (num[i] == '1')         
            dec_value += base; 
        base = base * 2; 
    } 
    return dec_value; 	
}

/*
	Function: integer to binary, 16 bits; 
*/
string DataConverter::integertobinary(int data){
	string binary = bitset<16>(data).to_string();	
	return binary;
}

/*
	Function: split string by character
*/
void DataConverter::split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();
    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
        pos = txt.find( ch, initialPos );
    }
    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
}

