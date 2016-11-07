//
// Created by QiboLee on 2016/10/31 0031.
//

#ifndef LEETCODE_STRING_H
#define LEETCODE_STRING_H

#include "heads/head.h"

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);

    friend std::istream &operator>>(std::istream &, String &);

    friend String operator+(const char *, const String &);

    friend String operator+(const String &, const char *);

    friend String operator+(const String &, const String &);

private:
    std::allocator<char> _m_alloc;
    size_t _m_capacity;
    size_t _m_size;
    char *ptr;

    void resize();

public:
    explicit String(size_t = 16u);

    String(const char *);

    String(const String &);

    String(String &&);

    ~String();

    size_t size() const {
        return _m_size;
    }

    size_t capacity() const {
        return _m_capacity;
    }

    char &operator[](const size_t &i) {
        if (i < _m_size) {
            return *(ptr + i);
        }
        return *ptr;
    }

    char operator[](const size_t &i) const {
        if (i < _m_size) {
            return *(ptr + i);
        }
        return *ptr;
    }

    void push_back(const char &);

    String &operator=(const String &);

    String &operator=(String &&);

    String &operator=(const char *);

    String &operator+=(const String &);

    String &operator+=(String &&);

    String &operator+=(const char *);


};

void String::resize() {
    auto new_capacity = _m_capacity << 2u;
    char *tmp = _m_alloc.allocate(new_capacity);
    for (size_t i = 0u; i < _m_size; ++i) {
        *(tmp + i) = *(ptr + i);
    }
    _m_alloc.deallocate(ptr, _m_capacity);
    ptr = tmp;
    _m_capacity = new_capacity;
}

void String::push_back(const char &c) {
    if (_m_capacity == _m_size) {
        resize();
    }
    *(ptr + _m_size) = c;
    ++_m_size;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
    for (size_t i = 0u; i < s._m_size; ++i) {
        os << *(s.ptr + i);
    }
    return os;
}

std::istream &operator>>(std::istream &is, String &s) {
    char tmp;
    is.get(tmp);
    while (tmp != '\n') {
        s.push_back(tmp);
        is.get(tmp);
    }
    return is;
}

String operator+(const char *c, const String &s) {
    size_t len = 0u;
    auto *tmp = c;
    while (*tmp) {
        ++len;
        ++tmp;
    }
    String ret(len + s._m_size);
    for (size_t i = 0u; i < len; ++i) {
        *(ret.ptr + i) = *(c + i);
    }
    for (size_t i = 0u; i < s._m_size; ++i) {
        *(ret.ptr + len + i) = *(s.ptr + i);
    }
    return ret;
}

String operator+(const String &s, const char *c) {
    return c + s;
}

String operator+(const String &s1, const String &s2) {
    String s(s1._m_size + s2._m_size);
    for (size_t i = 0u; i < s1._m_size; ++i) {
        *(s.ptr + i) = *(s1.ptr + i);
    }
    for (size_t i = 0u; i < s2._m_size; ++i) {
        *(s.ptr + i + s1._m_size) = *(s2.ptr + i);
    }
    return s;
}

String::String(size_t capacity) : _m_capacity(16u), _m_size(0u), ptr(nullptr) {
    while (_m_capacity < capacity) {
        _m_capacity <<= 2u;
    }
    ptr = _m_alloc.allocate(_m_capacity);
    std::cout << "String(size_t capacity = 16)" << std::endl;
}

String::String(const char *c) : _m_capacity(16u), _m_size(0u), ptr(nullptr) {
    auto tmp = c;
    while (*tmp) {
        ++_m_size;
        ++tmp;
    }
    while (_m_capacity < _m_size) {
        _m_capacity <<= 2u;
    }
    ptr = _m_alloc.allocate(_m_capacity);
    tmp = ptr;
    while (*c) {
        *ptr++ = *c++;
    }
    ptr = const_cast<char *>(tmp);
    std::cout << "String(const char *c)" << std::endl;
}

String::String(const String &s) : _m_capacity(s._m_capacity), _m_size(s._m_size), ptr(nullptr) {
    ptr = _m_alloc.allocate(_m_capacity);
    for (size_t i = 0u; i < _m_size; ++i) {
        *(ptr + i) = *(s.ptr + i);
    }
    std::cout << "String(const String &s):" << std::endl;
}

String::String(String &&s) : _m_capacity(s._m_capacity), _m_size(s._m_size), ptr(s.ptr) {
    s.ptr = nullptr;
    std::cout << "String(String &&s)" << std::endl;
}

String::~String() {
    if (ptr) {
        _m_alloc.deallocate(ptr, _m_capacity);
        ptr = nullptr;
    }
    _m_capacity = 0u;
    _m_size = 0u;

    std::cout << "~String()" << std::endl;
}

String &String::operator=(const String &s) {
    if (&s == this) {
        return *this;
    }
    if (_m_capacity < s._m_size) {
        _m_alloc.deallocate(ptr, _m_capacity);
        while (_m_capacity < s._m_size) {
            _m_capacity <<= 2u;
        }
        ptr = _m_alloc.allocate(_m_capacity);
    }
    _m_size = s._m_size;
    for (size_t i = 0u; i < _m_size; ++i) {
        *(ptr + i) = *(s.ptr + i);
    }
    std::cout << "operator=(const String &s)" << std::endl;
    return *this;
}

String &String::operator=(String &&s) {
    if (&s == this) {
        return *this;
    }
    _m_alloc.deallocate(ptr, _m_capacity);
    _m_capacity = s._m_capacity;
    _m_size = s._m_size;
    ptr = s.ptr;
    s.ptr = nullptr;
    std::cout << "operator=(String &&s)" << std::endl;
    return *this;
}

String &String::operator=(const char *c) {
    size_t len = 0u;
    auto tmp = c;
    while (*tmp) {
        ++len;
        ++tmp;
    }
    if (_m_capacity < len) {
        _m_alloc.deallocate(ptr, _m_capacity);
        while (_m_capacity < len) {
            _m_capacity <<= 2u;
        }
        ptr = _m_alloc.allocate(_m_capacity);
    }
    for (size_t i = 0u; i < len; ++i) {
        *(ptr + i) = *(c + i);
    }
    _m_size = len;
    return *this;
}

String &String::operator+=(const String &s) {
    if (_m_capacity < _m_size + s._m_size) {
        size_t new_capacity = _m_capacity << 2u;
        while (new_capacity < _m_size + s._m_size) {
            new_capacity <<= 2u;
        }
        char *tmp = _m_alloc.allocate(new_capacity);
        for (size_t i = 0u; i < _m_size; ++i) {
            *(tmp + i) = *(ptr + i);
        }
        _m_alloc.deallocate(ptr, _m_capacity);
        _m_capacity = new_capacity;
        ptr = tmp;
    }
    for (size_t i = 0u; i < s._m_size; ++i) {
        *(ptr + i + _m_size) = *(s.ptr + i);
    }
    _m_size += s._m_size;
    return *this;
}

String &String::operator+=(String &&s) {
    if (_m_capacity < _m_size + s._m_size) {
        size_t new_capacity = _m_capacity << 2u;
        while (new_capacity < _m_size + s._m_size) {
            new_capacity <<= 2u;
        }
        char *tmp = _m_alloc.allocate(new_capacity);
        for (size_t i = 0u; i < _m_size; ++i) {
            *(tmp + i) = *(ptr + i);
        }
        _m_alloc.deallocate(ptr, _m_capacity);
        _m_capacity = new_capacity;
        ptr = tmp;
    }
    for (size_t i = 0u; i < s._m_size; ++i) {
        *(ptr + i + _m_size) = *(s.ptr + i);
    }
    _m_size += s._m_size;
    return *this;
}

String &String::operator+=(const char *c) {
    size_t len = 0u;
    auto tmp = c;
    while (*tmp) {
        ++len;
        ++tmp;
    }
    if (_m_capacity < _m_size + len) {
        size_t new_capacity = _m_capacity << 2u;
        while (new_capacity < _m_size + len) {
            new_capacity <<= 2u;
        }
        char *tmp = _m_alloc.allocate(new_capacity);
        for (size_t i = 0u; i < _m_size; ++i) {
            *(tmp + i) = *(ptr + i);
        }
        _m_alloc.deallocate(ptr, _m_capacity);
        _m_capacity = new_capacity;
        ptr = tmp;
    }
    for (size_t i = 0u; i < len; ++i) {
        *(ptr + i + _m_size) = *(c + i);
    }
    _m_size += len;
    return *this;
}

#endif //LEETCODE_STRING_H
