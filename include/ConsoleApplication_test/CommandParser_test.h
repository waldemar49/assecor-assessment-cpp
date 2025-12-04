#pragma once

#include "Archive.h"

#include <gtest/gtest.h>

class CommandParserTester : public ::testing::Test 
{
  
protected:

  void SetUp();



  CustomerAPI::Archive archive;

};