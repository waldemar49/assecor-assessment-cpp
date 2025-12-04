#pragma once

#include "Customer.h"
#include "CustomerAPI_Exports.h"

#include <set>
#include <vector>
#include <optional>

namespace CustomerAPI
{

  // Provides the compare function for the set that holds the customers.
  struct customerCompare
  {
    bool operator() (const CUSTOMER& a, const CUSTOMER& b) 
    { 
      return a.id < b.id; 
    }
  };

  class Archive
  {

  public:
    
    CUSTOMERAPI void addCustomer(CUSTOMER& customer);

    CUSTOMERAPI std::optional<CUSTOMER> getCustomer(int id) const;

    CUSTOMERAPI std::vector<CUSTOMER> getAllCustomers() const;

    CUSTOMERAPI size_t getSize() const;

  private:

    std::set<CUSTOMER, customerCompare> customers;

  };

} // CustomerDatabase