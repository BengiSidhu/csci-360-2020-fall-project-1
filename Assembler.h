#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cmath>
#include "DataConverter.h"

using namespace std;

struct Variable{
	string type;
	string variable_name;
	int initial_value=0;
	int addr_offset;			
};

struct Function{
	string function_name;
	string return_type;
	vector<Variable> variables; 
	vector<string> assembly_instructions; 
	bool is_leaf_function;   // is_leaf_function == false && variables.size() > 0, we need to add "subq %16, %rsp" into  assembly_instructions 
};

struct Compare_statment{
	string operator_str;
	string revsered_operator_str;
	string operand1;
	string operand2;
	string jump_tag; 
};
		
class Assembler
{
	public:
		Assembler();
		string* compile(string* codes, int max);
		vector<Variable> variable_handler(string variable_str, int format, int &addr_offset); 
		void display_function_info();
		string add_mov_insturction(string source, string destination, int size);
		int get_offset_by_variable_name(string name, vector<Variable> variables);
		~Assembler();
		
		/*
		    updated to v1.1
		*/
		void function_handler(string* codes, int loc, int max_len);					// v1.1
		bool is_function_call(string source);						  				// v1.1 
		Function *get_function_obj_from_code(string source);						// v1.1
		Variable get_variable_by_name(string name, vector<Variable> variables);	// v1.1
		void function_call_handler(string* source, int loc, Function &f);			// v1.1
		void return_handler(string* source, int loc, Function &f);					// v1.1
		Compare_statment compare_statement_parser(string source);					// v1.1
		void variable_offset_allocation(string* source, int &loc, Function &f1, int &addr_offset);			// v1.1
		void IF_statement_handler(string* source, int &loc, int max_len, Function &f1, int &addr_offset); 	// v1.1
		bool common_instruction_handler_dispatcher(string* source, int &loc, int max_len, Function &f1, int &addr_offset); // v1.1
		
		/*
			updated to v1.2
		*/
		string compare_statement_handler(string source, Function &f);								// v1.2
		void FOR_statement_handler(string* source, int &loc, int max_len, Function &f1, int &addr_offset); 	// v1.2
		void arithmetic_handler(string source, Function &f);						// v1.2
		string array_operand_handler(string array_element_str, Function &f1, string reg32, string reg64);		// v1.2
		vector<Function> get_functions();
	private:
		vector<Function> functions;
		string register_for_argument_32[6] = {"edi", "esi", "edx", "ecx", "r8d", "r9d"}; // v1.1 
		string register_for_argument_64[6] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};	 // v1.1 
		int label_index = 1;															 // v1.1
};

#endif
