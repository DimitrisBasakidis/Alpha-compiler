/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    ID = 259,                      /* ID  */
    REAL = 260,                    /* REAL  */
    ASSIGN = 261,                  /* ASSIGN  */
    OR = 262,                      /* OR  */
    AND = 263,                     /* AND  */
    EQUAL = 264,                   /* EQUAL  */
    NOT_EQUAL = 265,               /* NOT_EQUAL  */
    GREATER_THAN = 266,            /* GREATER_THAN  */
    GREATER_EQUAL = 267,           /* GREATER_EQUAL  */
    LESSER_THAN = 268,             /* LESSER_THAN  */
    LESSER_EQUAL = 269,            /* LESSER_EQUAL  */
    LOWER_THAN_ELSE = 270,         /* LOWER_THAN_ELSE  */
    PLUS = 271,                    /* PLUS  */
    MINUS = 272,                   /* MINUS  */
    MULTIPLY = 273,                /* MULTIPLY  */
    SLASH = 274,                   /* SLASH  */
    MODULO = 275,                  /* MODULO  */
    UMINUS = 276,                  /* UMINUS  */
    NOT = 277,                     /* NOT  */
    INCREMENT = 278,               /* INCREMENT  */
    DECREMENT = 279,               /* DECREMENT  */
    DOT = 280,                     /* DOT  */
    DOUBLE_DOT = 281,              /* DOUBLE_DOT  */
    LEFT_SQUARE_BRACKET = 282,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 283,    /* RIGHT_SQUARE_BRACKET  */
    LEFT_PARENTHESIS = 284,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 285,       /* RIGHT_PARENTHESIS  */
    SEMICOLON = 286,               /* SEMICOLON  */
    LEFT_BRACKET = 287,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 288,           /* RIGHT_BRACKET  */
    COMMA = 289,                   /* COMMA  */
    COLON = 290,                   /* COLON  */
    DOUBLE_COLON = 291,            /* DOUBLE_COLON  */
    IF = 292,                      /* IF  */
    ELSE = 293,                    /* ELSE  */
    WHILE = 294,                   /* WHILE  */
    FOR = 295,                     /* FOR  */
    FUNCTION = 296,                /* FUNCTION  */
    RETURN_KW = 297,               /* RETURN_KW  */
    BRK = 298,                     /* BRK  */
    CONTINUE = 299,                /* CONTINUE  */
    LOCAL = 300,                   /* LOCAL  */
    TRUE_KW = 301,                 /* TRUE_KW  */
    FALSE_KW = 302,                /* FALSE_KW  */
    ENDL = 303,                    /* ENDL  */
    NIL = 304                      /* NIL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER 258
#define ID 259
#define REAL 260
#define ASSIGN 261
#define OR 262
#define AND 263
#define EQUAL 264
#define NOT_EQUAL 265
#define GREATER_THAN 266
#define GREATER_EQUAL 267
#define LESSER_THAN 268
#define LESSER_EQUAL 269
#define LOWER_THAN_ELSE 270
#define PLUS 271
#define MINUS 272
#define MULTIPLY 273
#define SLASH 274
#define MODULO 275
#define UMINUS 276
#define NOT 277
#define INCREMENT 278
#define DECREMENT 279
#define DOT 280
#define DOUBLE_DOT 281
#define LEFT_SQUARE_BRACKET 282
#define RIGHT_SQUARE_BRACKET 283
#define LEFT_PARENTHESIS 284
#define RIGHT_PARENTHESIS 285
#define SEMICOLON 286
#define LEFT_BRACKET 287
#define RIGHT_BRACKET 288
#define COMMA 289
#define COLON 290
#define DOUBLE_COLON 291
#define IF 292
#define ELSE 293
#define WHILE 294
#define FOR 295
#define FUNCTION 296
#define RETURN_KW 297
#define BRK 298
#define CONTINUE 299
#define LOCAL 300
#define TRUE_KW 301
#define FALSE_KW 302
#define ENDL 303
#define NIL 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

  int int_val;
  char* id;
  float real_val;

#line 171 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
