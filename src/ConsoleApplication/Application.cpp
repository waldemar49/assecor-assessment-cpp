#include "Application.h"
#include "CommandParser.h"

#include <iostream>

namespace ConsoleApplication
{

  const std::string welcomeText = "Welcome to the simple customer archive console application.\n"
                                  "Enter \"help\" if further instructions are needed.\n"
                                  "Enter \"quit\" to quit the application.\n";
  const std::string prompt = "> ";

  Application::Application()
    :
    archive(CustomerAPI::Archive())
  {
  }

  int Application::exec()
  {
    std::cout << welcomeText;
    std::cout << prompt;

    while (std::cin)
    {
      std::string commandStr;
      std::cin >> commandStr;
      if (CommandParser::parseCommand(commandStr, archive))
        break;

      std::cout << prompt;
    }

    return 0;
  }

} // ConsoleApplication