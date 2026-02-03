/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:33:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/03 12:47:24 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	if (DEBUG)
		printDebug("Bitcoin-> Default constructor called");
}

BitcoinExchange::~BitcoinExchange()
{
	if (DEBUG)
		printDebug("Bitcoin-> Default destructor called");
}



/* ---------- utilities ---------- */
void log(std::string message) {std::cout << message << std::endl;}

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }