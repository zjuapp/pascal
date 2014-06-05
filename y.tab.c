/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LP = 258,
     RP = 259,
     LB = 260,
     RB = 261,
     DOT = 262,
     COMMA = 263,
     COLON = 264,
     MUL = 265,
     DIV = 266,
     PLUS = 267,
     MINUS = 268,
     ID = 269,
     GE = 270,
     GT = 271,
     LE = 272,
     LT = 273,
     EQUAL = 274,
     ASSIGN = 275,
     INTEGER = 276,
     REAL = 277,
     CHAR = 278,
     STRING = 279,
     CONST = 280,
     SEMI = 281,
     VAR = 282,
     PROGRAM = 283,
     TYPE = 284,
     SYS_TYPE = 285,
     RECORD = 286,
     ARRAY = 287,
     BP = 288,
     END = 289,
     BEGINN = 290,
     MOD = 291,
     UNEQUAL = 292,
     DR = 293,
     NOT = 294,
     AND = 295,
     CASEE = 296,
     IFF = 297,
     DOO = 298,
     TO = 299,
     DOWNTO = 300,
     UNTIL = 301,
     FOR = 302,
     WHILE = 303,
     ELSEE = 304,
     OF = 305,
     REPEAT = 306,
     GOTO = 307,
     THEN = 308,
     PROCEDURE = 309,
     FUNCTION = 310,
     SYS_PROC = 311
   };
#endif
/* Tokens.  */
#define LP 258
#define RP 259
#define LB 260
#define RB 261
#define DOT 262
#define COMMA 263
#define COLON 264
#define MUL 265
#define DIV 266
#define PLUS 267
#define MINUS 268
#define ID 269
#define GE 270
#define GT 271
#define LE 272
#define LT 273
#define EQUAL 274
#define ASSIGN 275
#define INTEGER 276
#define REAL 277
#define CHAR 278
#define STRING 279
#define CONST 280
#define SEMI 281
#define VAR 282
#define PROGRAM 283
#define TYPE 284
#define SYS_TYPE 285
#define RECORD 286
#define ARRAY 287
#define BP 288
#define END 289
#define BEGINN 290
#define MOD 291
#define UNEQUAL 292
#define DR 293
#define NOT 294
#define AND 295
#define CASEE 296
#define IFF 297
#define DOO 298
#define TO 299
#define DOWNTO 300
#define UNTIL 301
#define FOR 302
#define WHILE 303
#define ELSEE 304
#define OF 305
#define REPEAT 306
#define GOTO 307
#define THEN 308
#define PROCEDURE 309
#define FUNCTION 310
#define SYS_PROC 311




/* Copy the first part of user declarations.  */
#line 1 "parse.y"

	void yyerror(char * s);
	extern int yylex();
	#include "common.h"
	#include "const_record.h"
	#include "type_record.h"
	#include "var_record.h"
	#include "stmt.h"
	#include "expr.h"
	#include "type_value.h"
	#include "routine.h"
	#include "enviroment.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "parse.y"
{
	char * _str;
	int _int;
	double _double;
	base_type * _type;
	char _char;
	key_value_tuple * _tuple;
	vector <string> * _vt;
	vector < pair <string, type_ptr> > * _field;
	base_expr * _expr;
	base_stmt * _stmt;
	int _direction;
	case_expr_list * _case_list;
	case_expr * _case_expr;
	stmt_list * _stmt_list;
	routine * _routine;
	const_record * _c_r;
	var_record * _v_r;
	type_record * _t_r;
	routine_head * _r_h;
	routine_record * _r_r;
	procedure * _procedure_decl;
	func * _function;
	pair<int, pair < vector <string>, type_ptr > > * _para_type_list;
	vector < pair<int, pair <vector <string>, type_ptr> > > * _para_decl_list;
	vector < shared_ptr <base_expr> > *  _args_list;
	proc_stmt * _proc_stmt;
}
/* Line 193 of yacc.c.  */
#line 254 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 267 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  253

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    13,    14,    15,    23,    26,
      29,    30,    36,    41,    43,    45,    47,    49,    52,    53,
      57,    59,    65,    70,    72,    74,    76,    83,    87,    90,
      92,    97,    99,   103,   108,   114,   121,   124,   125,   131,
     136,   140,   144,   148,   152,   156,   160,   164,   166,   170,
     174,   176,   180,   184,   188,   192,   194,   196,   201,   205,
     208,   211,   216,   220,   222,   224,   226,   228,   232,   234,
     238,   241,   245,   247,   249,   251,   253,   255,   257,   259,
     261,   263,   267,   274,   280,   286,   289,   290,   295,   300,
     309,   311,   313,   319,   322,   324,   329,   334,   337,   339,
     341,   346,   351,   355,   357,   360,   363,   364,   371,   375,
     376,   380,   382,   386,   390,   393,   395
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    28,    14,    26,    59,     7,    -1,    60,
      79,    -1,    -1,    -1,    -1,    65,    61,    68,    62,    77,
      63,   101,    -1,    60,    79,    -1,    25,    66,    -1,    -1,
      66,    14,    19,    67,    26,    -1,    14,    19,    67,    26,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    29,
      70,    -1,    -1,    69,     9,    14,    -1,    14,    -1,    70,
      14,    19,    71,    26,    -1,    14,    19,    71,    26,    -1,
      76,    -1,    72,    -1,    73,    -1,    32,     5,    76,     6,
      50,    71,    -1,    31,    74,    34,    -1,    74,    75,    -1,
      75,    -1,    69,     8,    71,    26,    -1,    30,    -1,     3,
      69,     4,    -1,    67,     7,     7,    67,    -1,    13,    67,
       7,     7,    67,    -1,    13,    67,     7,     7,    13,    67,
      -1,    27,    78,    -1,    -1,    78,    69,     8,    71,    26,
      -1,    69,     8,    71,    26,    -1,    35,    85,    34,    -1,
      80,    15,    81,    -1,    80,    16,    81,    -1,    80,    17,
      81,    -1,    80,    18,    81,    -1,    80,    19,    81,    -1,
      80,    37,    81,    -1,    81,    -1,    81,    12,    82,    -1,
      81,    13,    82,    -1,    82,    -1,    82,    10,    83,    -1,
      82,    11,    83,    -1,    82,    36,    83,    -1,    82,    40,
      83,    -1,    83,    -1,    14,    -1,    14,     3,    84,     4,
      -1,     3,    80,     4,    -1,    39,    83,    -1,    13,    83,
      -1,    14,     5,    80,     6,    -1,    14,     7,    14,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    84,     8,
      80,    -1,    80,    -1,    85,    86,    26,    -1,    86,    26,
      -1,    21,     9,    87,    -1,    87,    -1,    88,    -1,    89,
      -1,    91,    -1,    93,    -1,    92,    -1,    95,    -1,    98,
      -1,    99,    -1,    14,    20,    80,    -1,    14,     5,    80,
       6,    20,    80,    -1,    14,     7,    14,    20,    80,    -1,
      42,    80,    53,    86,    90,    -1,    49,    86,    -1,    -1,
      51,    85,    46,    80,    -1,    48,    80,    43,    86,    -1,
      47,    14,    20,    80,    94,    80,    43,    86,    -1,    44,
      -1,    45,    -1,    41,    80,    50,    96,    34,    -1,    96,
      97,    -1,    97,    -1,    67,     9,    86,    26,    -1,    14,
       9,    86,    26,    -1,    52,    21,    -1,    56,    -1,    14,
      -1,    14,     3,   100,     4,    -1,    56,     3,   100,     4,
      -1,   100,     8,    80,    -1,    80,    -1,   101,   102,    -1,
     101,   108,    -1,    -1,    54,    14,   103,    26,    64,    26,
      -1,     3,   104,     4,    -1,    -1,   104,    26,   105,    -1,
     105,    -1,   106,     8,    76,    -1,   107,     8,    76,    -1,
      27,    69,    -1,    69,    -1,    55,    14,   103,     9,    76,
      26,    64,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   108,   113,   117,   120,   113,   128,   135,
     139,   143,   147,   152,   160,   168,   176,   185,   188,   192,
     196,   201,   206,   212,   215,   218,   222,   229,   234,   241,
     245,   254,   273,   282,   290,   304,   329,   332,   336,   345,
     356,   365,   372,   379,   386,   393,   400,   407,   412,   419,
     426,   431,   438,   445,   452,   459,   464,   469,   470,   471,
     477,   483,   488,   495,   502,   508,   514,   522,   523,   528,
     533,   540,   541,   545,   548,   552,   555,   559,   563,   567,
     571,   576,   582,   589,   597,   605,   608,   613,   621,   628,
     638,   641,   646,   654,   659,   666,   673,   681,   688,   689,
     693,   699,   701,   706,   712,   717,   722,   726,   740,   743,
     748,   752,   758,   764,   772,   777,   785
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOT", "COMMA",
  "COLON", "MUL", "DIV", "PLUS", "MINUS", "ID", "GE", "GT", "LE", "LT",
  "EQUAL", "ASSIGN", "INTEGER", "REAL", "CHAR", "STRING", "CONST", "SEMI",
  "VAR", "PROGRAM", "TYPE", "SYS_TYPE", "RECORD", "ARRAY", "BP", "END",
  "BEGINN", "MOD", "UNEQUAL", "DR", "NOT", "AND", "CASEE", "IFF", "DOO",
  "TO", "DOWNTO", "UNTIL", "FOR", "WHILE", "ELSEE", "OF", "REPEAT", "GOTO",
  "THEN", "PROCEDURE", "FUNCTION", "SYS_PROC", "$accept", "program",
  "routine", "routine_head", "@1", "@2", "@3", "sub_routine", "const_part",
  "const_expr_list", "const_value", "type_part", "name_list",
  "type_decl_list", "type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "simple_type_decl", "var_part",
  "var_decl_list", "routine_body", "expression", "expr", "term", "factor",
  "arg_list", "stmt_list", "stmt", "non_label_stmt", "assign_stmt",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt",
  "direction", "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "proc_stmt", "args_list", "routine_part", "procedure_decl", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "function_decl", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    61,    62,    63,    60,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    72,    73,    74,    74,
      75,    76,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    88,    89,    90,    90,    91,    92,    93,
      94,    94,    95,    96,    96,    97,    97,    98,    99,    99,
      99,    99,   100,   100,   101,   101,   101,   102,   103,   103,
     104,   104,   105,   105,   106,   107,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     0,     0,     0,     7,     2,     2,
       0,     5,     4,     1,     1,     1,     1,     2,     0,     3,
       1,     5,     4,     1,     1,     1,     6,     3,     2,     1,
       4,     1,     3,     4,     5,     6,     2,     0,     5,     4,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     4,     3,     2,
       2,     4,     3,     1,     1,     1,     1,     3,     1,     3,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     6,     5,     5,     2,     0,     4,     4,     8,
       1,     1,     5,     2,     1,     4,     4,     2,     1,     1,
       4,     4,     3,     1,     2,     2,     0,     6,     3,     0,
       3,     1,     3,     3,     2,     1,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    10,     0,     0,     0,     4,
       0,     9,     2,     0,     3,    18,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,    72,
      73,    74,    75,    77,    76,    78,    79,    80,     0,     5,
      13,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    63,    64,    65,    66,     0,     0,
      47,    50,    55,     0,     0,     0,     0,    97,     0,    40,
       0,    70,     0,    17,    37,    12,     0,   103,     0,     0,
       0,    81,    71,     0,    60,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     6,    11,   100,     0,     0,     0,    58,    68,     0,
       0,    62,    41,    42,    43,    44,    45,    46,     0,     0,
       0,    94,    48,    49,    51,    52,    53,    54,    86,     0,
      88,    87,   101,     0,     0,    31,     0,     0,     0,     0,
      24,    25,    23,     0,    20,     0,    36,   106,   102,     0,
      83,    57,     0,    61,     0,     0,    92,    93,     0,    84,
      90,    91,     0,     0,     0,     0,     0,    29,     0,     0,
      22,     0,     0,     0,     0,     7,    82,    67,     0,     0,
      85,     0,    32,     0,     0,    27,    28,     0,     0,    21,
       0,    19,     0,     0,     0,   104,   105,    96,    95,     0,
       0,     0,     0,    33,    39,     0,   109,   109,    89,     0,
      34,    30,     0,    38,     0,     0,     0,    35,    26,     0,
     115,     0,   111,     0,     0,    10,     0,   114,   108,     0,
       0,     0,     0,     0,     0,   110,   112,   113,     8,   107,
      10,     0,   116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,   242,    15,    74,   157,   243,     9,    11,
     148,    39,   175,    73,   149,   150,   151,   176,   177,   152,
     111,   156,    14,    77,    60,    61,    62,   119,    27,    28,
      29,    30,    31,   169,    32,    33,    34,   172,    35,   130,
     131,    36,    37,    78,   185,   205,   225,   231,   232,   233,
     234,   206
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -176
static const yytype_int16 yypact[] =
{
     -17,     0,    28,     5,  -176,    19,    49,    43,    17,  -176,
      67,    84,  -176,   120,  -176,    71,   142,    91,    57,   103,
     156,   156,   101,   156,   120,    96,   119,    33,   109,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,   122,  -176,
    -176,  -176,  -176,  -176,   114,   142,   156,   156,   123,   156,
      55,   156,   156,    34,  -176,  -176,  -176,  -176,   156,     1,
      92,   113,  -176,     6,   128,   223,   104,  -176,   156,  -176,
     117,  -176,   135,   144,   147,  -176,   149,   235,    38,    76,
     161,   235,  -176,   169,  -176,   156,   156,   176,  -176,   156,
     156,   156,   156,   156,   156,   234,   156,   156,   156,   156,
     156,   156,   120,   156,   120,   156,    64,  -176,   201,   172,
     178,  -176,  -176,  -176,   156,   173,   156,  -176,   235,    79,
     183,  -176,    92,    92,    92,    92,    92,    92,   187,   188,
     259,  -176,   113,   113,  -176,  -176,  -176,  -176,   163,   192,
    -176,   235,  -176,   178,   142,  -176,   178,   200,   206,   189,
    -176,  -176,  -176,   201,  -176,   100,   178,  -176,   235,   156,
     235,  -176,   156,  -176,   120,   120,  -176,  -176,   120,  -176,
    -176,  -176,   156,     3,   209,   111,    -4,  -176,   246,   210,
    -176,   193,   201,   204,   118,    75,   235,   235,   195,   202,
    -176,   228,  -176,   219,   201,  -176,  -176,   221,   142,  -176,
     208,  -176,   201,   216,   247,  -176,  -176,  -176,  -176,   120,
     264,   236,   185,  -176,  -176,   237,   261,   261,  -176,   142,
    -176,  -176,   201,  -176,    -1,   248,   266,  -176,  -176,   178,
     269,    23,  -176,   271,   276,    19,   246,   269,  -176,    -1,
     246,   246,    17,   263,   265,  -176,  -176,  -176,  -176,  -176,
      19,   274,  -176
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -176,   285,  -176,  -176,  -176,    42,  -176,  -176,
     -16,  -176,  -108,  -176,  -149,  -176,  -176,  -176,   125,  -175,
    -176,  -176,    60,   -15,   205,    36,   -43,  -176,   279,   -26,
     254,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
     175,  -176,  -176,   238,  -176,  -176,    90,  -176,    69,  -176,
    -176,  -176
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    70,   155,   197,   181,    59,    63,   192,    65,    84,
     154,     1,   183,   154,     3,    88,    89,    90,    91,    92,
      93,    89,    90,    91,    92,    93,   229,   238,     4,    76,
     195,     5,    79,   200,    81,   173,    83,    85,    94,    86,
      70,    87,   113,    94,     6,   211,   114,    18,   184,   239,
      12,    95,    13,   215,    19,   134,   135,   136,   137,   102,
      46,   244,    47,    10,    48,   246,   247,    69,   142,    18,
     118,   120,   114,   228,    20,    21,   138,    49,   140,   129,
      22,    23,   115,   161,    24,    25,    16,   162,   139,    26,
     141,    89,    90,    91,    92,    93,    20,    21,    17,   158,
      38,   160,    22,    23,    96,    97,    24,    25,   182,   183,
      45,    26,    50,    94,   129,    64,   230,    67,    18,   194,
     183,   237,    68,    98,    99,    19,   202,   183,   174,   203,
     204,   230,   132,   133,    18,    71,    72,    80,   188,   189,
      75,    19,   190,   107,   186,    20,    21,   187,   103,   100,
     105,    22,    23,   101,   108,    24,    25,   191,   109,    51,
      26,    20,    21,    40,    41,    42,    43,    22,    23,    52,
      53,    24,    25,   117,   110,   112,    26,    54,    55,    56,
      57,   116,   213,   218,    89,    90,    91,    92,    93,   163,
     121,   153,   154,   159,   220,    58,   164,   165,    89,    90,
      91,    92,    93,   227,   143,   178,    94,    89,    90,    91,
      92,    93,   168,   179,   144,   180,   193,   198,   201,   199,
      94,   207,    40,    41,    42,    43,   210,   212,   208,    94,
     216,   145,   146,   147,   214,   222,   170,   171,    89,    90,
      91,    92,    93,    89,    90,    91,    92,    93,   128,   143,
      89,    90,    91,    92,    93,    40,    41,    42,    43,   144,
      94,   217,   221,   223,   224,    94,   104,    40,    41,    42,
      43,   209,    94,   128,   235,   236,   145,   219,   183,   240,
      40,    41,    42,    43,   241,    40,    41,    42,    43,   249,
       8,   250,   251,   166,   122,   123,   124,   125,   126,   127,
     252,   196,   248,    66,    82,   167,   106,   226,   245
};

static const yytype_uint8 yycheck[] =
{
      16,    27,   110,   178,   153,    20,    21,     4,    23,    52,
      14,    28,     9,    14,    14,    58,    15,    16,    17,    18,
      19,    15,    16,    17,    18,    19,    27,     4,     0,    45,
      34,    26,    47,   182,    49,   143,    51,     3,    37,     5,
      66,     7,     4,    37,    25,   194,     8,    14,   156,    26,
       7,    50,    35,   202,    21,    98,    99,   100,   101,    53,
       3,   236,     5,    14,     7,   240,   241,    34,     4,    14,
      85,    86,     8,   222,    41,    42,   102,    20,   104,    95,
      47,    48,     6,     4,    51,    52,    19,     8,   103,    56,
     105,    15,    16,    17,    18,    19,    41,    42,    14,   114,
      29,   116,    47,    48,    12,    13,    51,    52,     8,     9,
      19,    56,     9,    37,   130,    14,   224,    21,    14,     8,
       9,   229,     3,    10,    11,    21,     8,     9,   144,    54,
      55,   239,    96,    97,    14,    26,    14,    14,   164,   165,
      26,    21,   168,    26,   159,    41,    42,   162,    20,    36,
      46,    47,    48,    40,    19,    51,    52,   172,    14,     3,
      56,    41,    42,    21,    22,    23,    24,    47,    48,    13,
      14,    51,    52,     4,    27,    26,    56,    21,    22,    23,
      24,    20,   198,   209,    15,    16,    17,    18,    19,     6,
      14,    19,    14,    20,   210,    39,     9,     9,    15,    16,
      17,    18,    19,   219,     3,     5,    37,    15,    16,    17,
      18,    19,    49,     7,    13,    26,     7,     7,    14,    26,
      37,    26,    21,    22,    23,    24,     7,     6,    26,    37,
      14,    30,    31,    32,    26,    50,    44,    45,    15,    16,
      17,    18,    19,    15,    16,    17,    18,    19,    14,     3,
      15,    16,    17,    18,    19,    21,    22,    23,    24,    13,
      37,    14,    26,    26,     3,    37,    43,    21,    22,    23,
      24,    43,    37,    14,    26,     9,    30,    13,     9,     8,
      21,    22,    23,    24,     8,    21,    22,    23,    24,    26,
       5,    26,   250,    34,    89,    90,    91,    92,    93,    94,
      26,   176,   242,    24,    50,   130,    68,   217,   239
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    58,    14,     0,    26,    25,    59,    60,    65,
      14,    66,     7,    35,    79,    61,    19,    14,    14,    21,
      41,    42,    47,    48,    51,    52,    56,    85,    86,    87,
      88,    89,    91,    92,    93,    95,    98,    99,    29,    68,
      21,    22,    23,    24,    67,    19,     3,     5,     7,    20,
       9,     3,    13,    14,    21,    22,    23,    24,    39,    80,
      81,    82,    83,    80,    14,    80,    85,    21,     3,    34,
      86,    26,    14,    70,    62,    26,    67,    80,   100,    80,
      14,    80,    87,    80,    83,     3,     5,     7,    83,    15,
      16,    17,    18,    19,    37,    50,    12,    13,    10,    11,
      36,    40,    53,    20,    43,    46,   100,    26,    19,    14,
      27,    77,    26,     4,     8,     6,    20,     4,    80,    84,
      80,    14,    81,    81,    81,    81,    81,    81,    14,    67,
      96,    97,    82,    82,    83,    83,    83,    83,    86,    80,
      86,    80,     4,     3,    13,    30,    31,    32,    67,    71,
      72,    73,    76,    19,    14,    69,    78,    63,    80,    20,
      80,     4,     8,     6,     9,     9,    34,    97,    49,    90,
      44,    45,    94,    69,    67,    69,    74,    75,     5,     7,
      26,    71,     8,     9,    69,   101,    80,    80,    86,    86,
      86,    80,     4,     7,     8,    34,    75,    76,     7,    26,
      71,    14,     8,    54,    55,   102,   108,    26,    26,    43,
       7,    71,     6,    67,    26,    71,    14,    14,    86,    13,
      67,    26,    50,    26,     3,   103,   103,    67,    71,    27,
      69,   104,   105,   106,   107,    26,     9,    69,     4,    26,
       8,     8,    60,    64,    76,   105,    76,    76,    79,    26,
      26,    64,    26
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 102 "parse.y"
    {
	(yyvsp[(4) - (5)]._routine) -> name = (yyvsp[(2) - (5)]._str);
	enviroment::single() -> clear();
	(yyvsp[(4) - (5)]._routine) -> add_function_param();
	(yyvsp[(4) - (5)]._routine) -> gencode();
}
    break;

  case 3:
#line 108 "parse.y"
    {
	(yyval._routine) = new routine();
	(yyval._routine) -> header.reset((yyvsp[(1) - (2)]._r_h));
	(yyval._routine) -> stmt_vt.reset((yyvsp[(2) - (2)]._stmt_list));
}
    break;

  case 4:
#line 113 "parse.y"
    {
	(yyval._r_h) = new routine_head();
	(yyval._r_h) -> c_r.reset((yyvsp[(1) - (1)]._c_r));
	enviroment::single() -> insert((yyval._r_h));
	}
    break;

  case 5:
#line 117 "parse.y"
    {
		shared_ptr <type_record> tmp((yyvsp[(3) - (3)]._t_r));
		enviroment::single() -> top() -> t_r.reset((yyvsp[(3) - (3)]._t_r));
	}
    break;

  case 6:
#line 120 "parse.y"
    {
	enviroment::single() -> top() -> v_r.reset((yyvsp[(5) - (5)]._v_r));
	}
    break;

  case 7:
#line 123 "parse.y"
    {
	enviroment::single() -> top() -> r_r.reset((yyvsp[(7) - (7)]._r_r));
	(yyval._r_h) = enviroment::single() -> top();
	}
    break;

  case 8:
#line 128 "parse.y"
    {
		(yyval._routine) = new routine();
		(yyval._routine) -> header.reset((yyvsp[(1) - (2)]._r_h));
		(yyval._routine) -> stmt_vt.reset((yyvsp[(2) - (2)]._stmt_list));
		enviroment::single() -> pop();
	}
    break;

  case 9:
#line 136 "parse.y"
    {
			(yyval._c_r) = (yyvsp[(2) - (2)]._c_r);
		}
    break;

  case 10:
#line 139 "parse.y"
    {
		 	(yyval._c_r) = new const_record();
		}
    break;

  case 11:
#line 143 "parse.y"
    {
		(yyvsp[(1) - (5)]._c_r) -> insert((yyvsp[(2) - (5)]._str), (yyvsp[(4) - (5)]._tuple) -> first, (yyvsp[(4) - (5)]._tuple) -> second);
		(yyval._c_r) = (yyvsp[(1) - (5)]._c_r);
	}
    break;

  case 12:
#line 147 "parse.y"
    {
		(yyval._c_r) = new const_record();
		(yyval._c_r) -> insert((yyvsp[(1) - (4)]._str), (yyvsp[(3) - (4)]._tuple) -> first, (yyvsp[(3) - (4)]._tuple) -> second);
	}
    break;

  case 13:
#line 152 "parse.y"
    {
		value_set value;
		value._int = (yyvsp[(1) - (1)]._int);
		type_ptr ptr(new base_type(INT_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
}
    break;

  case 14:
#line 160 "parse.y"
    {
		value_set value;
		value._double = (yyvsp[(1) - (1)]._double);
		type_ptr ptr(new base_type(REAL_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
	}
    break;

  case 15:
#line 168 "parse.y"
    {
		value_set value;
		value._char = (yyvsp[(1) - (1)]._char);
		type_ptr ptr(new base_type(CHAR_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
	}
    break;

  case 16:
#line 176 "parse.y"
    {
		value_set value;
		value._str = (yyvsp[(1) - (1)]._str);
		type_ptr ptr(new base_type(STR_TYPE));
		(yyval._tuple) = new key_value_tuple();
		(yyval._tuple) -> first = ptr;
		(yyval._tuple) -> second = value;
	}
    break;

  case 17:
#line 185 "parse.y"
    {
		(yyval._t_r) = (yyvsp[(2) - (2)]._t_r);
	}
    break;

  case 18:
#line 188 "parse.y"
    {
		 	(yyval._t_r) = new type_record();
		}
    break;

  case 19:
#line 192 "parse.y"
    {
		(yyvsp[(1) - (3)]._vt) -> push_back((yyvsp[(3) - (3)]._str));
		(yyval._vt) = (yyvsp[(1) - (3)]._vt);
	}
    break;

  case 20:
#line 196 "parse.y"
    {
		(yyval._vt) = new vector <string> ();
		(yyval._vt) -> push_back((yyvsp[(1) - (1)]._str));
	}
    break;

  case 21:
#line 201 "parse.y"
    {
		shared_ptr <base_type> tmp((yyvsp[(4) - (5)]._type));
		(yyvsp[(1) - (5)]._t_r) -> insert((yyvsp[(2) - (5)]._str), tmp);	
		(yyval._t_r) = (yyvsp[(1) - (5)]._t_r);
	}
    break;

  case 22:
#line 206 "parse.y"
    {
		(yyval._t_r) = new type_record();
		shared_ptr <base_type> tmp((yyvsp[(3) - (4)]._type));
		(yyval._t_r) -> insert((yyvsp[(1) - (4)]._str), tmp);	
	}
    break;

  case 23:
#line 212 "parse.y"
    {
		(yyval._type) = (yyvsp[(1) - (1)]._type);
	}
    break;

  case 24:
#line 215 "parse.y"
    {
		(yyval._type) = (yyvsp[(1) - (1)]._type);
	}
    break;

  case 25:
#line 218 "parse.y"
    {
		(yyval._type) = (yyvsp[(1) - (1)]._type);
	}
    break;

  case 26:
#line 222 "parse.y"
    {
		arr_type * tmp = new arr_type();
		tmp -> nxt.reset((yyvsp[(6) - (6)]._type));
		tmp -> index.reset((yyvsp[(3) - (6)]._type));
		(yyval._type) = tmp;
	}
    break;

  case 27:
#line 229 "parse.y"
    {
		(yyval._type) = new record_type();
		((record_type * )(yyval._type)) -> vt = *(yyvsp[(2) - (3)]._field);
	}
    break;

  case 28:
#line 234 "parse.y"
    {
		for(auto i = (yyvsp[(2) - (2)]._field) -> begin(); i != (yyvsp[(2) - (2)]._field) -> end(); ++i){
			(yyvsp[(1) - (2)]._field) -> push_back(*i);
		}
		delete (yyvsp[(2) - (2)]._field);
		(yyval._field) = (yyvsp[(1) - (2)]._field);
	}
    break;

  case 29:
#line 241 "parse.y"
    {
		(yyval._field) = (yyvsp[(1) - (1)]._field);
	}
    break;

  case 30:
#line 245 "parse.y"
    {
		(yyval._field) = new vector < pair <string, type_ptr> >();
		for(auto i = (yyvsp[(1) - (4)]._vt) -> begin(); i != (yyvsp[(1) - (4)]._vt) -> end(); ++i){
			type_ptr tmp((yyvsp[(3) - (4)]._type));
			(yyval._field) -> push_back(make_pair(*i, tmp));
		}
	}
    break;

  case 31:
#line 255 "parse.y"
    {
		if(strcmp((yyvsp[(1) - (1)]._str), "int") == 0){
			(yyval._type) = new base_type(INT_TYPE);
		}
		else
			if(strcmp((yyvsp[(1) - (1)]._str), "real") == 0){
				cout << "fuck real" <<endl;
				(yyval._type) = new base_type(REAL_TYPE);
			}
			else
			if(strcmp((yyvsp[(1) - (1)]._str), "char") == 0){
				(yyval._type) = new base_type(CHAR_TYPE);
			}
			else
			if(strcmp((yyvsp[(1) - (1)]._str), "string") == 0){
				(yyval._type) = new base_type(STR_TYPE);
			}
	}
    break;

  case 32:
#line 275 "parse.y"
    {
		discrete_type * tmp = new discrete_type();
		for(auto i = (yyvsp[(2) - (3)]._vt) -> begin(); i != (yyvsp[(2) - (3)]._vt) -> end(); ++i){
			tmp -> index.push_back(*i);
		}
		(yyval._type) = tmp;
	}
    break;

  case 33:
#line 282 "parse.y"
    {
		continue_type * tmp = new continue_type();
		tmp -> left = *(yyvsp[(1) - (4)]._tuple);
		tmp -> right = *(yyvsp[(4) - (4)]._tuple);
		(yyval._type) = tmp;
		delete (yyvsp[(1) - (4)]._tuple);
		delete (yyvsp[(4) - (4)]._tuple);
	}
    break;

  case 34:
#line 290 "parse.y"
    {
			if((yyvsp[(2) - (5)]._tuple) -> first -> gettype() == INT_TYPE){
				(yyvsp[(2) - (5)]._tuple) -> second._int = -(yyvsp[(2) - (5)]._tuple) -> second._int;
			}
			if((yyvsp[(2) - (5)]._tuple) -> first -> gettype() == REAL_TYPE){
				(yyvsp[(2) - (5)]._tuple) -> second._double = -(yyvsp[(2) - (5)]._tuple) -> second._double;
			}
			continue_type * tmp = new continue_type();
			tmp -> left = *(yyvsp[(2) - (5)]._tuple);
			tmp -> right = *(yyvsp[(5) - (5)]._tuple);
			(yyval._type) = tmp;
			delete (yyvsp[(5) - (5)]._tuple);
			delete (yyvsp[(2) - (5)]._tuple);
	}
    break;

  case 35:
#line 304 "parse.y"
    {
			if((yyvsp[(2) - (6)]._tuple) -> first -> gettype() == INT_TYPE){
				(yyvsp[(2) - (6)]._tuple) -> second._int = -(yyvsp[(2) - (6)]._tuple) -> second._int;
			}
			if((yyvsp[(2) - (6)]._tuple) -> first -> gettype() == REAL_TYPE){
				(yyvsp[(2) - (6)]._tuple) -> second._double = -(yyvsp[(2) - (6)]._tuple) -> second._double;
			}
			if((yyvsp[(6) - (6)]._tuple) -> first -> gettype() == INT_TYPE){
				(yyvsp[(6) - (6)]._tuple) -> second._int = -(yyvsp[(6) - (6)]._tuple) -> second._int;
			}

			if((yyvsp[(6) - (6)]._tuple) -> first -> gettype() == REAL_TYPE){
				(yyvsp[(6) - (6)]._tuple) -> second._double = -(yyvsp[(6) - (6)]._tuple) -> second._double;
			}
			continue_type * tmp = new continue_type();
			tmp -> left = *(yyvsp[(2) - (6)]._tuple);
			tmp -> right = *(yyvsp[(6) - (6)]._tuple);
			(yyval._type) = tmp;
			delete (yyvsp[(2) - (6)]._tuple);
			delete (yyvsp[(6) - (6)]._tuple);
	}
    break;

  case 36:
#line 329 "parse.y"
    {
		(yyval._v_r) = (yyvsp[(2) - (2)]._v_r);
	}
    break;

  case 37:
#line 332 "parse.y"
    {
		 	(yyval._v_r) = new var_record();
		}
    break;

  case 38:
#line 336 "parse.y"
    {
	for(auto i = (yyvsp[(2) - (5)]._vt) -> begin(); i != (yyvsp[(2) - (5)]._vt) -> end(); ++i){
			type_ptr tmp((yyvsp[(4) - (5)]._type));
			if(!(yyvsp[(1) - (5)]._v_r) -> insert(*i, tmp)){
				yyerror("var_decl error");
			} 
		}	
	(yyval._v_r) = (yyvsp[(1) - (5)]._v_r);
	}
    break;

  case 39:
#line 345 "parse.y"
    {
		(yyval._v_r) = new var_record();
	for(auto i = (yyvsp[(1) - (4)]._vt) -> begin(); i != (yyvsp[(1) - (4)]._vt) -> end(); ++i){
			type_ptr tmp((yyvsp[(3) - (4)]._type));
			if(!(yyval._v_r) -> insert(*i, tmp)){
				yyerror("var_decl error");
			} 
		}	
	}
    break;

  case 40:
#line 356 "parse.y"
    {
		(yyval._stmt_list) = (yyvsp[(2) - (3)]._stmt_list);
	}
    break;

  case 41:
#line 365 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = GE_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 42:
#line 372 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = GT_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 43:
#line 379 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = LE_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 44:
#line 386 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = LT_TYPE;
		(yyval._expr) = tmp;	
	}
    break;

  case 45:
#line 393 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = EQUAL_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 46:
#line 400 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = UNEQUAL_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 47:
#line 407 "parse.y"
    {
		(yyval._expr) = (yyvsp[(1) - (1)]._expr);
	}
    break;

  case 48:
#line 412 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = PLUS_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 49:
#line 419 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = MINUS_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 50:
#line 426 "parse.y"
    {
		(yyval._expr) = (yyvsp[(1) - (1)]._expr);
	}
    break;

  case 51:
#line 431 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = MUL_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 52:
#line 438 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = DIV_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 53:
#line 445 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = MOD_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 54:
#line 452 "parse.y"
    {
		binary_expr * tmp = new binary_expr();
		tmp -> lchild.reset((yyvsp[(1) - (3)]._expr));
		tmp -> rchild.reset((yyvsp[(3) - (3)]._expr));
		tmp -> op = AND_TYPE;
		(yyval._expr) = tmp;
	}
    break;

  case 55:
#line 459 "parse.y"
    {
		(yyval._expr) = (yyvsp[(1) - (1)]._expr);
	}
    break;

  case 56:
#line 464 "parse.y"
    {
		id_node_value * tmp = new id_node_value();
		tmp -> id = (yyvsp[(1) - (1)]._str);
		(yyval._expr) = tmp;
	}
    break;

  case 59:
#line 471 "parse.y"
    {
		unary_expr * tmp = new unary_expr();
		tmp -> child.reset((yyvsp[(2) - (2)]._expr));
		tmp -> op = NOT;
		(yyval._expr) = tmp;
	}
    break;

  case 60:
#line 477 "parse.y"
    {
		unary_expr * tmp = new unary_expr();
		tmp -> child.reset((yyvsp[(2) - (2)]._expr));
		tmp -> op = MINUS;
		(yyval._expr) = tmp;
	}
    break;

  case 61:
#line 483 "parse.y"
    {
		arr_node_value * tmp = new arr_node_value();
		tmp -> id = (yyvsp[(1) - (4)]._str);
		tmp -> index.reset((yyvsp[(3) - (4)]._expr));
	}
    break;

  case 62:
#line 488 "parse.y"
    {
		record_node_value * tmp = new record_node_value();
		tmp -> id = (yyvsp[(1) - (3)]._str);
		tmp -> member = (yyvsp[(3) - (3)]._str);
		(yyval._expr) = tmp;
	}
    break;

  case 63:
#line 495 "parse.y"
    {
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = INT_TYPE;
		tmp -> value._int = (yyvsp[(1) - (1)]._int);
		(yyval._expr) = tmp;
	}
    break;

  case 64:
#line 502 "parse.y"
    {
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = REAL_TYPE;
		tmp -> value._double = (yyvsp[(1) - (1)]._double);
		(yyval._expr) = tmp;
	}
    break;

  case 65:
#line 508 "parse.y"
    {
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = CHAR_TYPE;
		tmp -> value._double = (yyvsp[(1) - (1)]._char);
		(yyval._expr) = tmp;
	}
    break;

  case 66:
#line 514 "parse.y"
    {
		leaf_node_value * tmp = new leaf_node_value();
		tmp -> type_id = STR_TYPE;
		tmp -> value._str = (yyvsp[(1) - (1)]._str);
		(yyval._expr) = tmp;
	}
    break;

  case 69:
#line 528 "parse.y"
    {
		shared_ptr<base_stmt> tmp((yyvsp[(2) - (3)]._stmt));
		(yyvsp[(1) - (3)]._stmt_list) -> vt.push_back(tmp);
		(yyval._stmt_list) = (yyvsp[(1) - (3)]._stmt_list);
	}
    break;

  case 70:
#line 533 "parse.y"
    {
		(yyval._stmt_list) = new stmt_list();
		shared_ptr<base_stmt> tmp((yyvsp[(1) - (2)]._stmt));
		(yyval._stmt_list) -> vt.push_back(tmp);
	}
    break;

  case 71:
#line 540 "parse.y"
    {
	}
    break;

  case 72:
#line 541 "parse.y"
    {
	}
    break;

  case 73:
#line 545 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(1) - (1)]._stmt);
	}
    break;

  case 74:
#line 548 "parse.y"
    {

		(yyval._stmt) = (yyvsp[(1) - (1)]._stmt);
	}
    break;

  case 75:
#line 552 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(1) - (1)]._stmt);
	}
    break;

  case 76:
#line 555 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(1) - (1)]._stmt);

	}
    break;

  case 77:
#line 559 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(1) - (1)]._stmt);

	}
    break;

  case 78:
#line 563 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(1) - (1)]._stmt);

	}
    break;

  case 79:
#line 567 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(1) - (1)]._stmt);

	}
    break;

  case 80:
#line 571 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(1) - (1)]._proc_stmt);
	}
    break;

  case 81:
#line 576 "parse.y"
    {
		normal_assign * tmp = new normal_assign();	
		tmp -> value.reset((yyvsp[(3) - (3)]._expr));
		tmp -> id = (yyvsp[(1) - (3)]._str);
		(yyval._stmt) = tmp;
	}
    break;

  case 82:
#line 582 "parse.y"
    {
		arr_assign * tmp = new arr_assign();
		tmp -> id = (yyvsp[(1) - (6)]._str);
		tmp -> index.reset((yyvsp[(3) - (6)]._expr));
		tmp -> value.reset((yyvsp[(6) - (6)]._expr));
		(yyval._stmt) = tmp;
	}
    break;

  case 83:
#line 589 "parse.y"
    {
		record_assign * tmp = new record_assign();
		tmp -> id = (yyvsp[(1) - (5)]._str);
		tmp -> member = (yyvsp[(3) - (5)]._str);
		tmp -> value.reset((yyvsp[(5) - (5)]._expr));
		(yyval._stmt) = tmp;
	}
    break;

  case 84:
#line 597 "parse.y"
    {
		if_stmt * tmp = new if_stmt();
		tmp -> judge.reset((yyvsp[(2) - (5)]._expr));
		tmp -> lchild.reset((yyvsp[(4) - (5)]._stmt));
		tmp -> rchild.reset((yyvsp[(5) - (5)]._stmt));
		(yyval._stmt) = tmp;
	}
    break;

  case 85:
#line 605 "parse.y"
    {
		(yyval._stmt) = (yyvsp[(2) - (2)]._stmt);
	}
    break;

  case 86:
#line 608 "parse.y"
    {
		 (yyval._stmt) = nullptr;
		}
    break;

  case 87:
#line 613 "parse.y"
    {
		repeat_stmt * tmp = new repeat_stmt();
		tmp -> stmt_vt.reset((yyvsp[(2) - (4)]._stmt_list));
		tmp -> judge.reset((yyvsp[(4) - (4)]._expr));
		(yyval._stmt) = tmp;
	}
    break;

  case 88:
#line 621 "parse.y"
    {
		while_stmt * tmp = new while_stmt();
		tmp -> judge.reset((yyvsp[(2) - (4)]._expr));
		tmp -> stmt.reset((yyvsp[(4) - (4)]._stmt));
		(yyval._stmt) = tmp;
	}
    break;

  case 89:
#line 628 "parse.y"
    {
		for_stmt * tmp = new for_stmt();
		tmp -> id = (yyvsp[(2) - (8)]._str);
		tmp -> end.reset((yyvsp[(6) - (8)]._expr));
		tmp -> start.reset((yyvsp[(4) - (8)]._expr));
		tmp -> dic = (yyvsp[(5) - (8)]._direction);
		(yyval._stmt) = tmp;
	}
    break;

  case 90:
#line 638 "parse.y"
    {
			(yyval._direction) = 0;
		}
    break;

  case 91:
#line 641 "parse.y"
    {
			(yyval._direction) = 1;
		}
    break;

  case 92:
#line 647 "parse.y"
    {
			case_stmt * tmp = new case_stmt();
			tmp -> expr.reset((yyvsp[(2) - (5)]._expr));
			tmp -> case_list.reset((yyvsp[(4) - (5)]._case_list));
			(yyval._stmt) = tmp;
		}
    break;

  case 93:
#line 654 "parse.y"
    {
		shared_ptr <case_expr> tmp((yyvsp[(2) - (2)]._case_expr));
		(yyvsp[(1) - (2)]._case_list) -> case_vt.push_back(tmp);
		(yyval._case_list) = (yyvsp[(1) - (2)]._case_list);
	}
    break;

  case 94:
#line 659 "parse.y"
    {
			shared_ptr <case_expr> tmp((yyvsp[(1) - (1)]._case_expr));
			(yyval._case_list) = new case_expr_list();
			(yyval._case_list) -> case_vt.push_back(tmp);
		}
    break;

  case 95:
#line 667 "parse.y"
    {	
		case_expr_const * tmp = new case_expr_const();
		tmp -> value.reset((yyvsp[(1) - (4)]._tuple));
		tmp -> stmt.reset((yyvsp[(3) - (4)]._stmt));
		(yyval._case_expr) = tmp;
	}
    break;

  case 96:
#line 673 "parse.y"
    {
			case_expr_id * tmp = new case_expr_id();
			tmp -> id = (yyvsp[(1) - (4)]._str);
			tmp -> stmt.reset((yyvsp[(3) - (4)]._stmt));
			(yyval._case_expr) = tmp;
		}
    break;

  case 97:
#line 681 "parse.y"
    {
		goto_stmt * tmp = new goto_stmt();
		tmp -> addr = (yyvsp[(2) - (2)]._int);
		(yyval._stmt) = tmp;
	}
    break;

  case 99:
#line 689 "parse.y"
    {
          	(yyval._proc_stmt) = new proc_stmt();
          	(yyval._proc_stmt) -> proc_id = (yyvsp[(1) - (1)]._str);
          }
    break;

  case 100:
#line 693 "parse.y"
    {
          	(yyval._proc_stmt) = new proc_stmt();
          	(yyval._proc_stmt) -> proc_id = (yyvsp[(1) - (4)]._str);
          	(yyval._proc_stmt) -> param = *(yyvsp[(3) - (4)]._args_list);
          	delete (yyvsp[(3) - (4)]._args_list);
          }
    break;

  case 102:
#line 701 "parse.y"
    {
	shared_ptr <base_expr> tmp((yyvsp[(3) - (3)]._expr));
	(yyvsp[(1) - (3)]._args_list) -> push_back(tmp);
	(yyval._args_list) = (yyvsp[(1) - (3)]._args_list);
	}
    break;

  case 103:
#line 706 "parse.y"
    {
	(yyval._args_list) = new vector < shared_ptr <base_expr> > ();
	shared_ptr <base_expr> tmp((yyvsp[(1) - (1)]._expr));
	(yyval._args_list) -> push_back(tmp);
	}
    break;

  case 104:
#line 712 "parse.y"
    {
		shared_ptr <routine> tmp((yyvsp[(2) - (2)]._procedure_decl));
		(yyvsp[(1) - (2)]._r_r) -> vt.push_back(tmp);
		(yyval._r_r) = (yyvsp[(1) - (2)]._r_r);
	}
    break;

  case 105:
#line 717 "parse.y"
    {
		shared_ptr <routine> tmp((yyvsp[(2) - (2)]._function));
		(yyvsp[(1) - (2)]._r_r) -> vt.push_back(tmp);
		(yyval._r_r) = (yyvsp[(1) - (2)]._r_r);
	}
    break;

  case 106:
#line 722 "parse.y"
    {
			(yyval._r_r) = new routine_record();
		}
    break;

  case 107:
#line 726 "parse.y"
    {
		(yyval._procedure_decl) = new procedure();
		(yyval._procedure_decl) -> name = (yyvsp[(2) - (6)]._str);
		(yyval._procedure_decl) -> header = (yyvsp[(5) - (6)]._routine) -> header;
		(yyval._procedure_decl) -> stmt_vt = (yyvsp[(5) - (6)]._routine) -> stmt_vt;
		for(auto i = (yyvsp[(3) - (6)]._para_decl_list) -> begin(); i != (yyvsp[(3) - (6)]._para_decl_list) -> end(); ++i){
			for(auto j = i -> second.first.begin(); j != i -> second.first.end(); ++j){
				(yyval._procedure_decl) -> param.push_back(make_pair(i -> first, make_pair(*j, i -> second.second)));
			}
		}
	}
    break;

  case 108:
#line 740 "parse.y"
    {
		(yyval._para_decl_list) = (yyvsp[(2) - (3)]._para_decl_list);
	}
    break;

  case 109:
#line 743 "parse.y"
    {
		(yyval._para_decl_list) = new vector < pair<int, pair <vector <string>, type_ptr> > >();
	}
    break;

  case 110:
#line 748 "parse.y"
    {
		(yyvsp[(1) - (3)]._para_decl_list) -> push_back(*(yyvsp[(3) - (3)]._para_type_list));
		(yyval._para_decl_list) = (yyvsp[(1) - (3)]._para_decl_list);
	}
    break;

  case 111:
#line 752 "parse.y"
    {
			(yyval._para_decl_list) = new vector < pair<int, pair <vector <string>, type_ptr> > >();
			(yyval._para_decl_list) -> push_back(*(yyvsp[(1) - (1)]._para_type_list));
		}
    break;

  case 112:
#line 758 "parse.y"
    {
		(yyval._para_type_list) = new pair<int, pair <vector <string>, type_ptr> >();
			(yyval._para_type_list) -> first = 1;
			(yyval._para_type_list) -> second.first = *(yyvsp[(1) - (3)]._vt);
			(yyval._para_type_list) -> second.second.reset((yyvsp[(3) - (3)]._type));
		}
    break;

  case 113:
#line 764 "parse.y"
    {
		(yyval._para_type_list) = new pair<int, pair <vector <string>, type_ptr> >();
			(yyval._para_type_list) -> first = 0; 
			(yyval._para_type_list) -> second.first = *(yyvsp[(1) - (3)]._vt);
			(yyval._para_type_list) -> second.second.reset((yyvsp[(3) - (3)]._type));
		}
    break;

  case 114:
#line 772 "parse.y"
    {
		(yyval._vt) = (yyvsp[(2) - (2)]._vt);		
	}
    break;

  case 115:
#line 777 "parse.y"
    {
puts("6");

		(yyval._vt) = (yyvsp[(1) - (1)]._vt);
	}
    break;

  case 116:
#line 785 "parse.y"
    {
		(yyval._function) = new func();
		(yyval._function) -> name = (yyvsp[(2) - (8)]._str);
		(yyval._function) -> header = (yyvsp[(7) - (8)]._routine) -> header;
		(yyval._function) -> stmt_vt = (yyvsp[(7) - (8)]._routine) -> stmt_vt;
		for(auto i = (yyvsp[(3) - (8)]._para_decl_list) -> begin(); i != (yyvsp[(3) - (8)]._para_decl_list) -> end(); ++i){
			for(auto j = i -> second.first.begin(); j != i -> second.first.end(); ++j){
				(yyval._function) -> param.push_back(make_pair(i -> first, make_pair(*j, i -> second.second)));
			}
		}
		(yyval._function) -> ret.reset((yyvsp[(5) - (8)]._type));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2742 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 798 "parse.y"

void yyerror(char * s){
	printf("%s\n", s);
	exit(0);
}
int main()
{
	freopen("out.txt", "w", stdout);
	printf("%d\n", yyparse());
}


 



