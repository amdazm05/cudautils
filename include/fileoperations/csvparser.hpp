#ifndef _CSV_PARSER
#define _CSV_PARSER

#include "utils/util.hpp"

// template recieves the structure that requires parsing
template<class T>
class CSVParser
{
    public:

        // Constructors and Destructors
        CSVParser();
        ~CSVParser();
        void readCSVfile(std::string && filename);
        std::vector<T> && getDataVector();
        
    private:
        std::fstream csvfile();
        std::size_t currentRow;
        std::size_t currentColumn;
        std::vector<T> vectorOfdata;
}

#endif //_CSV_PARSER