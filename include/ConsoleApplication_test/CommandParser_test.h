#pragma once

#include "Archive.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class CommandParserTester : public ::testing::Test 
{
  
protected:

  CommandParserTester() 
    : 
    archive(CustomerAPI::Archive()) 
  {};

  void SetUp();

  void testAddCustomer();
  void testPrintCustomerById();
  void testPrintAllCustomers();

  CustomerAPI::Archive archive;

};