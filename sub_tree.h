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

#pragma once

#include <iostream>
#include <cmath>

#include "point_types.h"

namespace EMST
{
    class sub_tree {
    public:
        sub_tree(void);
        sub_tree(const CyA::point &p);
        sub_tree(const sub_tree &st);
        ~sub_tree(void);

        void add_arc(const CyA::arc &a);
        void add_point(const CyA::point &p);
        bool contains(const CyA::point &p) const;
        void merge(const sub_tree &st, const CyA::weigthed_arc &a);

        inline const CyA::tree& get_arcs(void) const { return arcs_; }
        inline double get_cost(void) const { return cost_; }
    private:
        CyA::tree arcs_;
        CyA::point_collection points_;
        double cost_;

    };

    typedef std::vector<sub_tree> sub_tree_vector;
}