#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <stdint.h>

/* IMPLEMENT ME - see documentation in translate.c */
unsigned write_pass_one(FILE* output, const char* name, char** args, int num_args);


int translate_inst(FILE* output, const char* name, char** args, size_t num_args, 
    uint32_t addr, SymbolTable* symtbl, SymbolTable* reltbl);

/* Declaring helper functions: */

int write_rtype(uint8_t funct, FILE* output, char** args, size_t num_args);

int write_shift(uint8_t funct, FILE* output, char** args, size_t num_args);

uint32_t create_instr_r_type(int rs, int rt, int rd, int shamt, uint8_t funct);

uint32_t create_instr_i_type(uint8_t opcode, int rs, int rt, int imm);


/* IMPLEMENT ME ~ write*_ functions*/

int write_jr(uint8_t funct, FILE* output, char** args, size_t num_args);

int write_addiu(uint8_t opcode, FILE* output, char** args, size_t num_args);

int write_ori(uint8_t opcode, FILE* output, char** args, size_t num_args);

int write_xori(uint8_t opcode, FILE* output, char** args, size_t num_args);

int write_lui(uint8_t opcode, FILE* output, char** args, size_t num_args);

int write_mem(uint8_t opcode, FILE* output, char** args, size_t num_args);

int write_mult_div(uint8_t funct, FILE* output, char** args, size_t num_args);

int write_mfhi_mflo(uint8_t funct, FILE* output, char** args, size_t num_args);

int write_branch(uint8_t opcode, FILE* output, char** args, size_t num_args, 
    uint32_t addr, SymbolTable* symtbl);

int write_jump(uint8_t opcode, FILE* output, char** args, size_t num_args, 
    uint32_t addr, SymbolTable* reltbl);

#endif
