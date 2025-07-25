#include "Messages.h"

Messages::Messages(const std::string& fromUser, const std::string& text) : _fromUser(fromUser), _text(text)
{
}

Messages::~Messages() = default;

std::string Messages::getFromUser() const
{
	return _fromUser;
}

std::string Messages::getText() const
{
	return _text;
}