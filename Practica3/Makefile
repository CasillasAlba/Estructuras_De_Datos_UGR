SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ 
CPPFLAGS = -Wall -g  -I$(INC) -c


all: preambulo \
     $(BIN)/pruebacola_max

#pruebapila: $(BIN)/pruebapila

#************************************************************
preambulo:
	@echo
	@echo -----------------------------------------------
	@echo Práctica 2
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
$(BIN)/pruebacola_max:$(OBJ)/pruebacola_max.o
	$(CXX) -o $(BIN)/pruebacola_max $(OBJ)/pruebacola_max.o

$(OBJ)/pruebacola_max.o: $(SRC)/pruebacola_max.cpp $(INC)/Cola_max.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp	


#$(BIN)/pruebapila: $(OBJ)/pruebapila.o
#	$(CXX) -o $(BIN)/pruebapila $(OBJ)/pruebapila.o

#$(OBJ)/pruebapila.o: $(SRC)/mainpruebapila.cpp $(INC)/Pila_max.hpp
#	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebapila.o $(SRC)/mainpruebapila.cpp


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
