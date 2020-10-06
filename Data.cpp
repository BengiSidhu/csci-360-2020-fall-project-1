#include "Data.h"

Data::Data(string value, int size, int start_addr, string type)
{
	this->size = size;
	this->value = value;
	this->start_addr = start_addr; 
	this->type = type;
}

Data::~Data()
{
}
