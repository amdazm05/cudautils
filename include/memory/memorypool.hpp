#ifndef _MEMORY
#define _MEMORY

#include "utils/util.hpp"

class MemoryPool
{
    public: 
        MemoryPool();
        MemoryPool(std::size_t bytes);
        void freeMemory();

        
        template<class T>
        T *allocateChunkinPool(std::size_t size);
        

    private: 
        std::shared_ptr<std::uint8_t> _allocationPointer;
        std::size_t _allocatedMemorySize;
        std::size_t _currentMemoryAllocatedPointerIndex;
};

template<class T>
T * MemoryPool::allocateChunkinPool(std::size_t size)
{
    T * ptr = nullptr;
    // if current memory allocation pointer + size is less than the allocated memory than break and return null
    if((_currentMemoryAllocatedPointerIndex +  size) > _allocatedMemorySize)
    {
        ptr=  nullptr;
    }

    else
    {
        std::size_t ptrIndex = _currentMemoryAllocatedPointerIndex;
        _currentMemoryAllocatedPointerIndex +=size;
        ptr = (T*)(_allocationPointer.get()+ptrIndex);
    }
    return  ptr;
}

#endif //_MEMORY
// read into these
// https://github.com/DevShiftTeam/AppShift-MemoryPool
// https://www.codeproject.com/Articles/15527/C-Memory-Pool