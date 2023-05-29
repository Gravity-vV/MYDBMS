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
#line 1 "sql.y"

#include "sql.h"

char database[64]={0};

int yylex();
int yyparse();

void yyerror (const char *str) 
{
	fprintf(stderr, "error: %s\n", str);		// error function
}

int yywrap() 
{
	return 1;
}
// main function 
int main() 
{
	printf("SQL>");
	return	yyparse(); // calling parse funtion 
} 


#line 97 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    SELECT = 258,                  /* SELECT  */
    FROM = 259,                    /* FROM  */
    WHERE = 260,                   /* WHERE  */
    AND = 261,                     /* AND  */
    OR = 262,                      /* OR  */
    DROP = 263,                    /* DROP  */
    DELETE = 264,                  /* DELETE  */
    TABLE = 265,                   /* TABLE  */
    CREATE = 266,                  /* CREATE  */
    INTO = 267,                    /* INTO  */
    VALUES = 268,                  /* VALUES  */
    INSERT = 269,                  /* INSERT  */
    UPDATE = 270,                  /* UPDATE  */
    SET = 271,                     /* SET  */
    SHOW = 272,                    /* SHOW  */
    DATABASE = 273,                /* DATABASE  */
    DATABASES = 274,               /* DATABASES  */
    TABLES = 275,                  /* TABLES  */
    EXIT = 276,                    /* EXIT  */
    USE = 277,                     /* USE  */
    NUMBER = 278,                  /* NUMBER  */
    STRING = 279,                  /* STRING  */
    ID = 280,                      /* ID  */
    INT = 281,                     /* INT  */
    CHAR = 282,                    /* CHAR  */
    DOUBLE = 283,                  /* DOUBLE  */
    DOUBLEN = 284                  /* DOUBLEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define SELECT 258
#define FROM 259
#define WHERE 260
#define AND 261
#define OR 262
#define DROP 263
#define DELETE 264
#define TABLE 265
#define CREATE 266
#define INTO 267
#define VALUES 268
#define INSERT 269
#define UPDATE 270
#define SET 271
#define SHOW 272
#define DATABASE 273
#define DATABASES 274
#define TABLES 275
#define EXIT 276
#define USE 277
#define NUMBER 278
#define STRING 279
#define ID 280
#define INT 281
#define CHAR 282
#define DOUBLE 283
#define DOUBLEN 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "sql.y"
  
	int intval;   
	double dval;
  	char *strval;
  	struct hyper_items_def *Citemsval;
  	struct value_def *valueval;
  	struct item_def *itemval;
  	struct conditions_def *conval;
  	struct table_def *tbval;
  	struct upcon_def *updateval;

#line 220 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SELECT = 3,                     /* SELECT  */
  YYSYMBOL_FROM = 4,                       /* FROM  */
  YYSYMBOL_WHERE = 5,                      /* WHERE  */
  YYSYMBOL_AND = 6,                        /* AND  */
  YYSYMBOL_OR = 7,                         /* OR  */
  YYSYMBOL_DROP = 8,                       /* DROP  */
  YYSYMBOL_DELETE = 9,                     /* DELETE  */
  YYSYMBOL_TABLE = 10,                     /* TABLE  */
  YYSYMBOL_CREATE = 11,                    /* CREATE  */
  YYSYMBOL_INTO = 12,                      /* INTO  */
  YYSYMBOL_VALUES = 13,                    /* VALUES  */
  YYSYMBOL_INSERT = 14,                    /* INSERT  */
  YYSYMBOL_UPDATE = 15,                    /* UPDATE  */
  YYSYMBOL_SET = 16,                       /* SET  */
  YYSYMBOL_SHOW = 17,                      /* SHOW  */
  YYSYMBOL_DATABASE = 18,                  /* DATABASE  */
  YYSYMBOL_DATABASES = 19,                 /* DATABASES  */
  YYSYMBOL_TABLES = 20,                    /* TABLES  */
  YYSYMBOL_EXIT = 21,                      /* EXIT  */
  YYSYMBOL_USE = 22,                       /* USE  */
  YYSYMBOL_NUMBER = 23,                    /* NUMBER  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_ID = 25,                        /* ID  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_CHAR = 27,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 28,                    /* DOUBLE  */
  YYSYMBOL_DOUBLEN = 29,                   /* DOUBLEN  */
  YYSYMBOL_30_n_ = 30,                     /* '\n'  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '<'  */
  YYSYMBOL_39_ = 39,                       /* ">="  */
  YYSYMBOL_40_ = 40,                       /* "<="  */
  YYSYMBOL_41_ = 41,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_statements = 43,                /* statements  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_nextsql = 45,                   /* nextsql  */
  YYSYMBOL_usesql = 46,                    /* usesql  */
  YYSYMBOL_showsql = 47,                   /* showsql  */
  YYSYMBOL_createsql = 48,                 /* createsql  */
  YYSYMBOL_selectsql = 49,                 /* selectsql  */
  YYSYMBOL_deletesql = 50,                 /* deletesql  */
  YYSYMBOL_insertsql = 51,                 /* insertsql  */
  YYSYMBOL_updatesql = 52,                 /* updatesql  */
  YYSYMBOL_dropsql = 53,                   /* dropsql  */
  YYSYMBOL_exitsql = 54,                   /* exitsql  */
  YYSYMBOL_create_items = 55,              /* create_items  */
  YYSYMBOL_hyper_items = 56,               /* hyper_items  */
  YYSYMBOL_item = 57,                      /* item  */
  YYSYMBOL_item_list = 58,                 /* item_list  */
  YYSYMBOL_value = 59,                     /* value  */
  YYSYMBOL_value_list = 60,                /* value_list  */
  YYSYMBOL_comparator = 61,                /* comparator  */
  YYSYMBOL_condition = 62,                 /* condition  */
  YYSYMBOL_conditions = 63,                /* conditions  */
  YYSYMBOL_tables = 64,                    /* tables  */
  YYSYMBOL_up_cond = 65,                   /* up_cond  */
  YYSYMBOL_up_conds = 66                   /* up_conds  */
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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      30,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,     2,     2,     2,
      32,    33,    34,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      38,    36,    37,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    61,    63,    67,    70,    74,    78,
      83,    87,    90,    93,    97,   101,   106,   110,   115,   119,
     123,   126,   130,   135,   141,   147,   155,   158,   163,   170,
     173,   178,   184,   190,   197,   200,   205,   206,   207,   208,
     209,   210,   212,   221,   230,   240,   243,   246,   252,   259,
     264,   270,   277,   284,   292,   295
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
  "\"end of file\"", "error", "\"invalid token\"", "SELECT", "FROM",
  "WHERE", "AND", "OR", "DROP", "DELETE", "TABLE", "CREATE", "INTO",
  "VALUES", "INSERT", "UPDATE", "SET", "SHOW", "DATABASE", "DATABASES",
  "TABLES", "EXIT", "USE", "NUMBER", "STRING", "ID", "INT", "CHAR",
  "DOUBLE", "DOUBLEN", "'\\n'", "';'", "'('", "')'", "'*'", "','", "'='",
  "'>'", "'<'", "\">=\"", "\"<=\"", "'!'", "$accept", "statements",
  "statement", "nextsql", "usesql", "showsql", "createsql", "selectsql",
  "deletesql", "insertsql", "updatesql", "dropsql", "exitsql",
  "create_items", "hyper_items", "item", "item_list", "value",
  "value_list", "comparator", "condition", "conditions", "tables",
  "up_cond", "up_conds", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      43,   -20,    -7,     2,    58,    22,    28,    -4,    25,    34,
     -71,    10,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,    77,   -71,    -2,    57,    63,    83,
      84,    85,    86,    73,    56,    65,   -71,    81,   -71,   -71,
      88,    88,    89,    87,    90,    24,    91,    93,    -6,    92,
      67,    95,    96,   -71,     4,     7,   -71,    97,    98,    47,
      99,    94,   100,   101,    89,    79,   -71,    12,   -71,   -71,
     -71,    47,   102,   106,    47,   104,   -71,   -71,    47,    62,
     -71,    38,   -71,    66,   -71,    -5,   -71,    51,    15,    54,
      47,   105,    92,    55,   -71,   -71,    60,   -71,    16,   -71,
     -71,   -71,   -71,   -71,    80,    61,    47,    47,   107,   -71,
     108,   -71,   110,    94,   -71,   -71,   -71,   -71,    71,   109,
     -71,   -71,   -71,    64,   -71,   -71,   112,   113,   -71,   -71,
     -71,   -71,   -71,   -71,   114,   -71,   115,   116,   -71,   117,
      51,   118,   119,   -71,   -71,   103,   -71,   121,   -71,    51,
     -71,   -71,   -71,    72,   122,   124,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     3,    13,    12,     5,     4,     6,     8,     7,
       9,    10,    11,    38,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,    16,    17,
      15,     0,     0,     0,     0,     0,    30,    31,     0,     0,
      55,     0,    24,     0,    36,     0,    19,     0,     0,     0,
       0,     0,     0,     0,    20,    60,     0,    21,     0,    46,
      47,    48,    49,    50,     0,     0,     0,     0,     0,    33,
       0,    34,     0,     0,    41,    43,    42,    44,     0,     0,
      61,    63,    62,     0,    28,    65,     0,     0,    56,    51,
      52,    54,    53,    57,    58,    25,     0,     0,    37,     0,
       0,     0,     0,    22,    23,     0,    18,     0,    45,     0,
      29,    35,    26,     0,     0,     0,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   128,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,    31,   -71,    -1,   111,     5,     3,   -71,
     -71,   -70,   120,    68,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    84,    85,    79,    26,   117,   118,   105,
      80,    81,    54,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    93,    41,    27,    96,    23,    29,    63,    98,    71,
      38,    28,    74,     1,    24,    34,    35,    90,     2,     3,
     123,     4,   106,   107,     5,     6,    64,     7,   112,    59,
     113,     8,     9,    42,    32,    72,   133,   134,    75,    73,
      10,    56,    73,    91,   106,   107,     1,    92,   119,   128,
      42,     2,     3,    33,     4,    60,    36,     5,     6,    37,
       7,   106,   107,    25,     8,     9,   106,   107,    30,   108,
     106,   107,    23,    10,   114,   115,    31,   120,   121,    78,
     116,    40,    43,   122,   130,   131,   126,    50,    44,    49,
     132,   127,   109,   110,   111,   142,    51,    68,    99,   100,
     101,   102,   103,   104,   139,   154,   140,   140,    45,    46,
      47,    48,    52,    53,    23,    89,   129,    65,    57,    83,
     106,    58,   141,    61,    62,    69,    70,    76,    77,    82,
      86,    95,    94,    87,    97,   124,   151,   135,   145,    39,
     136,   137,   143,   144,   138,   148,   146,     0,   147,   150,
     149,   152,   153,   155,   156,     0,     0,     0,     0,     0,
     125,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88
};

static const yytype_int16 yycheck[] =
{
       1,    71,     4,    10,    74,    25,     4,    13,    78,     5,
       0,    18,     5,     3,    34,    19,    20,     5,     8,     9,
      90,    11,     6,     7,    14,    15,    32,    17,    33,     5,
      35,    21,    22,    35,    12,    31,   106,   107,    31,    35,
      30,    42,    35,    31,     6,     7,     3,    35,    33,    33,
      35,     8,     9,    25,    11,    31,    31,    14,    15,    25,
      17,     6,     7,    64,    21,    22,     6,     7,    10,    31,
       6,     7,    25,    30,    23,    24,    18,    23,    24,    32,
      29,     4,    25,    29,    23,    24,    31,    31,    25,    16,
      29,    31,    26,    27,    28,    31,    31,    30,    36,    37,
      38,    39,    40,    41,    33,    33,    35,    35,    25,    25,
      25,    25,    31,    25,    25,    36,    36,    25,    31,    25,
       6,    31,    13,    32,    31,    30,    30,    30,    30,    30,
      30,    25,    30,    32,    30,    30,    33,    30,    23,    11,
      32,    31,    30,    30,   113,   140,    30,    -1,    31,    30,
      32,    30,   149,    31,    30,    -1,    -1,    -1,    -1,    -1,
      92,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,     9,    11,    14,    15,    17,    21,    22,
      30,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    25,    34,    57,    58,    10,    18,     4,
      10,    18,    12,    25,    19,    20,    31,    25,     0,    44,
       4,     4,    35,    25,    25,    25,    25,    25,    25,    16,
      31,    31,    31,    25,    64,    64,    57,    31,    31,     5,
      31,    32,    31,    13,    32,    25,    65,    66,    30,    30,
      30,     5,    31,    35,     5,    31,    30,    30,    32,    57,
      62,    63,    30,    25,    55,    56,    30,    32,    58,    36,
       5,    31,    35,    63,    30,    25,    63,    30,    63,    36,
      37,    38,    39,    40,    41,    61,     6,     7,    31,    26,
      27,    28,    33,    35,    23,    24,    29,    59,    60,    33,
      23,    24,    29,    63,    30,    65,    31,    31,    33,    36,
      23,    24,    29,    63,    63,    30,    32,    31,    55,    33,
      35,    13,    31,    30,    30,    23,    30,    31,    59,    32,
      30,    33,    30,    60,    33,    31,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    45,    46,    47,    47,    48,    48,
      49,    49,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    55,    55,    55,    56,    56,    57,    58,
      58,    59,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     8,     5,
       6,     6,     8,     8,     5,     7,     9,    12,     6,     8,
       5,     5,     2,     2,     2,     5,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3
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
  case 14: /* nextsql: '\n'  */
#line 61 "sql.y"
                             {printf("SQL>");}
#line 1364 "y.tab.c"
    break;

  case 15: /* usesql: USE ID ';' '\n'  */
#line 63 "sql.y"
                                        {
					useDB((yyvsp[-2].strval));
		        }
#line 1372 "y.tab.c"
    break;

  case 16: /* showsql: SHOW DATABASES ';' '\n'  */
#line 67 "sql.y"
                                                {
		            showDB();
		        }
#line 1380 "y.tab.c"
    break;

  case 17: /* showsql: SHOW TABLES ';' '\n'  */
#line 70 "sql.y"
                                              {
		            showTable();
		        }
#line 1388 "y.tab.c"
    break;

  case 18: /* createsql: CREATE TABLE ID '(' hyper_items ')' ';' '\n'  */
#line 74 "sql.y"
                                                                     {//sql创建语句
                	createTable((yyvsp[-5].strval), (yyvsp[-3].Citemsval));
				}
#line 1396 "y.tab.c"
    break;

  case 19: /* createsql: CREATE DATABASE ID ';' '\n'  */
#line 78 "sql.y"
                                                             {
					strcpy(database, (yyvsp[-2].strval));
					createDB();
				}
#line 1405 "y.tab.c"
    break;

  case 20: /* selectsql: SELECT '*' FROM tables ';' '\n'  */
#line 83 "sql.y"
                                                       {
					selectWhere(NULL, (yyvsp[-2].tbval), NULL);
					printf("\n");
				}
#line 1414 "y.tab.c"
    break;

  case 21: /* selectsql: SELECT item_list FROM tables ';' '\n'  */
#line 87 "sql.y"
                                                                        {
					selectWhere((yyvsp[-4].itemval), (yyvsp[-2].tbval), NULL);
				}
#line 1422 "y.tab.c"
    break;

  case 22: /* selectsql: SELECT '*' FROM tables WHERE conditions ';' '\n'  */
#line 90 "sql.y"
                                                                                  {
					selectWhere(NULL, (yyvsp[-4].tbval), (yyvsp[-2].conval));
				}
#line 1430 "y.tab.c"
    break;

  case 23: /* selectsql: SELECT item_list FROM tables WHERE conditions ';' '\n'  */
#line 93 "sql.y"
                                                                                        { 
					selectWhere((yyvsp[-6].itemval), (yyvsp[-4].tbval), (yyvsp[-2].conval));
				}
#line 1438 "y.tab.c"
    break;

  case 24: /* deletesql: DELETE FROM ID ';' '\n'  */
#line 97 "sql.y"
                                                {
					deletes((yyvsp[-2].strval), NULL);
				}
#line 1446 "y.tab.c"
    break;

  case 25: /* deletesql: DELETE FROM ID WHERE conditions ';' '\n'  */
#line 101 "sql.y"
                                                                                { 
					deletes((yyvsp[-4].strval), (yyvsp[-2].conval));
				}
#line 1454 "y.tab.c"
    break;

  case 26: /* insertsql: INSERT INTO ID VALUES '(' value_list ')' ';' '\n'  */
#line 106 "sql.y"
                                                                          {//sql插入语句
					multiInsert((yyvsp[-6].strval), NULL, (yyvsp[-3].valueval));
				}
#line 1462 "y.tab.c"
    break;

  case 27: /* insertsql: INSERT INTO ID '(' item_list ')' VALUES '(' value_list ')' ';' '\n'  */
#line 110 "sql.y"
                                                                                                     {
					multiInsert((yyvsp[-9].strval), (yyvsp[-7].itemval), (yyvsp[-3].valueval));
				}
#line 1470 "y.tab.c"
    break;

  case 28: /* updatesql: UPDATE ID SET up_conds ';' '\n'  */
#line 115 "sql.y"
                                                        {
					updates((yyvsp[-4].strval), (yyvsp[-2].updateval), NULL);
				}
#line 1478 "y.tab.c"
    break;

  case 29: /* updatesql: UPDATE ID SET up_conds WHERE conditions ';' '\n'  */
#line 119 "sql.y"
                                                                                  {
					updates((yyvsp[-6].strval), (yyvsp[-4].updateval), (yyvsp[-2].conval));
				}
#line 1486 "y.tab.c"
    break;

  case 30: /* dropsql: DROP TABLE ID ';' '\n'  */
#line 123 "sql.y"
                                                {
					dropTable((yyvsp[-2].strval));
				}
#line 1494 "y.tab.c"
    break;

  case 31: /* dropsql: DROP DATABASE ID ';' '\n'  */
#line 126 "sql.y"
                                                            {
					dropDB((yyvsp[-2].strval));
				}
#line 1502 "y.tab.c"
    break;

  case 32: /* exitsql: EXIT ';'  */
#line 130 "sql.y"
                                 {
		            printf("exit with code 0!\n");
		            exit(0);
		        }
#line 1511 "y.tab.c"
    break;

  case 33: /* create_items: ID INT  */
#line 135 "sql.y"
                       {//该生成试返回一个结构体
					(yyval.Citemsval) = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    (yyval.Citemsval)->field = (yyvsp[-1].strval);
                    (yyval.Citemsval)->type = 0;	
                    (yyval.Citemsval)->next = NULL;	
				}
#line 1522 "y.tab.c"
    break;

  case 34: /* create_items: ID DOUBLE  */
#line 141 "sql.y"
                                            {
					(yyval.Citemsval) = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    (yyval.Citemsval)->field = (yyvsp[-1].strval);
                    (yyval.Citemsval)->type = 1;
                    (yyval.Citemsval)->next = NULL;	
				}
#line 1533 "y.tab.c"
    break;

  case 35: /* create_items: ID CHAR '(' NUMBER ')'  */
#line 147 "sql.y"
                                                        {
					(yyval.Citemsval) = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    (yyval.Citemsval)->field = (yyvsp[-4].strval);
                    (yyval.Citemsval)->type = 2;
                    (yyval.Citemsval)->next = NULL;	
				}
#line 1544 "y.tab.c"
    break;

  case 36: /* hyper_items: create_items  */
#line 155 "sql.y"
                             {
					(yyval.Citemsval) = (yyvsp[0].Citemsval);
				}
#line 1552 "y.tab.c"
    break;

  case 37: /* hyper_items: hyper_items ',' create_items  */
#line 158 "sql.y"
                                                               {//创建一个属性链表，这里左递归，属性值逆序了
					(yyval.Citemsval) = (yyvsp[0].Citemsval);
					(yyval.Citemsval)->next = (yyvsp[-2].Citemsval);				
				}
#line 1561 "y.tab.c"
    break;

  case 38: /* item: ID  */
#line 163 "sql.y"
                           {
					(yyval.itemval) = (struct item_def *)malloc(sizeof(struct item_def));
					(yyval.itemval)->field = (yyvsp[0].strval);
					(yyval.itemval)->pos = NULL;
					(yyval.itemval)->next = NULL;
				}
#line 1572 "y.tab.c"
    break;

  case 39: /* item_list: item  */
#line 170 "sql.y"
                             {
					(yyval.itemval) = (yyvsp[0].itemval);				
				}
#line 1580 "y.tab.c"
    break;

  case 40: /* item_list: item_list ',' item  */
#line 173 "sql.y"
                                                    {//产生一个只有字段组成的链表
					(yyval.itemval) = (yyvsp[0].itemval);
					(yyval.itemval)->next = (yyvsp[-2].itemval);
				}
#line 1589 "y.tab.c"
    break;

  case 41: /* value: NUMBER  */
#line 178 "sql.y"
                               {
					(yyval.valueval) = ((struct value_def *)malloc(sizeof(struct value_def)));
					(yyval.valueval)->value.intkey = (yyvsp[0].intval);
					(yyval.valueval)->type = 0;
					(yyval.valueval)->next = NULL;
				}
#line 1600 "y.tab.c"
    break;

  case 42: /* value: DOUBLEN  */
#line 184 "sql.y"
                                          {
					(yyval.valueval) = ((struct value_def *)malloc(sizeof(struct value_def)));
					(yyval.valueval)->value.dkey = (yyvsp[0].dval);
					(yyval.valueval)->type = 1;
					(yyval.valueval)->next = NULL;
				}
#line 1611 "y.tab.c"
    break;

  case 43: /* value: STRING  */
#line 190 "sql.y"
                                         {
					(yyval.valueval) = ((struct value_def *)malloc(sizeof(struct value_def)));
					strcpy((yyval.valueval)->value.skey, (yyvsp[0].strval));
					(yyval.valueval)->type = 2;
					(yyval.valueval)->next = NULL;
				}
#line 1622 "y.tab.c"
    break;

  case 44: /* value_list: value  */
#line 197 "sql.y"
                              {
					(yyval.valueval) = (yyvsp[0].valueval);
				}
#line 1630 "y.tab.c"
    break;

  case 45: /* value_list: value_list ',' value  */
#line 200 "sql.y"
                                                       {//值列表
					(yyval.valueval) = (yyvsp[0].valueval);
					(yyval.valueval)->next = (yyvsp[-2].valueval);
				}
#line 1639 "y.tab.c"
    break;

  case 46: /* comparator: '='  */
#line 205 "sql.y"
                            {(yyval.intval) = 1; }
#line 1645 "y.tab.c"
    break;

  case 47: /* comparator: '>'  */
#line 206 "sql.y"
                                      {(yyval.intval) = 2; }
#line 1651 "y.tab.c"
    break;

  case 48: /* comparator: '<'  */
#line 207 "sql.y"
                                      {(yyval.intval) = 3; }
#line 1657 "y.tab.c"
    break;

  case 49: /* comparator: ">="  */
#line 208 "sql.y"
                                       {(yyval.intval) = 4; }
#line 1663 "y.tab.c"
    break;

  case 50: /* comparator: "<="  */
#line 209 "sql.y"
                                       {(yyval.intval) = 5; }
#line 1669 "y.tab.c"
    break;

  case 51: /* comparator: '!' '='  */
#line 210 "sql.y"
                                          {(yyval.intval) = 6; }
#line 1675 "y.tab.c"
    break;

  case 52: /* condition: item comparator NUMBER  */
#line 212 "sql.y"
                                               {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->type = 0;
					(yyval.conval)->litem = (yyvsp[-2].itemval);
					(yyval.conval)->intv = (yyvsp[0].intval);
					(yyval.conval)->cmp_op = (yyvsp[-1].intval);
					(yyval.conval)->left = NULL;
					(yyval.conval)->right = NULL;
				}
#line 1689 "y.tab.c"
    break;

  case 53: /* condition: item comparator DOUBLEN  */
#line 221 "sql.y"
                                                          {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->type = 1;
					(yyval.conval)->litem = (yyvsp[-2].itemval);
					(yyval.conval)->intv = (yyvsp[0].dval);
					(yyval.conval)->cmp_op = (yyvsp[-1].intval);
					(yyval.conval)->left = NULL;
					(yyval.conval)->right = NULL;
				}
#line 1703 "y.tab.c"
    break;

  case 54: /* condition: item comparator STRING  */
#line 230 "sql.y"
                                                         {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->type = 2;
					(yyval.conval)->litem = (yyvsp[-2].itemval);
					(yyval.conval)->strv = (yyvsp[0].strval);
					(yyval.conval)->cmp_op = (yyvsp[-1].intval);
					(yyval.conval)->left = NULL;
					(yyval.conval)->right = NULL;
				}
#line 1717 "y.tab.c"
    break;

  case 55: /* conditions: condition  */
#line 240 "sql.y"
                          {
					(yyval.conval) = (yyvsp[0].conval);
				}
#line 1725 "y.tab.c"
    break;

  case 56: /* conditions: '(' conditions ')'  */
#line 243 "sql.y"
                                                    {
					(yyval.conval) = (yyvsp[-1].conval);
				}
#line 1733 "y.tab.c"
    break;

  case 57: /* conditions: conditions AND conditions  */
#line 246 "sql.y"
                                                            {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->cmp_op = 7;
					(yyval.conval)->left = (yyvsp[-2].conval);
					(yyval.conval)->right = (yyvsp[0].conval);
				}
#line 1744 "y.tab.c"
    break;

  case 58: /* conditions: conditions OR conditions  */
#line 252 "sql.y"
                                                           {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->cmp_op = 8;
					(yyval.conval)->left = (yyvsp[-2].conval);
					(yyval.conval)->right = (yyvsp[0].conval);
				}
#line 1755 "y.tab.c"
    break;

  case 59: /* tables: ID  */
#line 259 "sql.y"
                           {
					(yyval.tbval) = ((struct table_def *)malloc(sizeof(struct table_def)));
					(yyval.tbval)->table = (yyvsp[0].strval);
					(yyval.tbval)->next = NULL;
				}
#line 1765 "y.tab.c"
    break;

  case 60: /* tables: tables ',' ID  */
#line 264 "sql.y"
                                               {
					(yyval.tbval) = ((struct table_def *)malloc(sizeof(struct table_def)));
					(yyval.tbval)->table = (yyvsp[0].strval);
					(yyval.tbval)->next = (yyvsp[-2].tbval);				
				}
#line 1775 "y.tab.c"
    break;

  case 61: /* up_cond: ID '=' NUMBER  */
#line 270 "sql.y"
                                      {
					(yyval.updateval) = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					(yyval.updateval)->field = (yyvsp[-2].strval);
					(yyval.updateval)->type = 0;
					(yyval.updateval)->value.intkey = (yyvsp[0].intval);
					(yyval.updateval)->next = NULL;
				}
#line 1787 "y.tab.c"
    break;

  case 62: /* up_cond: ID '=' DOUBLEN  */
#line 277 "sql.y"
                                                 {
					(yyval.updateval) = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					(yyval.updateval)->field = (yyvsp[-2].strval);
					(yyval.updateval)->type = 1;
					(yyval.updateval)->value.dkey = (yyvsp[0].dval);
					(yyval.updateval)->next = NULL;				
				}
#line 1799 "y.tab.c"
    break;

  case 63: /* up_cond: ID '=' STRING  */
#line 284 "sql.y"
                                                {
					(yyval.updateval) = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					(yyval.updateval)->field = (yyvsp[-2].strval);
					(yyval.updateval)->type = 1;
					strcpy((yyval.updateval)->value.skey, (yyvsp[0].strval));
					(yyval.updateval)->next = NULL;				
				}
#line 1811 "y.tab.c"
    break;

  case 64: /* up_conds: up_cond  */
#line 292 "sql.y"
                                {
					(yyval.updateval) = (yyvsp[0].updateval);
				}
#line 1819 "y.tab.c"
    break;

  case 65: /* up_conds: up_conds ',' up_cond  */
#line 295 "sql.y"
                                                       {
					(yyval.updateval) = (yyvsp[0].updateval);
					(yyval.updateval)->next = (yyvsp[-2].updateval);
				}
#line 1828 "y.tab.c"
    break;


#line 1832 "y.tab.c"

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

#line 300 "sql.y"

