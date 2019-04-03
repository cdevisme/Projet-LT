%{
/* Fichier fichier1.lex */
#include "yystype.h"
#include "yygrammar.h"

char err[20]; /* Chaine de caracteres pour les erreurs de syntaxe */

// .                   { sprintf(err,"Mauvais caractere %c",yytext[0]);
//                       yyerror(err);    /* Generation d'une erreur de syntaxe */
//                     }

%}

/* Definition de macros */
chiffre         [0-9]
lettre          [a-zA-Zéàùïäüöçëêôûâîè]
caractere       [\-;,:\.'\(\)]
espace          [ ]
sep             [\t\n]

%%

"\\begin\{document\}"   return BEGIN_DOC;    
"\\end\{document\}"     return END_DOC;
"\\title"               return TITLE;
"\\author"              return AUTHOR;
"\\date"                return DATE;
"\\maketitle"           return MAKETITLE;
"\\section"             return SEC;
"\\subsection"          return SUBSEC;
"\\subsubsection"       return SUBSUBSEC;
"\\textbf"              return GRAS;
"\\textit"              return ITALIQUE;
"\\begin\{itemize\}"    return BEGIN_ITEMIZE;
"\\end\{itemize\}"      return END_ITEMIZE;
"\\begin\{enumerate\}"  return BEGIN_ENUM;
"\\end\{enumerate\}"    return END_ENUM;
"\\item"                return ITEM;
"\\\\"                  return LIGNE;
"\\ldots"               return DOTS;

({lettre}|{caractere}|{chiffre}|{espace})+       {yylval.valChaine=(char*) malloc(strlen(yytext)*sizeof(char)+1); strcpy(yylval.valChaine, yytext); return MOT;}

{sep}                ;

"\{"                 return ACCOUV;
"\}"                 return ACCFER;




%%
