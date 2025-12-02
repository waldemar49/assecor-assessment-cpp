#include "Application.h"
#include "CommandParser.h"

#include <iostream>

namespace ConsoleApplication
{

  const std::string welcomeText = "Welcome to the simple customer database console application.\n"
                                  "Enter \"help\" if further instructions are needed.\n"
                                  "Enter \"exit\" to quit the application.\n";
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
      if (executeCommand(CommandParser::parseCommand(commandStr)))
        break;

      std::cout << prompt;
    }

    return 0;
  }

  bool Application::executeCommand(Command command)
  {
    switch (command)
    {
    case Command::add:
      std::cout << "unimplemeneted\n";
      return false;
    case Command::printById:
      std::cout << "unimplemeneted\n";
      return false;
    case Command::printAll:
      printAllCustomers();
      return false;
    case Command::help:
      printHelpText();
      return false;
    case Command::exit:
      return true;
    default: // Unknown command.
      printUnknownCommandString();
      return false;
    }
  }

  void Application::printUnknownCommandString()
  {
    std::cout << "You have entered an unknown command.\n";
  }

  void Application::printHelpText()
  {
    std::cout << "Available commands:\n" <<
                 "  exit - to quit the application.\n" <<
                 "  help - for a list of available commands.\n" <<
                 "  add <first name, last name, zipcode, city, favorite color> - to add a new customer with given parameters to database.\n" <<
                 "  print <ID> - to print customer with given ID.\n" <<
                 "  printAll - to print all customers in database.\n";
  }

  void Application::printAllCustomers()
  {
    std::cout << CustomerAPI::Formatter::getAllCustomersString(archive) << "\n";
  }

} // ConsoleApplication