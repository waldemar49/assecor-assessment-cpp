#include "CommandParser_test.h"

const std::vector<CustomerAPI::CUSTOMER> initialCustomers = { CustomerAPI::CUSTOMER("Anna", "Nuhr", "23354", "Böhringen", CustomerAPI::Colors::COLOR_RED),
                                                              CustomerAPI::CUSTOMER("Bob", "Stuhr", "87985", "Suhlingen", CustomerAPI::Colors::COLOR_GREEN),
                                                              CustomerAPI::CUSTOMER("Carin", "Lahm", "48938", "Menden", CustomerAPI::Colors::COLOR_BLUE),
                                                              CustomerAPI::CUSTOMER("Dieter", "Sauer", "3989", "Blender", CustomerAPI::Colors::COLOR_TURQUOISE),
                                                              CustomerAPI::CUSTOMER("Egon", "Fehn", "30492", "Vöhringen", CustomerAPI::Colors::COLOR_YELLOW) };

void CommandParserTester::SetUp()
{
  archive = CustomerAPI::Archive();
  for (auto customer : initialCustomers)
  {
    archive.addCustomer(customer);
  }

  GTEST_ASSERT_EQ(archive.getSize(), 5);
}