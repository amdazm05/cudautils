#include "thread/threadpool.tcc"
std::shared_ptr<ThreadPool> ThreadPool::_instance;
std::size_t ThreadPool::_numberOfThreads;

void ThreadPool::init(std::size_t numberOfthreads)
{
    _instance = std::shared_ptr<ThreadPool>(new ThreadPool);
    _numberOfThreads = numberOfthreads;    
}

ThreadPool::ThreadPool()
{

}

ThreadPool::~ThreadPool()
{
    for(int i=0;i<_workers.size();i++)
    {
        _workers[i].join();
    }
}

std::shared_ptr<ThreadPool> ThreadPool::get_instance()
{
    return _instance;
}

void ThreadPool::runPool()
{
   for(int i =0 ; i <_numberOfThreads ;i++)
   {
        _workers.emplace_back
        (
            // This is the worker function emplaced in the thread
            [this]()
            {
                for(;;)
                {
                    // invokes the invokable
                    if(!_TasksQueue.empty())
                    {
                        (_TasksQueue.front())();
                        // Remove the task from the Task Queue as it is compeleted
                        _TasksQueue.pop();
                    }
                }
            }
        );
   }
}