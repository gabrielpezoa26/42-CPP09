/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:12:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/13 11:27:43 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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



/* ---------- utilities ---------- */
void log(std::string message) {std::cout << message << std::endl;}

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }