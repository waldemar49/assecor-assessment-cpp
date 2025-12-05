#pragma once

#include "Archive.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <optional>

// Couldn't get this to work.
class MockArchive : public CustomerAPI::Archive
{

public:

  MOCK_METHOD(void, addCustomer, (CustomerAPI::CUSTOMER& customer), (override));
  MOCK_METHOD(std::optional<CustomerAPI::CUSTOMER>, getCustomer, (int id), (const override));
  MOCK_METHOD(std::vector<CustomerAPI::CUSTOMER>, getAllCustomers, (), (const, override));
  MOCK_METHOD(size_t, getSize, (), (const, override));

};

class ArchiveTester : public ::testing::Test
{

protected:

  ArchiveTester() : archive(CustomerAPI::Archive()) {};

  void SetUp();

  void addCustomersTest();
  void addLoadedCustomerTest();
  void getCustomersByIdTest();
  void getAllCustomersTest();

  CustomerAPI::Archive archive;

};