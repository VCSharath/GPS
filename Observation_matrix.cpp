#include "stdafx.h"
#include <math.h>
#include <iostream>

#define MAX_SAT 32

using namespace std;

class PVT_Computaions
{
public:
	float G[MAX_SAT][4];
	float W[MAX_SAT][MAX_SAT] = {0};

	int build_obesrvation_matrix(float elev_angle[], float azim_angle[], int N)
	{
		// This implementation is derived from DO-229D observation matrix description
		// Gi = [-cos(elevation_angle_i)sin(azimuth_angle_i) -cos(elevation_angle_i)cos(azimuth_angle_i) -sin(elevation_angle_i) 1]... ith row
		for (int i = 0; i < N; i++)
		{
			G[i][0] = -(cos(elev_angle[i])*sin(azim_angle[i]));
			G[i][1] = -(cos(elev_angle[i])*cos(azim_angle[i]));
			G[i][2] = -(sin(elev_angle[i]));
			G[i][3] = 1.0;
		}
		return 0;
	}

	int weighted_matrix(float std_deviation[], int N)
	{
		float variance = 0.0;
		for (int i; i < N; i++)
		{
			variance = 1 / (pow(std_deviation[i], 2));
			W[i][i] = variance;
		}
		return 0;
	}

}