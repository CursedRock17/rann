#ifndef RANN__VISIBILITY_CONTROL_H_
#define RANN__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define RANN_EXPORT __attribute__ ((dllexport))
    #define RANN_IMPORT __attribute__ ((dllimport))
  #else
    #define RANN_EXPORT __declspec(dllexport)
    #define RANN_IMPORT __declspec(dllimport)
  #endif
  #ifdef RANN_BUILDING_LIBRARY
    #define RANN_PUBLIC RANN_EXPORT
  #else
    #define RANN_PUBLIC RANN_IMPORT
  #endif
  #define RANN_PUBLIC_TYPE RANN_PUBLIC
  #define RANN_LOCAL
#else
  #define RANN_EXPORT __attribute__ ((visibility("default")))
  #define RANN_IMPORT
  #if __GNUC__ >= 4
    #define RANN_PUBLIC __attribute__ ((visibility("default")))
    #define RANN_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define RANN_PUBLIC
    #define RANN_LOCAL
  #endif
  #define RANN_PUBLIC_TYPE
#endif

#endif  // RANN__VISIBILITY_CONTROL_H_
