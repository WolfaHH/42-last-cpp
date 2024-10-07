/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:01:56 by ngodard           #+#    #+#             */
/*   Updated: 2024/07/13 12:34:56 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.tpp"

template <typename T>

class Array
{
public:
    Array();
    Array(unsigned int size);
    Array(const Array &other);
    ~Array();
    Array &operator=(const Array &other);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;

private:
    T *m_array;
    unsigned int m_size;
};
