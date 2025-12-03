#pragma once

#ifdef CUSTOMERAPI_EXPORTS
#define CUSTOMERAPI __declspec(dllexport)
#else
#define CUSTOMERAPI __declspec(dllimport)
#endif

#include <string>

namespace CustomerAPI
{

  // Keep naming convention for easier reintegration.

  // Use enum instead of enum class to allow implicit casts, if required.
  enum CUSTOMERAPI Colors : int
  {
    // Hard coded values to keep compatibility with old definitions.
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_VIOLET = 3,
    COLOR_RED = 4,
    COLOR_YELLOW = 5,
    COLOR_TURQUOISE = 6,
    COLOR_WHITE = 7,

    LAST_COLOR // Must always be last.
  };

  /**
   * @brief Returns a string representation correspoding Colors enum.
   * @param color The Colors enum to get a string representation for.
   * @return The string representation of the given Colors enum.
   */
  CUSTOMERAPI inline std::string colorToString(Colors color);
  /**
   * @brief Returns the color to a corresponding string.
   * @param colorStr The string to find the color for, we copy the string, since we will transform it to lower case.
   * @return A Colors enum.
   */
  CUSTOMERAPI inline Colors stringToColor(std::string colorStr);

  struct CUSTOMER
  {
    
  public:

    // Throwing constructor to enforce compatibility, a factory method might be preferrable under certain circumstances.
    CUSTOMERAPI CUSTOMER(const std::string& firstName,
                         const std::string& lastName,
                         const std::string& zipCode,
                         const std::string& city,
                         Colors favoriteColor);

    int id = -1;
    
    std::string first_name; // Max. 24 chars including terminator.
    std::string last_name; // Max. 32 chars including terminator.
    std::string zip_code; // Max. 8 chars including terminator.
    std::string city; // Max. 32 chars including terminator.

    Colors favorite_color;

  };

  CUSTOMERAPI inline std::ostream& operator<<(std::ostream& os, const CUSTOMER& customer);
  CUSTOMERAPI inline std::istream& operator>>(std::istream& is, CUSTOMER& outCustomer);

} // CustomerDatabase