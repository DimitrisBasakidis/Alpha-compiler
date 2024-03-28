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

#include "utilities/symbol_table.h"
#include "utilities/structs.h"

int yylex(void);
int yyerror(const char *error_msg);

int scope = 0;
int func_in_between = 0;
int is_return_kw = 0;
int from_func_call = 0;
int in_loop = 0;
int from_elist = 0;


int is_local_kw = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

SymTable *symtable;
scopeLists *lists;
size_t nfuncs = 0U;
SymbolTableEntry *entry;



#line 105 "parser.c"

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
  YYSYMBOL_idlist = 82,                    /* idlist  */
  YYSYMBOL_ifstmt = 83,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 84,                 /* whilestmt  */
  YYSYMBOL_85_8 = 85,                      /* $@8  */
  YYSYMBOL_forstmt = 86,                   /* forstmt  */
  YYSYMBOL_87_9 = 87,                      /* $@9  */
  YYSYMBOL_returnstmt = 88,                /* returnstmt  */
  YYSYMBOL_89_10 = 89,                     /* $@10  */
  YYSYMBOL_90_11 = 90                      /* $@11  */
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
#define YYLAST   525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

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
       0,    69,    69,    72,    73,    77,    78,    79,    80,    81,
      82,    92,   103,   104,   105,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     124,   125,   126,   127,   139,   151,   162,   173,   177,   247,
     284,   315,   316,   317,   320,   324,   362,   375,   378,   379,
     380,   381,   384,   384,   385,   385,   386,   389,   390,   393,
     396,   399,   400,   401,   404,   405,   408,   409,   409,   413,
     417,   417,   418,   418,   421,   422,   431,   476,   476,   477,
     477,   480,   481,   482,   483,   484,   485,   488,   527,   528,
     531,   532,   535,   535,   538,   538,   541,   541,   551,   551
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
  "idlist", "ifstmt", "whilestmt", "$@8", "forstmt", "$@9", "returnstmt",
  "$@10", "$@11", YY_NULLPTR
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

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     194,  -144,  -144,  -144,  -144,   250,   250,    12,    12,     4,
     242,  -144,   -13,    22,     0,     1,     5,    39,    14,    15,
      27,    40,  -144,  -144,  -144,    48,   194,  -144,   330,  -144,
    -144,  -144,    89,  -144,    10,  -144,  -144,    30,  -144,  -144,
    -144,  -144,  -144,  -144,    -1,  -144,    23,    36,    10,    36,
     250,   293,    53,    55,    51,   378,    56,   194,    57,  -144,
     250,   250,   250,  -144,  -144,    58,   250,  -144,  -144,  -144,
    -144,  -144,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,  -144,   250,  -144,  -144,    88,
     250,   -15,    90,   250,  -144,     2,    64,    91,   250,  -144,
    -144,    74,  -144,    67,   146,  -144,   393,   408,    92,  -144,
     346,   480,   492,   504,   504,   189,   189,   189,   189,    -1,
      -1,  -144,  -144,  -144,   467,  -144,   423,   116,   250,  -144,
    -144,  -144,  -144,   445,   250,  -144,  -144,    87,    94,    67,
     250,  -144,  -144,   250,  -144,   194,  -144,   250,  -144,  -144,
      96,    99,  -144,   100,   101,   128,  -144,   312,  -144,   102,
      97,   194,   362,   250,  -144,  -144,  -144,  -144,   101,  -144,
    -144,   194,  -144,   250,   108,  -144,  -144,   109,  -144,  -144,
     194,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    81,    44,    83,    82,     0,     0,     0,     0,    63,
       0,    14,    70,     0,     0,     0,     0,    75,    98,     0,
       0,     0,    85,    86,    84,     0,     2,     4,     0,    29,
      15,    37,    39,    47,    40,    41,    12,     0,    13,    43,
       6,     7,     8,     9,    31,    30,     0,    33,     0,    35,
       0,    61,     0,     0,    66,     0,     0,     0,     0,    46,
       0,     0,    63,    74,    76,     0,     0,    10,    11,    45,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,    34,    36,     0,
       0,     0,     0,     0,    52,     0,     0,     0,    63,    64,
      65,     0,    32,    42,     0,    73,     0,     0,     0,    97,
       0,    28,    27,    25,    26,    21,    22,    23,    24,    16,
      17,    19,    18,    20,    38,    48,     0,     0,    63,    55,
      57,    58,    50,     0,    63,    87,    79,    88,     0,     0,
       0,    62,    67,    63,    71,     0,    92,     0,    99,    49,
       0,     0,    51,     0,     0,     0,    77,     0,    68,     0,
      90,     0,     0,    63,    59,    53,    80,    89,     0,    69,
      56,     0,    93,    63,     0,    78,    91,     0,    60,    94,
       0,    95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,    84,   -24,    -5,  -144,  -144,  -144,     6,  -144,
      16,  -144,  -144,  -144,  -144,  -144,   -45,  -144,    42,  -144,
    -144,  -143,  -144,  -144,  -144,  -144,    -7,  -144,  -144,  -144,
    -144,   -11,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   134,    91,   129,   130,   131,    52,    35,    53,   158,
      54,    36,    57,    58,    64,    37,    38,   168,   154,    39,
     137,   138,    40,    41,   161,    42,   180,    43,    65,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    45,    71,    56,    51,    55,   135,     1,     2,     3,
       4,   166,   127,    47,    49,   128,     2,   108,    82,    83,
      84,   -72,     5,    48,    48,   175,    59,     6,     7,     8,
      60,    61,     9,   136,    10,    62,    92,    50,    93,    96,
      94,    13,    46,    63,    69,    97,   -96,    67,    70,    13,
      21,    22,    23,   141,    24,   106,   107,    51,    21,    68,
      95,   110,    89,   -54,    90,    17,   -54,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      71,   124,    99,   151,   100,   126,   101,   103,   133,   153,
     109,   105,   125,    51,   132,   139,    86,   143,   159,    72,
      73,    74,    75,    76,    77,    78,    79,    50,    80,    81,
      82,    83,    84,    87,    88,    89,   -54,    90,   174,   -54,
     150,   160,   155,    51,   147,   156,   163,   140,   177,    51,
     164,   165,   135,   170,    12,   157,   171,   172,    51,   178,
     179,   104,   162,   142,   167,     0,     0,   176,     0,     1,
       2,     3,     4,     0,     0,     0,   181,     0,    51,     0,
       0,     0,     0,     0,     5,     0,     0,     0,    51,     6,
       7,     8,     0,     0,     9,     0,    10,     0,    11,    12,
     144,     0,     0,    13,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,     1,     2,     3,
       4,   -97,   -97,   -97,   -97,     0,    80,    81,    82,    83,
      84,     0,     5,     0,     0,     0,     0,     6,     7,     8,
       0,     0,     9,     0,    10,     0,    11,    12,     0,     0,
       0,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,     1,     2,     3,     4,     0,
       0,     0,     0,     1,     2,     3,     4,     0,     0,     0,
       5,     0,     0,     0,     0,     6,     7,     8,     5,     0,
       9,     0,    10,     6,     7,     8,     0,     0,     9,    13,
      10,     0,     0,     0,    17,     0,     0,    13,    21,    22,
      23,     0,    24,     0,     0,     0,    21,    22,    23,     0,
      24,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    98,    80,
      81,    82,    83,    84,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,   169,    80,    81,    82,
      83,    84,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    85,    80,    81,    82,    83,    84,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,   148,    80,
      81,    82,    83,    84,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,   173,    80,    81,    82,    83,    84,
       0,    72,    73,    74,    75,    76,    77,    78,    79,   102,
      80,    81,    82,    83,    84,     0,    72,    73,    74,    75,
      76,    77,    78,    79,   145,    80,    81,    82,    83,    84,
       0,    72,    73,    74,    75,    76,    77,    78,    79,   146,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,   149,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,   152,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    73,
      74,    75,    76,    77,    78,    79,     0,    80,    81,    82,
      83,    84,    74,    75,    76,    77,    78,    79,     0,    80,
      81,    82,    83,    84,   -97,   -97,    76,    77,    78,    79,
       0,    80,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
       5,     6,    26,    10,     9,    10,     4,     3,     4,     5,
       6,   154,    27,     7,     8,    30,     4,    62,    19,    20,
      21,    34,    18,     7,     8,   168,     4,    23,    24,    25,
      30,    30,    28,    31,    30,    30,    26,    33,    28,    46,
      30,    37,    30,     4,     4,    50,    32,    32,     0,    37,
      46,    47,    48,    98,    50,    60,    61,    62,    46,    32,
      30,    66,    26,    27,    28,    42,    30,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     104,    86,    29,   128,    29,    90,    35,    31,    93,   134,
      32,    34,     4,    98,     4,    31,     7,    30,   143,     8,
       9,    10,    11,    12,    13,    14,    15,    33,    17,    18,
      19,    20,    21,    24,    25,    26,    27,    28,   163,    30,
       4,   145,    35,   128,    32,    31,    30,    36,   173,   134,
      31,    31,     4,    31,    33,   140,    39,   161,   143,    31,
      31,    57,   147,   101,   155,    -1,    -1,   171,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,   180,    -1,   163,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,   173,    23,
      24,    25,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    -1,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,     3,     4,     5,
       6,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      21,    -1,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    33,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    18,    -1,
      28,    -1,    30,    23,    24,    25,    -1,    -1,    28,    37,
      30,    -1,    -1,    -1,    42,    -1,    -1,    37,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    35,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    34,    17,    18,    19,
      20,    21,    -1,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,    32,    17,    18,    19,    20,    21,    -1,    -1,
       8,     9,    10,    11,    12,    13,    14,    15,    32,    17,
      18,    19,    20,    21,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    32,    17,    18,    19,    20,    21,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    31,
      17,    18,    19,    20,    21,    -1,     8,     9,    10,    11,
      12,    13,    14,    15,    31,    17,    18,    19,    20,    21,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    31,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    21,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    21,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    10,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    18,    23,    24,    25,    28,
      30,    32,    33,    37,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    68,    72,    76,    77,    80,
      83,    84,    86,    88,    55,    55,    30,    59,    61,    59,
      33,    55,    67,    69,    71,    55,    77,    73,    74,     4,
      30,    30,    30,     4,    75,    89,    90,    32,    32,     4,
       0,    54,     8,     9,    10,    11,    12,    13,    14,    15,
      17,    18,    19,    20,    21,    32,     7,    24,    25,    26,
      28,    63,    26,    28,    30,    30,    77,    55,    35,    29,
      29,    35,    31,    31,    53,    34,    55,    55,    67,    32,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,     4,    55,    27,    30,    64,
      65,    66,     4,    55,    62,     4,    31,    81,    82,    31,
      36,    67,    69,    30,    34,    31,    31,    32,    32,    29,
       4,    67,    29,    67,    79,    35,    31,    55,    70,    67,
      54,    85,    55,    30,    31,    31,    72,    82,    78,    34,
      31,    39,    54,    32,    67,    72,    54,    67,    31,    31,
      87,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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
      77,    80,    80,    80,    80,    80,    80,    81,    82,    82,
      83,    83,    85,    84,    87,    86,    89,    88,    90,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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
       5,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     7,     0,     6,     0,    10,     0,     3,     0,     4
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
#line 69 "parser.y"
                    {}
#line 1378 "parser.c"
    break;

  case 3: /* statements: statements stmt  */
#line 72 "parser.y"
                            {;}
#line 1384 "parser.c"
    break;

  case 5: /* stmt: expr SEMICOLON  */
#line 77 "parser.y"
                     {}
#line 1390 "parser.c"
    break;

  case 6: /* stmt: ifstmt  */
#line 78 "parser.y"
               {}
#line 1396 "parser.c"
    break;

  case 7: /* stmt: whilestmt  */
#line 79 "parser.y"
                  {}
#line 1402 "parser.c"
    break;

  case 8: /* stmt: forstmt  */
#line 80 "parser.y"
                {}
#line 1408 "parser.c"
    break;

  case 9: /* stmt: returnstmt  */
#line 81 "parser.y"
                   {}
#line 1414 "parser.c"
    break;

  case 10: /* stmt: BRK SEMICOLON  */
#line 82 "parser.y"
                      {if (in_loop == 0){
                          printf("Use of");
                          printf("\033[31m");
                          printf(" break ");
                          printf("\033[0m");
                          printf(" while not in loop");
                         printf(" line: %d\n", yylineno);
                         exit(TRUE);

                              }}
#line 1429 "parser.c"
    break;

  case 11: /* stmt: CONTINUE SEMICOLON  */
#line 92 "parser.y"
                           {if (in_loop == 0){
                
                          printf("Use of");
                          printf("\033[31m");
                          printf(" continue ");
                          printf("\033[0m");
                          printf(" while not in loop");
                         printf(" line: %d\n", yylineno);
                         exit(TRUE);

                              }}
#line 1445 "parser.c"
    break;

  case 12: /* stmt: block  */
#line 103 "parser.y"
              {}
#line 1451 "parser.c"
    break;

  case 13: /* stmt: funcdef  */
#line 104 "parser.y"
                {}
#line 1457 "parser.c"
    break;

  case 14: /* stmt: SEMICOLON  */
#line 105 "parser.y"
                  {}
#line 1463 "parser.c"
    break;

  case 15: /* expr: assignexpr  */
#line 108 "parser.y"
                 {;}
#line 1469 "parser.c"
    break;

  case 16: /* expr: expr PLUS expr  */
#line 109 "parser.y"
                     {;}
#line 1475 "parser.c"
    break;

  case 17: /* expr: expr MINUS expr  */
#line 110 "parser.y"
                      {;}
#line 1481 "parser.c"
    break;

  case 18: /* expr: expr SLASH expr  */
#line 111 "parser.y"
                      {;}
#line 1487 "parser.c"
    break;

  case 19: /* expr: expr MULTIPLY expr  */
#line 112 "parser.y"
                         {;}
#line 1493 "parser.c"
    break;

  case 20: /* expr: expr MODULO expr  */
#line 113 "parser.y"
                       {;}
#line 1499 "parser.c"
    break;

  case 21: /* expr: expr GREATER_THAN expr  */
#line 114 "parser.y"
                             {;}
#line 1505 "parser.c"
    break;

  case 22: /* expr: expr GREATER_EQUAL expr  */
#line 115 "parser.y"
                              {;}
#line 1511 "parser.c"
    break;

  case 23: /* expr: expr LESSER_THAN expr  */
#line 116 "parser.y"
                            {;}
#line 1517 "parser.c"
    break;

  case 24: /* expr: expr LESSER_EQUAL expr  */
#line 117 "parser.y"
                             {;}
#line 1523 "parser.c"
    break;

  case 25: /* expr: expr EQUAL expr  */
#line 118 "parser.y"
                      {;}
#line 1529 "parser.c"
    break;

  case 26: /* expr: expr NOT_EQUAL expr  */
#line 119 "parser.y"
                          {;}
#line 1535 "parser.c"
    break;

  case 27: /* expr: expr AND expr  */
#line 120 "parser.y"
                    {;}
#line 1541 "parser.c"
    break;

  case 28: /* expr: expr OR expr  */
#line 121 "parser.y"
                   {;}
#line 1547 "parser.c"
    break;

  case 29: /* expr: term  */
#line 122 "parser.y"
           {;}
#line 1553 "parser.c"
    break;

  case 30: /* term: NOT expr  */
#line 124 "parser.y"
                {;}
#line 1559 "parser.c"
    break;

  case 31: /* term: MINUS expr  */
#line 125 "parser.y"
                 {;}
#line 1565 "parser.c"
    break;

  case 32: /* term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 126 "parser.y"
                                              {;}
#line 1571 "parser.c"
    break;

  case 33: /* term: INCREMENT lvalue  */
#line 127 "parser.y"
                       {
      entry = lookup(symtable, lists, (yyvsp[0].str_val), (lookup_lib_func((yyvsp[0].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          printf("cannot increment %s function", (entry->type == USERFUNC) ? "user" : "library");
          printf("\033[31m");
          printf(" %s", (yyvsp[0].str_val));
          printf("\033[0m");
          printf(" line: %d\n", yylineno);
          exit(TRUE); 
      }
    }
#line 1588 "parser.c"
    break;

  case 34: /* term: lvalue INCREMENT  */
#line 139 "parser.y"
                       {
      entry = lookup(symtable, lists, (yyvsp[-1].str_val), (lookup_lib_func((yyvsp[-1].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          printf("cannot increment %s function", (entry->type == USERFUNC) ? "user" : "library");
          printf("\033[31m");
          printf(" %s", (yyvsp[-1].str_val));
          printf("\033[0m");
          printf(" line: %d\n", yylineno);
          exit(TRUE); 
      }
    }
#line 1605 "parser.c"
    break;

  case 35: /* term: DECREMENT lvalue  */
#line 151 "parser.y"
                       {
      entry = lookup(symtable, lists, (yyvsp[0].str_val), (lookup_lib_func((yyvsp[0].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          printf("cannot decrement %s function", (entry->type == USERFUNC) ? "user" : "library");
          printf("\033[31m");
          printf(" %s", (yyvsp[0].str_val));
          printf("\033[0m");
          printf(" line: %d\n", yylineno);
          exit(TRUE); 
      }
    }
#line 1621 "parser.c"
    break;

  case 36: /* term: lvalue DECREMENT  */
#line 162 "parser.y"
                       {entry = lookup(symtable, lists, (yyvsp[-1].str_val), (lookup_lib_func((yyvsp[-1].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          printf("cannot decrement %s function", (entry->type == USERFUNC) ? "user" : "library");
          printf("\033[31m");
          printf(" %s", (yyvsp[-1].str_val));
          printf("\033[0m");
          printf(" line: %d\n", yylineno);
          exit(TRUE); 
      }
    }
#line 1637 "parser.c"
    break;

  case 37: /* term: primary  */
#line 173 "parser.y"
              {;}
#line 1643 "parser.c"
    break;

  case 38: /* assignexpr: lvalue ASSIGN expr  */
#line 177 "parser.y"
                               { 

  entry = lookup(symtable, lists, (yyvsp[-2].str_val), (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);

  if (entry == NULL) {
    printf("from func call %d %s\n", from_func_call, (yyvsp[-2].str_val));
    if (from_func_call) {
      printf("accessing undefined function ");
      printf("\033[31m");
      printf(" %s", (yyvsp[-2].str_val));
      printf("\033[0m");
      printf(" line: %d\n", yylineno);
      exit(TRUE); 
    }
    SymbolTableEntry *node = create_node((yyvsp[-2].str_val), scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);
  } else {
    printf("FUNC IN BETWEEN :: %d , %d, %d %d\n", func_in_between, entry->value.varVal->scope ,scope,from_func_call);
   if((func_in_between == 1  || entry->value.varVal->scope >= scope)){
    printf("here %d %d\n",entry->value.varVal->scope, scope);
    switch (entry->type) {
      case LOCALVAR:
      if (entry->value.varVal->scope == scope) {
        if (is_local_kw == 1 && entry->value.varVal->line != yylineno) 
        {
          printf("redefinition of variable ");
          printf("\033[31m");
          printf(" %s", (yyvsp[-2].str_val));
          printf("\033[0m");
          printf(" line: %d\n", yylineno);
          exit(TRUE); 
        }
      } else {
        printf("cant access variable outside of scope ");
        printf("\033[31m");
        printf(" %s", (yyvsp[-2].str_val));
        printf("\033[0m");
        printf(" line: %d\n", yylineno);
        exit(TRUE);  
      }
      break;
      case LIBFUNC:
      case USERFUNC: 
        if (from_func_call) break;
        printf("redefining %s function:", (entry->type == LIBFUNC) ? "library" : "user");
        printf("\033[31m");
        printf(" %s", (yyvsp[-2].str_val));
        printf("\033[0m");
        printf(" line: %d\n", yylineno);
        exit(TRUE); 

      case FORMAL:
        if (entry->value.varVal->scope != scope) {
          printf("cant access formal argument outside of scope ");
          printf("\033[31m");
          printf(" %s", (yyvsp[-2].str_val));
          printf("\033[0m");
          printf(" line: %d\n", yylineno);
          exit(TRUE);
        }
        
    }
    }
  }
  is_local_kw = 0;
  if(from_func_call>0) from_func_call--;
}
#line 1716 "parser.c"
    break;

  case 39: /* primary: lvalue  */
#line 247 "parser.y"
                { 
  entry = lookup(symtable, lists, (yyvsp[0].str_val), (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);
  printf("ENTRYY :: %p\n", entry);
  if (entry == NULL) {
    printf("%s, %d, line %d\n", "a1", from_elist, yylineno);
    if (from_elist) {
      printf("lookup %p\n", lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, scope, HASH));
      printf("using undefined variable as call argument");
      printf("\033[31m");
      printf(" %s", (yyvsp[0].str_val));
      printf("\033[0m");
      printf(" line: %d\n", yylineno);
      exit(TRUE);
    }
    SymbolTableEntry *node = create_node((yyvsp[0].str_val), scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);
  } else {
    
    switch (entry->type) {

      case LIBFUNC:
      case USERFUNC: 
        if (entry->value.varVal->scope == scope && is_return_kw == 0) {
          printf("redefining %s function:", (entry->type == LIBFUNC) ? "library" : "user");
          printf("\033[31m");
          printf(" %s", (yyvsp[0].str_val));
          printf("\033[0m");
          printf(" line: %d\n", yylineno);
          exit(TRUE);
        }        
    }
    
  };
  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
#line 1758 "parser.c"
    break;

  case 40: /* primary: call  */
#line 284 "parser.y"
       { 

    entry = lookup(symtable, lists, (yyvsp[0].str_val), (lookup_lib_func((yyvsp[0].str_val)) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

    SymbolTableEntry *temp = NULL;
    if (entry == NULL) {
        printf("calling undefined function " );
        printf("\033[31m");
        printf(" %s", (yyvsp[0].str_val));
        printf("\033[0m");
        printf(" line: %d\n", yylineno);
        exit(TRUE);  
     } else {

    switch (entry->type) {
      
      case LOCALVAR:
      case GLOBALVAR:

        temp = is_func(lists, (yyvsp[0].str_val), scope);
        // printf("temp scope %d %d\n", temp->value.funcVal->scope, scope);
        if (temp != NULL && temp->value.funcVal->scope <= scope) break;
        printf("calling %s variable as a function ", (entry->type == LOCALVAR) ? "local" : "global");
        printf("\033[31m");
        printf(" %s", (yyvsp[0].str_val));
        printf("\033[0m");
        printf(" line: %d\n", yylineno);
        exit(TRUE);  
    }
  };
}
#line 1794 "parser.c"
    break;

  case 41: /* primary: objectdef  */
#line 315 "parser.y"
                  {;}
#line 1800 "parser.c"
    break;

  case 42: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 316 "parser.y"
                                                   {;}
#line 1806 "parser.c"
    break;

  case 43: /* primary: const  */
#line 317 "parser.y"
              {;}
#line 1812 "parser.c"
    break;

  case 44: /* lvalue: ID  */
#line 320 "parser.y"
           { // ELEGXOYME STON HASHTABLE AN UPARXEI TO ONOMA TOU ID(print error msg gia redefining lib kai user functions) KAI EIANI ACTVIE ALLWS VAZOYME TO ID STO HASHTABLE.
          (yyval.str_val) = (yyvsp[0].str_val);
           }
#line 1820 "parser.c"
    break;

  case 45: /* lvalue: LOCAL ID  */
#line 324 "parser.y"
                 { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 
        entry = lookup(symtable, lists, (yyvsp[0].str_val), LOCALVAR, scope, SCOPE); 
        is_local_kw = 1;
        if (lookup_lib_func((yyvsp[0].str_val)) == TRUE) {
            printf("shadowing library function: ");
            printf("\033[31m");
            printf(" %s", (yyvsp[0].str_val));
            printf("\033[0m");
            printf(" line: %d\n", yylineno);
            exit(TRUE);  
        }

        if (entry == NULL) {
            SymbolTableEntry *node = create_node((yyvsp[0].str_val), scope, yylineno, LOCALVAR, ACTIVE);
            insert_symbol(symtable, node);
            insert_to_scope(lists, node, scope);
        } else {
          printf("entr->rype %d %d\n", entry->type, entry->value.funcVal->line);
          if (entry->type == USERFUNC) {
            printf("redefining user function: ");
            printf("\033[31m");
            printf(" %s", (yyvsp[0].str_val));
            printf("\033[0m");
            printf(" line: %d\n", yylineno);
            exit(TRUE);  
          } else if (entry->type == FORMAL) {
            printf("redefining formal argument: ");
            printf("\033[31m");
            printf(" %s", (yyvsp[0].str_val));
            printf("\033[0m");
            printf(" line: %d\n", yylineno);
            exit(TRUE);
          }
        }
        (yyval.str_val) = (yyvsp[0].str_val);

}
#line 1862 "parser.c"
    break;

  case 46: /* lvalue: DOUBLE_COLON ID  */
#line 362 "parser.y"
                        { 
        entry = lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, 0, SCOPE); 

        if (entry == NULL) {
          printf("No global variable");
          printf("\033[31m");
          printf(" ::%s", (yyvsp[0].str_val));
          printf("\033[0m");
          printf(" exists  line: %d\n", yylineno);
          exit(TRUE);  
        } 
        (yyval.str_val) = (yyvsp[0].str_val);
                        }
#line 1880 "parser.c"
    break;

  case 47: /* lvalue: member  */
#line 375 "parser.y"
               {;}
#line 1886 "parser.c"
    break;

  case 48: /* member: lvalue DOT ID  */
#line 378 "parser.y"
                      {;}
#line 1892 "parser.c"
    break;

  case 49: /* member: lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET  */
#line 379 "parser.y"
                                                             {;}
#line 1898 "parser.c"
    break;

  case 50: /* member: call DOT ID  */
#line 380 "parser.y"
                    {from_func_call++;}
#line 1904 "parser.c"
    break;

  case 51: /* member: call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET  */
#line 381 "parser.y"
                                                           {;}
#line 1910 "parser.c"
    break;

  case 52: /* $@1: %empty  */
#line 384 "parser.y"
                            {from_elist = 1;}
#line 1916 "parser.c"
    break;

  case 53: /* call: call LEFT_PARENTHESIS $@1 elist RIGHT_PARENTHESIS  */
#line 384 "parser.y"
                                                                       {;}
#line 1922 "parser.c"
    break;

  case 54: /* $@2: %empty  */
#line 385 "parser.y"
               {;}
#line 1928 "parser.c"
    break;

  case 55: /* call: lvalue $@2 callsuffix  */
#line 385 "parser.y"
                              {;}
#line 1934 "parser.c"
    break;

  case 56: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 386 "parser.y"
                                                                                            {;}
#line 1940 "parser.c"
    break;

  case 57: /* callsuffix: normcall  */
#line 389 "parser.y"
                     {;}
#line 1946 "parser.c"
    break;

  case 58: /* callsuffix: methodcall  */
#line 390 "parser.y"
                       {;}
#line 1952 "parser.c"
    break;

  case 59: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 393 "parser.y"
                                                   {printf("here %d\n", yylineno);}
#line 1958 "parser.c"
    break;

  case 60: /* methodcall: DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 396 "parser.y"
                                                                   {printf("here444 %d\n", yylineno);}
#line 1964 "parser.c"
    break;

  case 61: /* elist: expr  */
#line 399 "parser.y"
            {;}
#line 1970 "parser.c"
    break;

  case 62: /* elist: expr COMMA elist  */
#line 400 "parser.y"
                        { (yyval.str_val) = (yyvsp[-2].str_val);}
#line 1976 "parser.c"
    break;

  case 63: /* elist: %empty  */
#line 401 "parser.y"
       {;}
#line 1982 "parser.c"
    break;

  case 64: /* objectdef: LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET  */
#line 404 "parser.y"
                                                          {;}
#line 1988 "parser.c"
    break;

  case 65: /* objectdef: LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET  */
#line 405 "parser.y"
                                                            {;}
#line 1994 "parser.c"
    break;

  case 66: /* indexed: indexedelem  */
#line 408 "parser.y"
                     {;}
#line 2000 "parser.c"
    break;

  case 67: /* $@3: %empty  */
#line 409 "parser.y"
                                   {;}
#line 2006 "parser.c"
    break;

  case 68: /* indexed: indexedelem COMMA indexed $@3  */
#line 410 "parser.y"
       {;}
#line 2012 "parser.c"
    break;

  case 69: /* indexedelem: LEFT_BRACKET expr COLON expr RIGHT_BRACKET  */
#line 413 "parser.y"
                                                        {;}
#line 2018 "parser.c"
    break;

  case 70: /* $@4: %empty  */
#line 417 "parser.y"
                    {scope++;}
#line 2024 "parser.c"
    break;

  case 71: /* block: LEFT_BRACKET $@4 statements RIGHT_BRACKET  */
#line 417 "parser.y"
                                                        {hide_scope(lists, scope--);}
#line 2030 "parser.c"
    break;

  case 72: /* $@5: %empty  */
#line 418 "parser.y"
                    {scope++;}
#line 2036 "parser.c"
    break;

  case 73: /* block: LEFT_BRACKET $@5 RIGHT_BRACKET  */
#line 418 "parser.y"
                                             {hide_scope(lists, scope--);}
#line 2042 "parser.c"
    break;

  case 74: /* fname: ID  */
#line 421 "parser.y"
          { (yyval.str_val) = (yyvsp[0].str_val);}
#line 2048 "parser.c"
    break;

  case 75: /* fname: %empty  */
#line 422 "parser.y"
          {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          (yyval.str_val) = temp;
          }
#line 2060 "parser.c"
    break;

  case 76: /* func_id: FUNCTION fname  */
#line 431 "parser.y"
                       { // elegxoume ama uparxoyn ta entries sto hashtable kai einai active, an nai ektypwnoyme ta katallhla error messages
// alliws ta vazoume sto table
  entry = lookup(symtable, lists, (yyvsp[0].str_val), USERFUNC, scope, SCOPE);
  
  if (entry == NULL) {
    SymbolTableEntry *node = create_node((yyvsp[0].str_val), scope, yylineno, USERFUNC, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);
  } else {
    char *print = NULL;
    switch (entry->type) {

      case LIBFUNC:
        print = "library function";
        break;
      case USERFUNC: 
        print = "user function";
        break;

      case GLOBALVAR:
        print = "global variable";
        break; 

      case LOCALVAR: 
        print = "local variable";
        break;
      case FORMAL :
        print = "formal argument";
        break;
      default:
      print = "vaggeli agapiesai";  
      break;
    }

    printf("redefining %s:", print);
    printf("\033[31m");
    printf(" %s", (yyvsp[0].str_val));
    printf("\033[0m");
    printf(" line: %d\n", yylineno);
    exit(TRUE);

  }
}
#line 2108 "parser.c"
    break;

  case 77: /* $@6: %empty  */
#line 476 "parser.y"
                                                           {func_in_between++;}
#line 2114 "parser.c"
    break;

  case 78: /* funcdef: func_id LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS $@6 block  */
#line 476 "parser.y"
                                                                                     {func_in_between--;}
#line 2120 "parser.c"
    break;

  case 79: /* $@7: %empty  */
#line 477 "parser.y"
                                                    {func_in_between++;}
#line 2126 "parser.c"
    break;

  case 80: /* funcdef: func_id LEFT_PARENTHESIS RIGHT_PARENTHESIS $@7 block  */
#line 477 "parser.y"
                                                                               {func_in_between--;}
#line 2132 "parser.c"
    break;

  case 81: /* const: INTEGER  */
#line 480 "parser.y"
                {;}
#line 2138 "parser.c"
    break;

  case 82: /* const: REAL  */
#line 481 "parser.y"
            { ;}
#line 2144 "parser.c"
    break;

  case 83: /* const: STRING  */
#line 482 "parser.y"
              { ;}
#line 2150 "parser.c"
    break;

  case 84: /* const: NIL  */
#line 483 "parser.y"
           {;}
#line 2156 "parser.c"
    break;

  case 85: /* const: TRUE_KW  */
#line 484 "parser.y"
               {;}
#line 2162 "parser.c"
    break;

  case 86: /* const: FALSE_KW  */
#line 485 "parser.y"
                {;}
#line 2168 "parser.c"
    break;

  case 87: /* idlist_id: ID  */
#line 488 "parser.y"
              { 

  if (lookup_lib_func((yyvsp[0].str_val)) == TRUE) {
    printf("shadowing lib function:");
    printf("\033[31m");
    printf(" %s", (yyvsp[0].str_val));
    printf("\033[0m");
    printf(" line: %d\n", yylineno);
    exit(TRUE);
  }

  entry = lookup(symtable, lists, (yyvsp[0].str_val), GLOBALVAR, scope, SCOPE);
  if (entry != NULL && entry->value.varVal->scope != 0 && entry->type == USERFUNC) {
    printf("redefining argument:");
    printf("\033[31m");
    printf(" %s", (yyvsp[0].str_val));
    printf("\033[0m");
    printf(" line: %d\n", yylineno);
    exit(TRUE);
  } 
  

  entry = lookup(symtable, lists, (yyvsp[0].str_val), FORMAL, scope + 1, SCOPE); //check for same args 
  printf("entry :; %p, line %d\n", entry,yylineno);
  if (entry != NULL) {
    printf("redefining argument:");
    printf("\033[31m");
    printf(" %s", (yyvsp[0].str_val));
    printf("\033[0m");
    printf(" line: %d\n", yylineno);
    exit(TRUE);
  } 

  
  SymbolTableEntry *node = create_node((yyvsp[0].str_val), scope + 1, yylineno, FORMAL, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, scope + 1);
}
#line 2211 "parser.c"
    break;

  case 88: /* idlist: idlist_id  */
#line 527 "parser.y"
                  {;}
#line 2217 "parser.c"
    break;

  case 89: /* idlist: idlist_id COMMA idlist  */
#line 528 "parser.y"
                               {;}
#line 2223 "parser.c"
    break;

  case 90: /* ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt  */
#line 531 "parser.y"
                                                        {/**/}
#line 2229 "parser.c"
    break;

  case 91: /* ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt  */
#line 532 "parser.y"
                                                                  {;}
#line 2235 "parser.c"
    break;

  case 92: /* $@8: %empty  */
#line 535 "parser.y"
                                                         {in_loop = 1;}
#line 2241 "parser.c"
    break;

  case 93: /* whilestmt: WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS $@8 stmt  */
#line 535 "parser.y"
                                                                            {in_loop=0;}
#line 2247 "parser.c"
    break;

  case 94: /* $@9: %empty  */
#line 538 "parser.y"
                                                                                     {in_loop = 1;}
#line 2253 "parser.c"
    break;

  case 95: /* forstmt: FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS $@9 stmt  */
#line 538 "parser.y"
                                                                                                          {in_loop=0;}
#line 2259 "parser.c"
    break;

  case 96: /* $@10: %empty  */
#line 541 "parser.y"
                      {if (func_in_between == 0){
                          printf("Use of");
                          printf("\033[31m");
                          printf(" return ");
                          printf("\033[0m");
                          printf(" while not in function");
                         printf(" line: %d\n", yylineno);
                         exit(TRUE);

                              }}
#line 2274 "parser.c"
    break;

  case 97: /* returnstmt: RETURN_KW $@10 SEMICOLON  */
#line 550 "parser.y"
                                          {;}
#line 2280 "parser.c"
    break;

  case 98: /* $@11: %empty  */
#line 551 "parser.y"
                      {if (func_in_between == 0){
                
                          printf("Use of");
                          printf("\033[31m");
                          printf(" return ");
                          printf("\033[0m");
                          printf(" while not in function");
                         printf(" line: %d\n", yylineno);
                         exit(TRUE);

                              }}
#line 2296 "parser.c"
    break;

  case 99: /* returnstmt: RETURN_KW $@11 expr SEMICOLON  */
#line 561 "parser.y"
                                                { is_return_kw = 1;}
#line 2302 "parser.c"
    break;


#line 2306 "parser.c"

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

#line 564 "parser.y"


int yyerror(const char *error_msg) {
  fprintf(stderr, "something went\033[31m bad\033[0m %s, line %d\n", error_msg, yylineno);
  exit(0);
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
