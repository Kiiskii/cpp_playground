template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::rev_iterator MutantStack<T>::rbegin() {
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::rev_iterator MutantStack<T>::rend() {
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_rev_iterator MutantStack<T>::rbegin() const {
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_rev_iterator MutantStack<T>::rend() const {
	return (this->c.rend());
}
