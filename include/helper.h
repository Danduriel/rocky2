#ifndef HELPER_H
#define HELPER_H
//#include <string>
#include <string.h>
#include <iostream>

class helper
{
    public:
        helper();

        void debugMsg(std::string s)
        {
            std::cout<<s<< std::endl;
        }

    protected:

    private:
};

#endif // HELPER_H
