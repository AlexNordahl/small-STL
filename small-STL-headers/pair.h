#ifndef SMALL_STL_PAIR
#define SMALL_STL_PAIR

namespace sSTL
{
    template<typename T1, typename T2>
    struct pair
    {
        T1 first {};
        T2 second {};

        pair& operator= (const pair<T1, T2>& other)
        {
            first = other.first;
            second = other.second;
        }

        void swap(pair<T1, T2>& other)
        {
            auto temp1 = first;
            first = other.first;
            other.first = temp1;

            auto temp2 = second;
            second = other.second;
            other.second = temp2;
        }
    };

    template<typename T1, typename T2>
    pair<T1, T2> make_pair(T1 first, T2 second)
    {
        return {first, second};
    }
}

#endif