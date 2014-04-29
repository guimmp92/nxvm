/* Copyright 2012-2014 Neko. */

#ifndef NXVM_UTILS_H
#define NXVM_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "global.h"

/* Code Tracer */
typedef struct {
	char* blockstack[0x100];
	int bid;
	int cid;
} t_utils_trace_block;
typedef struct {
	t_utils_trace_block callstack[0x100];
	int cid;
	int flagerror;
} t_utils_trace_call;

#define UTILS_TRACE_DEBUG 0

void utilsTracePrintCall(t_utils_trace_call *rtrace, int cid);
void utilsTracePrintCallStack(t_utils_trace_call *rtrace);
void utilsTraceInit(t_utils_trace_call *rtrace);
void utilsTraceFinal(t_utils_trace_call *rtrace);
void utilsTraceCallBegin(t_utils_trace_call *rtrace, char *s);
void utilsTraceCallEnd(t_utils_trace_call *rtrace);
void utilsTraceBlockBegin(t_utils_trace_call *rtrace, char *s);
void utilsTraceBlockEnd(t_utils_trace_call *rtrace);

/* Standard C Library */
struct tm* LOCALTIME(const time_t *_Time);
char* STRCAT(char *_Dest, const char *_Source);
char* STRCPY(char *_Dest, const char *_Source);
char* STRTOK(char *_Str, const char *_Delim);
int   STRCMP(const char *_Str1, const char *_Str2);
int   SPRINTF(char *_Dest, const char *_Format, ...);
FILE* FOPEN(const char *_Filename, const char *_Mode);
char* FGETS(char *_Buf, int _MaxCount, FILE *_File);

/* NXVM Library */
void utilsSleep(unsigned int milisec);
void utilsLowerStr(char *s);
int utilsPrint(const char *format, ...);

/* NXVM Assembler Library */
unsigned char utilsAasm32(const char *stmt, unsigned char *rcode, unsigned char flag32);
unsigned int utilsAasm32x(const char *stmt, unsigned char *rcode, unsigned char flag32);
unsigned char utilsDasm32(char *stmt, unsigned char *rcode, unsigned char flag32);

#ifdef __cplusplus
}/*_EOCD_*/
#endif

#endif