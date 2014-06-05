/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 190 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

