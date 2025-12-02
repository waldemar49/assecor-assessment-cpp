#include "CommandParser.h"

namespace ConsoleApplication
{
 
  Command CommandParser::parseCommand(const std::string& command)
  {
    if (command == "add")
      return Command::add;
    else if (command == "print")
      return Command::printById;
    else if (command == "printAll")
      return Command::printAll;
    else if (command == "exit")
      return Command::exit;
    else if (command == "help")
      return Command::help;

    return Command::unknonw;
  }

} // ConsoleApplication