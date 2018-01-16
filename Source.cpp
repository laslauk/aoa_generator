#include <string>
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class AOGenerator {
public:
	string generate(int lines);
};

string AOGenerator::generate(int lines) {

	string text;
	for (int i = 0; i < lines; i++)
	{
		std::random_device rd;
		std::mt19937 rng(rd());  
		std::uniform_int_distribution<int> uni(1, 24); 

		auto length = uni(rng);
		char letter;
	
		for (int a = 0; a <= length; a++)
		{
			std::uniform_int_distribution<int> unif(1, 2); // guaranteed unbiased
			auto number = unif(rng);
			
			switch (number) {
			case 1:
				letter = 'ö';
				break;
			case 2:
				letter = 'ä';
				break;
			default:
				letter = 'X';
				break;
			}

			text.push_back(letter);

			if(a != length){text.push_back('-');}
		}
		text.append("\n");
	}
	return text;
}

int main()
{
	setlocale(LC_ALL, "finnish");
	AOGenerator generator;
	fstream file("aoao.txt", fstream::in | fstream::out | fstream::trunc);
	cout << "Tervetuloa generoimaan ä-ö-ä!" << endl;
	cout << "Syötä rivien määrä, max 20!: " << endl;

	int input;

	cin >> input;

	while(cin.fail())
	{
		cout << "Virhe syötteessä, syötä numero!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}

	if (!(input >= 0 && input <= 20))
	{
		cout << "Syötä numero 0-20" << endl;
	}

	else{
		int lines = input;

	try {
		if (file.is_open())
		{
			cout << "File opened!"<< endl;
			cout << generator.generate(lines);
			file << generator.generate(lines);
			cout << "*********************" << endl;
			cout << "Tiedostoon aoao.txt kirjoitettu onnistuneesti!" << endl;
		}
		else {
			cout << "ERROR OPENING FILE!" << endl;
		}
	}
	catch (...)
	{
		cout << "Unexpected error :( yoloswag!" << endl;
		return 0;
	}

	file.close();
	}
	system("pause");
	return 0;
}