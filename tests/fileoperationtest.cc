#include "fileoperations/fileoperations.hpp"

int main()
{
    char * buffer = "123456";
    char * buffer2 = new char[5];
    FileOperations::init();
    FileOperations *Handle = FileOperations::getinstance().get();

    Handle->writetofile("myfile.bin",buffer,sizeof(buffer));
    Handle->readfromfile("myfile.bin",buffer2,5);
    std::cout<<buffer2<<std::endl;
    return 0;
}