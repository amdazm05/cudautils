#include "memory/memorypool.hpp"

int main()
{
    MemoryPool MemPoo(1024);
    int * i  = MemPoo.allocateChunkinPool<int>(12).get();
    return 0;
}