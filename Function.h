#pragma once

const int INF = 0x7fffffff;

template <typename ElementType>
ElementType max(ElementType x, ElementType y)
{
	return (x > y) ? x : y;
}

template <typename ElementType>
ElementType min(ElementType x, ElementType y)
{
	return (x < y) ? x : y;
}