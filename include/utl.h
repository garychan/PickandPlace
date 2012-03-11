#ifndef UTL_H_INCLUDED
#define UTL_H_INCLUDED

#include "cnc_types.h"

#ifdef EXP2DF
#undef EXP2DF
#endif

#ifdef CNCAPI_EXPORTS
#define EXP2DF __declspec(dllexport)
#else
#define EXP2DF __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C" {
#endif

//Initialize-Terminate helper module,
void EXP2DF __stdcall UtlInit(void);
void EXP2DF __stdcall UtlTerm(void);

//Logging macro
#define UTL_LOG(functionName, errorClass, code) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, 0,  NULL) 

#define UTL_LOG_P0(functionName, errorClass, code, fmt) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, 0, fmt)

#define UTL_LOG_P1(functionName, errorClass, code, fmt, p1) \
    /*lint -e534*/UtlLog(functionName,  __FILE__, __LINE__, errorClass, code, 0, fmt, p1)

#define UTL_LOG_P2(functionName, errorClass, code, fmt, p1, p2) \
    /*lint -e534*/UtlLog(functionName,  __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2)

#define UTL_LOG_P3(functionName, errorClass, code, fmt, p1, p2, p3) \
    /*lint -e534*/UtlLog(functionName,  __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3)

#define UTL_LOG_P4(functionName, errorClass, code, fmt, p1, p2, p3, p4) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3, p4)

#define UTL_LOG_P5(functionName, errorClass, code, fmt, p1, p2, p3, p4, p5) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3, p4, p5)

#define UTL_LOG_P6(functionName, errorClass, code, fmt, p1, p2, p3, p4, p5, p6) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3, p4, p5, p6)

#define UTL_LOG_VA(functionName, errorClass, code, fmt, ...) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, __VA_ARGS__)

//Logging macro
#define UTL_LOG_S(functionName, errorClass, code, subCode) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, subCode,  NULL) 

#define UTL_LOG_S_P0(functionName, errorClass, code, subcode,  fmt) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, subCode, fmt)

#define UTL_LOG_S_P1(functionName, errorClass, code, subcode, fmt, p1) \
    /*lint -e534*/UtlLog(functionName,  __FILE__, __LINE__, errorClass, code, subCode, fmt, p1)

#define UTL_LOG_S_P2(functionName, errorClass, code, subcode, fmt, p1, p2) \
    /*lint -e534*/UtlLog(functionName,  __FILE__, __LINE__, errorClass, code, subCode, fmt, p1, p2)

#define UTL_LOG_S_P3(functionName, errorClass, code, subcode, fmt, p1, p2, p3) \
    /*lint -e534*/UtlLog(functionName,  __FILE__, __LINE__, errorClass, code, subCode, fmt, p1, p2, p3)

#define UTL_LOG_S_P4(functionName, errorClass, code, subcode, fmt, p1, p2, p3, p4) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, subCode, fmt, p1, p2, p3, p4)

#define UTL_LOG_S_P5(functionName, errorClass, code, subcode, fmt, p1, p2, p3, p4, p5) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, subCode, fmt, p1, p2, p3, p4, p5)

#define UTL_LOG_S_P6(functionName, errorClass, code, subcode, fmt, p1, p2, p3, p4, p5, p6) \
    /*lint -e534*/UtlLog(functionName, __FILE__, __LINE__, errorClass, code, subCode, fmt, p1, p2, p3, p4, p5, p6)



//Tracing macros, the higher the level, the more detail information
#ifndef TSL_SKIP_TRACING


#define UTL_TL_MAIN 0x1
#define UTL_TL_CMD  0x2
#define UTL_TL_INT  0x4
#define UTL_TL_EXE  0x8
#define UTL_TL_TRG  0x10
#define UTL_TL_TRG1 0x20
#define UTL_TL_TRG2 0x40
#define UTL_TL_TRG3 0x80


#define UTL_TRACE(functionName, l) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, NULL); }

#define UTL_TRACE0(functionName, l, fmt) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt); }

#define UTL_TRACE1(functionName, l, fmt, p1) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1); }

#define UTL_TRACE2(functionName, l, fmt, p1, p2) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2); }

#define UTL_TRACE3(functionName, l, fmt, p1, p2, p3) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3); }

#define UTL_TRACE4(functionName, l, fmt, p1, p2, p3, p4) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4); }

#define UTL_TRACE5(functionName, l, fmt, p1, p2, p3, p4, p5) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5); }

#define UTL_TRACE6(functionName, l, fmt, p1, p2, p3, p4, p5, p6) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6); }

#define UTL_TRACE7(functionName, l, fmt, p1, p2, p3, p4, p5, p6, p7) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6, p7); }

#define UTL_TRACE8(functionName, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8); }

#define UTL_TRACE9(functionName, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9); }

#else

/* Set macros to empty if TSL_SKIP_TRACEGING is defined */

#define UTL_TRACE0(functionName, fmt)
#define UTL_TRACE1(functionName, fmt, p1)
#define UTL_TRACE2(functionName, fmt, p1, p2)
#define UTL_TRACE3(functionName, fmt, p1, p2, p3)
#define UTL_TRACE4(functionName, fmt, p1, p2, p3, p4)
#define UTL_TRACE5(functionName, fmt, p1, p2, p3, p4, p5)
#define UTL_TRACE6(functionName, fmt, p1, p2, p3, p4, p5, p6)
#define UTL_TRACE7(functionName, fmt, p1, p2, p3, p4, p5, p6, p7)
#define UTL_TRACE8(functionName, fmt, p1, p2, p3, p4, p5, p6, p7, p8)
#define UTL_TRACE9(functionName, fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9)

#endif



//Assert macro, remain looping until assert function returns FALSE
#define UTL_ASSERT(exp) {UtlAssert((exp), #exp, __FILE__, __LINE__)/*lint -i 722*/;}

//Assert
BOOL EXP2DF __stdcall UtlAssert(int expression, void *expressionText, void *file, unsigned line);

//Log infos warnings errors for user
void UtlLog(char            *functionName,  /* name of the function that caused the error */
            char            *file,          /* the c-file name where the code resides     */
            LONG             line,          /* the offending line number                  */
            CNC_ERROR_CLASS  errorClass,     /* PS error class                            */
            CNC_RC           error,          /* PS error code                             */
            LONG             subCode,       /* error subcode                              */
            char            *fmt, ...);     /* optional text aruments                     */


//Trace function
void UtlTrace(char   *functionName, /* name of the function that caused the error */
              char   *file,         /* the c-file name where the code resides     */
              int    line,          /* the offending line number                  */
              int    level,
              char   *fmt, ...);    /* optional text aruments                     */

void UtlOpenTraceFile(void);

void UtlCloseTraceFile(void);

void UtlTraceFile( bool includeTimeStamp, char *fmt, ...);

void UtlFlushTraceFile(void);


void __stdcall UtlSetTraceLevel(int level);


//Start timer
void EXP2DF __stdcall UtlStartTimer(CNC_TIME_STAMP *pTimeStamp);


//Get elapsed time and reset
double EXP2DF __stdcall UtlStopTimer(CNC_TIME_STAMP *timeStamp);

//Get elapsed time 
double EXP2DF __stdcall UtlTimerElapse(CNC_TIME_STAMP *timeStamp);


//Check expiration of timer
BOOL EXP2DF __stdcall UtlIsTimerExpired(CNC_TIME_STAMP *timeStamp,
                             double duration, 
                             double *pSecondsSinceStart);

//Read parameter from INI file and log eventual errors
//File must be opened and closed using these functions
FILE EXP2DF * _stdcall UtlIniOpenFile(char *fileName, char *openAttributes);

int EXP2DF _stdcall UtlIniCloseFile(FILE *fp);

void EXP2DF __stdcall UtlIniSetLogging(int on);

CNC_RC EXP2DF __stdcall UtlIniReadRealParameter(char * fileName, FILE *fp, 
                               char *parameter, char *section, 
                               double *parValue);

//Read parameter from INI file and log eventual errors
CNC_RC EXP2DF __stdcall UtlIniReadStringParameter(char * fileName, FILE *fp, 
                                 char *parameter, char *section, 
                                 char *parValue, int maxLen);

//Read parameter from INI file and log eventual errors
CNC_RC EXP2DF __stdcall UtlIniReadIntParameter(char * fileName, FILE *fp, 
                              char *parameter, char *section, 
                              int  *parValue);

//Read parameter from INI file and log eventual errors
CNC_RC EXP2DF __stdcall UtlIniReadBoolParameter(char * fileName, FILE *fp, 
                               char *parameter, char *section, 
                               BOOL  *parValue);


//Remove path from filename
char EXP2DF * __stdcall UtlStripName( char *fileName );

//Case insensitive string compare
int EXP2DF __stdcall UtlStriCmp(const char *anyCase, const char *lowerCase);

//Case insensitive string compare
int EXP2DF __stdcall UtlStrniCmp(const char *anyCase, const char *lowerCase, size_t count);


//Translate CNC_IO_ID to string
char EXP2DF * __stdcall UtlGetIOString(CNC_IO_ID ioId );

#ifdef __cplusplus
}
#endif


#endif //UTL_H_INCLUDED

