/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:40:41 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/31 02:23:23 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ctime>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

class	Span
{
	public:
		virtual ~Span(void);
		Span(const unsigned int n);
		Span(const Span &span);
		Span& operator=(const Span& span);

		void addNumber(const int num);
		void fill(void);
		int  shortestSpan(void) const;
		int  longestSpan(void) const;
	private:
		Span(void);
		unsigned int mCapacity;
		std::vector<int> mData;
};
