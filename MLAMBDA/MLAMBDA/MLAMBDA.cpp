// MLAMBDA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "ARLambda.h"

using namespace std;
using namespace Eigen;

// Shows how to utilize MLAMBDA-Eigen
int main()
{

	// Lets assume you have the float ambiguities and corresponding covariance matrix
	// I have a sample here, taken from a GPS-only Relative kinematic processing routine,
	// The ambiguites belong to double-differenced carrier phase observations
	// NOTE : The units are in cycles
	// NOTE : Covariance values are large because it is taken from initial stages of processing

	VectorXd floatAmb = VectorXd::Zero(6);
	MatrixXd floatAmbCov = MatrixXd::Zero(6, 6);;

	floatAmb << -9.75792, 22.1086, -1.98908, 3.36186, 23.2148, 7.75073;

	floatAmbCov << 0.0977961, 0.0161137, 0.0468261, 0.0320695, 0.080857, 0.0376408,
		0.0161137, 0.0208976, 0.0185378, 0.00290225, 0.0111409, 0.0247762,
		0.0468261, 0.0185378, 0.0435412, 0.0227732, 0.0383208, 0.0382978,
		0.0320695, 0.00290225, 0.0227732, 0.0161712, 0.0273471, 0.0154774,
		0.080857, 0.0111409, 0.0383208, 0.0273471, 0.0672121, 0.0294637,
		0.0376408, 0.0247762, 0.0382978, 0.0154774, 0.0294637, 0.0392536;

	// Try Ambiguity Resolution...

	ARLambda AR;
	VectorXd intAmb(floatAmb.size()); intAmb.setZero();
	intAmb = AR.resolveIntegerAmbiguity(floatAmb, floatAmbCov);

	cout << "Float Ambiguity: \t" << floatAmb.transpose() << "\n";
	cout << "Integer Ambiguity: \t" << intAmb.transpose() << "\n";

}

