SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -std=c++11
CPPFLAGS = -Wall -g  -I$(INC) -c

all:	preambulo\

testDiccionario: 	$(BIN)/testDiccionario

testConjunto:			$(BIN)/testConjuntoLetras

testCantidad:			$(BIN)/cantidadLetras

letras:						$(BIN)/letras

#************************************************************
preambulo:
	@echo
	@echo -----------------------------------------------
	@echo Práctica 5
	@echo
	@echo Estructura de Datos
	@echo Grado en Ingeniería Informática - Grupo A1
	@echo CURSO 2018-2019
	@echo
	@echo REALIZADO POR
	@echo ALBA CASILLAS RODRÍGUEZ
	@echo 		Y
	@echo PAULA CUMBRERAS TORRENTE
	@echo -----------------------------------------------
	@echo

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/testDiccionario:$(OBJ)/testDiccionario.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/testDiccionario $(OBJ)/testDiccionario.o $(OBJ)/diccionario.o

$(BIN)/testConjuntoLetras:$(OBJ)/testConjuntoLetras.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o
	$(CXX) -o $(BIN)/testConjuntoLetras $(OBJ)/testConjuntoLetras.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o

$(BIN)/cantidadLetras:$(OBJ)/cantidadLetras.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/cantidadLetras $(OBJ)/cantidadLetras.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o $(OBJ)/diccionario.o

$(BIN)/letras:$(OBJ)/letras.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o $(OBJ)/diccionario.o $(OBJ)/bolsaLetras.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/letra.o $(OBJ)/conjuntoLetras.o $(OBJ)/diccionario.o $(OBJ)/bolsaLetras.o

$(OBJ)/testDiccionario.o: $(SRC)/testDiccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testDiccionario.o $(SRC)/testDiccionario.cpp

$(OBJ)/testConjuntoLetras.o: $(SRC)/testConjuntoLetras.cpp $(INC)/conjuntoLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testConjuntoLetras.o $(SRC)/testConjuntoLetras.cpp

$(OBJ)/cantidadLetras.o: $(SRC)/cantidadLetras.cpp $(INC)/diccionario.h $(INC)/conjuntoLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cantidadLetras.o $(SRC)/cantidadLetras.cpp

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o  $(SRC)/diccionario.cpp

$(OBJ)/letra.o: $(SRC)/letra.cpp $(INC)/letra.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letra.o  $(SRC)/letra.cpp

$(OBJ)/conjuntoLetras.o: $(SRC)/conjuntoLetras.cpp $(INC)/conjuntoLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/conjuntoLetras.o  $(SRC)/conjuntoLetras.cpp

$(OBJ)/bolsaLetras.o: $(SRC)/bolsaLetras.cpp $(INC)/bolsaLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/bolsaLetras.o  $(SRC)/bolsaLetras.cpp

$(OBJ)/letras.o: $(SRC)/letras.cpp $(INC)/bolsaLetras.h  $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letras.o  $(SRC)/letras.cpp 

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
