#pragma once




#include "Iterable.h"

class Iterator : public Iterable {
	void solve(float eta, int iter_max);
	void apply();
};
