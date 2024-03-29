/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     ZERO = 259,
     REALNUM = 260,
     PROGRAM = 261,
     INT = 262,
     REAL = 263,
     BOOL = 264,
     PROCEDURE = 265,
     FUNCTION = 266,
     BEGINN = 267,
     END = 268,
     IF = 269,
     THEN = 270,
     ELSE = 271,
     WHILE = 272,
     DO = 273,
     FOR = 274,
     TO = 275,
     DOWNTO = 276,
     CASE = 277,
     RETURN = 278,
     ANDTHEN = 279,
     ORELSE = 280,
     IDENTIFIER = 281,
     MINUS = 282,
     MULTIPLY = 283,
     DIVISION = 284,
     GREATERTHAN = 285,
     GREATEREQUAL = 286,
     NOTEQUAL = 287,
     EQUAL = 288,
     LESSTHAN = 289,
     LESSEQUAL = 290,
     COMMA = 291,
     SEMICOLON = 292,
     COLON = 293,
     DECLARE = 294,
     OPPAR = 295,
     CPAR = 296,
     FALSE = 297,
     TRUE = 298,
     ERROR = 299,
     IF_PREC = 300,
     PLUS = 301
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 54 "parser.y"

  char* strValue;
  struct eval* evalptr;


/* Line 2058 of yacc.c  */
#line 109 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
