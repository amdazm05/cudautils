#include <thread/threadpool.tcc>

int foo(int a , int b){return a+b;}

int main()
{
    ThreadPool::init(2);
    std::shared_ptr<ThreadPool>  instance = ThreadPool::get_instance();
    // instance->runPool();
    std::cout<<instance->queueTask(std::move(foo),4,5); 
}