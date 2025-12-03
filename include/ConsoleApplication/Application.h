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

    CustomerAPI::Archive archive;

  };

} // ConsoleApplication
