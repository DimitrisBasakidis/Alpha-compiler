/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     ID = 259,
     STRING = 260,
     REAL = 261,
     ASSIGN = 262,
     OR = 263,
     AND = 264,
     NOT_EQUAL = 265,
     EQUAL = 266,
     LOWER_THAN_ELSE = 267,
     LESSER_EQUAL = 268,
     LESSER_THAN = 269,
     GREATER_EQUAL = 270,
     GREATER_THAN = 271,
     MINUS = 272,
     PLUS = 273,
     MODULO = 274,
     SLASH = 275,
     MULTIPLY = 276,
     DECREMENT = 277,
     INCREMENT = 278,
     NOT = 279,
     UMINUS = 280,
     DOUBLE_DOT = 281,
     DOT = 282,
     RIGHT_SQUARE_BRACKET = 283,
     LEFT_SQUARE_BRACKET = 284,
     RIGHT_PARENTHESIS = 285,
     LEFT_PARENTHESIS = 286,
     SEMICOLON = 287,
     LEFT_BRACKET = 288,
     RIGHT_BRACKET = 289,
     COMMA = 290,
     COLON = 291,
     DOUBLE_COLON = 292,
     IF = 293,
     ELSE = 294,
     WHILE = 295,
     FOR = 296,
     FUNCTION = 297,
     RETURN_KW = 298,
     BRK = 299,
     CONTINUE = 300,
     LOCAL = 301,
     TRUE_KW = 302,
     FALSE_KW = 303,
     ENDL = 304,
     NIL = 305
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define ID 259
#define STRING 260
#define REAL 261
#define ASSIGN 262
#define OR 263
#define AND 264
#define NOT_EQUAL 265
#define EQUAL 266
#define LOWER_THAN_ELSE 267
#define LESSER_EQUAL 268
#define LESSER_THAN 269
#define GREATER_EQUAL 270
#define GREATER_THAN 271
#define MINUS 272
#define PLUS 273
#define MODULO 274
#define SLASH 275
#define MULTIPLY 276
#define DECREMENT 277
#define INCREMENT 278
#define NOT 279
#define UMINUS 280
#define DOUBLE_DOT 281
#define DOT 282
#define RIGHT_SQUARE_BRACKET 283
#define LEFT_SQUARE_BRACKET 284
#define RIGHT_PARENTHESIS 285
#define LEFT_PARENTHESIS 286
#define SEMICOLON 287
#define LEFT_BRACKET 288
#define RIGHT_BRACKET 289
#define COMMA 290
#define COLON 291
#define DOUBLE_COLON 292
#define IF 293
#define ELSE 294
#define WHILE 295
#define FOR 296
#define FUNCTION 297
#define RETURN_KW 298
#define BRK 299
#define CONTINUE 300
#define LOCAL 301
#define TRUE_KW 302
#define FALSE_KW 303
#define ENDL 304
#define NIL 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 59 "parser.y"
{
  int int_val;
  char *str_val;
  float real_val;
  struct expr *ex;
  struct call_t *elist_call;
  struct stmt_t* statement_struct;
  struct SymbolTableEntry *symbol;
  struct forstruct_t *forprefix_struct;
  struct indexed_list_t *indexedlist_node;

}
/* Line 1529 of yacc.c.  */
#line 162 "parser.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

