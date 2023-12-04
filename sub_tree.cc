/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 04/12/2023
  * @brief Este programa obtiene el Euclidean minimum spanning tree (EMST)
  *  de un conjunto de puntos en dos dimensiones (2D)
  */

#include <iomanip>
#include <cmath>

#include <algorithm>
#include <utility>

#include "sub_tree.h"

namespace EMST
{
    // constructor por defecto
    sub_tree::sub_tree(void) : arcs_(),
                               points_(),
                               cost_(0)

    {
    }

    // constructor con un punto
    sub_tree::sub_tree(const CyA::point &p) : arcs_(),
                                              points_(),
                                              cost_(0)
    {
        points_.insert(p);
    }

    // constructor de copia
    sub_tree::sub_tree(const sub_tree &st) : arcs_(st.arcs_),
                                             points_(st.points_),
                                             cost_(st.cost_)
    {
    }

    sub_tree::~sub_tree(void)
    {
    }

    void sub_tree::add_arc(const CyA::arc &a)
    {
        arcs_.push_back(a);

        points_.insert(a.first);
        points_.insert(a.second);
    }

    void sub_tree::add_point(const CyA::point &p)
    {
        points_.insert(p);
    }

    bool sub_tree::contains(const CyA::point &p) const
    {
        return points_.find(p) != points_.end();
    }

    void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a)
    {
        arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
        arcs_.push_back(a.second);

        points_.insert(st.points_.begin(), st.points_.end());

        cost_ += a.first + st.get_cost();
    }
}