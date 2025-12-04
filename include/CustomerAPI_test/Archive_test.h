#pragma once

#include "Archive.h"

#include <gtest/gtest.h>
//#include <gmo
//
//class MockArchive : public CustomerAPI::Archive
//{
//
//public:
//
//  MOCK_METHOD
//
//};

class ArchiveTester : public ::testing::Test
{

protected:

  void SetUp();

  void addCustomersTest();
  void addLoadedCustomerTest();
  void getCustomersByIdTest();
  void getAllCustomersTest();

  CustomerAPI::Archive archive;

};