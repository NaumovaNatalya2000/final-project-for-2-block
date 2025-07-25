#include "IncludeLibrary.h"

int main() {
	setlocale(LC_ALL, "");
	//создаем контейнер set для хранения элементов класса User
	std::map<std::string, User> MapUser;

	//Открываем базовое меню
	MainMenu(MapUser);
}