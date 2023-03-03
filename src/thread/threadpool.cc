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
    stopFlag = false;
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(_mtx);
        stopFlag= true;
    }
    _condition.notify_all();
    for(int i=0;i<_numberOfThreads;i++)
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
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(_mtx);
                        _condition.wait(lock,[this]{ return stopFlag || !_TasksQueue.empty();});
                        if(stopFlag)
                        {
                            return;
                        }
                        task = std::move((_TasksQueue.front()));
                        _TasksQueue.pop();
                    }
                    task();

                }
            }
        );
   }
}

 void ThreadPool::cleanse()
 {
    _instance.reset();

 }