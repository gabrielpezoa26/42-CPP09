/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:33:19 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/03 12:47:58 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

#define DEBUG true

class BitcoinExchange
{
	private:

	public:
		BitcoinExchange();
		~BitcoinExchange();
};

/* ---------- utilities ---------- */
void log(std::string message);
void printDebug(std::string message);

#endif