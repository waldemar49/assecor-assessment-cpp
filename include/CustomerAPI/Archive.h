#pragma once

#include "customer.h"
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

  /**
   * Provides the implementation of a customer archive.
   */
  class Archive
  {

  public:
    
    virtual ~Archive() = default;

    /**
     * @brief Adds the given customer to the archive.
     * @param customer The customer to add.
     */
    CUSTOMERAPI virtual void addCustomer(CUSTOMER& customer);

    /**
     * @brief Gets customer with given ID from archive, if any.
     * @param id The of the customer to get.
     * @return The customer with given ID, nullopt, else.
     */
    CUSTOMERAPI virtual std::optional<CUSTOMER> getCustomer(int id) const;

    /**
     * @brief Returns a sorted vector of all customers currently in the archive.
     * @return A vector of all customers in archive.
     */
    CUSTOMERAPI virtual std::vector<CUSTOMER> getAllCustomers() const;

    CUSTOMERAPI virtual size_t getSize() const;

  private:

    std::set<CUSTOMER, customerCompare> customers;

  };

} // CustomerDatabase