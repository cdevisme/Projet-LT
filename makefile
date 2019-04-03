ACCENT=/home/p/l/plouis/Documents/LT/Lex/Compil/accent/accent/accent
ENTIRE=/home/p/l/plouis/Documents/LT/Lex/Compil/accent/entire/entire.c
LEX=lex
CC=gcc

$(NOM) :	yygrammar.c lex.yy.c auxil.c
		$(CC) -o $(NOM) yygrammar.c lex.yy.c auxil.c $(ENTIRE) -Wno-implicit-function-declaration -Wno-implicit-int

lex.yy.c :      $(NOM).lex
		$(LEX) $(NOM).lex

yygrammar.c :   $(NOM).acc
		$(ACCENT) $(NOM).acc
