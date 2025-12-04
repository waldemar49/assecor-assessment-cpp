#pragma once

#ifdef CUSTOMERAPI_EXPORTS
#define CUSTOMERAPI __declspec(dllexport)
#else
#define CUSTOMERAPI __declspec(dllimport)
#endif