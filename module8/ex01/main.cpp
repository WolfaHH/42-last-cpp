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

#include "Span.hpp"

int main()
{
	try
	{
		Span s(5);
		s.addNumber(2);
		s.addNumber(4);
		s.addNumber(6);
		s.addNumber(8);
		s.addNumber(10);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span s(5);
		s.addNumber(2);
		s.addNumber(4);
		s.addNumber(6);
		s.addNumber(8);
		s.addNumber(10);
		s.addNumber(12);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span s(5);
		s.addNumber(2);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	try
	{
		Span s(1);
		s.addNumber(2);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::vector<int> big(10000);

	for (int i = 0; i < 10000; ++i)
		big[i] = i;

	try
	{
		Span s(10000);
		s.addRange(big.begin(), big.end());
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	}

	catch (std::exception &e)
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}