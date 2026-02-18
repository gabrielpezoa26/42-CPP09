/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:09:48 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/18 09:21:08 by gcesar-n         ###   ########.fr       */
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
#include <iomanip>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;


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

std::vector<int> jacobSthalIndices(size_t n);
int jacobSthalAlgo(int n);

template <typename T>
void insertPendElements(T& sorted, T& pending_elements)
{
	std::vector<int> insertionSequence = jacobSthalIndices(pending_elements.size());

	for (size_t i = 0; i < insertionSequence.size(); i++)
	{
		size_t index = insertionSequence[i] - 1;
		if (index >= pending_elements.size())
			continue ;
		int elem = pending_elements[index];
		typename T::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), elem);
		sorted.insert(pos, elem);
	}
}

template <typename T>
T fordJohnsonSort(T& input)
{
	if (DEBUG)
		std::cout << PURPLE << "fordJohnsonSort<> template called" << RESET << std::endl;

	if (input.size() <= 1)
		return input;
	int unpaired_element = -1;
	if (input.size() % 2 == 1)
	{
		unpaired_element = input.back();
		input.pop_back();
	}

	T main_chain;
	T pending;
	for (size_t i = 0; i < input.size(); i += 2)
	{
		int element_A = input[i];
		int element_B = input[i + 1];
		if (element_A > element_B)
			std::swap(element_A, element_B);
		pending.push_back(element_A);
		main_chain.push_back(element_B);
	}
	if (unpaired_element != -1)
		pending.push_back(unpaired_element);
	T sorted = fordJohnsonSort<T>(main_chain);
	insertPendElements(sorted, pending);
	return (sorted);
}

template <typename T>
bool isSorted(const T& container)
{
	if (container.size() < 2)
		return (true);
	typename T::const_iterator begin = container.begin();
	typename T::const_iterator end = begin;
	++end;
	while (end != container.end())
	{
		if (*begin > *end)
			return (false);
		++begin;
		++end;
	}
	return (true);
}

/* ---------- utilities ---------- */
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string message);

#endif