#pragma once
#include <stdexcept>

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

template <typename T>
class Array {

    private:
    T *_content;
    size_t _len;

    public:
    Array() {
        _content = nullptr;
        _len = 0;
    }

    Array(unsigned int n) {
        _len = n;
        if (n != 0) {
            _content = new T[_len]();
        }
        else {
            _content = nullptr;
        }
    }

    Array(const Array &other) {
        _len = other._len;
        if (_len != 0) {
            _content = new T[_len]();
            for (size_t i = 0; i < _len; i++)
                _content[i] = other._content[i];
        }
        else {
            _content = nullptr;
        }
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            _len = other._len;
            delete[] _content;
            if (_len != 0) {
                _content = new T[_len]();
                for (size_t i = 0; i < _len; i++)
                    _content[i] = other._content[i];
            }
            else {
                _content = nullptr;
            }
        }
        return (*this);
    }

    ~Array() {
        delete[] _content;
    }

    T& operator[] (size_t index) {
        if (index >= _len) {
            throw std::out_of_range("Invalid index.");
        }
        return (_content[index]);
    }

    const T &operator[] (size_t index) const {
        if (index >= _len) {
            throw std::out_of_range("Invalid index.");
        }
        return (_content[index]);
    }

    size_t size() const {
        return (_len);
    }
};
