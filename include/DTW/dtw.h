#pragma once
#include <vector>


struct DTW {
  double operator()(std::vector<double> const& a1, std::vector<double> const& a2);
};

