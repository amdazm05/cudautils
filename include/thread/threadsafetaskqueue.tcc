#ifndef _THREADSAFEQUEUE
#define _THREADSAFEQUEUE

template<class T>
class ThreadSafeTaskQueue
{
    private:
        std::queue<T> _taskQueue;
        // Only telling this to be able to mutate 
        mutable std::shared_mutex _mtx;
    public:
        // The difference between them is that shared_lock is designed to support readers in a read/write lock. 
        // You can have multiple threads all acquire the shared lock and reading the same data, 
        // but if anyone wants to write to the data, they need to use lock to get permission to write to the data.
        using uniqueLock = std::unique_lock<std::shared_mutex>;
        using sharedLock  = std::shared_lock<std::shared_mutex>;
        ThreadSafeTaskQueue();
        void clear();
        bool empty();
        T & front();
        void push(T &&function);
        void pop();
        void emplace(T&&function);
        ~ThreadSafeTaskQueue();
};

template<typename T>
void ThreadSafeTaskQueue<T>::push(T &&function)
{
    uniqueLock(_mtx);
    this->_taskQueue.push(function);
}

template<typename T>
bool ThreadSafeTaskQueue<T>::empty()
{
    uniqueLock(_mtx);
    return _taskQueue.empty();
}

template<typename T>
T & ThreadSafeTaskQueue<T>::front()
{
    uniqueLock(_mtx);
    return _taskQueue.front();
}

template<typename T>
void ThreadSafeTaskQueue<T>::pop()
{
    uniqueLock(_mtx);
    this->_taskQueue.pop();

}

template<typename T>
void ThreadSafeTaskQueue<T>::emplace(T &&function)
{
    uniqueLock(_mtx);
    this->_taskQueue.emplace(function);
}
template<typename T>
ThreadSafeTaskQueue<T>::ThreadSafeTaskQueue()
{

}
template<typename T>
ThreadSafeTaskQueue<T>::~ThreadSafeTaskQueue()
{

}


#endif