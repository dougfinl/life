#include "bitarray.h"

#include <stdexcept>


constexpr auto WORD_SIZE_BYTES = sizeof(std::uint_fast8_t);
constexpr auto WORD_SIZE_BITS = WORD_SIZE_BYTES * 8;

BitArray::BitArray(std::size_t size)
    : _size(size)
{
    const auto wordCount = _size / WORD_SIZE_BITS + (_size % WORD_SIZE_BITS != 0);
    _data = std::vector<std::uint_fast8_t>(wordCount, 0);
}

void BitArray::set(std::size_t bit)
{
    if (bit >= _size)
        throw std::out_of_range("bit index out of range");

    auto wordMask = wordMaskForBit(bit);
    auto dataIndex = dataIndexForBit(bit);

    // Bitwise 'OR' the mask to set a bit
    _data.at(dataIndex) |= wordMask;
}

void BitArray::unset(std::size_t bit)
{
    if (bit >= _size)
        throw std::out_of_range("bit index out of range");

    auto wordMask = wordMaskForBit(bit);
    auto dataIndex = dataIndexForBit(bit);

    // Bitwise 'AND' the inverse of the mask to clear a bit
    _data.at(dataIndex) &= ~wordMask;
}

bool BitArray::at(std::size_t bit) const
{
    if (bit >= _size)
        throw std::out_of_range("bit index out of range");

    auto wordMask = wordMaskForBit(bit);
    auto dataIndex = dataIndexForBit(bit);
    const auto data = _data.at(dataIndex);

    // If a bit is set, return true, otherwise false
    return (data & wordMask) > 0;
}

void BitArray::clear()
{
    std::fill(_data.begin(), _data.end(), 0);
}

std::size_t BitArray::dataIndexForBit(std::size_t bit)
{
    return bit / WORD_SIZE_BITS;
}

std::uint_fast8_t BitArray::wordIndexForBit(std::size_t bit)
{
    return bit % WORD_SIZE_BITS;
}

std::uint_fast8_t BitArray::wordMaskForBit(std::size_t bit)
{
    return 1 << wordIndexForBit(bit);
}
