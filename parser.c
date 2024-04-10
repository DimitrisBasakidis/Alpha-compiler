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


#line 127 "parser.c"

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
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_assignexpr = 57,                /* assignexpr  */
  YYSYMBOL_primary = 58,                   /* primary  */
  YYSYMBOL_lvalue = 59,                    /* lvalue  */
  YYSYMBOL_member = 60,                    /* member  */
  YYSYMBOL_call = 61,                      /* call  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_callsuffix = 64,                /* callsuffix  */
  YYSYMBOL_normcall = 65,                  /* normcall  */
  YYSYMBOL_methodcall = 66,                /* methodcall  */
  YYSYMBOL_elist = 67,                     /* elist  */
  YYSYMBOL_objectdef = 68,                 /* objectdef  */
  YYSYMBOL_indexed = 69,                   /* indexed  */
  YYSYMBOL_70_3 = 70,                      /* $@3  */
  YYSYMBOL_indexedelem = 71,               /* indexedelem  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_fname = 75,                     /* fname  */
  YYSYMBOL_func_id = 76,                   /* func_id  */
  YYSYMBOL_funcdef = 77,                   /* funcdef  */
  YYSYMBOL_78_6 = 78,                      /* $@6  */
  YYSYMBOL_79_7 = 79,                      /* $@7  */
  YYSYMBOL_const = 80,                     /* const  */
  YYSYMBOL_idlist_id = 81,                 /* idlist_id  */
  YYSYMBOL_open_for = 82,                  /* open_for  */
  YYSYMBOL_open_while = 83,                /* open_while  */
  YYSYMBOL_open_if = 84,                   /* open_if  */
  YYSYMBOL_idlist = 85,                    /* idlist  */
  YYSYMBOL_ifstmt = 86,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 87,                 /* whilestmt  */
  YYSYMBOL_88_8 = 88,                      /* $@8  */
  YYSYMBOL_forstmt = 89,                   /* forstmt  */
  YYSYMBOL_90_9 = 90,                      /* $@9  */
  YYSYMBOL_returnstmt = 91,                /* returnstmt  */
  YYSYMBOL_92_10 = 92,                     /* $@10  */
  YYSYMBOL_93_11 = 93                      /* $@11  */
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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

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
       0,    89,    89,    92,    93,    94,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   110,   111,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   130,   131,   132,   133,   137,   141,   146,   150,   154,
     162,   167,   171,   172,   173,   177,   182,   191,   198,   201,
     202,   203,   204,   207,   207,   208,   208,   209,   212,   213,
     216,   219,   222,   223,   224,   227,   228,   231,   232,   232,
     236,   240,   240,   241,   241,   244,   245,   254,   261,   261,
     262,   262,   265,   266,   267,   268,   269,   270,   273,   285,
     287,   289,   291,   292,   295,   296,   299,   299,   302,   302,
     305,   305,   307,   307
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
  "expr", "term", "assignexpr", "primary", "lvalue", "member", "call",
  "$@1", "$@2", "callsuffix", "normcall", "methodcall", "elist",
  "objectdef", "indexed", "$@3", "indexedelem", "block", "$@4", "$@5",
  "fname", "func_id", "funcdef", "$@6", "$@7", "const", "idlist_id",
  "open_for", "open_while", "open_if", "idlist", "ifstmt", "whilestmt",
  "$@8", "forstmt", "$@9", "returnstmt", "$@10", "$@11", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-101)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     192,  -144,  -144,  -144,  -144,   248,   248,     9,     9,     4,
     240,  -144,  -144,    20,  -144,  -144,  -144,    34,     8,    17,
      25,    52,  -144,  -144,  -144,    58,   192,  -144,   328,  -144,
    -144,  -144,    87,  -144,   -14,  -144,  -144,    29,  -144,  -144,
      30,    32,    33,  -144,  -144,  -144,  -144,    24,  -144,    22,
      -9,   -14,    -9,   248,   291,    37,    51,    49,   376,    55,
     192,    53,  -144,  -144,  -144,    57,   248,  -144,  -144,  -144,
    -144,  -144,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,  -144,   248,  -144,  -144,    86,
     248,    -4,   101,   248,  -144,     2,   248,   248,   248,    85,
      89,   248,  -144,  -144,    88,  -144,    90,   144,  -144,  -144,
     344,   478,   490,   502,   502,   187,   187,   187,   187,    24,
      24,  -144,  -144,  -144,   465,  -144,   421,   114,   248,  -144,
    -144,  -144,  -144,   443,   248,  -144,  -144,    84,    91,    92,
     391,   406,    90,   248,  -144,  -144,   248,  -144,  -144,  -144,
      96,    97,  -144,    99,    94,   127,  -144,   248,  -144,   192,
     310,  -144,   102,   248,  -144,  -144,  -144,  -144,    94,   360,
     192,    93,  -144,  -144,   103,  -144,   248,  -144,   192,  -144,
     105,  -144,  -144,   192,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    82,    45,    84,    83,     0,     0,     0,     0,    64,
       0,    15,    71,     0,    91,    90,    89,    76,   102,     0,
       0,     0,    86,    87,    85,     0,     2,     4,     0,    30,
      16,    38,    40,    48,    41,    42,    13,     0,    14,    44,
       0,     0,     0,     7,     8,     9,    10,    32,    31,     0,
      34,     0,    36,     0,    62,     0,     0,    67,     0,     0,
       5,     0,    47,    75,    77,     0,     0,    11,    12,    46,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,    35,    37,     0,
       0,     0,     0,     0,    53,     0,    64,     0,     0,     0,
       0,    64,    65,    66,     0,    33,    43,     0,    74,   101,
       0,    29,    28,    26,    27,    22,    23,    24,    25,    17,
      18,    20,    19,    21,    39,    49,     0,     0,    64,    56,
      58,    59,    51,     0,    64,    88,    80,    92,     0,     0,
       0,     0,     0,     0,    63,    68,    64,    72,   103,    50,
       0,     0,    52,     0,     0,     0,    78,     0,    96,     0,
       0,    69,     0,    64,    60,    54,    81,    93,     0,     0,
       0,    94,    70,    57,     0,    79,    64,    97,     0,    61,
       0,    95,    98,     0,    99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,    77,   -24,    -5,  -144,  -144,  -144,    23,  -144,
      28,  -144,  -144,  -144,  -144,  -144,   -81,  -144,    35,  -144,
    -144,  -143,  -144,  -144,  -144,  -144,    -7,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,   -15,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
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
       4,   166,    92,     2,    93,   139,    94,    89,   -55,    90,
     144,   -55,     5,   127,    62,   175,   128,     6,     7,     8,
      50,    52,     9,   136,    10,    51,    51,    53,    63,    49,
    -100,    13,    99,    82,    83,    84,    13,   151,   100,    67,
      21,    22,    23,   153,    24,    21,    69,    68,    70,    95,
      96,   110,    97,    98,    17,   162,   102,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     103,   124,   174,    71,   104,   126,   106,   108,   133,   109,
     125,    54,   140,   141,    86,   180,    54,    72,    73,    74,
      75,    76,    77,    78,    79,   132,    80,    81,    82,    83,
      84,    87,    88,    89,   -55,    90,   142,   -55,   150,   155,
     146,    53,   156,    54,   157,   143,   163,    12,   164,    54,
     165,   135,   178,   173,   179,   171,   182,   107,   160,   145,
     167,    54,     0,     0,     0,     0,   177,     1,     2,     3,
       4,     0,   169,     0,   181,     0,     0,     0,    54,   184,
       0,     0,     5,     0,     0,     0,     0,     6,     7,     8,
       0,    54,     9,     0,    10,     0,    11,    12,   147,     0,
       0,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,     1,     2,     3,     4,  -101,
    -101,  -101,  -101,     0,    80,    81,    82,    83,    84,     0,
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
      83,    84,  -101,  -101,    76,    77,    78,    79,     0,    80,
      81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
       5,     6,    26,    10,     9,    10,     4,     3,     4,     5,
       6,   154,    26,     4,    28,    96,    30,    26,    27,    28,
     101,    30,    18,    27,     4,   168,    30,    23,    24,    25,
       7,     8,    28,    31,    30,     7,     8,    33,     4,    30,
      32,    37,    49,    19,    20,    21,    37,   128,    53,    32,
      46,    47,    48,   134,    50,    46,     4,    32,     0,    30,
      30,    66,    30,    30,    42,   146,    29,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      29,    86,   163,   107,    35,    90,    31,    34,    93,    32,
       4,    96,    97,    98,     7,   176,   101,     8,     9,    10,
      11,    12,    13,    14,    15,     4,    17,    18,    19,    20,
      21,    24,    25,    26,    27,    28,    31,    30,     4,    35,
      30,    33,    31,   128,    32,    36,    30,    33,    31,   134,
      31,     4,    39,    31,    31,   159,    31,    60,   143,   104,
     155,   146,    -1,    -1,    -1,    -1,   170,     3,     4,     5,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    60,
      60,    60,    60,    62,    61,    63,    61,    61,    64,    64,
      65,    66,    67,    67,    67,    68,    68,    69,    70,    69,
      71,    73,    72,    74,    72,    75,    75,    76,    78,    77,
      79,    77,    80,    80,    80,    80,    80,    80,    81,    82,
      83,    84,    85,    85,    86,    86,    88,    87,    90,    89,
      92,    91,    93,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     2,     3,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     3,     4,     0,     5,     0,     3,     6,     1,     1,
       3,     5,     1,     3,     0,     3,     3,     1,     0,     4,
       5,     0,     4,     0,     3,     1,     0,     2,     0,     6,
       0,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     7,     0,     6,     0,    10,
       0,     3,     0,     4
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
#line 89 "parser.y"
                    {}
#line 1408 "parser.c"
    break;

  case 3: /* statements: statements stmt  */
#line 92 "parser.y"
                            {resettemp();}
#line 1414 "parser.c"
    break;

  case 4: /* statements: stmt  */
#line 93 "parser.y"
                {resettemp();}
#line 1420 "parser.c"
    break;

  case 6: /* stmt: expr SEMICOLON  */
#line 98 "parser.y"
                     {}
#line 1426 "parser.c"
    break;

  case 7: /* stmt: ifstmt  */
#line 99 "parser.y"
               {}
#line 1432 "parser.c"
    break;

  case 8: /* stmt: whilestmt  */
#line 100 "parser.y"
                  {}
#line 1438 "parser.c"
    break;

  case 9: /* stmt: forstmt  */
#line 101 "parser.y"
                {}
#line 1444 "parser.c"
    break;

  case 10: /* stmt: returnstmt  */
#line 102 "parser.y"
                   {}
#line 1450 "parser.c"
    break;

  case 11: /* stmt: BRK SEMICOLON  */
#line 103 "parser.y"
                      {manage_break(print_errors);}
#line 1456 "parser.c"
    break;

  case 12: /* stmt: CONTINUE SEMICOLON  */
#line 104 "parser.y"
                           {manage_continue(print_errors);}
#line 1462 "parser.c"
    break;

  case 13: /* stmt: block  */
#line 105 "parser.y"
              {}
#line 1468 "parser.c"
    break;

  case 14: /* stmt: funcdef  */
#line 106 "parser.y"
                {}
#line 1474 "parser.c"
    break;

  case 15: /* stmt: SEMICOLON  */
#line 107 "parser.y"
                  {}
#line 1480 "parser.c"
    break;

  case 16: /* expr: assignexpr  */
#line 110 "parser.y"
                 {;}
#line 1486 "parser.c"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 111 "parser.y"
                     {
        entry = newtemp(symtable, lists, scope, yylineno);
        (yyval.ex) = create_expr(arithexpr_e, entry, NULL, 0, NULL, '\0');
        emit(add, (yyval.ex), (yyvsp[-2].ex), (yyvsp[0].ex), 0, yylineno);
      }
#line 1496 "parser.c"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 116 "parser.y"
                      {;}
#line 1502 "parser.c"
    break;

  case 19: /* expr: expr SLASH expr  */
#line 117 "parser.y"
                      {;}
#line 1508 "parser.c"
    break;

  case 20: /* expr: expr MULTIPLY expr  */
#line 118 "parser.y"
                         {;}
#line 1514 "parser.c"
    break;

  case 21: /* expr: expr MODULO expr  */
#line 119 "parser.y"
                       {;}
#line 1520 "parser.c"
    break;

  case 22: /* expr: expr GREATER_THAN expr  */
#line 120 "parser.y"
                             {;}
#line 1526 "parser.c"
    break;

  case 23: /* expr: expr GREATER_EQUAL expr  */
#line 121 "parser.y"
                              {;}
#line 1532 "parser.c"
    break;

  case 24: /* expr: expr LESSER_THAN expr  */
#line 122 "parser.y"
                            {;}
#line 1538 "parser.c"
    break;

  case 25: /* expr: expr LESSER_EQUAL expr  */
#line 123 "parser.y"
                             {;}
#line 1544 "parser.c"
    break;

  case 26: /* expr: expr EQUAL expr  */
#line 124 "parser.y"
                      {;}
#line 1550 "parser.c"
    break;

  case 27: /* expr: expr NOT_EQUAL expr  */
#line 125 "parser.y"
                          {;}
#line 1556 "parser.c"
    break;

  case 28: /* expr: expr AND expr  */
#line 126 "parser.y"
                    {;}
#line 1562 "parser.c"
    break;

  case 29: /* expr: expr OR expr  */
#line 127 "parser.y"
                   {;}
#line 1568 "parser.c"
    break;

  case 30: /* expr: term  */
#line 128 "parser.y"
           {(yyval.ex)=(yyvsp[0].ex);}
#line 1574 "parser.c"
    break;

  case 31: /* term: NOT expr  */
#line 130 "parser.y"
                {;}
#line 1580 "parser.c"
    break;

  case 32: /* term: MINUS expr  */
#line 131 "parser.y"
                 {;}
#line 1586 "parser.c"
    break;

  case 33: /* term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 132 "parser.y"
                                              {;}
#line 1592 "parser.c"
    break;

  case 34: /* term: INCREMENT lvalue  */
#line 133 "parser.y"
                       { 
      entry = lookup(symtable, lists, (yyvsp[0].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[0].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
      manage_increment(entry, (yyvsp[0].ex)->sym->value.varVal->name, print_errors);
    }
#line 1601 "parser.c"
    break;

  case 35: /* term: lvalue INCREMENT  */
#line 137 "parser.y"
                       {
      entry = lookup(symtable, lists, (yyvsp[-1].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[-1].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
      manage_increment(entry, (yyvsp[-1].ex)->sym->value.varVal->name, print_errors);
    }
#line 1610 "parser.c"
    break;

  case 36: /* term: DECREMENT lvalue  */
#line 141 "parser.y"
                       {
      entry = lookup(symtable, lists, (yyvsp[0].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[0].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      manage_decrement(entry, (yyvsp[0].ex)->sym->value.varVal->name, print_errors);
    }
#line 1620 "parser.c"
    break;

  case 37: /* term: lvalue DECREMENT  */
#line 146 "parser.y"
                       {entry = lookup(symtable, lists, (yyvsp[-1].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[-1].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      manage_decrement(entry, (yyvsp[-1].ex)->sym->value.varVal->name, print_errors);
    }
#line 1629 "parser.c"
    break;

  case 38: /* term: primary  */
#line 150 "parser.y"
              { (yyval.ex) = (yyvsp[0].ex);}
#line 1635 "parser.c"
    break;

  case 39: /* assignexpr: lvalue ASSIGN expr  */
#line 154 "parser.y"
                               { 

  emit(assign, (yyvsp[-2].ex), NULL, (yyvsp[0].ex), 0, yylineno);
  is_local_kw = 0;
  if (from_func_call > 0) from_func_call--;
}
#line 1646 "parser.c"
    break;

  case 40: /* primary: lvalue  */
#line 162 "parser.y"
                { 

  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
#line 1656 "parser.c"
    break;

  case 41: /* primary: call  */
#line 167 "parser.y"
       { 
  entry = lookup(symtable, lists, (yyvsp[0].ex)->sym->value.varVal->name, (lookup_lib_func((yyvsp[0].ex)->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
  manage_call(symtable, lists, entry, (yyvsp[0].ex)->sym->value.varVal->name, print_errors, yylineno);
}
#line 1665 "parser.c"
    break;

  case 42: /* primary: objectdef  */
#line 171 "parser.y"
            {;}
#line 1671 "parser.c"
    break;

  case 43: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 172 "parser.y"
                                             {;}
#line 1677 "parser.c"
    break;

  case 44: /* primary: const  */
#line 173 "parser.y"
        { (yyval.ex) = (yyvsp[0].ex);}
#line 1683 "parser.c"
    break;

  case 45: /* lvalue: ID  */
#line 177 "parser.y"
           {
            entry = manage_id(symtable, lists, (yyvsp[0].str_val), yylineno, scope, print_errors);
            (yyval.ex) = lvalue_expr(entry);
           }
#line 1692 "parser.c"
    break;

  case 46: /* lvalue: LOCAL ID  */
#line 182 "parser.y"
           { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 

  is_local_kw = 1;

  entry = manage_local_id(symtable, lists, (yyvsp[0].str_val), print_errors, yylineno);

  (yyval.ex) = lvalue_expr(entry);
}
#line 1705 "parser.c"
    break;

  case 47: /* lvalue: DOUBLE_COLON ID  */
#line 191 "parser.y"
                  { 
  

  entry = manage_double_colon_id(symtable, lists, (yyvsp[0].str_val), print_errors);
  (yyval.ex) = lvalue_expr(entry);

}
#line 1717 "parser.c"
    break;

  case 48: /* lvalue: member  */
#line 198 "parser.y"
         {;}
#line 1723 "parser.c"
    break;

  case 49: /* member: lvalue DOT ID  */
#line 201 "parser.y"
                      {}
#line 1729 "parser.c"
    break;

  case 50: /* member: lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET  */
#line 202 "parser.y"
                                                             {;}
#line 1735 "parser.c"
    break;

  case 51: /* member: call DOT ID  */
#line 203 "parser.y"
                    {from_func_call++;}
#line 1741 "parser.c"
    break;

  case 52: /* member: call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET  */
#line 204 "parser.y"
                                                           {;}
#line 1747 "parser.c"
    break;

  case 53: /* $@1: %empty  */
#line 207 "parser.y"
                            {from_elist = 1; }
#line 1753 "parser.c"
    break;

  case 54: /* call: call LEFT_PARENTHESIS $@1 elist RIGHT_PARENTHESIS  */
#line 207 "parser.y"
                                                                        {;}
#line 1759 "parser.c"
    break;

  case 55: /* $@2: %empty  */
#line 208 "parser.y"
               {;}
#line 1765 "parser.c"
    break;

  case 56: /* call: lvalue $@2 callsuffix  */
#line 208 "parser.y"
                              {;}
#line 1771 "parser.c"
    break;

  case 57: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 209 "parser.y"
                                                                                            {;}
#line 1777 "parser.c"
    break;

  case 58: /* callsuffix: normcall  */
#line 212 "parser.y"
                     {;}
#line 1783 "parser.c"
    break;

  case 59: /* callsuffix: methodcall  */
#line 213 "parser.y"
                       {;}
#line 1789 "parser.c"
    break;

  case 60: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 216 "parser.y"
                                                   {;}
#line 1795 "parser.c"
    break;

  case 61: /* methodcall: DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 219 "parser.y"
                                                                   {;}
#line 1801 "parser.c"
    break;

  case 62: /* elist: expr  */
#line 222 "parser.y"
            {;}
#line 1807 "parser.c"
    break;

  case 63: /* elist: expr COMMA elist  */
#line 223 "parser.y"
                        { (yyval.str_val) = (yyvsp[-2].ex)->sym->value.varVal->name;}
#line 1813 "parser.c"
    break;

  case 64: /* elist: %empty  */
#line 224 "parser.y"
       {;}
#line 1819 "parser.c"
    break;

  case 65: /* objectdef: LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET  */
#line 227 "parser.y"
                                                          {;}
#line 1825 "parser.c"
    break;

  case 66: /* objectdef: LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET  */
#line 228 "parser.y"
                                                            {;}
#line 1831 "parser.c"
    break;

  case 67: /* indexed: indexedelem  */
#line 231 "parser.y"
                     {;}
#line 1837 "parser.c"
    break;

  case 68: /* $@3: %empty  */
#line 232 "parser.y"
                                   {;}
#line 1843 "parser.c"
    break;

  case 69: /* indexed: indexedelem COMMA indexed $@3  */
#line 233 "parser.y"
       {;}
#line 1849 "parser.c"
    break;

  case 70: /* indexedelem: LEFT_BRACKET expr COLON expr RIGHT_BRACKET  */
#line 236 "parser.y"
                                                        {;}
#line 1855 "parser.c"
    break;

  case 71: /* $@4: %empty  */
#line 240 "parser.y"
                    {scope++; }
#line 1861 "parser.c"
    break;

  case 72: /* block: LEFT_BRACKET $@4 statements RIGHT_BRACKET  */
#line 240 "parser.y"
                                                         {hide_scope(lists, scope--); }
#line 1867 "parser.c"
    break;

  case 73: /* $@5: %empty  */
#line 241 "parser.y"
                    {scope++;}
#line 1873 "parser.c"
    break;

  case 74: /* block: LEFT_BRACKET $@5 RIGHT_BRACKET  */
#line 241 "parser.y"
                                             {hide_scope(lists, scope--);}
#line 1879 "parser.c"
    break;

  case 75: /* fname: ID  */
#line 244 "parser.y"
          { (yyval.str_val) = (yyvsp[0].str_val);}
#line 1885 "parser.c"
    break;

  case 76: /* fname: %empty  */
#line 245 "parser.y"
          {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          (yyval.str_val) = temp;
          }
#line 1897 "parser.c"
    break;

  case 77: /* func_id: FUNCTION fname  */
#line 254 "parser.y"
                       { // elegxoume ama uparxoyn ta entries sto hashtable kai einai active, an nai ektypwnoyme ta katallhla error messages
// alliws ta vazoume sto table
  entry = lookup(symtable, lists, (yyvsp[0].str_val), USERFUNC, scope, SCOPE);
  
  manage_function(symtable, lists, entry, (yyvsp[0].str_val), print_errors, yylineno);
}
#line 1908 "parser.c"
    break;

  case 78: /* $@6: %empty  */
#line 261 "parser.y"
                                                           {func_in_between++;}
#line 1914 "parser.c"
    break;

  case 79: /* funcdef: func_id LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS $@6 block  */
#line 261 "parser.y"
                                                                                     {func_in_between--;}
#line 1920 "parser.c"
    break;

  case 80: /* $@7: %empty  */
#line 262 "parser.y"
                                                    {func_in_between++;}
#line 1926 "parser.c"
    break;

  case 81: /* funcdef: func_id LEFT_PARENTHESIS RIGHT_PARENTHESIS $@7 block  */
#line 262 "parser.y"
                                                                               {func_in_between--;}
#line 1932 "parser.c"
    break;

  case 82: /* const: INTEGER  */
#line 265 "parser.y"
               {(yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[0].int_val), "vaggelis", '\0');}
#line 1938 "parser.c"
    break;

  case 83: /* const: REAL  */
#line 266 "parser.y"
            { (yyval.ex) = create_expr(constnum_e, NULL, NULL, (yyvsp[0].real_val), "", '\0');}
#line 1944 "parser.c"
    break;

  case 84: /* const: STRING  */
#line 267 "parser.y"
              { (yyval.ex) = create_expr(conststring_e, NULL, NULL, 0, (yyvsp[0].str_val), '\0');}
#line 1950 "parser.c"
    break;

  case 85: /* const: NIL  */
#line 268 "parser.y"
           {(yyval.ex) = create_expr(nil_e, NULL, NULL, 0, "lempesis", '\0');}
#line 1956 "parser.c"
    break;

  case 86: /* const: TRUE_KW  */
#line 269 "parser.y"
               {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '1');}
#line 1962 "parser.c"
    break;

  case 87: /* const: FALSE_KW  */
#line 270 "parser.y"
                {(yyval.ex) = create_expr(constbool_e, NULL, NULL, 0, "", '0');}
#line 1968 "parser.c"
    break;

  case 88: /* idlist_id: ID  */
#line 273 "parser.y"
              { 

  SymbolTableEntry *entry_l = NULL;

  manage_lib_function((yyvsp[0].str_val), print_errors);

  entry = lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, scope, SCOPE);
  entry_l = lookup(symtable, lists, (yyvsp[0].str_val), FORMAL, scope + 1, SCOPE);
  
  manage_id_list(symtable, lists, entry, entry_l, (yyvsp[0].str_val), print_errors, yylineno);
}
#line 1984 "parser.c"
    break;

  case 89: /* open_for: FOR  */
#line 285 "parser.y"
              {for_loop++;}
#line 1990 "parser.c"
    break;

  case 90: /* open_while: WHILE  */
#line 287 "parser.y"
                  {while_loop++;}
#line 1996 "parser.c"
    break;

  case 91: /* open_if: IF  */
#line 289 "parser.y"
            {if_stmt++;}
#line 2002 "parser.c"
    break;

  case 92: /* idlist: idlist_id  */
#line 291 "parser.y"
                  {;}
#line 2008 "parser.c"
    break;

  case 93: /* idlist: idlist_id COMMA idlist  */
#line 292 "parser.y"
                               {;}
#line 2014 "parser.c"
    break;

  case 94: /* ifstmt: open_if LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt  */
#line 295 "parser.y"
                                                             {if_stmt--;}
#line 2020 "parser.c"
    break;

  case 95: /* ifstmt: open_if LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt  */
#line 296 "parser.y"
                                                                       {if_stmt--;}
#line 2026 "parser.c"
    break;

  case 96: /* $@8: %empty  */
#line 299 "parser.y"
                                                              {in_loop++;}
#line 2032 "parser.c"
    break;

  case 97: /* whilestmt: open_while LEFT_PARENTHESIS expr RIGHT_PARENTHESIS $@8 stmt  */
#line 299 "parser.y"
                                                                               {in_loop--; while_loop--;}
#line 2038 "parser.c"
    break;

  case 98: /* $@9: %empty  */
#line 302 "parser.y"
                                                                                          {in_loop++;}
#line 2044 "parser.c"
    break;

  case 99: /* forstmt: open_for LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS $@9 stmt  */
#line 302 "parser.y"
                                                                                                             {in_loop--; for_loop--;}
#line 2050 "parser.c"
    break;

  case 100: /* $@10: %empty  */
#line 305 "parser.y"
                      { manage_return(print_errors);}
#line 2056 "parser.c"
    break;

  case 101: /* returnstmt: RETURN_KW $@10 SEMICOLON  */
#line 305 "parser.y"
                                                                {;}
#line 2062 "parser.c"
    break;

  case 102: /* $@11: %empty  */
#line 307 "parser.y"
            { manage_return(print_errors);}
#line 2068 "parser.c"
    break;

  case 103: /* returnstmt: RETURN_KW $@11 expr SEMICOLON  */
#line 307 "parser.y"
                                                           { is_return_kw = 1;}
#line 2074 "parser.c"
    break;


#line 2078 "parser.c"

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

#line 309 "parser.y"


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
 
  printf("\n\n\n");

  print_quads();

  free_table(symtable);

  return 0;
}

