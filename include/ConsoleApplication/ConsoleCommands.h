#pragma once

#include "Archive.h"
#include "Customer.h"
#include "Formatter.h"

namespace ConsoleApplication
{

  /**
   * A collection of static functions to execute requested console commands.
   */
  class ConsoleCommands
  {

  public:

    static void addCustomer(CustomerAPI::Archive& archive, CustomerAPI::CUSTOMER& customer);
    static void availableColors();
    static void help();
    static void printCustomer(const CustomerAPI::Archive& archive, int id);
    static void printAllCustomers(const CustomerAPI::Archive& archive);
    static void unknownCommand();

  };

}  // ConsoleApplication
