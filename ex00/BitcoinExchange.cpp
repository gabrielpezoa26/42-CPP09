/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:33:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/19 08:34:11 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ---------- canonical form ---------- */
BitcoinExchange::BitcoinExchange()
{
	if (DEBUG)
		printDebug("Default constructor called");

	_readDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	if (DEBUG)
		printDebug("Copy constructor called");

	if (this != &other)
		*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
	if (DEBUG)
		printDebug("Default destructor called");
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (DEBUG)
		printDebug("Assignment operator called");
	
	if (this != &other)
	{
		_value = other._value;
	}
	return *this;
}


void BitcoinExchange::convert(char *input_file)
{
	if (DEBUG)
		printDebug("convert() method called");
	std::ifstream file(input_file);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t delimiter = line.find('|');
		if (delimiter == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, delimiter);
		std::string value_str = line.substr(delimiter + 1);

		date = _trim(date);
		value_str = _trim(value_str);
		if (!_isDateValid(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		double price_value = _validatePrice(value_str);
		if (price_value != -1)
			_multiply(date, price_value);
	}
	file.close();
}

void BitcoinExchange::_readDataBase()
{
	if (DEBUG)
		printDebug("_readDataBase() called");

	std::ifstream input_file("data.csv");
	if (!input_file.is_open())
		throw std::runtime_error("Error: could not open file.");
	
	std::string line;
	std::getline(input_file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: file is missing header or empty");

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
			log("Error: invalid price format in database");
		_value[date] = price_value;
	}
	input_file.close();
}

bool BitcoinExchange::_isDateValid(std::string date)
{
	if (DEBUG)
		printDebug("_isDateValid() called");

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	return (true);
}

double BitcoinExchange::_validatePrice(std::string price)
{
	if (DEBUG)
		printDebug("_validatePrice() called");

	double price_value;
	std::istringstream price_stream(price);
	
	if (!(price_stream >> price_value))
	{
		std::cout << "Error: bad value input => " << price_value << std::endl;
		return -1;
	}
	if (price_value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return -1;
	}
	else if (price_value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return -1;
	}
	return (price_value);
}

void BitcoinExchange::_multiply(std::string date, double price_value)
{
	if (DEBUG)
		printDebug("_multiply() called");

	std::map<std::string, double>::iterator it = _value.find(date);
	if (it != _value.end())
		std::cout << date << " => " << price_value << " => " << price_value * it->second << std::endl;
	else
	{
		std::map<std::string, double>::iterator it2 = _value.lower_bound(date);
		if (it2 == _value.begin())
			std::cout << date << " => " << price_value << " => " << price_value * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " => " << price_value << " => " << price_value * it2->second << std::endl;
		}
	}
}

std::string BitcoinExchange::_trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (std::string::npos == first)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

/* ---------- utilities ---------- */
void log(std::string message) {std::cout << message << std::endl;}

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }