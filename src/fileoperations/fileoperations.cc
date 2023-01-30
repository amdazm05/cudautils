#include "fileoperations/fileoperations.hpp"

void FileOperations::init()
{
    // Calls the constructor
    static bool isInstance;
    if(!static_cast<bool>(isInstance))
    {
        _instance = std::unique_ptr<FileOperations>(new FileOperations());
        isInstance = true;
    }
    
}

std::unique_ptr<FileOperations> FileOperations::getinstance()
{
    return _instance;
}

void FileOperations::readfromfile(std::string filename,char * buffer, size_t sizeofbuffer)
{
    if(filereadhandles.find(filename) != filewritehandles.end())
    {
        std::ofstream file(filename, std::ios::in | std::ios::binary);
        filereadhandles.insert(std::pair<std::string,std::ofstream>(filename,std::move(file)));
    }
    filereadhandles.find(filename)->second->read(buffer,sizeofbuffer);
}

void writetofile (std::string filename,char * buffer, size_t sizeofbuffer)
{

}

FileOperations::FileOperations()
{

}