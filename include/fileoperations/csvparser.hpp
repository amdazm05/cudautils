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
    private:
        std::fstream csvfile();
}

#endif //_CSV_PARSER