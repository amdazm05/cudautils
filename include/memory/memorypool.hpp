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
        std::shared_ptr<T> allocateChunkinPool(std::size_t size);
        

    private: 
        std::shared_ptr<std::uint8_t> _allocationPointer;
        std::size_t _allocatedMemorySize;
        std::size_t _currentMemoryAllocatedPointerIndex;
};

template<class T>
std::shared_ptr<T> MemoryPool::allocateChunkinPool(std::size_t size)
{
    // if current memory allocation pointer + size is less than the allocated memory than break and return null
    if((_currentMemoryAllocatedPointerIndex +  size) < _allocatedMemorySize)
    {
        return nullptr;
    }

    else
    {
        _currentMemoryAllocatedPointerIndex +=size;
        return  std::shared_ptr<T>((T*)_allocationPointer.get());
    }
}

#endif //_MEMORY
// read into these
// https://github.com/DevShiftTeam/AppShift-MemoryPool
// https://www.codeproject.com/Articles/15527/C-Memory-Pool