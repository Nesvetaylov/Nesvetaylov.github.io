#include <iostream>
using namespace std;

const int WIDTH=15;
const int HEIGHT = 8;

char Picture[HEIGHT][WIDTH];
void F(int x, int y, int imwidth, int imheight)
{

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		cout << "Ќекорректные координаты";
		return;
	}
	for (int i = y; i < imheight; i++)
	{
		for (int j = x; j < x+imwidth; j++)
		{
			if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH)
			{
				Picture[i][j] = '0';
			}
		}
	}

}

int main()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			Picture[i][j]='1';
		}
	}
	
	F(2, 0, 4, 5);
	F(10, 0, 3, 4);
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			cout << Picture[i][j];
		}
		cout << endl;
	}
	return 0;

}




/*
void F(char Picture[100][100], int width, int height, int x, int y)
{
	char image[3][2];//изобр с параметрами
	for (int i = y; i < y + height; i++)//добавление изобр в массив
	{
		if (i >= height)
		{
			break;
		}
		for (int j = x; j < x + width; j++)
		{
			if (j >= width)//за пределы
			{
				break;
			}
			Picture[i][j] = image[i - y][j - x];
		}
	}
}*/

