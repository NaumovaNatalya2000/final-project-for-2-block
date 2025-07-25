#include "FunctionsMenu.h"

void MainMenu(std::map<std::string, User>& users) {

	char BasicMenu{}; //переменная для перехода по базовому меню
	std::string input; //переменная для считывания потока ввода

	while (BasicMenu != 'q' && BasicMenu != 'Q') {
		clearScreen(); //чистка экрана при каждой итерации цикла
		std::cout << "------------Основное меню программы Чатик------------\n"
			<< "-----------------------------------------------------\n"
			<< "Выберите пункт меню:\n"
			<< "1 - Регистрация пользователя в системе\n"
			<< "2 - Вход в чат(если уже прошли регистрацию)\n"
			<< "-----------------------------------------------------\n"
			<< "Введите q для выхода из программы(все данные будут удалены!)" << std::endl;

		BasicMenu = NotEmptyChar(); //считывание первого символа из потока
		switch (BasicMenu){
			case '1': RegistrationMenu(users); break; //переход в меню регистрации
			case '2': MessageMenu(users); break; //переход в меню сообщений
			default: break;
		}
	}
}

void RegistrationMenu(std::map<std::string, User>& users)
{
	char RegMenu{'a'}; //переменная для перехода по меню регистрации
	std::string input; //переменная для считывания потока ввода

	do {
		RegMenu = 'a';
		clearScreen(); //чистка экрана при каждой итерации цикла
		std::string login, password, name; //переменные логин, пароль, имя
		
		login = NotEmptyString("Введите логин:");
		password = NotEmptyString("Введите пароль:");
		std::vector<uint8_t> vecPass(password.begin(), password.end());
		name = NotEmptyString("Введите имя:");

		//проверка не существует ли пользователь с таким логином
		auto it = users.find(login);
		if (it == users.end()) {
			users.insert({ login, User(login, SHA1(vecPass), name) });
			std::cout << "Добавлен новый пользователь с логином: " << login << std::endl;
			pause();
		}
		else {
			std::cout << "Пользователь с указанным логином уже существует. Повторите попытку регистрации.\n" << login << std::endl;
			pause();
			continue;
		}
		std::cout << "Вы хотите создать еще одного пользователя?(Введите y)\n"
			<< "-----------------------------------------------------\n"
			<< "Если Вы хотите вернуться в главное меню, введите любой другой символ" << std::endl;
		std::getline(std::cin, input);
		if (!input.empty() && input[0]!='\n') {
			RegMenu = input[0]; //считывание первого символа из потока
		}
	} while (RegMenu == 'y' || RegMenu == 'Y');
}

void MessageMenu(std::map<std::string, User>& users)
{
	char MesMenu{}; //переменная для перехода по меню сообщений
	std::string input;//переменная для считывания потока ввода

	do {
		clearScreen();
		std::string login, password; //переменные логин, пароль

		std::cout << "------------Отправка сообщений------------\n"
			<< "Выберите пункт меню:\n"
			<< "1 - Вывести список доступных логинов\n"
			<< "2 - Вход по логину\n"
			<< "q - для возврата на основное меню" << std::endl;

		std::getline(std::cin, input);
		if (!input.empty()) {
			MesMenu = input[0]; //считывание первого символа из потока
		}
		if (MesMenu == '1') {
			clearScreen();
			PrintUsers(users);
		}
		if (MesMenu == '2') {
			std::cout << "------------Вход в систему------------\n" << std::endl;
			login = NotEmptyString("Введите логин:");
			//поиск логина
			auto it = users.find(login);
			if (it != users.end()) {
				std::cout << "Пользователь с логином " << login << " найден\n"
					<< "Введите пароль:" << std::endl;
				std::getline(std::cin, password);
				std::vector<uint8_t> vecPass(password.begin(), password.end());

				//если пароль совпадает
				if (it->second.IsCorrectPassword(SHA1(vecPass))) {
					clearScreen();
					//индекс пользователя - i - передаем его в новое подменю
					SendingMenu(users, it);
				}
				else {
					std::cout << "Пароль введен неверно" << std::endl;
					pause();
				}
			}
			//если логин не найден
			else {
				std::cout << "Введенного логина не существует" << std::endl;
				pause();
			}
		}
	} while (MesMenu != 'q' && MesMenu != 'Q');
}

void SendingMenu(std::map<std::string, User>& users, std::map<std::string, User>::iterator it)
{
	char SendMenu{'a'}; //переменная для перехода по подменю сообщений
	std::string input; //переменная для считывания потока ввода

	do {
		clearScreen();
		std::cout << "Вы вошли в систему под логином: " << it->first << "\n"
			<< "-----------------------------------------------------\n"
			<< "1 - Вывести список пользователей\n"
			<< "2 - Отправка сообщений одному пользователю\n"
			<< "3 - Отправка сообщений всем пользователям\n"
			<< "4 - Вывести список сообщений для меня\n"
			<< "q - для возврата на предыдущее меню " << std::endl;
		SendMenu = NotEmptyChar();
		
		if (SendMenu == '1') {
			clearScreen();
			PrintUsers(users);
		}
		if (SendMenu == '2') {
			clearScreen();
			std::string fromUser = it->first; //переменная отправитель
			std::string toUser, text; //переменные получатель и текст сообщения

			std::cout << "---Отправка сообщения конкретному пользователю---\n"
				<< "Введите логин, кому хотите отправить сообщение" << std::endl;
			std::getline(std::cin, toUser);
			//поиск логина
			auto it2 = users.find(toUser);
			if (it2 != users.end()) {
				std::cout << "Пользователь под логином " << toUser << " найден\n"
					<< "Введите текст сообщения" << std::endl;
				std::getline(std::cin, text);
				it2->second.addMessage(fromUser, text);
			}
			else {
				std::cout << "Логин не найден" << std::endl;
				pause();
			}
		}
		if (SendMenu == '3') {
			clearScreen();
			
			std::string fromUser = it->first; //отправитель
			std::string text; //текст сообщения

			std::cout << "---Отправка сообщения всем пользователям---" << std::endl;
			std::cout << "Введите текст сообщения" << std::endl;
			std::getline(std::cin, text);
			for (auto it2 = users.begin(); it2 != users.end(); it2++) {
				it2->second.addMessage(fromUser, text);
			}
		}
		if (SendMenu == '4') {
			clearScreen();
			it->second.PrintMessage();
			pause();
		}
	} while (SendMenu != 'q' && SendMenu != 'Q');
}

void PrintUsers(const std::map<std::string, User>& users)
{
	std::cout << "Список пользователей:\n"
		<< "-----------------------------------------------------" << std::endl;
	for (auto it = users.begin(); it != users.end(); it++) {
		std::cout << (*it).first << std::endl;
	}
	pause();
	clearScreen();
}

std::string NotEmptyString(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
	} while (input.empty());
	return input;
}

char NotEmptyChar()
{
	std::string input;
	std::getline(std::cin, input); //ввод данных до первого enter
	if (!input.empty()) {
		return input[0]; //считывание первого символа из потока
	}
	else {
		return 'a';
	}
}