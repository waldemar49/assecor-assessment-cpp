#pragma once

#ifdef CUSTOMERAPI_EXPORTS
#define CUSTOMERAPI __declspec(dllexport)
#else
#define CUSTOMERAPI __declspec(dllimport)
#endif

#include <string>

namespace CustomerAPI
{

  // Forward declarations to improve compile times.
  struct CUSTOMER;

  class Archive;

  class Formatter
  {

  public:

    static CUSTOMERAPI std::string getCustomerString(const CUSTOMER& customer);
    static CUSTOMERAPI std::string getCustomerString(int id, const Archive& archive);
    static CUSTOMERAPI std::string getAllCustomersString(const Archive& archive);

  private:

    static std::string getFormattedString(const CUSTOMER& customer);

  };

} // CustomerDatabase
