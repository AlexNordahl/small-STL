#ifndef SMALL_STL_ITERATOR
#define SMALL_STL_ITERATOR

namespace sSTL
{
    template<typename It> 
    class reverse_iterator
    {
    public:
        reverse_iterator() = default;

        reverse_iterator(It itr)
            : current {itr}
        {}

        reverse_iterator& operator++ () { --current; return *this; }
        reverse_iterator operator++ (int) { auto temp = *this; ++(*this); return temp; }

        reverse_iterator& operator-- () { ++current; return *this; }
        reverse_iterator& operator-- (int) { auto temp = *this; --(*this); return temp; }

        auto operator* () { return *current; }

    private:
        It current = It();
    };
}

#endif