/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:33:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/09 09:44:59 by gcesar-n         ###   ########.fr       */
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



/* ---------- utilities ---------- */
void log(std::string message) {std::cout << message << std::endl;}

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }