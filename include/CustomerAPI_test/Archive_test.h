#pragma once

#include "Archive.h"

#include <gtest/gtest.h>

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