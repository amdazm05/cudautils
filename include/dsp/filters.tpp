#ifndef _FILTERS
#define _FILTERS
#include "utils/util.hpp"

//Temporary remove after a while once in actual pipeline
constexpr size_t samples =100;
constexpr size_t filter_size = 3;
constexpr size_t slides_per_window = samples - filter_size;

template<typename T>
concept _floatingType = requires (T a)
{
    std::is_floating_point<T>::value;
};

template<size_t N>
concept _isOdd = (N%2)!=0;

template<typename T, size_t size = 100, size_t sizeofFilter  = filter_size >
requires _floatingType<T> && _isOdd<sizeofFilter>
class Filters
{
    public:
        Filters()
        {

        }
        ~Filters()
        {

        }
        void MedianFilter(std::array<T,size-sizeofFilter> &dataOut,std::array<T,size> &dataIn)
        { 
            typename std::array<T,size>::iterator it = dataIn.begin();
            typename std::array<T,size>::iterator itend = dataIn.end();
            std::size_t ind=0;
            for(;it<=(itend-sizeofFilter);it++)
            {
                std::ranges::copy(it,it+sizeofFilter,_windowToSort.begin());
                std::ranges::sort(_windowToSort.begin(),_windowToSort.end());
                dataOut[ind++]=(_windowToSort[sizeofFilter/2]);
            }
        }

    private:
        std::array<T,sizeofFilter> _windowToSort;
};

#endif //_FILTERS