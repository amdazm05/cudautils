#ifndef _THREADPOOL
#define _THREADPOOL

#include "utils/util.hpp"

// What this class does:
// This is a thread pool manager , it recieves a task and  is able to execute that
// It should send results back 
// Execute arbitrary functions

class ThreadQueue
{
    private:
        std::queue<std::thread> _threadQueue;
        std::atomic_bool _isDone;
        mutable bool _isBlockingQueue;
        // Only telling this to be able to mutate 
        mutable std::shared_mutex _mtx;
    public:
        // The difference between them is that shared_lock is designed to support readers in a read/write lock. 
        // You can have multiple threads all acquire the shared lock and reading the same data, 
        // but if anyone wants to write to the data, they need to use lock to get permission to write to the data.
        using writeLock = std::unique_lock<std::shared_mutex>;
        using readLock  = std::shared_lock<std::shared_mutex>;
        ThreadQueue();
        void clear();
        void push();
        void pop();
        void emplace();
        ~ThreadQueue();

};
class ThreadPoolManager 
{
    private:
    ThreadQueue _threadQueueInstance;
    std::shared_ptr<ThreadPoolManager> _instance;
    ThreadPoolManager();

    public:

    static void init(bool isBlockingModel);
    static std::shared_ptr<ThreadPoolManager> get_instance();

};

#endif //_THREADPOOL
// For some clarity see the example you made
// https://godbolt.org/z/a6nrEjMdc
// helpful thread for my understanding
// https://stackoverflow.com/questions/63240416/whats-the-difference-between-unique-lock-and-shared-lock-in-c