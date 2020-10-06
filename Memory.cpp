#include "Memory.h"

Memory::Memory()
{
	
}

string Memory::get(int start_addr){
	/*
	
	*/
	for (auto & element : this->storage) {
    	if(element.start_addr==start_addr){
    		return element.value;
		}
	}
	return "empty";
}

bool Memory::set(string value, int size, int start_addr, string type){
	Data d(value, size, start_addr, type);
	this->storage.push_back(d);
	return true;
}

int Memory::get_start_addr_of_Text(){
	return start_addr_of_Text;
} 

/*
   Example code for memory display
*/
void Memory::display(string type){
	
	cout << "-------------------------------------------------------------"<<endl;
	cout << "-                     MEMORY DISPLAY                        -"<<endl;
	cout << "-------------------------------------------------------------"<<endl;
		
	for (auto & element : this->storage) {
		if(element.type == type){
			cout << element.start_addr << ":\t" << element.value << endl;
		}
	}
}

Memory::~Memory()
{
}
