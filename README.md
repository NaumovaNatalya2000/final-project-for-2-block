## Класс User:
##### Переменные:
- `std::string _login` - логин
- `std::vector<uint8_t> _password` - пароль
- `std::string _name` - имя
- `std::vector<Messages> MessageList` - вектор сообщений сотрудника
Пароль типа unsigned int 8 для хранения хеша пароля после прохождения через функцию sha1
##### Методы класса:
- конструктор с параметрами для создания нового пользователя:
  `User(const std::string& login, const std::vector<uint8_t>& password, const std::string& name);`
- деструктор - по умолчанию
- сеттеров нет - изменение данных УЗ на текущий момент не предусмотрено
- геттеры - для логина и имени
- метод добавления сообщения:
  `void addMessage(const std::string& fromUser, const std::string& text);`
  В нем две переменные передаются - от кого отправляется сообщение и текст сообщения
- метод вывода сообщений сотрудника:
  `void PrintMessage();`
- метод сравнения паролей:
  `bool IsCorrectPassword(const std::vector<uint8_t>& password);`
## Класс Messages
##### Переменные:
- `std::string _fromUser` - отправитель
- `std::string _text` - текст сообщения
##### Методы класса:
- конструктор:
  `Messages(const std::string& fromUser, const std::string& text);`
- деструктор - по умолчанию
## Функция SHA1:
Для хеширования пароля - на основе вектора.
## Функции FunctionsSystem:
В данном файле находится две функции:
- `void clearScreen()` - функция очистки экрана
- `void pause()` - функция паузы
## Класс FunctionsMenu:
В main создается контейнер map - в нем хранятся пары - логин - ключ и User (логин, пароль, имя) - значение.
Контейнер передается в функцию главного меню:
`void MainMenu(std::map<std::string, User>& users)`
##### Главное меню:
- **Подменю регистрации:**
  `void RegistrationMenu(std::map<std::string, User>& users)`
- **Подменю сообщений:**
  `void MessageMenu(std::map<std::string, User>& users)`
- Либо произвести выход из программы с помощью символа 'q'
##### Подменю Регистрации:
- `void RegistrationMenu(std::map<std::string, User>& users)`
- Сотрудник вводит логин, пароль и имя.
- Пароль уходит для хеширования в функцию SHA1.
- Выполняется проверка, существует ли уже пользователь с указанным логином - логин у двух сотрудников повторяться не может
- Если УЗ с введенным логином не найдена - создается User
##### Подменю сообщений:
- `void MessageMenu(std::map<std::string, User>& users)`
- Здесь можно вывести список всех доступных логинов и войти по логину и паролю в систему отправки сообщений. При вводе правильного пароля - переход в подменю отправки и просмотра сообщений
##### Подменю отправки и просмотра сообщений:
- `void SendingMenu(std::map<std::string, User>& users, std::map<std::string, User>::iterator it)`
Здесь можно:
- Вывести список пользователей
- Отправка сообщений одному пользователю
- Отправка сообщений всем пользователям
- Вывести список сообщений для меня
##### Функция вывода списка сотрудников:
`void PrintUsers(const std::map<std::string, User>& users)`
##### Функция проверки вводимой строки на пустоту
`std::string NotEmptyString(const std::string& prompt)`
##### Функция проверки вводимого символа перехода по меню на пустоту:
`char NotEmptyChar()`
