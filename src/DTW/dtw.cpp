#include <DTW/dtw.h>
#include "boost/multi_array.hpp"

double DTW::operator()(std::vector<double> const& a1, std::vector<double> const& a2) {
  size_t n = a1.size();
  size_t m = a2.size();
  boost::multi_array<double, 2> d(boost::extents[n][m]);
  double double_max = std::numeric_limits<double>::max();

  for (size_t i = 0; i < n; ++i)
  for (size_t j = 0; j < m; ++j) {
    d[i][j] = (a1[i] - a2[j]) * (a1[i] - a2[j]);
    if (i >= 1 || j >= 1) {
      d[i][j] += std::min({
        (i > 0)              ? d[i - 1][j]     : double_max, 
        ((i > 0) && (j > 0)) ? d[i - 1][j - 1] : double_max, 
        (j > 0)              ? d[i][j - 1]     : double_max 
      });
    }
  }
  size_t i = 0, j = 0;
  size_t K = 0;
  double val = 0;
  double val1, val2, val3;
  while((i < n) || (j < m)) {
    val += d[i][j];
    ++K;
    if (i + 1 < n && j + 1 < m) {
      val1 = d[i + 1][j];
      val2 = d[i][j + 1];
      val3 = d[i + 1][j + 1];

      if ((val3 <= val2) && (val3 <= val1)) {
        ++i;
        ++j;
        continue;
      }

      if ((val1 <= val2) && (val1 <= val3)) {
        ++i;
        continue;
      }
      if ((val2 <= val1) && (val2 <= val3)) {
        ++j;
        continue;
      }
    }
    if (i + 1 < n) {
      ++i;
      continue;
    }
    if (j + 1 < m) {
      ++j;
      continue;
    }
    break;
  }
  return val / K;
}

