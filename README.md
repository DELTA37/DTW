# DTW
Dynamic time warping C++ library with Python module
mkdir build  
cd build  
cmake .. && make -j 4  
cd python  
python2.7  
> import dtw  
> arr1 = dtw.vectorDouble()  
> arr2 = dtw.vectorDouble()  
> arr1.extend([1,2,3,4])  
> arr2.extend([2,3,4,5])  
> metric = dtw.DTW()  
> print(metric(arr1, arr2))  
