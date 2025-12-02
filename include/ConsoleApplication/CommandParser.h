#pragma once

#include "Archive.h"
#include "Formatter.h"
#include "Customer.h"

#include <string>

namespace ConsoleApplication
{

  enum class Command
  {
    unknonw,
    exit,
    help,
    add,
    printById,
    printAll
  };

  class CommandParser
  {

  public:

    static Command parseCommand(const std::string& command);

  };

} // ConsoleApplication