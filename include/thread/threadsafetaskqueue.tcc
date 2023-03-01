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
        using writeLock = std::unique_lock<std::shared_mutex>;
        using readLock  = std::shared_lock<std::shared_mutex>;
        ThreadSafeTaskQueue();
        void clear();
        void push(T &function);
        void pop();
        void emplace(T&function);
        ~ThreadSafeTaskQueue();
};

template<typename T>
void ThreadSafeTaskQueue<T>::push(T &function)
{
    writeLock(_mtx);
    this->_threadQueue.push(std::move(&function));
}


template<typename T>
void ThreadSafeTaskQueue<T>::pop()
{
    writeLock(_mtx);
    this->_threadQueue.pop();

}

template<typename T>
void ThreadSafeTaskQueue<T>::pop()
{
    writeLock(_mtx);
    this->_threadQueue.pop();

}

template<typename T>
void ThreadSafeTaskQueue<T>::emplace(T &function)
{
    writeLock(_mtx);
    this->_threadQueue.emplace(std::move(&function));
}

#endif