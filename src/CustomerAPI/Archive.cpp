#include "pch.h"
#include "Archive.h"

#include <algorithm>

namespace CustomerAPI
{
  
  void Archive::addCustomer(CUSTOMER& customer)
  {
    if (!customers.empty()) // Likely.
      customer.id = static_cast<int>((customers.rbegin())->id + 1); // Set is sorted, so should be biggest ID.
    else
      customer.id = 0;
    
    customers.insert(customer);
  }

  std::optional<CUSTOMER> Archive::getCustomer(int id) const
  {
    if (customers.empty())
      return std::nullopt;

    if (const auto it = std::find_if(customers.begin(), customers.end(), [id](const CUSTOMER& customer) { return id == customer.id; }); 
      it != customers.end())
    {
      return *it;
    }

    return std::nullopt;
  }

  std::vector<CUSTOMER> Archive::getAllCustomers() const
  {
    std::vector<CUSTOMER> res;
    for (auto& c : customers)
    {
      res.emplace_back(c);
    }

    return res;
  }

  size_t Archive::getSize() const
  {
    return customers.size();
  }

} // CustomerDatabase
