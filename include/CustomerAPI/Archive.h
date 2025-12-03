#pragma once

#define no_init_all deprecated // Some visual studio bug.

#ifdef CUSTOMERAPI_EXPORTS
#define CUSTOMERAPI __declspec(dllexport)
#else
#define CUSTOMERAPI __declspec(dllimport)
#endif

#include "Customer.h"

#include <vector>
#include <optional>

namespace CustomerAPI
{

  class Archive
  {

  public:
    
    CUSTOMERAPI Archive();

    CUSTOMERAPI void addCustomer(CUSTOMER& customer);

    CUSTOMERAPI std::optional<CUSTOMER> getCustomer(int id) const;

    CUSTOMERAPI std::vector<CUSTOMER> getAllCustomers() const;

    CUSTOMERAPI size_t getSize() const;

  private:

    // TODO: existing data might have holes in-between their IDs making vector unsuitable -> use set with unique ID as hash.
    std::vector<CUSTOMER> customers; // Since IDs are unique we can use a vector container with index = ID to identify the objects.

  };

} // CustomerDatabase