/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */
 
#include <iostream>


/**
 * Comprueba que al programa se le pasen los parámetros adecuados
 * @param argc, número de argumentos
 * @param argv, cada argumento que se le pasa al programa
 * @param KcorrectNumber, número correcto de parámetros
 * @return true, si todo funciona bien.
*/
bool CheckCorrectParameters(const int argc, char* argv[], const int kCorrectNumber) {
  if (argc > 1) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << "Modo de empleo: ./TuringMachine input.tm input.tape output.tape" << std::endl << std::endl;
      std::cout << "El primer fichero de entrada debe ser un fichero con la extension .tm, que contendrá la \n";
      std::cout << "definición de la máquina de Turing. El segundo fichero de entrada debe ser un fichero con \n";
      std::cout << "la extension .tape, que contendrá la cinta de entrada de la máquina de Turing. El tercer \n";
      std::cout << "fichero de entrada debe ser un fichero con la extension .tape, que contendrá la cinta de \n";
      std::cout << "salida de la máquina de Turing." << std::endl << std::endl;
      std::cout << std::endl << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != kCorrectNumber) {
  std::cout << "Modo de empleo: ./TuringMachine input.tm input.tape output.tape" << std::endl;
  std::cout << "Pruebe ./Grammar2CNF --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  return true;
}
