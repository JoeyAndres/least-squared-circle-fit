//
// Created by jandres on 02/11/15.
//

#ifndef LEAST_SQUARES_CIRCLE_FIT_LEASTSQUARESCIRCLEFIT_H
#define LEAST_SQUARES_CIRCLE_FIT_LEASTSQUARESCIRCLEFIT_H

#include <tuple>
#include <vector>
#include <numeric>
#include <algorithm>

#include "const.h"

namespace lscf {
    std::tuple<Radius, V2d> least_square_circle_fit(const std::vector<V2d>& v2ds) {
        std::vector<double> u;
        std::transform(v2ds.begin(), v2ds.end(), u.begin(), [](const V2d& v2d) {
            return std::get<0>(v2d);
        });

        std::vector<double> v;
        std::transform(v2ds.begin(), v2ds.end(), v.begin(), [](const V2d& v2d) {
            return std::get<1>(v2d);
        });

        double u_avg = std::accumulate(u.begin(), u.end(), 0, [](double sum, double cur_val) {
            return sum + cur_val;
        });
        double v_avg = std::accumulate(v.begin(), v.end(), 0, [](double sum, double cur_val) {
            return sum + cur_val;
        });

        double s_uu = std::accumulate(u.begin(), u.end(), 0, [](double sum, double cur_val) {
            return sum + cur_val * cur_val;
        });
        double s_uuu;
        double s_vv = std::accumulate(v.begin(), v.end(), 0, [](double sum, double cur_val) {
            return sum + cur_val * cur_val;
        });
        double s_vvv;
        double s_uvv;
        double s_vuu;
        double v_c;
        double u_c;
        return std::make_tuple(0.0F, V2d({0.0F, 0.0F}));
    };
}

#endif //LEAST_SQUARES_CIRCLE_FIT_LEASTSQUARESCIRCLEFIT_H
