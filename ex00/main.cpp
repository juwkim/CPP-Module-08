/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:49:08 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/31 01:35:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

const int size = 10;
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	std::vector<int> v;
	std::deque<int> d;

	v.reserve(size);
	for (int i = 0; i < size; ++i) {
		v.push_back(i);
		d.push_back(i);
	}

	const int val = std::atoi(argv[1]);

	{
		std::vector<int>::iterator it = easyfind(v, val);
		std::cout << "vector: ";
		if (it == v.end())
			std::cout << " not found" << '\n';
		else
			std::cout << " found at " << it - v.begin() << "th index" << '\n';
	}
	{
		std::deque<int>::iterator it = easyfind(d, val);
		std::cout << "list: ";
		if (it == d.end())
			std::cout << " not found" << '\n';
		else
			std::cout << " found at " << it - d.begin() << "th index" << '\n';
	}
	return 0;
}
