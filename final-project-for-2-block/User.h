#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "FunctionsSystem.h"
#include "Messages.h"

class User
{
public:
	//конструктор с параметрами
	User(const std::string& login, const std::vector<uint8_t>& password, const std::string& name);
	//деструктор
	~User();
	//запрещаем конструктор присваивания
	User& operator=(const User&) = delete;
	//геттеры
	const std::string& getLogin() const;
	const std::string& getName() const;
	//метод добавления сообщения
	void addMessage(const std::string& fromUser, const std::string& text);
	//метод вывода сообщений сотрудника
	void PrintMessage();
	//метод сравнения паролей
	bool IsCorrectPassword(const std::vector<uint8_t>& password);

private:
	std::string _login; //логин
	std::vector<uint8_t> _password; //пароль
	std::string _name; //имя
	std::vector<Messages> MessageList;
};

