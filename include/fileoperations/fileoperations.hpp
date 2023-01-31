#ifndef _FILEOPS
#define _FILEOPS

#include "utils/util.hpp"

class FileOperations
{
    public:
        static void init();
        static std::shared_ptr<FileOperations> getinstance();
        void readfromfile(std::string&& filename,char * buffer, size_t sizeofbuffer);
        void writetofile (std::string&& filename,char * buffer, size_t sizeofbuffer);

        ~FileOperations();
    private:
        static std::shared_ptr<FileOperations> _instance; 
        FileOperations();
        std::unordered_map<std::string,std::ofstream> filewritehandles;
        std::unordered_map<std::string,std::ifstream> filereadhandles; 
};  

#endif //_FILEOPS