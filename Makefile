#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa Poker
# Autor		: Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
# Histórico	: 2022-06-07 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/analisador.o $(OBJ)/ordenacao.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/memlog.h $(INC)/msgassert.h $(INC)/analisador.hpp $(INC)/ordenacao.hpp
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/analisador

all: use

use: $(EXE)
	$(EXE) -pg -o analisador 

$(BIN)/analisador: $(OBJS)
	$(CC) -g -o $(BIN)/analisador $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/analisador.o: $(HDRS) $(SRC)/analisador.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/analisador.o $(SRC)/analisador.cpp 

$(OBJ)/ordenacao.o: $(HDRS) $(SRC)/ordenacao.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/ordenacao.o $(SRC)/ordenacao.cpp 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c

clean:
	rm -f $(EXE) $(OBJS)  
