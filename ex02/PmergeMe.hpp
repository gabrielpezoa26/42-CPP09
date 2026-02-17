/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:09:48 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/16 18:31:13 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define DEBUG true

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>
#include <set>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> _stored_vector;
		std::deque<int> _stored_deque;


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);

		void parseInput(int argc, char **argv);
		void sortVector();
};

template <typename T>
void printObject(const T& obj)
{
	if (DEBUG)
		std::cout << PURPLE << "printObject<> template called" << RESET << std::endl;

	typename T::const_iterator start = obj.begin();
	for (; start != obj.end(); ++start)
		std::cout << " " << *start;
	std::cout << std::endl;
}

template <typename T>
T mergeSort(T& input)
{
	if (DEBUG)
		std::cout << PURPLE << "mergeSort<> template called" << RESET << std::endl;

	if (input.size() <= 1)
		return input;
	
	return input; // apagar
}

/* ---------- utilities ---------- */
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string message);

#endif