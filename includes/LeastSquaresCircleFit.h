//
// Created by jandres on 02/11/15.
//

#ifndef LEAST_SQUARES_CIRCLE_FIT_LEASTSQUARESCIRCLEFIT_H
#define LEAST_SQUARES_CIRCLE_FIT_LEASTSQUARESCIRCLEFIT_H

#include <tuple>
#include <vector>

#include "const.h"

namespace lscf {
    std::tuple<Radius, V2d> least_square_circle_fit(const std::vector<V2d>& v2ds) {
        return std::make_tuple(0.0F, V2d({0.0F, 0.0F}));
    };
}

#endif //LEAST_SQUARES_CIRCLE_FIT_LEASTSQUARESCIRCLEFIT_H
