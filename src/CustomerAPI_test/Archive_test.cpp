#include "Archive_test.h"

#include <optional>

const std::vector<CustomerAPI::CUSTOMER> initialCustomers = { CustomerAPI::CUSTOMER("Anna", "Nuhr", "23354", "Böhringen", CustomerAPI::Colors::COLOR_RED),
                                                              CustomerAPI::CUSTOMER("Bob", "Stuhr", "87985", "Suhlingen", CustomerAPI::Colors::COLOR_GREEN),
                                                              CustomerAPI::CUSTOMER("Carin", "Lahm", "48938", "Menden", CustomerAPI::Colors::COLOR_BLUE),
                                                              CustomerAPI::CUSTOMER("Dieter", "Sauer", "3989", "Blender", CustomerAPI::Colors::COLOR_TURQUOISE),
                                                              CustomerAPI::CUSTOMER("Egon", "Fehn", "30492", "Vöhringen", CustomerAPI::Colors::COLOR_YELLOW) };

void ArchiveTester::SetUp()
{
  archive = CustomerAPI::Archive();
  for (auto customer : initialCustomers)
  {
    archive.addCustomer(customer);
  }

  GTEST_ASSERT_EQ(archive.getSize(), 5) << "Setup failed, tried to insert " << initialCustomers.size() << " customers, found: " << archive.getSize();
}

TEST_F(ArchiveTester, addLoadedCustomerTest)
{
  // Simulate existing customer. E.g. from database.
  const int existingCustomerId = 99;
  archive.addCustomer(CustomerAPI::CUSTOMER("a", "a", "a", "a", CustomerAPI::Colors::COLOR_BLUE, existingCustomerId));
  std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(existingCustomerId);
  GTEST_ASSERT_EQ(customer.has_value(), true);
  GTEST_ASSERT_EQ(customer.value().id, existingCustomerId);

  // Add a new customer.
  archive.addCustomer(CustomerAPI::CUSTOMER("b", "b", "b", "b", CustomerAPI::Colors::COLOR_BLUE));
  customer = archive.getCustomer(existingCustomerId + 1);
  GTEST_ASSERT_EQ(customer.has_value(), true);
  GTEST_ASSERT_EQ(customer.value().id, existingCustomerId + 1);
}

TEST_F(ArchiveTester, addCustomersTest)
{
  const int expectedId = 6;
  const std::string testFirstName = "A";
  const std::string testLastName = "B";
  const std::string testZipCode = "012234";
  const std::string testCity = "C";
  const CustomerAPI::Colors testColor = CustomerAPI::Colors::COLOR_WHITE;

  archive.addCustomer(CustomerAPI::CUSTOMER(testFirstName, testLastName, testZipCode, testCity, testColor));
  GTEST_ASSERT_EQ(archive.getSize(), expectedId);

  std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(expectedId);
  GTEST_ASSERT_EQ(customer.has_value(), true);
  GTEST_ASSERT_EQ(customer.value().id, expectedId);
  GTEST_ASSERT_EQ(customer.value().first_name, testFirstName);
  GTEST_ASSERT_EQ(customer.value().last_name, testLastName);
  GTEST_ASSERT_EQ(customer.value().zip_code, testZipCode);
  GTEST_ASSERT_EQ(customer.value().city, testCity);
  GTEST_ASSERT_EQ(customer.value().favorite_color, testColor);
}

TEST_F(ArchiveTester, getCustomersByIdTest)
{
  for (int i = 0; i < initialCustomers.size(); ++i)
  {
    std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(i + 1); // One indexed.
    GTEST_ASSERT_EQ(customer.has_value(), true);
    GTEST_ASSERT_EQ(customer.value().id, i + 1);
    GTEST_ASSERT_EQ(customer.value().first_name, initialCustomers[i].first_name);
    GTEST_ASSERT_EQ(customer.value().last_name, initialCustomers[i].last_name);
    GTEST_ASSERT_EQ(customer.value().zip_code, initialCustomers[i].zip_code);
    GTEST_ASSERT_EQ(customer.value().city, initialCustomers[i].city);
    GTEST_ASSERT_EQ(customer.value().favorite_color, initialCustomers[i].favorite_color);
  }

  // Negative test.
  std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(999);
  GTEST_ASSERT_EQ(customer.has_value(), false) << "Error: found unexpected customer with ID: " << 999 << ", this customer should not exist.";
}

TEST_F(ArchiveTester, getAllCustomersTest)
{
  std::vector<CustomerAPI::CUSTOMER> customers = archive.getAllCustomers();
  GTEST_ASSERT_EQ(customers.size(), initialCustomers.size());
  GTEST_ASSERT_EQ(customers.size(), archive.getSize());
}
