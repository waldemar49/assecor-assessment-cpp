#include "CommandParser.h"
#include "ConsoleCommands.h"

#include <iostream>

namespace ConsoleApplication
{
 
  bool CommandParser::parseCommand(const std::string& command, CustomerAPI::Archive& archive)
  {
    if (command == "add")
      addCustomer(archive);
    else if (command == "availableColors")
      ConsoleCommands::availableColors();
    else if (command == "print")
      printById(archive);
    else if (command == "printAll")
      ConsoleCommands::printAllCustomers(archive);
    else if (command == "help")
      ConsoleCommands::help();
    else if (command == "quit")
      return true;
    else
      ConsoleCommands::unknownCommand();

    clearInputStream(); // Only one command per input.
    return false;
  }

  void CommandParser::printById(const CustomerAPI::Archive& archive)
  {
    int id;
    std::cin >> id;
    if (!std::cin)
    {
      std::cout << "Invalid parameter for print, parameter must be a positive integer.\n" <<
                   "Please repeat your request.\n";
      clearInputStream();
    }
    else
    {
      ConsoleCommands::printCustomer(archive, id);
    }
  }

  void CommandParser::addCustomer(CustomerAPI::Archive& archive)
  {
    std::string firstName;
    std::string lastName;
    std::string zipCode;
    std::string city;
    std::string colorStr;

    std::cin >> firstName;
    std::cin >> lastName;
    std::cin >> zipCode;
    std::cin >> city;
    std::cin >> colorStr;

    removeComma(firstName);
    removeComma(lastName);
    removeComma(zipCode);
    removeComma(city);
    removeComma(colorStr);

    CustomerAPI::Colors color = CustomerAPI::stringToColor(colorStr);
    if (color == CustomerAPI::Colors::LAST_COLOR)
    {
      std::cout << "An invalid color was entered.\n" <<
                   "Please repeat your request with a valid favorite color.\n";
      ConsoleCommands::availableColors();

      return;
    }

    try 
    {
      CustomerAPI::CUSTOMER customer = CustomerAPI::CUSTOMER(firstName, lastName, zipCode, city, color);
      ConsoleCommands::addCustomer(archive, customer);
    }
    catch (const std::runtime_error& e)
    {
      std::cout << "Invalid parameter for add, " << e.what() << "\n" <<
                   "Please repeat your request with valid parameters.\n";
    }
  }

  void CommandParser::clearInputStream()
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  void CommandParser::removeComma(std::string& toRemoveFrom)
  {
    if(toRemoveFrom[toRemoveFrom.size() - 1] == ',')
      toRemoveFrom.pop_back();
  }

} // ConsoleApplication