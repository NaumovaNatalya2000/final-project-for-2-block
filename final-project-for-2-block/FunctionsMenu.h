#pragma once
#include<iostream>
#include<string>
#include<map>
#include "User.h"
#include "FunctionsSystem.h"
#include "sha1.h"

//функция основное меню - передаем контейнер ссылкой
void MainMenu(std::map<std::string, User>& users);

//функция подменю регистрации - передаем контейнер ссылкой
void RegistrationMenu(std::map<std::string, User>& users);

//функция подменю сообщений - передаем контейнер ссылкой
void MessageMenu(std::map<std::string, User>& users);

//функция подменю отправки и просмотра сообщений - передаем контейнер ссылкой
void SendingMenu(std::map<std::string, User>& users, std::map<std::string, User>::iterator it);

//функция - вывод всех пользователей
void PrintUsers(const std::map<std::string, User>& users);

//функция ввода строки с проверкой на пустоту
std::string NotEmptyString(const std::string& prompt);

//функция проверки потока ввода на пустоту - управление меню
char NotEmptyChar();