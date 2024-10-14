/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:00:00 by ngodard           #+#    #+#             */
/*   Updated: 2024/07/01 10:00:00 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : std::stack<int>()
{
}

RPN::RPN(const RPN &src) : std::stack<int>(src)
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		std::stack<int>::operator=(src);
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculate(Operation oper)
{
	if (this->size() < 2)
	{
		throw std::logic_error("Error: Not enough operands");
	}
	int v2 = this->top();
	this->pop();
	int v1 = this->top();
	this->pop();

	int result;
	switch (oper)
	{
	case ADD:
		result = this->add(v1, v2);
		break;
	case SUB:
		result = this->substract(v1, v2);
		break;
	case MUL:
		result = this->multiply(v1, v2);
		break;
	case DIV:
		result = this->divide(v1, v2);
		break;
	default:
		throw std::invalid_argument("Error: Invalid operator");
	}
	this->push(result);
}

void RPN::add(char entry)
{
	if (entry > '9' || entry < '0')
	{
		throw std::invalid_argument("Error");
	}
	std::stringstream ss;
	ss << entry;
	int value;
	ss >> value;
	this->push(value);
}

int RPN::add(int v1, int v2)
{
	if ((v2 > 0 && v1 > INT_MAX - v2) || (v2 < 0 && v1 < INT_MIN - v2))
	{
		throw std::runtime_error("Error: Integer overflow");
	}
	return v1 + v2;
}

int RPN::substract(int v1, int v2)
{
	if ((v2 < 0 && v1 > INT_MAX + v2) || (v2 > 0 && v1 < INT_MIN + v2))
	{
		throw std::runtime_error("Error: Integer overflow");
	}
	return v1 - v2;
}

int RPN::multiply(int v1, int v2)
{
	if (v1 > 0 && v2 > 0 && v1 > INT_MAX / v2)
		throw std::runtime_error("Error: Integer overflow");
	if (v1 > 0 && v2 < 0 && v2 < INT_MIN / v1)
		throw std::runtime_error("Error: Integer overflow");
	if (v1 < 0 && v2 > 0 && v1 < INT_MIN / v2)
		throw std::runtime_error("Error: Integer overflow");
	if (v1 < 0 && v2 < 0 && v1 < INT_MAX / v2)
		throw std::runtime_error("Error: Integer overflow");
	return v1 * v2;
}

int RPN::divide(int v1, int v2)
{
	if (v2 == 0)
	{
		throw std::runtime_error("Error: Division by zero");
	}
	if (v1 == INT_MIN && v2 == -1)
	{
		throw std::runtime_error("Error: Integer overflow");
	}
	return v1 / v2;
}
