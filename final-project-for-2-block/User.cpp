#include "User.h"

User::User(const std::string& login, const std::vector<uint8_t>& password, const std::string& name) : _login(login), _password(password), _name(name)
{
	
}

User::~User() = default;

const std::string& User::getLogin() const
{
	return _login;
}

const std::string& User::getName() const
{
	return _name;
}

void User::addMessage(const std::string& fromUser, const std::string& text)
{
	MessageList.push_back(Messages(fromUser, text));
}

void User::PrintMessage()
{
	if (MessageList.empty()) {
		std::cout << "Список сообщений для вас пуст" << std::endl;
		pause();
		return;
	}
	for (int i{}; i < MessageList.size(); i++) {
		std::cout << "Сообщение " << i+1 << " от " << MessageList[i].getFromUser() << ":\n" << MessageList[i].getText() << std::endl;
	}
}

bool User::IsCorrectPassword(const std::vector<uint8_t>& password)
{
	return _password == password;
}
