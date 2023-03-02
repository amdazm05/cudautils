#ifndef _THREADPOOL
#define _THREADPOOL

#include "utils/util.hpp"
#include "thread/threadsafetaskqueue.tcc"

// What this class does:
// This is a thread pool manager , it recieves a task and  is able to execute that in a pool typically equal to the number of users specified by the user
// Execute arbitrary functions
// template tells the type of arguements that is to be passed in to the task 
// something along these lines 
class ThreadPool 
{
    private:
    std::atomic_bool _isDone;
    std::vector<std::thread> _workers;
    ThreadSafeTaskQueue<std::function<void()>> _TasksQueue;
    static std::shared_ptr<ThreadPool> _instance;
    // A pool is supposed to have the threads equal to the number of hardware concurrent threads possible
    static std::size_t _numberOfThreads; // = std::thread::hardware_concurrency()
    ThreadPool();
    ThreadPool(std::size_t numberOfThreads);

    public:
    static void init(std::size_t numberOfThreads);
    static std::shared_ptr<ThreadPool> get_instance();
    void runPool();
    ~ThreadPool();
    // Now this needs to be binded
    template<class T, class... Args>
    typename std::result_of<T(Args...)>::type queueTask(T && invokAble , Args && ... arguments);
};

template<class T, class... Args>
typename std::result_of<T(Args...)>::type ThreadPool::queueTask(T && invokAble , Args && ... arguments)
{
  
    std::shared_ptr<std::packaged_task<typename std::result_of<T(Args...)>::type()>> PackedTask = 
    std::make_shared<std::packaged_task<typename std::result_of<T(Args...)>::type()>>
        (
            std::bind(std::forward<T>(invokAble),std::forward<Args>(arguments)...)
        );

    std::future<typename std::result_of<T(Args...)>::type> result = PackedTask->get_future();
    std::function<void()> voidTaskPackaged = [PackedTask](){(*PackedTask)();};
    _TasksQueue.emplace(std::move(voidTaskPackaged));
    //  passes the task into the TaskQueue once it is finished the result will be returned as the type of the function that was passed
    return result.get();
}

#endif //_THREADPOOL
// For some clarity see the example you made
// https://godbolt.org/z/a6nrEjMdc
// helpful thread for my understanding
// https://stackoverflow.com/questions/63240416/whats-the-difference-between-unique-lock-and-shared-lock-in-c
// My inspirations : https://github.com/USCiLab/cereal
// Most notably : // to be honest its more of a learning goal here :)
// https://github.com/progschj/ThreadPool/blob/master/ThreadPool.h
// You might need a conditional variable to show that your task has been completed here