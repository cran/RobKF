#include <RcppEigen.h>
#include "Particle.h"
#include <iostream>

void prepare_Particles(std::list <Particle> & Particle_List, const Eigen::MatrixXd & A, const Eigen::MatrixXd & C, const Eigen::MatrixXd & Sigma_Inn_contribution, const Eigen::MatrixXd & Sigma_Add_contribution)
{

	// This can be optimised further!

	std::list<Particle>::iterator it_Particle;

	for (it_Particle  = Particle_List.begin(); it_Particle != Particle_List.end(); ++it_Particle)
	{

		it_Particle->obs_Pred = C * A * it_Particle->mu;
		it_Particle->obs_Prec = ( C * A * it_Particle->Sigma  * A.transpose() * C.transpose()  + Sigma_Inn_contribution + Sigma_Add_contribution ).inverse();

	}

};
