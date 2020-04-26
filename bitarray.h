#ifndef BITARRAY_H
#define BITARRAY_H

#include <cinttypes>
#include <vector>


class BitArray
{
public:
    explicit BitArray(std::size_t size);

    void set(std::size_t bit);
    void unset(std::size_t bit);

    bool at(std::size_t bit) const;
    void clear();

private:
    static inline std::size_t dataIndexForBit(std::size_t bit);
    static inline std::uint_fast8_t wordIndexForBit(std::size_t bit);
    static inline std::uint_fast8_t wordMaskForBit(std::size_t bit);

    std::size_t _size;
    std::vector<std::uint_fast8_t> _data;
};

#endif // BITARRAY_H
