/**
 *
 */
#include <tuple>
#include <gtest/gtest.h>

#include "const.h"
#include "LeastSquaresCircleFit.h"

using namespace lscf;

TEST(LeastSquareCircleFitTest, BaseCase1) {
    std::vector<V2d> v2ds({V2d({0, 0}),
                           V2d({0, 5}),
                           V2d({1, 6}),
                           V2d({2, 7}),
                           V2d({8, 7})});
    std::tuple<Radius, V2d> result = least_square_circle_fit(v2ds);

    Radius r = std::get<0>(result);
    V2d center = std::get<1>(result);
    ASSERT_NEAR(30.57261F, r, 0.1);
    ASSERT_NEAR(4.98735F, std::get<0>(center), 0.1);
    ASSERT_NEAR(2.34605F, std::get<1>(center), 0.1);
}

GTEST_API_ int main(int argc, char **argv) {
    std::cout << "Running main() from base_test.cpp" << std::endl;

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}