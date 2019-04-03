#line 3 "V3.acc"
 /* Code C */
    /* Inclusion de bibliotheques C */
    #include <stdio.h>
    #include <malloc.h>
    #include "yystype.h"

    /* Action de fin d analyse */
    void fin_analyse(){
    }

    /*Action qui vérifie le nombre d'options*/
    void nb_options(int a, int d, int t){
        int error=0;
        if(a>1) {printf("Erreur ! trop de commandes 'author' declarees\n"); error+=1;}
        if(d>1) {printf("Erreur ! trop de commandes 'date' declarees\n"); error+=1;}
        if(t>1) {printf("Erreur ! trop de commandes 'title' declarees\n"); error+=1;}
        if(error !=0) yyerror("\nRevoir le nombre d'options du debut de document\n");
    }


# line 23 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 40: {
      racine();
      get_lexval();
      } break;
   }
}

racine ()
{
   switch(yyselect()) {
   case 1: {
      debut();
#line 29 "V3.acc"
fin_analyse();
# line 43 "yygrammar.c"
      } break;
   }
}

debut ()
{
   int nba;
   int nbd;
   int nbt;
   switch(yyselect()) {
   case 2: {
#line 31 "V3.acc"
if(nbt!=1 || nba!=1) printf("<title>");
# line 57 "yygrammar.c"
      options(&nba, &nbd, &nbt);
#line 31 "V3.acc"
if(nbt==1) printf("</title>");
# line 61 "yygrammar.c"
#line 31 "V3.acc"
nb_options(nba, nbd, nbt);
# line 64 "yygrammar.c"
      get_lexval();
#line 31 "V3.acc"
printf("<!doctype html>\n<html>\n<head>\n<meta charset=\"utf-8\">");
# line 68 "yygrammar.c"
      maketitle();
#line 31 "V3.acc"
printf("\n</head>\n<body>");
# line 72 "yygrammar.c"
      contenu();
      get_lexval();
#line 31 "V3.acc"
printf("\n</body>\n</html>");
# line 77 "yygrammar.c"
      } break;
   }
}

options (nba, nbd, nbt)
   int *nba;
   int *nbd;
   int *nbt;
{
   int nba1;
   int nbd1;
   int nbt1;
   switch(yyselect()) {
   case 3: {
      get_lexval();
      get_lexval();
      mot();
      get_lexval();
      options(&nba1, &nbd1, &nbt1);
#line 37 "V3.acc"
*nba=nba1+1; *nbd=nbd1; *nbt=nbt1;
# line 99 "yygrammar.c"
      } break;
   case 4: {
      get_lexval();
      get_lexval();
      mot();
      get_lexval();
      options(&nba1, &nbd1, &nbt1);
#line 38 "V3.acc"
*nba=nba1; *nbd=nbd1+1; *nbt=nbt1;
# line 109 "yygrammar.c"
      } break;
   case 5: {
      get_lexval();
      get_lexval();
      mot();
      get_lexval();
      options(&nba1, &nbd1, &nbt1);
#line 39 "V3.acc"
*nba=nba1; *nbd=nbd1; *nbt=nbt1+1;
# line 119 "yygrammar.c"
      } break;
   case 6: {
#line 40 "V3.acc"
*nba=0; *nbd=0; *nbt=0;
# line 124 "yygrammar.c"
      } break;
   }
}

maketitle ()
{
   switch(yyselect()) {
   case 7: {
      get_lexval();
      } break;
   case 8: {
      } break;
   }
}

commande ()
{
   switch(yyselect()) {
   case 9: {
      get_lexval();
#line 47 "V3.acc"
printf("<br/>");
# line 147 "yygrammar.c"
      } break;
   case 10: {
      get_lexval();
#line 48 "V3.acc"
printf("<b>");
# line 153 "yygrammar.c"
      get_lexval();
      mot();
      get_lexval();
#line 48 "V3.acc"
printf("</b>");
# line 159 "yygrammar.c"
      } break;
   case 11: {
      get_lexval();
#line 49 "V3.acc"
printf("<i>");
# line 165 "yygrammar.c"
      get_lexval();
      mot();
      get_lexval();
#line 49 "V3.acc"
printf("</i>");
# line 171 "yygrammar.c"
      } break;
   case 12: {
      get_lexval();
#line 50 "V3.acc"
printf("...");
# line 177 "yygrammar.c"
      } break;
   case 13: {
      } break;
   }
}

mot ()
{
   YYSTYPE val;
   switch(yyselect()) {
   case 14: {
      commande();
      mot();
      } break;
   case 15: {
      get_lexval();
      val = yylval;
#line 54 "V3.acc"
printf("\n%s", val.valChaine);
# line 197 "yygrammar.c"
      commande();
      mot();
      } break;
   case 16: {
      } break;
   }
}

contenu ()
{
   switch(yyselect()) {
   case 17: {
      commande();
      contenu();
      } break;
   case 18: {
      mot();
      contenu();
      } break;
   case 19: {
      liste();
      contenu();
      } break;
   case 20: {
      num();
      contenu();
      } break;
   case 21: {
      section();
      } break;
   case 22: {
      } break;
   }
}

liste ()
{
   switch(yyselect()) {
   case 23: {
      get_lexval();
#line 64 "V3.acc"
printf("<ul>");
# line 240 "yygrammar.c"
      mot();
      item();
      get_lexval();
#line 64 "V3.acc"
printf("</ul>");
# line 246 "yygrammar.c"
      } break;
   case 24: {
      get_lexval();
#line 65 "V3.acc"
printf("<ul>");
# line 252 "yygrammar.c"
      liste();
      get_lexval();
#line 65 "V3.acc"
printf("</ul>");
# line 257 "yygrammar.c"
      } break;
   case 25: {
      get_lexval();
#line 66 "V3.acc"
printf("<ul>");
# line 263 "yygrammar.c"
      num();
      get_lexval();
#line 66 "V3.acc"
printf("</ul>");
# line 268 "yygrammar.c"
      } break;
   }
}

num ()
{
   switch(yyselect()) {
   case 26: {
      get_lexval();
#line 68 "V3.acc"
printf("<ol>");
# line 280 "yygrammar.c"
      mot();
      item();
      get_lexval();
#line 68 "V3.acc"
printf("</ol>");
# line 286 "yygrammar.c"
      } break;
   case 27: {
      get_lexval();
#line 69 "V3.acc"
printf("<ol>");
# line 292 "yygrammar.c"
      liste();
      get_lexval();
#line 69 "V3.acc"
printf("</ol>");
# line 297 "yygrammar.c"
      } break;
   case 28: {
      get_lexval();
#line 70 "V3.acc"
printf("<ol>");
# line 303 "yygrammar.c"
      num();
      get_lexval();
#line 70 "V3.acc"
printf("</ol>");
# line 308 "yygrammar.c"
      } break;
   }
}

item ()
{
   switch(yyselect()) {
   case 29: {
      get_lexval();
#line 72 "V3.acc"
printf("<li>");
# line 320 "yygrammar.c"
      mot();
#line 72 "V3.acc"
printf("</li>");
# line 324 "yygrammar.c"
      fin();
      } break;
   case 30: {
      get_lexval();
#line 73 "V3.acc"
printf("<li>");
# line 331 "yygrammar.c"
      mot();
#line 73 "V3.acc"
printf("</li>");
# line 335 "yygrammar.c"
      liste();
      fin();
      } break;
   case 31: {
      get_lexval();
#line 74 "V3.acc"
printf("<li>");
# line 343 "yygrammar.c"
      mot();
#line 74 "V3.acc"
printf("</li>");
# line 347 "yygrammar.c"
      num();
      fin();
      } break;
   }
}

fin ()
{
   switch(yyselect()) {
   case 32: {
      item();
      } break;
   case 33: {
      } break;
   }
}

section ()
{
   switch(yyselect()) {
   case 34: {
#line 80 "V3.acc"
printf("\n<h1>");
# line 371 "yygrammar.c"
      get_lexval();
      get_lexval();
      mot();
      get_lexval();
#line 80 "V3.acc"
printf("\n</h1>");
# line 378 "yygrammar.c"
      contenu();
      section();
      subsection();
      } break;
   case 35: {
      } break;
   }
}

subsection ()
{
   switch(yyselect()) {
   case 36: {
#line 84 "V3.acc"
printf("\n<h2>");
# line 394 "yygrammar.c"
      get_lexval();
      get_lexval();
      mot();
      get_lexval();
#line 84 "V3.acc"
printf("\n</h2>");
# line 401 "yygrammar.c"
      contenu();
      subsection();
      subsubsection();
      } break;
   case 37: {
      } break;
   }
}

subsubsection ()
{
   switch(yyselect()) {
   case 38: {
#line 88 "V3.acc"
printf("\n<h3>");
# line 417 "yygrammar.c"
      get_lexval();
      get_lexval();
      mot();
      get_lexval();
#line 88 "V3.acc"
printf("\n</h3>");
# line 424 "yygrammar.c"
      contenu();
      subsubsection();
      } break;
   case 39: {
      } break;
   }
}

extern YYSTYPE yylval;
YYSTYPE yylval;
extern long yypos;
long yypos = 1;
/* GentleFlag = no */

typedef struct LEXELEMSTRUCT {
   YYSTYPE val;
   long pos;
   long sym;
   char * text;
   struct LEXELEMSTRUCT *next;
} LEXELEM;
   
LEXELEM *first_lexelem, *cur_lexelem;

init_lexelem()
{
   cur_lexelem = first_lexelem;
}

first_lexval () {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
   first_lexelem = p;
}

next_lexval() {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   cur_lexelem-> next = p;
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
}

get_lexval() {
   extern int FREE_LEXELEMS;
   LEXELEM *p;
   yylval = cur_lexelem->val;
   yypos = cur_lexelem->pos;
   p = cur_lexelem;
   cur_lexelem = cur_lexelem->next;
   free(p);
}

extern int c_length;
int c_length = 220;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 40,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 18,
/* 12 */ 50256,
/* 13 */ 45,
/* 14 */ 91,
/* 15 */ 50257,
/* 16 */ -10,
/* 17 */ 2,
/* 18 */ 26,
/* 19 */ 50258,
/* 20 */ 50275,
/* 21 */ 77,
/* 22 */ 50276,
/* 23 */ 18,
/* 24 */ -18,
/* 25 */ 3,
/* 26 */ 34,
/* 27 */ 50260,
/* 28 */ 50275,
/* 29 */ 77,
/* 30 */ 50276,
/* 31 */ 18,
/* 32 */ -18,
/* 33 */ 4,
/* 34 */ 42,
/* 35 */ 50259,
/* 36 */ 50275,
/* 37 */ 77,
/* 38 */ 50276,
/* 39 */ 18,
/* 40 */ -18,
/* 41 */ 5,
/* 42 */ 0,
/* 43 */ -18,
/* 44 */ 6,
/* 45 */ 49,
/* 46 */ 50261,
/* 47 */ -45,
/* 48 */ 7,
/* 49 */ 0,
/* 50 */ -45,
/* 51 */ 8,
/* 52 */ 56,
/* 53 */ 50272,
/* 54 */ -52,
/* 55 */ 9,
/* 56 */ 63,
/* 57 */ 50265,
/* 58 */ 50275,
/* 59 */ 77,
/* 60 */ 50276,
/* 61 */ -52,
/* 62 */ 10,
/* 63 */ 70,
/* 64 */ 50266,
/* 65 */ 50275,
/* 66 */ 77,
/* 67 */ 50276,
/* 68 */ -52,
/* 69 */ 11,
/* 70 */ 74,
/* 71 */ 50273,
/* 72 */ -52,
/* 73 */ 12,
/* 74 */ 0,
/* 75 */ -52,
/* 76 */ 13,
/* 77 */ 82,
/* 78 */ 52,
/* 79 */ 77,
/* 80 */ -77,
/* 81 */ 14,
/* 82 */ 88,
/* 83 */ 50274,
/* 84 */ 52,
/* 85 */ 77,
/* 86 */ -77,
/* 87 */ 15,
/* 88 */ 0,
/* 89 */ -77,
/* 90 */ 16,
/* 91 */ 96,
/* 92 */ 52,
/* 93 */ 91,
/* 94 */ -91,
/* 95 */ 17,
/* 96 */ 101,
/* 97 */ 77,
/* 98 */ 91,
/* 99 */ -91,
/* 100 */ 18,
/* 101 */ 106,
/* 102 */ 118,
/* 103 */ 91,
/* 104 */ -91,
/* 105 */ 19,
/* 106 */ 111,
/* 107 */ 137,
/* 108 */ 91,
/* 109 */ -91,
/* 110 */ 20,
/* 111 */ 115,
/* 112 */ 183,
/* 113 */ -91,
/* 114 */ 21,
/* 115 */ 0,
/* 116 */ -91,
/* 117 */ 22,
/* 118 */ 125,
/* 119 */ 50267,
/* 120 */ 77,
/* 121 */ 156,
/* 122 */ 50268,
/* 123 */ -118,
/* 124 */ 23,
/* 125 */ 131,
/* 126 */ 50267,
/* 127 */ 118,
/* 128 */ 50268,
/* 129 */ -118,
/* 130 */ 24,
/* 131 */ 0,
/* 132 */ 50267,
/* 133 */ 137,
/* 134 */ 50268,
/* 135 */ -118,
/* 136 */ 25,
/* 137 */ 144,
/* 138 */ 50269,
/* 139 */ 77,
/* 140 */ 156,
/* 141 */ 50270,
/* 142 */ -137,
/* 143 */ 26,
/* 144 */ 150,
/* 145 */ 50269,
/* 146 */ 118,
/* 147 */ 50270,
/* 148 */ -137,
/* 149 */ 27,
/* 150 */ 0,
/* 151 */ 50269,
/* 152 */ 137,
/* 153 */ 50270,
/* 154 */ -137,
/* 155 */ 28,
/* 156 */ 162,
/* 157 */ 50271,
/* 158 */ 77,
/* 159 */ 176,
/* 160 */ -156,
/* 161 */ 29,
/* 162 */ 169,
/* 163 */ 50271,
/* 164 */ 77,
/* 165 */ 118,
/* 166 */ 176,
/* 167 */ -156,
/* 168 */ 30,
/* 169 */ 0,
/* 170 */ 50271,
/* 171 */ 77,
/* 172 */ 137,
/* 173 */ 176,
/* 174 */ -156,
/* 175 */ 31,
/* 176 */ 180,
/* 177 */ 156,
/* 178 */ -176,
/* 179 */ 32,
/* 180 */ 0,
/* 181 */ -176,
/* 182 */ 33,
/* 183 */ 193,
/* 184 */ 50262,
/* 185 */ 50275,
/* 186 */ 77,
/* 187 */ 50276,
/* 188 */ 91,
/* 189 */ 183,
/* 190 */ 196,
/* 191 */ -183,
/* 192 */ 34,
/* 193 */ 0,
/* 194 */ -183,
/* 195 */ 35,
/* 196 */ 206,
/* 197 */ 50263,
/* 198 */ 50275,
/* 199 */ 77,
/* 200 */ 50276,
/* 201 */ 91,
/* 202 */ 196,
/* 203 */ 209,
/* 204 */ -196,
/* 205 */ 36,
/* 206 */ 0,
/* 207 */ -196,
/* 208 */ 37,
/* 209 */ 218,
/* 210 */ 50264,
/* 211 */ 50275,
/* 212 */ 77,
/* 213 */ 50276,
/* 214 */ 91,
/* 215 */ 209,
/* 216 */ -209,
/* 217 */ 38,
/* 218 */ 0,
/* 219 */ -209,
/* 220 */ 39,
0
};
extern int yyannotation[];
int yyannotation[] = {
0,
/* 1 */ 0,
/* 2 */ 0,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 0,
/* 6 */ 0,
/* 7 */ 1,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 0,
/* 11 */ 1,
/* 12 */ 50256,
/* 13 */ 1,
/* 14 */ 1,
/* 15 */ 50257,
/* 16 */ -10,
/* 17 */ 1,
/* 18 */ 26,
/* 19 */ 50258,
/* 20 */ 50275,
/* 21 */ 1,
/* 22 */ 50276,
/* 23 */ 1,
/* 24 */ -18,
/* 25 */ 1,
/* 26 */ 34,
/* 27 */ 50260,
/* 28 */ 50275,
/* 29 */ 1,
/* 30 */ 50276,
/* 31 */ 1,
/* 32 */ -18,
/* 33 */ 2,
/* 34 */ 42,
/* 35 */ 50259,
/* 36 */ 50275,
/* 37 */ 1,
/* 38 */ 50276,
/* 39 */ 1,
/* 40 */ -18,
/* 41 */ 3,
/* 42 */ 0,
/* 43 */ -18,
/* 44 */ 4,
/* 45 */ 49,
/* 46 */ 50261,
/* 47 */ -45,
/* 48 */ 1,
/* 49 */ 0,
/* 50 */ -45,
/* 51 */ 2,
/* 52 */ 56,
/* 53 */ 50272,
/* 54 */ -52,
/* 55 */ 1,
/* 56 */ 63,
/* 57 */ 50265,
/* 58 */ 50275,
/* 59 */ 1,
/* 60 */ 50276,
/* 61 */ -52,
/* 62 */ 2,
/* 63 */ 70,
/* 64 */ 50266,
/* 65 */ 50275,
/* 66 */ 1,
/* 67 */ 50276,
/* 68 */ -52,
/* 69 */ 3,
/* 70 */ 74,
/* 71 */ 50273,
/* 72 */ -52,
/* 73 */ 4,
/* 74 */ 0,
/* 75 */ -52,
/* 76 */ 5,
/* 77 */ 82,
/* 78 */ 1,
/* 79 */ 1,
/* 80 */ -77,
/* 81 */ 1,
/* 82 */ 88,
/* 83 */ 50274,
/* 84 */ 1,
/* 85 */ 1,
/* 86 */ -77,
/* 87 */ 2,
/* 88 */ 0,
/* 89 */ -77,
/* 90 */ 3,
/* 91 */ 96,
/* 92 */ 1,
/* 93 */ 1,
/* 94 */ -91,
/* 95 */ 1,
/* 96 */ 101,
/* 97 */ 1,
/* 98 */ 1,
/* 99 */ -91,
/* 100 */ 2,
/* 101 */ 106,
/* 102 */ 1,
/* 103 */ 1,
/* 104 */ -91,
/* 105 */ 3,
/* 106 */ 111,
/* 107 */ 1,
/* 108 */ 1,
/* 109 */ -91,
/* 110 */ 4,
/* 111 */ 115,
/* 112 */ 1,
/* 113 */ -91,
/* 114 */ 5,
/* 115 */ 0,
/* 116 */ -91,
/* 117 */ 6,
/* 118 */ 125,
/* 119 */ 50267,
/* 120 */ 1,
/* 121 */ 1,
/* 122 */ 50268,
/* 123 */ -118,
/* 124 */ 1,
/* 125 */ 131,
/* 126 */ 50267,
/* 127 */ 1,
/* 128 */ 50268,
/* 129 */ -118,
/* 130 */ 2,
/* 131 */ 0,
/* 132 */ 50267,
/* 133 */ 1,
/* 134 */ 50268,
/* 135 */ -118,
/* 136 */ 3,
/* 137 */ 144,
/* 138 */ 50269,
/* 139 */ 1,
/* 140 */ 1,
/* 141 */ 50270,
/* 142 */ -137,
/* 143 */ 1,
/* 144 */ 150,
/* 145 */ 50269,
/* 146 */ 1,
/* 147 */ 50270,
/* 148 */ -137,
/* 149 */ 2,
/* 150 */ 0,
/* 151 */ 50269,
/* 152 */ 1,
/* 153 */ 50270,
/* 154 */ -137,
/* 155 */ 3,
/* 156 */ 162,
/* 157 */ 50271,
/* 158 */ 1,
/* 159 */ 1,
/* 160 */ -156,
/* 161 */ 1,
/* 162 */ 169,
/* 163 */ 50271,
/* 164 */ 1,
/* 165 */ 1,
/* 166 */ 1,
/* 167 */ -156,
/* 168 */ 2,
/* 169 */ 0,
/* 170 */ 50271,
/* 171 */ 1,
/* 172 */ 1,
/* 173 */ 1,
/* 174 */ -156,
/* 175 */ 3,
/* 176 */ 180,
/* 177 */ 1,
/* 178 */ -176,
/* 179 */ 1,
/* 180 */ 0,
/* 181 */ -176,
/* 182 */ 2,
/* 183 */ 193,
/* 184 */ 50262,
/* 185 */ 50275,
/* 186 */ 1,
/* 187 */ 50276,
/* 188 */ 1,
/* 189 */ 1,
/* 190 */ 1,
/* 191 */ -183,
/* 192 */ 1,
/* 193 */ 0,
/* 194 */ -183,
/* 195 */ 2,
/* 196 */ 206,
/* 197 */ 50263,
/* 198 */ 50275,
/* 199 */ 1,
/* 200 */ 50276,
/* 201 */ 1,
/* 202 */ 1,
/* 203 */ 1,
/* 204 */ -196,
/* 205 */ 1,
/* 206 */ 0,
/* 207 */ -196,
/* 208 */ 2,
/* 209 */ 218,
/* 210 */ 50264,
/* 211 */ 50275,
/* 212 */ 1,
/* 213 */ 50276,
/* 214 */ 1,
/* 215 */ 1,
/* 216 */ -209,
/* 217 */ 1,
/* 218 */ 0,
/* 219 */ -209,
/* 220 */ 2,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 29008,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 29008,
/* 6 */ 9999,
/* 7 */ 29010,
/* 8 */ 9999,
/* 9 */ 29014,
/* 10 */ 9999,
/* 11 */ 31051,
/* 12 */ 9999,
/* 13 */ 31218,
/* 14 */ 31259,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 31009,
/* 18 */ 9999,
/* 19 */ 9999,
/* 20 */ 9999,
/* 21 */ 37019,
/* 22 */ 9999,
/* 23 */ 37030,
/* 24 */ 9999,
/* 25 */ 37010,
/* 26 */ 9999,
/* 27 */ 9999,
/* 28 */ 9999,
/* 29 */ 38017,
/* 30 */ 9999,
/* 31 */ 38028,
/* 32 */ 9999,
/* 33 */ 38008,
/* 34 */ 9999,
/* 35 */ 9999,
/* 36 */ 9999,
/* 37 */ 39018,
/* 38 */ 9999,
/* 39 */ 39029,
/* 40 */ 9999,
/* 41 */ 39009,
/* 42 */ 9999,
/* 43 */ 9999,
/* 44 */ 40005,
/* 45 */ 9999,
/* 46 */ 9999,
/* 47 */ 9999,
/* 48 */ 44013,
/* 49 */ 9999,
/* 50 */ 9999,
/* 51 */ 45005,
/* 52 */ 9999,
/* 53 */ 9999,
/* 54 */ 9999,
/* 55 */ 47016,
/* 56 */ 9999,
/* 57 */ 9999,
/* 58 */ 9999,
/* 59 */ 48034,
/* 60 */ 9999,
/* 61 */ 9999,
/* 62 */ 48008,
/* 63 */ 9999,
/* 64 */ 9999,
/* 65 */ 9999,
/* 66 */ 49038,
/* 67 */ 9999,
/* 68 */ 9999,
/* 69 */ 49012,
/* 70 */ 9999,
/* 71 */ 9999,
/* 72 */ 9999,
/* 73 */ 50008,
/* 74 */ 9999,
/* 75 */ 9999,
/* 76 */ 51005,
/* 77 */ 9999,
/* 78 */ 53007,
/* 79 */ 53016,
/* 80 */ 9999,
/* 81 */ 53014,
/* 82 */ 9999,
/* 83 */ 9999,
/* 84 */ 54050,
/* 85 */ 54059,
/* 86 */ 9999,
/* 87 */ 54009,
/* 88 */ 9999,
/* 89 */ 9999,
/* 90 */ 55007,
/* 91 */ 9999,
/* 92 */ 57011,
/* 93 */ 57020,
/* 94 */ 9999,
/* 95 */ 57018,
/* 96 */ 9999,
/* 97 */ 58005,
/* 98 */ 58009,
/* 99 */ 9999,
/* 100 */ 58007,
/* 101 */ 9999,
/* 102 */ 59005,
/* 103 */ 59011,
/* 104 */ 9999,
/* 105 */ 59009,
/* 106 */ 9999,
/* 107 */ 60005,
/* 108 */ 60009,
/* 109 */ 9999,
/* 110 */ 60007,
/* 111 */ 9999,
/* 112 */ 61005,
/* 113 */ 9999,
/* 114 */ 61011,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 62005,
/* 118 */ 9999,
/* 119 */ 9999,
/* 120 */ 64041,
/* 121 */ 64045,
/* 122 */ 9999,
/* 123 */ 9999,
/* 124 */ 64021,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 65037,
/* 128 */ 9999,
/* 129 */ 9999,
/* 130 */ 65017,
/* 131 */ 9999,
/* 132 */ 9999,
/* 133 */ 66037,
/* 134 */ 9999,
/* 135 */ 9999,
/* 136 */ 66017,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 68036,
/* 140 */ 68040,
/* 141 */ 9999,
/* 142 */ 9999,
/* 143 */ 68016,
/* 144 */ 9999,
/* 145 */ 9999,
/* 146 */ 69036,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 69016,
/* 150 */ 9999,
/* 151 */ 9999,
/* 152 */ 70036,
/* 153 */ 9999,
/* 154 */ 9999,
/* 155 */ 70016,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 72031,
/* 159 */ 72054,
/* 160 */ 9999,
/* 161 */ 72011,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 73031,
/* 165 */ 73054,
/* 166 */ 73060,
/* 167 */ 9999,
/* 168 */ 73011,
/* 169 */ 9999,
/* 170 */ 9999,
/* 171 */ 74031,
/* 172 */ 74054,
/* 173 */ 74058,
/* 174 */ 9999,
/* 175 */ 74011,
/* 176 */ 9999,
/* 177 */ 76007,
/* 178 */ 9999,
/* 179 */ 76010,
/* 180 */ 9999,
/* 181 */ 9999,
/* 182 */ 77007,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 9999,
/* 186 */ 80036,
/* 187 */ 9999,
/* 188 */ 80068,
/* 189 */ 80076,
/* 190 */ 80084,
/* 191 */ 9999,
/* 192 */ 80005,
/* 193 */ 9999,
/* 194 */ 9999,
/* 195 */ 81005,
/* 196 */ 9999,
/* 197 */ 9999,
/* 198 */ 9999,
/* 199 */ 84039,
/* 200 */ 9999,
/* 201 */ 84071,
/* 202 */ 84079,
/* 203 */ 84090,
/* 204 */ 9999,
/* 205 */ 84005,
/* 206 */ 9999,
/* 207 */ 9999,
/* 208 */ 85005,
/* 209 */ 9999,
/* 210 */ 9999,
/* 211 */ 9999,
/* 212 */ 88042,
/* 213 */ 9999,
/* 214 */ 88074,
/* 215 */ 88082,
/* 216 */ 9999,
/* 217 */ 88005,
/* 218 */ 9999,
/* 219 */ 9999,
/* 220 */ 89005,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[222];
*/
int TABLE[41][277];
init_dirsets() {
TABLE[40][0] = 1;
TABLE[40][256] = 1;
TABLE[40][258] = 1;
TABLE[40][260] = 1;
TABLE[40][259] = 1;
TABLE[1][0] = 1;
TABLE[1][256] = 1;
TABLE[1][259] = 1;
TABLE[1][260] = 1;
TABLE[1][258] = 1;
TABLE[2][256] = 1;
TABLE[2][258] = 1;
TABLE[2][260] = 1;
TABLE[2][259] = 1;
TABLE[3][258] = 1;
TABLE[4][260] = 1;
TABLE[5][259] = 1;
TABLE[6][256] = 1;
TABLE[7][261] = 1;
TABLE[8][273] = 1;
TABLE[8][266] = 1;
TABLE[8][265] = 1;
TABLE[8][272] = 1;
TABLE[8][274] = 1;
TABLE[8][267] = 1;
TABLE[8][269] = 1;
TABLE[8][262] = 1;
TABLE[8][257] = 1;
TABLE[9][272] = 1;
TABLE[10][265] = 1;
TABLE[11][266] = 1;
TABLE[12][273] = 1;
TABLE[13][273] = 1;
TABLE[13][266] = 1;
TABLE[13][265] = 1;
TABLE[13][272] = 1;
TABLE[13][274] = 1;
TABLE[13][276] = 1;
TABLE[13][267] = 1;
TABLE[13][269] = 1;
TABLE[13][262] = 1;
TABLE[13][257] = 1;
TABLE[13][271] = 1;
TABLE[13][268] = 1;
TABLE[13][270] = 1;
TABLE[13][263] = 1;
TABLE[13][264] = 1;
TABLE[14][276] = 1;
TABLE[14][267] = 1;
TABLE[14][269] = 1;
TABLE[14][262] = 1;
TABLE[14][257] = 1;
TABLE[14][271] = 1;
TABLE[14][268] = 1;
TABLE[14][270] = 1;
TABLE[14][263] = 1;
TABLE[14][264] = 1;
TABLE[14][274] = 1;
TABLE[14][272] = 1;
TABLE[14][265] = 1;
TABLE[14][266] = 1;
TABLE[14][273] = 1;
TABLE[15][274] = 1;
TABLE[16][276] = 1;
TABLE[16][273] = 1;
TABLE[16][266] = 1;
TABLE[16][265] = 1;
TABLE[16][272] = 1;
TABLE[16][274] = 1;
TABLE[16][267] = 1;
TABLE[16][269] = 1;
TABLE[16][262] = 1;
TABLE[16][257] = 1;
TABLE[16][271] = 1;
TABLE[16][268] = 1;
TABLE[16][270] = 1;
TABLE[16][263] = 1;
TABLE[16][264] = 1;
TABLE[17][257] = 1;
TABLE[17][263] = 1;
TABLE[17][264] = 1;
TABLE[17][274] = 1;
TABLE[17][267] = 1;
TABLE[17][269] = 1;
TABLE[17][262] = 1;
TABLE[17][272] = 1;
TABLE[17][265] = 1;
TABLE[17][266] = 1;
TABLE[17][273] = 1;
TABLE[18][257] = 1;
TABLE[18][263] = 1;
TABLE[18][264] = 1;
TABLE[18][267] = 1;
TABLE[18][269] = 1;
TABLE[18][262] = 1;
TABLE[18][273] = 1;
TABLE[18][266] = 1;
TABLE[18][265] = 1;
TABLE[18][272] = 1;
TABLE[18][274] = 1;
TABLE[19][267] = 1;
TABLE[20][269] = 1;
TABLE[21][257] = 1;
TABLE[21][263] = 1;
TABLE[21][264] = 1;
TABLE[21][262] = 1;
TABLE[22][257] = 1;
TABLE[22][262] = 1;
TABLE[22][263] = 1;
TABLE[22][264] = 1;
TABLE[23][267] = 1;
TABLE[24][267] = 1;
TABLE[25][267] = 1;
TABLE[26][269] = 1;
TABLE[27][269] = 1;
TABLE[28][269] = 1;
TABLE[29][271] = 1;
TABLE[30][271] = 1;
TABLE[31][271] = 1;
TABLE[32][271] = 1;
TABLE[33][268] = 1;
TABLE[33][270] = 1;
TABLE[34][262] = 1;
TABLE[35][257] = 1;
TABLE[35][263] = 1;
TABLE[35][262] = 1;
TABLE[35][264] = 1;
TABLE[36][263] = 1;
TABLE[37][257] = 1;
TABLE[37][264] = 1;
TABLE[37][263] = 1;
TABLE[37][262] = 1;
TABLE[38][264] = 1;
TABLE[39][257] = 1;
TABLE[39][264] = 1;
TABLE[39][263] = 1;
TABLE[39][262] = 1;
}

extern int yydirset();
int yydirset(i,j)
   int i,j;
{
   return TABLE[i][j];
}
int yytransparent(n)
   int n;
{
   switch(n) {
      case 1: return 1; break;
      case 6: return 1; break;
      case 10: return 1; break;
      case 18: return 1; break;
      case 45: return 1; break;
      case 52: return 1; break;
      case 77: return 1; break;
      case 91: return 1; break;
      case 118: return 0; break;
      case 137: return 0; break;
      case 156: return 0; break;
      case 176: return 1; break;
      case 183: return 1; break;
      case 196: return 1; break;
      case 209: return 1; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "racine"; break;
         case 10: return "debut"; break;
         case 18: return "options"; break;
         case 45: return "maketitle"; break;
         case 52: return "commande"; break;
         case 77: return "mot"; break;
         case 91: return "contenu"; break;
         case 118: return "liste"; break;
         case 137: return "num"; break;
         case 156: return "item"; break;
         case 176: return "fin"; break;
         case 183: return "section"; break;
         case 196: return "subsection"; break;
         case 209: return "subsubsection"; break;
   }
   else 
      switch(n-50000) {
         case 276: return "ACCFER"; break;
         case 275: return "ACCOUV"; break;
         case 274: return "MOT"; break;
         case 273: return "DOTS"; break;
         case 272: return "LIGNE"; break;
         case 271: return "ITEM"; break;
         case 270: return "END_ENUM"; break;
         case 269: return "BEGIN_ENUM"; break;
         case 268: return "END_ITEMIZE"; break;
         case 267: return "BEGIN_ITEMIZE"; break;
         case 266: return "ITALIQUE"; break;
         case 265: return "GRAS"; break;
         case 264: return "SUBSUBSEC"; break;
         case 263: return "SUBSEC"; break;
         case 262: return "SEC"; break;
         case 261: return "MAKETITLE"; break;
         case 260: return "DATE"; break;
         case 259: return "TITLE"; break;
         case 258: return "AUTHOR"; break;
         case 257: return "END_DOC"; break;
         case 256: return "BEGIN_DOC"; break;
      }
   return "special_character";
}
