/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:55:30 by ngodard           #+#    #+#             */
/*   Updated: 2024/07/13 12:34:56 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>

void iter(T *array, size_t size, void (*f)(T const &))
{
    for (size_t i = 0; i < size; i++)
    {
        f(array[i]);
    }
}
