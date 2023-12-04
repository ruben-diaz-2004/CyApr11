/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 21/10/2023
  * @brief Este programa se encarga de transformar una gramática
  * a forma normal de Chomsky (CNF)
  */

#include <iostream>
#include <fstream>
#include "parameters.cc"
#include "point_set.h"



int main(int argc, char *argv[]) {
  CheckCorrectParameters(argc, argv, 3);

  std::ifstream input_TM{argv[1]};
  std::ofstream output_tape{argv[2]};


  CyA::point_vector points;
  input_TM >> points;

  point_set arbol(points);

  arbol.write_tree(output_tape);






  return 0;
}