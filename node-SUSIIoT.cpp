#include <nan.h>
#include "node-SUSIIoT.h"
#include "common.h"

static SusiIoTStatus_t status = SUSIIOT_STATUS_NOT_INITIALIZED;
NAN_METHOD(getCapability) {
    Nan::HandleScope scope;
	if (status != SUSIIOT_STATUS_SUCCESS)
	{
		if((status = SusiIoTInitialize()) != SUSIIOT_STATUS_SUCCESS)
		{
			info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());
		}
	}

	char * buffer = SusiIoTGetPFCapabilityString();
	if (buffer == (void *)0)
	{
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiIoTGetPFCapabilityString() failed.").ToLocalChecked());
	}
	
	v8::Local<v8::String> capabilityStr = Nan::New<v8::String>(buffer).ToLocalChecked();
	//NanUtf8String *capabilityStr = new NanUtf8String(buffer);
    SusiIoTMemFree((void *)buffer);

    info.GetReturnValue().Set(capabilityStr);
}

NAN_METHOD(getData) {
    Nan::HandleScope scope;
	if (status != SUSIIOT_STATUS_SUCCESS)
	{
		if((status = SusiIoTInitialize()) != SUSIIOT_STATUS_SUCCESS)
		{
			info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());
		}
	}
	
	uint32_t offset = 0;
	if (info.Length() == 1)
		offset = info[0]->Uint32Value();

	char * buffer = SusiIoTGetPFDataString(offset);
	if (buffer == (void *)0)
	{
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiIoTGetPFCapabilityString() failed.").ToLocalChecked());
	}
	//In Node v0.10, you write: 
	//v8::Local<v8::String> dataStr = v8::String::New(buffer);
	//In Node v0.12, you write:
	//v8::Isolate* isolate = v8::Isolate::GetCurrent();;
	//v8::Local<v8::String> dataStr = v8::String::NewFromUtf8(isolate, buffer);
	//Use Nan support
	v8::Local<v8::String> dataStr = Nan::New<v8::String>(buffer).ToLocalChecked();
	
    SusiIoTMemFree((void *)buffer);

    info.GetReturnValue().Set(dataStr);
}


NAN_METHOD(setData) {
    Nan::HandleScope scope;

	if (status != SUSIIOT_STATUS_SUCCESS)
	{
		if((status = SusiIoTInitialize()) != SUSIIOT_STATUS_SUCCESS)
		{
			info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());
		}
	}
	
	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiIoT: No IoT parameter!").ToLocalChecked());
	
	v8::String::Utf8Value baz(info[0]);
	if (SusiIoTSetPFDataString(*baz) != SUSIIOT_STATUS_SUCCESS)
	{
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiIoTSetPFDataString() failed.").ToLocalChecked());
	}

    info.GetReturnValue().Set(Nan::New<v8::String>("SusiIoTSetPFDataString() Successful.").ToLocalChecked());
}

NAN_METHOD(aString) {
    Nan::HandleScope scope;
    info.GetReturnValue().Set(Nan::New<v8::String>("This is a thing.").ToLocalChecked());
}

