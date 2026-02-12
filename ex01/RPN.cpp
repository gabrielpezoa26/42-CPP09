/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:12:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2026/02/10 15:13:59 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ---------- utilities ---------- */
void log(std::string message) {std::cout << message << std::endl;}

void logColor(std::string message, std::string color) { std::cout << color << message << RESET << std::endl; }

void printDebug(std::string message) { std::cout << PURPLE << message << RESET << std::endl; }