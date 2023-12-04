# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# 
# @author Rubén Díaz Marrero
# @date 25/09/2023
# 

CXX = g++
CXXFLAGS = -Wall -std=c++17 -g 



all: EMST

EMST: EMST_main.cc point_set.cc point_types.cc sub_tree.cc
		$(CXX) $(CXXFLAGS) -o $@ $^
	

	
.PHONY: all clean
clean:
		rm -f EMST