#include "Controller.h"
#include <iostream>
#include <sstream>
using std::cerr;

int main()
{
    srand(time(0));
    Controller c;
    try
    {
        c.run();
    }
    catch (std::exception& error)
    {
        cerr << error.what() << "\n";
        return EXIT_FAILURE;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
