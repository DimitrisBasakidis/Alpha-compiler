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

#include "utilities/elist.h"

#define YYERROR_VERBOSE 1

int yylex(void);
void yyerror(const char *error_msg);
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

int temp_count = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

extern int column;
extern char *lineptr;

SymTable *symtable;
scopeLists *lists;
scope_stack *stack;

size_t nfuncs = 0U;
SymbolTableEntry *entry;


#line 128 "parser.c"

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
#line 59 "parser.y"

  int int_val;
  char *str_val;
  float real_val;
  struct expr *ex;
  struct call_t *elist_call;
  struct stmt_t* statement_struct;
  struct SymbolTableEntry *symbol;
  struct forstruct_t *forprefix_struct;
  struct indexed_list_t *indexedlist_node;


#line 293 "parser.c"

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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

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
       0,   103,   103,   104,   107,   129,   132,   133,   134,   135,
     136,   137,   144,   150,   151,   152,   155,   156,   161,   165,
     169,   173,   177,   180,   183,   186,   189,   192,   195,   200,
     205,   211,   212,   213,   214,   227,   243,   257,   272,   276,
     292,   297,   301,   302,   303,   307,   312,   321,   327,   328,
     331,   334,   339,   340,   343,   345,   350,   364,   370,   371,
     374,   382,   390,   394,   399,   401,   404,   414,   427,   428,
     429,   432,   436,   436,   437,   437,   440,   441,   450,   463,
     467,   470,   475,   477,   490,   491,   492,   493,   494,   495,
     498,   510,   512,   514,   520,   527,   530,   532,   534,   535,
     538,   544,   572,   581,   582,   584,   592,   594,   596,   608,
     612
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
  "primary", "lvalue", "tableitem", "member", "left_par", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef",
  "tablemake", "indexed", "indexedelem", "block", "$@1", "$@2", "funcname",
  "funcprefix", "funcargs", "funcbody", "r_parenthesis", "funcdef",
  "const", "idlist_id", "open_for", "open_while", "whilecond", "ifprefix",
  "elseprefix", "open_if", "return_keyword", "idlist", "ifstmt",
  "whilestmt", "N", "M", "forprefix", "N_right_par", "for_stmt_args",
  "forstmt", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF (-168)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     188,  -168,  -168,  -168,  -168,   292,   292,     6,     6,     9,
     236,  -168,   -26,    24,  -168,  -168,  -168,    31,  -168,   -16,
       8,    34,  -168,  -168,  -168,    45,   188,  -168,   354,  -168,
    -168,  -168,    37,  -168,  -168,    66,  -168,  -168,  -168,    20,
    -168,  -168,    21,    28,   188,    30,   244,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,    27,    -4,    66,    -4,   292,   335,
      25,    54,    50,   402,    55,   188,    57,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,  -168,   292,
    -168,  -168,    84,    89,   292,   292,  -168,  -168,  -168,    94,
     292,  -168,   292,    98,   292,   292,   188,    65,   292,  -168,
     370,   292,    74,   102,   292,  -168,  -168,    75,  -168,    77,
     140,  -168,   504,   313,   516,   516,   183,   183,   183,   183,
      10,    10,  -168,  -168,  -168,   491,  -168,    88,   447,   108,
    -168,   469,   109,  -168,   110,   107,  -168,   115,   417,  -168,
    -168,   188,   432,  -168,   117,    77,   292,  -168,  -168,   292,
    -168,   292,  -168,  -168,  -168,  -168,  -168,   119,    98,  -168,
    -168,  -168,  -168,  -168,   188,   116,   118,   122,  -168,  -168,
    -168,   292,  -168,  -168,  -168,  -168,  -168,  -168,   386,  -168,
    -168
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    84,    45,    86,    85,     0,     0,     0,     0,    64,
       0,    15,    72,     0,    96,    92,    91,    77,    97,     0,
       0,     0,    88,    89,    87,     0,     2,     5,     0,    30,
      16,    38,    40,    49,    48,    41,    42,    65,    13,     0,
      14,    44,     0,     0,     0,     0,     0,     7,     8,   103,
       9,    10,    32,    33,     0,    34,     0,    36,     0,    62,
       0,     0,    68,     0,     0,     0,     0,    47,    76,    78,
      11,    12,    46,     1,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
      35,    37,     0,     0,     0,    64,    56,    58,    59,     0,
       0,    54,    64,    80,    64,     0,     0,   100,     0,   109,
       0,    64,     0,     0,    64,    66,    67,    70,    31,    43,
       0,    75,    29,    28,    26,    27,    22,    23,    24,    25,
      17,    18,    19,    20,    21,    39,    50,     0,     0,     0,
      52,     0,     0,    90,     0,    98,    79,     0,     0,   102,
      95,     0,     0,   110,     0,     0,     0,    63,    69,    64,
      73,    64,    51,    60,    53,    55,    82,     0,     0,   104,
      93,   101,    94,   103,     0,     0,     0,     0,    81,    83,
      99,     0,   106,   107,   103,    71,    57,    61,     0,   108,
     105
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,    92,   -19,    -5,  -168,  -168,  -168,    12,  -168,
    -168,  -168,    41,  -168,  -168,  -168,   -93,  -168,  -168,    42,
    -168,    -6,  -168,  -168,  -168,  -168,  -168,  -168,  -168,    -7,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,    -8,
    -168,  -168,  -167,  -168,  -168,  -168,  -168,  -168,  -168
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   102,    35,    96,    97,    98,    60,    36,    37,    61,
      62,    38,    65,    66,    69,    39,   144,   179,   167,    40,
      41,   145,    42,    43,   106,    44,   151,    45,    46,   146,
      47,    48,   111,   181,    49,   174,   184,    50,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    53,   139,    64,    59,    63,   182,    74,   -74,   142,
       2,   147,     1,     2,     3,     4,    70,   189,   154,    55,
      57,   157,    92,    93,    94,   107,    95,     5,    67,    85,
      86,    87,     6,     7,     8,    68,    54,     9,    72,    10,
      71,   110,    58,    13,    89,    73,    13,   112,    56,    56,
     103,   104,    21,   113,   115,    21,    22,    23,   105,    24,
     108,    90,    91,    92,    93,    94,   176,    95,   177,    17,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   116,   135,   117,   119,   149,   136,   138,
      59,   121,    99,   137,   100,   141,   101,    59,   140,    59,
     148,    74,   143,   152,   150,   155,    59,   159,    58,    59,
      75,    76,    77,    78,    79,    80,    81,    82,   161,    83,
      84,    85,    86,    87,    75,    76,    77,    78,    79,    80,
      81,    82,   171,    83,    84,    85,    86,    87,   156,   163,
     165,   166,   168,     1,     2,     3,     4,   169,   173,   186,
     185,   175,    12,   187,    59,   183,    59,   120,     5,   158,
     180,   178,     0,     6,     7,     8,     0,     0,     9,     0,
      10,     0,    11,    12,   160,     0,   188,    13,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      24,     1,     2,     3,     4,   -75,   -75,   -75,   -75,     0,
      83,    84,    85,    86,    87,     0,     5,     0,     0,     0,
       0,     6,     7,     8,     0,     0,     9,     0,    10,     0,
      11,    12,     0,     0,     0,    13,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,     1,
       2,     3,     4,     0,     0,     0,     0,     1,     2,     3,
       4,     0,     0,     0,     5,     0,     0,     0,     0,     6,
       7,     8,     5,     0,     9,     0,    10,     6,     7,     8,
       0,     0,     9,    13,    10,     0,   109,     0,    17,     0,
       0,    13,    21,    22,    23,     0,    24,     0,     0,     0,
      21,    22,    23,     0,    24,     1,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     6,     7,     8,     0,     0,
       9,     0,    10,    77,    78,    79,    80,    81,    82,    13,
      83,    84,    85,    86,    87,     0,     0,     0,    21,    22,
      23,     0,    24,    75,    76,    77,    78,    79,    80,    81,
      82,     0,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
     114,    83,    84,    85,    86,    87,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    88,    83,    84,    85,
      86,    87,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,   153,    83,    84,    85,    86,    87,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,   190,    83,
      84,    85,    86,    87,     0,    75,    76,    77,    78,    79,
      80,    81,    82,   118,    83,    84,    85,    86,    87,     0,
      75,    76,    77,    78,    79,    80,    81,    82,   170,    83,
      84,    85,    86,    87,     0,    75,    76,    77,    78,    79,
      80,    81,    82,   172,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,   162,    75,    76,    77,
      78,    79,    80,    81,    82,     0,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,   164,    75,
      76,    77,    78,    79,    80,    81,    82,     0,    83,    84,
      85,    86,    87,    76,    77,    78,    79,    80,    81,    82,
       0,    83,    84,    85,    86,    87,   -75,   -75,    79,    80,
      81,    82,     0,    83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
       5,     6,    95,    10,     9,    10,   173,    26,    34,   102,
       4,   104,     3,     4,     5,     6,    32,   184,   111,     7,
       8,   114,    26,    27,    28,    44,    30,    18,     4,    19,
      20,    21,    23,    24,    25,     4,    30,    28,     4,    30,
      32,    46,    33,    37,     7,     0,    37,    54,     7,     8,
      30,    30,    46,    58,    29,    46,    47,    48,    30,    50,
      30,    24,    25,    26,    27,    28,   159,    30,   161,    42,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    29,    89,    35,    31,   106,     4,    94,
      95,    34,    26,     4,    28,   100,    30,   102,     4,   104,
     105,   120,     4,   108,    39,    31,   111,    30,    33,   114,
       8,     9,    10,    11,    12,    13,    14,    15,    30,    17,
      18,    19,    20,    21,     8,     9,    10,    11,    12,    13,
      14,    15,   151,    17,    18,    19,    20,    21,    36,    31,
      31,    31,    35,     3,     4,     5,     6,    32,    31,    31,
      34,   156,    33,    31,   159,   174,   161,    65,    18,   117,
     168,   167,    -1,    23,    24,    25,    -1,    -1,    28,    -1,
      30,    -1,    32,    33,    34,    -1,   181,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,     3,     4,     5,     6,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    -1,    18,    -1,    -1,    -1,
      -1,    23,    24,    25,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      24,    25,    18,    -1,    28,    -1,    30,    23,    24,    25,
      -1,    -1,    28,    37,    30,    -1,    32,    -1,    42,    -1,
      -1,    37,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,
      28,    -1,    30,    10,    11,    12,    13,    14,    15,    37,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    46,    47,
      48,    -1,    50,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      35,    17,    18,    19,    20,    21,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    32,    17,    18,    19,
      20,    21,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    32,    17,    18,    19,    20,    21,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    32,    17,
      18,    19,    20,    21,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    31,    17,    18,    19,    20,    21,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    31,    17,
      18,    19,    20,    21,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    31,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    19,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    18,    23,    24,    25,    28,
      30,    32,    33,    37,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    63,    68,    69,    72,    76,
      80,    81,    83,    84,    86,    88,    89,    91,    92,    95,
      98,    99,    55,    55,    30,    59,    63,    59,    33,    55,
      67,    70,    71,    55,    80,    73,    74,     4,     4,    75,
      32,    32,     4,     0,    54,     8,     9,    10,    11,    12,
      13,    14,    15,    17,    18,    19,    20,    21,    32,     7,
      24,    25,    26,    27,    28,    30,    64,    65,    66,    26,
      28,    30,    62,    30,    30,    30,    85,    54,    30,    32,
      55,    93,    80,    55,    35,    29,    29,    35,    31,    31,
      53,    34,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,     4,     4,    55,    67,
       4,    55,    67,     4,    77,    82,    90,    67,    55,    54,
      39,    87,    55,    32,    67,    31,    36,    67,    70,    30,
      34,    30,    29,    31,    29,    31,    31,    79,    35,    32,
      31,    54,    31,    31,    96,    55,    67,    67,    72,    78,
      90,    94,    93,    54,    97,    34,    31,    31,    55,    93,
      32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    63,    64,    64,
      65,    66,    67,    67,    67,    68,    69,    69,    70,    70,
      70,    71,    73,    72,    74,    72,    75,    75,    76,    77,
      77,    78,    79,    80,    81,    81,    81,    81,    81,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    90,
      91,    91,    92,    93,    94,    95,    96,    97,    98,    99,
      99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     1,
       3,     4,     3,     4,     1,     4,     2,     6,     1,     1,
       3,     5,     1,     3,     0,     1,     3,     3,     1,     3,
       0,     5,     0,     4,     0,     3,     1,     0,     2,     1,
       0,     1,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     3,
       2,     4,     3,     0,     0,     7,     2,     1,     6,     2,
       3
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
#line 103 "parser.y"
                    {}
#line 1685 "parser.c"
    break;

  case 4:
#line 107 "parser.y"
                            {
                resettemp();
                (yyval.statement_struct) = malloc(sizeof(struct stmt_t));
                int brk_statemenets = 0, brk_stmt = 0;
                int cont_statements = 0, cont_stmt = 0;

                if((yyvsp[-1].statement_struct)){
                  brk_statemenets = (yyvsp[-1].statement_struct)->breakList;
                  cont_statements = (yyvsp[-1].statement_struct)->contList;
                }

                if((yyvsp[0].statement_struct)){
                  brk_stmt = (yyvsp[0].statement_struct)->breakList;
                  cont_stmt = (yyvsp[0].statement_struct)->contList;
                }

                (yyval.statement_struct)->breakList = mergelist(brk_statemenets, brk_stmt);
                (yyval.statement_struct)->contList = mergelist(cont_statements , cont_stmt);

           //     $$->breakList = mergelist($1->breakList,$2->breakList);
          //      $$->contList = mergelist($1->contList,$2->contList);
          }
#line 1712 "parser.c"
    break;

  case 5:
#line 129 "parser.y"
                 { resettemp();   (yyval.statement_struct) = (yyvsp[0].statement_struct); }
#line 1718 "parser.c"
    break;

  case 6:
#line 132 "parser.y"
                     { (yyval.statement_struct) = make_stmt((yyval.statement_struct)); }
#line 1724 "parser.c"
    break;

  case 7:
#line 133 "parser.y"
               { (yyval.statement_struct) = (yyvsp[0].statement_struct); }
#line 1730 "parser.c"
    break;

  case 8:
#line 134 "parser.y"
                  {/* $$ = make_stmt($$); */ (yyval.statement_struct) = NULL; }
#line 1736 "parser.c"
    break;

  case 9:
#line 135 "parser.y"
                { /*$$ = make_stmt($$);*/ (yyval.statement_struct) = NULL; }
#line 1742 "parser.c"
    break;

  case 10:
#line 136 "parser.y"
                   { (yyval.statement_struct) = (yyvsp[0].statement_struct); }
#line 1748 "parser.c"
    break;

  case 11:
#line 137 "parser.y"
                      { 
                        manage_break(print_errors);
                        (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                        (yyval.statement_struct)->breakList = newlist(nextquadlabel()); 
                        emit(jump,NULL,NULL,NULL,0,yylineno);
                        
                      }
#line 1760 "parser.c"
    break;

  case 12:
#line 144 "parser.y"
                           {
                            manage_continue(print_errors);
                            (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                            (yyval.statement_struct)->contList = newlist(nextquadlabel()); 
                            emit(jump,NULL,NULL,NULL,0,yylineno);
                            }
#line 1771 "parser.c"
    break;

  case 13:
#line 150 "parser.y"
              {(yyval.statement_struct) = (yyvsp[0].statement_struct);}
#line 1777 "parser.c"
    break;

  case 14:
#line 151 "parser.y"
                { /*$$ = make_stmt($$);*/ (yyval.statement_struct) = NULL; }
#line 1783 "parser.c"
    break;

  case 15:
#line 152 "parser.y"
                  { (yyval.statement_struct) = NULL; }
#line 1789 "parser.c"
    break;

  case 16:
#line 155 "parser.y"
                 {;}
#line 1795 "parser.c"
    break;

  case 17:
#line 156 "parser.y"
                     {
      // diafaneia 5 dialeksh 3 
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),add);
    }
#line 1805 "parser.c"
    break;

  case 18:
#line 161 "parser.y"
                      {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),sub);
    }
#line 1814 "parser.c"
    break;

  case 19:
#line 165 "parser.y"
                         {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),mul);
    }
#line 1823 "parser.c"
    break;

  case 20:
#line 169 "parser.y"
                      {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),divide);
    }
#line 1832 "parser.c"
    break;

  case 21:
#line 173 "parser.y"
                       {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),mod);
    }
#line 1841 "parser.c"
    break;

  case 22:
#line 177 "parser.y"
                             {
      (yyval.ex) = create_and_emit_bool_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),if_greater);
    }
#line 1849 "parser.c"
    break;

  case 23:
#line 180 "parser.y"
                              {
      (yyval.ex) = create_and_emit_bool_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),if_greatereq);
    }
#line 1857 "parser.c"
    break;

  case 24:
#line 183 "parser.y"
                            {
      (yyval.ex) = create_and_emit_bool_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),if_less);
    }
#line 1865 "parser.c"
    break;

  case 25:
#line 186 "parser.y"
                             {
      (yyval.ex) = create_and_emit_bool_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),if_lesseq);
    }
#line 1873 "parser.c"
    break;

  case 26:
#line 189 "parser.y"
                      {
      (yyval.ex) = create_and_emit_bool_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),if_eq);
    }
#line 1881 "parser.c"
    break;

  case 27:
#line 192 "parser.y"
                          {
      (yyval.ex) = create_and_emit_bool_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),if_noteq);
    }
#line 1889 "parser.c"
    break;

  case 28:
#line 195 "parser.y"
                    {
      // $$ = create_and_emit_bool_expr(symtable,lists,scope,yylineno,$1,$3,and);
      (yyval.ex) = create_expr(boolexpr_e, newtemp(symtable, lists, scope, yylineno), NULL, 0.0f, NULL, '\0');
      emit(and, (yyval.ex), (yyvsp[-2].ex), (yyvsp[0].ex), 0, yylineno);
    }
#line 1899 "parser.c"
    break;

  case 29:
#line 200 "parser.y"
                   {
      // $$ = create_and_emit_bool_expr(symtable,lists,scope,yylineno,$1,$3,or);
      (yyval.ex) = create_expr(boolexpr_e, newtemp(symtable, lists, scope, yylineno), NULL, 0.0f, NULL, '\0');
      emit(or, (yyval.ex), (yyvsp[-2].ex), (yyvsp[0].ex), 0, yylineno);
    }
#line 1909 "parser.c"
    break;

  case 30:
#line 205 "parser.y"
           {(yyval.ex)=(yyvsp[0].ex);}
#line 1915 "parser.c"
    break;

  case 31:
#line 211 "parser.y"
                                              {(yyval.ex) = (yyvsp[-1].ex);}
#line 1921 "parser.c"
    break;

  case 32:
#line 212 "parser.y"
                 {(yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[0].ex),NULL,uminus);}
#line 1927 "parser.c"
    break;

  case 33:
#line 213 "parser.y"
               { (yyval.ex) = create_and_emit_bool_expr(symtable,lists,scope,yylineno,(yyvsp[0].ex),NULL,not);}
#line 1933 "parser.c"
    break;

  case 34:
#line 214 "parser.y"
                       { 
      manage_increment(symtable, lists, (yyvsp[0].ex)->sym->value.varVal->name, print_errors);
      check_arith((yyvsp[0].ex), "++lvalue");
      if ((yyvsp[0].ex)->type == tableitem_e) {
        (yyval.ex) = emit_iftableitem((yyvsp[0].ex), symtable, lists, scope, yylineno);
        emit(add, (yyval.ex), newexpr_constnum(1), (yyval.ex), 0, yylineno);
        emit(tablesetelem, (yyvsp[0].ex), (yyvsp[0].ex)->index, (yyval.ex), 0, yylineno);
      } else {
        emit(add, (yyvsp[0].ex), newexpr_constnum(1), (yyvsp[0].ex), 0, yylineno);
        (yyval.ex) = create_expr(arithexpr_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[0].ex), 0.0f, NULL, '\0');
        emit(assign, (yyvsp[0].ex), NULL, (yyval.ex), 0, yylineno);
      }
    }
#line 1951 "parser.c"
    break;

  case 35:
#line 227 "parser.y"
                       {
      
      manage_increment(symtable, lists, (yyvsp[-1].ex)->sym->value.varVal->name, print_errors);
      check_arith((yyvsp[-1].ex), "lvalue++");
      (yyval.ex) = create_expr(var_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[-1].ex), 0.0f, NULL, '\0');
      if ((yyvsp[-1].ex)->type == tableitem_e) {
        expr *val = emit_iftableitem((yyvsp[-1].ex), symtable, lists, scope, yylineno);
        emit(assign, val, NULL, (yyval.ex), 0, yylineno);
        emit(add, val, newexpr_constnum(1), val, 0, yylineno);
        emit(tablesetelem, (yyvsp[-1].ex), (yyvsp[-1].ex)->index, val, 0, yylineno);
      } else {
        emit(assign, (yyvsp[-1].ex), NULL, (yyval.ex), 0, yylineno);
        emit(add, (yyvsp[-1].ex), newexpr_constnum(1), (yyvsp[-1].ex), 0, yylineno);
      }
      
    }
#line 1972 "parser.c"
    break;

  case 36:
#line 243 "parser.y"
                       {

      manage_decrement(symtable, lists, (yyvsp[0].ex)->sym->value.varVal->name, print_errors);
      check_arith((yyvsp[0].ex), "--lvalue");
      if ((yyvsp[0].ex)->type == tableitem_e) {
        (yyval.ex) = emit_iftableitem((yyvsp[0].ex), symtable, lists, scope, yylineno);
        emit(add, (yyval.ex), newexpr_constnum(1), (yyval.ex), 0, yylineno);
        emit(tablesetelem, (yyvsp[0].ex), (yyvsp[0].ex)->index, (yyval.ex), 0, yylineno);
      } else {
        emit(add, (yyvsp[0].ex), newexpr_constnum(1), (yyvsp[0].ex), 0, yylineno);
        (yyval.ex) = create_expr(arithexpr_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[0].ex), 0.0f, NULL, '\0');
        emit(assign, (yyvsp[0].ex), NULL, (yyval.ex), 0, yylineno);
      }
    }
#line 1991 "parser.c"
    break;

  case 37:
#line 257 "parser.y"
                       {

      manage_decrement(symtable, lists, (yyvsp[-1].ex)->sym->value.varVal->name, print_errors);
      check_arith((yyvsp[-1].ex), "lvalue--");
      (yyval.ex) = create_expr(var_e, newtemp(symtable, lists, scope, yylineno), (yyvsp[-1].ex), 0.0f, NULL, '\0');
      if ((yyvsp[-1].ex)->type == tableitem_e) {
        expr *val = emit_iftableitem((yyvsp[-1].ex), symtable, lists, scope, yylineno);
        emit(assign, val, NULL, (yyval.ex), 0, yylineno);
        emit(sub, val, newexpr_constnum(1), val, 0, yylineno);
        emit(tablesetelem, (yyvsp[-1].ex), (yyvsp[-1].ex)->index, val, 0, yylineno);
      } else {
        emit(assign, (yyvsp[-1].ex), NULL, (yyval.ex), 0, yylineno);
        emit(sub, (yyvsp[-1].ex), newexpr_constnum(1), (yyvsp[-1].ex), 0, yylineno);
      }
    }
#line 2011 "parser.c"
    break;

  case 38:
#line 272 "parser.y"
              { (yyval.ex) = (yyvsp[0].ex);}
#line 2017 "parser.c"
    break;

  case 39:
#line 276 "parser.y"
                               {
    if((yyvsp[-2].ex)->type == tableitem_e){
        emit(tablesetelem,(yyvsp[-2].ex),(yyvsp[-2].ex)->index,(yyvsp[0].ex),0,yylineno);
        (yyval.ex) = emit_iftableitem((yyvsp[-2].ex),symtable,lists,scope,yylineno);
        (yyval.ex)->type = assignexpr_e;
    }else{
      emit(assign, (yyvsp[-2].ex), (yyvsp[0].ex), NULL, 0, yylineno);
      expr *tmp = lvalue_expr(newtemp(symtable, lists, scope, yylineno));
      emit(assign, tmp,(yyvsp[-2].ex), NULL, 0, yylineno);

    }
    is_local_kw = 0;
    if (from_func_call > 0) from_func_call--;
}
#line 2036 "parser.c"
    break;

  case 40:
#line 292 "parser.y"
                { 
  (yyval.ex) = emit_iftableitem((yyvsp[0].ex), symtable, lists, scope, yylineno);
  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
#line 2046 "parser.c"
    break;

  case 41:
#line 297 "parser.y"
       { 
  entry = lookup(symtable, lists, (yyvsp[0].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[0].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
  manage_call(symtable, lists, entry, (yyvsp[0].ex)->sym->value.varVal->name, print_errors, yylineno);
}
#line 2055 "parser.c"
    break;

  case 42:
#line 301 "parser.y"
            {;}
#line 2061 "parser.c"
    break;

  case 43:
#line 302 "parser.y"
                                             {(yyval.ex) = create_expr(programfunc_e,(yyvsp[-1].symbol),0,0,"",'\0');}
#line 2067 "parser.c"
    break;

  case 44:
#line 303 "parser.y"
        { (yyval.ex) = (yyvsp[0].ex);}
#line 2073 "parser.c"
    break;

  case 45:
#line 307 "parser.y"
           {
            entry = manage_id(symtable, lists, (yyvsp[0].str_val), yylineno, scope, print_errors);
            (yyval.ex) = lvalue_expr(entry);
           }
#line 2082 "parser.c"
    break;

  case 46:
#line 312 "parser.y"
           { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 

  is_local_kw = 1;

  entry = manage_local_id(symtable, lists, (yyvsp[0].str_val), print_errors, yylineno);

  (yyval.ex) = lvalue_expr(entry);
}
#line 2095 "parser.c"
    break;

  case 47:
#line 321 "parser.y"
                  { 
  
  entry = manage_double_colon_id(symtable, lists, (yyvsp[0].str_val), print_errors);
  (yyval.ex) = lvalue_expr(entry);

}
#line 2106 "parser.c"
    break;

  case 48:
#line 327 "parser.y"
         {(yyval.ex)=(yyvsp[0].ex);}
#line 2112 "parser.c"
    break;

  case 49:
#line 328 "parser.y"
             {(yyval.ex) = (yyvsp[0].ex);}
#line 2118 "parser.c"
    break;

  case 50:
#line 331 "parser.y"
                         {                           
                          (yyval.ex) = member_item((yyvsp[-2].ex),(yyvsp[0].str_val),symtable,lists,scope,yylineno);
                          }
#line 2126 "parser.c"
    break;

  case 51:
#line 334 "parser.y"
                                                                {
            (yyvsp[-3].ex) = emit_iftableitem((yyvsp[-3].ex), symtable, lists, scope, yylineno);
            (yyval.ex) = create_expr(tableitem_e, (yyvsp[-3].ex)->sym, (yyvsp[-1].ex), 0.0f, NULL, '\0');
            }
#line 2135 "parser.c"
    break;

  case 52:
#line 339 "parser.y"
                    {from_func_call++;}
#line 2141 "parser.c"
    break;

  case 53:
#line 340 "parser.y"
                                                           {;}
#line 2147 "parser.c"
    break;

  case 54:
#line 343 "parser.y"
                           {from_elist = 1; }
#line 2153 "parser.c"
    break;

  case 55:
#line 345 "parser.y"
                                            {
  //lookup_func_id(symtable, lists, $1, print_errors);
  (yyval.ex) = make_call((yyvsp[-3].ex), reverse_elist((yyvsp[-1].ex)),yylineno,symtable,lists,scope);
  
}
#line 2163 "parser.c"
    break;

  case 56:
#line 350 "parser.y"
                    {
    //lookup_func_id(symtable, lists, $1, print_errors);
    (yyvsp[-1].ex) = emit_iftableitem((yyvsp[-1].ex),symtable,lists,scope,yylineno);
    if ((yyvsp[0].elist_call)->method) {
      expr* last = get_last((yyvsp[0].elist_call)->elist);
      if(last == NULL){
        last = (yyvsp[-1].ex);
      }else{
        last->next = (yyvsp[-1].ex);
      }
      (yyvsp[-1].ex) = emit_iftableitem(member_item((yyval.ex), (yyvsp[0].elist_call)->name,symtable,lists,scope,yylineno),symtable,lists,scope,yylineno);
    }
    (yyval.ex) = make_call((yyvsp[-1].ex), reverse_elist((yyvsp[0].elist_call)->elist) ,yylineno, symtable, lists, scope);
  }
#line 2182 "parser.c"
    break;

  case 57:
#line 364 "parser.y"
                                                                                      {
  // lookup_func_id(symtable, lists, $1->name, print_errors);
  expr* func = create_expr(programfunc_e, (yyvsp[-4].symbol), NULL, 0.0f, NULL, '\0'); 
  (yyval.ex) = make_call(func, reverse_elist((yyvsp[-1].ex)), yylineno, symtable, lists, scope);
}
#line 2192 "parser.c"
    break;

  case 58:
#line 370 "parser.y"
                     {(yyval.elist_call) = (yyvsp[0].elist_call);}
#line 2198 "parser.c"
    break;

  case 59:
#line 371 "parser.y"
                       {(yyval.elist_call) = (yyvsp[0].elist_call);}
#line 2204 "parser.c"
    break;

  case 60:
#line 374 "parser.y"
                                                   {
  (yyval.elist_call) = malloc(sizeof(struct call_t));
  (yyval.elist_call)->elist = (yyvsp[-1].ex);
  (yyval.elist_call)->method = 0;
  (yyval.elist_call)->name = NULL;
}
#line 2215 "parser.c"
    break;

  case 61:
#line 382 "parser.y"
                                                                   {
  (yyval.elist_call) = malloc(sizeof(struct call_t));
  (yyval.elist_call)->elist = (yyvsp[-1].ex);
  (yyval.elist_call)->method = 1;
  (yyval.elist_call)->name = strdup((yyvsp[-3].str_val));
}
#line 2226 "parser.c"
    break;

  case 62:
#line 390 "parser.y"
            {  
             // correct
              (yyval.ex)->next = NULL;
            }
#line 2235 "parser.c"
    break;

  case 63:
#line 394 "parser.y"
                           {
                            // correct
                            (yyvsp[-2].ex)->next = (yyvsp[0].ex); 
                            (yyval.ex)=(yyvsp[-2].ex);      
                           }
#line 2245 "parser.c"
    break;

  case 64:
#line 399 "parser.y"
          { (yyval.ex) = NULL;}
#line 2251 "parser.c"
    break;

  case 65:
#line 401 "parser.y"
                     {;}
#line 2257 "parser.c"
    break;

  case 66:
#line 404 "parser.y"
                                                          {
  expr* t = create_expr(newtable_e, newtemp(symtable, lists, scope, yylineno), NULL, 0.0f, NULL, '\0');
  emit(tablecreate, t, NULL, NULL, 0, yylineno);
  expr *tmp = (yyvsp[-1].ex);
  for (int i = 0; tmp; tmp = tmp->next) {
    
    emit(tablesetelem, t, newexpr_constnum(i++), tmp, 0, yylineno);
  }
  (yyval.ex) = t;
}
#line 2272 "parser.c"
    break;

  case 67:
#line 414 "parser.y"
                                                      {
        expr* t = create_expr(newtable_e,NULL,NULL,0.0f,"",'\0');
        t->sym = newtemp(symtable,lists,scope,yylineno);
        emit(tablecreate,t,NULL,NULL,0,yylineno);
        indexed_list_t *tmp = (yyvsp[-1].indexedlist_node);
        while(tmp!=NULL){
          emit(tablesetelem,t,tmp->index,tmp->value,0,yylineno);
          tmp = tmp->next;
        }
        (yyval.ex) = t;
    }
#line 2288 "parser.c"
    break;

  case 68:
#line 427 "parser.y"
                     {(yyval.indexedlist_node) = (yyvsp[0].indexedlist_node); (yyval.indexedlist_node)->next = NULL;}
#line 2294 "parser.c"
    break;

  case 69:
#line 428 "parser.y"
                                   {(yyvsp[-2].indexedlist_node)->next = (yyvsp[0].indexedlist_node); (yyval.indexedlist_node)=(yyvsp[-2].indexedlist_node);}
#line 2300 "parser.c"
    break;

  case 70:
#line 429 "parser.y"
        {(yyval.indexedlist_node) = NULL;}
#line 2306 "parser.c"
    break;

  case 71:
#line 432 "parser.y"
                                                        {(yyval.indexedlist_node) = create_indexlist_node((yyvsp[-3].ex),(yyvsp[-1].ex));}
#line 2312 "parser.c"
    break;

  case 72:
#line 436 "parser.y"
                    {scope++;  }
#line 2318 "parser.c"
    break;

  case 73:
#line 436 "parser.y"
                                                          { hide_scope(lists, scope--); (yyval.statement_struct) = (yyvsp[-1].statement_struct); }
#line 2324 "parser.c"
    break;

  case 74:
#line 437 "parser.y"
                    {scope++;}
#line 2330 "parser.c"
    break;

  case 75:
#line 437 "parser.y"
                                             {hide_scope(lists, scope--); (yyval.statement_struct) = NULL;}
#line 2336 "parser.c"
    break;

  case 76:
#line 440 "parser.y"
             { (yyval.str_val) = (yyvsp[0].str_val);}
#line 2342 "parser.c"
    break;

  case 77:
#line 441 "parser.y"
          {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          (yyval.str_val) = temp;
          }
#line 2354 "parser.c"
    break;

  case 78:
#line 450 "parser.y"
                              { // elegxoume ama uparxoyn ta entries sto hashtable kai einai active, an nai ektypwnoyme ta katallhla error messages
// alliws ta vazoume sto table
  
  (yyval.symbol) = manage_function(symtable, lists, (yyvsp[0].str_val), print_errors, yylineno);
  /* gia tin epomenh fash */ 
  emit(jump, NULL, NULL, NULL, 0, yylineno);
  //$$->iaddress = nextquadlabel();// deixnei sto funcstart command tou quad poy antistoixei sthn sunarthsh poy orizetai
  emit(funcstart, lvalue_expr((yyval.symbol)), NULL, NULL, 0, 0);
  push(stack, currscopeoffset());
  enterscopespace();
  resetformalargsoffset();
}
#line 2371 "parser.c"
    break;

  case 79:
#line 463 "parser.y"
                 {
                enterscopespace();
                resetfunctionlocaloffset();
                }
#line 2380 "parser.c"
    break;

  case 80:
#line 467 "parser.y"
                  {enterscopespace();
                resetfunctionlocaloffset();}
#line 2387 "parser.c"
    break;

  case 81:
#line 470 "parser.y"
                {
    (yyval.int_val) = currscopeoffset();
    exitscopespace();
    }
#line 2396 "parser.c"
    break;

  case 82:
#line 475 "parser.y"
                                 {func_in_between++; }
#line 2402 "parser.c"
    break;

  case 83:
#line 477 "parser.y"
                                                                     {
      exitscopespace();
      (yyval.symbol)->total_locals = (yyvsp[0].int_val);
      scopestack_t *temp = pop(stack);
      int offset = temp->x;
      restorecurrentscopeoffset(offset);
      (yyval.symbol) = (yyvsp[-4].symbol);
      emit(funcend, lvalue_expr((yyvsp[-4].symbol)), NULL, NULL, 0, 0);
      
      func_in_between--;
      }
#line 2418 "parser.c"
    break;

  case 84:
#line 490 "parser.y"
               {(yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[0].int_val), "vaggelis", '\0');}
#line 2424 "parser.c"
    break;

  case 85:
#line 491 "parser.y"
            { (yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[0].real_val), "", '\0');}
#line 2430 "parser.c"
    break;

  case 86:
#line 492 "parser.y"
              { (yyval.ex) = create_expr(conststring_e, NULL, NULL, 0, (yyvsp[0].str_val), '\0');}
#line 2436 "parser.c"
    break;

  case 87:
#line 493 "parser.y"
           {(yyval.ex) = create_expr(nil_e, NULL, NULL, 0, "lempesis", '\0');}
#line 2442 "parser.c"
    break;

  case 88:
#line 494 "parser.y"
               {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '1');}
#line 2448 "parser.c"
    break;

  case 89:
#line 495 "parser.y"
                {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '0');}
#line 2454 "parser.c"
    break;

  case 90:
#line 498 "parser.y"
              { 

  SymbolTableEntry *entry_l = NULL;

  manage_lib_function((yyvsp[0].str_val), print_errors);

  entry = lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, scope, SCOPE);
  entry_l = lookup(symtable, lists, (yyvsp[0].str_val), FORMAL, scope + 1, SCOPE);
  
  manage_id_list(symtable, lists, entry, entry_l, (yyvsp[0].str_val), print_errors, yylineno);
}
#line 2470 "parser.c"
    break;

  case 91:
#line 510 "parser.y"
              {for_loop++;}
#line 2476 "parser.c"
    break;

  case 92:
#line 512 "parser.y"
                  {while_loop++; (yyval.int_val) = nextquadlabel();}
#line 2482 "parser.c"
    break;

  case 93:
#line 514 "parser.y"
                                                  {in_loop++; 
              emit(if_eq,(yyvsp[-1].ex),create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,nextquadlabel()+2,yylineno);
              (yyval.int_val) = nextquadlabel();
              printf("while cond next label ::%d\n", nextquadlabel());
              emit(jump,NULL,NULL,NULL,0,yylineno);}
#line 2492 "parser.c"
    break;

  case 94:
#line 520 "parser.y"
                                                           {
                emit (if_eq, (yyvsp[-1].ex), create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,nextquadlabel() + 2, yylineno);
                (yyval.int_val) = nextquadlabel();
                emit(jump,NULL,NULL,NULL,0,yylineno);
                }
#line 2502 "parser.c"
    break;

  case 95:
#line 527 "parser.y"
                  { (yyval.int_val) = nextquadlabel();
                    emit(jump,NULL,NULL,NULL,0,yylineno);}
#line 2509 "parser.c"
    break;

  case 96:
#line 530 "parser.y"
             { if_stmt++; }
#line 2515 "parser.c"
    break;

  case 97:
#line 532 "parser.y"
                          { manage_return(print_errors);}
#line 2521 "parser.c"
    break;

  case 98:
#line 534 "parser.y"
                  {;}
#line 2527 "parser.c"
    break;

  case 99:
#line 535 "parser.y"
                               {;}
#line 2533 "parser.c"
    break;

  case 100:
#line 538 "parser.y"
                      { 
                      if_stmt--;
                       patchlabel((yyvsp[-1].int_val),nextquadlabel());
                       (yyval.statement_struct)=(yyvsp[0].statement_struct);
                        printf("if\n");
                      }
#line 2544 "parser.c"
    break;

  case 101:
#line 544 "parser.y"
                                      { 
                                        if_stmt--;
                                        (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                                        patchlabel((yyvsp[-3].int_val),(yyvsp[-1].int_val)+1);
                                        patchlabel((yyvsp[-1].int_val),nextquadlabel());
                                        printf("$2->breakList = %p, $4->breakList = %p\n", (yyvsp[-2].statement_struct), (yyvsp[0].statement_struct));
                                        fflush(stdout);
                                        
                                        int brk_statemenets = 0, cont_statements = 0;
                                        int brk_stmt = 0, cont_stmt = 0;

                                        if((yyvsp[-2].statement_struct)){
                                          brk_statemenets = (yyvsp[-2].statement_struct)->breakList;
                                          if((yyvsp[0].statement_struct))
                                          cont_statements = (yyvsp[0].statement_struct)->contList;
                                        }

                                        if((yyvsp[0].statement_struct)){
                                          brk_stmt = (yyvsp[0].statement_struct)->breakList;
                                          if((yyvsp[-2].statement_struct))
                                          cont_stmt = (yyvsp[-2].statement_struct)->contList;
                                        }

                                        (yyval.statement_struct)->breakList = mergelist(brk_statemenets, brk_stmt);
                                        (yyval.statement_struct)->contList = mergelist(cont_statements , cont_stmt);
                                        }
#line 2575 "parser.c"
    break;

  case 102:
#line 572 "parser.y"
                                     {  printf("in while stmt\n");
                                      in_loop--; while_loop--;
                                      emit(jump,NULL,NULL,NULL,(yyvsp[-2].int_val),yylineno);
                                      patchlabel((yyvsp[-1].int_val),nextquadlabel());
                                      if((yyvsp[0].statement_struct)) {patchlist((yyvsp[0].statement_struct)->breakList,nextquadlabel()); //$3->breaklist: index tou quad opou briskontai ta breaks, nextquadlabel(): quad label opou bazoume ta brakes na deixnoun 
                                            patchlist((yyvsp[0].statement_struct)->contList,(yyvsp[-2].int_val));}
                                      }
#line 2587 "parser.c"
    break;

  case 103:
#line 581 "parser.y"
   {(yyval.int_val) = nextquadlabel(); emit(jump,NULL,NULL,NULL,0,yylineno);}
#line 2593 "parser.c"
    break;

  case 104:
#line 582 "parser.y"
  {(yyval.int_val) = nextquadlabel();}
#line 2599 "parser.c"
    break;

  case 105:
#line 584 "parser.y"
                                                                       {
              (yyval.forprefix_struct) = malloc(sizeof(struct forstruct_t));
              (yyval.forprefix_struct)->test = (yyvsp[-2].int_val);
              (yyval.forprefix_struct)->enter = nextquadlabel();
              emit(if_eq,(yyvsp[-1].ex),create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,0,yylineno);
          }
#line 2610 "parser.c"
    break;

  case 106:
#line 592 "parser.y"
                                 { (yyval.int_val) = (yyvsp[0].int_val); in_loop++;}
#line 2616 "parser.c"
    break;

  case 107:
#line 594 "parser.y"
                    {(yyval.statement_struct) = make_stmt((yyval.statement_struct)); in_loop--; for_loop--;}
#line 2622 "parser.c"
    break;

  case 108:
#line 596 "parser.y"
                                                       {
            (yyval.statement_struct) = make_stmt((yyval.statement_struct));
            patchlabel((yyvsp[-5].forprefix_struct)->enter,(yyvsp[-2].int_val)+1);
            patchlabel((yyvsp[-4].int_val),nextquadlabel());
            patchlabel((yyvsp[-2].int_val),(yyvsp[-5].forprefix_struct)->test);
            patchlabel((yyvsp[0].int_val),(yyvsp[-4].int_val) +1);

            patchlist((yyvsp[-1].statement_struct)->breakList,nextquadlabel());
            patchlist((yyvsp[-1].statement_struct)->contList,(yyvsp[-4].int_val)+1);
}
#line 2637 "parser.c"
    break;

  case 109:
#line 608 "parser.y"
                                     {emit(ret,NULL,NULL,NULL,0,0);
                                      (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                                      emit(jump,NULL,NULL,NULL,0,yylineno);
                                    }
#line 2646 "parser.c"
    break;

  case 110:
#line 612 "parser.y"
                                { emit(ret,(yyvsp[-1].ex),NULL,NULL,0,0);is_return_kw = 1; 
                                  (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                                  emit(jump,NULL,NULL,NULL,0,yylineno);
                                }
#line 2655 "parser.c"
    break;


#line 2659 "parser.c"

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
#line 617 "parser.y"


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

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  

  file_name = strrchr(argv[1], '/');
  lists = create_scope_lists();
  emit(jump,NULL,NULL,NULL,1,0);
  symtable = create_table();

  stack = create_scope_stack();

  add_lib_func(symtable, lists);
  yyparse();
  
  print_scopes(lists);

 
  printf("\n\n\n");

  print_quads();

  free_table(symtable);

  return 0;
}

