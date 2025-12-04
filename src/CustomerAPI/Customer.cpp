#include "pch.h"
#include "customer.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

namespace CustomerAPI
{
  const std::string blueStr = "blue";
  const std::string greenStr = "green";
  const std::string violetStr = "violet";
  const std::string redStr = "red";
  const std::string yellowStr = "yellow";
  const std::string turquoiseStr = "turquoise";
  const std::string whiteStr = "white";

  CUSTOMERAPI std::string colorToString(Colors color)
  {
    switch (color)
    {
    case Colors::COLOR_BLUE:
      return blueStr;
    case Colors::COLOR_GREEN:
      return greenStr;
    case Colors::COLOR_VIOLET:
      return violetStr;
    case Colors::COLOR_RED:
      return redStr;
    case Colors::COLOR_YELLOW:
      return yellowStr;
    case Colors::COLOR_TURQUOISE:
      return turquoiseStr;
    case Colors::COLOR_WHITE:
      return whiteStr;
    default: // Unknown.
      return "unknown color";
    }

  }

  CUSTOMERAPI Colors stringToColor(std::string colorStr)
  {
    std::transform(colorStr.begin(), colorStr.end(), colorStr.begin(), [](unsigned char c) { return std::tolower(c); });

    if (colorStr == blueStr)
      return Colors::COLOR_BLUE;
    else if (colorStr == greenStr)
      return Colors::COLOR_GREEN;
    else if (colorStr == violetStr)
      return Colors::COLOR_VIOLET;
    else if (colorStr == redStr)
      return Colors::COLOR_RED;
    else if (colorStr == yellowStr)
      return Colors::COLOR_YELLOW;
    else if (colorStr == turquoiseStr)
      return Colors::COLOR_TURQUOISE;
    else if (colorStr == whiteStr)
      return Colors::COLOR_WHITE;

    return Colors::LAST_COLOR; // Unknown color.
  }

  CUSTOMER::CUSTOMER(const std::string& firstName, 
                     const std::string& lastName, 
                     const std::string& zipCode, 
                     const std::string& city, 
                     Colors favoriteColor,
                     int id)
    :
    id(id),
    first_name(firstName),
    last_name(lastName),
    zip_code(zipCode),
    city(city),
    favorite_color(favoriteColor)
  {
    // Enforce string max. lengths, including terminators.
    if (firstName.size() > 23)
      throw std::runtime_error("first name is too long: " + firstName + ", length: " + std::to_string(firstName.size()) + " / 23 characters");

    if (lastName.size() > 31)
      throw std::runtime_error("last name is too long: " + lastName + ", length: " + std::to_string(lastName.size()) + " / 31 characters");

    if (zipCode.size() > 7)
      throw std::runtime_error("zip code is too long: " + zipCode + ", length: " + std::to_string(zipCode.size()) + " / 7 characters");

    if (city.size() > 31)
      throw std::runtime_error("city name is too long: " + city + ", length: " + std::to_string(city.size()) + " / 31 characters");

    if (favorite_color == Colors::LAST_COLOR)
      throw std::runtime_error("an invalid color was passed (LAST_COLOR)");
  }

} // CustomerDatabase