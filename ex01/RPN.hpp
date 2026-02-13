/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:12:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/13 15:26:51 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

#define DEBUG true

#include <iostream>
#include <stack>
#include <sstream>
#include <string.h>
#include <exception>

class RPN
{
	private:
		std::stack<int> _rpnStack;
		bool isValidOperator(std::string op);
		void exec(const std::string& op, int x, int y);


	public:
		RPN();
		RPN(const RPN& other);
		~RPN();

		RPN& operator=(const RPN& other);

		int calculator(const std::string &input);

		/* ---------- exceptions ---------- */
		class InvalidFormatException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidTokenException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};


/* ---------- utilities ---------- */
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string message);

#endif