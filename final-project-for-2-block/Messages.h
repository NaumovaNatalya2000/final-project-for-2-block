#pragma once
#include<iostream>
#include<string>
class Messages
{
private:
	//отправитель
	std::string _fromUser;
	//текст сообщения
	std::string _text;
public:
	//конструктор
	Messages(const std::string& fromUser, const std::string& text);
	//деструктор
	~Messages();

	std::string getFromUser() const;
	std::string getText() const;
};