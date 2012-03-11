#ifndef TOS_H
#define TOS_H

#include <windows.h>
#include <winbase.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <process.h>
#include <time.h>
#include <.\sys\types.h>
#include <.\sys\timeb.h>



#ifdef EXP2DF
	#undef EXP2DF
#endif

#ifdef CNCAPI_EXPORTS
#define EXP2DF __declspec(dllexport)
#else
#define EXP2DF __declspec(dllimport)
#endif


#define	TOS_MAX_COMMAND_LINE		MAX_PATH
#define TOS_MAX_ARGUMENTS           20
#define TOS_MAX_SHARED_MEM          100
#define TOS_MAX_MAILBOXES			100
#define TOS_MAX_MAILBOX_MESSAGES	255
#define TOS_MAX_NAME_LENGTH			MAX_PATH    /* Target os max name length */
#define TOS_INDEFINITE_WAIT			INFINITE
#define TOS_IMMEDIATE_RETURN		0
#define MSEC_PER_TICK				15
#define TOS_NO_MBXID                ((TOS_MBXID)0xFFFFFFFF)
#define TOS_NO_SEMID                ((TOS_SEMID)0xFFFFFFFF)
#define TOS_NO_MEMPTR               ((void *)0x0)
#define TOS_NO_PROCESSID            ((TOS_PROCESSID)0x0) //OxFFFFFFFF is a valid pid in windows!
#define TOS_USED					1
#define TOS_FREE					0


typedef HANDLE  TOS_EVENT_HANDLE;
typedef HANDLE  TOS_MUTEX_HANDLE;
typedef HANDLE  TOS_SEMAPHORE_HANDLE;
typedef DWORD   TOS_PROCESSID;
typedef char   *TOS_PROCESS_ENTRY;  /* name of process */
typedef int     TOS_MBXID;

typedef struct TOS_THREADID
{
	HANDLE m_hThread;
	DWORD  m_threadId;

} TOS_THREADID;

typedef DWORD (__stdcall *TOS_TASK_ENTRY)(void * lpThreadParameter);


#define TOS_THREAD_PRIORITY_BELOW_NORMAL	THREAD_PRIORITY_BELOW_NORMAL
#define TOS_THREAD_PRIORITY_NORMAL			THREAD_PRIORITY_NORMAL
#define TOS_THREAD_PRIORITY_ABOVE_NORMAL	THREAD_PRIORITY_ABOVE_NORMAL
#define TOS_THREAD_PRIORITY_HIGH			THREAD_PRIORITY_HIGHEST
#define TOS_THREAD_PRIORITY_TIME_CRITICAL   THREAD_PRIORITY_TIME_CRITICAL


typedef enum
{
    TOS_NO_ERROR         = WAIT_OBJECT_0,
    TOS_ALREADY_EXISTING,
    TOS_TIMEOUT          = WAIT_TIMEOUT,
    TOS_ERROR_INTERRUPT,
    TOS_ERROR,
    TOS_ABANDONED        = WAIT_ABANDONED,
    TOS_WRONG_SIZE,
    TOS_NO_MEM,
    TOS_INVALID_NAME,
    TOS_RESOURCE_FINISHED,
    TOS_MBX_FULL,
	TOS_MBX_EMPTY,
	TOS_INVALID_ID,
	TOS_MESSAGE_TOO_LONG
} TOS_RET;

typedef enum
{
    TOS_PP_IDLE,
    TOS_PP_NORMAL,
    TOS_PP_HIGH,
    TOS_PP_REALTIME
} TOS_PROCESS_PRIORITY;

typedef enum 
{
	TOS_PM_DETACHED,
	TOS_PM_NEW_CONSOLE,
	TOS_PM_NORMAL
} TOS_PROCESS_MODE;

#ifdef __cplusplus
extern "C" {
#endif


//TosInit should be called before any other Tos functionality
//TosTerm when the process ends
extern TOS_RET EXP2DF __stdcall TosInit(void);
extern TOS_RET EXP2DF __stdcall TosTerm(void);

//Mutex, use NULL for unnamed 
extern TOS_RET EXP2DF __stdcall TosOpenMutex (char *name, TOS_MUTEX_HANDLE *handle);
extern TOS_RET EXP2DF __stdcall TosCloseMutex (TOS_MUTEX_HANDLE handle);
extern TOS_RET EXP2DF __stdcall TosRequestMutex (TOS_MUTEX_HANDLE handle,unsigned long timeOut);
extern TOS_RET EXP2DF __stdcall TosReleaseMutex (TOS_MUTEX_HANDLE handle);

//Events, default not set
extern TOS_RET EXP2DF __stdcall TosOpenEvent (char *name, TOS_EVENT_HANDLE *handle);
extern TOS_RET EXP2DF __stdcall TosCloseEvent (TOS_EVENT_HANDLE handle);
extern TOS_RET EXP2DF __stdcall TosWaitEvent (TOS_EVENT_HANDLE handle, unsigned long timeOut);
extern TOS_RET EXP2DF __stdcall TosSetEvent (TOS_EVENT_HANDLE handle);
extern TOS_RET EXP2DF __stdcall TosResetEvent (TOS_EVENT_HANDLE handle);

//Counting semaphores, use NULL for unnamed semaphores
extern TOS_RET EXP2DF __stdcall TosOpenSemaphore (char *name, int count, TOS_SEMAPHORE_HANDLE *handle);
extern TOS_RET EXP2DF __stdcall TosCloseSemaphore (TOS_SEMAPHORE_HANDLE handle);
extern TOS_RET EXP2DF __stdcall TosRequestSemaphore (TOS_SEMAPHORE_HANDLE handle,unsigned long timeOut);
extern TOS_RET EXP2DF __stdcall TosReleaseSemaphore (TOS_SEMAPHORE_HANDLE handle);

//Named shared memory
extern TOS_RET EXP2DF __stdcall TosOpenSharedMemory (void **ppvoidSharedMemory,
							unsigned long size,
							char *name);
extern TOS_RET EXP2DF __stdcall TosCloseSharedMemory (void *pvoidSharedMemory);


//Mailboxes
extern TOS_RET EXP2DF __stdcall TosOpenMbx (char *pszMbxName, unsigned long ulSize, TOS_MBXID *pMbxId);
extern TOS_RET EXP2DF __stdcall TosCloseMbx (TOS_MBXID mbxId);
extern TOS_RET EXP2DF __stdcall TosReadMbx (TOS_MBXID mbxId, unsigned long ulMaxMsgSize,
                    double dTimeOutPeriod, char *pszMessage,
                    unsigned long *pulActualMsgSize);
extern TOS_RET EXP2DF __stdcall TosWriteMbx (TOS_MBXID mbxId, char *pszMessage, unsigned long ulMsgSize);

//Process/Thread functionality
extern TOS_RET EXP2DF __stdcall TosCreateThread(TOS_TASK_ENTRY taskEntry, void *taskParameter, TOS_THREADID *pThreadId);
extern void EXP2DF __stdcall TosSetThreadPriority(TOS_THREADID *pTrhreadId, int priority);

extern TOS_PROCESSID EXP2DF __stdcall TosGetCurrentProcessId (void);
extern TOS_RET EXP2DF __stdcall TosCreateProcess (TOS_PROCESS_ENTRY tosProcessEntry, 
                          int iNumberOfParameters,
                          char *szProcessParameters[], 
						  TOS_PROCESS_MODE mode,
						  TOS_PROCESS_PRIORITY priority,
						  TOS_PROCESSID *pProcessId);
extern TOS_RET EXP2DF __stdcall TosCreateProcess2 (TOS_PROCESS_ENTRY vosProcessEntry,
                           char commandLine[],
						   TOS_PROCESS_MODE mode,
						   TOS_PROCESS_PRIORITY priority,
                           TOS_PROCESSID *pProcessId);
extern TOS_RET EXP2DF __stdcall TosDeleteProcess (TOS_PROCESSID tosProcessId);
extern TOS_RET EXP2DF __stdcall TosGetProcessId (TOS_PROCESSID *pProcessId);
extern TOS_RET EXP2DF __stdcall TosWaitProcess (TOS_PROCESSID tosProcessId, unsigned long timeOut);
extern TOS_RET EXP2DF __stdcall TosSetProcessPriority (TOS_PROCESSID processId, TOS_PROCESS_PRIORITY priority);
extern TOS_RET EXP2DF __stdcall TosGetProcessPriority (TOS_PROCESSID processId, TOS_PROCESS_PRIORITY *priority);
extern BOOL EXP2DF    __stdcall TosIsElevatedAdministrator (HANDLE hInputToken); 


//Sleep milliseconds
extern TOS_RET EXP2DF __stdcall TosSleep (unsigned long time);

#ifdef __cplusplus
}
#endif


#endif //defined TOS_H

