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



all: TuringMachine

TuringMachine: TM_main.cc tupla.cc turingmachine.cc
		$(CXX) $(CXXFLAGS) -o $@ $^
	

	
.PHONY: all clean
clean:
		rm -f TuringMachine