#include "pch.h"
#include "Customer.h"

#include <iostream>
#include <sstream>

namespace CustomerAPI
{
  std::string colorToString(Colors color)
  {
    switch (color)
    {
    case Colors::COLOR_BLUE:
      return "blue";
    case Colors::COLOR_GREEN:
      return "green";
    case Colors::COLOR_VIOLET:
      return "violet";
    case Colors::COLOR_RED:
      return "red";
    case Colors::COLOR_YELLOW:
      return "yellow";
    case Colors::COLOR_TURQUOISE:
      return "turquoise";
    case Colors::COLOR_WHITE:
      return "white";
    default: // Unknown.
      return "unknown color";
    }

  }

  std::ostream& operator<<(std::ostream& os, CUSTOMER& customer)
  {
    std::stringstream ss;
    ss << "ID: " << customer.id << ", first name: " << customer.first_name << ", last name: " << customer.last_name << ", zip code: " <<
      customer.zip_code << ", city: " << customer.city << ", color: " << colorToString(customer.favorite_color);

    return os << ss.str();
  }

  std::istream& operator>>(std::istream& is, CUSTOMER& outCustomer)
  {
    // TODO: read from stream.
    return is;
  }

  CUSTOMER::CUSTOMER(const std::string& firstName, 
                     const std::string& lastName, 
                     const std::string& zipCode, 
                     const std::string& city, 
                     Colors favoriteColor)
    :
    favorite_color(favoriteColor)
  {
    // Enforce string max. lengths, including terminators.
    if (firstName[firstName.size()] != '\0')
    {
      if (firstName.size() > 23)
        throw std::runtime_error("Invalid first name: " + firstName + ", length: " + std::to_string(firstName.size()) + " / 24");

      first_name = firstName + '\0';
    }
    else
    {
      first_name = firstName;
    }

    if (lastName[lastName.size()] != '0')
    {
      if (lastName.size() > 31)
        throw std::runtime_error("Invalid last name: " + lastName + ", length: " + std::to_string(lastName.size()) + " / 32");

      last_name = lastName + '\0';
    }
    else
    {
      last_name = lastName;
    }

    if (zipCode[zipCode.size()] != '\0')
    {
      if (zipCode.size() > 7)
        throw std::runtime_error("Invalid zip code: " + zipCode + ", length: " + std::to_string(zipCode.size()) + " / 8");

      zip_code = zipCode + '\0';
    }
    else
    {
      zip_code = zipCode;
    }

    if (city[city.size()] != '\0')
    {
      if (city.size() > 31)
        throw std::runtime_error("Invalid city name: " + city + ", length: " + std::to_string(city.size()) + " / 32");

      this->city = city + '\0';
    }
    else
    {
      this->city = city;
    }
  }

} // CustomerDatabase