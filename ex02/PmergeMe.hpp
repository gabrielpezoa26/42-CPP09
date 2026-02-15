/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:09:48 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/15 10:18:29 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGE_HPP

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

#include <iostream>
#include <vector>
#include <deque>

#define DEBUG false

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

	
};
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string message);


#endif