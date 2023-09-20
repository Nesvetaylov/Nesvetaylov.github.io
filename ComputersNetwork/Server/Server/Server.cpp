#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>

using namespace std;
struct Person
{
	char name[25];
	int grade[4];
}B;

struct Client
{
	string name;
	int size;
};
int answer;
long size_pred;

void Print() {
	cout << endl << "Запрос получен: " << B.name << " ";
	for (int i = 0; i < 5; i++)
		cout << B.grade[i] << " ";
	cout << endl;
}
int Stipendia() {
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 2)
		{
			cout << "1" << endl;
			return 1;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 3)
		{
			cout << "2" << endl;
			return 2;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 4)
		{
			cout << "3" << endl;
			return 3;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (B.grade[i] == 5)
		{
			cout << "4" << endl;
			return 4;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	long size_of_Connections;

	ofstream out_of_Information;
	ifstream in_Information;
	ifstream newClientFile;

	string path = "F:/ComputersNetwork/Information/";
	string infFile = path + "information.bin";
	string newClientName;

	out_of_Information.open(infFile, ios::binary | ios::app); // создадим connection.bin, если его нет
	out_of_Information.close();

	in_Information.open(infFile, ios::binary); //открытие файла connection.bin
	in_Information.seekg(0, ios::end);
	size_of_Connections = in_Information.tellg();
	in_Information.close();

	vector<Client> client;

	cout << "Сервер работает" << endl;
	cout << "Размер файла подключений: " << size_of_Connections << endl;

	while (true) // начало работы сервера
	{   // проверка наличия новых клиентов
		in_Information.open(infFile, ios::binary); //открытие файла connection.bin
		in_Information.seekg(0, ios::end);
		if (size_of_Connections < in_Information.tellg()) // найден новый клиент
		{
			in_Information.seekg(size_of_Connections, ios::beg);
			in_Information.read((char*)&newClientName, sizeof(newClientName));

			Client newClientData;
			newClientFile.open(path + newClientName + ".bin");
			newClientFile.seekg(0, ios::end);
			newClientData.name = newClientName;
			newClientData.size = newClientFile.tellg();
			client.push_back(newClientData);
			newClientFile.close();

			in_Information.seekg(0, ios::end);
			size_of_Connections = in_Information.tellg();

			cout << endl << "Новый клиент: " << newClientName << endl;
			cout << "Размер файла подключений: " << size_of_Connections << endl;
		}
		in_Information.close();

		// Обход текущих клиентов
		bool haveNewInput = false;
		int answer = 9;
		ofstream outFile;
		ifstream inFile;
		for (int i = 0; i < client.size(); i++)
		{
			inFile.open(path + client[i].name + ".bin", ios::binary);
			inFile.clear();
			inFile.seekg(0, ios::end);
			if (client[i].size < inFile.tellg())
			{
				inFile.seekg(client[i].size, ios::beg);
				inFile.read((char*)&B, sizeof(B));
				haveNewInput = true;
				Print();
			}
			inFile.close();

			if (haveNewInput)
			{
				cout << "Ответ отправлен: ";
				outFile.open(path + client[i].name + ".bin", ios::app | ios::binary);
				answer = Stipendia();
				outFile.write((char*)&answer, sizeof(answer));
				outFile.seekp(0, ios::end);
				client[i].size = outFile.tellp();
				outFile.close();
			}
			haveNewInput = false;
		}
		Sleep(100);
	}
}
