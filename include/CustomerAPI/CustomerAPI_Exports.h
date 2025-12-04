#pragma once

#define no_init_all deprecated // Some visual studio bug.

#ifdef CUSTOMERAPI_EXPORTS
#define CUSTOMERAPI __declspec(dllexport)
#else
#define CUSTOMERAPI __declspec(dllimport)
#endif