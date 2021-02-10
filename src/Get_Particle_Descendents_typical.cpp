#include "Particle.h"
#include <RcppEigen.h>

std::list < Particle > Get_Particle_Descendents_typical(Particle & Ancestor, double likelihood)
{

	std::list < Particle > out;

	out.push_back(initiate_Particle(Ancestor.log_prob + likelihood, 1, &Ancestor, 0, -1, -1));

	return(out);
	
};
