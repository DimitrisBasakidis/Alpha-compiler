/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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


#line 132 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_EQUAL = 10,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 11,                 /* NOT_EQUAL  */
  YYSYMBOL_GREATER_THAN = 12,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUAL = 13,             /* GREATER_EQUAL  */
  YYSYMBOL_LESSER_THAN = 14,               /* LESSER_THAN  */
  YYSYMBOL_LESSER_EQUAL = 15,              /* LESSER_EQUAL  */
  YYSYMBOL_LOWER_THAN_ELSE = 16,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_PLUS = 17,                      /* PLUS  */
  YYSYMBOL_MINUS = 18,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 19,                  /* MULTIPLY  */
  YYSYMBOL_SLASH = 20,                     /* SLASH  */
  YYSYMBOL_MODULO = 21,                    /* MODULO  */
  YYSYMBOL_UMINUS = 22,                    /* UMINUS  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_INCREMENT = 24,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 25,                 /* DECREMENT  */
  YYSYMBOL_DOT = 26,                       /* DOT  */
  YYSYMBOL_DOUBLE_DOT = 27,                /* DOUBLE_DOT  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 28,       /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 29,      /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_LEFT_PARENTHESIS = 30,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 31,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_LEFT_BRACKET = 33,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 34,             /* RIGHT_BRACKET  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_COLON = 36,                     /* COLON  */
  YYSYMBOL_DOUBLE_COLON = 37,              /* DOUBLE_COLON  */
  YYSYMBOL_IF = 38,                        /* IF  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_FOR = 41,                       /* FOR  */
  YYSYMBOL_FUNCTION = 42,                  /* FUNCTION  */
  YYSYMBOL_RETURN_KW = 43,                 /* RETURN_KW  */
  YYSYMBOL_BRK = 44,                       /* BRK  */
  YYSYMBOL_CONTINUE = 45,                  /* CONTINUE  */
  YYSYMBOL_LOCAL = 46,                     /* LOCAL  */
  YYSYMBOL_TRUE_KW = 47,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 48,                  /* FALSE_KW  */
  YYSYMBOL_ENDL = 49,                      /* ENDL  */
  YYSYMBOL_NIL = 50,                       /* NIL  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_stmt = 54,                      /* stmt  */
  YYSYMBOL_expr = 55,                      /* expr  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_assignexpr = 61,                /* assignexpr  */
  YYSYMBOL_primary = 62,                   /* primary  */
  YYSYMBOL_lvalue = 63,                    /* lvalue  */
  YYSYMBOL_tableitem = 64,                 /* tableitem  */
  YYSYMBOL_member = 65,                    /* member  */
  YYSYMBOL_call = 66,                      /* call  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_callsuffix = 68,                /* callsuffix  */
  YYSYMBOL_normcall = 69,                  /* normcall  */
  YYSYMBOL_methodcall = 70,                /* methodcall  */
  YYSYMBOL_elist = 71,                     /* elist  */
  YYSYMBOL_objectdef = 72,                 /* objectdef  */
  YYSYMBOL_tablemake = 73,                 /* tablemake  */
  YYSYMBOL_indexed = 74,                   /* indexed  */
  YYSYMBOL_indexedelem = 75,               /* indexedelem  */
  YYSYMBOL_block = 76,                     /* block  */
  YYSYMBOL_77_6 = 77,                      /* $@6  */
  YYSYMBOL_78_7 = 78,                      /* $@7  */
  YYSYMBOL_funcname = 79,                  /* funcname  */
  YYSYMBOL_funcprefix = 80,                /* funcprefix  */
  YYSYMBOL_funcargs = 81,                  /* funcargs  */
  YYSYMBOL_funcbody = 82,                  /* funcbody  */
  YYSYMBOL_funcblockstart = 83,            /* funcblockstart  */
  YYSYMBOL_funcblockend = 84,              /* funcblockend  */
  YYSYMBOL_funcdef = 85,                   /* funcdef  */
  YYSYMBOL_86_8 = 86,                      /* $@8  */
  YYSYMBOL_const = 87,                     /* const  */
  YYSYMBOL_idlist_id = 88,                 /* idlist_id  */
  YYSYMBOL_open_while = 89,                /* open_while  */
  YYSYMBOL_whilecond = 90,                 /* whilecond  */
  YYSYMBOL_ifprefix = 91,                  /* ifprefix  */
  YYSYMBOL_92_9 = 92,                      /* $@9  */
  YYSYMBOL_elseprefix = 93,                /* elseprefix  */
  YYSYMBOL_idlist = 94,                    /* idlist  */
  YYSYMBOL_ifstmt = 95,                    /* ifstmt  */
  YYSYMBOL_loopstart = 96,                 /* loopstart  */
  YYSYMBOL_loopend = 97,                   /* loopend  */
  YYSYMBOL_loopstmt = 98,                  /* loopstmt  */
  YYSYMBOL_whilestmt = 99,                 /* whilestmt  */
  YYSYMBOL_N = 100,                        /* N  */
  YYSYMBOL_M = 101,                        /* M  */
  YYSYMBOL_forprefix = 102,                /* forprefix  */
  YYSYMBOL_103_10 = 103,                   /* $@10  */
  YYSYMBOL_N_right_par = 104,              /* N_right_par  */
  YYSYMBOL_forstmt = 105,                  /* forstmt  */
  YYSYMBOL_106_11 = 106,                   /* $@11  */
  YYSYMBOL_returnstmt = 107,               /* returnstmt  */
  YYSYMBOL_108_12 = 108,                   /* $@12  */
  YYSYMBOL_109_13 = 109                    /* $@13  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,   106,   106,   107,   110,   129,   131,   137,   138,   139,
     140,   141,   148,   155,   156,   157,   160,   161,   166,   170,
     174,   178,   182,   189,   196,   203,   210,   210,   218,   218,
     226,   226,   233,   233,   240,   243,   244,   245,   250,   263,
     279,   292,   307,   311,   330,   335,   339,   340,   341,   345,
     355,   364,   370,   371,   374,   375,   380,   381,   384,   384,
     388,   402,   408,   409,   412,   420,   428,   429,   430,   432,
     435,   445,   458,   459,   460,   463,   467,   467,   468,   468,
     471,   472,   481,   494,   498,   501,   503,   505,   507,   507,
     519,   520,   521,   522,   523,   524,   527,   539,   541,   548,
     548,   556,   559,   560,   563,   569,   595,   597,   599,   601,
     610,   611,   613,   613,   622,   624,   624,   636,   636,   640,
     640
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "ID",
  "STRING", "REAL", "ASSIGN", "OR", "AND", "EQUAL", "NOT_EQUAL",
  "GREATER_THAN", "GREATER_EQUAL", "LESSER_THAN", "LESSER_EQUAL",
  "LOWER_THAN_ELSE", "PLUS", "MINUS", "MULTIPLY", "SLASH", "MODULO",
  "UMINUS", "NOT", "INCREMENT", "DECREMENT", "DOT", "DOUBLE_DOT",
  "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "LEFT_PARENTHESIS",
  "RIGHT_PARENTHESIS", "SEMICOLON", "LEFT_BRACKET", "RIGHT_BRACKET",
  "COMMA", "COLON", "DOUBLE_COLON", "IF", "ELSE", "WHILE", "FOR",
  "FUNCTION", "RETURN_KW", "BRK", "CONTINUE", "LOCAL", "TRUE_KW",
  "FALSE_KW", "ENDL", "NIL", "$accept", "program", "statements", "stmt",
  "expr", "$@1", "$@2", "$@3", "$@4", "term", "assignexpr", "primary",
  "lvalue", "tableitem", "member", "call", "$@5", "callsuffix", "normcall",
  "methodcall", "elist", "objectdef", "tablemake", "indexed",
  "indexedelem", "block", "$@6", "$@7", "funcname", "funcprefix",
  "funcargs", "funcbody", "funcblockstart", "funcblockend", "funcdef",
  "$@8", "const", "idlist_id", "open_while", "whilecond", "ifprefix",
  "$@9", "elseprefix", "idlist", "ifstmt", "loopstart", "loopend",
  "loopstmt", "whilestmt", "N", "M", "forprefix", "$@10", "N_right_par",
  "forstmt", "$@11", "returnstmt", "$@12", "$@13", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-170)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-118)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     191,  -170,  -170,  -170,  -170,   274,   274,    19,    19,   239,
      29,  -170,   -26,     5,  -170,  -170,  -170,    13,    -8,    -4,
      -3,    26,  -170,  -170,  -170,    31,   191,  -170,   354,  -170,
    -170,  -170,    12,  -170,  -170,    72,  -170,  -170,  -170,    11,
    -170,  -170,    14,   191,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,     8,    66,    72,    66,   274,   317,    17,    22,    23,
     402,    33,   191,    34,  -170,    30,    37,  -170,  -170,    41,
     274,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
     274,   274,   274,   274,   274,   274,   274,   274,   274,  -170,
     274,  -170,  -170,    65,    70,   274,   274,  -170,  -170,  -170,
      74,   274,  -170,    85,   274,  -170,    58,   274,    68,   119,
     274,  -170,  -170,    76,  -170,    73,   141,  -170,   274,   274,
    -170,   370,  -170,  -170,   274,   274,    93,    93,    93,    93,
       1,     1,  -170,  -170,  -170,   491,  -170,    87,   447,    84,
    -170,   469,   274,  -170,    88,    86,  -170,   417,   191,  -170,
    -170,   191,    89,    73,   274,  -170,  -170,   274,  -170,   432,
      90,  -170,   274,   274,   295,   295,   274,  -170,  -170,  -170,
     104,  -170,    85,  -170,  -170,  -170,  -170,  -170,   336,   110,
    -170,  -170,   504,   516,   111,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,   274,  -170,   116,  -170,   386,  -170,  -170,
    -170,  -170,  -170
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    90,    49,    92,    91,     0,     0,     0,     0,    68,
       0,    15,    76,     0,    99,    97,   112,    81,   119,     0,
       0,     0,    94,    95,    93,     0,     2,     5,     0,    34,
      16,    42,    44,    53,    52,    45,    46,    69,    13,     0,
      14,    48,     0,     0,     7,     8,   110,     9,    10,    36,
      37,     0,    38,     0,    40,     0,    66,     0,     0,    72,
       0,     0,     0,     0,    51,     0,     0,    80,    82,     0,
       0,    11,    12,    50,     1,     4,    32,    30,    26,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,    39,    41,     0,     0,     0,    68,    60,    62,    63,
       0,     0,    58,    84,     0,   106,   104,    68,     0,     0,
      68,    70,    71,    74,    35,    47,     0,    79,     0,    68,
     118,     0,   111,   111,     0,     0,    22,    23,    24,    25,
      17,    18,    19,    20,    21,    43,    54,     0,     0,     0,
      56,     0,    68,    96,     0,   102,    83,     0,     0,   109,
     101,     0,     0,     0,     0,    67,    73,    68,    77,     0,
       0,   120,     0,     0,    27,    29,    68,    55,    64,    57,
       0,    88,     0,    98,   107,   105,   110,   106,     0,     0,
     100,   111,    33,    31,     0,    59,    86,   103,   108,   114,
     115,    75,    61,     0,    65,     0,   110,     0,    85,    87,
     116,   113,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,    81,   -25,     0,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,     4,  -170,  -170,     7,  -170,  -170,  -170,  -170,
     -94,  -170,  -170,    39,  -170,   -45,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,    -6,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,   -19,  -170,  -170,  -170,   -21,  -170,  -169,
    -120,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    56,   124,   125,   123,   122,    29,
      30,    31,    32,    33,    34,    35,   142,    97,    98,    99,
      57,    36,    37,    58,    59,    38,    62,    63,    68,    39,
     144,   199,   195,   202,    40,   186,    41,   145,    42,   105,
      43,    65,   151,   146,    44,   148,   188,   149,    45,   107,
     162,    46,    66,   177,    47,   196,    48,    69,    70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    75,   139,   163,    61,    49,    50,   189,   -78,    64,
      60,    52,    54,   152,    53,    53,   155,    67,   106,    90,
      86,    87,    88,     2,  -117,   160,    28,   200,    71,    72,
      73,    74,     1,     2,     3,     4,    91,    92,    93,    94,
      95,   103,    96,    28,   104,   108,   111,     5,   170,    51,
      17,   112,     6,     7,     8,   109,    13,     9,   113,    10,
     118,   193,    28,   179,   115,    21,    13,   119,   117,   136,
     121,    17,   184,   120,   137,    21,    22,    23,   140,    24,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   143,
     135,    75,    93,    94,    95,   138,    96,   150,   100,   153,
     101,   141,   102,   157,   147,  -118,  -118,  -118,  -118,    55,
      84,    85,    86,    87,    88,   168,    28,   166,   159,   171,
     176,   172,   181,   174,   164,   165,   175,    76,    77,    78,
      79,    80,    81,    82,    83,   185,    84,    85,    86,    87,
      88,   192,   194,   116,     1,     2,     3,     4,    28,    12,
     198,    28,   156,   187,   178,   154,   190,     0,     0,     5,
       0,     0,   182,   183,     6,     7,     8,     0,     0,     9,
       0,    10,     0,    11,    12,   158,     0,     0,    13,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,    24,     0,   197,     1,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     6,     7,     8,     0,     0,     9,
       0,    10,     0,    11,    12,     0,     0,     0,    13,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,    24,     1,     2,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     6,     7,     8,     0,     0,     9,     0,    10,
       0,     0,    55,     0,     0,     0,    13,     1,     2,     3,
       4,     0,     0,     0,     0,    21,    22,    23,     0,    24,
       0,     0,     5,     0,     0,     0,     0,     6,     7,     8,
       0,     0,     9,     0,    10,  -118,  -118,    80,    81,    82,
      83,    13,    84,    85,    86,    87,    88,     0,     0,     0,
      21,    22,    23,     0,    24,    76,    77,    78,    79,    80,
      81,    82,    83,     0,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,   110,    84,    85,    86,    87,    88,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
     191,    84,    85,    86,    87,    88,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    89,    84,    85,    86,
      87,    88,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,   161,    84,    85,    86,    87,    88,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,   201,    84,
      85,    86,    87,    88,     0,    76,    77,    78,    79,    80,
      81,    82,    83,   114,    84,    85,    86,    87,    88,     0,
      76,    77,    78,    79,    80,    81,    82,    83,   173,    84,
      85,    86,    87,    88,     0,    76,    77,    78,    79,    80,
      81,    82,    83,   180,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,   167,    76,    77,    78,
      79,    80,    81,    82,    83,     0,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,   169,    76,
      77,    78,    79,    80,    81,    82,    83,     0,    84,    85,
      86,    87,    88,    77,    78,    79,    80,    81,    82,    83,
       0,    84,    85,    86,    87,    88,    78,    79,    80,    81,
      82,    83,     0,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
       0,    26,    96,   123,    10,     5,     6,   176,    34,     4,
      10,     7,     8,   107,     7,     8,   110,     4,    43,     7,
      19,    20,    21,     4,    32,   119,    26,   196,    32,    32,
       4,     0,     3,     4,     5,     6,    24,    25,    26,    27,
      28,    30,    30,    43,    30,    51,    29,    18,   142,    30,
      42,    29,    23,    24,    25,    55,    37,    28,    35,    30,
      30,   181,    62,   157,    31,    46,    37,    30,    34,     4,
      70,    42,   166,    32,     4,    46,    47,    48,     4,    50,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     4,
      90,   116,    26,    27,    28,    95,    30,    39,    26,    31,
      28,   101,    30,    30,   104,    12,    13,    14,    15,    33,
      17,    18,    19,    20,    21,    31,   116,    30,   118,    31,
      31,    35,    32,   148,   124,   125,   151,     8,     9,    10,
      11,    12,    13,    14,    15,    31,    17,    18,    19,    20,
      21,    31,    31,    62,     3,     4,     5,     6,   148,    33,
     195,   151,   113,   172,   154,    36,   177,    -1,    -1,    18,
      -1,    -1,   162,   163,    23,    24,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    -1,   193,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    28,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    28,    -1,    30,    10,    11,    12,    13,    14,
      15,    37,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    35,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,     8,     9,    10,    11,    12,    13,    14,    15,
      34,    17,    18,    19,    20,    21,    -1,    -1,     8,     9,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    18,    23,    24,    25,    28,
      30,    32,    33,    37,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    52,    53,    54,    55,    60,
      61,    62,    63,    64,    65,    66,    72,    73,    76,    80,
      85,    87,    89,    91,    95,    99,   102,   105,   107,    55,
      55,    30,    63,    66,    63,    33,    55,    71,    74,    75,
      55,    85,    77,    78,     4,    92,   103,     4,    79,   108,
     109,    32,    32,     4,     0,    54,     8,     9,    10,    11,
      12,    13,    14,    15,    17,    18,    19,    20,    21,    32,
       7,    24,    25,    26,    27,    28,    30,    68,    69,    70,
      26,    28,    30,    30,    30,    90,    54,   100,    85,    55,
      35,    29,    29,    35,    31,    31,    53,    34,    30,    30,
      32,    55,    59,    58,    56,    57,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,     4,     4,    55,    71,
       4,    55,    67,     4,    81,    88,    94,    55,    96,    98,
      39,    93,    71,    31,    36,    71,    74,    30,    34,    55,
      71,    32,   101,   101,    55,    55,    30,    29,    31,    29,
      71,    31,    35,    31,    54,    54,    31,   104,    55,    71,
      31,    32,    55,    55,    71,    31,    86,    94,    97,   100,
      98,    34,    31,   101,    31,    83,   106,    55,    76,    82,
     100,    32,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: statements  */
#line 106 "parser.y"
                    {}
#line 1448 "parser.c"
    break;

  case 3: /* program: %empty  */
#line 107 "parser.y"
        {;}
#line 1454 "parser.c"
    break;

  case 4: /* statements: statements stmt  */
#line 110 "parser.y"
                            {
                resettemp();
                (yyval.statement_struct) = malloc(sizeof(struct stmt_t));
                int brk_statemenets = 0, brk_stmt = 0;
                int cont_statements = 0, cont_stmt = 0;

                if ((yyvsp[-1].statement_struct)) {
                  brk_statemenets = (yyvsp[-1].statement_struct)->breakList;
                  cont_statements = (yyvsp[-1].statement_struct)->contList;
                }

                if ((yyvsp[0].statement_struct)) {
                  brk_stmt = (yyvsp[0].statement_struct)->breakList;
                  cont_stmt = (yyvsp[0].statement_struct)->contList;
                }

                (yyval.statement_struct)->breakList = mergelist(brk_statemenets, brk_stmt);
                (yyval.statement_struct)->contList = mergelist(cont_statements , cont_stmt);
          }
#line 1478 "parser.c"
    break;

  case 5: /* statements: stmt  */
#line 129 "parser.y"
             { resettemp();   (yyval.statement_struct) = (yyvsp[0].statement_struct); }
#line 1484 "parser.c"
    break;

  case 6: /* stmt: expr SEMICOLON  */
#line 131 "parser.y"
                     {  
                        printf("expr semicolon in line %d\n", yylineno);
                        (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                        if (boolflag !=1) (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno);
                        boolflag = 0;
                    }
#line 1495 "parser.c"
    break;

  case 7: /* stmt: ifstmt  */
#line 137 "parser.y"
                   { (yyval.statement_struct) = (yyvsp[0].statement_struct); }
#line 1501 "parser.c"
    break;

  case 8: /* stmt: whilestmt  */
#line 138 "parser.y"
                   { (yyval.statement_struct) = NULL; }
#line 1507 "parser.c"
    break;

  case 9: /* stmt: forstmt  */
#line 139 "parser.y"
                   { (yyval.statement_struct) = NULL; }
#line 1513 "parser.c"
    break;

  case 10: /* stmt: returnstmt  */
#line 140 "parser.y"
                   { (yyval.statement_struct) = (yyvsp[0].statement_struct); }
#line 1519 "parser.c"
    break;

  case 11: /* stmt: BRK SEMICOLON  */
#line 142 "parser.y"
                   { 
                    manage_break(print_errors);
                    (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                    (yyval.statement_struct)->breakList = newlist(nextquadlabel()); 
                    emit(jump,NULL,NULL,NULL,0,yylineno);   
                   }
#line 1530 "parser.c"
    break;

  case 12: /* stmt: CONTINUE SEMICOLON  */
#line 149 "parser.y"
                   {
                    manage_continue(print_errors);
                    (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                    (yyval.statement_struct)->contList = newlist(nextquadlabel()); 
                    emit(jump,NULL,NULL,NULL,0,yylineno);
                   }
#line 1541 "parser.c"
    break;

  case 13: /* stmt: block  */
#line 155 "parser.y"
                   { (yyval.statement_struct) = (yyvsp[0].statement_struct);}
#line 1547 "parser.c"
    break;

  case 14: /* stmt: funcdef  */
#line 156 "parser.y"
                   { (yyval.statement_struct) = NULL; }
#line 1553 "parser.c"
    break;

  case 15: /* stmt: SEMICOLON  */
#line 157 "parser.y"
                   { (yyval.statement_struct) = NULL; }
#line 1559 "parser.c"
    break;

  case 16: /* expr: assignexpr  */
#line 160 "parser.y"
                 {(yyval.ex) = (yyvsp[0].ex);}
#line 1565 "parser.c"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 161 "parser.y"
                     {
      // diafaneia 5 dialeksh 3 
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),add);
    }
#line 1575 "parser.c"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 166 "parser.y"
                      {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),sub);
    }
#line 1584 "parser.c"
    break;

  case 19: /* expr: expr MULTIPLY expr  */
#line 170 "parser.y"
                         {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),mul);
    }
#line 1593 "parser.c"
    break;

  case 20: /* expr: expr SLASH expr  */
#line 174 "parser.y"
                      {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),divide);
    }
#line 1602 "parser.c"
    break;

  case 21: /* expr: expr MODULO expr  */
#line 178 "parser.y"
                       {
      check_expr((yyvsp[-2].ex),(yyvsp[0].ex),print_errors);
      (yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[-2].ex),(yyvsp[0].ex),mod);
    }
#line 1611 "parser.c"
    break;

  case 22: /* expr: expr GREATER_THAN expr  */
#line 182 "parser.y"
                             {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_greater,NULL,(yyvsp[-2].ex),(yyvsp[0].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
#line 1623 "parser.c"
    break;

  case 23: /* expr: expr GREATER_EQUAL expr  */
#line 189 "parser.y"
                              {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_greatereq,NULL,(yyvsp[-2].ex),(yyvsp[0].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
#line 1635 "parser.c"
    break;

  case 24: /* expr: expr LESSER_THAN expr  */
#line 196 "parser.y"
                            {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_less,NULL,(yyvsp[-2].ex),(yyvsp[0].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
#line 1647 "parser.c"
    break;

  case 25: /* expr: expr LESSER_EQUAL expr  */
#line 203 "parser.y"
                             {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_lesseq,NULL,(yyvsp[-2].ex),(yyvsp[0].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
#line 1659 "parser.c"
    break;

  case 26: /* $@1: %empty  */
#line 210 "parser.y"
                 { (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno); }
#line 1665 "parser.c"
    break;

  case 27: /* expr: expr EQUAL $@1 expr  */
#line 210 "parser.y"
                                                                                   {
      (yyvsp[0].ex) = manage_bool_expr((yyvsp[0].ex),symtable,lists,scope,yylineno);
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_eq,NULL,(yyvsp[-3].ex),(yyvsp[0].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
#line 1678 "parser.c"
    break;

  case 28: /* $@2: %empty  */
#line 218 "parser.y"
                     { (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno); }
#line 1684 "parser.c"
    break;

  case 29: /* expr: expr NOT_EQUAL $@2 expr  */
#line 218 "parser.y"
                                                                                       {
      (yyvsp[0].ex) = manage_bool_expr((yyvsp[0].ex),symtable,lists,scope,yylineno);
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      (yyval.ex)->trueList = newlist(nextquadlabel());
      (yyval.ex)->falseList = newlist(nextquadlabel() + 1);
      emit(if_noteq,NULL,(yyvsp[-3].ex),(yyvsp[0].ex),0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
#line 1697 "parser.c"
    break;

  case 30: /* $@3: %empty  */
#line 226 "parser.y"
               { (yyvsp[-1].ex) = do_bool((yyvsp[-1].ex),yylineno); }
#line 1703 "parser.c"
    break;

  case 31: /* expr: expr AND $@3 M expr  */
#line 226 "parser.y"
                                                     {
      (yyval.ex) = create_expr(boolexpr_e, NULL , NULL, 0.0f, NULL, '\0');
      (yyvsp[0].ex) = do_bool((yyvsp[0].ex),yylineno);
      patchlist((yyvsp[-4].ex)->trueList,(yyvsp[-1].int_val));
      (yyval.ex)->trueList = (yyvsp[0].ex)->trueList;
      (yyval.ex)->falseList = mergelist((yyvsp[-4].ex)->falseList,(yyvsp[0].ex)->falseList);
    }
#line 1715 "parser.c"
    break;

  case 32: /* $@4: %empty  */
#line 233 "parser.y"
              { (yyvsp[-1].ex) = do_bool((yyvsp[-1].ex),yylineno); }
#line 1721 "parser.c"
    break;

  case 33: /* expr: expr OR $@4 M expr  */
#line 233 "parser.y"
                                                    {
      (yyval.ex) = create_expr(boolexpr_e, NULL, NULL, 0.0f, NULL, '\0');
      (yyvsp[0].ex) = do_bool((yyvsp[0].ex),yylineno);
      patchlist((yyvsp[-4].ex)->falseList,(yyvsp[-1].int_val));
      (yyval.ex)->trueList = mergelist((yyvsp[-4].ex)->trueList,(yyvsp[0].ex)->trueList);
      (yyval.ex)->falseList = (yyvsp[0].ex)->falseList;
    }
#line 1733 "parser.c"
    break;

  case 34: /* expr: term  */
#line 240 "parser.y"
           {(yyval.ex)=(yyvsp[0].ex);}
#line 1739 "parser.c"
    break;

  case 35: /* term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 243 "parser.y"
                                              {(yyval.ex) = (yyvsp[-1].ex);}
#line 1745 "parser.c"
    break;

  case 36: /* term: MINUS expr  */
#line 244 "parser.y"
                 {(yyval.ex) = create_and_emit_arith_expr(symtable,lists,scope,yylineno,(yyvsp[0].ex),NULL,uminus);}
#line 1751 "parser.c"
    break;

  case 37: /* term: NOT expr  */
#line 245 "parser.y"
               {(yyvsp[0].ex) = do_bool((yyvsp[0].ex),yylineno); 
                (yyval.ex) = (yyvsp[0].ex);
                int tmp = (yyval.ex)->trueList;
                (yyval.ex)->trueList = (yyvsp[0].ex)->falseList;
                (yyval.ex)->falseList = tmp;}
#line 1761 "parser.c"
    break;

  case 38: /* term: INCREMENT lvalue  */
#line 250 "parser.y"
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
#line 1779 "parser.c"
    break;

  case 39: /* term: lvalue INCREMENT  */
#line 263 "parser.y"
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
#line 1800 "parser.c"
    break;

  case 40: /* term: DECREMENT lvalue  */
#line 279 "parser.y"
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
#line 1818 "parser.c"
    break;

  case 41: /* term: lvalue DECREMENT  */
#line 292 "parser.y"
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
#line 1838 "parser.c"
    break;

  case 42: /* term: primary  */
#line 307 "parser.y"
              { (yyval.ex) = (yyvsp[0].ex);}
#line 1844 "parser.c"
    break;

  case 43: /* assignexpr: lvalue ASSIGN expr  */
#line 311 "parser.y"
                               {
    (yyval.ex) = (yyvsp[0].ex);
    if((yyvsp[-2].ex)->type == tableitem_e){
        emit(tablesetelem,(yyvsp[-2].ex),(yyvsp[-2].ex)->index,(yyvsp[0].ex),0,yylineno);
        (yyval.ex) = emit_iftableitem((yyvsp[-2].ex),symtable,lists,scope,yylineno);
        (yyval.ex)->type = assignexpr_e;
    }else{
      expr* new = manage_bool_expr((yyvsp[0].ex),symtable,lists,scope,yylineno);
      emit(assign, (yyvsp[-2].ex), new, NULL, 0, yylineno);
      expr* tmp = NULL ;
      tmp = lvalue_expr(newtemp(symtable, lists, scope, yylineno));
      emit(assign, tmp,(yyvsp[-2].ex), NULL, 0, yylineno);
      boolflag = 1;
    }
    is_local_kw = 0;
    if (from_func_call > 0) from_func_call--;
}
#line 1866 "parser.c"
    break;

  case 44: /* primary: lvalue  */
#line 330 "parser.y"
                { 
  (yyval.ex) = emit_iftableitem((yyvsp[0].ex), symtable, lists, scope, yylineno);
  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
#line 1876 "parser.c"
    break;

  case 45: /* primary: call  */
#line 335 "parser.y"
       { 
  entry = lookup(symtable, lists, (yyvsp[0].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[0].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
  manage_call(symtable, lists, entry, (yyvsp[0].ex)->sym->value.varVal->name, print_errors, yylineno);
}
#line 1885 "parser.c"
    break;

  case 46: /* primary: objectdef  */
#line 339 "parser.y"
            {;}
#line 1891 "parser.c"
    break;

  case 47: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 340 "parser.y"
                                             {(yyval.ex) = create_expr(programfunc_e,(yyvsp[-1].symbol),0,0,"",'\0');}
#line 1897 "parser.c"
    break;

  case 48: /* primary: const  */
#line 341 "parser.y"
        { (yyval.ex) = (yyvsp[0].ex);}
#line 1903 "parser.c"
    break;

  case 49: /* lvalue: ID  */
#line 345 "parser.y"
           {
            if (peek(func_scopes) == NULL) {
              printf("we are not in a func in scope: %d\n", scope);
            } else {
              printf("we are  in a func in scope: %d and the prev func scope is %d\n", scope, peek(func_scopes)->x);
            }
            entry = manage_id(symtable, lists, (yyvsp[0].str_val), yylineno, scope, (peek(func_scopes) != NULL) ? peek(func_scopes)->x : -1, print_errors);
            (yyval.ex) = lvalue_expr(entry);
           }
#line 1917 "parser.c"
    break;

  case 50: /* lvalue: LOCAL ID  */
#line 355 "parser.y"
           { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 

  is_local_kw = 1;

  entry = manage_local_id(symtable, lists, (yyvsp[0].str_val), print_errors, yylineno);

  (yyval.ex) = lvalue_expr(entry);
}
#line 1930 "parser.c"
    break;

  case 51: /* lvalue: DOUBLE_COLON ID  */
#line 364 "parser.y"
                  { 
  
  entry = manage_double_colon_id(symtable, lists, (yyvsp[0].str_val), print_errors);
  (yyval.ex) = lvalue_expr(entry);

}
#line 1941 "parser.c"
    break;

  case 52: /* lvalue: member  */
#line 370 "parser.y"
         {(yyval.ex)=(yyvsp[0].ex);}
#line 1947 "parser.c"
    break;

  case 53: /* lvalue: tableitem  */
#line 371 "parser.y"
             {(yyval.ex) = (yyvsp[0].ex);}
#line 1953 "parser.c"
    break;

  case 54: /* tableitem: lvalue DOT ID  */
#line 374 "parser.y"
                         { (yyval.ex) = member_item((yyvsp[-2].ex),(yyvsp[0].str_val),symtable,lists,scope,yylineno); }
#line 1959 "parser.c"
    break;

  case 55: /* tableitem: lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET  */
#line 375 "parser.y"
                                                                {
            (yyvsp[-3].ex) = emit_iftableitem((yyvsp[-3].ex), symtable, lists, scope, yylineno);
            (yyval.ex) = create_expr(tableitem_e, (yyvsp[-3].ex)->sym, (yyvsp[-1].ex), 0.0f, NULL, '\0');
            }
#line 1968 "parser.c"
    break;

  case 56: /* member: call DOT ID  */
#line 380 "parser.y"
                    {from_func_call++;}
#line 1974 "parser.c"
    break;

  case 57: /* member: call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET  */
#line 381 "parser.y"
                                                           {;}
#line 1980 "parser.c"
    break;

  case 58: /* $@5: %empty  */
#line 384 "parser.y"
                            {from_elist = 1; }
#line 1986 "parser.c"
    break;

  case 59: /* call: call LEFT_PARENTHESIS $@5 elist RIGHT_PARENTHESIS  */
#line 384 "parser.y"
                                                                       {
  (yyval.ex) = make_call((yyvsp[-4].ex), reverse_elist((yyvsp[-1].ex)),yylineno,symtable,lists,scope);
  
}
#line 1995 "parser.c"
    break;

  case 60: /* call: lvalue callsuffix  */
#line 388 "parser.y"
                    {
    (yyvsp[-1].ex) = emit_iftableitem((yyvsp[-1].ex),symtable,lists,scope,yylineno);
    if ((yyvsp[0].elist_call)->method) {
      expr* last = get_last((yyvsp[0].elist_call)->elist);
    
      if(last == NULL){
        (yyvsp[0].elist_call)->elist = (yyvsp[-1].ex);
      }else{
        last->next = (yyvsp[-1].ex);
      }
      (yyvsp[-1].ex) = emit_iftableitem(member_item((yyval.ex), (yyvsp[0].elist_call)->name,symtable,lists,scope,yylineno),symtable,lists,scope,yylineno);
    }
    (yyval.ex) = make_call((yyvsp[-1].ex), reverse_elist((yyvsp[0].elist_call)->elist) ,yylineno, symtable, lists, scope);
  }
#line 2014 "parser.c"
    break;

  case 61: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 402 "parser.y"
                                                                                      {
  // lookup_func_id(symtable, lists, $1->name, print_errors);
  expr* func = create_expr(programfunc_e, (yyvsp[-4].symbol), NULL, 0.0f, NULL, '\0'); 
  (yyval.ex) = make_call(func, reverse_elist((yyvsp[-1].ex)), yylineno, symtable, lists, scope);
}
#line 2024 "parser.c"
    break;

  case 62: /* callsuffix: normcall  */
#line 408 "parser.y"
                     {(yyval.elist_call) = (yyvsp[0].elist_call);}
#line 2030 "parser.c"
    break;

  case 63: /* callsuffix: methodcall  */
#line 409 "parser.y"
                       {(yyval.elist_call) = (yyvsp[0].elist_call);}
#line 2036 "parser.c"
    break;

  case 64: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 412 "parser.y"
                                                   {
  (yyval.elist_call) = malloc(sizeof(struct call_t));
  (yyval.elist_call)->elist = (yyvsp[-1].ex);
  (yyval.elist_call)->method = 0;
  (yyval.elist_call)->name = NULL;
}
#line 2047 "parser.c"
    break;

  case 65: /* methodcall: DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 420 "parser.y"
                                                                   {
  (yyval.elist_call) = malloc(sizeof(struct call_t));
  (yyval.elist_call)->elist = (yyvsp[-1].ex);
  (yyval.elist_call)->method = 1;
  (yyval.elist_call)->name = strdup((yyvsp[-3].str_val));
}
#line 2058 "parser.c"
    break;

  case 66: /* elist: expr  */
#line 428 "parser.y"
            { printf("expr\n"); (yyval.ex)->next = NULL; (yyval.ex) = manage_bool_expr((yyvsp[0].ex),symtable,lists,scope,yylineno); }
#line 2064 "parser.c"
    break;

  case 67: /* elist: expr COMMA elist  */
#line 429 "parser.y"
                           { printf("expr comma elist\n"); (yyvsp[-2].ex)->next = (yyvsp[0].ex); (yyval.ex)=(yyvsp[-2].ex); }
#line 2070 "parser.c"
    break;

  case 68: /* elist: %empty  */
#line 430 "parser.y"
          { printf("hi");(yyval.ex) = NULL;}
#line 2076 "parser.c"
    break;

  case 69: /* objectdef: tablemake  */
#line 432 "parser.y"
                     {;}
#line 2082 "parser.c"
    break;

  case 70: /* tablemake: LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET  */
#line 435 "parser.y"
                                                          {
  expr* t = create_expr(newtable_e, newtemp(symtable, lists, scope, yylineno), NULL, 0.0f, NULL, '\0');
  emit(tablecreate, t, NULL, NULL, 0, yylineno);
  expr *tmp = (yyvsp[-1].ex);
  for (int i = 0; tmp; tmp = tmp->next) {
    
    emit(tablesetelem, t, newexpr_constnum(i++), tmp, 0, yylineno);
  }
  (yyval.ex) = t;
}
#line 2097 "parser.c"
    break;

  case 71: /* tablemake: LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET  */
#line 445 "parser.y"
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
#line 2113 "parser.c"
    break;

  case 72: /* indexed: indexedelem  */
#line 458 "parser.y"
                     {(yyval.indexedlist_node) = (yyvsp[0].indexedlist_node); (yyval.indexedlist_node)->next = NULL;}
#line 2119 "parser.c"
    break;

  case 73: /* indexed: indexedelem COMMA indexed  */
#line 459 "parser.y"
                                   {(yyvsp[-2].indexedlist_node)->next = (yyvsp[0].indexedlist_node); (yyval.indexedlist_node)=(yyvsp[-2].indexedlist_node);}
#line 2125 "parser.c"
    break;

  case 74: /* indexed: %empty  */
#line 460 "parser.y"
        {(yyval.indexedlist_node) = NULL;}
#line 2131 "parser.c"
    break;

  case 75: /* indexedelem: LEFT_BRACKET expr COLON expr RIGHT_BRACKET  */
#line 463 "parser.y"
                                                        {(yyval.indexedlist_node) = create_indexlist_node((yyvsp[-3].ex),(yyvsp[-1].ex)); (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno);}
#line 2137 "parser.c"
    break;

  case 76: /* $@6: %empty  */
#line 467 "parser.y"
                    {scope++;  }
#line 2143 "parser.c"
    break;

  case 77: /* block: LEFT_BRACKET $@6 statements RIGHT_BRACKET  */
#line 467 "parser.y"
                                                          { hide_scope(lists, scope--); (yyval.statement_struct) = (yyvsp[-1].statement_struct); }
#line 2149 "parser.c"
    break;

  case 78: /* $@7: %empty  */
#line 468 "parser.y"
                    {scope++;}
#line 2155 "parser.c"
    break;

  case 79: /* block: LEFT_BRACKET $@7 RIGHT_BRACKET  */
#line 468 "parser.y"
                                             {hide_scope(lists, scope--); (yyval.statement_struct) = NULL;}
#line 2161 "parser.c"
    break;

  case 80: /* funcname: ID  */
#line 471 "parser.y"
             { (yyval.str_val) = (yyvsp[0].str_val);}
#line 2167 "parser.c"
    break;

  case 81: /* funcname: %empty  */
#line 472 "parser.y"
          {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          (yyval.str_val) = temp;
          }
#line 2179 "parser.c"
    break;

  case 82: /* funcprefix: FUNCTION funcname  */
#line 481 "parser.y"
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
#line 2196 "parser.c"
    break;

  case 83: /* funcargs: idlist  */
#line 494 "parser.y"
                 {
                enterscopespace();
                resetfunctionlocaloffset();
                }
#line 2205 "parser.c"
    break;

  case 84: /* funcargs: %empty  */
#line 498 "parser.y"
                  {enterscopespace();
                resetfunctionlocaloffset();}
#line 2212 "parser.c"
    break;

  case 85: /* funcbody: block  */
#line 501 "parser.y"
                { (yyval.int_val) = currscopeoffset(); exitscopespace(); }
#line 2218 "parser.c"
    break;

  case 86: /* funcblockstart: %empty  */
#line 503 "parser.y"
                { push(func_scopes, scope); push(loop_stack, in_loop); in_loop = 0;}
#line 2224 "parser.c"
    break;

  case 87: /* funcblockend: %empty  */
#line 505 "parser.y"
              { scopestack_t *temp = pop(loop_stack); pop(func_scopes); in_loop = temp->x; }
#line 2230 "parser.c"
    break;

  case 88: /* $@8: %empty  */
#line 507 "parser.y"
                                                                { func_in_between++; }
#line 2236 "parser.c"
    break;

  case 89: /* funcdef: funcprefix LEFT_PARENTHESIS funcargs RIGHT_PARENTHESIS $@8 funcblockstart funcbody funcblockend  */
#line 507 "parser.y"
                                                                                                                            {
  exitscopespace();
  (yyval.symbol)->total_locals = (yyvsp[-1].int_val);
  scopestack_t *temp = pop(stack);
  int offset = temp->x;
  restorecurrentscopeoffset(offset);
  (yyval.symbol) = (yyvsp[-7].symbol);
  emit(funcend, lvalue_expr((yyvsp[-7].symbol)), NULL, NULL, 0, 0);
  
  func_in_between--;
}
#line 2252 "parser.c"
    break;

  case 90: /* const: INTEGER  */
#line 519 "parser.y"
               {(yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[0].int_val), "vaggelis", '\0');}
#line 2258 "parser.c"
    break;

  case 91: /* const: REAL  */
#line 520 "parser.y"
            { (yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[0].real_val), "", '\0');}
#line 2264 "parser.c"
    break;

  case 92: /* const: STRING  */
#line 521 "parser.y"
              { (yyval.ex) = create_expr(conststring_e, NULL, NULL, 0, (yyvsp[0].str_val), '\0');}
#line 2270 "parser.c"
    break;

  case 93: /* const: NIL  */
#line 522 "parser.y"
           {(yyval.ex) = create_expr(nil_e, NULL, NULL, 0, "lempesis", '\0');}
#line 2276 "parser.c"
    break;

  case 94: /* const: TRUE_KW  */
#line 523 "parser.y"
               {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '1');}
#line 2282 "parser.c"
    break;

  case 95: /* const: FALSE_KW  */
#line 524 "parser.y"
                {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '0');}
#line 2288 "parser.c"
    break;

  case 96: /* idlist_id: ID  */
#line 527 "parser.y"
              { 

  SymbolTableEntry *entry_l = NULL;

  manage_lib_function((yyvsp[0].str_val), print_errors);

  entry = lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, scope, SCOPE);
  entry_l = lookup(symtable, lists, (yyvsp[0].str_val), FORMAL, scope + 1, SCOPE);
  
  manage_id_list(symtable, lists, entry, entry_l, (yyvsp[0].str_val), print_errors, yylineno);
}
#line 2304 "parser.c"
    break;

  case 97: /* open_while: WHILE  */
#line 539 "parser.y"
                  {while_loop++; (yyval.int_val) = nextquadlabel();}
#line 2310 "parser.c"
    break;

  case 98: /* whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 541 "parser.y"
                                                   { 
              (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno);
              emit(if_eq,(yyvsp[-1].ex),create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,nextquadlabel()+2,yylineno);
              (yyval.int_val) = nextquadlabel();
              printf("while cond next label ::%d\n", nextquadlabel());
              emit(jump,NULL,NULL,NULL,0,yylineno);}
#line 2321 "parser.c"
    break;

  case 99: /* $@9: %empty  */
#line 548 "parser.y"
                { if_stmt++; }
#line 2327 "parser.c"
    break;

  case 100: /* ifprefix: IF $@9 LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 548 "parser.y"
                                                                       {
                (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno);
                emit (mul, (yyvsp[-1].ex), create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,nextquadlabel() + 2, yylineno);
                (yyval.int_val) = nextquadlabel();
                emit(jump,NULL,NULL,NULL,0,yylineno);
                }
#line 2338 "parser.c"
    break;

  case 101: /* elseprefix: ELSE  */
#line 556 "parser.y"
                  { (yyval.int_val) = nextquadlabel();
                    emit(jump,NULL,NULL,NULL,0,yylineno);}
#line 2345 "parser.c"
    break;

  case 102: /* idlist: idlist_id  */
#line 559 "parser.y"
                  {;}
#line 2351 "parser.c"
    break;

  case 103: /* idlist: idlist_id COMMA idlist  */
#line 560 "parser.y"
                               {;}
#line 2357 "parser.c"
    break;

  case 104: /* ifstmt: ifprefix stmt  */
#line 563 "parser.y"
                      { 
                      if_stmt--;
                       patchlabel((yyvsp[-1].int_val),nextquadlabel());
                       (yyval.statement_struct)=(yyvsp[0].statement_struct);
                        printf("if\n");
                      }
#line 2368 "parser.c"
    break;

  case 105: /* ifstmt: ifprefix stmt elseprefix stmt  */
#line 570 "parser.y"
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
          if((yyvsp[0].statement_struct)) cont_statements = (yyvsp[0].statement_struct)->contList;
        }

        if((yyvsp[0].statement_struct)){
          brk_stmt = (yyvsp[0].statement_struct)->breakList;
          if((yyvsp[-2].statement_struct)) cont_stmt = (yyvsp[-2].statement_struct)->contList;
        }

        (yyval.statement_struct)->breakList = mergelist(brk_statemenets, brk_stmt);
        (yyval.statement_struct)->contList = mergelist(cont_statements , cont_stmt);
      }
#line 2397 "parser.c"
    break;

  case 106: /* loopstart: %empty  */
#line 595 "parser.y"
           { in_loop++; }
#line 2403 "parser.c"
    break;

  case 107: /* loopend: %empty  */
#line 597 "parser.y"
         { in_loop--; }
#line 2409 "parser.c"
    break;

  case 108: /* loopstmt: loopstart stmt loopend  */
#line 599 "parser.y"
                                 { (yyval.statement_struct) = (yyvsp[-1].statement_struct); }
#line 2415 "parser.c"
    break;

  case 109: /* whilestmt: open_while whilecond loopstmt  */
#line 601 "parser.y"
                                         {  printf("in while stmt\n");
                                      in_loop--; while_loop--;
                                      emit(jump,NULL,NULL,NULL,(yyvsp[-2].int_val),yylineno);
                                      patchlabel((yyvsp[-1].int_val),nextquadlabel());
                                      if((yyvsp[0].statement_struct)) {patchlist((yyvsp[0].statement_struct)->breakList,nextquadlabel()); //$3->breaklist: index tou quad opou briskontai ta breaks, nextquadlabel(): quad label opou bazoume ta brakes na deixnoun 
                                            patchlist((yyvsp[0].statement_struct)->contList,(yyvsp[-2].int_val));}
                                      }
#line 2427 "parser.c"
    break;

  case 110: /* N: %empty  */
#line 610 "parser.y"
   {(yyval.int_val) = nextquadlabel(); emit(jump,NULL,NULL,NULL,0,yylineno);}
#line 2433 "parser.c"
    break;

  case 111: /* M: %empty  */
#line 611 "parser.y"
   {(yyval.int_val) = nextquadlabel();}
#line 2439 "parser.c"
    break;

  case 112: /* $@10: %empty  */
#line 613 "parser.y"
                {for_loop++; in_loop++; }
#line 2445 "parser.c"
    break;

  case 113: /* forprefix: FOR $@10 LEFT_PARENTHESIS elist SEMICOLON M expr SEMICOLON  */
#line 613 "parser.y"
                                                                                            {
              (yyval.forprefix_struct) = malloc(sizeof(struct forstruct_t));
              (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno);
              (yyval.forprefix_struct)->test = (yyvsp[-2].int_val);
              (yyval.forprefix_struct)->enter = nextquadlabel();
              emit(if_eq,(yyvsp[-1].ex),create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,0,yylineno);
          }
#line 2457 "parser.c"
    break;

  case 114: /* N_right_par: RIGHT_PARENTHESIS N  */
#line 622 "parser.y"
                                 { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2463 "parser.c"
    break;

  case 115: /* $@11: %empty  */
#line 624 "parser.y"
                                                { in_loop--; for_loop--;}
#line 2469 "parser.c"
    break;

  case 116: /* forstmt: forprefix N elist N_right_par loopstmt $@11 N  */
#line 624 "parser.y"
                                                                            {
  (yyval.statement_struct) = make_stmt((yyval.statement_struct));
  patchlabel((yyvsp[-6].forprefix_struct)->enter,(yyvsp[-3].int_val)+1);
  patchlabel((yyvsp[-5].int_val),nextquadlabel());
  patchlabel((yyvsp[-3].int_val),(yyvsp[-6].forprefix_struct)->test);
  patchlabel((yyvsp[0].int_val),(yyvsp[-5].int_val) +1);
  
  if ((yyvsp[-2].statement_struct)) patchlist((yyvsp[-2].statement_struct)->breakList,nextquadlabel());
  // printf("$5 = %d\n", $5->contList);
  if ((yyvsp[-2].statement_struct)) patchlist((yyvsp[-2].statement_struct)->contList,(yyvsp[-5].int_val)+1);
}
#line 2485 "parser.c"
    break;

  case 117: /* $@12: %empty  */
#line 636 "parser.y"
                      { manage_return(print_errors); }
#line 2491 "parser.c"
    break;

  case 118: /* returnstmt: RETURN_KW $@12 SEMICOLON  */
#line 636 "parser.y"
                                                                 {emit(ret,NULL,NULL,NULL,0,0);
                                      (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                                      emit(jump,NULL,NULL,NULL,0,yylineno);
                                    }
#line 2500 "parser.c"
    break;

  case 119: /* $@13: %empty  */
#line 640 "parser.y"
            { manage_return(print_errors); }
#line 2506 "parser.c"
    break;

  case 120: /* returnstmt: RETURN_KW $@13 expr SEMICOLON  */
#line 640 "parser.y"
                                                            { emit(ret,(yyvsp[-1].ex),NULL,NULL,0,0); is_return_kw = 1; 
                                  (yyvsp[-1].ex) = manage_bool_expr((yyvsp[-1].ex),symtable,lists,scope,yylineno);
                                  (yyval.statement_struct) = make_stmt((yyval.statement_struct));
                                  emit(jump,NULL,NULL,NULL,0,yylineno);
                                }
#line 2516 "parser.c"
    break;


#line 2520 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 646 "parser.y"


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

  free_table(symtable);

  return 0;
}
