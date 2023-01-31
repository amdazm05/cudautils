#ifndef _FILEOPS
#define _FILEOPS

#include "utils/util.hpp"
#define MAP_SIGNATURE_OFSTREAM std::string,std::unique_ptr<std::ofstream,void(*)(std::ofstream *)>
#define MAP_SIGNATURE_IFSTREAM std::string,std::unique_ptr<std::ifstream,void(*)(std::ifstream *)>
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
        std::unordered_map<MAP_SIGNATURE_OFSTREAM> filewritehandles;
        std::unordered_map<MAP_SIGNATURE_IFSTREAM> filereadhandles; 
};  

void ifstream_deleter(std::ifstream * ptr);
void ofstream_deleter(std::ofstream * ptr);

#endif //_FILEOPS