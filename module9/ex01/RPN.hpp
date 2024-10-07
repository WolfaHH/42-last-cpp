/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:00:00 by ngodard           #+#    #+#             */
/*   Updated: 2024/07/01 10:00:00 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

enum Operation
{
	ADD = '+',
	SUB = '-',
	DIV = '/',
	MUL = '*'
};

class RPN : public std::stack<int>
{
	typedef std::stack<int> Container;

public:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();
	void calculate(Operation operation);
	void add(char entry);
	/* Operaions */
	int add(int v1, int v2);
	int substract(int v1, int v2);
	int multiply(int v1, int v2);
	int divide(int v1, int v2);
};

#endif
