#pragma once

#include <iostream>
#include <string>
#include <tuple>
#include "structures.h"
using namespace std;
const constexpr int size1 = 30;
class elastic_net {
public:
	void insert_city();
	void initialize_map();
	void print_map();
	pair <int, int>  compute_center_of_cities();
	void getCenterPosition();
	void make_circle(int r, int number_of_cities, float cv_ratio);
	int count_cities();
	void getpositioncity();
};
