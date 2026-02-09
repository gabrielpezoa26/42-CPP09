/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:33:19 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/09 12:30:42 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <map>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

#define DEBUG true

class BitcoinExchange
{
	private:
		std::map<std::string, double> _value;
		void _readDb();
		bool _isDateValid(std::string date);
		double _validatePrice(std::string price);
		std::string _trim(const std::string& str);
		void _multiply(std::string date, double price_value);


	public:
		/* ---------- canonical form ---------- */
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void convert(char *file);

};

/* ---------- utilities ---------- */
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string message);

#endif