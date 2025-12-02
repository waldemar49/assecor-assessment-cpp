#define no_init_all deprecated // Some visual studio bug.

#include "Application.h"

#include <stdexcept>
#include <iostream>

int main(int argc, char** argv)
{ 
  ConsoleApplication::Application app;
  try
  {
    // Main loop.
    return app.exec();
  }
  catch (const std::runtime_error& e)
  {
    std::cout << "Error: " << e.what();
    
    return 1;
  }
  catch (...)
  {
    std::cout << "An unexpected error occurred.";

    return 2;
  }
}