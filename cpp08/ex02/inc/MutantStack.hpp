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
	using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
	using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

#include "../srcs/MutantStack.tpp"
