
#include "elastic_net.h"


int main() {

	elastic_net EN;
	EN.initialize_map();
	EN.print_map();
	
	
	char z = 'y';
	while (z == 'y') {
		EN.insert_city();
		cout << "noch eine stadt ? " << endl;
		cin >> z;
	}
	
	EN.print_map();
	printf("\n");
	EN.compute_center_of_cities();
	printf("\n");
	int radius = 6;
	float cv_ratio1 = 3.0;
	int c = EN.count_cities();
	EN.make_circle(radius, c, cv_ratio1);
	EN.print_map();
	printf("\n");
	EN.getpositioncity();
	printf("\n");
	system("pause");
	return 0;
};


