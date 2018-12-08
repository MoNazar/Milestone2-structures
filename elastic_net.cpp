#include "elastic_net.h"
#include "structures.h"
char map2[size1][size1];
City stadt1;
void elastic_net::initialize_map() {
	int i, j; 
	for (i = 0; i < size1; i++) {
		for (j = 0; j < size1; j++) {
			map2[i][j] = 0;
		}
	}
	 
}

void elastic_net::print_map() {
	int i, j; 
	for (i = 0; i < size1; i++) {
		for (j = 0; j < size1; j++) {
			printf("%d ", map2[i][j]);
		}
		printf("\n");
	}
	
}

void elastic_net::insert_city() {
	int x, j = 0;
	cout << "Koordinaten der neuen Stadt" << endl;
	cin >> x >> j;
	map2[x][j] = stadt1.nodeofcity;
}

int elastic_net::count_cities() {
	int city_counter = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map2[i][j] == 1) {
				city_counter++;
			}
		}
	}
	return city_counter;
}

pair <int, int> elastic_net::compute_center_of_cities() {
	int x = 0;
	int y = 0;
	int city_counter = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			if (map2[i][j] == 1) {
				x += i;
				y += j;
				city_counter++;
			}
		}
	}
	x /= city_counter;
	y /= city_counter;
	map2[x][y] = 2;
	pair<int, int> center = { x, y };
	return center;
}
void elastic_net::getCenterPosition(){
	int i, j;
	for (i = 0; i < size1; i++) {
		for (j = 0; j < size1; j++) {
			if (map2[i][j] == 2) {
				cout << i << " " << j << endl;
			}
		}	
	}
}

void elastic_net::make_circle(int r, int number_of_cities, float cv_ratio) {
	int koordinate1, koordinate2 = 0;
	// 1: Koordinaten des Zentrums ermitteln
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			if (map2[i][j] == 2) {
				koordinate1 = i; koordinate2 = j;
				break;

			}
		}
	}
	int number_of_vertices = cv_ratio * number_of_cities;
	double alpha = 0;
	for (int h = 1; h <= number_of_vertices; h++) {
		int y = (int)(koordinate1 + (r*cos(alpha)));
		int x = (int)(koordinate2 + (r* sin(alpha)));
		//map[y][x] = 3;
		map2[y][x] = 3;
		alpha += (2 * 3.14159265) / number_of_vertices;
		
	}
	
}
// Nächster Schritt : 
/* Implementiere einen Kreis mit radius r, und platziere Anzahl_Städte Knoten äquidistanz auf Kreis.*/