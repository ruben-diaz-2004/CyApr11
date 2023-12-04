#include <algorithm>
#include <utility>


#include "point_set.h"


point_set::point_set(const CyA::point_vector &points, CyA::arc_vector &av) : CyA::point_vector(points), emst_() {
  compute_arc_vector(av);
}

/**
 * @brief método para calcular los costes entre cada par de puntos
 */

void point_set::compute_arc_vector(CyA::arc_vector &av) const {
  av.clear();
 
  const int n = size();
 
  for (int i = 0; i < n - 1; ++i) {
    const CyA::point &p_i = (*this)[i];
 
    for (int j = i + 1; j < n; ++j) {
      const CyA::point &p_j = (*this)[j];
 
      const double dist = euclidean_distance(std::make_pair(p_i, p_j));
 
      av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
    }
  }
 
  std::sort(av.begin(), av.end());
}


void point_set::find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const {

}


void point_set::merge_subtrees(forest& st, const CyA::arc &a, int i, int j) const {

}


double point_set::compute_cost(void) const {

}


double point_set::euclidean_distance(const CyA::arc& a) const {
  const double distancia_x = a.first.first - a.second.first;
  const double distancia_y = a.first.second - a.second.second;
 
  return sqrt(distancia_x * distancia_x + distancia_y * distancia_y);
}


void point_set::EMST(void) {

}


void point_set::write_tree(std::ostream &os) const {
}


void point_set::write(std::ostream &os) const {
}