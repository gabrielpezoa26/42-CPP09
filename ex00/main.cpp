/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:33:17 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/07 11:30:31 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		logColor("correct usage: ./btc <file>", RED);
	}
	(void)argv;

	BitcoinExchange example;  //tests
	BitcoinExchange example2(example);
	BitcoinExchange example3;
	example3 = example2;


	//fzr o parse do arquivo
	// retorna o resultado
	// printa
	return 0;
}
