#include "memory/memorypool.hpp"
MemoryPool::MemoryPool()
{
    _currentMemoryAllocatedPointerIndex = 0;
    _allocatedMemorySize = 1<<16;
    _allocationPointer =   std::shared_ptr<std::uint8_t>(new std::uint8_t[_allocatedMemorySize]);
}
MemoryPool::MemoryPool(std::size_t bytes)
{
    _currentMemoryAllocatedPointerIndex = 0;
    _allocatedMemorySize = bytes;
    _allocationPointer =   std::shared_ptr<std::uint8_t>(new std::uint8_t[_allocatedMemorySize]);
}

