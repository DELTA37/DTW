#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <DTW/dtw.h>
#include <string>
#include <vector>

BOOST_PYTHON_MODULE(dtw) {
  using namespace boost::python;

  class_<std::vector<double>>("vectorDouble")
    .def(vector_indexing_suite<std::vector<double>>())
  ;

  class_<DTW>("DTW")
    .def("__call__", &DTW::operator());
  ;
}
