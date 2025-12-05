#include "Archive_test.h"

#include <optional>

using ::testing::Return;

const std::vector<CustomerAPI::CUSTOMER> initialCustomers = { CustomerAPI::CUSTOMER("Anna", "Nuhr", "23354", "Böhringen", CustomerAPI::Colors::COLOR_RED),
                                                              CustomerAPI::CUSTOMER("Bob", "Stuhr", "87985", "Suhlingen", CustomerAPI::Colors::COLOR_GREEN),
                                                              CustomerAPI::CUSTOMER("Carin", "Lahm", "48938", "Menden", CustomerAPI::Colors::COLOR_BLUE),
                                                              CustomerAPI::CUSTOMER("Dieter", "Sauer", "3989", "Blender", CustomerAPI::Colors::COLOR_TURQUOISE),
                                                              CustomerAPI::CUSTOMER("Egon", "Fehn", "30492", "Vöhringen", CustomerAPI::Colors::COLOR_YELLOW) };

void ArchiveTester::SetUp()
{
  ON_CALL(archive, addCustomer(::testing::_))
    .WillByDefault([this](CustomerAPI::CUSTOMER& customer) 
  {
    archive._addCustomer(customer);
  });

  EXPECT_CALL(archive, addCustomer(::testing::_))
    .Times(5);

  for (auto customer : initialCustomers)
  {
    archive.addCustomer(customer);
  }

  EXPECT_CALL(archive, getSize())
    .Times(1)
    .WillOnce(Return(5));
  
  archive.getSize();
}

TEST_F(ArchiveTester, addLoadedCustomerTest)
{
  // Simulate existing customer. E.g. from database.
  const int existingCustomerId = 99;
  CustomerAPI::CUSTOMER existingCustomer = CustomerAPI::CUSTOMER("a", "a", "a", "a", CustomerAPI::Colors::COLOR_BLUE, existingCustomerId);

  EXPECT_CALL(archive, addCustomer(existingCustomer))
    .Times(1);

  EXPECT_CALL(archive, getCustomer(existingCustomerId))
    .Times(1)
    .WillOnce(Return(existingCustomer));

  archive.addCustomer(existingCustomer);
  std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(existingCustomerId);

  GTEST_ASSERT_EQ(customer.has_value(), true);
  GTEST_ASSERT_EQ(customer.value().id, existingCustomerId);

  // Add a new customer.
  CustomerAPI::CUSTOMER newCustomer = CustomerAPI::CUSTOMER("b", "b", "b", "b", CustomerAPI::Colors::COLOR_BLUE);
  
  EXPECT_CALL(archive, addCustomer(newCustomer))
    .Times(1);
  
  archive.addCustomer(newCustomer);

  EXPECT_CALL(archive, getCustomer(existingCustomerId + 1))
    .Times(1)
    .WillOnce(Return(newCustomer));

  customer = archive.getCustomer(existingCustomerId + 1);

  GTEST_ASSERT_EQ(customer.has_value(), true);
  GTEST_ASSERT_EQ(customer.value().id, existingCustomerId + 1);
}

TEST_F(ArchiveTester, addCustomersTest)
{
  const int expectedId = 6;
  CustomerAPI::CUSTOMER newCustomer = CustomerAPI::CUSTOMER("a", "b", "01234", "c", CustomerAPI::Colors::COLOR_WHITE);

  EXPECT_CALL(archive, addCustomer(newCustomer))
    .Times(1);

  EXPECT_CALL(archive, getSize())
    .Times(1)
    .WillOnce(Return(expectedId));

  archive.addCustomer(newCustomer);
  archive.getSize();

  EXPECT_CALL(archive, getCustomer(expectedId))
    .Times(1)
    .WillOnce(Return(newCustomer));

  std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(expectedId);
  GTEST_ASSERT_EQ(customer.value().id, expectedId);
  GTEST_ASSERT_EQ(customer.value().first_name, newCustomer.first_name);
  GTEST_ASSERT_EQ(customer.value().last_name, newCustomer.last_name);
  GTEST_ASSERT_EQ(customer.value().zip_code, newCustomer.zip_code);
  GTEST_ASSERT_EQ(customer.value().city, newCustomer.city);
  GTEST_ASSERT_EQ(customer.value().favorite_color, newCustomer.favorite_color);
}

TEST_F(ArchiveTester, getCustomersByIdTest)
{
  for (int i = 0; i < initialCustomers.size(); ++i)
  {
    EXPECT_CALL(archive, getCustomer(i + 1))
      .Times(1)
      .WillOnce(Return(initialCustomers[i]));

    std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(i + 1); // One indexed.
    GTEST_ASSERT_EQ(customer.has_value(), true);
    GTEST_ASSERT_EQ(customer.value().first_name, initialCustomers[i].first_name);
    GTEST_ASSERT_EQ(customer.value().last_name, initialCustomers[i].last_name);
    GTEST_ASSERT_EQ(customer.value().zip_code, initialCustomers[i].zip_code);
    GTEST_ASSERT_EQ(customer.value().city, initialCustomers[i].city);
    GTEST_ASSERT_EQ(customer.value().favorite_color, initialCustomers[i].favorite_color);
  }

  // Negative test.
  int invalidCustomerId = 999;
  EXPECT_CALL(archive, getCustomer(invalidCustomerId))
    .Times(1)
    .WillOnce(Return(std::nullopt));

  std::optional<CustomerAPI::CUSTOMER> customer = archive.getCustomer(invalidCustomerId);
  GTEST_ASSERT_EQ(customer.has_value(), false) << "Error: found unexpected customer with ID: " << invalidCustomerId << ", this customer should not exist.";
}

TEST_F(ArchiveTester, getAllCustomersTest)
{
  EXPECT_CALL(archive, getAllCustomers())
    .Times(1)
    .WillOnce(Return(initialCustomers));

  EXPECT_CALL(archive, getSize())
    .Times(1)
    .WillOnce(Return(initialCustomers.size()));

  std::vector<CustomerAPI::CUSTOMER> customers = archive.getAllCustomers();
  GTEST_ASSERT_EQ(customers.size(), archive.getSize());
}
