/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:12:06 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/10 15:18:28 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

#define DEBUG false

#include <iostream>

class RPN
{

};


/* ---------- utilities ---------- */
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string message);

#endif