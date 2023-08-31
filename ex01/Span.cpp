/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:42:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/08/31 02:21:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span(void)
{
}

Span::Span(void)
	:mCapacity(0)
{
	mData.reserve(mCapacity);
}

Span::Span(const unsigned int n)
	:mCapacity(n)
{
	mData.reserve(mCapacity);
}

Span::Span(const Span& span)
	:mCapacity(span.mCapacity)
{
	mData.reserve(mCapacity);
	std::copy(span.mData.begin(), span.mData.end(), std::back_inserter(mData));
}

Span& Span::operator=(const Span& span)
{
	mCapacity = span.mCapacity;
	mData.clear();
	mData.reserve(mCapacity);
	std::copy(span.mData.begin(), span.mData.end(), std::back_inserter(mData));
	return *this;
}

void Span::addNumber(const int num)
{
	if (mData.size() >= mCapacity)
		throw std::runtime_error("span is full");
	mData.push_back(num);
}

void Span::fill(void)
{		
	std::generate_n(std::back_inserter(mData), mCapacity - mData.size(), std::rand);
}

static int _abs(const int val)
{
	return val > 0 ? val : -val;
}

int	Span::shortestSpan(void) const
{
	if (mData.size() <= 1)
		throw std::runtime_error("no span can be found");
	std::vector<int> spans;
	std::adjacent_difference(mData.begin(), mData.end(), std::back_inserter(spans));
	std::transform(spans.begin(), spans.end(), spans.begin(), _abs);
	return *std::min_element(spans.begin() + 1, spans.end());
}

int	Span::longestSpan(void) const
{
	if (mData.size() <= 1)
		throw std::runtime_error("no span can be found");
	std::vector<int> spans;
	std::adjacent_difference(mData.begin(), mData.end(), std::back_inserter(spans));
	std::transform(spans.begin(), spans.end(), spans.begin(), _abs);
	return *std::max_element(spans.begin() + 1, spans.end());
}
