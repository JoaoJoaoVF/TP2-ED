#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa Poker
# Autor		: Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
# Histórico	: 2022-06-30 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm 
SRC = src
OBJ = ./obj/
INC = ./include/
BIN = ./bin/
SAIDA = ./saida/
OBJS = $(OBJ)/Execucao.o $(OBJ)/Analisador.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/memlog.h $(INC)/msgassert.h $(INC)/Execucao.hpp $(INC)/Analisador.hpp
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/analisador.out

all: use

use: $(EXE)
	$(EXE) -i "./entrada/1.txt" -o "./saida/1.txt" 
	$(EXE) -i "./entrada/2.txt" -o "./saida/2.txt"
	$(EXE) -i "./entrada/3.txt" -o "./saida/3.txt"
	$(EXE) -i "./entrada/4.txt" -o "./saida/4.txt"
	$(EXE) -i "./entrada/5.txt" -o "./saida/5.txt"
	$(EXE) -i "./entrada/6.txt" -o "./saida/6.txt"
	$(EXE) -i "./entrada/7.txt" -o "./saida/7.txt"
	$(EXE) -i "./entrada/8.txt" -o "./saida/8.txt"
	$(EXE) -i "./entrada/9.txt" -o "./saida/9.txt"
	$(EXE) -i "./entrada/10.txt" -o "./saida/10.txt"
	$(EXE) -i "./entrada/11.txt" -o "./saida/11.txt"
#	gprof $(EXE) gmon.out > gprof.txt

$(BIN)/analisador: $(OBJS)
	$(CC) -g -o $(BIN)/analisador $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Execucao.o: $(HDRS) $(SRC)/Execucao.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/Execucao.o $(SRC)/Execucao.cpp 

$(OBJ)/Analisador.o: $(HDRS) $(SRC)/Analisador.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/Analisador.o $(SRC)/Analisador.cpp 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c

clean:
	rm -f $(EXE)* $(OBJS)* $(SAIDA)* $(BIN)* gmon.out
	clear 
