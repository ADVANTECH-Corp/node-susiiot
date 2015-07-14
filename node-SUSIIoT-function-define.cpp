#include <node.h>
#include <nan.h>
#include "node-SUSIIoT.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;

// NativeExtension.cc represents the top level of the module. 
// C++ constructs that are exposed to javascript are exported here

void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("getCapability"),
    NanNew<FunctionTemplate>(getCapability)->GetFunction());
  exports->Set(NanNew<String>("getData"),
    NanNew<FunctionTemplate>(getData)->GetFunction());
  exports->Set(NanNew<String>("setData"),
    NanNew<FunctionTemplate>(setData)->GetFunction());
  exports->Set(NanNew<String>("aString"),
    NanNew<FunctionTemplate>(aString)->GetFunction());

}

NODE_MODULE(node_SUSIIoT, InitAll)
