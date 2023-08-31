/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 03:32:07 by juwkim            #+#    #+#             */
/*   Updated: 2023/09/01 02:22:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		virtual ~MutantStack(void) {};
		MutantStack(void): std::stack<T, Container>() {};
		MutantStack(const MutantStack &q): std::stack<T, Container>(q.c) {};
		MutantStack& operator=(const MutantStack &q) {this->c = q.c; return *this;};

		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		iterator begin(void) {return this->c.begin();};
		const_iterator begin(void) const {return this->c.begin();};
		reverse_iterator rbegin(void) {return this->c.rbegin();};
		const_reverse_iterator rbegin(void) const {return this->c.rbegin();};

		iterator end(void) {return this->c.end();};
		const_iterator end(void) const {return this->c.end();};
		reverse_iterator rend(void) {return this->c.rend();};
		const_reverse_iterator rend(void) const {return this->c.rend();};
};

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& out, MutantStack<T, Container>& q)
{
	typename MutantStack<T, Container>::const_iterator it = q.begin();
	typename MutantStack<T, Container>::const_iterator end = q.end();

	for (; it != end; ++it)
		out << *it << ' ';
	return out;
};