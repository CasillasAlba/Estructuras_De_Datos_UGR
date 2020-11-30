SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -std=c++11
CPPFLAGS = -Wall -g  -I$(INC) -c



all: preambulo \
     $(BIN)/pruebadiccionario


#************************************************************
preambulo:
	@echo
	@echo -----------------------------------------------
	@echo Práctica 4
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
	doxygen ./doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(OBJ)/termino.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/termino.o $(OBJ)/diccionario.o

$(OBJ)/pruebadiccionario.o: $(SRC)/pruebadiccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp

$(OBJ)/termino.o: $(SRC)/termino.cpp $(INC)/termino.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/termino.o $(SRC)/termino.cpp

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
