#include <iostream>
#include<vector>
#include<string>
#include<windows.h>
#include<locale>
#undef max
class Kib {
	public:
		int8_t bytes[1024];
};

class Mib {
public:
	Kib kibibytes[1024];
};

class Gib {
public:
	Mib Mibibyte[1024];
};

int main()
{
	system("chcp 1252");
	setlocale(LC_ALL, "Se");
	int choice = 0;
	int memsize = 0;
	try {
		std::vector<Kib*> Kibibyte;
		std::vector<Mib*> Mebibyte;
		std::vector<Gib*> Gibibyte;


		bool MenuOn = true;
		while (MenuOn != false)
		{

			system("CLS");
			std::wcout << "#######################################\n";
			std::wcout << " 1 - Allokera Kib.\n";
			std::wcout << " 2 - Allokera Mib.\n";
			std::wcout << " 3 - allokera Gib.\n";
			std::wcout << " 4 - Exit.\n";
			std::wcout << " Välj alternativ och tryck Enter: \n";
			std::wcout << "#######################################\n";
			std::wcout << ((Kibibyte.size()) + (Mebibyte.size()) + (Gibibyte.size() * 1024)) << " MiB Minne allokerat.\n";

			std::cin >> choice;
			if (!std::cin)
				std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("CLS");
			if(choice != 4)
			{
			std::wcout << " Skriv in talet för storleken" << std::endl;
			std::cin >> memsize;
			}
			
			switch (choice)
			{
			case 1:
				for (int k = 0; k < memsize; k++)
					Kibibyte.emplace_back(new Kib);

				std::wcout << Kibibyte.size() << " Kibibyte Minne allokerat " << std::endl;

				Sleep(3000);


				memsize = 0;
				break;
			case 2:
				for (int k = 0; k < memsize; k++)
					Mebibyte.emplace_back(new Mib);

				std::wcout << Mebibyte.size() << " Mibibyte Minne allokerat" << std::endl;

				Sleep(3000);

				memsize = 0;
				break;
			case 3:
				for (int k = 0; k < memsize; k++)
					Gibibyte.emplace_back(new Gib);
				std::wcout << Gibibyte.size() << " Gigabyte Minne allokerat" << std::endl;

				Sleep(3000);
				memsize = 0;
				break;
			case 4:
				std::wcout << "Du valde att avsluta programmet\n";
				std::wcout << "Minnet släpps nu fritt\n";

				Sleep(3000);
				MenuOn = 0;

			}
			choice = 0;

			
		}
		for (int i = 0; i < Kibibyte.size(); i++)
			delete Kibibyte[i];

		for (int j = 0; j < Gibibyte.size(); j++)
			delete Gibibyte[j];

		for (int k = 0; k < Mebibyte.size(); k++)
			delete Mebibyte[k];
	}
	catch (std::bad_alloc e)
	{
		std::cerr << e.what() << std::endl;
		Sleep(3000);
	}



	return 0;
}