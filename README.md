# least-squared-circle-fit

Based of: http://www.dtcenter.org/met/users/docs/write_ups/circle_fit.pdf

## Installation and Building

There is only one external library and that is ```armadillo```. This is available in yum/dnf/apt-get repositories
based upon my _distro swinging_ vice.

git clone this repo and then in the directory:

```bash
mkdir build
cd build
cmake ..
make -j16
sudo make install
```

Congratulation, you have installed least-squared-circle-fit!!!

## Example:

Consider a circle with a radius of 2 and centers in (0, 0) in cartesian plane. Now suppose
we only know some points (3 points or more) that lies in the circumference of this circle, [ (-2, 0), (0, -2), (2, 0) ],

```cpp
#include <vector>
#include <utility>  // std::get...

#include <least_squared_circle_fit/LeastSquaredCircleFit.h>

int main() {
    std::vector<lscf::V2d> circle_coords({
      lscf::V2d({-2, 0}),
      lscf::V2d({0, -2}),
      lscf::V2d({2, 0})
    });

    auto result = lscf::least_square_circle_fit(v2ds);

    // Radius.
    double radius = std::get<0>(result);

    // Center coordinate.
    V2d center = std::get<1>(result);
    double center_x = std::get<0>(center);
    double center_y = std::get<1>(center);
}
```

Add ````-larmadillo``` to your Makefile, or simply ```armadillo``` to your cmake.

## Contact
To ask more questions about this thing, contact at jandres@ualberta.ca