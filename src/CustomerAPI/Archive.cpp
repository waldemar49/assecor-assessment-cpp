#include "pch.h"
#include "Archive.h"

namespace CustomerAPI
{

  Archive::Archive()
  {
    // Pre-allocate some space to avoid unnecessary copying of the vector, keep it small since this is just an exercise.
    customers.reserve(16);
  }
  
  void Archive::addCustomer(CUSTOMER& customer)
  {
    customer.id = static_cast<int>(customers.size()); // Narrowing cast, but unlikely to be a problem.
    customers.emplace_back(customer);
  }

  std::optional<CUSTOMER> Archive::getCustomer(int id) const
  {
    if (customers.empty() || id < 0 || id > customers.size())
      return std::nullopt;

    return customers[id];
  }

  std::vector<CUSTOMER> Archive::getAllCustomers() const
  {
    return customers;
  }

  size_t Archive::getSize() const
  {
    return customers.size();
  }

} // CustomerDatabase
