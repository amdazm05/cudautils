#include "memory/memorypool.hpp"
#include <new>
struct FooStruct
{
    int a = 0;
    char d = 1;
    short x = 12;
};

int main()
{
    MemoryPool MemPoo(1024);
    int * i  = MemPoo.allocateChunkinPool<int>(sizeof(int));
    char * j  = MemPoo.allocateChunkinPool<char>(sizeof(char));
    long long * k  = MemPoo.allocateChunkinPool<long long>(sizeof(long long));
    // Placement new , and adding a constructor
    *i = 102;
    *k = 0xDEADBEEF;
    *j  = 'X';
    // placement new  technique can be used here
    FooStruct * something = new (MemPoo.allocateChunkinPool<FooStruct>(sizeof(FooStruct))) FooStruct();
    long long * bb  = MemPoo.allocateChunkinPool<long long>(sizeof(long long));
    
    return 0;
}