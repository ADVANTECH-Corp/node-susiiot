#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>

// Example top-level functions. These functions demonstrate how to return various js types.
// Implementations are in functions.cc

NAN_METHOD(getCapability);
NAN_METHOD(getData);
NAN_METHOD(setData);
NAN_METHOD(aString);

#endif
