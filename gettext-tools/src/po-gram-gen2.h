/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_PO_GRAM_PO_GRAM_GEN_TAB_H_INCLUDED
# define YY_PO_GRAM_PO_GRAM_GEN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef PO_GRAM_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PO_GRAM_DEBUG 1
#  else
#   define PO_GRAM_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PO_GRAM_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PO_GRAM_DEBUG */
#if PO_GRAM_DEBUG
extern DLL_VARIABLE int po_gram_debug;
#endif

/* Token type.  */
#ifndef PO_GRAM_TOKENTYPE
# define PO_GRAM_TOKENTYPE
  enum po_gram_tokentype
  {
    COMMENT = 258,
    DOMAIN = 259,
    JUNK = 260,
    PREV_MSGCTXT = 261,
    PREV_MSGID = 262,
    PREV_MSGID_PLURAL = 263,
    PREV_STRING = 264,
    MSGCTXT = 265,
    MSGID = 266,
    MSGID_PLURAL = 267,
    MSGSTR = 268,
    NAME = 269,
    NUMBER = 270,
    STRING = 271
  };
#endif

/* Value type.  */
#if ! defined PO_GRAM_STYPE && ! defined PO_GRAM_STYPE_IS_DECLARED

union PO_GRAM_STYPE
{
#line 103 "po-gram-gen.y" /* yacc.c:1909  */

  struct { char *string; lex_pos_ty pos; bool obsolete; } string;
  struct { string_list_ty stringlist; lex_pos_ty pos; bool obsolete; } stringlist;
  struct { long number; lex_pos_ty pos; bool obsolete; } number;
  struct { lex_pos_ty pos; bool obsolete; } pos;
  struct { char *ctxt; char *id; char *id_plural; lex_pos_ty pos; bool obsolete; } prev;
  struct { char *prev_ctxt; char *prev_id; char *prev_id_plural; char *ctxt; lex_pos_ty pos; bool obsolete; } message_intro;
  struct { struct msgstr_def rhs; lex_pos_ty pos; bool obsolete; } rhs;

#line 89 "po-gram-gen2.h" /* yacc.c:1909  */
};

typedef union PO_GRAM_STYPE PO_GRAM_STYPE;
# define PO_GRAM_STYPE_IS_TRIVIAL 1
# define PO_GRAM_STYPE_IS_DECLARED 1
#endif


extern DLL_VARIABLE PO_GRAM_STYPE po_gram_lval;

int po_gram_parse (void);

#endif /* !YY_PO_GRAM_PO_GRAM_GEN_TAB_H_INCLUDED  */
