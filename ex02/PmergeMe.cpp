/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:09:45 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/16 17:06:12 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	if (DEBUG)
		printDebug("Default constructor called");
}

PmergeMe::PmergeMe(const PmergeMe& other)
 : _stored_vector(other._stored_vector), _stored_deque(other._stored_deque)
{
	if (DEBUG)
		printDebug("Copy constructor called");
}

PmergeMe::~PmergeMe()
{
	if (DEBUG)
		printDebug("Destructor called");
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (DEBUG)
		printDebug("assignment operator called");

	if (this != &other)
	{
		_stored_vector = other._stored_vector;
		_stored_deque = other._stored_deque;
	}
	return *this;
}

void PmergeMe::parseInput(int argc, char**argv)
{
	if (DEBUG)
		printDebug("parseInput() method called");

	std::set<int> set;
	for (int i = 1; i < argc; ++i)
	{
		const std::string input = argv[i];
		int value;
		std::istringstream iss(input);
		char extra;

		if (!(iss >> value) || (iss >> extra) || value < 0)
			throw std::runtime_error("Invalid input :(");
		if (!set.insert(value).second)
			throw std::runtime_error("Duplicated value present :/");
		_stored_vector.push_back(value);
		_stored_deque.push_back(value);
	}
	printDebug("deu bommm");
}

void PmergeMe::sortVector()
{
	if (DEBUG)
		printDebug("sortVector() method called");
	printObject(_stored_vector);
}

/* ---------- utilities ---------- */
void log(std::string message) { std::cout << message << std::endl; }

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }