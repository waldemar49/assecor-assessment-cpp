#pragma once

#include "Archive.h"
#include "Formatter.h"
#include "Customer.h"

#include <string>

namespace ConsoleApplication
{

  class CommandParser
  {

  public:

    static bool parseCommand(const std::string& command, CustomerAPI::Archive& archive);

  private:

    static void printById(const CustomerAPI::Archive& archive);
    static void addCustomer(CustomerAPI::Archive& archive);

    static void clearInputStream();
    static void removeComma(std::string& toRemoveFrom);

  };

} // ConsoleApplication