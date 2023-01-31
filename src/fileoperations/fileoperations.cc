#include "fileoperations/fileoperations.hpp"

// Deleters
void ofstream_deleter(std::ofstream * ptr)
{
    ptr->close();
    delete [] ptr;
}
void ifstream_deleter(std::ifstream * ptr)
{   
    ptr->close();
    delete [] ptr;
}
//

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

std::shared_ptr<FileOperations> FileOperations::getinstance()
{
    return _instance;
}

void FileOperations::readfromfile(std::string&& filename,char * buffer, size_t sizeofbuffer)
{
    if(filereadhandles.find(filename) != filereadhandles.end())
    {
        // emplaces an ofstream object into the map
        filereadhandles.emplace
        (
            std::pair<MAP_SIGNATURE_IFSTREAM>
            (   
                filename,
                std::move
                (
                    std::unique_ptr<std::ifstream,void(*)(std::ifstream *)>
                    (
                        new std::ifstream(filename, std::ios::in | std::ios::binary), ifstream_deleter
                    )
                )
            )
        );
    }
    filereadhandles.find(filename)->second->read(buffer,sizeofbuffer);
}

void FileOperations::writetofile(std::string&& filename,char * buffer, size_t sizeofbuffer)
{
    if(filewritehandles.find(filename) != filewritehandles.end())
    {
        // emplaces an ofstream object into the map
        filewritehandles.emplace
        (
            std::pair<MAP_SIGNATURE_OFSTREAM>
            (   
                filename,
                std::move
                (
                    std::unique_ptr<std::ofstream,void(*)(std::ofstream *)>
                    (
                        new std::ofstream(filename, std::ios::out | std::ios::binary), ofstream_deleter
                    )
                )
            )
        );
    }
    filewritehandles.find(filename)->second->write(buffer,sizeofbuffer);
}

FileOperations::FileOperations()
{

}