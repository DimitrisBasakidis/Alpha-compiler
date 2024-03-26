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

#include "utilities/symbol_table.h"
#include "utilities/structs.h"

int yylex(void);
int yyerror(const char *error_msg);

int scope = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

SymTable *symtable;
scopeLists *lists;
size_t nfuncs = 0U;



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
#line 25 "parser.y"
{
  int int_val;
  char *str_val;
  float real_val;
  struct expr_t* expression;
}
/* Line 193 of yacc.c.  */
#line 227 "parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 240 "parser.c"

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

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
       0,     0,     3,     5,     8,    10,    13,    15,    17,    19,
      21,    24,    27,    29,    31,    33,    35,    39,    43,    47,
      51,    55,    59,    63,    67,    71,    75,    79,    83,    87,
      89,    92,    95,    99,   102,   105,   108,   111,   113,   117,
     119,   121,   123,   127,   129,   131,   134,   137,   139,   143,
     148,   152,   157,   162,   165,   172,   174,   176,   180,   186,
     188,   189,   194,   198,   202,   204,   205,   210,   216,   217,
     222,   223,   227,   229,   230,   233,   239,   244,   246,   248,
     250,   252,   254,   256,   258,   262,   268,   276,   282,   292,
     295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    53,    54,    -1,    54,    -1,
      55,    32,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    44,    32,    -1,    45,    32,    -1,    71,    -1,    76,
      -1,    32,    -1,    57,    -1,    55,    18,    55,    -1,    55,
      17,    55,    -1,    55,    20,    55,    -1,    55,    21,    55,
      -1,    55,    19,    55,    -1,    55,    16,    55,    -1,    55,
      15,    55,    -1,    55,    14,    55,    -1,    55,    13,    55,
      -1,    55,    11,    55,    -1,    55,    10,    55,    -1,    55,
       9,    55,    -1,    55,     8,    55,    -1,    56,    -1,    24,
      55,    -1,    17,    55,    -1,    31,    55,    30,    -1,    23,
      59,    -1,    59,    23,    -1,    22,    59,    -1,    59,    22,
      -1,    58,    -1,    59,     7,    55,    -1,    59,    -1,    61,
      -1,    67,    -1,    31,    76,    30,    -1,    77,    -1,     4,
      -1,    46,     4,    -1,    37,     4,    -1,    60,    -1,    59,
      27,     4,    -1,    59,    29,    55,    28,    -1,    61,    27,
       4,    -1,    61,    29,    55,    28,    -1,    61,    31,    65,
      30,    -1,    59,    62,    -1,    31,    76,    30,    31,    65,
      30,    -1,    63,    -1,    64,    -1,    31,    65,    30,    -1,
      26,     4,    31,    65,    30,    -1,    55,    -1,    -1,    55,
      35,    65,    66,    -1,    29,    65,    28,    -1,    29,    68,
      28,    -1,    70,    -1,    -1,    70,    35,    68,    69,    -1,
      33,    55,    36,    55,    34,    -1,    -1,    33,    72,    53,
      34,    -1,    -1,    33,    73,    34,    -1,     4,    -1,    -1,
      42,    74,    -1,    75,    31,    78,    30,    71,    -1,    75,
      31,    30,    71,    -1,     3,    -1,     6,    -1,     5,    -1,
      50,    -1,    47,    -1,    48,    -1,     4,    -1,     4,    35,
      78,    -1,    38,    31,    55,    30,    54,    -1,    38,    31,
      55,    30,    54,    39,    54,    -1,    40,    31,    55,    30,
      54,    -1,    41,    31,    65,    32,    55,    32,    65,    30,
      54,    -1,    43,    32,    -1,    43,    55,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    62,    63,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      95,    96,    97,    98,    99,   100,   101,   102,   106,   109,
     110,   111,   112,   113,   116,   123,   130,   136,   139,   140,
     141,   142,   145,   146,   147,   150,   151,   154,   157,   160,
     161,   161,   165,   166,   169,   170,   170,   174,   178,   178,
     179,   179,   182,   183,   192,   200,   201,   204,   205,   206,
     207,   208,   209,   212,   213,   216,   217,   220,   223,   226,
     227
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
  "$accept", "program", "statements", "stmt", "expr", "term", "assignexpr",
  "primary", "lvalue", "member", "call", "callsuffix", "normcall",
  "methodcall", "elist", "@1", "objectdef", "indexed", "@2", "indexedelem",
  "block", "@3", "@4", "fname", "func_id", "funcdef", "const", "idlist",
  "ifstmt", "whilestmt", "forstmt", "returnstmt", 0
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
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    64,    65,
      66,    65,    67,    67,    68,    69,    68,    70,    72,    71,
      73,    71,    74,    74,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    81,    82,
      82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     3,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     4,     2,     6,     1,     1,     3,     5,     1,
       0,     4,     3,     3,     1,     0,     4,     5,     0,     4,
       0,     3,     1,     0,     2,     5,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     7,     5,     9,     2,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    77,    44,    79,    78,     0,     0,     0,     0,     0,
       0,    14,    68,     0,     0,     0,     0,    73,     0,     0,
       0,     0,    81,    82,    80,     0,     2,     4,     0,    29,
      15,    37,    39,    47,    40,    41,    12,     0,    13,    43,
       6,     7,     8,     9,    31,     0,    35,     0,    33,    30,
       0,    59,     0,     0,    64,     0,     0,     0,     0,    46,
       0,     0,     0,    72,    74,    89,     0,    10,    11,    45,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,    36,    34,     0,
       0,     0,     0,    53,    55,    56,     0,     0,     0,     0,
       0,     0,     0,    62,    63,     0,    32,    42,     0,    71,
       0,     0,     0,    90,    28,    27,    26,    25,    24,    23,
      22,    21,    17,    16,    20,    18,    19,    38,     0,    48,
       0,     0,    50,     0,     0,    83,     0,     0,     0,     0,
      60,    65,     0,    69,     0,     0,     0,     0,    49,    57,
      51,    52,     0,    76,     0,     0,    61,    66,     0,    85,
      87,     0,     0,    84,    75,    67,    54,     0,     0,    58,
      86,     0,     0,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    93,    94,    95,    52,   156,    35,    53,   157,    54,
      36,    57,    58,    64,    37,    38,    39,   137,    40,    41,
      42,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
     175,  -136,  -136,  -136,  -136,   293,     2,     2,   293,   223,
      12,  -136,   -25,     8,   -17,    -9,     0,    40,   258,     6,
      15,    60,  -136,  -136,  -136,    66,   175,  -136,   381,  -136,
    -136,  -136,     1,  -136,    34,  -136,  -136,    49,  -136,  -136,
    -136,  -136,  -136,  -136,    32,    41,    86,    34,    86,  -136,
     293,   336,    54,    57,    53,   441,    59,   175,    62,  -136,
     293,   293,   293,  -136,  -136,  -136,   401,  -136,  -136,  -136,
    -136,  -136,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,  -136,   293,  -136,  -136,    87,
      98,   293,   293,  -136,  -136,  -136,   110,   293,   293,     7,
      64,    90,   293,  -136,  -136,    85,  -136,    88,   127,  -136,
     459,   477,    91,  -136,   540,   552,   564,   564,   169,   169,
     169,   169,    32,    32,  -136,  -136,  -136,   527,    93,  -136,
     495,    92,  -136,   511,    95,    94,   102,    97,    88,   293,
    -136,  -136,   293,  -136,   175,   175,   293,   293,  -136,  -136,
    -136,  -136,   124,  -136,   102,   359,  -136,  -136,   106,    99,
    -136,   421,   109,  -136,  -136,  -136,  -136,   175,   293,  -136,
    -136,   115,   175,  -136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,    83,   -24,    -5,  -136,  -136,  -136,    14,  -136,
      19,  -136,  -136,  -136,   -52,  -136,  -136,    42,  -136,  -136,
    -135,  -136,  -136,  -136,  -136,    -3,  -136,    -6,  -136,  -136,
    -136,  -136
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -71
static const yytype_int16 yytable[] =
{
      44,   153,    71,    49,    51,    55,     2,    56,    86,   -70,
     112,   135,    59,    66,    60,     1,     2,     3,     4,   164,
      46,    48,    61,    87,    88,    47,    47,    89,    90,     5,
      91,    62,    92,    45,     6,     7,     8,   136,    67,    13,
     131,     9,   100,    10,    63,   101,   134,    68,    21,    13,
     140,    82,    83,    84,    17,   110,   111,    51,    21,    22,
      23,    96,    24,    97,    69,    98,    70,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      99,   127,   103,    17,    71,   104,   130,    51,   105,   107,
     158,   128,   133,    51,   138,   162,   109,    51,    72,    73,
      74,    75,   129,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    89,    90,   132,    91,   171,    92,    50,   142,
     159,   160,   149,   146,   147,   151,   139,   154,   135,   152,
       1,     2,     3,     4,   155,    12,   166,    51,   167,   169,
     108,   161,    51,   170,     5,   172,   163,   141,   173,     6,
       7,     8,     0,     0,     0,     0,     9,     0,    10,    11,
      12,   143,     0,    51,    13,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    24,     1,     2,
       3,     4,   -71,   -71,   -71,   -71,    80,    81,    82,    83,
      84,     0,     5,     0,     0,     0,     0,     6,     7,     8,
       0,     0,     0,     0,     9,     0,    10,    11,    12,     0,
       0,     0,    13,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    24,     1,     2,     3,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     6,     7,     8,     0,     0,
       0,     0,     9,     0,    10,     0,    50,     0,     0,     0,
      13,     1,     2,     3,     4,     0,     0,     0,     0,    21,
      22,    23,     0,    24,     0,     5,     0,     0,     0,     0,
       6,     7,     8,     0,     0,     0,     0,     9,     0,    10,
      65,     0,     0,     0,     0,    13,     1,     2,     3,     4,
       0,     0,     0,     0,    21,    22,    23,     0,    24,     0,
       5,     0,     0,     0,     0,     6,     7,     8,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,    23,     0,    24,    72,    73,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,    74,
      75,   102,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,   165,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    85,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,   113,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,   168,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,    72,    73,    74,
      75,   106,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,    72,    73,    74,    75,   144,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,    72,    73,    74,    75,   145,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,    72,
      73,    74,    75,   148,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,    72,    73,    74,    75,   150,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    73,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    74,    75,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   -71,   -71,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
       5,   136,    26,     8,     9,    10,     4,    10,     7,    34,
      62,     4,     4,    18,    31,     3,     4,     5,     6,   154,
       6,     7,    31,    22,    23,     6,     7,    26,    27,    17,
      29,    31,    31,    31,    22,    23,    24,    30,    32,    37,
      92,    29,    45,    31,     4,    50,    98,    32,    46,    37,
     102,    19,    20,    21,    42,    60,    61,    62,    46,    47,
      48,    27,    50,    29,     4,    31,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      31,    86,    28,    42,   108,    28,    91,    92,    35,    30,
     142,     4,    97,    98,    30,   147,    34,   102,     8,     9,
      10,    11,     4,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    26,    27,     4,    29,   168,    31,    33,    31,
     144,   145,    30,    32,    31,    30,    36,    30,     4,    35,
       3,     4,     5,     6,   139,    33,    30,   142,    39,    30,
      57,   146,   147,   167,    17,    30,   152,   105,   172,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    -1,   168,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,     3,     4,
       5,     6,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    50,    -1,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    37,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    50,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    10,
      11,    35,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,    34,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,    32,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,    32,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,    32,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,     8,     9,    10,
      11,    30,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,     8,     9,    10,    11,    30,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,     8,     9,    10,    11,    30,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,     8,
       9,    10,    11,    28,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,     8,     9,    10,    11,    28,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    17,    22,    23,    24,    29,
      31,    32,    33,    37,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    67,    71,    75,    76,    77,
      79,    80,    81,    82,    55,    31,    59,    61,    59,    55,
      33,    55,    65,    68,    70,    55,    76,    72,    73,     4,
      31,    31,    31,     4,    74,    32,    55,    32,    32,     4,
       0,    54,     8,     9,    10,    11,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    32,     7,    22,    23,    26,
      27,    29,    31,    62,    63,    64,    27,    29,    31,    31,
      76,    55,    35,    28,    28,    35,    30,    30,    53,    34,
      55,    55,    65,    32,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,     4,     4,
      55,    65,     4,    55,    65,     4,    30,    78,    30,    36,
      65,    68,    31,    34,    30,    30,    32,    31,    28,    30,
      28,    30,    35,    71,    30,    55,    66,    69,    65,    54,
      54,    55,    65,    78,    71,    34,    30,    39,    32,    30,
      54,    65,    30,    54
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
#line 59 "parser.y"
    {}
    break;

  case 3:
#line 62 "parser.y"
    {;}
    break;

  case 5:
#line 67 "parser.y"
    {}
    break;

  case 6:
#line 68 "parser.y"
    {}
    break;

  case 7:
#line 69 "parser.y"
    {}
    break;

  case 8:
#line 70 "parser.y"
    {}
    break;

  case 9:
#line 71 "parser.y"
    {}
    break;

  case 10:
#line 72 "parser.y"
    {}
    break;

  case 11:
#line 73 "parser.y"
    {}
    break;

  case 12:
#line 74 "parser.y"
    {}
    break;

  case 13:
#line 75 "parser.y"
    {}
    break;

  case 14:
#line 76 "parser.y"
    {}
    break;

  case 15:
#line 79 "parser.y"
    {}
    break;

  case 16:
#line 80 "parser.y"
    {;}
    break;

  case 17:
#line 81 "parser.y"
    {;}
    break;

  case 18:
#line 82 "parser.y"
    {;}
    break;

  case 19:
#line 83 "parser.y"
    {;}
    break;

  case 20:
#line 84 "parser.y"
    {;}
    break;

  case 21:
#line 85 "parser.y"
    {;}
    break;

  case 22:
#line 86 "parser.y"
    {;}
    break;

  case 23:
#line 87 "parser.y"
    {;}
    break;

  case 24:
#line 88 "parser.y"
    {;}
    break;

  case 25:
#line 89 "parser.y"
    {;}
    break;

  case 26:
#line 90 "parser.y"
    {;}
    break;

  case 27:
#line 91 "parser.y"
    {;}
    break;

  case 28:
#line 92 "parser.y"
    {;}
    break;

  case 29:
#line 93 "parser.y"
    {;}
    break;

  case 30:
#line 95 "parser.y"
    {;}
    break;

  case 31:
#line 96 "parser.y"
    {;}
    break;

  case 32:
#line 97 "parser.y"
    {;}
    break;

  case 33:
#line 98 "parser.y"
    {;}
    break;

  case 34:
#line 99 "parser.y"
    {;}
    break;

  case 35:
#line 100 "parser.y"
    {;}
    break;

  case 36:
#line 101 "parser.y"
    {;}
    break;

  case 37:
#line 102 "parser.y"
    {;}
    break;

  case 38:
#line 106 "parser.y"
    {}
    break;

  case 39:
#line 109 "parser.y"
    {}
    break;

  case 40:
#line 110 "parser.y"
    {;}
    break;

  case 41:
#line 111 "parser.y"
    {;}
    break;

  case 42:
#line 112 "parser.y"
    {;}
    break;

  case 43:
#line 113 "parser.y"
    {;}
    break;

  case 44:
#line 116 "parser.y"
    { if (lookup(symtable, (yyvsp[(1) - (1)].str_val), (scope == 0) ? GLOBALVAR : LOCALVAR, scope, NO_KW) == FALSE) {
              SymbolTableEntry *node = create_node((yyvsp[(1) - (1)].str_val), scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
              insert_symbol(symtable, node);
              insert_to_scope(lists, node, scope);
             } else printf("found id %s\n", (yyvsp[(1) - (1)].str_val));

           }
    break;

  case 45:
#line 123 "parser.y"
    { if (lookup(symtable, (yyvsp[(2) - (2)].str_val), (scope == 0) ? GLOBALVAR : LOCALVAR, scope, LOCAL_KW) == FALSE) {
                    SymbolTableEntry *node = create_node((yyvsp[(2) - (2)].str_val), scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
                    insert_symbol(symtable, node);
                    insert_to_scope(lists, node, scope);
                   } else printf("found local id %s\n", (yyvsp[(2) - (2)].str_val));
                 }
    break;

  case 46:
#line 130 "parser.y"
    { if (lookup(symtable, (yyvsp[(2) - (2)].str_val), (scope == 0) ? GLOBALVAR : LOCALVAR, scope, NO_KW) == FALSE) {
                            SymbolTableEntry *node = create_node((yyvsp[(2) - (2)].str_val), scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
                            //insert_symbol(symtable, node);
                            //§insert_to_scope(lists, node, scope);
                          } else printf("found double colon id %s\n", (yyvsp[(2) - (2)].str_val));
                        }
    break;

  case 47:
#line 136 "parser.y"
    {;}
    break;

  case 48:
#line 139 "parser.y"
    {;}
    break;

  case 49:
#line 140 "parser.y"
    {;}
    break;

  case 50:
#line 141 "parser.y"
    {;}
    break;

  case 51:
#line 142 "parser.y"
    {;}
    break;

  case 52:
#line 145 "parser.y"
    {;}
    break;

  case 53:
#line 146 "parser.y"
    {;}
    break;

  case 54:
#line 147 "parser.y"
    {;}
    break;

  case 55:
#line 150 "parser.y"
    {;}
    break;

  case 56:
#line 151 "parser.y"
    {;}
    break;

  case 57:
#line 154 "parser.y"
    {;}
    break;

  case 58:
#line 157 "parser.y"
    {;}
    break;

  case 59:
#line 160 "parser.y"
    {;}
    break;

  case 60:
#line 161 "parser.y"
    {;}
    break;

  case 61:
#line 162 "parser.y"
    {;}
    break;

  case 62:
#line 165 "parser.y"
    {;}
    break;

  case 63:
#line 166 "parser.y"
    {;}
    break;

  case 64:
#line 169 "parser.y"
    {;}
    break;

  case 65:
#line 170 "parser.y"
    {;}
    break;

  case 66:
#line 171 "parser.y"
    {;}
    break;

  case 67:
#line 174 "parser.y"
    {;}
    break;

  case 68:
#line 178 "parser.y"
    {scope++;}
    break;

  case 69:
#line 178 "parser.y"
    {hide_scope(lists, scope--);}
    break;

  case 70:
#line 179 "parser.y"
    {scope++;}
    break;

  case 71:
#line 179 "parser.y"
    {hide_scope(lists, scope--);}
    break;

  case 72:
#line 182 "parser.y"
    { (yyval.str_val) = (yyvsp[(1) - (1)].str_val);}
    break;

  case 73:
#line 183 "parser.y"
    {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          (yyval.str_val) = temp;
          }
    break;

  case 74:
#line 192 "parser.y"
    {if (lookup(symtable, (yyvsp[(2) - (2)].str_val), USERFUNC, scope, (scope == 0) ? FUNC : LOCAL_FUNC) == FALSE) {
                            SymbolTableEntry *node = create_node((yyvsp[(2) - (2)].str_val), scope, yylineno, USERFUNC, ACTIVE);;
                            insert_symbol(symtable, node);
                            insert_to_scope(lists, node, scope);
                          } else printf("found func id %s\n", (yyvsp[(2) - (2)].str_val));
                        }
    break;

  case 75:
#line 200 "parser.y"
    {;}
    break;

  case 76:
#line 201 "parser.y"
    {;}
    break;

  case 77:
#line 204 "parser.y"
    { printf("int %d scope %d\n", yyval.int_val, scope);}
    break;

  case 78:
#line 205 "parser.y"
    { printf("real %f scope %d\n", yyval.real_val, scope);}
    break;

  case 79:
#line 206 "parser.y"
    { printf("str %s scope %d\n",yyval.str_val, scope);}
    break;

  case 80:
#line 207 "parser.y"
    {;}
    break;

  case 81:
#line 208 "parser.y"
    {;}
    break;

  case 82:
#line 209 "parser.y"
    {;}
    break;

  case 83:
#line 212 "parser.y"
    {;}
    break;

  case 84:
#line 213 "parser.y"
    {;}
    break;

  case 85:
#line 216 "parser.y"
    {/**/}
    break;

  case 86:
#line 217 "parser.y"
    {;}
    break;

  case 87:
#line 220 "parser.y"
    {;}
    break;

  case 88:
#line 223 "parser.y"
    {;}
    break;

  case 89:
#line 226 "parser.y"
    {;}
    break;

  case 90:
#line 227 "parser.y"
    {;}
    break;


/* Line 1267 of yacc.c.  */
#line 2146 "parser.c"
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


#line 230 "parser.y"


int yyerror(const char *error_msg) {
  fprintf(stderr, "something went bad %s, line %d\n", error_msg, yylineno);

  return 1;
}

int main(int argc, char **argv) {

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  lists = create_scope_lists();
  
  symtable = create_table();

  add_lib_func(symtable, lists);
  yyparse();
  
// print_hash(symtable);
print_scopes(lists);

  free_table(symtable);

  return 0;
}

/* x = 2;
function foo() {
  function foo(bar) {
    local foo = 2;
    return bar + foo;
  }
  {
    local foo = [{foo:[{foo:foo}]}];
    foo.foo..foo(::foo);
  }
  x = (function(){});
}
*/

