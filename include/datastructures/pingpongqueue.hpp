#ifndef _PINGPONGBUFFER
#define _PINGPONGBUFFER

#include "utils/util.hpp"

template<class T,std::size_t sizeOfQueue =0>
class PingPongQueue
{
    public:
        enum
        {
            PING = 0,
            PONG = 1
        };
        PingPongQueue();
        ~PingPongQueue();
        void begin_read(uint8_t* pBuffer,std::size_t size);
        void begin_write(uint8_t* pBuffer,std::size_t size);
        void end_write();
        void reset();
    private:
        std::atomic<bool>   _pingDataReady;
        std::atomic<bool>   _pongDataReady;
        std::atomic<int>    _writeIndex; 
        template <std::size_t sizeofArray = sizeOfQueue>
        typename std::enable_if<sizeofArray != 0>::type 
            std::array<uint32_t,sizeofArray> buffer;
        template <std::size_t sizeofArray = sizeOfQueue>
        typename std::enable_if<sizeofArray == 0>::type 
            std::vector<std::vector<uint32_t>> buffer;
        template <std::size_t sizeofArray = sizeOfQueue>
        typename std::enable_if<sizeofArray == 0>::type 
            void set_buffer_size(std::size_t size`);
};

#endif //_PINGPONGBUFFER