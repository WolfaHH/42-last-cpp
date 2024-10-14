/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:00:00 by ngodard           #+#    #+#             */
/*   Updated: 2024/07/01 10:00:00 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <exception>

int add(int v1, int v2)
{
	return v1 + v2;
}

int substract(int v1, int v2)
{
	return v1 - v2;
}

int multiply(int v1, int v2)
{
	return v1 * v2;
}

int divide(int v1, int v2)
{
	return v1 / v2;
}

int main(int argc, char *argv[])
{
	if (argc != 2 || std::string(argv[1]).empty())
	{
		std::cerr << "Error: Program requires exactly one non-empty argument" << std::endl;
		return 1;
	}

	RPN rpn;
	std::string input(argv[1]);
	std::istringstream iss(input);
	std::string token;

	try
	{
		while (iss >> token)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				rpn.calculate(static_cast<Operation>(token[0]));
			}
			else
			{
				int value;
				std::istringstream tokenStream(token);
				if (!(tokenStream >> value) || !tokenStream.eof() || value < 0 || value > 9)
				{
					throw std::invalid_argument("Error: Invalid number");
				}
				rpn.push(value);
			}
		}

		if (rpn.size() != 1)
		{
			throw std::logic_error("Error: Invalid expression");
		}

		std::cout << rpn.top() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
