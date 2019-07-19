/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include "all.h"
#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include "stack.h"
//#include "stack_arith.h"


extern FILE* yyin;
extern char* tempString;
struct Stack* tblptrStack;

void loadTmpVal(char * theTmp);
void saveTmpVal(char* theTmp);
void topPlsLoclNum(int quad);
char* mkString(char* input);
char* getRelop(char* str);
char* assignBool(Node * trueList , Node * falseList , char* var , bool isVar, bool mkItEval);
char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID);
char* functionCall(char* id , char * explist);
Eval* strToEval(char* input);
char * newQuad();
char * newTemp();
char * newVTemp();
char * newPTemp();
char * newITemp();
char* createLable();
void defaultGotoGen();
Eval * idToEval(char * idName);

char num[5];
int returnQuads[30];
int lastOfReturnQuad=0;
int tt=0;
int v=0;
int I=0;
int currentType;
char* returnType;
bool errorFlag=false;
int quadTmp;
struct SymbolTable* mainSymTbl;


int yylex();
void yyerror(char* error);

struct SymbolTable* secondArg(struct SymbolTable* a,struct SymbolTable* b );
void mkSymTblFncPrc(char * name);

/* Line 371 of yacc.c  */
#line 121 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 54 "parser.y"

  char* strValue;
  struct eval* evalptr;


/* Line 387 of yacc.c  */
#line 216 "parser.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 244 "parser.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   367

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    20,    21,    23,    26,    28,    30,
      32,    34,    36,    38,    40,    41,    46,    48,    52,    56,
      57,    58,    74,    75,    89,    90,    91,   109,   110,   126,
     127,   128,   130,   134,   135,   138,   140,   144,   148,   150,
     152,   157,   159,   160,   165,   171,   181,   188,   189,   190,
     203,   204,   205,   218,   219,   226,   227,   232,   234,   235,
     240,   245,   249,   253,   257,   261,   265,   269,   271,   273,
     275,   277,   282,   283,   285,   287,   291,   293,   295,   297,
     299,   301,   306,   312,   319,   321,   325,   326,   328,   330,
     332,   334,   336
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,     6,    26,    49,    37,    50,    70,    83,
      37,    -1,     6,    26,    49,    37,    70,    83,    37,    -1,
      -1,    51,    -1,    50,    51,    -1,    56,    -1,    57,    -1,
      61,    -1,     7,    -1,     8,    -1,     9,    -1,    26,    -1,
      -1,    26,    54,    39,    82,    -1,    53,    -1,    55,    36,
      53,    -1,    52,    55,    37,    -1,    -1,    -1,    10,    26,
      66,    40,    67,    41,    83,    58,    50,    59,    70,    83,
      65,    83,    37,    -1,    -1,    10,    26,    66,    40,    67,
      41,    83,    60,    70,    83,    65,    83,    37,    -1,    -1,
      -1,    11,    26,    66,    40,    67,    41,    38,    52,    83,
      62,    50,    63,    70,    83,    65,    83,    37,    -1,    -1,
      11,    26,    66,    40,    67,    41,    38,    52,    83,    64,
      70,    83,    65,    83,    37,    -1,    -1,    -1,    68,    -1,
      67,    37,    68,    -1,    -1,    52,    69,    -1,    26,    -1,
      69,    36,    26,    -1,    12,    71,    13,    -1,    73,    -1,
      73,    -1,    71,    37,    83,    73,    -1,    26,    -1,    -1,
      72,    39,    74,    82,    -1,    14,    82,    15,    83,    70,
      -1,    14,    82,    15,    83,    70,    16,    81,    83,    70,
      -1,    17,    83,    82,    18,    83,    70,    -1,    -1,    -1,
      19,    72,    39,    82,    20,    75,    83,    82,    76,    18,
      70,    83,    -1,    -1,    -1,    19,    72,    39,    82,    21,
      77,    83,    82,    78,    18,    70,    83,    -1,    -1,    22,
      82,    79,    86,    83,    13,    -1,    -1,    23,    82,    80,
      65,    -1,    82,    -1,    -1,    82,    24,    83,    82,    -1,
      82,    25,    83,    82,    -1,    82,    46,    82,    -1,    82,
      27,    82,    -1,    82,    28,    82,    -1,    82,    29,    82,
      -1,    40,    82,    41,    -1,    85,    88,    85,    -1,    84,
      -1,    43,    -1,    42,    -1,    72,    -1,    26,    40,    87,
      41,    -1,    -1,     3,    -1,     5,    -1,    40,    82,    41,
      -1,     3,    -1,     5,    -1,    43,    -1,    42,    -1,    72,
      -1,    26,    40,    87,    41,    -1,     3,    38,    83,    70,
      37,    -1,    86,     3,    38,    83,    70,    37,    -1,    82,
      -1,    87,    36,    82,    -1,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   133,   150,   161,   164,   169,   173,   176,
     181,   188,   195,   204,   209,   209,   230,   233,   238,   244,
     252,   244,   269,   269,   294,   303,   294,   326,   326,   357,
     374,   382,   383,   384,   387,   392,   396,   402,   408,   414,
     419,   426,   432,   432,   454,   460,   480,   490,   501,   490,
     522,   536,   522,   557,   557,   579,   579,   589,   592,   598,
     602,   609,   618,   627,   634,   641,   644,   655,   658,   663,
     668,   686,   692,   697,   701,   707,   720,   721,   722,   723,
     724,   734,   739,   745,   760,   775,   789,   795,   796,   797,
     798,   799,   800
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ZERO", "REALNUM", "PROGRAM",
  "INT", "REAL", "BOOL", "PROCEDURE", "FUNCTION", "BEGINN", "END", "IF",
  "THEN", "ELSE", "WHILE", "DO", "FOR", "TO", "DOWNTO", "CASE", "RETURN",
  "ANDTHEN", "ORELSE", "IDENTIFIER", "MINUS", "MULTIPLY", "DIVISION",
  "GREATERTHAN", "GREATEREQUAL", "NOTEQUAL", "EQUAL", "LESSTHAN",
  "LESSEQUAL", "COMMA", "SEMICOLON", "COLON", "DECLARE", "OPPAR", "CPAR",
  "FALSE", "TRUE", "ERROR", "IF_PREC", "PLUS", "$accept", "program", "PM",
  "declist", "dec", "type", "iddec", "$@1", "idlist", "vardec", "procdec",
  "$@2", "$@3", "$@4", "funcdec", "$@5", "$@6", "$@7", "ret", "NP",
  "paramdecs", "paramdec", "paramlist", "block", "stmtlist", "lvalue",
  "stmt", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "NS",
  "exp", "M", "constant", "boolexp", "caseelement", "explist", "relop", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    50,    50,    51,    51,    51,
      52,    52,    52,    53,    54,    53,    55,    55,    56,    58,
      59,    57,    60,    57,    62,    63,    61,    64,    61,    65,
      66,    67,    67,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    74,    73,    73,    73,    73,    75,    76,    73,
      77,    78,    73,    79,    73,    80,    73,    73,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    86,    86,    87,    87,    87,    88,    88,    88,
      88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     7,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     3,     3,     0,
       0,    15,     0,    13,     0,     0,    17,     0,    15,     0,
       0,     1,     3,     0,     2,     1,     3,     3,     1,     1,
       4,     1,     0,     4,     5,     9,     6,     0,     0,    12,
       0,     0,    12,     0,     6,     0,     4,     1,     0,     4,
       4,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     6,     1,     3,     0,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     0,    73,    74,    10,
      11,    12,     0,     0,     0,     0,    72,     0,     0,     0,
      41,     0,    69,    68,     0,     5,     0,     7,     8,     9,
      72,    70,    38,    57,    67,     0,    30,    30,     0,    39,
      70,     0,     0,    41,     0,    53,    55,    86,     0,     6,
      72,    13,    16,     0,     0,    42,    72,    72,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    37,    72,    72,     0,     0,     0,    29,    84,     0,
      65,     0,     0,     0,    18,     3,     0,     0,     0,    62,
      63,    64,    61,    76,    77,    41,     0,    79,    78,    80,
      66,    33,    33,     0,     0,    72,     0,     0,    72,    56,
       0,    71,     2,     0,    17,    43,    59,    60,    86,     0,
       0,     0,    31,     0,    40,    44,     0,    47,    50,    72,
       0,     0,    85,    15,     0,    75,    35,    34,     0,    72,
       0,    58,    46,    72,    72,     0,    72,    54,    81,     0,
      32,    22,     0,    72,     0,     0,     0,     0,    36,     0,
       0,    72,     0,    48,    51,    82,     0,    20,    72,    27,
      45,     0,     0,    83,     0,    29,     0,     0,     0,     0,
      72,    72,    25,    72,    72,    72,    29,     0,     0,    29,
      49,    52,    72,    23,    72,    72,     0,    29,     0,    21,
      72,    28,     0,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    24,    25,    26,    52,    82,    53,    27,
      28,   159,   174,   160,    29,   176,   188,   177,   109,    69,
     121,   122,   137,    30,    38,    40,    32,    86,   143,   171,
     144,   172,    76,    77,   153,    33,    42,    34,    35,   108,
      79,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -167
static const yytype_int16 yypact[] =
{
      23,    11,    13,  -167,  -167,    -2,    66,   278,   291,  -167,
    -167,  -167,    17,    22,   107,     7,  -167,    29,     7,     7,
       6,     7,   297,   303,    66,  -167,    34,  -167,  -167,  -167,
    -167,   262,  -167,   261,  -167,   309,  -167,  -167,    -7,  -167,
     315,    76,     7,  -167,    33,   261,   261,     7,   235,  -167,
    -167,    45,  -167,   -10,    26,  -167,  -167,  -167,     7,     7,
       7,     7,  -167,  -167,  -167,  -167,  -167,  -167,    53,    46,
      47,  -167,  -167,  -167,   209,     7,    91,  -167,   261,   -19,
     321,    62,    63,    34,  -167,  -167,     7,     7,     7,    39,
    -167,  -167,    39,  -167,  -167,    67,     7,  -167,  -167,  -167,
    -167,   127,   127,   107,     2,  -167,   221,    73,   110,  -167,
       7,   327,  -167,     7,  -167,   261,    24,    24,     7,   241,
      89,    -3,  -167,    20,  -167,   100,     2,  -167,  -167,  -167,
      80,   106,   261,   261,     0,  -167,  -167,    87,   127,  -167,
      90,  -167,  -167,  -167,  -167,     2,  -167,  -167,  -167,    99,
    -167,   295,   127,  -167,     7,     7,    94,     2,  -167,   307,
       2,  -167,     2,   261,   261,  -167,    95,   307,  -167,   356,
    -167,   109,   119,  -167,     2,  -167,   307,     2,     2,     2,
    -167,  -167,   307,  -167,  -167,  -167,  -167,   103,     2,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,   104,  -167,   105,  -167,
    -167,  -167,   120,  -167
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -144,   -22,   -98,    60,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -166,   121,
      44,    21,  -167,    40,  -167,    -6,   -13,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,   165,     9,  -167,    93,  -167,
      49,  -167
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
      31,    39,    49,   120,   120,     7,    71,     8,    31,   181,
       7,    44,     8,     4,    14,   167,    15,   110,    31,    16,
     192,    17,   111,   195,    18,    19,    83,    84,    20,     1,
      72,   200,   182,    20,   138,     6,   110,     3,   139,    54,
     120,   148,    21,    36,    22,    23,    47,    21,    37,    22,
      23,    58,    59,    60,   161,    43,    93,   138,    94,    81,
      51,   140,    99,    85,    50,    87,    88,    59,    60,     7,
      61,     8,    75,     9,    10,    11,    12,    13,    14,    95,
      15,   103,   104,    16,   -14,    17,   101,   102,    18,    19,
     124,    73,    20,    96,   107,    97,    98,    31,    31,   112,
      56,    57,   113,    58,    59,    60,    21,   118,    22,    23,
       7,   129,     8,   130,   126,   136,   141,   131,   146,   147,
      31,    15,    61,   149,    16,   158,    17,   178,   152,    18,
      19,   165,   173,    20,     9,    10,    11,   179,   145,    31,
     193,   199,   201,   114,   125,    49,   123,    21,   151,    22,
      23,    31,   154,   155,    31,   157,    31,   203,    70,   150,
      49,   100,   162,     0,     0,     0,   142,   134,    31,     0,
     169,    31,    31,    31,     0,     0,     0,   175,     0,     0,
      41,     0,    31,    45,    46,   156,    48,     0,     0,   186,
     187,     0,   189,   190,   191,     0,     0,   166,     0,     0,
     168,   196,   170,   197,   198,     0,     0,    74,     0,   202,
       0,     0,    78,     0,   180,     0,     0,   183,   184,   185,
       0,     0,     0,    89,    90,    91,    92,   105,   194,     0,
       0,     0,     0,    56,    57,     0,    58,    59,    60,     0,
     106,   127,   128,     0,     0,    56,    57,     0,    58,    59,
      60,   115,   116,   117,     0,    61,     0,     0,     0,    56,
      57,   119,    58,    59,    60,    56,    57,    61,    58,    59,
      60,     0,     0,     0,     0,   132,    80,     0,   133,     0,
       0,    61,   135,    78,     0,    56,    57,    61,    58,    59,
      60,     0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,    55,   -19,   -19,   -19,   -19,   -19,    61,   -76,   -76,
     -76,   -76,   -76,   -76,     9,    10,    11,    12,    13,   163,
     164,   -77,   -77,   -77,   -77,   -77,   -77,   -79,   -79,   -79,
     -79,   -79,   -79,   -78,   -78,   -78,   -78,   -78,   -78,    62,
      63,    64,    65,    66,    67,   -80,   -80,   -80,   -80,   -80,
     -80,   -75,   -75,   -75,   -75,   -75,   -75,   -81,   -81,   -81,
     -81,   -81,   -81,   -24,   -24,   -24,   -24,   -24
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,    14,    24,   101,   102,     3,    13,     5,    14,   175,
       3,    17,     5,     0,    12,   159,    14,    36,    24,    17,
     186,    19,    41,   189,    22,    23,    36,    37,    26,     6,
      37,   197,   176,    26,    37,    37,    36,    26,    41,    30,
     138,    41,    40,    26,    42,    43,    40,    40,    26,    42,
      43,    27,    28,    29,   152,    26,     3,    37,     5,    50,
      26,    41,    68,    37,    24,    56,    57,    28,    29,     3,
      46,     5,    39,     7,     8,     9,    10,    11,    12,    26,
      14,    72,    73,    17,    39,    19,    40,    40,    22,    23,
     103,    15,    26,    40,     3,    42,    43,   103,   104,    37,
      24,    25,    39,    27,    28,    29,    40,    40,    42,    43,
       3,    38,     5,     3,   105,    26,    16,   108,    38,    13,
     126,    14,    46,    36,    17,    26,    19,    18,    38,    22,
      23,    37,    37,    26,     7,     8,     9,    18,   129,   145,
      37,    37,    37,    83,   104,   167,   102,    40,   139,    42,
      43,   157,   143,   144,   160,   146,   162,    37,    37,   138,
     182,    68,   153,    -1,    -1,    -1,   126,   118,   174,    -1,
     161,   177,   178,   179,    -1,    -1,    -1,   168,    -1,    -1,
      15,    -1,   188,    18,    19,   145,    21,    -1,    -1,   180,
     181,    -1,   183,   184,   185,    -1,    -1,   157,    -1,    -1,
     160,   192,   162,   194,   195,    -1,    -1,    42,    -1,   200,
      -1,    -1,    47,    -1,   174,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,    58,    59,    60,    61,    18,   188,    -1,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,
      75,    20,    21,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    86,    87,    88,    -1,    46,    -1,    -1,    -1,    24,
      25,    96,    27,    28,    29,    24,    25,    46,    27,    28,
      29,    -1,    -1,    -1,    -1,   110,    41,    -1,   113,    -1,
      -1,    46,    41,   118,    -1,    24,    25,    46,    27,    28,
      29,    -1,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,     7,     8,     9,    10,    11,    46,    30,    31,
      32,    33,    34,    35,     7,     8,     9,    10,    11,   154,
     155,    30,    31,    32,    33,    34,    35,    30,    31,    32,
      33,    34,    35,    30,    31,    32,    33,    34,    35,    30,
      31,    32,    33,    34,    35,    30,    31,    32,    33,    34,
      35,    30,    31,    32,    33,    34,    35,    30,    31,    32,
      33,    34,    35,     7,     8,     9,    10,    11
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    48,    26,     0,    49,    37,     3,     5,     7,
       8,     9,    10,    11,    12,    14,    17,    19,    22,    23,
      26,    40,    42,    43,    50,    51,    52,    56,    57,    61,
      70,    72,    73,    82,    84,    85,    26,    26,    71,    73,
      72,    82,    83,    26,    72,    82,    82,    40,    82,    51,
      70,    26,    53,    55,    83,    39,    24,    25,    27,    28,
      29,    46,    30,    31,    32,    33,    34,    35,    88,    66,
      66,    13,    37,    15,    82,    39,    79,    80,    82,    87,
      41,    83,    54,    36,    37,    37,    74,    83,    83,    82,
      82,    82,    82,     3,     5,    26,    40,    42,    43,    72,
      85,    40,    40,    83,    83,    18,    82,     3,    86,    65,
      36,    41,    37,    39,    53,    82,    82,    82,    40,    82,
      52,    67,    68,    67,    73,    70,    83,    20,    21,    38,
       3,    83,    82,    82,    87,    41,    26,    69,    37,    41,
      41,    16,    70,    75,    77,    83,    38,    13,    41,    36,
      68,    83,    38,    81,    83,    83,    70,    83,    26,    58,
      60,    52,    83,    82,    82,    37,    70,    50,    70,    83,
      70,    76,    78,    37,    59,    83,    62,    64,    18,    18,
      70,    65,    50,    70,    70,    70,    83,    83,    63,    83,
      83,    83,    65,    37,    70,    65,    83,    83,    83,    37,
      65,    37,    83,    37
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 119 "parser.y"
    {
		
		printf("\nin program\n");
		topPlsLoclNum( atoi( ((Eval*)(yyvsp[(3) - (8)].evalptr))->str ) );
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		mainSymTbl = pop(tblptrStack);
		allSymbolTablePrint( mainSymTbl ); 
		backpatch( ((Eval*)(yyvsp[(6) - (8)].evalptr))->nextList , ((Eval*)(yyvsp[(7) - (8)].evalptr))->quad );
		emit("return" , "0" , "" , "" );
		
		(yyval.strValue) = (yyvsp[(2) - (8)].strValue);
	}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    {
		printf("\nin program\n");
		topPlsLoclNum( atoi( ((Eval*)(yyvsp[(3) - (7)].evalptr))->str ) );
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		mainSymTbl = pop(tblptrStack);
		allSymbolTablePrint( mainSymTbl );
		printf("this is program");
		backpatch( ((Eval*)(yyvsp[(5) - (7)].evalptr))->nextList , ((Eval*)(yyvsp[(6) - (7)].evalptr))->quad );
		emit("return" , "0" , "" , "" );
		
		printf("end of program\n");
		(yyval.strValue) = (yyvsp[(2) - (7)].strValue);
	}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    {
		emit("//" , "program decleration:" , "" , "");
		snprintf(num,5,"%d",nextquad);
		emit("-" , "top" , "NA" , "top" );
		
		struct SymbolTable* t = mkTable( NULL , "program");
		push(t, tblptrStack);
		(yyval.evalptr) = mkEval (0 ,0 ,0 , "" , mkString(num) );
	}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (2)].strValue);
	}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    {
		printf("var deccc");
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 181 "parser.y"
    {
		currentType=4;
		returnType = (char*) malloc(strlen("INT"));
		strcpy(returnType, "INT");
		printf("this is int");
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 188 "parser.y"
    {
		currentType=8;
		returnType = (char*) malloc(strlen("REAL"));
		strcpy(returnType, "REAL");
		printf("this is real");
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    {
		currentType=1;
		returnType = (char*) malloc(strlen("BOOL"));
		strcpy(returnType, "BOOL");
		printf("this is bool\n");	
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    {
		enterVar( (yyvsp[(1) - (1)].strValue), currentType , top(tblptrStack) ); printf("a variable entered:%s\n",(yyvsp[(1) - (1)].strValue));
		
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {
		
		enterVar( (yyvsp[(1) - (1)].strValue) , currentType , top(tblptrStack) );
		
	}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    {
		
		if( currentType > 1 && ((Eval*)(yyvsp[(4) - (4)].evalptr))->str != 0 )
		{
			Eval* lvalueEval = idToEval((yyvsp[(1) - (4)].strValue));
			//DANGER
			emit("IP" , ((Eval*)(yyvsp[(4) - (4)].evalptr))->str , "" , lvalueEval->str );
		}
		else if (currentType == 1)
		{
			assignBool( ((Eval*)(yyvsp[(4) - (4)].evalptr))->trueList , ((Eval*)(yyvsp[(4) - (4)].evalptr))->falseList, (yyvsp[(1) - (4)].strValue) , true ,true );
		}
		(yyval.strValue) = (yyvsp[(1) - (4)].strValue);
		printf("a variable entered:%s\n",(yyvsp[(1) - (4)].strValue)); 
	}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 230 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (3)].strValue);
	}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 238 "parser.y"
    {
		printf("vardec");
		(yyval.strValue) = (yyvsp[(1) - (3)].strValue);
	}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 244 "parser.y"
    {
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "proc decleration:" , (yyvsp[(2) - (7)].strValue) , "");
		snprintf(num,5,"%d",nextquad);
		(yyvsp[(1) - (7)].strValue) = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
	}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 252 "parser.y"
    {
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		enterProcFunc( tmpc , 0 , "NULL" ,  tmpt , top(tblptrStack)  , ((Eval*)(yyvsp[(7) - (9)].evalptr))->quad );
		push( tmpt , tblptrStack );

	}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 258 "parser.y"
    {
		topPlsLoclNum(atoi((yyvsp[(1) - (15)].strValue)));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)(yyvsp[(3) - (15)].evalptr))->nextList , ((Eval*)(yyvsp[(14) - (15)].evalptr))->quad );
		backpatch( ((Eval*)(yyvsp[(11) - (15)].evalptr))->nextList , ((Eval*)(yyvsp[(12) - (15)].evalptr))->quad );
		(yyval.strValue) = (yyvsp[(2) - (15)].strValue);
		
	}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 269 "parser.y"
    {
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "proc decleration:" , (yyvsp[(2) - (7)].strValue) , "");
		snprintf(num,5,"%d",nextquad);
		(yyvsp[(1) - (7)].strValue) = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		enterProcFunc( tmpc , 0 , "NULL" ,  tmpt , top(tblptrStack)  , ((Eval*)(yyvsp[(7) - (7)].evalptr))->quad );
		push( tmpt , tblptrStack );
	}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 281 "parser.y"
    { 
		topPlsLoclNum(atoi((yyvsp[(1) - (13)].strValue)));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)(yyvsp[(3) - (13)].evalptr))->nextList , ((Eval*)(yyvsp[(12) - (13)].evalptr))->quad );
		backpatch( ((Eval*)(yyvsp[(9) - (13)].evalptr))->nextList , ((Eval*)(yyvsp[(10) - (13)].evalptr))->quad );
		(yyval.strValue) = (yyvsp[(2) - (13)].strValue);
		
	}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 294 "parser.y"
    {
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "func decleration:" , (yyvsp[(2) - (9)].strValue) , "");
		snprintf(num,5,"%d",nextquad);
		(yyvsp[(1) - (9)].strValue) = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
		printf("In Function declaration before declist\n");
	}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 303 "parser.y"
    {
		
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		//printf("after enterProcFunc\n");
		enterProcFunc(tmpc , -1 , returnType ,  tmpt , top(tblptrStack) , ((Eval*)(yyvsp[(9) - (11)].evalptr))->quad );
		push( tmpt , tblptrStack );

	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 311 "parser.y"
    {
		//printf("afterBlock in funcdec\n");
		topPlsLoclNum(atoi((yyvsp[(1) - (17)].strValue)));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)(yyvsp[(3) - (17)].evalptr))->nextList , ((Eval*)(yyvsp[(16) - (17)].evalptr))->quad );
		//printf("BETWEEN in funcdec\n");
		backpatch( ((Eval*)(yyvsp[(13) - (17)].evalptr))->nextList , ((Eval*)(yyvsp[(14) - (17)].evalptr))->quad );
		//printf("AFTER in funcdec\n");
		(yyval.strValue) = (yyvsp[(2) - (17)].strValue);
		
		
	}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 326 "parser.y"
    {
		emit("=" , "top" , "" , "sp");
		
		emit("//" , "func decleration:" , (yyvsp[(2) - (9)].strValue) , "");
		
		snprintf(num,5,"%d",nextquad);
		(yyvsp[(1) - (9)].strValue) = mkString(num);
		emit("-" , "top" , "NA" , "top" );
		
		
		//printf("after enterProcFunc\n");
		char* tmpc = mkString( top(tblptrStack)->name );
		struct SymbolTable* tmpt = pop(tblptrStack);
		//printf("after enterProcFunc\n");
		enterProcFunc(tmpc , -1 , returnType ,  tmpt , top(tblptrStack) , ((Eval*)(yyvsp[(9) - (9)].evalptr))->quad );
		push( tmpt , tblptrStack );
		printf("funcdec after return type\n");
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 343 "parser.y"
    {
		//printf("after block in funcdec\n");
		topPlsLoclNum(atoi((yyvsp[(1) - (15)].strValue)));
		for(int i=0 ; i<lastOfReturnQuad ; i++)
			topPlsLoclNum( returnQuads[i] );
		lastOfReturnQuad=0;
		pop(tblptrStack);
		backpatch( ((Eval*)(yyvsp[(3) - (15)].evalptr))->nextList , ((Eval*)(yyvsp[(14) - (15)].evalptr))->quad );
		backpatch( ((Eval*)(yyvsp[(11) - (15)].evalptr))->nextList , ((Eval*)(yyvsp[(12) - (15)].evalptr))->quad );
		(yyval.strValue) = (yyvsp[(2) - (15)].strValue);
		
	}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 357 "parser.y"
    {
		char * tmpPointer = newPTemp();
		char * PPtmp = newVTemp();
		char * tmpPointerWithStar = (char*) malloc(strlen(tmpPointer)+1);
		strcpy(tmpPointerWithStar , "*");
		strcat( tmpPointerWithStar , tmpPointer );
		//returning
		emit("//" , "return" , "" , "");
		returnQuads[lastOfReturnQuad] = nextquad;
		lastOfReturnQuad++;
		emit("+" , "top" , "NA" , "top");
		emit("+" , "atop" , "1" , PPtmp);
		emit("PI" , PPtmp , "" , tmpPointer );
		emit("goto" , tmpPointerWithStar , "" , "");
	}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 374 "parser.y"
    {
		printf("starting reducing NP\n");
		mkSymTblFncPrc(tempString);
		(yyval.evalptr) = mkEval(0 , 0 , mkList(nextquad) , "" , "");
		emit("goto" , "" , "" , "" );
	}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 382 "parser.y"
    { (yyval.strValue) = (yyvsp[(1) - (1)].strValue); printf("paramdecs\n"); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 383 "parser.y"
    { (yyval.strValue) = (yyvsp[(1) - (3)].strValue); printf("paramdecs\n"); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 384 "parser.y"
    { (yyval.strValue) = 0; printf("paramdecs\n"); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 387 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (2)].strValue);
	}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 392 "parser.y"
    {
		enterParam( (yyvsp[(1) - (1)].strValue), currentType , top(tblptrStack) ); printf("a variable entered:%s\n",(yyvsp[(1) - (1)].strValue)); 
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
	}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 396 "parser.y"
    {
		enterParam( (yyvsp[(3) - (3)].strValue), currentType , top(tblptrStack) ); printf("a variable entered:%s\n",(yyvsp[(3) - (3)].strValue)); 
		(yyval.strValue) = (yyvsp[(3) - (3)].strValue);
	}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 402 "parser.y"
    {
		
		(yyval.evalptr) = mkEval (0 ,0 , ((Eval*)(yyvsp[(2) - (3)].evalptr))->nextList , "" , "");
		printf("this is block \t nextList:%x\n" , ((Eval*)(yyvsp[(2) - (3)].evalptr))->nextList );
		
	}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 408 "parser.y"
    {
		(yyval.evalptr) = mkEval (0 ,0 ,((Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
		printf("this is block \t nextList:%x\n" , ((Eval*)(yyvsp[(1) - (1)].evalptr))->nextList );
	}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 414 "parser.y"
    {
		//printf("BEFORE in : stmt to stmtlist:)\n");
		(yyval.evalptr) = mkEval (0 ,0 , ((Eval*)(yyvsp[(1) - (1)].evalptr))->nextList , "" , "");
		printf("in : stmt <to> stmtlist:\t nextLIst is:%x)\n",((Eval*)(yyvsp[(1) - (1)].evalptr))->nextList );
	}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 419 "parser.y"
    {
		printf("in : stmtlist SEMICOLON M stmt <to> stmtlist:\t nextLIst is:%x)\n",((Eval*)(yyvsp[(4) - (4)].evalptr))->nextList );
		backpatch( ((Eval*)(yyvsp[(1) - (4)].evalptr))->nextList , ((Eval*)(yyvsp[(3) - (4)].evalptr))->quad );
		(yyval.evalptr) = mkEval (0 ,0 , ((Eval*)(yyvsp[(4) - (4)].evalptr))->nextList , "" , "");
	}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 426 "parser.y"
    {
		(yyval.strValue) = (yyvsp[(1) - (1)].strValue);
		printf("lvalue->identifier : %s\n", (yyvsp[(1) - (1)].strValue) );
	}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 432 "parser.y"
    {
		printf("decleration (stmt)\n");
	}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 434 "parser.y"
    {
		
		printf("in : lvalue DECLARE exp to stmt\n");
		//if(lvalue)
		//int idSize = atoi( ((Eval*)$1)->quad );
		//printf("88888888888888888888888888idSize:%d \t address:%s\n" , idSize , ((Eval*)$1)->str );
		if( strcmp( ((Eval*)(yyvsp[(4) - (4)].evalptr))->quad , "*" ) != 0 ){
			Eval* lvalueEval = idToEval((yyvsp[(1) - (4)].strValue));
			//DANGER
			emit("IP" , ((Eval*)(yyvsp[(4) - (4)].evalptr))->str , "" , lvalueEval->str );
		}
		else{
			
			//printf("88888888888888888bool lvalue is assugning:\t%s\n" , lvalueEval->str);
			assignBool( ((Eval*)(yyvsp[(4) - (4)].evalptr))->trueList , ((Eval*)(yyvsp[(4) - (4)].evalptr))->falseList, (yyvsp[(1) - (4)].strValue) , true ,true );
		}
		(yyval.evalptr) = mkEval(0,0,0,"","");
		
		
	}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 454 "parser.y"
    {
		printf("stmt->if then\n");
		backpatch( ((Eval*)(yyvsp[(2) - (5)].evalptr)) ->trueList, ((Eval*)(yyvsp[(4) - (5)].evalptr)) ->quad);
		Node * tmp = mergeList ( ((Eval*)(yyvsp[(2) - (5)].evalptr)) ->falseList, ((Eval*)(yyvsp[(5) - (5)].evalptr)) ->nextList );
		(yyval.evalptr)=mkEval(0,0, tmp ,"","");
	}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 460 "parser.y"
    {
		printf("BEGIN : IF exp THEN M block ELSE NS M block <TO> stmt\n");
		backpatch( ((Eval*)(yyvsp[(2) - (9)].evalptr)) ->trueList , ((Eval*)(yyvsp[(4) - (9)].evalptr)) ->quad );
		backpatch( ((Eval*)(yyvsp[(2) - (9)].evalptr)) ->falseList , ((Eval*)(yyvsp[(8) - (9)].evalptr)) ->quad );
		printf("in : IF exp THEN M block ELSE NS M block <TO> stmt\n");
		if( ((Eval*)(yyvsp[(9) - (9)].evalptr)) ->nextList == 0)
			printf("((Eval*)$9) ->nextList == 0\n");
		if( ((Eval*)(yyvsp[(7) - (9)].evalptr)) ->nextList == 0)
			printf("((Eval*)$7) ->nextList == 0\n");
		if( ((Eval*)(yyvsp[(5) - (9)].evalptr)) ->nextList == 0)
			printf("((Eval*)$5) ->nextList == 0\n");
		
		Node * tmp1=mergeList ( ((Eval*)(yyvsp[(7) - (9)].evalptr)) ->nextList , ((Eval*)(yyvsp[(9) - (9)].evalptr)) ->nextList );
		printf("in : IF exp THEN M block ELSE NS M block <TO> stmt\n");
		Node * tmp = mergeList ( ((Eval*)(yyvsp[(5) - (9)].evalptr)) ->nextList , tmp1);
		
		(yyval.evalptr) = mkEval(0,0,tmp,"","");
		printf("FINISH : IF exp THEN M block ELSE NS M block <TO> stmt FINISHED\n");
		
	}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 480 "parser.y"
    {
		//printf("WHILE:\n");
		printf("in : WHILE M exp DO M block <TO> stmt\n");
		backpatch( ((Eval*)(yyvsp[(6) - (6)].evalptr))->nextList , ((Eval*)(yyvsp[(2) - (6)].evalptr))->quad );
		backpatch( ((Eval*)(yyvsp[(3) - (6)].evalptr))->trueList , ((Eval*)(yyvsp[(5) - (6)].evalptr))->quad );
		Node * tmp = mergeList ( ((Eval*)(yyvsp[(3) - (6)].evalptr)) ->falseList, ((Eval*)(yyvsp[(6) - (6)].evalptr)) ->nextList );
		(yyval.evalptr) = mkEval( 0 ,0 , ((Eval*)(yyvsp[(3) - (6)].evalptr))->falseList , "" , "");
		emit("goto", ((Eval*)(yyvsp[(2) - (6)].evalptr)) ->quad ,"" ,"");
	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 490 "parser.y"
    {
		printf("For to");
		if( strcmp( ((Eval*)(yyvsp[(4) - (5)].evalptr))->quad , "*" ) != 0 ){
			Eval* lvalueEval = idToEval((yyvsp[(2) - (5)].strValue));
			//DANGER
			emit("IP" , ((Eval*)(yyvsp[(4) - (5)].evalptr))->str , "" , lvalueEval->str );
		}
		else{
			//printf("88888888888888888bool lvalue is assugning:\t%s\n" , lvalueEval->str);
			assignBool( ((Eval*)(yyvsp[(4) - (5)].evalptr))->trueList , ((Eval*)(yyvsp[(4) - (5)].evalptr))->falseList, (yyvsp[(2) - (5)].strValue) , true ,true );
		}
	}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 501 "parser.y"
    {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval((yyvsp[(2) - (8)].strValue));
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("if" , lvalueValue , ">" ,((Eval*)(yyvsp[(8) - (8)].evalptr)) ->str);
		
		//printf("((Eval*)$4) ->str : %s\t((Eval*)$2) ->str : %s\n",((Eval*)$4) ->str, $2 );
		((Eval*)(yyvsp[(8) - (8)].evalptr)) ->nextList = mkList(nextquad);
		emit("goto" , "" , "" , "" );
	}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 510 "parser.y"
    {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval((yyvsp[(2) - (12)].strValue));
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("+" , lvalueValue , "1" , lvalueValue );
		emit("IP" , lvalueValue , "" , lvalueEval->str );
		emit("goto" , ((Eval*)(yyvsp[(7) - (12)].evalptr))->quad , "" , "" );
		backpatch ( ((Eval*)(yyvsp[(11) - (12)].evalptr)) ->nextList , ((Eval*)(yyvsp[(12) - (12)].evalptr))->quad );
		Node * tmp = ((Eval*)(yyvsp[(8) - (12)].evalptr)) ->nextList ;
		(yyval.evalptr) = mkEval( 0 , 0 , tmp , "" , "" );
	}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 522 "parser.y"
    {
		
		printf("Downto is seen\n");
		if( strcmp( ((Eval*)(yyvsp[(4) - (5)].evalptr))->quad , "*" ) != 0 ){
			printf("inside the if\n");
			Eval* lvalueEval = idToEval((yyvsp[(2) - (5)].strValue));
			emit("IP" , ((Eval*)(yyvsp[(4) - (5)].evalptr))->str , "" , lvalueEval->str );
		}
		else{
			//printf("88888888888888888bool lvalue is assugning:\t%s\n" , lvalueEval->str);
			assignBool( ((Eval*)(yyvsp[(4) - (5)].evalptr))->trueList , ((Eval*)(yyvsp[(4) - (5)].evalptr))->falseList, (yyvsp[(2) - (5)].strValue) , true , true );
		}
		printf("For Downto\n");
		
	}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 536 "parser.y"
    {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval((yyvsp[(2) - (8)].strValue));
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("if" , lvalueValue , "<" ,((Eval*)(yyvsp[(8) - (8)].evalptr)) ->str);
		
		((Eval*)(yyvsp[(8) - (8)].evalptr)) ->nextList = mkList(nextquad);
		emit("goto" , "" , "" , "" );
	}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 544 "parser.y"
    {
		char* lvalueValue = newTemp();
		Eval* lvalueEval = idToEval((yyvsp[(2) - (12)].strValue));
		emit("PI" , lvalueEval->str , "" , lvalueValue );
		emit("-" , lvalueValue , "1" , lvalueValue );
		//printf("((Eval*)$6)->quad : ",((Eval*)$7)->quad);
		emit("IP" , lvalueValue , "" , lvalueEval->str );
		emit("goto" , ((Eval*)(yyvsp[(7) - (12)].evalptr))->quad , "" , "" );
		backpatch ( ((Eval*)(yyvsp[(11) - (12)].evalptr)) ->nextList , ((Eval*)(yyvsp[(12) - (12)].evalptr))->quad );
		Node * tmp = ((Eval*)(yyvsp[(8) - (12)].evalptr)) ->nextList ;
		(yyval.evalptr) = mkEval( 0 , 0 , tmp , "" , "" );
	}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 557 "parser.y"
    {
		((Eval*)(yyvsp[(2) - (2)].evalptr)) -> nextList = mkList(nextquad);
		emit("goto" , "" ,"" , "" );
	}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 560 "parser.y"
    {
		backpatch( ((Eval*)(yyvsp[(2) - (6)].evalptr))->nextList , ((Eval*)(yyvsp[(5) - (6)].evalptr))->quad );
		char * casStr = ((Eval*)(yyvsp[(4) - (6)].evalptr)) ->str;
		char * casQuad = ((Eval*)(yyvsp[(4) - (6)].evalptr)) ->quad;
		char* strTmp = strtok( ((Eval*)(yyvsp[(4) - (6)].evalptr)) ->str , ",");
		char* quadTmp = strtok( ((Eval*)(yyvsp[(4) - (6)].evalptr)) ->quad , ",");
		while( strTmp != 0  &&  quadTmp != 0 )
		{
			casStr += strlen(strTmp) + 1 ;
			casQuad += strlen(quadTmp) + 1 ;
			
			emit("if" , ((Eval*)(yyvsp[(2) - (6)].evalptr))->str , "==" , strTmp );
			emit("goto" , quadTmp , "" , "");
			strTmp = strtok( casStr , ",");
			quadTmp = strtok( casQuad , ",");
		}
		(yyval.evalptr) = mkEval( 0 ,0 , ((Eval*)(yyvsp[(4) - (6)].evalptr))->nextList , "" , "" );
	}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 579 "parser.y"
    {
		printf("return\n");
		char * tmpPointer = newPTemp();
		//set return value
		emit("+" , "sp" , "1" , tmpPointer);
		//DANGER
		emit("IP" , ((Eval*)(yyvsp[(2) - (2)].evalptr))->str , "" , tmpPointer);
		
	}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 587 "parser.y"
    {(yyval.evalptr)=mkEval(0 , 0 , 0 , "" , "");}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 589 "parser.y"
    { (yyval.evalptr)=(yyvsp[(1) - (1)].evalptr); printf("stmt exp\n");}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 592 "parser.y"
    {
		(yyval.evalptr) = mkEval ( 0 , 0 , mkList(nextquad) , "" , "" );
		emit( "goto" ,"","","" );
	}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 598 "parser.y"
    {
		backpatch( ((Eval*)(yyvsp[(1) - (4)].evalptr)) ->trueList , ((Eval*)(yyvsp[(3) - (4)].evalptr)) ->quad);
		(yyval.evalptr) = mkEval( ((Eval*)(yyvsp[(4) - (4)].evalptr)) ->trueList , mergeList( ((Eval*)(yyvsp[(1) - (4)].evalptr))->falseList , ((Eval*)(yyvsp[(4) - (4)].evalptr)) ->falseList ) , 0 , "*" , "" );
	}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 602 "parser.y"
    {
		//printf("zero");
		backpatch( ((Eval*)(yyvsp[(1) - (4)].evalptr)) ->falseList , ((Eval*)(yyvsp[(3) - (4)].evalptr)) ->quad);
		//printf("first");
		(yyval.evalptr) = mkEval( mergeList( ((Eval*)(yyvsp[(1) - (4)].evalptr))->trueList , ((Eval*)(yyvsp[(4) - (4)].evalptr)) ->trueList ), ((Eval*)(yyvsp[(4) - (4)].evalptr)) ->falseList , 0 , "*" , "" );
		//printf("second");
	}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 609 "parser.y"
    {
		//$2="+";
		(yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)(yyvsp[(1) - (3)].evalptr))->str);
		loadTmpVal(((Eval*)(yyvsp[(3) - (3)].evalptr))->str);
		emit("+" , ((Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((Eval*)(yyval.evalptr))->str );
		saveTmpVal(((Eval*)(yyval.evalptr))->str);
		//printf("--------------------------------------------------------\nexp PLUS exp\t$1:%s\t$2:%s\t$3:%s\n",((Eval*)$1)->str,$2,((Eval*)$3)->str);
		}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 618 "parser.y"
    {
		//$2="-";
		(yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)(yyvsp[(1) - (3)].evalptr))->str);
		loadTmpVal(((Eval*)(yyvsp[(3) - (3)].evalptr))->str);
		emit("-" , ((Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((Eval*)(yyval.evalptr))->str );
		saveTmpVal(((Eval*)(yyval.evalptr))->str);
		//printf("--------------------------------------------------------\nexp MINUS exp\t$1:%s\t$2:%s\t$3:%s\n",$1,$2,$3);
	}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 627 "parser.y"
    {
		(yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)(yyvsp[(1) - (3)].evalptr))->str);
		loadTmpVal(((Eval*)(yyvsp[(3) - (3)].evalptr))->str);
		emit("*" , ((Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((Eval*)(yyval.evalptr))->str );
		saveTmpVal(((Eval*)(yyval.evalptr))->str);
	}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 634 "parser.y"
    {
		(yyval.evalptr)=mkEval( 0 , 0 , 0 , "" , newTemp() );
		loadTmpVal(((Eval*)(yyvsp[(1) - (3)].evalptr))->str);
		loadTmpVal(((Eval*)(yyvsp[(3) - (3)].evalptr))->str);
		emit("/" , ((Eval*)(yyvsp[(1) - (3)].evalptr))->str , ((Eval*)(yyvsp[(3) - (3)].evalptr))->str , ((Eval*)(yyval.evalptr))->str );
		saveTmpVal(((Eval*)(yyval.evalptr))->str);
	}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 641 "parser.y"
    {
		(yyval.evalptr)=(yyvsp[(2) - (3)].evalptr);
	}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 644 "parser.y"
    {
		//printf( "boolexp relop boolexp to exp : %s\n" , ((Eval*)$1) ->str );
		loadTmpVal( ((Eval*)(yyvsp[(1) - (3)].evalptr)) ->str );
		loadTmpVal( ((Eval*)(yyvsp[(3) - (3)].evalptr)) ->str );
		emit("if", ((Eval*)(yyvsp[(1) - (3)].evalptr)) ->str , getRelop((yyvsp[(2) - (3)].strValue)) ,((Eval*)(yyvsp[(3) - (3)].evalptr))->str );
		
		(yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , "");
		defaultGotoGen();
		defaultGotoGen();
		
	}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 655 "parser.y"
    {
		printf("exp->constant : %s\n" , (yyvsp[(1) - (1)].evalptr) );
		(yyval.evalptr) = (yyvsp[(1) - (1)].evalptr);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 658 "parser.y"
    {
		(yyval.evalptr) = mkEval( mkList(nextquad) , 0 , 0 , "*" , "true");
		defaultGotoGen();
		
	}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 663 "parser.y"
    {
		(yyval.evalptr) = mkEval( 0 , mkList(nextquad) , 0 , "*" , "false");
		defaultGotoGen();
		
	}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 668 "parser.y"
    {
		Eval* lvalueEval = idToEval((yyvsp[(1) - (1)].strValue));
		int idSize = atoi( lvalueEval->quad );
		char * value = newTemp();
		emit("PI" , lvalueEval ->str , "" , value);
		saveTmpVal(value);
		if( idSize == 1)
		{	
			emit("if", value , "==" , "true" );
			(yyval.evalptr) = mkEval( mkList(nextquad) , mkList(nextquad+2) , 0 , "*" , value);
			defaultGotoGen();
			defaultGotoGen();
		}
		else
			(yyval.evalptr) = mkEval( 0 , 0 , 0 , "" , value);
		printf("lvalue\n");
		
	}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 686 "parser.y"
    {
		//symbolTablePrint(top(tblptrStack) );
		(yyval.evalptr) = mkEval( 0 , 0 , 0 , "" , functionCall ( (yyvsp[(1) - (4)].strValue) , ((Eval*)(yyvsp[(3) - (4)].evalptr))->str ) );
	}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 692 "parser.y"
    {
	(yyval.evalptr) = mkEval( 0 , 0 , 0 , createLable() , "");
}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 697 "parser.y"
    {
		printf("Integer:%s\n",(yyvsp[(1) - (1)].strValue));
		(yyval.evalptr)=strToEval((yyvsp[(1) - (1)].strValue));
	}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 701 "parser.y"
    {
		printf("RealNum:%s\n",(yyvsp[(1) - (1)].strValue));
		(yyval.evalptr)=strToEval((yyvsp[(1) - (1)].strValue));
	}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 707 "parser.y"
    { 
		char* str = ((Eval*)(yyvsp[(2) - (3)].evalptr))->str;
		char* thequad = ((Eval*)(yyvsp[(2) - (3)].evalptr))->quad;
		if(strcmp(thequad , "*") == 0 || strcmp(str , "true") == 0 || strcmp(str , "false") == 0)
		{
			char* newtemp  = newTemp() ;
			assignBool( ((Eval*)(yyvsp[(2) - (3)].evalptr))->trueList , ((Eval*)(yyvsp[(2) - (3)].evalptr))->falseList, newtemp ,true , true);
			(yyval.evalptr) = mkEval(0 , 0 , 0 , "" , newtemp);
		}
		else
			(yyval.evalptr) = ( Eval* )(yyvsp[(2) - (3)].evalptr);
		
	}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 720 "parser.y"
    {(yyval.evalptr) = mkEval(0,0,0,"" , (yyvsp[(1) - (1)].strValue)); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 721 "parser.y"
    {(yyval.evalptr) = mkEval(0,0,0,"" , (yyvsp[(1) - (1)].strValue)); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 722 "parser.y"
    {(yyval.evalptr) = mkEval(0,0,0,"" , "true"); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 723 "parser.y"
    {(yyval.evalptr) = mkEval(0,0,0,"" , "false"); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 724 "parser.y"
    {

		Eval* lvalueEval = idToEval((yyvsp[(1) - (1)].strValue));
		char * value = newTemp();
		emit("PI" , lvalueEval ->str , "" , value);
		saveTmpVal(value);
		printf("boolexp->lvalue : %s\n",(yyvsp[(1) - (1)].strValue));
		(yyval.evalptr) = mkEval( 0 , 0 , 0 , "" , value);
		printf("boolexp->lvalue : %s\n$$:%s|\n",(yyvsp[(1) - (1)].strValue),(yyval.evalptr));
	}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 734 "parser.y"
    {
		(yyval.evalptr) = mkEval( 0 , 0 , 0 , "" , functionCall( (yyvsp[(1) - (4)].strValue) , ((Eval*)(yyvsp[(3) - (4)].evalptr))->str ) );
	}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 739 "parser.y"
    {
		Node* tmp = mergeList( mkList(nextquad) , ((Eval*)(yyvsp[(4) - (5)].evalptr))->nextList );
		
		emit("goto" , "" ,"" ,"");
		(yyval.evalptr) = mkEval(0 ,0, tmp , ((Eval*)(yyvsp[(3) - (5)].evalptr)) ->quad , (yyvsp[(1) - (5)].strValue));
	}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 745 "parser.y"
    {
		Node* tmp = mergeList( mkList(nextquad) ,((Eval*)(yyvsp[(1) - (6)].evalptr))->nextList ) ;
		tmp = mergeList( tmp ,((Eval*)(yyvsp[(5) - (6)].evalptr))->nextList );
		emit("goto" , "" ,"" ,"");
		
		char* quadTmp = strcat( ((Eval*)(yyvsp[(1) - (6)].evalptr))->quad , "," );
		quadTmp = strcat( quadTmp , ((Eval*)(yyvsp[(4) - (6)].evalptr))->quad );
		
		char* strTmp = strcat( ((Eval*)(yyvsp[(1) - (6)].evalptr))->str , "," );
		strTmp = strcat( strTmp , (yyvsp[(2) - (6)].strValue) );
		
		(yyval.evalptr) = mkEval(0 ,0, tmp , quadTmp , strTmp);
	}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 760 "parser.y"
    {
		printf("explist->exp : %s\n", ((Eval*)(yyvsp[(1) - (1)].evalptr))->str  );
		char* strTmp;
		if( strcmp( ((Eval*)(yyvsp[(1) - (1)].evalptr))->str , "" ) )
			strTmp = strcat( ((Eval*)(yyvsp[(1) - (1)].evalptr))->str , "," );
		else
		{
			char * mytmp = newTemp();
			assignBool(((Eval*)(yyvsp[(1) - (1)].evalptr)) ->trueList , ((Eval*)(yyvsp[(1) - (1)].evalptr)) ->falseList , mytmp , true , true );
			strTmp = strcat( mytmp , "," );
			
		}
		(yyval.evalptr) = mkEval(0 , 0 , 0 , "" , strTmp);
		
	}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 775 "parser.y"
    {
		//char* strTmp = (char* ) malloc ( strlen(((Eval*)$3)->str) + strlen(((Eval*)$1)->str + 1 ) );
		char* strTmp = strcat( ((Eval*)(yyvsp[(1) - (3)].evalptr))->str , "," );
		if( strcmp( ((Eval*)(yyvsp[(3) - (3)].evalptr))->str , "" ) )
			strTmp = strcat( strTmp , ((Eval*)(yyvsp[(3) - (3)].evalptr))->str );
		else
		{
			char * mytmp = newTemp();
			assignBool(((Eval*)(yyvsp[(3) - (3)].evalptr)) ->trueList , ((Eval*)(yyvsp[(3) - (3)].evalptr)) ->falseList , mytmp , true , true );
			strTmp = strcat( strTmp , mytmp );
		}
		(yyval.evalptr) = mkEval(0 , 0 , 0 , "" , strTmp);
		
	}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 789 "parser.y"
    {
		printf("explist->  \n");
		(yyval.evalptr) = mkEval(0 , 0 , 0 , "" , "" );
	}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 795 "parser.y"
    {(yyval.strValue)=(yyvsp[(1) - (1)].strValue);}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 796 "parser.y"
    {(yyval.strValue)=(yyvsp[(1) - (1)].strValue);}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 797 "parser.y"
    {(yyval.strValue)=(yyvsp[(1) - (1)].strValue);}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 798 "parser.y"
    {(yyval.strValue)=(yyvsp[(1) - (1)].strValue);}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 799 "parser.y"
    {(yyval.strValue)=(yyvsp[(1) - (1)].strValue);}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 800 "parser.y"
    {(yyval.strValue)=(yyvsp[(1) - (1)].strValue);}
    break;


/* Line 1792 of yacc.c  */
#line 2741 "parser.tab.c"
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 805 "parser.y"


int t=0;
int q=0;

void topPlsLoclNum(int quad)
{
	printf("in topPlsLoclNum()\n");
	snprintf(num,5,"%d",top(tblptrStack)->localNum );
	int i =0;
	printf("in topPlsLoclNum()\n");
  while(num[i]!='\0'){
   quad_ruples[quad][2][i] = num[i];
  i++;
  }  
  quad_ruples[quad][2][i] = num[i];
}

void loadTmpVal(char * theTmp){
	int *i = (int *) malloc( sizeof(int) );
	int *j = (int *) malloc( sizeof(int) );
	if( (theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true")==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
		return;
	char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
	emit( "PI" , addressOfStack , "" , theTmp );
}

void saveTmpVal(char* theTmp){
	if( (theTmp[0]>='0' && theTmp[0]<='9') || strcmp(theTmp, "true" )==0 || strcmp(theTmp, "false" )==0 || theTmp[0]=='-')
		return;
	int *i = (int *) malloc( sizeof(int) );
	int *j = (int *) malloc( sizeof(int) );
	printf("<<<<<<<<<<<<saveing temp value!>>>>>>>>>>>\t:%s\n",theTmp);
	char* addressOfStack = lookup(theTmp , top(tblptrStack) , i , j );
	
	emit("IP" , theTmp , "" , addressOfStack );
}

Eval * idToEval(char * idName){
	
	int * intsize = (int *) malloc(sizeof(int));
	int * scopeID = (int *) malloc(sizeof(int));
	char* tmp = lookup( idName ,top(tblptrStack) , intsize , scopeID );
	char * num = (char*) malloc( sizeof(char) * 3 ) ;
	itoa(*intsize, num , 10);
	//printf("lvalue to Identifier\tintSize:%d\tnum=%s\tthe addres is:%s\n", *intsize , num , tmp);
	if(tmp == 0)
	{
		yyerror("Variable is not Defined!!!!!!\t:'(");
		return 0;
	}
	else
		return mkEval( 0,0, 0 , num , tmp );
}

char* functionCall(char* id ,char * explist){
	//emit("=" , "top" , "" , "sp");
	printf("function call: %s \n" , id);
	//char * casStr = explist;
	char* strTmp = strtok( explist , "," );
	while( strTmp != 0 )//push variables
	{
		emit( "//" , "functioncall:" , id , "");
		//casStr += strlen(strTmp) + 1 ;
		emit( "-" , "top" , "1" , "top" );
		loadTmpVal(strTmp);
		emit("IP" , strTmp , "" , "top" );
		strTmp = strtok( NULL , ",");
	}
	int* size = (int*) malloc( sizeof(int) );
	int* scopeID = (int*) malloc( sizeof(int) );
	//symbolTablePrint(top(tblptrStack) );
	char* tmp = lookup(id , top(tblptrStack) , size , scopeID );
	//printf("size is : %d" , *size );
	if(*size>8)
	{
		char * retLabel= newQuad();
		char * retaddress = newPTemp();
		
		//push number of arguments
		emit("-" , "top" , "1" , "top");
		char* buff = (char*) malloc( sizeof(char) * 3 );
		itoa(*size - 9 , buff , 10);
		emit("IP" , buff , "" , "top" );
		
		//push return address
		emit("-" , "top" , "1" , "top");
		emit("&&" , retLabel , "" , retaddress);
		emit("-" , "atop" , "1" , "atop");
		emit("IP" , retaddress , "" , "atop");
		
		//push return value
		emit("-" , "top" , "1" , "top");
		
		//push sp
		emit("-" , "top" , "1" , "top");
		char* scopeid = (char*) malloc( sizeof(char) * 3 );
		itoa(*scopeID , scopeid , 10);
		emit("IP" , scopeid , "" , "top");
		emit("-" , "atop" , "1" , "atop");
		emit("IP" , "sp" , "" , "atop");
		
		//call
		emit("goto" , tmp , "" , "");
		emit( "//" , "return after func call" , "" , "");
		//return location
		emit( strcat(retLabel ,":") , "" , "" , "");
		
		//get return value
		char* returnValue = newTemp();
		emit("+" , "top" , "1" , "top");
		emit("PI" , "top" , "" , returnValue);
		//printf("size is : %d" , *size );
		
		//make every thing normal
			//setting top
			emit("+" , "top" , "2" , "top");
			char* argcount = newITemp();
			emit("PI" , "top" , "" , argcount);
			emit("+" , argcount , "1" , argcount);
			emit("+" , "top" , argcount , "top");
			//setting sp
			emit("PI" , "atop" , "" , "sp");
			//setting atop
			emit("+" , "atop" , "2" , "atop");
		emit( "//" , "every thing is normal after func call:" , id , "");
		saveTmpVal(returnValue);
		return returnValue;
	}
	else{
		printf("No such Function!!! : %s\n" , id);
		errorFlag = true;
		return 0;
	}
}

char* mkCodeFndVarScp(int id){
	char * scopeId = (char*) malloc(sizeof(char) *3);
	itoa(id , scopeId , 10);
	
	char * loop = newQuad();
	char * outOfLoop = newQuad();
	char * loopLabel = (char* ) malloc( strlen(loop)+1 );
	strcpy(loopLabel , loop);
	strcat(loopLabel , ":");
	
	char * outOfLoopLabel = (char* ) malloc( strlen(outOfLoop)+1 );
	strcpy(outOfLoopLabel , outOfLoop );
	strcat(outOfLoopLabel , ":");
	
	char* vPointer = newVTemp();
	char* pPointer = newPTemp();
	char* value = newTemp();
	
	emit("=" , "atop" , "" , vPointer);
	emit(loopLabel , "" ,"" ,"");
	emit("PI" , vPointer , "" , pPointer);
	emit("PI" , pPointer , "" , value);
	emit("if" , value , "==" , scopeId);
	emit("goto" , outOfLoop , "" , "");
	emit("+" , vPointer , "2" , vPointer );
	emit("goto" , loop , "" , "");
	emit(outOfLoopLabel , "" ,"" ,"");
	return pPointer;
}

char * lookup(char * name , struct SymbolTable* symbolTable , int * size ,int * scopeID){
	
	bool isInside=true;
	struct SymbolTable* currentTbl = symbolTable;
	
	while(currentTbl != NULL){
		
		struct SymbolTableNode* currentNode = currentTbl->head;
		while(currentNode != NULL){
			//symbolTablePrint(currentTbl);
			//printf("variable is searched : %s ?= %s\n" , currentNode->name , name);
			
			if( strcmp( currentNode->name , name ) == 0 )
			{
				*size = currentNode->size;
				//printf("fuck the life!! %d \n", strcmp( currentNode->name , name ));
				//printf("the variable is found! : %s\t with size:%d\n" , name , *size);
				char* tblPtrTmp;
				
				
				if(*size >= 1 || *size==-2)
				{
					*scopeID = currentTbl->ID;
					if(isInside)
					{
						tblPtrTmp = newPTemp();
						if(currentNode->offset>0)
							emit("+" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						else
							emit("-" , "sp" , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						return tblPtrTmp;
					}
					else{
						tblPtrTmp = mkCodeFndVarScp(currentTbl->ID);
						if(currentNode->offset>0)
							emit("+" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						else
							emit("-" , tblPtrTmp , getOffset(currentNode->offset , currentTbl->argNum ) , tblPtrTmp );
						return tblPtrTmp;
					}
				}
				else{
					//printf("it is func or proc!\n");
					*scopeID = currentNode-> innerScope ->ID;
					*size = 9 + (currentNode->innerScope->argNum);
					return (currentNode->address);
				}
			}
			currentNode = currentNode->next;
		}
		currentTbl = currentTbl->outerScope;
		isInside = false;
		
	}
	printf("No such variable or Function!!! : %s\n" , name);
	
	errorFlag = true;
	return 0;
}

char * assignBool(Node * trueList , Node * falseList , char* name , bool isVar , bool mkItEval)
{
	char* var;
	
	char * quad3 = newQuad();
	if(trueList!=0){
		char * quad1 = createLable();
		
		if(mkItEval){
			Eval* lvalueEval = idToEval(name);
			var = lvalueEval->str;
		}
		else{
			var = (char*) malloc(strlen(name));
			strcpy(var , name);
		}
		if(isVar)
			emit ( "IP" , "true" , "" , var );
		else
			emit ( "=" , "true" , "" , var );
		
		backpatch( trueList , quad1 );
		emit ( "goto" , quad3 , "" , "" );
	}
	if(falseList!=0)
	{
		char * quad2 = newQuad();
		char * colonQuad2 = (char *)malloc( strlen(quad2) );
		strcpy(colonQuad2 , quad2);
		strcat(colonQuad2 , ":");
		emit ( colonQuad2 , "" , "" , "" );
		if(mkItEval){
			Eval* lvalueEval = idToEval(name);
			var = lvalueEval->str;
		}
		else{
			var = (char*) malloc(strlen(name));
			strcpy(var , name);
		}
		if(isVar)
			emit ( "IP" , "false" , "" , var );
		else
			emit ( "=" , "false" , "" , var );
		backpatch( falseList , quad2 );
		emit ( "goto" , quad3 , "" , "" );
	}
	
	char * colonQuad3 = (char *)malloc( strlen(quad3) );
	strcpy(colonQuad3 , quad3);
	strcat(colonQuad3 , ":");
	emit ( colonQuad3 , "" , "" , "" );
	return var;
}


void writeTmpVar(FILE * f)
{
	char defStr[10000];
	strcpy(defStr , "double ");
	
	
	for(int i = 0 ; i<t ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
		strcpy(tmp,  "t");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(t>0)
		fprintf(f, defStr );
	
	strcpy(defStr , "double ");
	
	for(int i = 0 ; i<tt ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("*tt")+sizeof(num) );
		strcpy(tmp,  "*tt");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(tt>0)
		fprintf(f, defStr );
	
	strcpy(defStr , "double ");
	for(int i = 0 ; i<v ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("**v")+sizeof(num) );
		strcpy(tmp,  "**v");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(v>0)
		fprintf(f, defStr );
	
	strcpy(defStr , "int ");
	for(int i = 0 ; i<I ; i++)
	{
		snprintf(num,5,"%d",i);
		char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
		strcpy(tmp,  "i");
		strcat(tmp,num);
		strcat(defStr , tmp );
		strcat(defStr , " , " );
	}
	strcpy( defStr+strlen(defStr)-2 , ";\n" );
	if(I>0)
		fprintf(f, defStr );
}

void mkCfile()
{
	FILE * fp;
   /* open the file for writing*/
   fp = fopen ("intermediate.c","w");
   fprintf(fp,"#include <stdbool.h>\n");
   fprintf(fp,"#include <stdlib.h>\n");
   fprintf(fp,"#include <stdio.h>\n");
   
   fprintf(fp,"double * top;\n");
   fprintf(fp,"double * sp;\n");
   fprintf(fp,"double ** atop;\n");
   
   writeTmpVar(fp);
   //writeVar( mainSymTbl , 8 , fp );
   //writeVar( mainSymTbl , 4 , fp );
   //writeVar( mainSymTbl , 1 , fp );
   
   fprintf(fp,"int main() {\n");
   fprintf(fp,"top = (double *) malloc(sizeof(double) *10001);\n");
   fprintf(fp,"atop = (double **) malloc(sizeof(double*) *1001);\n");
   fprintf(fp,"top = top + 10000;\n");
   fprintf(fp,"atop = atop + 1000;\n");
   fprintf(fp,"sp = top;\n\n");
   fprintf(fp,"*top = 0;\n\n");
   
   for(int i=0; i<=nextquad-1; i++){
	   if( strcmpi( quad_ruples[i][0] , "if" ) == 0 )
		  fprintf(fp,"%s ( %s %s %s )\n",quad_ruples[i][0],quad_ruples[i][1],quad_ruples[i][2],quad_ruples[i][3]);
		else if(strcmpi( quad_ruples[i][0] , "goto" ) == 0 )
			fprintf(fp,"\t\t%s %s; \n",quad_ruples[i][0],quad_ruples[i][1]);
		else if(strcmpi( quad_ruples[i][0] , "=" ) == 0 )
			fprintf(fp,"\t%s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][0],quad_ruples[i][1]);
		else if(strcmpi( quad_ruples[i][0] , "+" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if(strcmpi( quad_ruples[i][0] , "-" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if(strcmpi( quad_ruples[i][0] , "*" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if(strcmpi( quad_ruples[i][0] , "/" ) == 0 )
			fprintf(fp,"\t%s = %s %s %s; \n", quad_ruples[i][3] , quad_ruples[i][1] , quad_ruples[i][0] , quad_ruples[i][2]);
		else if( strstr( quad_ruples[i][0] , ":" ) != 0 )
			fprintf(fp,"%s\n", quad_ruples[i][0]);
		else if(strcmpi( quad_ruples[i][0] , "PI" ) == 0 )
			fprintf(fp,"\t%s = *%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
		else if(strcmpi( quad_ruples[i][0] , "IP" ) == 0 )
			fprintf(fp,"\t*%s = %s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
		else if(strcmpi( quad_ruples[i][0] , "&&" ) == 0 )
			fprintf(fp,"\t%s = &&%s; \n", quad_ruples[i][3] , quad_ruples[i][1] );
		else if(strcmpi( quad_ruples[i][0] , "//" ) == 0 )
			fprintf(fp,"//%s %s %s\n", quad_ruples[i][1] , quad_ruples[i][2] , quad_ruples[i][3] );
		
	}
	fprintf(fp,"return 0;\n");
	fprintf(fp,"}\n");
 
   /* close the file*/  
   fclose (fp);
}

char* getRelop(char* str){
	
	if( strcmp( str , ".GT.") == 0 )
		return mkString(">");
	else if ( strcmp( str , ".GE.") == 0 )
		return mkString(">=");
	else if ( strcmp( str , ".NE.") == 0 )
		return mkString("!=");
	else if ( strcmp( str , ".EQ.") == 0 )
		return mkString("==");
	else if ( strcmp( str , ".LT.") == 0 )
		return mkString("<");
	else if ( strcmp( str , ".LE.") == 0 )
		return mkString("<=");
}

void defaultGotoGen(){
	char * tmp = newQuad();
	emit("goto",tmp,"","");
	emit(strcat(tmp,":") , "" ,"" ,"");
}

char* mkString(char* input)
{
	char* string = (char*) malloc(strlen(input));
	strcpy(string , input);
	return string;
}

char * newQuad(){
	
  snprintf(num,5,"%d",q);
  char * tmp = (char*) malloc( sizeof("L")+sizeof(num) );
	strcpy(tmp,  "L");
  strcat(tmp,num);
  q++;
  return tmp;
  
}

char * newVTemp(){
	
  snprintf(num,5,"%d",v);
  char * tmp = (char*) malloc( sizeof("v")+sizeof(num) );
	strcpy(tmp,  "v");
  strcat(tmp,num);
  v++;
  return tmp;
}

char * newTemp(){
	
  snprintf(num,5,"%d",t);
  char * tmp = (char*) malloc( sizeof("t")+sizeof(num) );
	strcpy(tmp,  "t");
  strcat(tmp,num);
  tmp = mkString(tmp);
  //printf("newTmp() : |%s|\n", tmp);
  enterVar( tmp, -2 , top(tblptrStack) );
  t++;
  return tmp;
}

char * newPTemp(){
	
  snprintf(num,5,"%d",tt);
  char * tmp = (char*) malloc( sizeof("tt")+sizeof(num) );
	strcpy(tmp,  "tt");
  strcat(tmp,num);
  tt++;
  return tmp;
}

char * newITemp(){
	
  snprintf(num,5,"%d",I);
  char * tmp = (char*) malloc( sizeof("i")+sizeof(num) );
	strcpy(tmp,  "i");
  strcat(tmp,num);
  I++;
  return tmp;
}

char* createLable(){
	char * tmp = newQuad();
	char *ttmp = mkString(tmp);
	emit(strcat(ttmp,":") , "" ,"" ,"");
	return tmp;
}

Eval* strToEval(char* input){
	
	Eval* e = (Eval*) malloc (sizeof(Eval));
	char * string = (char*) malloc (strlen(input));
	strcpy(string , input);
	e->str = string;
	e->trueList = 0;
	e->falseList = 0;
	e->nextList = 0;
	e->quad = mkString("");
	return e;
}

void mkSymTblFncPrc(char * name)
{
	struct SymbolTable* t = mkTable( top(tblptrStack) , name );
	push(t, tblptrStack);
}

struct SymbolTable* popTop(struct Stack* b ){
	pop(b);
	top(b);
}

int main(){

	tblptrStack=createStack();
	tblptrStack->top = NULL;
	yyin = fopen("fibonachi.txt", "r");
	yyparse();
	if(errorFlag)
	{
		printf("!!!!!!!!OH!!!!!!!!! <<<<ERROR>>>> !!!!!!!!OH!!!!!!!!!! \t :'( /_\\");
	}
	quad_display();
	mkCfile();
	printf("------<<<<<<<***** FINISH *****>>>>>>------ :D *_*");
	return 0;
}

void yyerror(char* error){
	printf("Error : %s\n", error);
}