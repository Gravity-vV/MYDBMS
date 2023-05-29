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
    CHAR = 282                     /* CHAR  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "sql.y"
  
	int intval;   
  	char *strval;
  	struct hyper_items_def *Citemsval;
  	struct value_def *valueval;
  	struct item_def *itemval;
  	struct conditions_def *conval;
  	struct table_def *tbval;
  	struct upcon_def *updateval;

#line 215 "y.tab.c"

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
  YYSYMBOL_28_n_ = 28,                     /* '\n'  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '>'  */
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* ">="  */
  YYSYMBOL_38_ = 38,                       /* "<="  */
  YYSYMBOL_39_ = 39,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_statements = 41,                /* statements  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_nextsql = 43,                   /* nextsql  */
  YYSYMBOL_usesql = 44,                    /* usesql  */
  YYSYMBOL_showsql = 45,                   /* showsql  */
  YYSYMBOL_createsql = 46,                 /* createsql  */
  YYSYMBOL_selectsql = 47,                 /* selectsql  */
  YYSYMBOL_deletesql = 48,                 /* deletesql  */
  YYSYMBOL_insertsql = 49,                 /* insertsql  */
  YYSYMBOL_updatesql = 50,                 /* updatesql  */
  YYSYMBOL_dropsql = 51,                   /* dropsql  */
  YYSYMBOL_exitsql = 52,                   /* exitsql  */
  YYSYMBOL_create_items = 53,              /* create_items  */
  YYSYMBOL_hyper_items = 54,               /* hyper_items  */
  YYSYMBOL_item = 55,                      /* item  */
  YYSYMBOL_item_list = 56,                 /* item_list  */
  YYSYMBOL_value = 57,                     /* value  */
  YYSYMBOL_value_list = 58,                /* value_list  */
  YYSYMBOL_comparator = 59,                /* comparator  */
  YYSYMBOL_condition = 60,                 /* condition  */
  YYSYMBOL_conditions = 61,                /* conditions  */
  YYSYMBOL_tables = 62,                    /* tables  */
  YYSYMBOL_up_cond = 63,                   /* up_cond  */
  YYSYMBOL_up_conds = 64                   /* up_conds  */
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
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      28,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,     2,     2,
      30,    31,    32,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
      36,    34,    35,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    59,    61,    65,    68,    72,    76,
      81,    85,    88,    91,    95,    99,   104,   108,   113,   117,
     121,   124,   128,   133,   139,   146,   149,   154,   161,   164,
     169,   175,   182,   185,   190,   191,   192,   193,   194,   195,
     197,   206,   216,   219,   222,   228,   235,   240,   246,   253,
     261,   264
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
  "'\\n'", "';'", "'('", "')'", "'*'", "','", "'='", "'>'", "'<'",
  "\">=\"", "\"<=\"", "'!'", "$accept", "statements", "statement",
  "nextsql", "usesql", "showsql", "createsql", "selectsql", "deletesql",
  "insertsql", "updatesql", "dropsql", "exitsql", "create_items",
  "hyper_items", "item", "item_list", "value", "value_list", "comparator",
  "condition", "conditions", "tables", "up_cond", "up_conds", YY_NULLPTR
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
      37,    32,    -7,    23,    -5,    11,    24,    74,     3,    46,
     -71,     7,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,    35,   -71,    -2,    72,    80,    81,
      82,    83,    84,    28,    33,    56,   -71,    58,   -71,   -71,
      85,    85,    86,    87,    88,     4,    50,    89,    40,    90,
      76,    91,    92,   -71,     1,     9,   -71,    93,    94,   -13,
      95,    99,    97,    96,    86,    78,   -71,    14,   -71,   -71,
     -71,   -13,   100,   102,   -13,   101,   -71,   -71,   -13,    38,
     -71,    49,   -71,    69,   -71,    48,   -71,    75,    51,    77,
     -13,   103,    90,    54,   -71,   -71,    60,   -71,    19,   -71,
     -71,   -71,   -71,   -71,    98,    79,   -13,   -13,   105,   -71,
     104,   106,    99,   -71,   -71,   -71,    55,   117,   -71,   -71,
      62,   -71,   -71,   108,   109,   -71,   -71,   -71,   -71,   -71,
     107,   -71,   115,   111,   -71,   112,    75,   110,   114,   -71,
     -71,   113,   -71,   118,   -71,    75,   -71,   -71,   -71,    59,
     116,   119,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     3,    13,    12,     5,     4,     6,     8,     7,
       9,    10,    11,    37,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,    16,    17,
      15,     0,     0,     0,     0,     0,    30,    31,     0,     0,
      52,     0,    24,     0,    35,     0,    19,     0,     0,     0,
       0,     0,     0,     0,    20,    57,     0,    21,     0,    44,
      45,    46,    47,    48,     0,     0,     0,     0,     0,    33,
       0,     0,     0,    40,    41,    42,     0,     0,    58,    59,
       0,    28,    61,     0,     0,    53,    49,    50,    51,    54,
      55,    25,     0,     0,    36,     0,     0,     0,     0,    22,
      23,     0,    18,     0,    43,     0,    29,    34,    26,     0,
       0,     0,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   132,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,     2,   -71,    -1,   120,    12,     5,   -71,
     -71,   -70,   121,    57,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    84,    85,    79,    26,   115,   116,   105,
      80,    81,    54,    66,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    93,    41,    27,    96,    30,    71,    38,    98,    59,
       1,    28,    23,    31,    74,     2,     3,    78,     4,    90,
     120,     5,     6,    32,     7,   106,   107,    29,     8,     9,
      72,    42,    36,    60,    73,    10,   129,   130,    75,    40,
       1,    56,    73,    91,    49,     2,     3,    92,     4,    33,
     125,     5,     6,    63,     7,   106,   107,    23,     8,     9,
     106,   107,    50,    25,    24,    10,   106,   107,   106,   107,
      64,    37,    99,   100,   101,   102,   103,   104,   108,   111,
      61,   112,   117,   123,    42,    51,   135,    52,   136,   124,
     150,   138,   136,    34,    35,   109,   110,    43,   113,   114,
     118,   119,   127,   128,    68,    44,    45,    46,    47,    48,
      53,    23,    89,   106,   134,    65,    57,    58,    62,    69,
      70,    76,    77,    82,    83,    86,    87,    95,    94,    97,
     137,   121,   126,   131,   132,   133,   139,   140,   141,   142,
     145,   143,   146,    39,   147,   151,   148,   152,   144,   122,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88
};

static const yytype_int16 yycheck[] =
{
       1,    71,     4,    10,    74,    10,     5,     0,    78,     5,
       3,    18,    25,    18,     5,     8,     9,    30,    11,     5,
      90,    14,    15,    12,    17,     6,     7,     4,    21,    22,
      29,    33,    29,    29,    33,    28,   106,   107,    29,     4,
       3,    42,    33,    29,    16,     8,     9,    33,    11,    25,
      31,    14,    15,    13,    17,     6,     7,    25,    21,    22,
       6,     7,    29,    64,    32,    28,     6,     7,     6,     7,
      30,    25,    34,    35,    36,    37,    38,    39,    29,    31,
      30,    33,    31,    29,    33,    29,    31,    29,    33,    29,
      31,    29,    33,    19,    20,    26,    27,    25,    23,    24,
      23,    24,    23,    24,    28,    25,    25,    25,    25,    25,
      25,    25,    34,     6,   112,    25,    29,    29,    29,    28,
      28,    28,    28,    28,    25,    28,    30,    25,    28,    28,
      13,    28,    34,    28,    30,    29,    28,    28,    23,    28,
      30,    29,    28,    11,    31,    29,    28,    28,   136,    92,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,     9,    11,    14,    15,    17,    21,    22,
      28,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    25,    32,    55,    56,    10,    18,     4,
      10,    18,    12,    25,    19,    20,    29,    25,     0,    42,
       4,     4,    33,    25,    25,    25,    25,    25,    25,    16,
      29,    29,    29,    25,    62,    62,    55,    29,    29,     5,
      29,    30,    29,    13,    30,    25,    63,    64,    28,    28,
      28,     5,    29,    33,     5,    29,    28,    28,    30,    55,
      60,    61,    28,    25,    53,    54,    28,    30,    56,    34,
       5,    29,    33,    61,    28,    25,    61,    28,    61,    34,
      35,    36,    37,    38,    39,    59,     6,     7,    29,    26,
      27,    31,    33,    23,    24,    57,    58,    31,    23,    24,
      61,    28,    63,    29,    29,    31,    34,    23,    24,    61,
      61,    28,    30,    29,    53,    31,    33,    13,    29,    28,
      28,    23,    28,    29,    57,    30,    28,    31,    28,    58,
      31,    29,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    43,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     8,     5,
       6,     6,     8,     8,     5,     7,     9,    12,     6,     8,
       5,     5,     2,     2,     5,     1,     3,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     3
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
#line 59 "sql.y"
                             {printf("SQL>");}
#line 1358 "y.tab.c"
    break;

  case 15: /* usesql: USE ID ';' '\n'  */
#line 61 "sql.y"
                                        {
					useDB((yyvsp[-2].strval));
		        }
#line 1366 "y.tab.c"
    break;

  case 16: /* showsql: SHOW DATABASES ';' '\n'  */
#line 65 "sql.y"
                                                {
		            showDB();
		        }
#line 1374 "y.tab.c"
    break;

  case 17: /* showsql: SHOW TABLES ';' '\n'  */
#line 68 "sql.y"
                                              {
		            showTable();
		        }
#line 1382 "y.tab.c"
    break;

  case 18: /* createsql: CREATE TABLE ID '(' hyper_items ')' ';' '\n'  */
#line 72 "sql.y"
                                                                     {//sql创建语句
                	createTable((yyvsp[-5].strval), (yyvsp[-3].Citemsval));
				}
#line 1390 "y.tab.c"
    break;

  case 19: /* createsql: CREATE DATABASE ID ';' '\n'  */
#line 76 "sql.y"
                                                             {
					strcpy(database, (yyvsp[-2].strval));
					createDB();
				}
#line 1399 "y.tab.c"
    break;

  case 20: /* selectsql: SELECT '*' FROM tables ';' '\n'  */
#line 81 "sql.y"
                                                       {
					selectWhere(NULL, (yyvsp[-2].tbval), NULL);
					printf("\n");
				}
#line 1408 "y.tab.c"
    break;

  case 21: /* selectsql: SELECT item_list FROM tables ';' '\n'  */
#line 85 "sql.y"
                                                                        {
					selectWhere((yyvsp[-4].itemval), (yyvsp[-2].tbval), NULL);
				}
#line 1416 "y.tab.c"
    break;

  case 22: /* selectsql: SELECT '*' FROM tables WHERE conditions ';' '\n'  */
#line 88 "sql.y"
                                                                                  {
					selectWhere(NULL, (yyvsp[-4].tbval), (yyvsp[-2].conval));
				}
#line 1424 "y.tab.c"
    break;

  case 23: /* selectsql: SELECT item_list FROM tables WHERE conditions ';' '\n'  */
#line 91 "sql.y"
                                                                                        { 
					selectWhere((yyvsp[-6].itemval), (yyvsp[-4].tbval), (yyvsp[-2].conval));
				}
#line 1432 "y.tab.c"
    break;

  case 24: /* deletesql: DELETE FROM ID ';' '\n'  */
#line 95 "sql.y"
                                                {
					deletes((yyvsp[-2].strval), NULL);
				}
#line 1440 "y.tab.c"
    break;

  case 25: /* deletesql: DELETE FROM ID WHERE conditions ';' '\n'  */
#line 99 "sql.y"
                                                                                { 
					deletes((yyvsp[-4].strval), (yyvsp[-2].conval));
				}
#line 1448 "y.tab.c"
    break;

  case 26: /* insertsql: INSERT INTO ID VALUES '(' value_list ')' ';' '\n'  */
#line 104 "sql.y"
                                                                          {//sql插入语句
					multiInsert((yyvsp[-6].strval), NULL, (yyvsp[-3].valueval));
				}
#line 1456 "y.tab.c"
    break;

  case 27: /* insertsql: INSERT INTO ID '(' item_list ')' VALUES '(' value_list ')' ';' '\n'  */
#line 108 "sql.y"
                                                                                                     {
					multiInsert((yyvsp[-9].strval), (yyvsp[-7].itemval), (yyvsp[-3].valueval));
				}
#line 1464 "y.tab.c"
    break;

  case 28: /* updatesql: UPDATE ID SET up_conds ';' '\n'  */
#line 113 "sql.y"
                                                        {
					updates((yyvsp[-4].strval), (yyvsp[-2].updateval), NULL);
				}
#line 1472 "y.tab.c"
    break;

  case 29: /* updatesql: UPDATE ID SET up_conds WHERE conditions ';' '\n'  */
#line 117 "sql.y"
                                                                                  {
					updates((yyvsp[-6].strval), (yyvsp[-4].updateval), (yyvsp[-2].conval));
				}
#line 1480 "y.tab.c"
    break;

  case 30: /* dropsql: DROP TABLE ID ';' '\n'  */
#line 121 "sql.y"
                                                {
					dropTable((yyvsp[-2].strval));
				}
#line 1488 "y.tab.c"
    break;

  case 31: /* dropsql: DROP DATABASE ID ';' '\n'  */
#line 124 "sql.y"
                                                            {
					dropDB((yyvsp[-2].strval));
				}
#line 1496 "y.tab.c"
    break;

  case 32: /* exitsql: EXIT ';'  */
#line 128 "sql.y"
                                 {
		            printf("exit with code 0!\n");
		            exit(0);
		        }
#line 1505 "y.tab.c"
    break;

  case 33: /* create_items: ID INT  */
#line 133 "sql.y"
                       {//该生成试返回一个结构体
					(yyval.Citemsval) = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    (yyval.Citemsval)->field = (yyvsp[-1].strval);
                    (yyval.Citemsval)->type = 0;	
                    (yyval.Citemsval)->next = NULL;	
				}
#line 1516 "y.tab.c"
    break;

  case 34: /* create_items: ID CHAR '(' NUMBER ')'  */
#line 139 "sql.y"
                                                        {
					(yyval.Citemsval) = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    (yyval.Citemsval)->field = (yyvsp[-4].strval);
                    (yyval.Citemsval)->type = 1;
                    (yyval.Citemsval)->next = NULL;	
				}
#line 1527 "y.tab.c"
    break;

  case 35: /* hyper_items: create_items  */
#line 146 "sql.y"
                             {
					(yyval.Citemsval) = (yyvsp[0].Citemsval);
				}
#line 1535 "y.tab.c"
    break;

  case 36: /* hyper_items: hyper_items ',' create_items  */
#line 149 "sql.y"
                                                               {//创建一个属性链表，这里左递归，属性值逆序了
					(yyval.Citemsval) = (yyvsp[0].Citemsval);
					(yyval.Citemsval)->next = (yyvsp[-2].Citemsval);				
				}
#line 1544 "y.tab.c"
    break;

  case 37: /* item: ID  */
#line 154 "sql.y"
                           {
					(yyval.itemval) = (struct item_def *)malloc(sizeof(struct item_def));
					(yyval.itemval)->field = (yyvsp[0].strval);
					(yyval.itemval)->pos = NULL;
					(yyval.itemval)->next = NULL;
				}
#line 1555 "y.tab.c"
    break;

  case 38: /* item_list: item  */
#line 161 "sql.y"
                             {
					(yyval.itemval) = (yyvsp[0].itemval);				
				}
#line 1563 "y.tab.c"
    break;

  case 39: /* item_list: item_list ',' item  */
#line 164 "sql.y"
                                                    {//产生一个只有字段组成的链表
					(yyval.itemval) = (yyvsp[0].itemval);
					(yyval.itemval)->next = (yyvsp[-2].itemval);
				}
#line 1572 "y.tab.c"
    break;

  case 40: /* value: NUMBER  */
#line 169 "sql.y"
                               {
					(yyval.valueval) = ((struct value_def *)malloc(sizeof(struct value_def)));
					(yyval.valueval)->value.intkey = (yyvsp[0].intval);
					(yyval.valueval)->type = 0;
					(yyval.valueval)->next = NULL;
				}
#line 1583 "y.tab.c"
    break;

  case 41: /* value: STRING  */
#line 175 "sql.y"
                                         {
					(yyval.valueval) = ((struct value_def *)malloc(sizeof(struct value_def)));
					strcpy((yyval.valueval)->value.skey, (yyvsp[0].strval));
					(yyval.valueval)->type = 1;
					(yyval.valueval)->next = NULL;
				}
#line 1594 "y.tab.c"
    break;

  case 42: /* value_list: value  */
#line 182 "sql.y"
                              {
					(yyval.valueval) = (yyvsp[0].valueval);
				}
#line 1602 "y.tab.c"
    break;

  case 43: /* value_list: value_list ',' value  */
#line 185 "sql.y"
                                                       {//值列表
					(yyval.valueval) = (yyvsp[0].valueval);
					(yyval.valueval)->next = (yyvsp[-2].valueval);
				}
#line 1611 "y.tab.c"
    break;

  case 44: /* comparator: '='  */
#line 190 "sql.y"
                            {(yyval.intval) = 1; }
#line 1617 "y.tab.c"
    break;

  case 45: /* comparator: '>'  */
#line 191 "sql.y"
                                      {(yyval.intval) = 2; }
#line 1623 "y.tab.c"
    break;

  case 46: /* comparator: '<'  */
#line 192 "sql.y"
                                      {(yyval.intval) = 3; }
#line 1629 "y.tab.c"
    break;

  case 47: /* comparator: ">="  */
#line 193 "sql.y"
                                       {(yyval.intval) = 4; }
#line 1635 "y.tab.c"
    break;

  case 48: /* comparator: "<="  */
#line 194 "sql.y"
                                       {(yyval.intval) = 5; }
#line 1641 "y.tab.c"
    break;

  case 49: /* comparator: '!' '='  */
#line 195 "sql.y"
                                          {(yyval.intval) = 6; }
#line 1647 "y.tab.c"
    break;

  case 50: /* condition: item comparator NUMBER  */
#line 197 "sql.y"
                                               {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->type = 0;
					(yyval.conval)->litem = (yyvsp[-2].itemval);
					(yyval.conval)->intv = (yyvsp[0].intval);
					(yyval.conval)->cmp_op = (yyvsp[-1].intval);
					(yyval.conval)->left = NULL;
					(yyval.conval)->right = NULL;
				}
#line 1661 "y.tab.c"
    break;

  case 51: /* condition: item comparator STRING  */
#line 206 "sql.y"
                                                         {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->type = 1;
					(yyval.conval)->litem = (yyvsp[-2].itemval);
					(yyval.conval)->strv = (yyvsp[0].strval);
					(yyval.conval)->cmp_op = (yyvsp[-1].intval);
					(yyval.conval)->left = NULL;
					(yyval.conval)->right = NULL;
				}
#line 1675 "y.tab.c"
    break;

  case 52: /* conditions: condition  */
#line 216 "sql.y"
                          {
					(yyval.conval) = (yyvsp[0].conval);
				}
#line 1683 "y.tab.c"
    break;

  case 53: /* conditions: '(' conditions ')'  */
#line 219 "sql.y"
                                                    {
					(yyval.conval) = (yyvsp[-1].conval);
				}
#line 1691 "y.tab.c"
    break;

  case 54: /* conditions: conditions AND conditions  */
#line 222 "sql.y"
                                                            {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->cmp_op = 7;
					(yyval.conval)->left = (yyvsp[-2].conval);
					(yyval.conval)->right = (yyvsp[0].conval);
				}
#line 1702 "y.tab.c"
    break;

  case 55: /* conditions: conditions OR conditions  */
#line 228 "sql.y"
                                                           {
					(yyval.conval) = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					(yyval.conval)->cmp_op = 8;
					(yyval.conval)->left = (yyvsp[-2].conval);
					(yyval.conval)->right = (yyvsp[0].conval);
				}
#line 1713 "y.tab.c"
    break;

  case 56: /* tables: ID  */
#line 235 "sql.y"
                           {
					(yyval.tbval) = ((struct table_def *)malloc(sizeof(struct table_def)));
					(yyval.tbval)->table = (yyvsp[0].strval);
					(yyval.tbval)->next = NULL;
				}
#line 1723 "y.tab.c"
    break;

  case 57: /* tables: tables ',' ID  */
#line 240 "sql.y"
                                               {
					(yyval.tbval) = ((struct table_def *)malloc(sizeof(struct table_def)));
					(yyval.tbval)->table = (yyvsp[0].strval);
					(yyval.tbval)->next = (yyvsp[-2].tbval);				
				}
#line 1733 "y.tab.c"
    break;

  case 58: /* up_cond: ID '=' NUMBER  */
#line 246 "sql.y"
                                      {
					(yyval.updateval) = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					(yyval.updateval)->field = (yyvsp[-2].strval);
					(yyval.updateval)->type = 0;
					(yyval.updateval)->value.intkey = (yyvsp[0].intval);
					(yyval.updateval)->next = NULL;
				}
#line 1745 "y.tab.c"
    break;

  case 59: /* up_cond: ID '=' STRING  */
#line 253 "sql.y"
                                                {
					(yyval.updateval) = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					(yyval.updateval)->field = (yyvsp[-2].strval);
					(yyval.updateval)->type = 1;
					strcpy((yyval.updateval)->value.skey, (yyvsp[0].strval));
					(yyval.updateval)->next = NULL;				
				}
#line 1757 "y.tab.c"
    break;

  case 60: /* up_conds: up_cond  */
#line 261 "sql.y"
                                {
					(yyval.updateval) = (yyvsp[0].updateval);
				}
#line 1765 "y.tab.c"
    break;

  case 61: /* up_conds: up_conds ',' up_cond  */
#line 264 "sql.y"
                                                       {
					(yyval.updateval) = (yyvsp[0].updateval);
					(yyval.updateval)->next = (yyvsp[-2].updateval);
				}
#line 1774 "y.tab.c"
    break;


#line 1778 "y.tab.c"

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

#line 269 "sql.y"

