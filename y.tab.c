/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbolTable.c"
#define YYERROR_VERBOSE

int curtype;
int g_addr = 100;
int i=1,lnum1=0;
int stack[100],index1=0,end[100],arr[10],ct,c,b,fl,top=0,label[20],label_num=0,ltop=0;
char st1[100][10];
int counter = 0;
int plist[100],flist[100],k=-1,errc=0,j=0;
char temp[2]="t";
char null[2]=" ";
int yylex();
void yyerror(const char *s);
int printline();
extern int yylineno;

void scope_start()
{
	stack[index1]=i;
	i++;
	index1++;
	return;
}
void scope_end()
{
	index1--;
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}
void if1()
{
	label_num++;
	strcpy(temp,"t");
	char snum[10];
	sprintf(snum, "%d", counter); 
	strcat(temp,snum);	
	printf("\n%s = not %s\n",temp,st1[top]);
 	printf("if %s goto L%d\n",temp,label_num);
	counter++;
	label[++ltop]=label_num;
}
void if2()
{
	label_num++;
	printf("\ngoto L%d\n",label_num);
	printf("L%d: \n",label[ltop--]);
	label[++ltop]=label_num;
}
void if3()
{
	printf("\nL%d:\n",label[ltop--]);
}
void while1()
{
	label_num++;
	label[++ltop]=label_num;
	printf("\nL%d:\n",label_num);
}
void while2()
{
	label_num++;
	strcpy(temp,"t");
	char snum[10];
	sprintf(snum, "%d", counter); 
	strcat(temp,snum);
	printf("\n%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,label_num);
	counter++;
	label[++ltop]=label_num;
}
void while3()
{
	int y=label[ltop--];
	printf("\ngoto L%d\n",label[ltop--]);
	printf("L%d:\n",y);
}
void dowhile1()
{
	label_num++;
	label[++ltop]=label_num;
	printf("\nL%d:\n",label_num);
}
void dowhile2()
{
 	printf("\nif %s goto L%d\n",st1[top--],label[ltop--]);
}
void for1()
{
	label_num++;
	label[++ltop]=label_num;
	printf("\nL%d:\n",label_num);
}
void for2()
{
	label_num++;
	strcpy(temp,"t");
	char snum[10];
	sprintf(snum, "%d", counter); 
	strcat(temp,snum);
	printf("\n%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,label_num);
	counter++;
	label[++ltop]=label_num;
	label_num++;
	printf("goto L%d\n",label_num);
	label[++ltop]=label_num;
	label_num++;
	printf("L%d:\n",label_num);
	label[++ltop]=label_num;
}
void for3()
{
	printf("\ngoto L%d\n",label[ltop-3]);
	printf("L%d:\n",label[ltop-1]);
}
void for4()
{
	printf("\ngoto L%d\n",label[ltop]);
	printf("L%d:\n",label[ltop-2]);
	ltop-=4;
}
void push(char *a)
{
	strcpy(st1[++top],a);
}
void array1()
{
	strcpy(temp,"t");
	char snum[10];
	sprintf(snum, "%d", counter); 
	strcat(temp,snum);
	printf("\n%s = %s\n",temp,st1[top]);
	strcpy(st1[top],temp);
	counter++;
	strcpy(temp,"t");
	sprintf(snum, "%d", counter); 
	strcat(temp,snum);
	printf("%s = %s [ %s ] \n",temp,st1[top-1],st1[top]);
	top--;
	strcpy(st1[top],temp);
	counter++;
}
void codegen()
{
	strcpy(temp,"t");
	char snum[10];
	sprintf(snum, "%d", counter); 
	strcat(temp,snum);	
	if (strcmp(st1[top-1],"!") == 0 || strcmp(st1[top-1],"++") == 0 
			||  strcmp(st1[top-1],"--") == 0 || strcmp(st1[top-1],"~") == 0)
	{
		printf("\n%s = %s %s\n",temp,st1[top-1],st1[top]);
		top--;
	}
	else
	{
		printf("\n%s = %s %s %s\n",temp,st1[top-2],st1[top-1],st1[top]);		
		int sc = returnscope(st1[top-2],stack[index1-1]);
		if ((isdigit(st1[top-2][0]) == 0) && (isdigit(st1[top][0]) == 0))
		{
			if (returntype(st1[top-2],sc) != returntype(st1[top],sc))
			{
				printf("Type mismatch of %s and %s while performing %s operation\n", st1[top-2], st1[top], st1[top-1]);
			}
		}			
		top-=2;
	}
	strcpy(st1[top],temp);
	counter++;
}
void codegen_umin()
{
	strcpy(temp,"t");
	char snum[10];
	sprintf(snum, "%d", counter); 
	strcat(temp,snum);
	printf("\n%s = -%s\n",temp,st1[top]);
	top--;
	strcpy(st1[top],temp);
	counter++;
}
void codegen_assign()
{

	int scopcur = stack[index1-1];	
	printf("\n%s = %s\n",st1[top-2],st1[top]);
	if (top > 5)
	{
		if (returntype(st1[top-4],scopcur) != returntype(st1[top-2],scopcur) && strncmp(st1[top],"t",1) == 0)
		{
			printf("Type mismatch of %s and %s while performing %s operation\n", st1[top-4], st1[top-2], st1[top-1]);
		}		
	}
	top-=2;
}

#line 270 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    CHAR = 261,
    ID = 262,
    NUM = 263,
    REAL = 264,
    CHARACTER_LITERAL = 265,
    WHILE = 266,
    IF = 267,
    RETURN = 268,
    PREPROC = 269,
    LE = 270,
    STRING = 271,
    PRINT = 272,
    FUNCTION = 273,
    DO = 274,
    ARRAY = 275,
    ELSE = 276,
    STRUCT = 277,
    STRUCT_VAR = 278,
    FOR = 279,
    GE = 280,
    EQ = 281,
    NE = 282,
    INC = 283,
    DEC = 284,
    AND = 285,
    OR = 286,
    NEWLINE = 287,
    ARROW = 288,
    BITWISE_LEFT = 289,
    BITWISE_RIGHT = 290,
    NEQ = 291,
    UMINUS = 292
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define CHAR 261
#define ID 262
#define NUM 263
#define REAL 264
#define CHARACTER_LITERAL 265
#define WHILE 266
#define IF 267
#define RETURN 268
#define PREPROC 269
#define LE 270
#define STRING 271
#define PRINT 272
#define FUNCTION 273
#define DO 274
#define ARRAY 275
#define ELSE 276
#define STRUCT 277
#define STRUCT_VAR 278
#define FOR 279
#define GE 280
#define EQ 281
#define NE 282
#define INC 283
#define DEC 284
#define AND 285
#define OR 286
#define NEWLINE 287
#define ARROW 288
#define BITWISE_LEFT 289
#define BITWISE_RIGHT 290
#define NEQ 291
#define UMINUS 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 218 "parser.y" /* yacc.c:355  */

	int ival;
	char *str;

#line 386 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 403 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    45,    55,     2,
      46,    47,    43,    41,    48,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      37,    39,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    56,    50,     2,     2,     2,     2,
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
      35,    36,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   224,   224,   225,   226,   227,   230,   260,   294,   295,
     298,   306,   307,   308,   309,   312,   315,   316,   319,   320,
     321,   322,   323,   324,   325,   337,   342,   356,   357,   358,
     362,   366,   361,   373,   377,   381,   372,   391,   395,   390,
     401,   405,   409,   413,   408,   422,   423,   424,   425,   426,
     427,   431,   435,   439,   430,   460,   467,   468,   477,   553,
     554,   555,   564,   565,   569,   573,   577,   568,   615,   614,
     653,   670,   723,   724,   729,   734,   739,   738,   746,   745,
     754,   753,   762,   761,   770,   769,   778,   777,   786,   785,
     794,   793,   801,   803,   807,   802,   815,   819,   814,   827,
     831,   826,   839,   843,   838,   851,   855,   850,   863,   867,
     862,   875,   879,   874,   886,   890,   885,   898,   902,   897,
     910,   914,   909,   921,   928,   927,   936,   935,   943,   946,
     951,   950,   959,   964
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "CHAR", "ID",
  "NUM", "REAL", "CHARACTER_LITERAL", "WHILE", "IF", "RETURN", "PREPROC",
  "LE", "STRING", "PRINT", "FUNCTION", "DO", "ARRAY", "ELSE", "STRUCT",
  "STRUCT_VAR", "FOR", "GE", "EQ", "NE", "INC", "DEC", "AND", "OR",
  "NEWLINE", "ARROW", "BITWISE_LEFT", "BITWISE_RIGHT", "NEQ", "'<'", "'>'",
  "'='", "UMINUS", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "','",
  "'{'", "'}'", "';'", "'['", "']'", "'!'", "'&'", "'|'", "'^'", "$accept",
  "start", "Function", "parameter_list", "parameter", "Type",
  "CompoundStmt", "StmtList", "stmt", "dowhile", "$@1", "$@2", "for",
  "$@3", "$@4", "$@5", "if", "$@6", "$@7", "else", "while", "$@8", "$@9",
  "assignment", "assignment1", "$@10", "$@11", "$@12", "consttype",
  "enddec", "Declaration", "$@13", "$@14", "$@15", "$@16", "array", "$@17",
  "E", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25",
  "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34",
  "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42", "$@43",
  "$@44", "T", "$@45", "$@46", "F", "$@47", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    60,    62,    61,
     292,    43,    45,    42,    47,    37,    40,    41,    44,   123,
     125,    59,    91,    93,    33,    38,   124,    94
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -121

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     219,   -82,   -82,   -82,   -82,   -82,   -29,   -82,   -82,   -82,
     219,    -4,    86,   219,     1,    55,    43,   219,    32,    32,
      41,   -82,     8,   -82,   -82,    -8,   239,   -82,   -82,    32,
     -82,   -34,   -82,    54,   -82,    55,   239,    45,    68,    73,
      55,   110,   -82,   -82,    55,    20,   -82,    70,    69,    17,
     -82,   116,    99,    81,    89,   -82,   -82,   -18,   -82,   161,
     -82,    20,   -82,   -82,   -82,   173,    12,   -82,    55,   -82,
     -82,    69,   150,   -82,   122,    68,    68,    55,    68,    20,
      90,   129,   132,   134,   138,   103,   119,   121,   143,   145,
     142,    80,    94,    20,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   160,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   173,    20,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   173,    20,    20,
      80,    80,    80,    80,    80,    80,   184,   -82,   139,    63,
     148,   -82,   155,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,    55,    74,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,   154,   154,    12,    12,    12,    12,
     -82,   -82,   158,   156,    20,   170,   -82,   180,   190,    69,
      20,   -82,   -82,   154,   154,   154,   154,   173,   173,   173,
     154,   154,   154,   183,    20,   221,   -82,   -82,   165,   226,
     173,   -82,   223,   -82,   187,   193,   199,   -82,    69,   -82,
      20,    20,    69,   -82,   241,   173,   -82,   238,   -82,   209,
      69,   -82,   215,    20,   -82,   -82,   173,   220,    69,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    75,    11,    12,    13,    14,    51,    59,    60,    61,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     3,     0,     1,     2,    68,     0,    63,    70,     0,
       4,    57,    55,     0,    52,     0,     0,     0,     0,     0,
       0,     0,    62,    56,     0,     0,    74,     0,     0,     0,
       9,     0,    49,     0,    50,    65,    69,    68,    72,   132,
     130,     0,    86,   133,   123,    53,    92,   128,     0,    17,
       6,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    90,    82,    84,    78,    80,
      54,   124,   126,    73,     0,     7,     8,    45,    46,    47,
      71,    48,    66,     0,    94,    97,   100,   103,   106,   109,
     112,   115,   118,   121,   132,   131,   129,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    42,     0,     0,
       0,    30,     0,    15,    27,    29,    16,    22,    23,    19,
      21,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    91,    83,    85,    79,    81,
     125,   127,     0,     0,     0,     0,    25,     0,     0,     0,
       0,    67,    77,    95,    98,   101,   104,   107,   110,   113,
     116,   119,   122,     0,     0,     0,    26,    24,     0,     0,
      33,    20,     0,    37,     0,     0,     0,    43,     0,    28,
       0,     0,     0,    38,     0,    34,    44,    41,    31,     0,
       0,    39,     0,     0,    40,    32,    35,     0,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   135,   -82,   -82,   197,   -25,   -69,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -15,    40,   -82,   -82,   -82,     7,   -31,
     -20,   -82,   -82,   -82,   -82,   -82,   -82,   -61,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,    60,   -82,   -82,   -81,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    49,    50,    14,    70,   104,   146,   147,
     179,   222,   148,   206,   219,   227,   149,   208,   217,   221,
     150,   173,   212,    53,    15,    20,    45,   100,    63,    28,
      17,    39,    79,   152,    40,    64,    80,    65,   132,   133,
     130,   131,    93,   128,   129,    81,   154,    82,   155,    83,
     156,    84,   157,    85,   158,    86,   159,    87,   160,    88,
     161,    89,   162,    90,   163,    66,   134,   135,    67,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    41,   105,    22,    46,   -51,    42,    16,    25,    56,
     125,    41,    51,    58,    18,    35,    47,    16,   112,    18,
      16,   -64,   -57,    19,    16,    16,    16,    59,     7,     8,
       9,   -64,   127,    16,    38,   145,    16,   103,    37,    31,
       7,     8,     9,    16,    38,    54,   110,    51,     2,     3,
       4,     5,   153,   170,   171,   101,   102,    36,    32,    33,
     108,   109,    60,   111,    71,    72,    61,   164,   165,    43,
     175,     7,     8,     9,    62,    52,     7,     8,     9,    41,
      34,   107,    54,    54,   151,    54,    23,   124,     7,     8,
       9,    29,    48,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    26,    94,    95,    27,    44,    96,    97,
     199,    16,    55,   195,   176,    98,    99,    57,    69,   200,
      68,   181,    60,    73,    94,    95,    61,   182,    96,    97,
       7,     8,     9,   202,    77,    98,    99,    78,    74,   213,
      75,   126,   113,   216,   114,    21,   177,    76,    24,   214,
     215,   224,    30,     2,     3,     4,     5,   115,   118,   229,
     116,     1,   226,     2,     3,     4,     5,   136,     7,     8,
       9,   137,   138,   139,   117,   119,   -93,   140,   120,   141,
     121,   123,    11,   122,   142,   174,   -96,   -99,    96,    97,
     166,   167,   168,   169,   178,    98,    99,  -102,  -114,  -117,
    -120,   180,   194,    94,    95,   193,   198,    96,    97,    69,
     143,   144,   204,   -76,    98,    99,  -105,  -108,  -111,    -5,
       1,   196,     2,     3,     4,     5,     6,     7,     8,     9,
     172,   197,    18,    10,   201,   -57,    19,   205,   209,   210,
       1,    11,     2,     3,     4,     5,     6,     7,     8,     9,
     211,    94,    95,    94,    95,    96,    97,    96,    97,   220,
     223,    11,    98,    99,    98,    99,   225,   228,   203,   106,
     207,    94,    95,     0,     0,    96,    97,     0,     0,     0,
       0,     0,    98,    99,     0,     0,     0,     0,   218
};

static const yytype_int16 yycheck[] =
{
      61,    26,    71,     7,    35,    39,    26,     0,     7,    40,
      91,    36,    37,    44,    48,     7,    36,    10,    79,    48,
      13,    39,    51,    52,    17,    18,    19,     7,     8,     9,
      10,    39,    93,    26,    52,   104,    29,    68,    46,     7,
       8,     9,    10,    36,    52,    38,    77,    72,     3,     4,
       5,     6,   113,   134,   135,    43,    44,    49,    18,    19,
      75,    76,    42,    78,    47,    48,    46,   128,   129,    29,
       7,     8,     9,    10,    54,     7,     8,     9,    10,   104,
      39,    74,    75,    76,   104,    78,     0,     7,     8,     9,
      10,    48,    47,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    48,    30,    31,    51,    53,    34,    35,
     179,   104,    39,   174,    51,    41,    42,     7,    49,   180,
      50,   152,    42,     7,    30,    31,    46,    53,    34,    35,
       8,     9,    10,   194,    53,    41,    42,    48,    39,   208,
      41,    47,    52,   212,    15,    10,   139,    48,    13,   210,
     211,   220,    17,     3,     4,     5,     6,    25,    55,   228,
      26,     1,   223,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    36,    56,    15,    17,    57,    19,
      37,    39,    22,    38,    24,    46,    25,    26,    34,    35,
     130,   131,   132,   133,    46,    41,    42,    36,    37,    38,
      39,    46,    46,    30,    31,    47,    16,    34,    35,    49,
      50,    51,    47,    52,    41,    42,    55,    56,    57,     0,
       1,    51,     3,     4,     5,     6,     7,     8,     9,    10,
      46,    51,    48,    14,    51,    51,    52,    11,    51,    46,
       1,    22,     3,     4,     5,     6,     7,     8,     9,    10,
      51,    30,    31,    30,    31,    34,    35,    34,    35,    21,
      51,    22,    41,    42,    41,    42,    51,    47,    47,    72,
      47,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      14,    22,    59,    60,    63,    82,    86,    88,    48,    52,
      83,    59,     7,     0,    59,     7,    48,    51,    87,    48,
      59,     7,    82,    82,    39,     7,    49,    46,    52,    89,
      92,    63,    88,    82,    53,    84,    87,    88,    47,    61,
      62,    63,     7,    81,    86,    39,    87,     7,    87,     7,
      42,    46,    54,    86,    93,    95,   123,   126,    50,    49,
      64,    47,    48,     7,    39,    41,    48,    53,    48,    90,
      94,   103,   105,   107,   109,   111,   113,   115,   117,   119,
     121,   127,    95,   100,    30,    31,    34,    35,    41,    42,
      85,    43,    44,    87,    65,    64,    62,    86,    81,    81,
      87,    81,    95,    52,    15,    25,    26,    36,    55,    56,
      57,    37,    38,    39,     7,   126,    47,    95,   101,   102,
      98,    99,    96,    97,   124,   125,     7,    11,    12,    13,
      17,    19,    24,    50,    51,    64,    66,    67,    70,    74,
      78,    88,    91,    95,   104,   106,   108,   110,   112,   114,
     116,   118,   120,   122,    95,    95,   123,   123,   123,   123,
     126,   126,    46,    79,    46,     7,    51,    86,    46,    68,
      46,    87,    53,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    47,    46,    95,    51,    51,    16,    64,
      95,    51,    95,    47,    47,    11,    71,    47,    75,    51,
      46,    51,    80,    64,    95,    95,    64,    76,    47,    72,
      21,    77,    69,    51,    64,    51,    95,    73,    47,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    63,    63,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      68,    69,    67,    71,    72,    73,    70,    75,    76,    74,
      77,    77,    79,    80,    78,    81,    81,    81,    81,    81,
      81,    83,    84,    85,    82,    82,    82,    82,    82,    86,
      86,    86,    87,    87,    89,    90,    91,    88,    92,    88,
      88,    88,    88,    88,    88,    88,    94,    93,    96,    95,
      97,    95,    98,    95,    99,    95,   100,    95,   101,    95,
     102,    95,    95,   103,   104,    95,   105,   106,    95,   107,
     108,    95,   109,   110,    95,   111,   112,    95,   113,   114,
      95,   115,   116,    95,   117,   118,    95,   119,   120,    95,
     121,   122,    95,    95,   124,   123,   125,   123,   123,   126,
     127,   126,   126,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     6,     3,     1,
       2,     1,     1,     1,     1,     3,     2,     0,     1,     1,
       4,     1,     1,     1,     3,     2,     3,     1,     5,     1,
       0,     0,     9,     0,     0,     0,    12,     0,     0,     8,
       2,     0,     0,     0,     7,     3,     3,     3,     3,     1,
       1,     0,     0,     0,     6,     3,     3,     1,     1,     1,
       1,     1,     2,     1,     0,     0,     0,     8,     0,     4,
       2,     6,     5,     6,     4,     1,     0,     5,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     0,     4,
       0,     4,     1,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     1,     0,     4,     0,     4,     1,     3,
       0,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
        case 6:
#line 231 "parser.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-3].str),"main")!=0)
	{
		printf("goto F%d\n",lnum1);
	}

	/*
	if ($1!=returntype_func(ct))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}
	*/

	if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && 
			strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") 
				&& strcmp ((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") 
					&& strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") 
						&& strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush")))
	{
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
	}		
	else
	{
		insert((yyvsp[-3].str),FUNCTION);
		insert((yyvsp[-3].str),(yyvsp[-4].ival));
		g_addr+=4;
	}
}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 261 "parser.y" /* yacc.c:1646  */
    {
	if ((yyvsp[-5].ival)!=returntype_func(ct))
	{
		printf("\nError : Type mismatch : Line %d\n",printline()); 
		errc++;
	}

	if (!(strcmp((yyvsp[-4].str),"printf") && strcmp((yyvsp[-4].str),"scanf") &&
			strcmp((yyvsp[-4].str),"getc") && strcmp((yyvsp[-4].str),"gets") && 
				strcmp((yyvsp[-4].str),"getchar") && strcmp ((yyvsp[-4].str),"puts") && 
					strcmp((yyvsp[-4].str),"putchar") && strcmp((yyvsp[-4].str),"clearerr") 
						&& strcmp((yyvsp[-4].str),"getw") && strcmp((yyvsp[-4].str),"putw") && 
							strcmp((yyvsp[-4].str),"putc") && strcmp((yyvsp[-4].str),"rewind") && 
								strcmp((yyvsp[-4].str),"sprint") && strcmp((yyvsp[-4].str),"sscanf") && 
									strcmp((yyvsp[-4].str),"remove") && strcmp((yyvsp[-4].str),"fflush")))
	{
		printf("Error : Redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());
		errc++;
	}

	else
	{
		insert((yyvsp[-4].str),FUNCTION);
		insert((yyvsp[-4].str),(yyvsp[-5].ival));
		for(j=0;j<=k;j++)
		{
			insertp((yyvsp[-4].str),plist[j]);
		}
		k=-1;
	}
}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 299 "parser.y" /* yacc.c:1646  */
    {
	plist[++k]=(yyvsp[-1].ival);
	insert((yyvsp[0].str),(yyvsp[-1].ival));
	insertscope((yyvsp[0].str),i);
}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 326 "parser.y" /* yacc.c:1646  */
    {
	if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str))))
	{
		storereturn(ct,FLOAT);
	}
	else
	{
		storereturn(ct,INT);
	}
	ct++;
}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 338 "parser.y" /* yacc.c:1646  */
    {
	storereturn(ct,VOID); 
	ct++;
}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 343 "parser.y" /* yacc.c:1646  */
    {
    int sct=returnscope((yyvsp[-1].str),stack[top-1]);	//stack[top-1] - current scope
	int type=returntype((yyvsp[-1].str),sct);
    if (type==259) 
	{
		storereturn(ct,FLOAT);
	}
    else
	{
		storereturn(ct,INT);
	}
    ct++;
}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 362 "parser.y" /* yacc.c:1646  */
    {
	dowhile1();
}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 366 "parser.y" /* yacc.c:1646  */
    {
	dowhile2();
}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 373 "parser.y" /* yacc.c:1646  */
    {
	for1();
}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 377 "parser.y" /* yacc.c:1646  */
    {
	for2();
}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 381 "parser.y" /* yacc.c:1646  */
    {
	for3();
}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 385 "parser.y" /* yacc.c:1646  */
    {
	for4();
}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 391 "parser.y" /* yacc.c:1646  */
    {
	if1();
}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 395 "parser.y" /* yacc.c:1646  */
    {
	if2();
}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 402 "parser.y" /* yacc.c:1646  */
    {
	if3();
}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 409 "parser.y" /* yacc.c:1646  */
    {
	while1();
}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 413 "parser.y" /* yacc.c:1646  */
    {
	while2();
}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 417 "parser.y" /* yacc.c:1646  */
    {
	while3();
}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 431 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 435 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"=");
}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 439 "parser.y" /* yacc.c:1646  */
    {
	codegen_assign();
}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 442 "parser.y" /* yacc.c:1646  */
    {
	int sct=returnscope((yyvsp[-5].str),stack[index1-1]);
	int type=returntype((yyvsp[-5].str),sct);
	if((!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && type==258 && fl==0)
	{
		printf("\nError : Type Mismatch : Line %d\n",printline());
	}			
	if(!lookup((yyvsp[-5].str)))
	{
		int currscope=stack[index1-1];
		int scope=returnscope((yyvsp[-5].str),currscope);
		if((scope<=currscope && end[scope]==0) && !(scope==0))
		{
			check_scope_update((yyvsp[-5].str),(yyvsp[-1].str),currscope);
		}
	}
}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 461 "parser.y" /* yacc.c:1646  */
    {
	if(lookup((yyvsp[-2].str)))
	{
		printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
	}						
}
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 469 "parser.y" /* yacc.c:1646  */
    {
	if(lookup((yyvsp[0].str)))
	{
		printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
	}		
}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 569 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 573 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"=");
}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 577 "parser.y" /* yacc.c:1646  */
    {
	codegen_assign();
}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 581 "parser.y" /* yacc.c:1646  */
    {
	if( (!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival)==258 && (fl==0))
	{
		printf("\nError : Type Mismatch : Line %d\n",printline());
		fl=1;
	}
	curtype = (yyvsp[-7].ival);
	if(!lookup((yyvsp[-6].str)))
	{
		int currscope=stack[index1-1];
		int previous_scope=returnscope((yyvsp[-6].str),currscope);
		if(currscope==previous_scope)
		{
			printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-6].str),printline());
		}				
		else
		{
			insert_dup((yyvsp[-6].str),(yyvsp[-7].ival),currscope);
			check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
			int sg=returnscope((yyvsp[-6].str),stack[index1-1]);
			g_addr+=4;
		}			
	}
	else
	{
		int scope=stack[index1-1];
		insert((yyvsp[-6].str),(yyvsp[-7].ival));
		insertscope((yyvsp[-6].str),scope);
		check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
		g_addr+=4;
	}
}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 615 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 619 "parser.y" /* yacc.c:1646  */
    {
	/*
	if( (!(strspn($3,"0123456789")==strlen($8))) && $1==258 && (fl==0))
	{
		printf("\nError : Type Mismatch : Line %d\n",printline());
		fl=1;
	}
	*/
	curtype = (yyvsp[-3].ival);
	if(!lookup((yyvsp[-2].str)))
	{
		int currscope=stack[index1-1];
		int previous_scope=returnscope((yyvsp[-2].str),currscope);
		if(currscope==previous_scope)
		{
			printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-2].str),printline());
		}				
		else		
		{
			insert_dup((yyvsp[-2].str),(yyvsp[-3].ival),currscope);
			check_scope_update((yyvsp[-2].str),"0",stack[index1-1]);
			int sg=returnscope((yyvsp[-2].str),stack[index1-1]);
			g_addr+=4;
		}
	}
	else
	{
		int scope=stack[index1-1];
		insert((yyvsp[-2].str),(yyvsp[-3].ival));
		insertscope((yyvsp[-2].str),scope);
		check_scope_update((yyvsp[-2].str),"0",stack[index1-1]);
		g_addr+=4;
	}
}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 654 "parser.y" /* yacc.c:1646  */
    {
	if(!lookup((yyvsp[-1].str)))
	{
		int currscope=stack[index1-1];
		int scope=returnscope((yyvsp[-1].str),currscope);
		if(!(scope<=currscope && end[scope]==0) || scope==0)
		{
			printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
		}						
	}
	else // lookup($1)
	{
		printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
	}		
}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 671 "parser.y" /* yacc.c:1646  */
    {
	int itype;
	if(!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) 
	{
		itype=259;
	}
	else 
	{
		itype = 258;
	}
	if(itype!=258)
	{ 
		printf("\nError : Array index must be of type int : Line %d\n",printline());
		errc++;
	}
	if(atoi((yyvsp[-2].str))<=0)
	{ 
		printf("\nError : Array index must be of type int > 0 : Line %d\n",printline());
		errc++;
	}
	if(!lookup((yyvsp[-4].str)))
	{
		int currscope=stack[top-1];
		int previous_scope=returnscope((yyvsp[-4].str),currscope);
		if(currscope==previous_scope)
		{
			printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());
			errc++;
		}
		else
		{
			insert_dup((yyvsp[-4].str),ARRAY,currscope);
			insert_by_scope((yyvsp[-4].str),(yyvsp[-5].ival),currscope);	//to insert type to the correct identifier in case of multiple entries of the identifier by using scope
			if (itype==258)
			{
				insert_index((yyvsp[-4].str),(yyvsp[-2].str));
			}
		}
	}
	else
	{
		int scope=stack[top-1];
		insert((yyvsp[-4].str),ARRAY);
		insert((yyvsp[-4].str),(yyvsp[-5].ival));
		insertscope((yyvsp[-4].str),scope);
		if (itype==258) 
		{
			insert_index((yyvsp[-4].str),(yyvsp[-2].str));
		}
	}
}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 725 "parser.y" /* yacc.c:1646  */
    {
	insert((yyvsp[-4].str),STRUCT);
	g_addr+=4;
}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 730 "parser.y" /* yacc.c:1646  */
    {
	insert((yyvsp[-1].str),STRUCT_VAR);
	g_addr+=4;
}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 739 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 746 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"+");
}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 750 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 754 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"-");
}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 758 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 762 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"<<");
}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 766 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 770 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],">>");
}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 774 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 778 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"!");
}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 782 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 786 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"&&");
}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 790 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 794 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"||");
}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 798 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 803 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 807 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"<=");
}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 811 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 815 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 819 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],">=");
}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 823 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 827 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 831 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"==");
}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 835 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 839 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 843 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"!=");
}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 847 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 851 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 855 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"&");
}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 859 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 863 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 867 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"|");
}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 871 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 875 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 879 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"^");
}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 882 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 886 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 890 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"<");
}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 894 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 898 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 902 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],">");
}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 906 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 910 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 914 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"=");
}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 918 "parser.y" /* yacc.c:1646  */
    {
	codegen_assign();
}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 922 "parser.y" /* yacc.c:1646  */
    {
	array1();
}
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 928 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"*");
}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 932 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 936 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"/");
}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 940 "parser.y" /* yacc.c:1646  */
    {
	codegen();
}
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 947 "parser.y" /* yacc.c:1646  */
    {
	(yyval.str)=(yyvsp[-1].str);
}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 951 "parser.y" /* yacc.c:1646  */
    {
	strcpy(st1[++top],"-");
}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 955 "parser.y" /* yacc.c:1646  */
    {
	codegen_umin();
}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 960 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
	fl=1;
}
#line 2579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 965 "parser.y" /* yacc.c:1646  */
    {
	push((yyvsp[0].str));
}
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2591 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 970 "parser.y" /* yacc.c:1906  */


#include "lex.yy.c"
#include<ctype.h>

int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	yyparse();
	if(!yyparse())
	{
		printf("Parsing done\n");
		print();
	}
	else
	{
		printf("Error \n");
	}
	fclose(yyin);
	return 0;
}

void yyerror(const char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}
int printline()
{
	return yylineno;
}
