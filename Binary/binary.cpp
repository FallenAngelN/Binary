#include "binary.hpp"

BinIterator::BinIterator(Byte* p) : p(p) {}

BinIterator::BinIterator(const BinIterator& it) : p(it.p) {}

bool BinIterator::operator!=(BinIterator const& other) const
{
    return p != other.p;
}

bool BinIterator::operator==(BinIterator const& other) const
{
    return p == other.p;
}

typename BinIterator::reference BinIterator::operator*() const
{
    return *p;
}

BinIterator& BinIterator::operator++()
{
    ++p;
    return *this;
}