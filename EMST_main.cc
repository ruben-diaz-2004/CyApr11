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

  // 1. Crear un bosque ( F ) donde cada vértice en el grafo es un árbol separado.
  // 2. Crear un conjunto ordenado ( S ) que contenga todas las aristas del grafo.

  // 3. Mientras ( S ) no esté vacío y ( F ) aún no abarque todo el grafo:

  // Eliminar una arista con el peso mínimo de ( S ).
  // Si la arista eliminada conecta dos árboles diferentes, entonces añadirla al bosque ( F ), combinando dos árboles en uno solo.
  // Si la arista eliminada conecta dos vértices del mismo árbol, entonces descartarla.
  // 4. Devolver el bosque ( F ) como el árbol de expansión mínima del grafo.

  // 1. 
  CyA::point_vector points;
  input_TM >> points;
  forest bosque_F;
  for (int i = 0; i < points.size(); i++) {
    bosque_F.push_back(EMST::sub_tree(points[i]));
  }

  // 2.
  // Crear aristas
  CyA::arc_vector aristas_S;
  point_set puntos(points, aristas_S);

  // 3.
  while (!aristas_S.empty() && bosque_F.size() != 1) {
    // Eliminar una arista con el peso mínimo de ( S ).
    CyA::arc arista_minima = aristas_S[0].second;
    aristas_S.erase(aristas_S.begin());
    // Si la arista eliminada conecta dos árboles diferentes, entonces añadirla al bosque ( F ), combinando dos árboles en uno solo.
    int i = 0;
    int j = 0;
    puntos.find_incident_subtrees(bosque_F, arista_minima, i, j);
    if (i != j) {
      puntos.merge_subtrees(bosque_F, arista_minima, i, j);
    }
    // Si la arista eliminada conecta dos vértices del mismo árbol, entonces descartarla.
  }

  // 4.
  puntos.write_tree(output_tape);
  






  return 0;
}