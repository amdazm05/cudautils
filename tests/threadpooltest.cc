#include <thread/threadpool.tcc>

int foo(int a , int b){return a+b;}

int main()
{
    ThreadPool::init(3);
    std::shared_ptr<ThreadPool>  instance = ThreadPool::get_instance();
    instance->runPool();
    std::cout<<instance->queueTask(std::move(foo),4,5)<<std::endl; 
    std::cout<<instance->queueTask(std::move(foo),4,11)<<std::endl; 
    std::cout<<instance->queueTask(std::move(foo),4,12)<<std::endl; 
}