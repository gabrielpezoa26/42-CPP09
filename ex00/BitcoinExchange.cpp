/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:33:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/09 12:44:20 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ---------- canonical form ---------- */
BitcoinExchange::BitcoinExchange()
{
	if (DEBUG)
		printDebug("Bitcoin-> Default constructor called");

	_readDb();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	if (DEBUG)
		printDebug("Bitcoin-> Copy constructor called");

	if (this != &other)
		*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
	if (DEBUG)
		printDebug("Bitcoin-> Default destructor called");
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (DEBUG)
		printDebug("Bitcoin-> Assignment operator called");
	
	if (this != &other)
	{
		_value = other._value;
	}
	return *this;
}

void BitcoinExchange::_readDb()
{
	if (DEBUG)
		printDebug("Bitcoin-> _readDb() called");

	std::ifstream input_file("data.csv");
	if (!input_file.is_open())
		log("vishhhh");
	
	std::string line;
	std::getline(input_file, line);
	if (line != "date,exchange_rate")
		log("vishhhh 2");
	while (std::getline(input_file, line))
	{
		std::string date;
		std::string price;
		std::istringstream ss(line);

		std::getline(ss, date, ',');
		std::getline(ss, price, ',');
		
		double price_value;
		std::istringstream price_stream(price);
		if(!(price_stream >> price_value))
			log("vishhh 3");
		_value[date] = price_value;
	}
	input_file.close();
}

void BitcoinExchange::convert(char *input_file)
{
	if (DEBUG)
		printDebug("Bitcoin-> convert() called");

	std::ifstream file(input_file);
	if (!file.is_open())
		log("vishhh 4");
	
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		log("vishhh 5");
	while(std::getline(file, line))
	{
		std::string date;
		std::string value_str;
		double price_value;

		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, value_str, '|');
		if (!date.empty())
			date = date.erase(date.length() -1);
		if (!_isDateValid(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if(!value_str.empty())
			value_str = value_str.erase(0, 1);
		price_value = _validatePrice(value_str);
		if (price_value != -1)
			_multiply(date, price_value);
	}
	file.close();
}

bool BitcoinExchange::_isDateValid(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
	return (false);

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	return (false);

	if (month == 2)
	{
		bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (is_leap && day > 29)
			return (false);
		if (!is_leap && day > 28)
			return (false);
	}
	return (true);
}

double BitcoinExchange::_validatePrice(std::string price)
{
	double price_value;
	std::istringstream price_stream(price);
	
	if (!(price_stream >> price_value))
	{
		std::cout << "Error: bad value input => " << price_value << std::endl;
		return -1;
	}
	if (price_value < 0)
	{
		std::cout << "Error: not a positive number => " << price_value << std::endl;
		return -1;
	}
	else if (price_value > 1000)
	{
		std::cout << "Error: too large number => " << price_value << std::endl;
		return -1;
	}
	return (price_value);
}

void BitcoinExchange::_multiply(std::string date, double price_value)
{
	std::map<std::string, double>::iterator it = _value.find(date);
	if (it != _value.end())
		std::cout << date << " | " << price_value << " | " << price_value * it->second << std::endl;
	else
	{
		std::map<std::string, double>::iterator it2 = _value.lower_bound(date);
		if (it2 == _value.begin())
			std::cout << date << " | " << price_value << " | " << price_value * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " | " << price_value << " | " << price_value * it2->second << std::endl;
		}
	}
}

/* ---------- utilities ---------- */
void log(std::string message) {std::cout << message << std::endl;}

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }