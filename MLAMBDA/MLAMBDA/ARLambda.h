#pragma once

/*
* ARLambda.h
* Ambiguity Resolution using MLAMBDA
* As described in GPSTk : https://github.com/SGL-UT/GPSTk
* GPSTk version of MLAMBDA implemented using Eigen Library
* Created on: Nov 11, 2018
*      Author: Aaron
*/

#ifndef ARLAMBDA_H_
#define ARLAMBDA_H_

#include "pch.h"
#include "MathUtils.h"

class ARLambda
{
public:
	ARLambda();
	~ARLambda();

	Eigen::VectorXd resolveIntegerAmbiguity(Eigen::VectorXd& ambFloat, Eigen::MatrixXd& ambCov);

	bool isFixedSuccessfully(double threshhold = 3.0){
		return (squaredRatio>threshhold) ? true : false;
	}

	double squaredRatio;

protected:

	// lambda/mlambda integer least-square estimation
	// a     Float parameters (n x 1)
	// Q     Covariance matrix of float parameters (n x n)
	// F     Fixed solutions (n x m)
	// s     Sum of squared residulas of fixed solutions (1 x m)
	// m     Number of fixed solutions
	//      status (0:ok,other:error)
	int lambda(Eigen::VectorXd& a, Eigen::MatrixXd& Q, Eigen::MatrixXd& F, Eigen::VectorXd& s, const int& m = 2);

	// Q = L'*diag(D)*L
	int factorize(Eigen::MatrixXd& Q, Eigen::MatrixXd& L, Eigen::VectorXd& D);
	void gauss(Eigen::MatrixXd& L, Eigen::MatrixXd& Z, int i, int j);
	void permute(Eigen::MatrixXd& L, Eigen::VectorXd& D, int j, double del, Eigen::MatrixXd& Z);
	void reduction(Eigen::MatrixXd& L, Eigen::VectorXd& D, Eigen::MatrixXd& Z);

	// Modified lambda (mlambda) search
	virtual int search(Eigen::MatrixXd& L, Eigen::VectorXd& D, Eigen::VectorXd& zs, Eigen::MatrixXd& zn, Eigen::VectorXd& s, const int& m = 2);

};

#endif /* ARLAMBDA_H_ */