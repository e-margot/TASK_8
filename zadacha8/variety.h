#pragma once

struct point {
	int x, y;
};

class Variety {
private:
	point* ArrP;
	int** Index;
	int** ArrDist;
	int N;
public:
	Variety();
	Variety(int N);
	~Variety();
	void Draw(int i1, int i2, int i3);
	void SearchDist();
	void Sort();
	bool check(int num);
};