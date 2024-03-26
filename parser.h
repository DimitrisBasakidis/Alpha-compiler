/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    ID = 259,
    STRING = 260,
    REAL = 261,
    ASSIGN = 262,
    OR = 263,
    AND = 264,
    EQUAL = 265,
    NOT_EQUAL = 266,
    GREATER_THAN = 267,
    GREATER_EQUAL = 268,
    LESSER_THAN = 269,
    LESSER_EQUAL = 270,
    LOWER_THAN_ELSE = 271,
    PLUS = 272,
    MINUS = 273,
    MULTIPLY = 274,
    SLASH = 275,
    MODULO = 276,
    UMINUS = 277,
    NOT = 278,
    INCREMENT = 279,
    DECREMENT = 280,
    DOT = 281,
    DOUBLE_DOT = 282,
    LEFT_SQUARE_BRACKET = 283,
    RIGHT_SQUARE_BRACKET = 284,
    LEFT_PARENTHESIS = 285,
    RIGHT_PARENTHESIS = 286,
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
#define EQUAL 265
#define NOT_EQUAL 266
#define GREATER_THAN 267
#define GREATER_EQUAL 268
#define LESSER_THAN 269
#define LESSER_EQUAL 270
#define LOWER_THAN_ELSE 271
#define PLUS 272
#define MINUS 273
#define MULTIPLY 274
#define SLASH 275
#define MODULO 276
#define UMINUS 277
#define NOT 278
#define INCREMENT 279
#define DECREMENT 280
#define DOT 281
#define DOUBLE_DOT 282
#define LEFT_SQUARE_BRACKET 283
#define RIGHT_SQUARE_BRACKET 284
#define LEFT_PARENTHESIS 285
#define RIGHT_PARENTHESIS 286
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

  int int_val;
  char *str_val;
  float real_val;
  struct expr_t* expression;

#line 164 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
