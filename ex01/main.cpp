/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:42:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/31 02:25:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
	}
	{
		std::srand(std::time(NULL));
		Span sp(10000);

		sp.fill();
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';

		try {
			sp.addNumber(42);
		} catch (std::exception &e) {
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
