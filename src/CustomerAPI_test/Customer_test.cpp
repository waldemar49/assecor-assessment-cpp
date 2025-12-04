#include "Customer_test.h"

const std::string tooLong32Chars = std::string(32, 'a');
const std::string tooLong24Chars = std::string(24, 'a');
const std::string tooLong8Chars = std::string(8, 'a');

TEST(testCustomer, testFirstNameTooLong)
{
  EXPECT_THROW(
    CustomerAPI::CUSTOMER(tooLong24Chars, "a", "a", "a", CustomerAPI::Colors::COLOR_WHITE),
    std::runtime_error
  );
}

TEST(testCustomer, testLastNameTooLong)
{
  EXPECT_THROW(
    CustomerAPI::CUSTOMER("a", tooLong32Chars, "a", "a", CustomerAPI::Colors::COLOR_WHITE),
    std::runtime_error
  );
}

TEST(testCustomer, testZipCodeTooLong)
{
  EXPECT_THROW(
    CustomerAPI::CUSTOMER("a", "a", tooLong8Chars, "a", CustomerAPI::Colors::COLOR_WHITE),
    std::runtime_error
  );
}

TEST(testCustomer, testCityTooLong)
{
  EXPECT_THROW(
    CustomerAPI::CUSTOMER("a", "a", "a", tooLong32Chars, CustomerAPI::Colors::COLOR_WHITE),
    std::runtime_error
  );
}

TEST(testCustomer, testInvalidColor)
{
  EXPECT_THROW(
    CustomerAPI::CUSTOMER("a", "a", "a", "a", CustomerAPI::Colors::LAST_COLOR),
    std::runtime_error
  );
}

TEST(testColors, testColorMapping)
{
  // Enforce color mappings correspond to existing data.
  const int blue = 1;
  const int green = 2;
  const int violet = 3;
  const int red = 4;
  const int yellow = 5;
  const int turquoise = 6;
  const int white = 7;

  ASSERT_EQ(CustomerAPI::Colors::COLOR_BLUE, blue);
  ASSERT_EQ(CustomerAPI::Colors::COLOR_GREEN, green);
  ASSERT_EQ(CustomerAPI::Colors::COLOR_VIOLET, violet);
  ASSERT_EQ(CustomerAPI::Colors::COLOR_RED, red);
  ASSERT_EQ(CustomerAPI::Colors::COLOR_YELLOW, yellow);
  ASSERT_EQ(CustomerAPI::Colors::COLOR_TURQUOISE, turquoise);
  ASSERT_EQ(CustomerAPI::Colors::COLOR_WHITE, white);
}                     