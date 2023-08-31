/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:33:13 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/01 02:24:50 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <list>
#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Stack: " << mstack << '\n';

	std::cout << "Stack top: " << mstack.top() << '\n' << '\n';

	mstack.pop();
	std::cout << "After pop" << '\n';
	std::cout << "Stack: " << mstack << '\n';

	std::cout << "Stack Size: " << mstack.size() << '\n';

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Stack: " << mstack << '\n';

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << '\n';
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

