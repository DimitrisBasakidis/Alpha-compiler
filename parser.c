/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grammatical_rules/grammar_functions.h"

#include "utilities/quads.h"

#define YYERROR_VERBOSE 1

int yylex(void);
int yyerror(const char *error_msg);
void print_errors(const char *error_msg, char *token, const char *error_type);

const char *file_name;

quad* quads = (quad*)0;
unsigned total = 0;
unsigned int currQuad = 0;

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

unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

// expr *ex;

int temp_count = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

extern int column;
extern char *lineptr;

SymTable *symtable;
scopeLists *lists;

size_t nfuncs = 0U;
SymbolTableEntry *entry;



#line 129 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 60 "parser.y"

  int int_val;
  char *str_val;
  float real_val;
  struct expr *ex;

#line 288 "parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    97,    98,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     130,   131,   132,   133,   137,   141,   146,   150,   154,   165,
     173,   177,   178,   179,   183,   187,   196,   202,   205,   206,
     207,   208,   211,   211,   212,   212,   213,   216,   217,   220,
     223,   226,   227,   228,   231,   232,   235,   236,   236,   240,
     244,   244,   245,   245,   248,   249,   258,   299,   299,   300,
     300,   303,   304,   305,   306,   307,   308,   311,   323,   325,
     327,   329,   330,   333,   334,   337,   337,   340,   340,   343,
     343,   345,   345
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ID", "STRING", "REAL",
  "ASSIGN", "OR", "AND", "EQUAL", "NOT_EQUAL", "GREATER_THAN",
  "GREATER_EQUAL", "LESSER_THAN", "LESSER_EQUAL", "LOWER_THAN_ELSE",
  "PLUS", "MINUS", "MULTIPLY", "SLASH", "MODULO", "UMINUS", "NOT",
  "INCREMENT", "DECREMENT", "DOT", "DOUBLE_DOT", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS",
  "SEMICOLON", "LEFT_BRACKET", "RIGHT_BRACKET", "COMMA", "COLON",
  "DOUBLE_COLON", "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN_KW",
  "BRK", "CONTINUE", "LOCAL", "TRUE_KW", "FALSE_KW", "ENDL", "NIL",
  "$accept", "program", "statements", "stmt", "expr", "term", "assignexpr",
  "primary", "lvalue", "member", "call", "$@1", "$@2", "callsuffix",
  "normcall", "methodcall", "elist", "objectdef", "indexed", "$@3",
  "indexedelem", "block", "$@4", "$@5", "fname", "func_id", "funcdef",
  "$@6", "$@7", "const", "idlist_id", "open_for", "open_while", "open_if",
  "idlist", "ifstmt", "whilestmt", "$@8", "forstmt", "$@9", "returnstmt",
  "$@10", "$@11", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-100)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     192,  -144,  -144,  -144,  -144,   248,   248,     9,     9,     4,
     240,  -144,   -10,    34,  -144,  -144,  -144,    36,    17,    25,
      26,    52,  -144,  -144,  -144,    59,   192,  -144,   328,  -144,
    -144,  -144,    87,  -144,   -14,  -144,  -144,    30,  -144,  -144,
      32,    33,    50,  -144,  -144,  -144,  -144,    24,  -144,    22,
      -9,   -14,    -9,   248,   291,    37,    55,    51,   376,    56,
     192,    71,  -144,  -144,  -144,    57,   248,  -144,  -144,  -144,
    -144,  -144,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,  -144,   248,  -144,  -144,    86,
     248,    -4,   112,   248,  -144,     2,   248,   248,   248,    88,
      89,   248,  -144,  -144,    85,  -144,    90,   144,  -144,  -144,
     344,   478,   490,   502,   502,   187,   187,   187,   187,    24,
      24,  -144,  -144,  -144,   465,  -144,   421,   117,   248,  -144,
    -144,  -144,  -144,   443,   248,  -144,  -144,    91,    93,    95,
     391,   406,    90,   248,  -144,  -144,   248,  -144,  -144,  -144,
      92,    97,  -144,    99,    98,   128,  -144,   248,  -144,   192,
     310,  -144,   102,   248,  -144,  -144,  -144,  -144,    98,   360,
     192,   100,  -144,  -144,   103,  -144,   248,  -144,   192,  -144,
     105,  -144,  -144,   192,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    81,    44,    83,    82,     0,     0,     0,     0,    63,
       0,    14,    70,     0,    90,    89,    88,    75,   101,     0,
       0,     0,    85,    86,    84,     0,     2,     4,     0,    29,
      15,    37,    39,    47,    40,    41,    12,     0,    13,    43,
       0,     0,     0,     6,     7,     8,     9,    31,    30,     0,
      33,     0,    35,     0,    61,     0,     0,    66,     0,     0,
       0,     0,    46,    74,    76,     0,     0,    10,    11,    45,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,    34,    36,     0,
       0,     0,     0,     0,    52,     0,    63,     0,     0,     0,
       0,    63,    64,    65,     0,    32,    42,     0,    73,   100,
       0,    28,    27,    25,    26,    21,    22,    23,    24,    16,
      17,    19,    18,    20,    38,    48,     0,     0,    63,    55,
      57,    58,    50,     0,    63,    87,    79,    91,     0,     0,
       0,     0,     0,     0,    62,    67,    63,    71,   102,    49,
       0,     0,    51,     0,     0,     0,    77,     0,    95,     0,
       0,    68,     0,    63,    59,    53,    80,    92,     0,     0,
       0,    93,    69,    56,     0,    78,    63,    96,     0,    60,
       0,    94,    97,     0,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,    77,   -24,    -5,  -144,  -144,  -144,    23,  -144,
      28,  -144,  -144,  -144,  -144,  -144,   -81,  -144,    38,  -144,
    -144,  -143,  -144,  -144,  -144,  -144,    -7,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,   -15,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   134,    91,   129,   130,   131,    55,    35,    56,   161,
      57,    36,    60,    61,    64,    37,    38,   168,   154,    39,
     137,    40,    41,    42,   138,    43,    44,   170,    45,   183,
      46,    65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    48,    71,    59,    54,    58,   135,     1,     2,     3,
       4,   166,    92,     2,    93,   139,    94,    89,   -54,    90,
     144,   -54,     5,   127,   -72,   175,   128,     6,     7,     8,
      50,    52,     9,   136,    10,    51,    51,    53,    62,    49,
      63,    13,    99,    82,    83,    84,    13,   151,   100,   -99,
      21,    22,    23,   153,    24,    21,    69,    67,    68,    70,
      95,   110,    96,    97,    17,   162,   102,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      98,   124,   174,    71,   103,   126,   104,   106,   133,   109,
     125,    54,   140,   141,    86,   180,    54,    72,    73,    74,
      75,    76,    77,    78,    79,   108,    80,    81,    82,    83,
      84,    87,    88,    89,   -54,    90,   132,   -54,    53,   142,
     146,   150,   163,    54,   156,   143,   155,   157,   164,    54,
     165,    12,   135,   173,   179,   171,   182,   107,   160,   178,
     167,    54,   145,     0,     0,     0,   177,     1,     2,     3,
       4,     0,   169,     0,   181,     0,     0,     0,    54,   184,
       0,     0,     5,     0,     0,     0,     0,     6,     7,     8,
       0,    54,     9,     0,    10,     0,    11,    12,   147,     0,
       0,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,     1,     2,     3,     4,  -100,
    -100,  -100,  -100,     0,    80,    81,    82,    83,    84,     0,
       5,     0,     0,     0,     0,     6,     7,     8,     0,     0,
       9,     0,    10,     0,    11,    12,     0,     0,     0,    13,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,     1,     2,     3,     4,     0,     0,     0,
       0,     1,     2,     3,     4,     0,     0,     0,     5,     0,
       0,     0,     0,     6,     7,     8,     5,     0,     9,     0,
      10,     6,     7,     8,     0,     0,     9,    13,    10,     0,
       0,     0,    17,     0,     0,    13,    21,    22,    23,     0,
      24,     0,     0,     0,    21,    22,    23,     0,    24,    72,
      73,    74,    75,    76,    77,    78,    79,     0,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,   101,    80,    81,    82,
      83,    84,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,   172,    80,    81,    82,    83,    84,
       0,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      85,    80,    81,    82,    83,    84,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,   148,    80,    81,    82,
      83,    84,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    79,   176,    80,    81,    82,    83,    84,     0,    72,
      73,    74,    75,    76,    77,    78,    79,   105,    80,    81,
      82,    83,    84,     0,    72,    73,    74,    75,    76,    77,
      78,    79,   158,    80,    81,    82,    83,    84,     0,    72,
      73,    74,    75,    76,    77,    78,    79,   159,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
     149,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,   152,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    73,    74,    75,
      76,    77,    78,    79,     0,    80,    81,    82,    83,    84,
      74,    75,    76,    77,    78,    79,     0,    80,    81,    82,
      83,    84,  -100,  -100,    76,    77,    78,    79,     0,    80,
      81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
       5,     6,    26,    10,     9,    10,     4,     3,     4,     5,
       6,   154,    26,     4,    28,    96,    30,    26,    27,    28,
     101,    30,    18,    27,    34,   168,    30,    23,    24,    25,
       7,     8,    28,    31,    30,     7,     8,    33,     4,    30,
       4,    37,    49,    19,    20,    21,    37,   128,    53,    32,
      46,    47,    48,   134,    50,    46,     4,    32,    32,     0,
      30,    66,    30,    30,    42,   146,    29,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      30,    86,   163,   107,    29,    90,    35,    31,    93,    32,
       4,    96,    97,    98,     7,   176,   101,     8,     9,    10,
      11,    12,    13,    14,    15,    34,    17,    18,    19,    20,
      21,    24,    25,    26,    27,    28,     4,    30,    33,    31,
      30,     4,    30,   128,    31,    36,    35,    32,    31,   134,
      31,    33,     4,    31,    31,   159,    31,    60,   143,    39,
     155,   146,   104,    -1,    -1,    -1,   170,     3,     4,     5,
       6,    -1,   157,    -1,   178,    -1,    -1,    -1,   163,   183,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,   176,    28,    -1,    30,    -1,    32,    33,    34,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,     3,     4,     5,     6,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    21,    -1,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,
      28,    -1,    30,    -1,    32,    33,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    23,    24,    25,    18,    -1,    28,    -1,
      30,    23,    24,    25,    -1,    -1,    28,    37,    30,    -1,
      -1,    -1,    42,    -1,    -1,    37,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    46,    47,    48,    -1,    50,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    35,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    34,    17,    18,    19,    20,    21,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      32,    17,    18,    19,    20,    21,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    32,    17,    18,    19,
      20,    21,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    32,    17,    18,    19,    20,    21,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    31,    17,    18,
      19,    20,    21,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    31,    17,    18,    19,    20,    21,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    31,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    21,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    21,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    18,    23,    24,    25,    28,
      30,    32,    33,    37,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    68,    72,    76,    77,    80,
      82,    83,    84,    86,    87,    89,    91,    55,    55,    30,
      59,    61,    59,    33,    55,    67,    69,    71,    55,    77,
      73,    74,     4,     4,    75,    92,    93,    32,    32,     4,
       0,    54,     8,     9,    10,    11,    12,    13,    14,    15,
      17,    18,    19,    20,    21,    32,     7,    24,    25,    26,
      28,    63,    26,    28,    30,    30,    30,    30,    30,    77,
      55,    35,    29,    29,    35,    31,    31,    53,    34,    32,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,     4,    55,    27,    30,    64,
      65,    66,     4,    55,    62,     4,    31,    81,    85,    67,
      55,    55,    31,    36,    67,    69,    30,    34,    32,    29,
       4,    67,    29,    67,    79,    35,    31,    32,    31,    31,
      55,    70,    67,    30,    31,    31,    72,    85,    78,    55,
      88,    54,    34,    31,    67,    72,    32,    54,    39,    31,
      67,    54,    31,    90,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    62,    61,    63,    61,    61,    64,    64,    65,
      66,    67,    67,    67,    68,    68,    69,    70,    69,    71,
      73,    72,    74,    72,    75,    75,    76,    78,    77,    79,
      77,    80,    80,    80,    80,    80,    80,    81,    82,    83,
      84,    85,    85,    86,    86,    88,    87,    90,    89,    92,
      91,    93,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     2,     3,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     0,     5,     0,     3,     6,     1,     1,     3,
       5,     1,     3,     0,     3,     3,     1,     0,     4,     5,
       0,     4,     0,     3,     1,     0,     2,     0,     6,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     7,     0,     6,     0,    10,     0,
       3,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 94 "parser.y"
                    {}
#line 1670 "parser.c"
    break;

  case 3:
#line 97 "parser.y"
                            {;}
#line 1676 "parser.c"
    break;

  case 5:
#line 102 "parser.y"
                     {}
#line 1682 "parser.c"
    break;

  case 6:
#line 103 "parser.y"
               {}
#line 1688 "parser.c"
    break;

  case 7:
#line 104 "parser.y"
                  {}
#line 1694 "parser.c"
    break;

  case 8:
#line 105 "parser.y"
                {}
#line 1700 "parser.c"
    break;

  case 9:
#line 106 "parser.y"
                   {}
#line 1706 "parser.c"
    break;

  case 10:
#line 107 "parser.y"
                      {manage_break(print_errors);}
#line 1712 "parser.c"
    break;

  case 11:
#line 108 "parser.y"
                           {manage_continue(print_errors);}
#line 1718 "parser.c"
    break;

  case 12:
#line 109 "parser.y"
              {}
#line 1724 "parser.c"
    break;

  case 13:
#line 110 "parser.y"
                {}
#line 1730 "parser.c"
    break;

  case 14:
#line 111 "parser.y"
                  {}
#line 1736 "parser.c"
    break;

  case 15:
#line 114 "parser.y"
                 {;}
#line 1742 "parser.c"
    break;

  case 16:
#line 115 "parser.y"
                     {;}
#line 1748 "parser.c"
    break;

  case 17:
#line 116 "parser.y"
                      {;}
#line 1754 "parser.c"
    break;

  case 18:
#line 117 "parser.y"
                      {;}
#line 1760 "parser.c"
    break;

  case 19:
#line 118 "parser.y"
                         {;}
#line 1766 "parser.c"
    break;

  case 20:
#line 119 "parser.y"
                       {;}
#line 1772 "parser.c"
    break;

  case 21:
#line 120 "parser.y"
                             {;}
#line 1778 "parser.c"
    break;

  case 22:
#line 121 "parser.y"
                              {;}
#line 1784 "parser.c"
    break;

  case 23:
#line 122 "parser.y"
                            {;}
#line 1790 "parser.c"
    break;

  case 24:
#line 123 "parser.y"
                             {;}
#line 1796 "parser.c"
    break;

  case 25:
#line 124 "parser.y"
                      {;}
#line 1802 "parser.c"
    break;

  case 26:
#line 125 "parser.y"
                          {;}
#line 1808 "parser.c"
    break;

  case 27:
#line 126 "parser.y"
                    {;}
#line 1814 "parser.c"
    break;

  case 28:
#line 127 "parser.y"
                   {;}
#line 1820 "parser.c"
    break;

  case 29:
#line 128 "parser.y"
           {;}
#line 1826 "parser.c"
    break;

  case 30:
#line 130 "parser.y"
                {;}
#line 1832 "parser.c"
    break;

  case 31:
#line 131 "parser.y"
                 {;}
#line 1838 "parser.c"
    break;

  case 32:
#line 132 "parser.y"
                                              {;}
#line 1844 "parser.c"
    break;

  case 33:
#line 133 "parser.y"
                       { 
      entry = lookup(symtable, lists, (yyvsp[0].str_val), (lookup_lib_func((yyvsp[0].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
      manage_increment(entry, (yyvsp[0].str_val), print_errors);
    }
#line 1853 "parser.c"
    break;

  case 34:
#line 137 "parser.y"
                       {
      entry = lookup(symtable, lists, (yyvsp[-1].str_val), (lookup_lib_func((yyvsp[-1].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
      manage_increment(entry, (yyvsp[-1].str_val), print_errors);
    }
#line 1862 "parser.c"
    break;

  case 35:
#line 141 "parser.y"
                       {
      entry = lookup(symtable, lists, (yyvsp[0].str_val), (lookup_lib_func((yyvsp[0].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      manage_decrement(entry, (yyvsp[0].str_val), print_errors);
    }
#line 1872 "parser.c"
    break;

  case 36:
#line 146 "parser.y"
                       {entry = lookup(symtable, lists, (yyvsp[-1].str_val), (lookup_lib_func((yyvsp[-1].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      manage_decrement(entry, (yyvsp[-1].str_val), print_errors);
    }
#line 1881 "parser.c"
    break;

  case 37:
#line 150 "parser.y"
              {;}
#line 1887 "parser.c"
    break;

  case 38:
#line 154 "parser.y"
                               { 

  entry = lookup(symtable, lists, (yyvsp[-2].str_val), (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);

  manage_assignexpr(symtable, lists, entry, (yyvsp[-2].str_val), print_errors, yylineno);

  is_local_kw = 0;
  if (from_func_call > 0) from_func_call--;
}
#line 1901 "parser.c"
    break;

  case 39:
#line 165 "parser.y"
                { 
  //entry = lookup(symtable, lists, $1, (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);
  // entry = manage_lvalue(symtable, lists, $1, print_errors, yylineno);
  entry = manage_lvalue(symtable, lists, (yyvsp[0].str_val), print_errors, yylineno);

  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
#line 1914 "parser.c"
    break;

  case 40:
#line 173 "parser.y"
       { 
  entry = lookup(symtable, lists, (yyvsp[0].str_val), (lookup_lib_func((yyvsp[0].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
  manage_call(symtable, lists, entry, (yyvsp[0].str_val), print_errors, yylineno);
}
#line 1923 "parser.c"
    break;

  case 41:
#line 177 "parser.y"
            {;}
#line 1929 "parser.c"
    break;

  case 42:
#line 178 "parser.y"
                                             {;}
#line 1935 "parser.c"
    break;

  case 43:
#line 179 "parser.y"
        {;}
#line 1941 "parser.c"
    break;

  case 44:
#line 183 "parser.y"
           { //$$->strConst = malloc(strlen($1));
          (yyval.str_val) = (yyvsp[0].str_val);
        }
#line 1949 "parser.c"
    break;

  case 45:
#line 187 "parser.y"
           { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 
  entry = lookup(symtable, lists, (yyvsp[0].str_val), LOCALVAR, scope, SCOPE); 
  
  is_local_kw = 1;
  manage_local_id(symtable, lists, entry, (yyvsp[0].str_val), print_errors, yylineno);

  (yyval.str_val) = (yyvsp[0].str_val);
}
#line 1962 "parser.c"
    break;

  case 46:
#line 196 "parser.y"
                  { 
  entry = lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, 0, SCOPE); 

  manage_double_colon_id(entry, (yyvsp[0].str_val), print_errors);
  (yyval.str_val) = (yyvsp[0].str_val);
}
#line 1973 "parser.c"
    break;

  case 47:
#line 202 "parser.y"
         {;}
#line 1979 "parser.c"
    break;

  case 48:
#line 205 "parser.y"
                      {printf("id : %s\n", (yyvsp[0].str_val));}
#line 1985 "parser.c"
    break;

  case 49:
#line 206 "parser.y"
                                                             {;}
#line 1991 "parser.c"
    break;

  case 50:
#line 207 "parser.y"
                    {from_func_call++;}
#line 1997 "parser.c"
    break;

  case 51:
#line 208 "parser.y"
                                                           {;}
#line 2003 "parser.c"
    break;

  case 52:
#line 211 "parser.y"
                            {from_elist = 1;}
#line 2009 "parser.c"
    break;

  case 53:
#line 211 "parser.y"
                                                                       {;}
#line 2015 "parser.c"
    break;

  case 54:
#line 212 "parser.y"
               {;}
#line 2021 "parser.c"
    break;

  case 55:
#line 212 "parser.y"
                              {;}
#line 2027 "parser.c"
    break;

  case 56:
#line 213 "parser.y"
                                                                                            {;}
#line 2033 "parser.c"
    break;

  case 57:
#line 216 "parser.y"
                     {;}
#line 2039 "parser.c"
    break;

  case 58:
#line 217 "parser.y"
                       {;}
#line 2045 "parser.c"
    break;

  case 59:
#line 220 "parser.y"
                                                   {;}
#line 2051 "parser.c"
    break;

  case 60:
#line 223 "parser.y"
                                                                   {;}
#line 2057 "parser.c"
    break;

  case 61:
#line 226 "parser.y"
            {;}
#line 2063 "parser.c"
    break;

  case 62:
#line 227 "parser.y"
                        { (yyval.str_val) = (yyvsp[-2].str_val);}
#line 2069 "parser.c"
    break;

  case 63:
#line 228 "parser.y"
       {;}
#line 2075 "parser.c"
    break;

  case 64:
#line 231 "parser.y"
                                                          {;}
#line 2081 "parser.c"
    break;

  case 65:
#line 232 "parser.y"
                                                            {;}
#line 2087 "parser.c"
    break;

  case 66:
#line 235 "parser.y"
                     {;}
#line 2093 "parser.c"
    break;

  case 67:
#line 236 "parser.y"
                                   {;}
#line 2099 "parser.c"
    break;

  case 68:
#line 237 "parser.y"
       {;}
#line 2105 "parser.c"
    break;

  case 69:
#line 240 "parser.y"
                                                        {;}
#line 2111 "parser.c"
    break;

  case 70:
#line 244 "parser.y"
                    {scope++;}
#line 2117 "parser.c"
    break;

  case 71:
#line 244 "parser.y"
                                                        {hide_scope(lists, scope--);}
#line 2123 "parser.c"
    break;

  case 72:
#line 245 "parser.y"
                    {scope++;}
#line 2129 "parser.c"
    break;

  case 73:
#line 245 "parser.y"
                                             {hide_scope(lists, scope--);}
#line 2135 "parser.c"
    break;

  case 74:
#line 248 "parser.y"
          { (yyval.str_val) = (yyvsp[0].str_val);}
#line 2141 "parser.c"
    break;

  case 75:
#line 249 "parser.y"
          {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          (yyval.str_val) = temp;
          }
#line 2153 "parser.c"
    break;

  case 76:
#line 258 "parser.y"
                       { // elegxoume ama uparxoyn ta entries sto hashtable kai einai active, an nai ektypwnoyme ta katallhla error messages
// alliws ta vazoume sto table
  entry = lookup(symtable, lists, (yyvsp[0].str_val), USERFUNC, scope, SCOPE);
  
  manage_function(symtable, lists, entry, (yyvsp[0].str_val), print_errors, yylineno);
  // if (entry == NULL) {
  //   SymbolTableEntry *node = create_node($2, scope, yylineno, USERFUNC, ACTIVE);
  //   insert_symbol(symtable, node);
  //   insert_to_scope(lists, node, scope);
  // } else {
  //   char *print = NULL;
  //   switch (entry->type) {

  //     case LIBFUNC:
  //       print = "redefining library function";
  //       break;
  //     case USERFUNC: 
  //       print = "redefining user function";
  //       break;

  //     case GLOBALVAR:
  //       print = "redefining global variable";
  //       break; 

  //     case LOCALVAR: 
  //       print = "redefining local variable";
  //       break;
  //     case FORMAL:
  //       print = "redefining formal argument";
  //       break;

  //     default:
  //       print = "vaggeli agapiesai";  
  //       break;
  //   }

  //   print_errors(print, $2, "grammar");
  //   exit(TRUE);
  // }
}
#line 2198 "parser.c"
    break;

  case 77:
#line 299 "parser.y"
                                                           {func_in_between++;}
#line 2204 "parser.c"
    break;

  case 78:
#line 299 "parser.y"
                                                                                     {func_in_between--;}
#line 2210 "parser.c"
    break;

  case 79:
#line 300 "parser.y"
                                                    {func_in_between++;}
#line 2216 "parser.c"
    break;

  case 80:
#line 300 "parser.y"
                                                                               {func_in_between--;}
#line 2222 "parser.c"
    break;

  case 81:
#line 303 "parser.y"
                {;}
#line 2228 "parser.c"
    break;

  case 82:
#line 304 "parser.y"
            { ;}
#line 2234 "parser.c"
    break;

  case 83:
#line 305 "parser.y"
              { ;}
#line 2240 "parser.c"
    break;

  case 84:
#line 306 "parser.y"
           {;}
#line 2246 "parser.c"
    break;

  case 85:
#line 307 "parser.y"
               {;}
#line 2252 "parser.c"
    break;

  case 86:
#line 308 "parser.y"
                {;}
#line 2258 "parser.c"
    break;

  case 87:
#line 311 "parser.y"
              { 

  SymbolTableEntry *entry_l = NULL;

  manage_lib_function((yyvsp[0].str_val), print_errors);

  entry = lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, scope, SCOPE);
  entry_l = lookup(symtable, lists, (yyvsp[0].str_val), FORMAL, scope + 1, SCOPE);
  
  manage_id(symtable, lists, entry, entry_l, (yyvsp[0].str_val), print_errors, yylineno);
}
#line 2274 "parser.c"
    break;

  case 88:
#line 323 "parser.y"
              {for_loop++;}
#line 2280 "parser.c"
    break;

  case 89:
#line 325 "parser.y"
                  {while_loop++;}
#line 2286 "parser.c"
    break;

  case 90:
#line 327 "parser.y"
            {if_stmt++;}
#line 2292 "parser.c"
    break;

  case 91:
#line 329 "parser.y"
                  {;}
#line 2298 "parser.c"
    break;

  case 92:
#line 330 "parser.y"
                               {;}
#line 2304 "parser.c"
    break;

  case 93:
#line 333 "parser.y"
                                                             {if_stmt--;}
#line 2310 "parser.c"
    break;

  case 94:
#line 334 "parser.y"
                                                                       {if_stmt--;}
#line 2316 "parser.c"
    break;

  case 95:
#line 337 "parser.y"
                                                              {in_loop++;}
#line 2322 "parser.c"
    break;

  case 96:
#line 337 "parser.y"
                                                                               {in_loop--; while_loop--;}
#line 2328 "parser.c"
    break;

  case 97:
#line 340 "parser.y"
                                                                                          {in_loop++;}
#line 2334 "parser.c"
    break;

  case 98:
#line 340 "parser.y"
                                                                                                             {in_loop--; for_loop--;}
#line 2340 "parser.c"
    break;

  case 99:
#line 343 "parser.y"
                      { manage_return(print_errors);}
#line 2346 "parser.c"
    break;

  case 100:
#line 343 "parser.y"
                                                                {;}
#line 2352 "parser.c"
    break;

  case 101:
#line 345 "parser.y"
            { manage_return(print_errors);}
#line 2358 "parser.c"
    break;

  case 102:
#line 345 "parser.y"
                                                           { is_return_kw = 1;}
#line 2364 "parser.c"
    break;


#line 2368 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 347 "parser.y"


int yyerror(const char *error_msg) {
  print_errors(yylval.str_val, yytext, "syntax");
  exit(0);
}

void print_errors(const char *error_msg, char *token, const char *error_type) {
  int count = 1;
  int temp = yylineno;

  fprintf(stderr, "%s:%d ",file_name + 1, yylineno);
  printf("\033[31merror:\033[0m %s\n", error_type);   

  while (temp) {temp /= 10; count++;}; 
  printf("  %d | %s",yylineno, error_msg);
  printf("\033[31m");
  printf(" %s", token);
  printf("\033[0m\n");
  printf("%*s|", count + 2, "");
  for (int i = 0; i < strlen(error_msg) + 2; i++) printf(" ");
  printf("\033[31m^\033[0m");
  if (strlen(token) > 1) {
    for (int i = 0; i < strlen(token) - 1; i++) printf("\033[31m~\033[0m");
  }
  printf("\n%*s|\n", count + 2, "");
}


int main(int argc, char **argv) {

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  file_name = strrchr(argv[1], '/');
  lists = create_scope_lists();
  
  symtable = create_table();

  add_lib_func(symtable, lists);
  yyparse();
  
  print_scopes(lists);

  free_table(symtable);

  return 0;
}

