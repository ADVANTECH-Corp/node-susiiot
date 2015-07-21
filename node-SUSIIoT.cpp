#include <nan.h>
#include "node-SUSIIoT.h"
#include "common.h"

static SusiIoTStatus_t status = SUSIIOT_STATUS_NOT_INITIALIZED;
NAN_METHOD(getCapability) {
    NanScope();

	if (status != SUSIIOT_STATUS_SUCCESS)
	{
		if((status = SusiIoTInitialize()) != SUSIIOT_STATUS_SUCCESS)
		{
			NanReturnValue(NanNew<v8::String>("SusiIoTInitialize() failed."));
		}
	}

	char * buffer = SusiIoTGetPFCapabilityString();
	if (buffer == (void *)0)
	{
		NanReturnValue(NanNew<v8::String>("SusiIoTGetPFCapabilityString() failed."));
	}
	
	v8::Local<v8::String> capabilityStr = NanNew<v8::String>(buffer);
	//NanUtf8String *capabilityStr = new NanUtf8String(buffer);
    SusiIoTMemFree((void *)buffer);

    NanReturnValue(capabilityStr);
}

NAN_METHOD(getData) {
    NanScope();

	if (status != SUSIIOT_STATUS_SUCCESS)
	{
		if((status = SusiIoTInitialize()) != SUSIIOT_STATUS_SUCCESS)
		{
			NanReturnValue(NanNew<v8::String>("SusiIoTInitialize() failed."));
		}
	}
	
	uint32_t offset = 0;
	if (args.Length() == 1)
		offset = args[0]->Uint32Value();

	char * buffer = SusiIoTGetPFDataString(offset);
	if (buffer == (void *)0)
	{
		NanReturnValue(NanNew<v8::String>("SusiIoTGetPFCapabilityString() failed."));
	}
	//In Node v0.10, you write: 
	//v8::Local<v8::String> dataStr = v8::String::New(buffer);
	//In Node v0.12, you write:
	//v8::Isolate* isolate = v8::Isolate::GetCurrent();;
	//v8::Local<v8::String> dataStr = v8::String::NewFromUtf8(isolate, buffer);
	//Use Nan support
	v8::Local<v8::String> dataStr = NanNew<v8::String>(buffer);
	
    SusiIoTMemFree((void *)buffer);

    NanReturnValue(dataStr);
}


NAN_METHOD(setData) {
    NanScope();

	if (status != SUSIIOT_STATUS_SUCCESS)
	{
		if((status = SusiIoTInitialize()) != SUSIIOT_STATUS_SUCCESS)
		{
			NanReturnValue(NanNew<v8::String>("SusiIoTInitialize() failed."));
		}
	}
	
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("SusiIoT: No IoT parameter!"));
	
	NanUtf8String baz(args[0]);
	if (SusiIoTSetPFDataString(*baz) != SUSIIOT_STATUS_SUCCESS)
	{
		NanReturnValue(NanNew<v8::String>("SusiIoTSetPFDataString() failed."));
	}

    NanReturnValue(NanNew<v8::String>("SusiIoTSetPFDataString() Successful."));
}

NAN_METHOD(aString) {
    NanScope();
    NanReturnValue(NanNew<v8::String>("This is a thing."));
}

