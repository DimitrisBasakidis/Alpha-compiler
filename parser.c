/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Compiler/grammatical_rules/grammar_functions.h"

#include "Compiler/utilities/quads.h"
#include "Compiler/utilities/elist.h"
#include "Compiler/utilities/target_code_generators.h"
#include "Compiler/utilities/binary_file.h"

#define YYERROR_VERBOSE 1

int yylex(void);
void yyerror(const char *error_msg);
void print_errors(const char *error_msg, char *token, const char *error_type);
void convert_to_binary(void);
void write_to_file(void); 

const char *file_name;

quad* quads = (quad*)0;
unsigned total = 0;
unsigned int currQuad = 0;

incomplete_jump *ij_head = (incomplete_jump *) 0;
unsigned ij_total = 0;

instruction* instructions = (instruction*) 0;
unsigned total_f = 0;
unsigned int currInstruction = 0 ;
funcstack * funcs; 

int scope = 0;
int func_in_between = 0;
int is_return_kw = 0;
int from_func_call = 0;
int in_loop = 0;
int from_elist = 0;
int while_loop = 0;
int for_loop = 0;
int if_stmt = 0;
int global_val_exists = 0;
int is_local_kw = 0;
int boolflag = 0;

unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

int temp_count = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

extern int column;
extern char *lineptr;

SymTable *symtable;
scopeLists *lists;
scope_stack *stack;
scope_stack *loop_stack;
scope_stack *func_scopes;

size_t nfuncs = 0U;
SymbolTableEntry *entry;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 74 "parser.y"
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
/* Line 193 of yacc.c.  */
#line 282 "parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 295 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   572

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    16,    18,
      20,    22,    25,    28,    30,    32,    34,    36,    40,    44,
      48,    52,    56,    60,    64,    68,    72,    73,    78,    79,
      84,    85,    91,    92,    98,   100,   104,   107,   110,   113,
     116,   119,   122,   124,   128,   130,   132,   134,   138,   140,
     142,   145,   148,   150,   152,   156,   161,   165,   170,   171,
     177,   180,   187,   189,   191,   195,   201,   203,   207,   208,
     210,   214,   218,   220,   224,   225,   231,   232,   237,   238,
     242,   244,   245,   248,   250,   251,   253,   254,   255,   256,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   285,
     286,   292,   294,   296,   300,   303,   308,   309,   310,   314,
     318,   319,   320,   321,   330,   333,   334,   342,   343,   347,
     348
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    -1,    53,    54,    -1,    54,
      -1,    55,    32,    -1,    95,    -1,    99,    -1,   105,    -1,
     107,    -1,    44,    32,    -1,    45,    32,    -1,    76,    -1,
      85,    -1,    32,    -1,    61,    -1,    55,    18,    55,    -1,
      55,    17,    55,    -1,    55,    21,    55,    -1,    55,    20,
      55,    -1,    55,    19,    55,    -1,    55,    16,    55,    -1,
      55,    15,    55,    -1,    55,    14,    55,    -1,    55,    13,
      55,    -1,    -1,    55,    11,    56,    55,    -1,    -1,    55,
      10,    57,    55,    -1,    -1,    55,     9,    58,   101,    55,
      -1,    -1,    55,     8,    59,   101,    55,    -1,    60,    -1,
      31,    55,    30,    -1,    17,    55,    -1,    24,    55,    -1,
      23,    63,    -1,    63,    23,    -1,    22,    63,    -1,    63,
      22,    -1,    62,    -1,    63,     7,    55,    -1,    63,    -1,
      66,    -1,    72,    -1,    31,    85,    30,    -1,    87,    -1,
       4,    -1,    46,     4,    -1,    37,     4,    -1,    65,    -1,
      64,    -1,    63,    27,     4,    -1,    63,    29,    55,    28,
      -1,    66,    27,     4,    -1,    66,    29,    55,    28,    -1,
      -1,    66,    31,    67,    71,    30,    -1,    63,    68,    -1,
      31,    85,    30,    31,    71,    30,    -1,    69,    -1,    70,
      -1,    31,    71,    30,    -1,    26,     4,    31,    71,    30,
      -1,    55,    -1,    55,    35,    71,    -1,    -1,    73,    -1,
      29,    71,    28,    -1,    29,    74,    28,    -1,    75,    -1,
      75,    35,    74,    -1,    -1,    33,    55,    36,    55,    34,
      -1,    -1,    33,    77,    53,    34,    -1,    -1,    33,    78,
      34,    -1,     4,    -1,    -1,    42,    79,    -1,    94,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    80,    31,    81,    30,
      86,    83,    82,    84,    -1,     3,    -1,     6,    -1,     5,
      -1,    50,    -1,    47,    -1,    48,    -1,     4,    -1,    40,
      -1,    31,    55,    30,    -1,    -1,    38,    92,    31,    55,
      30,    -1,    39,    -1,    88,    -1,    88,    35,    94,    -1,
      91,    54,    -1,    91,    54,    93,    54,    -1,    -1,    -1,
      96,    54,    97,    -1,    89,    90,    98,    -1,    -1,    -1,
      -1,    41,   103,    31,    71,    32,   101,    55,    32,    -1,
      30,   100,    -1,    -1,   102,   100,    71,   104,    98,   106,
     100,    -1,    -1,    43,   108,    32,    -1,    -1,    43,   109,
      55,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   119,   122,   145,   147,   152,   153,   154,
     155,   156,   163,   170,   171,   172,   175,   176,   181,   185,
     189,   193,   197,   204,   211,   218,   225,   225,   233,   233,
     241,   241,   248,   248,   255,   258,   259,   260,   266,   279,
     295,   318,   343,   347,   366,   371,   376,   377,   378,   382,
     387,   394,   398,   399,   402,   403,   408,   409,   412,   412,
     416,   430,   435,   436,   438,   445,   452,   453,   454,   456,
     458,   468,   481,   482,   483,   486,   490,   490,   491,   491,
     494,   495,   504,   519,   520,   522,   524,   526,   528,   528,
     541,   542,   543,   544,   545,   546,   549,   561,   563,   571,
     571,   579,   581,   582,   585,   586,   616,   618,   620,   622,
     630,   631,   633,   633,   643,   645,   645,   657,   657,   662,
     662
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ID", "STRING", "REAL",
  "ASSIGN", "OR", "AND", "NOT_EQUAL", "EQUAL", "LOWER_THAN_ELSE",
  "LESSER_EQUAL", "LESSER_THAN", "GREATER_EQUAL", "GREATER_THAN", "MINUS",
  "PLUS", "MODULO", "SLASH", "MULTIPLY", "DECREMENT", "INCREMENT", "NOT",
  "UMINUS", "DOUBLE_DOT", "DOT", "RIGHT_SQUARE_BRACKET",
  "LEFT_SQUARE_BRACKET", "RIGHT_PARENTHESIS", "LEFT_PARENTHESIS",
  "SEMICOLON", "LEFT_BRACKET", "RIGHT_BRACKET", "COMMA", "COLON",
  "DOUBLE_COLON", "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN_KW",
  "BRK", "CONTINUE", "LOCAL", "TRUE_KW", "FALSE_KW", "ENDL", "NIL",
  "$accept", "program", "statements", "stmt", "expr", "@1", "@2", "@3",
  "@4", "term", "assignexpr", "primary", "lvalue", "tableitem", "member",
  "call", "@5", "callsuffix", "normcall", "methodcall", "elist",
  "objectdef", "tablemake", "indexed", "indexedelem", "block", "@6", "@7",
  "funcname", "funcprefix", "funcargs", "funcbody", "funcblockstart",
  "funcblockend", "funcdef", "@8", "const", "idlist_id", "open_while",
  "whilecond", "ifprefix", "@9", "elseprefix", "idlist", "ifstmt",
  "loopstart", "loopend", "loopstmt", "whilestmt", "N", "M", "forprefix",
  "@10", "N_right_par", "forstmt", "@11", "returnstmt", "@12", "@13", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    55,    57,    55,
      58,    55,    59,    55,    55,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    64,    64,    65,    65,    67,    66,
      66,    66,    68,    68,    69,    70,    71,    71,    71,    72,
      73,    73,    74,    74,    74,    75,    77,    76,    78,    76,
      79,    79,    80,    81,    81,    82,    83,    84,    86,    85,
      87,    87,    87,    87,    87,    87,    88,    89,    90,    92,
      91,    93,    94,    94,    95,    95,    96,    97,    98,    99,
     100,   101,   103,   102,   104,   106,   105,   108,   107,   109,
     107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     4,     0,     4,
       0,     5,     0,     5,     1,     3,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     1,     1,     3,     1,     1,
       2,     2,     1,     1,     3,     4,     3,     4,     0,     5,
       2,     6,     1,     1,     3,     5,     1,     3,     0,     1,
       3,     3,     1,     3,     0,     5,     0,     4,     0,     3,
       1,     0,     2,     1,     0,     1,     0,     0,     0,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       5,     1,     1,     3,     2,     4,     0,     0,     3,     3,
       0,     0,     0,     8,     2,     0,     7,     0,     3,     0,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    90,    49,    92,    91,     0,     0,     0,     0,    68,
       0,    15,    76,     0,    99,    97,   112,    81,   119,     0,
       0,     0,    94,    95,    93,     0,     2,     5,     0,    34,
      16,    42,    44,    53,    52,    45,    46,    69,    13,     0,
      14,    48,     0,     0,     7,     8,   110,     9,    10,    36,
       0,    40,     0,    38,    37,     0,    66,     0,     0,    72,
       0,     0,     0,     0,    51,     0,     0,    80,    82,     0,
       0,    11,    12,    50,     1,     4,    32,    30,    28,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,    41,    39,     0,     0,     0,    68,    60,    62,    63,
       0,     0,    58,    84,     0,   106,   104,    68,     0,     0,
      68,    70,    71,    74,    35,    47,     0,    79,     0,    68,
     118,     0,   111,   111,     0,     0,    25,    24,    23,    22,
      18,    17,    21,    20,    19,    43,     0,    54,     0,     0,
      56,     0,    68,    96,     0,   102,    83,     0,     0,   109,
     101,     0,     0,     0,     0,    67,    73,    68,    77,     0,
       0,   120,     0,     0,    29,    27,    68,    55,    64,    57,
       0,    88,     0,    98,   107,   105,   110,   106,     0,     0,
     100,   111,    33,    31,     0,    59,    86,   103,   108,   114,
     115,    75,    61,     0,    65,     0,   110,     0,    85,    87,
     116,   113,    89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    56,   125,   124,   123,   122,    29,
      30,    31,    32,    33,    34,    35,   142,    97,    98,    99,
      57,    36,    37,    58,    59,    38,    62,    63,    68,    39,
     144,   199,   195,   202,    40,   186,    41,   145,    42,   105,
      43,    65,   151,   146,    44,   148,   188,   149,    45,   107,
     162,    46,    66,   177,    47,   196,    48,    69,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -173
static const yytype_int16 yypact[] =
{
     183,  -173,  -173,  -173,  -173,   266,     8,     8,   266,    27,
     231,  -173,   -11,    25,  -173,  -173,  -173,    32,     5,     6,
       9,    36,  -173,  -173,  -173,    42,   183,  -173,   368,  -173,
    -173,  -173,    71,  -173,  -173,   -20,  -173,  -173,  -173,    16,
    -173,  -173,    22,   183,  -173,  -173,  -173,  -173,  -173,  -173,
      10,   -12,   -20,   -12,  -173,   266,   323,    29,    31,    30,
     428,    37,   183,    34,  -173,    35,    38,  -173,  -173,    39,
     266,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
     266,   266,   266,   266,   266,   266,   266,   266,   266,  -173,
     266,  -173,  -173,    72,    75,   266,   266,  -173,  -173,  -173,
      85,   266,  -173,    88,   266,  -173,    57,   266,    69,   309,
     266,  -173,  -173,    70,  -173,    83,   135,  -173,   266,   266,
    -173,   388,  -173,  -173,   266,   266,    92,    92,    92,    92,
       1,     1,  -173,  -173,  -173,   514,    84,  -173,   482,    87,
    -173,   498,   266,  -173,    89,    86,  -173,   446,   183,  -173,
    -173,   183,    90,    83,   266,  -173,  -173,   266,  -173,   464,
      95,  -173,   266,   266,   539,   539,   266,  -173,  -173,  -173,
      98,  -173,    88,  -173,  -173,  -173,  -173,  -173,   346,    99,
    -173,  -173,   527,   551,   100,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   266,  -173,   101,  -173,   408,  -173,  -173,
    -173,  -173,  -173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,    60,   -25,     0,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,    21,  -173,  -173,    28,  -173,  -173,  -173,  -173,
     -94,  -173,  -173,    18,  -173,   -63,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,    -4,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   -39,  -173,  -173,  -173,   -42,  -173,  -172,
    -120,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -118
static const yytype_int16 yytable[] =
{
      28,    75,   139,   163,   189,    49,    61,   100,    54,   101,
      60,   102,     2,   152,    93,    94,   155,    95,   106,    96,
      86,    87,    88,   -78,   200,   160,    28,    51,    53,    64,
       1,     2,     3,     4,    52,    52,    67,  -117,    71,    50,
      73,    72,    74,    28,     5,    13,   108,   103,   170,     6,
       7,     8,    17,   104,    21,   109,     9,   111,    10,   112,
      55,   193,    28,   179,    13,   113,   118,   115,   117,   119,
     121,   120,   184,    21,    22,    23,   136,    24,    90,   137,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   140,
     135,    75,   143,    91,    92,   138,   150,    93,    94,   153,
      95,   141,    96,    55,   147,  -118,  -118,  -118,  -118,    84,
      85,    86,    87,    88,   157,   166,    28,   168,   159,   171,
     176,   172,   116,   174,   164,   165,   175,   181,   185,   192,
     194,   156,   198,   187,    12,   190,     0,     0,     1,     2,
       3,     4,     0,     0,     0,     0,     0,     0,    28,     0,
       0,    28,     5,     0,   178,     0,     0,     6,     7,     8,
       0,     0,   182,   183,     9,     0,    10,    11,    12,   158,
       0,     0,    13,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    24,     1,     2,     3,     4,
       0,     0,     0,   197,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     6,     7,     8,     0,     0,
       0,     0,     9,     0,    10,    11,    12,     0,     0,     0,
      13,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,    24,     1,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     6,     7,     8,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,    13,     1,
       2,     3,     4,    17,     0,     0,     0,    21,    22,    23,
       0,    24,     0,     5,     0,     0,     0,     0,     6,     7,
       8,     0,     0,     0,     0,     9,     0,    10,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    22,    23,     0,    24,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    76,    77,    78,    79,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   154,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,    78,    79,   110,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
     191,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      89,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
     161,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
     201,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,    76,    77,    78,    79,   114,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,    76,    77,    78,    79,   173,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
      76,    77,    78,    79,   180,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,    76,    77,    78,    79,
     167,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,    76,    77,    78,    79,   169,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    77,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,  -118,
    -118,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88
};

static const yytype_int16 yycheck[] =
{
       0,    26,    96,   123,   176,     5,    10,    27,     8,    29,
      10,    31,     4,   107,    26,    27,   110,    29,    43,    31,
      19,    20,    21,    34,   196,   119,    26,     6,     7,     4,
       3,     4,     5,     6,     6,     7,     4,    32,    32,    31,
       4,    32,     0,    43,    17,    37,    50,    31,   142,    22,
      23,    24,    42,    31,    46,    55,    29,    28,    31,    28,
      33,   181,    62,   157,    37,    35,    31,    30,    34,    31,
      70,    32,   166,    46,    47,    48,     4,    50,     7,     4,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     4,
      90,   116,     4,    22,    23,    95,    39,    26,    27,    30,
      29,   101,    31,    33,   104,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    31,    31,   116,    30,   118,    30,
      30,    35,    62,   148,   124,   125,   151,    32,    30,    30,
      30,   113,   195,   172,    33,   177,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,
      -1,   151,    17,    -1,   154,    -1,    -1,    22,    23,    24,
      -1,    -1,   162,   163,    29,    -1,    31,    32,    33,    34,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,     3,     4,     5,     6,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    -1,    31,    32,    33,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,     3,
       4,     5,     6,    42,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    10,    11,    35,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      34,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      32,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      32,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      32,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,     8,     9,    10,    11,    30,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    30,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
       8,     9,    10,    11,    30,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,     8,     9,    10,    11,
      28,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,     8,     9,    10,    11,    28,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    17,    22,    23,    24,    29,
      31,    32,    33,    37,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    52,    53,    54,    55,    60,
      61,    62,    63,    64,    65,    66,    72,    73,    76,    80,
      85,    87,    89,    91,    95,    99,   102,   105,   107,    55,
      31,    63,    66,    63,    55,    33,    55,    71,    74,    75,
      55,    85,    77,    78,     4,    92,   103,     4,    79,   108,
     109,    32,    32,     4,     0,    54,     8,     9,    10,    11,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    32,
       7,    22,    23,    26,    27,    29,    31,    68,    69,    70,
      27,    29,    31,    31,    31,    90,    54,   100,    85,    55,
      35,    28,    28,    35,    30,    30,    53,    34,    31,    31,
      32,    55,    59,    58,    57,    56,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,     4,     4,    55,    71,
       4,    55,    67,     4,    81,    88,    94,    55,    96,    98,
      39,    93,    71,    30,    36,    71,    74,    31,    34,    55,
      71,    32,   101,   101,    55,    55,    31,    28,    30,    28,
      71,    30,    35,    30,    54,    54,    30,   104,    55,    71,
      30,    32,    55,    55,    71,    30,    86,    94,    97,   100,
      98,    34,    30,   101,    30,    83,   106,    55,    76,    82,
     100,    32,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 118 "parser.y"
    {}
    break;

  case 3:
#line 119 "parser.y"
    {;}
    break;

  case 4:
#line 122 "parser.y"
    {
        resettemp();
        (yyval.statement_struct) = malloc(sizeof(struct stmt_t));
        int brk_statemenets = 0, brk_stmt = 0;
        int cont_statements = 0, cont_stmt = 0;
        int ret_statements = 0, ret_stmt = 0;

        if ((yyvsp[(1) - (2)].statement_struct)) {
          brk_statemenets = (yyvsp[(1) - (2)].statement_struct)->breakList;
          cont_statements = (yyvsp[(1) - (2)].statement_struct)->contList;
          ret_statements = (yyvsp[(1) - (2)].statement_struct)->retList;
        }

        if ((yyvsp[(2) - (2)].statement_struct)) {
          brk_stmt = (yyvsp[(2) - (2)].statement_struct)->breakList;
          cont_stmt = (yyvsp[(2) - (2)].statement_struct)->contList;
          ret_stmt = (yyvsp[(2) - (2)].statement_struct)->retList;
        }

        (yyval.statement_struct)->breakList = mergelist(brk_statemenets, brk_stmt);
        (yyval.statement_struct)->contList = mergelist(cont_statements , cont_stmt);
        (yyval.statement_struct)->retList = mergelist(ret_statements,ret_stmt);
  }
    break;

  case 5:
#line 145 "parser.y"
    { resettemp();   (yyval.statement_struct) = (yyvsp[(1) - (1)].statement_struct); }
    break;

  case 6:
#line 147 "parser.y"
    {  
          (yyval.statement_struct) = make_stmt((yyval.statement_struct));
          if (boolflag !=1) (yyvsp[(1) - (2)].ex) = manage_bool_expr((yyvsp[(1) - (2)].ex),symtable,lists,scope,yylineno);
          boolflag = 0;
        }
    break;

  case 7:
#line 152 "parser.y"
    { (yyval.statement_struct) = (yyvsp[(1) - (1)].statement_struct); }
    break;

  case 8:
#line 153 "parser.y"
    { (yyval.statement_struct) = NULL; }
    break;

  case 9:
#line 154 "parser.y"
    { (yyval.statement_struct) = NULL; }
    break;

  case 10:
#line 155 "parser.y"
    { (yyval.statement_struct) = (yyvsp[(1) - (1)].statement_struct); }
    break;

  case 11:
#line 157 "parser.y"
    { 
            manage_break(print_errors);
            (yyval.statement_struct) = make_stmt((yyval.statement_struct));
            (yyval.statement_struct)->breakList = newlist(nextquadlabel()); 
            emit(jump,NULL,NULL,NULL,0,yylineno);   
            }
    break;

  case 12:
#line 164 "parser.y"
    {
              manage_continue(print_errors);
              (yyval.statement_struct) = make_stmt((yyval.statement_struct));
              (yyval.statement_struct)->contList = newlist(nextquadlabel()); 
              emit(jump,NULL,NULL,NULL,0,yylineno);
            }
    break;

  case 13:
#line 170 "parser.y"
    { (yyval.statement_struct) = (yyvsp[(1) - (1)].statement_struct);}
    break;

  case 14:
#line 171 "parser.y"
    { (yyval.statement_struct) = NULL; }
    break;

  case 15:
#line 172 "parser.y"
    { (yyval.statement_struct) = NULL; }
    break;

  case 16:
#line 175 "parser.y"
    {(yyval.ex) = (yyvsp[(1) - (1)].ex);}
    break;

  case 17:
#line 176 "parser.y"
    {
      // diafaneia 5 dialeksh 3 
      check_expr((yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),add);
    }
    break;

  case 18:
#line 181 "parser.y"
    {
      check_expr((yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),sub);
    }
    break;

  case 19:
#line 185 "parser.y"
    {
      check_expr((yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),mul);
    }
    break;

  case 20:
#line 189 "parser.y"
    {
      check_expr((yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),divide);
    }
    break;

  case 21:
#line 193 "parser.y"
    {
      check_expr((yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),mod);
    }
    break;

  case 22:
#line 197 "parser.y"
    {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_greater,NULL,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    break;

  case 23:
#line 204 "parser.y"
    {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_greatereq,NULL,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    break;

  case 24:
#line 211 "parser.y"
    {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_less,NULL,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    break;

  case 25:
#line 218 "parser.y"
    {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_lesseq,NULL,(yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    break;

  case 26:
#line 225 "parser.y"
    { (yyvsp[(1) - (2)].ex) = manage_bool_expr((yyvsp[(1) - (2)].ex),symtable,lists,scope,yylineno); }
    break;

  case 27:
#line 225 "parser.y"
    {
      (yyvsp[(4) - (4)].ex) = manage_bool_expr((yyvsp[(4) - (4)].ex),symtable,lists,scope,yylineno);
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_eq,NULL,(yyvsp[(1) - (4)].ex),(yyvsp[(4) - (4)].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    break;

  case 28:
#line 233 "parser.y"
    { (yyvsp[(1) - (2)].ex) = manage_bool_expr((yyvsp[(1) - (2)].ex),symtable,lists,scope,yylineno); }
    break;

  case 29:
#line 233 "parser.y"
    {
      (yyvsp[(4) - (4)].ex) = manage_bool_expr((yyvsp[(4) - (4)].ex),symtable,lists,scope,yylineno);
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_noteq,NULL,(yyvsp[(1) - (4)].ex),(yyvsp[(4) - (4)].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    break;

  case 30:
#line 241 "parser.y"
    { (yyvsp[(1) - (2)].ex) = do_bool((yyvsp[(1) - (2)].ex),yylineno); }
    break;

  case 31:
#line 241 "parser.y"
    {
      (yyval.ex) = create_expr(boolexpr_e, NULL , NULL, 0.0f, NULL, '\0');
      (yyvsp[(5) - (5)].ex) = do_bool((yyvsp[(5) - (5)].ex),yylineno);
      patchlist((yyvsp[(1) - (5)].ex)->trueList,(yyvsp[(4) - (5)].int_val));
      (yyval.ex)->trueList = (yyvsp[(5) - (5)].ex)->trueList;
      (yyval.ex)->falseList = mergelist((yyvsp[(1) - (5)].ex)->falseList,(yyvsp[(5) - (5)].ex)->falseList);
    }
    break;

  case 32:
#line 248 "parser.y"
    { (yyvsp[(1) - (2)].ex) = do_bool((yyvsp[(1) - (2)].ex),yylineno); }
    break;

  case 33:
#line 248 "parser.y"
    {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0.0f, NULL, '\0');
      (yyvsp[(5) - (5)].ex) = do_bool((yyvsp[(5) - (5)].ex),yylineno);
      patchlist((yyvsp[(1) - (5)].ex)->falseList,(yyvsp[(4) - (5)].int_val));
      (yyval.ex)->trueList = mergelist((yyvsp[(1) - (5)].ex)->trueList,(yyvsp[(5) - (5)].ex)->trueList);
      (yyval.ex)->falseList = (yyvsp[(5) - (5)].ex)->falseList;
    }
    break;

  case 34:
#line 255 "parser.y"
    {(yyval.ex)=(yyvsp[(1) - (1)].ex);}
    break;

  case 35:
#line 258 "parser.y"
    {(yyval.ex) = (yyvsp[(2) - (3)].ex);}
    break;

  case 36:
#line 259 "parser.y"
    { (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[(2) - (2)].ex),NULL,uminus); }
    break;

  case 37:
#line 260 "parser.y"
    { (yyvsp[(2) - (2)].ex) = do_bool((yyvsp[(2) - (2)].ex),yylineno); 
            (yyval.ex) = (yyvsp[(2) - (2)].ex);
            int tmp = (yyval.ex)->trueList;
            (yyval.ex)->trueList = (yyvsp[(2) - (2)].ex)->falseList;
            (yyval.ex)->falseList = tmp;
          }
    break;

  case 38:
#line 266 "parser.y"
    { 
  manage_increment(symtable, lists, (yyvsp[(2) - (2)].ex)->sym->value.varVal->name, print_errors);
  check_arith((yyvsp[(2) - (2)].ex), "++lvalue");
  if ((yyvsp[(2) - (2)].ex)->type == tableitem_e) {
    (yyval.ex) = emit_iftableitem((yyvsp[(2) - (2)].ex), symtable, lists, scope, yylineno);
    emit(add, (yyval.ex), newexpr_constnum(1), (yyval.ex), 0, yylineno);
    emit(tablesetelem, (yyvsp[(2) - (2)].ex), (yyvsp[(2) - (2)].ex)->index, (yyval.ex), 0, yylineno);
  } else {
    emit(add, (yyvsp[(2) - (2)].ex), newexpr_constnum(1), (yyvsp[(2) - (2)].ex), 0, yylineno);
    (yyval.ex) = create_expr(arithexpr_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[(2) - (2)].ex), 0.0f, NULL, '\0');
    emit(assign, (yyval.ex), (yyvsp[(2) - (2)].ex),NULL, 0, yylineno);
  }
}
    break;

  case 39:
#line 279 "parser.y"
    {
  
  manage_increment(symtable, lists, (yyvsp[(1) - (2)].ex)->sym->value.varVal->name, print_errors);
  check_arith((yyvsp[(1) - (2)].ex), "lvalue++");
  (yyval.ex) = create_expr(var_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[(1) - (2)].ex), 0.0f, NULL, '\0');
  if ((yyvsp[(1) - (2)].ex)->type == tableitem_e) {
    expr *val = emit_iftableitem((yyvsp[(1) - (2)].ex), symtable, lists, scope, yylineno);
    emit(assign, val, (yyval.ex), NULL, 0, yylineno);
    emit(add, val, newexpr_constnum(1), val, 0, yylineno);
    emit(tablesetelem, (yyvsp[(1) - (2)].ex), (yyvsp[(1) - (2)].ex)->index, val, 0, yylineno);
  } else {
    emit(assign, (yyval.ex), (yyvsp[(1) - (2)].ex), NULL, 0, yylineno);
    emit(add, (yyvsp[(1) - (2)].ex), newexpr_constnum(1), (yyvsp[(1) - (2)].ex), 0, yylineno);
  }
  
}
    break;

  case 40:
#line 295 "parser.y"
    {
  manage_decrement(symtable, lists, (yyvsp[(2) - (2)].ex)->sym->value.varVal->name, print_errors);
  check_arith((yyvsp[(2) - (2)].ex), "--lvalue");
  if ((yyvsp[(2) - (2)].ex)->type == tableitem_e) {
    (yyval.ex) = emit_iftableitem((yyvsp[(2) - (2)].ex), symtable, lists, scope, yylineno);
    emit(sub, (yyval.ex),(yyval.ex), newexpr_constnum(1),  0, yylineno);
    emit(tablesetelem, (yyvsp[(2) - (2)].ex), (yyvsp[(2) - (2)].ex)->index, (yyval.ex), 0, yylineno);
  } else {
    emit(sub, (yyvsp[(2) - (2)].ex),(yyvsp[(2) - (2)].ex), newexpr_constnum(1), 0, yylineno);
    (yyval.ex) = create_expr(arithexpr_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[(2) - (2)].ex), 0.0f, NULL, '\0');
    emit(assign, (yyval.ex), (yyvsp[(2) - (2)].ex),NULL, 0, yylineno);
  }

  // if ($2->type == tableitem_e) {
  //   $$ = emit_iftableitem($2, symtable, lists, scope, yylineno);
  //   emit(add, $$, newexpr_constnum(1), $$, 0, yylineno);
  //   emit(tablesetelem, $2, $2->index, $$, 0, yylineno);
  // } else {
  //   emit(sub, $2, newexpr_constnum(1), $2, 0, yylineno);
  //   $$ = create_expr(arithexpr_e, newtemp(symtable, lists, scope, yylineno), $2, 0.0f, NULL, '\0');
  //   emit(assign, $$, $2,NULL, 0, yylineno);
  // }
}
    break;

  case 41:
#line 318 "parser.y"
    {

  manage_decrement(symtable, lists, (yyvsp[(1) - (2)].ex)->sym->value.varVal->name, print_errors);
  check_arith((yyvsp[(1) - (2)].ex), "lvalue--");
  (yyval.ex) = create_expr(var_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[(1) - (2)].ex), 0.0f, NULL, '\0');
  if ((yyvsp[(1) - (2)].ex)->type == tableitem_e) {
    expr *val = emit_iftableitem((yyvsp[(1) - (2)].ex), symtable, lists, scope, yylineno);
    emit(assign, val, (yyval.ex), NULL, 0, yylineno);
    emit(sub, val,val, newexpr_constnum(1), 0, yylineno);
    emit(tablesetelem, (yyvsp[(1) - (2)].ex), (yyvsp[(1) - (2)].ex)->index, val, 0, yylineno);
  } else {
    emit(assign, (yyval.ex), (yyvsp[(1) - (2)].ex), NULL, 0, yylineno);
    emit(sub, (yyvsp[(1) - (2)].ex),(yyvsp[(1) - (2)].ex), newexpr_constnum(1), 0, yylineno);
  }
  // $$ = create_expr(var_e, newtemp(symtable, lists, scope, yylineno), $1, 0.0f, NULL, '\0');
  // if ($1->type == tableitem_e) {
  //   expr *val = emit_iftableitem($1, symtable, lists, scope, yylineno);
  //   emit(assign, val, $$, NULL, 0, yylineno);
  //   emit(sub, val, newexpr_constnum(1), val, 0, yylineno);
  //   emit(tablesetelem, $1, $1->index, val, 0, yylineno);
  // } else {
  //   emit(assign, $1, $$,NULL, 0, yylineno);
  //   emit(sub, $1, newexpr_constnum(1), $1, 0, yylineno);
  // }
}
    break;

  case 42:
#line 343 "parser.y"
    { (yyval.ex) = (yyvsp[(1) - (1)].ex);}
    break;

  case 43:
#line 347 "parser.y"
    {
  (yyval.ex) = (yyvsp[(3) - (3)].ex);
  if((yyvsp[(1) - (3)].ex)->type == tableitem_e){
      emit(tablesetelem,(yyvsp[(1) - (3)].ex),(yyvsp[(1) - (3)].ex)->index,(yyvsp[(3) - (3)].ex),0,yylineno);
      (yyval.ex) = emit_iftableitem((yyvsp[(1) - (3)].ex),symtable,lists,scope,yylineno);
      (yyval.ex)->type = assignexpr_e;
  }else{
    expr* new = manage_bool_expr((yyvsp[(3) - (3)].ex),symtable,lists,scope,yylineno);
    emit(assign, (yyvsp[(1) - (3)].ex), new, NULL, 0, yylineno);
    expr* tmp = NULL ;
    tmp = lvalue_expr(newtemp(symtable, lists, scope, yylineno));
    emit(assign, tmp,(yyvsp[(1) - (3)].ex), NULL, 0, yylineno);
    boolflag = 1;
  }
  is_local_kw = 0;
  if (from_func_call > 0) from_func_call--;
}
    break;

  case 44:
#line 366 "parser.y"
    { 
  (yyval.ex) = emit_iftableitem((yyvsp[(1) - (1)].ex), symtable, lists, scope, yylineno);
  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
    break;

  case 45:
#line 371 "parser.y"
    { 
  printf("curr scope space :: %d\n",currscopespace());
  entry = lookup(symtable, lists, (yyvsp[(1) - (1)].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[(1) - (1)].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
  manage_call(symtable, lists, entry, (yyvsp[(1) - (1)].ex)->sym->value.varVal->name, print_errors, yylineno);
}
    break;

  case 46:
#line 376 "parser.y"
    {;}
    break;

  case 47:
#line 377 "parser.y"
    {(yyval.ex) = create_expr(programfunc_e,(yyvsp[(2) - (3)].symbol),0,0,"",'\0');}
    break;

  case 48:
#line 378 "parser.y"
    { (yyval.ex) = (yyvsp[(1) - (1)].ex);}
    break;

  case 49:
#line 382 "parser.y"
    {
  entry = manage_id(symtable, lists, (yyvsp[(1) - (1)].str_val), yylineno, scope, (peek(func_scopes) != NULL) ? peek(func_scopes)->x : -1, print_errors);
  (yyval.ex) = lvalue_expr(entry);
}
    break;

  case 50:
#line 387 "parser.y"
    { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 
  is_local_kw = 1;

  entry = manage_local_id(symtable, lists, (yyvsp[(2) - (2)].str_val), print_errors, yylineno);
  (yyval.ex) = lvalue_expr(entry);
}
    break;

  case 51:
#line 394 "parser.y"
    { 
  entry = manage_double_colon_id(symtable, lists, (yyvsp[(2) - (2)].str_val), print_errors);
  (yyval.ex) = lvalue_expr(entry);
}
    break;

  case 52:
#line 398 "parser.y"
    {(yyval.ex)=(yyvsp[(1) - (1)].ex);}
    break;

  case 53:
#line 399 "parser.y"
    {(yyval.ex) = (yyvsp[(1) - (1)].ex);}
    break;

  case 54:
#line 402 "parser.y"
    { (yyval.ex) = member_item((yyvsp[(1) - (3)].ex),(yyvsp[(3) - (3)].str_val),symtable,lists,scope,yylineno); }
    break;

  case 55:
#line 403 "parser.y"
    {
  (yyvsp[(1) - (4)].ex) = emit_iftableitem((yyvsp[(1) - (4)].ex), symtable, lists, scope, yylineno);
  (yyval.ex) = create_expr(tableitem_e, (yyvsp[(1) - (4)].ex)->sym, (yyvsp[(3) - (4)].ex), 0.0f, NULL, '\0');
}
    break;

  case 56:
#line 408 "parser.y"
    {from_func_call++;}
    break;

  case 57:
#line 409 "parser.y"
    {;}
    break;

  case 58:
#line 412 "parser.y"
    {from_elist = 1; }
    break;

  case 59:
#line 412 "parser.y"
    {
  (yyval.ex) = make_call((yyvsp[(1) - (5)].ex), reverse_elist((yyvsp[(4) - (5)].ex)),yylineno,symtable,lists,scope);
  
}
    break;

  case 60:
#line 416 "parser.y"
    {
    (yyvsp[(1) - (2)].ex) = emit_iftableitem((yyvsp[(1) - (2)].ex),symtable,lists,scope,yylineno);
    if ((yyvsp[(2) - (2)].elist_call)->method) {
      expr* last = get_last((yyvsp[(2) - (2)].elist_call)->elist);
    
      if(last == NULL){
        (yyvsp[(2) - (2)].elist_call)->elist = (yyvsp[(1) - (2)].ex);
      }else{
        last->next = (yyvsp[(1) - (2)].ex);
      }
      (yyvsp[(1) - (2)].ex) = emit_iftableitem(member_item((yyval.ex), (yyvsp[(2) - (2)].elist_call)->name,symtable,lists,scope,yylineno),symtable,lists,scope,yylineno);
    }
    (yyval.ex) = make_call((yyvsp[(1) - (2)].ex), reverse_elist((yyvsp[(2) - (2)].elist_call)->elist) ,yylineno, symtable, lists, scope);
  }
    break;

  case 61:
#line 430 "parser.y"
    {
  expr* func = create_expr(programfunc_e, (yyvsp[(2) - (6)].symbol), NULL, 0.0f, NULL, '\0'); 
  (yyval.ex) = make_call(func, reverse_elist((yyvsp[(5) - (6)].ex)), yylineno, symtable, lists, scope);
}
    break;

  case 62:
#line 435 "parser.y"
    {(yyval.elist_call) = (yyvsp[(1) - (1)].elist_call);}
    break;

  case 63:
#line 436 "parser.y"
    {(yyval.elist_call) = (yyvsp[(1) - (1)].elist_call);}
    break;

  case 64:
#line 438 "parser.y"
    {
  (yyval.elist_call) = malloc(sizeof(struct call_t));
  (yyval.elist_call)->elist = (yyvsp[(2) - (3)].ex);
  (yyval.elist_call)->method = 0;
  (yyval.elist_call)->name = NULL;
}
    break;

  case 65:
#line 445 "parser.y"
    {
  (yyval.elist_call) = malloc(sizeof(struct call_t));
  (yyval.elist_call)->elist = (yyvsp[(4) - (5)].ex);
  (yyval.elist_call)->method = 1;
  (yyval.elist_call)->name = strdup((yyvsp[(2) - (5)].str_val));
}
    break;

  case 66:
#line 452 "parser.y"
    { (yyval.ex)->next = NULL; (yyval.ex) = manage_bool_expr((yyvsp[(1) - (1)].ex),symtable,lists,scope,yylineno); }
    break;

  case 67:
#line 453 "parser.y"
    { (yyvsp[(1) - (3)].ex)->next = (yyvsp[(3) - (3)].ex); (yyval.ex)=(yyvsp[(1) - (3)].ex); }
    break;

  case 68:
#line 454 "parser.y"
    { (yyval.ex) = NULL;}
    break;

  case 69:
#line 456 "parser.y"
    {;}
    break;

  case 70:
#line 458 "parser.y"
    {
  expr* t = create_expr(newtable_e, newtemp(symtable, lists, scope, yylineno), NULL, 0.0f, NULL, '\0');
  emit(tablecreate, t, NULL, NULL, 0, yylineno);
  expr *tmp = (yyvsp[(2) - (3)].ex);
  for (int i = 0; tmp; tmp = tmp->next) {
    
    emit(tablesetelem, t, newexpr_constnum(i++), tmp, 0, yylineno);
  }
  (yyval.ex) = t;
}
    break;

  case 71:
#line 468 "parser.y"
    {
        expr* t = create_expr(newtable_e,NULL,NULL,0.0f,"",'\0');
        t->sym = newtemp(symtable,lists,scope,yylineno);
        emit(tablecreate,t,NULL,NULL,0,yylineno);
        indexed_list_t *tmp = (yyvsp[(2) - (3)].indexedlist_node);
        while(tmp!=NULL){
          emit(tablesetelem,t,tmp->index,tmp->value,0,yylineno);
          tmp = tmp->next;
        }
        (yyval.ex) = t;
    }
    break;

  case 72:
#line 481 "parser.y"
    {(yyval.indexedlist_node) = (yyvsp[(1) - (1)].indexedlist_node); (yyval.indexedlist_node)->next = NULL;}
    break;

  case 73:
#line 482 "parser.y"
    {(yyvsp[(1) - (3)].indexedlist_node)->next = (yyvsp[(3) - (3)].indexedlist_node); (yyval.indexedlist_node)=(yyvsp[(1) - (3)].indexedlist_node);}
    break;

  case 74:
#line 483 "parser.y"
    {(yyval.indexedlist_node) = NULL;}
    break;

  case 75:
#line 486 "parser.y"
    {(yyval.indexedlist_node) = create_indexlist_node((yyvsp[(2) - (5)].ex),(yyvsp[(4) - (5)].ex)); (yyvsp[(4) - (5)].ex) = manage_bool_expr((yyvsp[(4) - (5)].ex),symtable,lists,scope,yylineno);}
    break;

  case 76:
#line 490 "parser.y"
    {scope++;  }
    break;

  case 77:
#line 490 "parser.y"
    { hide_scope(lists, scope--); (yyval.statement_struct) = (yyvsp[(3) - (4)].statement_struct); }
    break;

  case 78:
#line 491 "parser.y"
    {scope++;}
    break;

  case 79:
#line 491 "parser.y"
    {hide_scope(lists, scope--); (yyval.statement_struct) = NULL;}
    break;

  case 80:
#line 494 "parser.y"
    { (yyval.str_val) = (yyvsp[(1) - (1)].str_val);}
    break;

  case 81:
#line 495 "parser.y"
    {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          (yyval.str_val) = temp;
          }
    break;

  case 82:
#line 504 "parser.y"
    { // elegxoume ama uparxoyn ta entries sto hashtable kai einai active, an nai ektypwnoyme ta katallhla error messages
// alliws ta vazoume sto table
  
  (yyval.symbol) = manage_function(symtable, lists, (yyvsp[(2) - (2)].str_val), print_errors, yylineno);
  /* gia tin epomenh fash */
   (yyval.symbol)->iaddress = nextquadlabel(); 
   emit(jump, NULL, NULL, NULL, 0, yylineno); 
 // deixnei sto funcstart command tou quad poy antistoixei sthn sunarthsh poy orizetai
 // GOTO
  emit(funcstart, lvalue_expr((yyval.symbol)), NULL, NULL, 0, 0);
  push(stack, currscopeoffset());
  enterscopespace();
  resetformalargsoffset();
}
    break;

  case 83:
#line 519 "parser.y"
    { enterscopespace(); resetfunctionlocaloffset(); }
    break;

  case 84:
#line 520 "parser.y"
    { enterscopespace(); resetfunctionlocaloffset(); }
    break;

  case 85:
#line 522 "parser.y"
    { (yyval.int_val) = currscopeoffset(); if((yyvsp[(1) - (1)].statement_struct)) patchlist((yyvsp[(1) - (1)].statement_struct)->retList,nextquadlabel()); exitscopespace(); }
    break;

  case 86:
#line 524 "parser.y"
    { push(func_scopes, scope); push(loop_stack, in_loop); in_loop = 0; }
    break;

  case 87:
#line 526 "parser.y"
    { scopestack_t *temp = pop(loop_stack); pop(func_scopes); in_loop = temp->x; }
    break;

  case 88:
#line 528 "parser.y"
    { func_in_between++; }
    break;

  case 89:
#line 528 "parser.y"
    {
  exitscopespace();
  (yyval.symbol)->total_locals = (yyvsp[(7) - (8)].int_val);
  scopestack_t *temp = pop(stack);
  int offset = temp->x;
  restorecurrentscopeoffset(offset);
  (yyval.symbol) = (yyvsp[(1) - (8)].symbol);
  emit(funcend, lvalue_expr((yyvsp[(1) - (8)].symbol)), NULL, NULL, 0, 0);
  patchlabel((yyvsp[(1) - (8)].symbol)->iaddress, nextquadlabel());

  func_in_between--;
}
    break;

  case 90:
#line 541 "parser.y"
    {(yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[(1) - (1)].int_val), "vaggelis", '\0');}
    break;

  case 91:
#line 542 "parser.y"
    { (yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[(1) - (1)].real_val), "", '\0');}
    break;

  case 92:
#line 543 "parser.y"
    { (yyval.ex) = create_expr(conststring_e, NULL, NULL, 0, (yyvsp[(1) - (1)].str_val), '\0');}
    break;

  case 93:
#line 544 "parser.y"
    {(yyval.ex) = create_expr(nil_e, NULL, NULL, 0, "lempesis", '\0');}
    break;

  case 94:
#line 545 "parser.y"
    {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '1');}
    break;

  case 95:
#line 546 "parser.y"
    {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '0');}
    break;

  case 96:
#line 549 "parser.y"
    { 

  SymbolTableEntry *entry_l = NULL;

  manage_lib_function((yyvsp[(1) - (1)].str_val), print_errors);

  entry = lookup(symtable, lists, (yyvsp[(1) - (1)].str_val), GLOBALVAR, scope, SCOPE);
  entry_l = lookup(symtable, lists, (yyvsp[(1) - (1)].str_val), FORMAL, scope + 1, SCOPE);
  
  manage_id_list(symtable, lists, entry, entry_l, (yyvsp[(1) - (1)].str_val), print_errors, yylineno);
}
    break;

  case 97:
#line 561 "parser.y"
    {while_loop++; in_loop++; (yyval.int_val) = nextquadlabel();}
    break;

  case 98:
#line 564 "parser.y"
    { 
      (yyvsp[(2) - (3)].ex) = manage_bool_expr((yyvsp[(2) - (3)].ex),symtable,lists,scope,yylineno);
      emit(if_eq,NULL,(yyvsp[(2) - (3)].ex),create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),nextquadlabel()+2,yylineno);
      (yyval.int_val) = nextquadlabel();
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    break;

  case 99:
#line 571 "parser.y"
    { if_stmt++; }
    break;

  case 100:
#line 571 "parser.y"
    {
        (yyvsp[(4) - (5)].ex) = manage_bool_expr((yyvsp[(4) - (5)].ex),symtable,lists,scope,yylineno);
        emit (if_eq,NULL, (yyvsp[(4) - (5)].ex), create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),nextquadlabel() + 2, yylineno);
        // filippe peiraja thn emit an exw kanei malakia sorry <3
        (yyval.int_val) = nextquadlabel();
        emit(jump,NULL,NULL,NULL,0,yylineno);
      }
    break;

  case 101:
#line 579 "parser.y"
    { (yyval.int_val) = nextquadlabel(); emit(jump,NULL,NULL,NULL,0,yylineno);}
    break;

  case 102:
#line 581 "parser.y"
    {;}
    break;

  case 103:
#line 582 "parser.y"
    {;}
    break;

  case 104:
#line 585 "parser.y"
    { if_stmt--; patchlabel((yyvsp[(1) - (2)].int_val),nextquadlabel()); (yyval.statement_struct)=(yyvsp[(2) - (2)].statement_struct); }
    break;

  case 105:
#line 587 "parser.y"
    { 
        if_stmt--;
        (yyval.statement_struct) = make_stmt((yyval.statement_struct));
        patchlabel((yyvsp[(1) - (4)].int_val),(yyvsp[(3) - (4)].int_val)+1);
        patchlabel((yyvsp[(3) - (4)].int_val),nextquadlabel());
        fflush(stdout);
        
        int brk_statemenets = 0, cont_statements = 0;
        int brk_stmt = 0, cont_stmt = 0;
        int ret_statements = 0, ret_stmt = 0;


        if((yyvsp[(2) - (4)].statement_struct)){
          brk_statemenets = (yyvsp[(2) - (4)].statement_struct)->breakList;
          if((yyvsp[(4) - (4)].statement_struct)) cont_statements = (yyvsp[(4) - (4)].statement_struct)->contList;
          ret_statements = (yyvsp[(2) - (4)].statement_struct)->retList;
        }

        if((yyvsp[(4) - (4)].statement_struct)){
          brk_stmt = (yyvsp[(4) - (4)].statement_struct)->breakList;
          if((yyvsp[(2) - (4)].statement_struct)) cont_stmt = (yyvsp[(2) - (4)].statement_struct)->contList;
          ret_stmt = (yyvsp[(4) - (4)].statement_struct)->retList;
        }
  
        (yyval.statement_struct)->breakList = mergelist(brk_statemenets, brk_stmt);
        (yyval.statement_struct)->contList = mergelist(cont_statements , cont_stmt);
        (yyval.statement_struct)->retList = mergelist(ret_statements, ret_stmt);
      }
    break;

  case 106:
#line 616 "parser.y"
    { in_loop++; }
    break;

  case 107:
#line 618 "parser.y"
    { in_loop--; }
    break;

  case 108:
#line 620 "parser.y"
    { (yyval.statement_struct) = (yyvsp[(2) - (3)].statement_struct); }
    break;

  case 109:
#line 622 "parser.y"
    {
                                      in_loop--; while_loop--;
                                      emit(jump,NULL,NULL,NULL,(yyvsp[(1) - (3)].int_val),yylineno);
                                      patchlabel((yyvsp[(2) - (3)].int_val),nextquadlabel());
                                      if((yyvsp[(3) - (3)].statement_struct)) {patchlist((yyvsp[(3) - (3)].statement_struct)->breakList,nextquadlabel()); //$3->breaklist: index tou quad opou briskontai ta breaks, nextquadlabel(): quad label opou bazoume ta brakes na deixnoun 
                                            patchlist((yyvsp[(3) - (3)].statement_struct)->contList,(yyvsp[(1) - (3)].int_val));}
                                      }
    break;

  case 110:
#line 630 "parser.y"
    {(yyval.int_val) = nextquadlabel(); emit(jump,NULL,NULL,NULL,0,yylineno);}
    break;

  case 111:
#line 631 "parser.y"
    {(yyval.int_val) = nextquadlabel();}
    break;

  case 112:
#line 633 "parser.y"
    {for_loop++; in_loop++; }
    break;

  case 113:
#line 633 "parser.y"
    {
              (yyval.forprefix_struct) = malloc(sizeof(struct forstruct_t));
              (yyvsp[(7) - (8)].ex) = manage_bool_expr((yyvsp[(7) - (8)].ex),symtable,lists,scope,yylineno);
              (yyval.forprefix_struct)->test = (yyvsp[(6) - (8)].int_val);
              (yyval.forprefix_struct)->enter = nextquadlabel();
              emit(if_eq,NULL,(yyvsp[(7) - (8)].ex),create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),0,yylineno);
          // filippe o vaggelis peirakse kai auth thn emit <3
          }
    break;

  case 114:
#line 643 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); }
    break;

  case 115:
#line 645 "parser.y"
    { in_loop--; for_loop--;}
    break;

  case 116:
#line 645 "parser.y"
    {
  (yyval.statement_struct) = make_stmt((yyval.statement_struct));

  patchlabel((yyvsp[(1) - (7)].forprefix_struct)->enter,(yyvsp[(4) - (7)].int_val)+1);
  patchlabel((yyvsp[(2) - (7)].int_val),nextquadlabel());
  patchlabel((yyvsp[(4) - (7)].int_val),(yyvsp[(1) - (7)].forprefix_struct)->test);
  patchlabel((yyvsp[(7) - (7)].int_val),(yyvsp[(2) - (7)].int_val) +1);
  
  if ((yyvsp[(5) - (7)].statement_struct)) patchlist((yyvsp[(5) - (7)].statement_struct)->breakList,nextquadlabel());
  if ((yyvsp[(5) - (7)].statement_struct)) patchlist((yyvsp[(5) - (7)].statement_struct)->contList,(yyvsp[(2) - (7)].int_val)+1);
}
    break;

  case 117:
#line 657 "parser.y"
    { manage_return(print_errors); }
    break;

  case 118:
#line 657 "parser.y"
    { emit(ret,NULL,NULL,NULL,0,0);
                        (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                        (yyval.statement_struct)->retList = newlist(nextquadlabel());
                        emit(jump,NULL,NULL,NULL,0,yylineno);
                      }
    break;

  case 119:
#line 662 "parser.y"
    { manage_return(print_errors); }
    break;

  case 120:
#line 662 "parser.y"
    { emit(ret,NULL,(yyvsp[(3) - (4)].ex), NULL,0,0); is_return_kw = 1; 
                        (yyvsp[(3) - (4)].ex) = manage_bool_expr((yyvsp[(3) - (4)].ex),symtable,lists,scope,yylineno);
                        (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                        (yyval.statement_struct)->retList = newlist(nextquadlabel());
                        emit(jump,NULL,NULL,NULL,0,yylineno);
                      }
    break;


/* Line 1267 of yacc.c.  */
#line 2738 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 669 "parser.y"


void yyerror(const char *error_msg) {
  print_errors(yylval.str_val, yytext, "syntax");
  exit(0);
}

void print_errors(const char *error_msg, char *token, const char *error_type) {
  int count = 1;
  int temp = yylineno;

  printf("%p, %p\n", error_msg, token);
  fflush(stdout);

  fprintf(stderr, "%s:%d ",file_name + 1, yylineno);
  printf("\033[31merror:\033[0m %s\n", error_type);   

  while (temp) {temp /= 10; count++;}; 
  if (error_msg == NULL) {
    printf("  %d | ",yylineno);
  } else {
    printf("  %d | %s",yylineno, error_msg);
  }
  printf("\033[31m");
  printf(" %s", token);
  printf("\033[0m\n");
  printf("%*s|", count + 2, "");
  if (error_msg != NULL) {
    for (int i = 0; i < strlen(error_msg) + 2; i++) printf(" ");
    printf("\033[31m^\033[0m");
    if (strlen(token) > 1) {
      for (int i = 0; i < strlen(token) - 1; i++) printf("\033[31m~\033[0m");
    }
  }
  
  printf("\n%*s|\n", count + 2, "");
}

int main(int argc, char **argv) {

  FILE* fptr = NULL;

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  if (argc == 3) {
    fptr = fopen(argv[2], "wb+");
    if (fptr == NULL) {
      perror("error opening file");
      exit(-1);
    }
  }

  file_name = strrchr(argv[1], '/');
  funcs = create_func_stack();
  lists = create_scope_lists();
  symtable = create_table();
  stack = create_scope_stack();
  loop_stack = create_scope_stack();
  func_scopes = create_scope_stack();

  emit(jump,NULL,NULL,NULL,1,0);

  add_lib_func(symtable, lists);
  yyparse();
  
  print_scopes(lists, (fptr == NULL) ? stdout : fptr);

  fprintf((fptr == NULL) ? stdout : fptr, "\n\n\n");

  print_quads((fptr == NULL) ? stdout : fptr);

 generate_targetcode();
// printInstructions();  

  printf("NUMBER OF GLOBALS :: %d\n",global_vars_no );

  convert_to_binary();
  // write_to_file();
  free_table(symtable);

  return 0;
}

