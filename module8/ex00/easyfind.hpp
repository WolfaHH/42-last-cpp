/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:00:00 by ngodard           #+#    #+#             */
/*   Updated: 2024/07/01 10:00:00 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

typename T::iterator easyfind(T &container, int needle)
{
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	return it;
}

#endif