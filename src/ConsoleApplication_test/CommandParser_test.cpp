#include "CommandParser_test.h"
#include "CommandParser.h"
#include "Customer.h"

const std::vector<CustomerAPI::CUSTOMER> initialCustomers = { CustomerAPI::CUSTOMER("Anna", "Nuhr", "23354", "Böhringen", CustomerAPI::Colors::COLOR_RED),
                                                              CustomerAPI::CUSTOMER("Bob", "Stuhr", "87985", "Suhlingen", CustomerAPI::Colors::COLOR_GREEN),
                                                              CustomerAPI::CUSTOMER("Carin", "Lahm", "48938", "Menden", CustomerAPI::Colors::COLOR_BLUE),
                                                              CustomerAPI::CUSTOMER("Dieter", "Sauer", "3989", "Blender", CustomerAPI::Colors::COLOR_TURQUOISE),
                                                              CustomerAPI::CUSTOMER("Egon", "Fehn", "30492", "Vöhringen", CustomerAPI::Colors::COLOR_YELLOW) };

void CommandParserTester::SetUp()
{
  for (auto customer : initialCustomers)
  {
    archive.addCustomer(customer);
  }

  GTEST_ASSERT_EQ(archive.getSize(), 5);
}

TEST_F(CommandParserTester, testAddCustomer)
{
  std::string addCustomer = "add";
  std::streambuf* orig = std::cin.rdbuf();
  std::istringstream input("a b c d blue");
  std::cin.rdbuf(input.rdbuf());

  ConsoleApplication::CommandParser::parseCommand(addCustomer, archive);
}

TEST_F(CommandParserTester, testPrintCustomerById)
{
  for (int i = 0; i < initialCustomers.size(); ++i)
  {
    // Assign
    std::string printCustomer = "print";
    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input(std::to_string(i + 1));
    std::cin.rdbuf(input.rdbuf());

    // Act
    testing::internal::CaptureStdout();
    ConsoleApplication::CommandParser::parseCommand(printCustomer, archive);

    // Assert
    std::vector<std::string> words;
    {
      std::stringstream output;
      output << testing::internal::GetCapturedStdout();
      std::string tmp;
      while (std::getline(output, tmp, ','))
      {
        if (tmp[0] == ' ')
          tmp.erase(0, 1);

        if (size_t index = tmp.find("\n"); index != std::string::npos)
          tmp.erase(index, 2);

        words.emplace_back(tmp);
      }
    }

    GTEST_ASSERT_EQ(words[0], initialCustomers[i].first_name);
    GTEST_ASSERT_EQ(words[1], initialCustomers[i].last_name);
    GTEST_ASSERT_EQ(words[2], initialCustomers[i].zip_code);
    GTEST_ASSERT_EQ(words[3], initialCustomers[i].city);
    GTEST_ASSERT_EQ(words[4], CustomerAPI::colorToString(initialCustomers[i].favorite_color));
  }
}

TEST_F(CommandParserTester, testPrintAllCustomers)
{
  // Assign
  std::string printCustomer = "printAll";
  std::streambuf* orig = std::cin.rdbuf();
  std::istringstream input("");
  std::cin.rdbuf(input.rdbuf());

  // Act
  testing::internal::CaptureStdout();
  ConsoleApplication::CommandParser::parseCommand(printCustomer, archive);

  // Assert
  std::vector<std::string> words;
  {
    std::stringstream output;
    output << testing::internal::GetCapturedStdout();
    std::string tmp;
    while (std::getline(output, tmp, '\n'))
    {
      words.emplace_back(tmp);
    }
  }

  GTEST_ASSERT_EQ(words.size(), initialCustomers.size());
}