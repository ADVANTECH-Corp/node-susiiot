#include <node.h>
#include <nan.h>
#include "node-SUSIIoT.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;

// NativeExtension.cc represents the top level of the module. 
// C++ constructs that are exposed to javascript are exported here

NAN_MODULE_INIT(Init) {
	NAN_EXPORT(target, getCapability);
	NAN_EXPORT(target, getData);
	NAN_EXPORT(target, setData);
	NAN_EXPORT(target, aString);
}

NODE_MODULE(node_SUSI, Init)
