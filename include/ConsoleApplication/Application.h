#pragma once

#include "Archive.h"

namespace ConsoleApplication
{
  enum class Command;

  class Application
  {

  public:

    Application();

    int exec();

  private:

    bool executeCommand(Command command);

    void printUnknownCommandString();
    void printHelpText();
    void printAllCustomers();

    CustomerAPI::Archive archive;

  };

} // ConsoleApplication
