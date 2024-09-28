#pragma once

#include "exception.hpp"
#include <iterator>
#include <vector>

typedef unsigned char Byte;

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef unsigned long long U64;

typedef char I8;
typedef short I16;
typedef int I32;
typedef long long I64;

class BinIterator : public std::iterator<std::input_iterator_tag, Byte> {
    friend class Binary;
private:
    BinIterator(Byte* p);
public:
    BinIterator(const BinIterator& it);

    bool operator!=(BinIterator const& other) const;
    bool operator==(BinIterator const& other) const; //need for BOOST_FOREACH
    typename BinIterator::reference operator*() const;
    BinIterator& operator++();
private:
    Byte* p;
};

class Binary {
    typedef BinIterator iterator;
    typedef const BinIterator const_iterator;

public:
    Binary();
    Binary(const std::string& data, const bool is_hex = false);
    Binary(const Byte* data, const bool is_hex = false);
    Binary(const Byte* first, const Byte* last);
    Binary(const size_t size, const Byte filler);
    Binary(const std::initializer_list<Byte>& list);

    iterator begin() noexcept;
    iterator end() noexcept;

    const_iterator cbegin() noexcept;
    const_iterator cend() noexcept;

    ~Binary();
private:
    Byte* m_data;
    size_t m_size;
    size_t m_capacity;
};