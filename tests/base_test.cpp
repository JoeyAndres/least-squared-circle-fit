/**
 *
 */
#include <tuple>
#include <gtest/gtest.h>

#include "const.h"
#include "LeastSquaresCircleFit.h"

using namespace lscf;

// Avg is the (0, 0). Thus just testing radius for r=1.
TEST(LeastSquareCircleFitTest, BaseCase1) {
    std::vector<V2d> v2ds({V2d({-1, 0}),
                           V2d({0, 1}),
                           V2d({1, 0}),
                           V2d({0, -1}) });
    std::tuple<Radius, V2d> result = least_square_circle_fit(v2ds);

    Radius r = std::get<0>(result);
    V2d center = std::get<1>(result);

    ASSERT_NEAR(1.0, r, 0.1);
    ASSERT_NEAR(0.0, std::get<0>(center), 0.1);
    ASSERT_NEAR(0.0, std::get<1>(center), 0.1);
}

// Avg of y is not 0. Now testing the center.
TEST(LeastSquareCircleFitTest, BaseCase2) {
    std::vector<V2d> v2ds({V2d({-1, 0}),
                           V2d({0, 1}),
                           V2d({1, 0}) });
    std::tuple<Radius, V2d> result = least_square_circle_fit(v2ds);

    Radius r = std::get<0>(result);
    V2d center = std::get<1>(result);

    ASSERT_NEAR(1.0, r, 0.1);
    ASSERT_NEAR(0.0, std::get<0>(center), 0.1);
    ASSERT_NEAR(0.0, std::get<1>(center), 0.1);
}

// Avg of x is not 0. Now testing the center.
TEST(LeastSquareCircleFitTest, BaseCase3) {
    std::vector<V2d> v2ds({V2d({-1, 0}),
                           V2d({0, 1}),
                           V2d({0, -1}) });
    std::tuple<Radius, V2d> result = least_square_circle_fit(v2ds);

    Radius r = std::get<0>(result);
    V2d center = std::get<1>(result);

    ASSERT_NEAR(1.0, r, 0.1);
    ASSERT_NEAR(0.0, std::get<0>(center), 0.1);
    ASSERT_NEAR(0.0, std::get<1>(center), 0.1);
}

// Avg is the (0, 0). r=1 = alpha=sqrt(r)=1, which is actually a special case. Test for non-special case then.
TEST(LeastSquareCircleFitTest, BaseCase4) {
    std::vector<V2d> v2ds({V2d({-2, 0}),
                           V2d({0, 2}),
                           V2d({2, 0}),
                           V2d({0, -2}) });
    std::tuple<Radius, V2d> result = least_square_circle_fit(v2ds);

    Radius r = std::get<0>(result);
    V2d center = std::get<1>(result);

    ASSERT_NEAR(2.0, r, 0.1);
    ASSERT_NEAR(0.0, std::get<0>(center), 0.1);
    ASSERT_NEAR(0.0, std::get<1>(center), 0.1);
}

// Avg of x is not 0. r=1 = alpha=sqrt(r)=1, which is actually a special case. Test for non-special case then.
TEST(LeastSquareCircleFitTest, BaseCase5) {
    std::vector<V2d> v2ds({V2d({-2, 0}),
                           V2d({0, 2}),
                           V2d({0, -2}) });
    std::tuple<Radius, V2d> result = least_square_circle_fit(v2ds);

    Radius r = std::get<0>(result);
    V2d center = std::get<1>(result);

    ASSERT_NEAR(2.0, r, 0.1);
    ASSERT_NEAR(0.0, std::get<0>(center), 0.1);
    ASSERT_NEAR(0.0, std::get<1>(center), 0.1);
}

// Avg of y is not 0. r=1 = alpha=sqrt(r)=1, which is actually a special case. Test for non-special case then.
TEST(LeastSquareCircleFitTest, BaseCase6) {
    std::vector<V2d> v2ds({V2d({-2, 0}),
                           V2d({0, 2}),
                           V2d({2, 0})});
    std::tuple<Radius, V2d> result = least_square_circle_fit(v2ds);

    Radius r = std::get<0>(result);
    V2d center = std::get<1>(result);

    ASSERT_NEAR(2.0, r, 0.1);
    ASSERT_NEAR(0.0, std::get<0>(center), 0.1);
    ASSERT_NEAR(0.0, std::get<1>(center), 0.1);
}

GTEST_API_ int main(int argc, char **argv) {
    std::cout << "Running main() from base_test.cpp" << std::endl;

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}