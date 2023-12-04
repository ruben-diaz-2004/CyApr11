#include <algorithm>
#include <utility>


#include "point_set.h"



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


/**
 * @brief método para encontrar los subárboles incidentes
*/
void point_set::find_incident_subtrees(const forest& st, const CyA::arc &a, int& i, int& j) const {
  i = 0;
  j = 0;
  bool encontrado = false;
  while (i < st.size() && !encontrado) {
    j = 0;
    while (j < st[i].get_arcs().size() && !encontrado) {
      if (st[i].get_arcs()[j].second == a.first) {
        encontrado = true;
      }
      else {
        j++;
      }
    }
    if (!encontrado) {
      i++;
    }
  }
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
  forest bosque_F;
  for (int i = 0; i < size(); i++) {
    bosque_F.push_back(EMST::sub_tree((*this)[i]));
  }

  CyA::arc_vector aristas_S;
  compute_arc_vector(aristas_S);

  while (!aristas_S.empty() && bosque_F.size() != 1) {
    CyA::arc arista_minima = aristas_S[0].second;
    aristas_S.erase(aristas_S.begin());
    int i = 0;
    int j = 0;
    find_incident_subtrees(bosque_F, arista_minima, i, j);
    if (i != j) {
      merge_subtrees(bosque_F, arista_minima, i, j);
    }
  }

  emst_ = bosque_F[0].get_arcs();

}


void point_set::write_tree(std::ostream &os) const {
  os << emst_.size() << std::endl;
 
  for (const CyA::arc &a : emst_) {
    os << a.first << "\t" << a.second << std::endl;
  }
}


void point_set::write(std::ostream &os) const {
}