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
        reverse_iterator& operator+= (int value) { current -= value; return *this;}

        reverse_iterator& operator-- () { ++current; return *this; }
        reverse_iterator operator-- (int) { auto temp = *this; --(*this); return temp; }
        reverse_iterator& operator-= (int value) { current += value; return *this;}

        decltype(auto) operator* () { return *current; }

        It base() const { return current; }
        
        friend bool operator== (const reverse_iterator<It>& left, const reverse_iterator<It>& right) { return left.base() == right.base(); }
        friend bool operator!= (const reverse_iterator<It>& left, const reverse_iterator<It>& right) { return left.base() != right.base(); }
        friend bool operator< (const reverse_iterator<It>& left, const reverse_iterator<It>& right) { return left.base() > right.base(); }
        friend bool operator<= (const reverse_iterator<It>& left, const reverse_iterator<It>& right) { return left.base() >= right.base(); }
        friend bool operator> (const reverse_iterator<It>& left, const reverse_iterator<It>& right) { return left.base() < right.base(); }
        friend bool operator>= (const reverse_iterator<It>& left, const reverse_iterator<It>& right) { return left.base() <= right.base(); }

    private:
        It current = It();
    };

}

#endif