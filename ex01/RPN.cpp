/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:12:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/13 14:12:50 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ---------- canonical form ---------- */
RPN::RPN()
{
	if (DEBUG)
		printDebug("Default constructor called");
}

RPN::RPN(const RPN& other) : _mangoLokoStack(other._mangoLokoStack)
{
	if (DEBUG)
		printDebug("Copy constructor called");
}

RPN::~RPN()
{
	if (DEBUG)
		printDebug("Default destructor called");
}

RPN& RPN::operator=(const RPN& other)
{
	if (DEBUG)
		printDebug("Assignment operator called");

	if (this != &other)
	{
		_mangoLokoStack = other._mangoLokoStack;
	}
	return *this;
}

int RPN::calculator(const std::string &input)
{
	if (DEBUG)
		printDebug("parseInput() called");

	if (input.empty())
		throw InvalidFormatException();
	std::istringstream iss(input);
	std::string token;
	
	while (iss >> token)
	{
		if (token.size() == 1 && isdigit(token[0]))
		{
			_mangoLokoStack.push(token[0] - '0');
		}
		else if (isValidOperator(token))
		{
			if (_mangoLokoStack.size() < 2)
				throw InvalidFormatException();
			int y = _mangoLokoStack.top(); 
			_mangoLokoStack.pop();

			int x = _mangoLokoStack.top(); 
			_mangoLokoStack.pop();
			exec(token, x, y);
		}
		else
		{
			throw InvalidTokenException();
		}
	}
	if (_mangoLokoStack.size() != 1)
		throw InvalidFormatException();
	return _mangoLokoStack.top();
}

bool RPN::isValidOperator(std::string op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
		return true;
	return false;
}

void RPN::exec(const std::string& op, int x, int y)
{
	if (op == "+")
		_mangoLokoStack.push(x + y);
	else if (op == "-")
		_mangoLokoStack.push(x - y);
	else if (op == "*")
		_mangoLokoStack.push(x * y);
	else if (op == "/")
	{
		if (y == 0)
			throw InvalidFormatException();
		_mangoLokoStack.push(x / y);
	}
}

const char* RPN::InvalidFormatException::what() const throw()
{
	return "vishhh 1";
}

const char* RPN::InvalidTokenException::what() const throw()
{
	return "vishhh 2";

}

/* ---------- utilities ---------- */
void log(std::string message) { std::cout << message << std::endl; }

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }