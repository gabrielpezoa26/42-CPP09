/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:09:45 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/15 16:04:06 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	if (DEBUG)
		printDebug("Default constructor called");
}

PmergeMe::PmergeMe(const PmergeMe& other)
 : _vector(other._vector), _deque(other._deque)
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
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

void PmergeMe::parseInput(int argc, char**argv)
{
	if (DEBUG)
		printDebug("parseInput() called");

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
			throw std::runtime_error("Duplicated value present");
		_vector.push_back(value);
		_deque.push_back(value);
	}
	printDebug("deu bommm");
}


/* ---------- utilities ---------- */
void log(std::string message) { std::cout << message << std::endl; }

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }