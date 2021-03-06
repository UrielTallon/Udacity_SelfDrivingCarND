/*
* particle_filter.cpp
*
*  Created on: Dec 12, 2016
*      Author: Tiffany Huang
*/

#ifndef PARTICLE_FILTER_H_
#define PARTICLE_FILTER_H_

#include "helper_functions.h"
#include <vector>

struct Particle {
	int id;
	double x;
	double y;
	double theta;
	double weight;
};

class ParticleFilter {

	int num_particles;

	bool is_initialized;

	std::vector<double> weights;

public:

	std::vector<Particle> particles;

	ParticleFilter() : num_particles(0), is_initialized(false) {}

	~ParticleFilter() {}

	void init(double x, double y, double theta, double std[]);

	void prediction(double delta_t, double std_pos[], double velocity, double yaw_rate);

	void dataAssociation(std::vector<LandmarkObs> predicted, std::vector<LandmarkObs> &observations);

	void updateWeights(double sensor_range, double std_landmark[],
					   std::vector<LandmarkObs> observations, Map map_landmarks);

	void resample();

	void write(std::string filename);

	const bool initialized() const {
		return is_initialized;
	}

};

#endif // !PARTICLE_FILTER_H_
