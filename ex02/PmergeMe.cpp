/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:09:45 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/19 09:59:17 by gcesar-n         ###   ########.fr       */
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
		printDebug("parseInput() method called");

	std::set<int> set;
	for (int i = 1; i < argc; ++i)
	{
		const std::string input = argv[i];
		int value;
		std::istringstream iss(input);
		char extra;

		if (!(iss >> value) || (iss >> extra) || value < 0)
			throw std::runtime_error("Error");
		if (!set.insert(value).second)
			throw std::runtime_error("Duplicated value present :/");
		_vector.push_back(value);
		_deque.push_back(value);
	}
}

void PmergeMe::sortVector()
{
	if (DEBUG)
		printDebug("sortVector() method called");
	std::cout << "Before:\t";
	printObject(_vector);

	std::clock_t start_time = clock();
	std::vector<int> sorted_vector = fordJohnsonSort<std::vector<int> >(this->_vector);
	std::clock_t finish_time = clock();

	if (!isSorted<std::vector<int> >(sorted_vector))
			throw (std::runtime_error("error during sort vector"));
	std::cout << "After\t";
	printObject(sorted_vector);
	double	elapsed_time_us = static_cast<double>(finish_time - start_time) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : "
			  << std::setprecision(5) << elapsed_time_us << " us" << std::endl;
}

void	PmergeMe::sortDeque(void)
{
	if (DEBUG)
		printDebug("sortDeque() method called");
	std::clock_t	start_time = clock();
	std::deque<int>	sorted_deque = fordJohnsonSort<std::deque<int> >(_deque);
	std::clock_t	finish = clock();

	if (!isSorted<std::deque<int> >(sorted_deque))
		throw (std::runtime_error("error during sort deque"));

	double	elapsed_time_us = static_cast<double>(finish - start_time) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : "
			  << std::setprecision(5) << elapsed_time_us << " us" << std::endl;
}

std::vector<int> jacobSthalIndices(size_t n)
{
	if (DEBUG)
		printDebug("jacobSthalIndices() function called");

	std::vector<int> insertion_sequence;
	std::set<int> processed_indices;

	for (int j = 2; insertion_sequence.size() < n; ++j)
	{
		int num = jacobSthalAlgo(j);
		if (num > static_cast<int>(n))
			num = static_cast<int>(n);
		while (num > 0 && !processed_indices.count(num))
		{
			insertion_sequence.push_back(num);
			processed_indices.insert(num);
			--num;
		}
	}
	return (insertion_sequence);
}

int jacobSthalAlgo(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobSthalAlgo(n - 1) + 2 * jacobSthalAlgo(n - 2));
}



/* ---------- utilities ---------- */
void log(std::string message) { std::cout << message << std::endl; }

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }