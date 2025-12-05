#pragma once

#include "Archive.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <optional>

class MockArchive : public CustomerAPI::Archive
{

public:

  MOCK_METHOD(void, addCustomer, (CustomerAPI::CUSTOMER& customer), (override));
  MOCK_METHOD(std::optional<CustomerAPI::CUSTOMER>, getCustomer, (int id), (const, override));
  MOCK_METHOD(std::vector<CustomerAPI::CUSTOMER>, getAllCustomers, (), (const, override));
  MOCK_METHOD(size_t, getSize, (), (const, override));

  void _addCustomer(CustomerAPI::CUSTOMER& customer)
  {
    CustomerAPI::Archive::addCustomer(customer);
  }

};

class ArchiveTester : public ::testing::Test
{

protected:

  void SetUp() override;

  void addCustomersTest();
  void addLoadedCustomerTest();
  void getCustomersByIdTest();
  void getAllCustomersTest();

  MockArchive archive;

};