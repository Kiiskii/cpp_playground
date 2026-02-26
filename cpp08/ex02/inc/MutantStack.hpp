#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() = default;
	MutantStack(const MutantStack& other) = default;
	MutantStack& operator=(const MutantStack& other) = default;
	~MutantStack() = default;

	using iterator = typename std::stack<T>::container_type::iterator;
	using const_iterator = typename std::stack<T>::container_type::const_iterator;
	using rev_iterator = typename std::stack<T>::container_type::reverse_iterator;
	using const_rev_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	rev_iterator rbegin();
	rev_iterator rend();
	const_rev_iterator rbegin() const;
	const_rev_iterator rend() const;
};

#include "../srcs/MutantStack.tpp"
