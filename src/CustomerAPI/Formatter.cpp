#include "pch.h"
#include "Formatter.h"
#include "Archive.h"
#include "Customer.h"

#include <sstream>

namespace CustomerAPI
{
  
  const std::string noCustomerStr = "(Kein Kunde)";

  std::string Formatter::getCustomerString(const CUSTOMER& customer)
  {
    return getFormattedString(customer);
  }

  std::string Formatter::getCustomerString(int id, const Archive& archive)
  {
    std::optional<CUSTOMER> customer = archive.getCustomer(id);
    if (customer.has_value())
      return getFormattedString(customer.value());
    else
      return noCustomerStr;
  }

  std::string Formatter::getAllCustomersString(const Archive& archive)
  {
    std::stringstream ss;
    if (std::vector<CUSTOMER> allCustomers = archive.getAllCustomers(); allCustomers.empty())
    {
      ss << noCustomerStr;
    }
    else
    {
      for (auto customer : allCustomers)
      {
        ss << getFormattedString(customer);
        if (customer.id != allCustomers.size() - 1)
          ss << "\n";
      }
    }

    return ss.str();
  }

  std::string Formatter::getFormattedString(const CUSTOMER& customer)
  {
    std::stringstream ss;
    ss << customer.first_name << ", " << customer.last_name << ", " << customer.zip_code << ", " << customer.city <<
      ", " << colorToString(customer.favorite_color);

    return ss.str();
  }

} // CustomerDatabase