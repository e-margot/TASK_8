#include <iostream>
#include <string.h>
#include <math.h>
#include "windows.h"
#include "conio.h"
#include "variety.h"
#include <ctime>

using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd); //получаем DC(контекст устройства) для рисования
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
HPEN hpen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));;
HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 0));
HBRUSH hbrush1 = CreateSolidBrush(RGB(255, 0, 0));

Variety::Variety() {
	srand(unsigned(time(0)));
	do {
		cout << "Введите количество точек (более трех)" << endl;
		cin >> N;
		system("cls");
	} while (!check(N));
	ArrP = new point[N];
	ArrDist = new int*[N];
	Index = new int*[N];
	for (int i = 0; i < N; i++) {
		ArrDist[i] = new int[N];
		Index[i] = new int[N];
		ArrP[i].x = 0;
		ArrP[i].y = 0;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			ArrDist[i][j] = 0;
			Index[i][j] = j;
		}
			
	for (int i = 0; i < N; i++) {
		ArrP[i].x = 400 + rand() % 500;
		ArrP[i].y = 20 + rand() % 300;
	}
	
}
Variety::Variety(int N) {
	srand(unsigned(time(0)));
	this->N = N;
	ArrP = new point[N];
	ArrDist = new int*[N];
	for (int i = 0; i < N; i++) {
		ArrDist[i] = new int[N];
		ArrP[i].x = 0;
		ArrP[i].y = 0;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ArrDist[i][j] = 0;
	for (int i = 0; i < N; i++) {
		ArrP[i].x = 400 + rand() % 500;
		ArrP[i].y = 20 + rand() % 300;
	}
}
Variety::~Variety() {
	delete[] ArrP;
	for (int i = 0; i < N; i++)
		delete[] ArrDist[i];
	delete[] ArrDist;

}
bool Variety::check(int num) {
	if (N < 3) {
		cout << "Количество точек меньше трех" << endl;
		return false;
	}
	return true;
}

void Variety::Draw(int i1, int i2, int i3) {
	SelectObject(hdc, hpen);
	SelectObject(hdc, hbrush);
	for (int i = 0; i < N; i++) {
		SelectObject(hdc, hbrush);
		Ellipse(hdc, ArrP[i].x - 3, ArrP[i].y - 3, ArrP[i].x + 3, ArrP[i].y + 3);
	}
}
void Variety::SearchDist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ArrDist[i][j] = sqrt(pow((ArrP[j].x - ArrP[i].x), 2) + pow((ArrP[j].y - ArrP[i].y), 2));
		
		}
		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ArrDist[i][j] << "\t";

		}
		cout << endl;
	}
	cout <<"----------------SORT---------------"<< endl;
	Sort();
	
}
void Variety::Sort() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				if (ArrDist[i][j] < ArrDist[i][k])
				{
					int tmp = ArrDist[i][j];
					ArrDist[i][j] = ArrDist[i][k];
					ArrDist[i][k] = tmp;
					tmp = Index[i][j];
					Index[i][j] = Index[i][k];
					Index[i][k] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ArrDist[i][j] << "\t";

		}
		cout << endl;
	}
	cout << "----------------INDEX------------------" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Index[i][j] << "\t";
		}
		cout << endl;
	}
	int MAX = 0;
	point IndMax;
	IndMax.x = 0; //first point of max distans
	IndMax.y = 0;
	for (int i = 0; i < N; i++) {
		if (ArrDist[i][N] > MAX) {
			MAX = ArrDist[i][N];
			IndMax.x = i; //first point of max distans
			IndMax.y = Index[i][N];  //second point of max distans
		}
	}
	cout << MAX << endl;
	int max2 = 0;
	cout << "____________our index________" << endl;
	if (ArrDist[IndMax.x][N - 1] > ArrDist[IndMax.y][N - 1]) {
		cout << Index[IndMax.x][N - 1] << "\t" << IndMax.x << "\t" << IndMax.y << endl;
		Draw(Index[IndMax.x][N - 1], IndMax.x, IndMax.y);
	}
	else {
		cout << Index[IndMax.y][N - 1] << "\t" << IndMax.x << "\t" << IndMax.y << endl;
		Draw(Index[IndMax.y][N - 1], IndMax.x, IndMax.y);
	}
}
