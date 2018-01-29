find_package(PythonInterp 2.7  REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)
find_package (Boost 1.62 COMPONENTS python REQUIRED)

set(PYTHON_VERSION 2.7)
set(PYTHON_INCLUDE /usr/include/python${PYTHON_VERSION})
set(PYTHON_LIBS -L/usr/lib/python${PYTHON_VERSION}/config) 
set(PYTHON_LIBS ${PYTHON_LIBS} -L/usr/lib/python${PYTHON_VERSION})
SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)

add_definitions("-Wall")
include_directories(${Boost_INCLUDE_DIR} ${PYTHON_INCLUDE})

add_library(dtw SHARED generate-python-bindings.cpp)
target_link_libraries(dtw ${Boost_LIBRARIES} ${PYTHON_LIBS} boost_python DTW python${PYTHON_VERSION})
set_target_properties(dtw PROPERTIES SUFFIX .so)
set_target_properties(dtw PROPERTIES PREFIX "")
