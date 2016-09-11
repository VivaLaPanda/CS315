
#ifndef __LEX_HPP
#define __LEX_HPP

#include<iostream>

const int MAX_ATOM_LEN = 9;
enum tokens {LPAREN = '(', RPAREN = ')', ATOM, END_OF_TEXT};

void init_lex();
tokens get_token( char name[] );
void unget_token();

#endif
