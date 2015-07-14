#ifndef _COMMON_H_
#define _COMMON_H_

#include "OsDeclarations.h"
#include "SusiIoT.h"
#include <stdlib.h>

#ifndef _MSC_VER
    #define SUSI_IOT_API
    #define SCANF(fmt, input) scanf(fmt, input)
    #define PAUSE() printf("\nPress Enter key to continue..."); fgetc(stdin); fgetc(stdin);  
    #define CLRSCR() system("clear")
#else
    #include <Windows.h>
    #ifndef SUSI_IOT_API
    #define SUSI_IOT_API __stdcall
    #endif
    #define SCANF(fmt, input) scanf_s(fmt, input)
    #define PAUSE() system("pause")
    #define CLRSCR() system("cls")
#endif

#ifdef __cplusplus
extern "C" {
#endif
    #include "jansson.h"

	SusiIoTStatus_t SUSI_IOT_API SusiIoTInitialize(void);
	SusiIoTStatus_t SUSI_IOT_API SusiIoTUninitialize(void);

	SusiIoTStatus_t SUSI_IOT_API SusiIoTGetPFCapability(json_t *capability);
	SusiIoTStatus_t SUSI_IOT_API SusiIoTGetPFData(SusiIoTId_t id, json_t *data);
	SusiIoTStatus_t SUSI_IOT_API SusiIoTSetPFData(json_t *data);

	///* Getter for String */
	char *SUSI_IOT_API SusiIoTGetPFCapabilityString();
	char *SUSI_IOT_API SusiIoTGetPFDataString(SusiIoTId_t id);
	SusiIoTStatus_t SUSI_IOT_API SusiIoTSetPFDataString(char* jsonString);

	///* Data API */
	SusiIoTStatus_t SUSI_IOT_API SusiIoTGetValue(SusiIoTId_t id, json_t *jValue);
	SusiIoTStatus_t SUSI_IOT_API SusiIoTSetValue(SusiIoTId_t id, json_t *jValue);

	/* Memory API */
	SusiIoTStatus_t SUSI_IOT_API SusiIoTMemFree(void *address);

    /* Capability Probe & Data Getter/Setter */
	typedef void (SUSI_IOT_API *SUSI_IOT_EVENT_CALLBACK) (SusiIoTId_t id, char *jsonstr);
	SusiIoTStatus_t SUSI_IOT_API SusiIoTSetPFEventHandler(SUSI_IOT_EVENT_CALLBACK eventCallbackFun);

	SusiIoTStatus_t SUSI_IOT_API SusiIoTLogger(bool enabled);
	bool SUSI_IOT_API SusiIoTGetLoggerStatus();
	char *SUSI_IOT_API SusiIoTGetLoggerPath();

#ifdef __cplusplus
}
#endif

#endif /* _COMMON_H_ */
