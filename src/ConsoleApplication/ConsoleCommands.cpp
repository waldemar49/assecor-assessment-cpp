#include "ConsoleCommands.h"

#include <iostream>
#include <sstream>

namespace ConsoleApplication
{

  void ConsoleCommands::addCustomer(CustomerAPI::Archive& archive, CustomerAPI::CUSTOMER & customer)
  {
    archive.addCustomer(customer);
  }

  void ConsoleCommands::availableColors()
  {
    std::stringstream ss;
    for (int i = 1; i < CustomerAPI::Colors::LAST_COLOR; ++i)
    {
      ss << CustomerAPI::colorToString(static_cast<CustomerAPI::Colors>(i));
      if (i < static_cast<int>(CustomerAPI::Colors::LAST_COLOR) - 1)
        ss << ", ";
    }

    std::cout << "The following colors are available:\n  " << ss.str() << "\n";
  }

  void ConsoleCommands::help()
  {
    std::cout << "Available commands:\n" <<
      "  add <first name, last name, zipcode, city, favorite color> - to add a new customer with given parameters to database.\n" <<
      "  availableColors - for a list of available favorite colors to choose from.\n"
      "  help - for a list of available commands.\n" <<
      "  print <ID> - to print customer with given ID.\n" <<
      "  printAll - to print all customers in database.\n" <<
      "  quit - to quit the application.\n";
  }

  void ConsoleCommands::printCustomer(const CustomerAPI::Archive& archive, int id)
  {
    if (const auto customer = archive.getCustomer(id); customer.has_value())
    {
      std::cout << CustomerAPI::Formatter::getCustomerString(customer.value()) << "\n";
    }
    else
    {
      std::cout << "(Kein Kunde)\n";
    }
  }

  void ConsoleCommands::printAllCustomers(const CustomerAPI::Archive& archive)
  {
    std::cout << CustomerAPI::Formatter::getAllCustomersString(archive) << "\n";
  }

  void ConsoleCommands::unknownCommand()
  {
    std::cout << "You have entered an unknown command.\n";
  }

}