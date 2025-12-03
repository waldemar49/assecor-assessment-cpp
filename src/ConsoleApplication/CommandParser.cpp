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
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

    // TODO: react to commas.
    std::cin >> firstName;
    std::cin >> lastName;
    std::cin >> zipCode;
    std::cin >> city;

    std::cin >> colorStr;
    CustomerAPI::Colors color = static_cast<CustomerAPI::Colors>(CustomerAPI::stringToColor(colorStr));
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

} // ConsoleApplication