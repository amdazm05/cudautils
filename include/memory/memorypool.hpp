#ifndef _MEMORY
#define _MEMORY

#include "utils/util.hpp"

class Memory
{
    public: 
        Memory();
        void freeMemory();
        void allocateMemory(std::size_t bytes);
};

#endif //_MEMORY
// read into these
// https://github.com/DevShiftTeam/AppShift-MemoryPool
// https://www.codeproject.com/Articles/15527/C-Memory-Pool