/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngodard <ngodard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:01:56 by ngodard           #+#    #+#             */
/*   Updated: 2024/07/13 12:34:56 by ngodard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>

Array<T>::Array()
{
    m_size = 0;
    m_array = new T[0];
}

template <typename T>

Array<T>::Array(unsigned int size)
{
    m_size = size;
    m_array = new T[size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_array[i] = 0;
    }
}

template <typename T>

Array<T>::Array(const Array &other)
{
    m_array = new T[other.size()];
    m_size = other.size();
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_array[i] = other[i];
    }
}

template <typename T>

Array<T>::~Array()
{
    delete[] m_array;
}

template <typename T>

Array<T> &Array<T>::operator=(const Array &other)
{
    delete[] m_array;
    m_array = new T[other.size()];
    m_size = other.size();
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_array[i] = other[i];
    }
    return *this;
}

template <typename T>

const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_array[index];
}

template <typename T>

T &Array<T>::operator[](unsigned int index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_array[index];
}

template <typename T>

unsigned int Array<T>::size() const
{
    return m_size;
}
