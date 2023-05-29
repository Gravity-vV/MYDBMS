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

#line 137 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
