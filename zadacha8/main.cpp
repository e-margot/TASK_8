//#include "pch.h"
#include "windows.h"
#include "conio.h"
#include <iostream>

#include "variety.h"

#define PI 3.14159265

using namespace std;
int N;
int** graph;
/*
HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd); //получаем DC(контекст устройства) для рисования
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
HPEN hpen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));;
HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 0));
HBRUSH hbrush1 = CreateSolidBrush(RGB(255, 0, 0));*/
//void Pyxel(HDC hdc, int x1, int y1, COLORREF clr);
/*struct point {
	float x;
	float y;
};

void init_matrix() {
	int k = 0;

	std::cout << "Введите количество городов: ";
	std::cin >> N;

	graph = new int *[N];
	for (int i = 0; i < N; ++i)
		graph[i] = new int[N];

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (j == i) {
				graph[i][j] = 0;
				continue;
			}
			std::cout << "Введите расстояние между городом " << i + 1 << " и " << j + 1 << ": ";
			std::cin >> k;
			graph[i][j] = k;
			graph[j][i] = k;
		}
	}
	std::cout << "\nМатрица\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			std::cout << graph[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

int calculate_way() {
	int min = 10000000;
	int tmp = 0;
	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			tmp += graph[i][j];
		std::cout << "Сумма растояний города " << i + 1 << ": " << tmp << "\n";
		if (tmp < min) {
			index = i;
			min = tmp;
		}
		tmp = 0;
	}
	return index;
}

void draw_graph(int n) {
	point* masP = new point[N];
	point p0, p;
	COORD pos;
	p0.x = 800;
	p0.y = 200;
	int R = 20 * N;
	int delta = 360 / N;
	float a = 215;
	for (int i = 0; i < N; i++) {
		p.x = R * sin(a*PI / 180) + p0.x;
		p.y = R * cos(a*PI / 180) + p0.y;
		masP[i].x = p.x; masP[i].y = p.y;
		Ellipse(hdc, p.x - 15, p.y - 15, p.x + 15, p.y + 15);
		p.x = 0; p.y = 0;
		a -= delta;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			MoveToEx(hdc, masP[i].x, masP[i].y, NULL);
			LineTo(hdc, masP[j].x, masP[j].y);
		}
	}
	for (int i = 0; i < N; i++)
		if (i == n) {
			SelectObject(hdc, hbrush1);
			Ellipse(hdc, masP[i].x - 15, masP[i].y - 15, masP[i].x + 15, masP[i].y + 15);
			SelectObject(hdc, hbrush);
		}
}
void draw() {
	int n = 1;
	srand(unsigned(time(0)));
	cout << "Введите количество точек" <<endl ;
	cin >> n;
	
	int* Px;
	int* Py;
	Px = new int [n];
	Py = new int [n];
	for (int i = 0; i < n; i++) {
		Px[i] = 400 + rand() % 500;
		Py[i] = 20 + rand() % 300;
	//	Pyxel(hdc, Px[i], Py[i], 0x0000FF00);
		SelectObject(hdc, hbrush);
		Ellipse(hdc, Px[i] - 3, Py[i] - 3, Px[i] + 3, Py[i] + 3);
	//	SetPixel(hdc, Px[i], Py[i], RGB(0, 0, 0));
	//	cout << Px[i] << endl;
	//	cout << Py[i] << endl;
	}

}
void Pyxel(HDC hdc, int x1, int y1, COLORREF clr) // точка
{
	HPEN hPen; //Объявляется кисть
	hPen = CreatePen(PS_SOLID, 1, clr); //Создаётся объект
	SelectObject(hdc, hPen); //Объект делается текущим
	SetPixel(hdc, x1, y1, clr);
	DeleteObject(hPen);
}*/
int main()
{
	//SelectObject(hdc, hpen);
	//SelectObject(hdc, hbrush);

	setlocale(LC_ALL, "Russian");
	//init_matrix();
	//draw_graph(calculate_way());
	//draw();
	Variety var;
	var.SearchDist();
	//var.Draw();
	_getch();
	//_getch();
	return 0;
}
