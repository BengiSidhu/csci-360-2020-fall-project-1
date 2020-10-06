#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Data.h"
using namespace std;

/*
   Therefore, we can use string array to simulate memory storage.
   Assumptions:  1 insturction = 4 bytes
                 
*/

class Memory
{
	public:
		Memory();
		/* Get memory by address */
		string get(int start_addr); 
		/* Set memory by address */
		bool set(string value, int size, int start_addr, string type);
		/* 
			Display a segment of memory on the screen with the following format:
			addr     value
			2048     mov $1, %eax 
			2044     add $1, %eax
			...		 ...
		*/
		void display(string type);
		int get_start_addr_of_Text();
		~Memory();
	private:
		/*
		   data = <value, size>
		*/
		vector<Data> storage; 
		/* Create memory-layout for programs */
		int start_addr_of_stack = 2048;
		int start_addr_of_heap  = 1000;
		int start_addr_of_BSS   = 800;
		int start_addr_of_Data  = 700;
		int start_addr_of_Text  = 500;
};

#endif
