# MLAMBDA-Eigen
Modified LAMBDA Algorithm using Eigen for GNSS Carrier Phase Ambiguity Resolution.
This is an offshoot of the GPSTk version of MLAMBDA, but implemented using the Eigen Library.
The original version can be found here: https://github.com/SGL-UT/GPSTk

## Synopsis
Least-squares Ambiguity Decorrelation (LAMBDA) is used to obtain optimal integer estimates of the float ambiguties corresponding to GNSS carrier phase observations. Modified LAMBDA (MLAMBDA) reduces the computational complexity of LAMBDA, while maintaining solution quality.

## Motivation
I was preparing my GNSS processing software using the Eigen library. I had implemented LAMBDA but it was long and complicated. When I saw GPSTk, its LAMBDA implementation was simpler and faster because it was based on MLAMBDA. The problem was GPSTk had its own Matrix and Vector implementation. So I modified the Modified LAMBDA to work with Eigen.

## Installation
You need Eigen 3.3.7 and Visual Studio 2017. I have included eigen here along with relative path property so that you can simply download the project and open "MLAMBDA.sln". This should work. 
If not, you can find more info about using eigen with VS here: http://eigen.tuxfamily.org/index.php?title=Visual_Studio

## Testing
You will find instructions in MLAMBDA.cpp.

## License
Free-to-use (MIT), but at your own risk. Credits to GPSTk and Eigen. 
