#ifndef __CNCAPI__H__
#define __CNCAPI__H__

#ifdef EXP2DF
	#undef EXP2DF
#endif

#ifdef CNCAPI_EXPORTS
	#define EXP2DF __declspec(dllexport)
#else
	#define EXP2DF __declspec(dllimport)
#endif

#include "cnc_types.h"
#include "CncLang.h"
#include "Tos.h"
#include "utl.h"

#ifdef __cplusplus
extern "C" {
#endif

/*************************************************************************/
/*                         Configuration items                           */
/*************************************************************************/

/*
 * Name   : CncGetControllerFirmwareVersion
 * In     : char pointer to array of CNC_MAX_NAME_LENGTH size
 * Out    : the PIC firmware version string
 * Return : -
 */
 char EXP2DF * __stdcall CncGetControllerFirmwareVersion(void);

 /*
 * Name   : CncGetFirmwareHasOptions
 * In     : -
 * Out    : -
 * Return : 0=no options, 1=options available
 * Descr  : Check to see if option dialog in GUI is needed.
 */
 int EXP2DF __stdcall CncGetFirmwareHasOptions(void);

/*
* Name   : CncChangeLanguage
* In     : rc
* Out    : -
* Return : Change language of cncserver
*/
CNC_RC EXP2DF __stdcall CncChangeLanguage(CNC_LANG_T newLanguage);

/*
* Name   : CncExportLanguage
* In     : rc
* Out    : -
* Return : Export language of cncserver to CncServerLang-Export.txt
*/
CNC_RC EXP2DF __stdcall CncExportLanguage(void);

/*
* Name   : CncGetConfig
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : 
*/
 CNC_MACHINE_CONFIG EXP2DF * __stdcall CncGetConfig(void);



/*
* Name   : CncGetMachineType
* In     : -
* Out    : -
* Return : 0=milling, 1=turning
* Descr  : 
*/
 CNC_MACHINE_TYPE EXP2DF __stdcall CncGetMachineType(void);
 
 /*
* Name   : CncGetDiameterProgramming
* In     : -
* Out    : -
* Return : 0=milling, 1=turning
* Descr  : 
*/
 int EXP2DF __stdcall CncGetDiameterProgramming(void);


 /*
 * Name   : CncGetJointCfg
 * In     : joint index 0 .. CNC_MAX_JOINTS-1
 * Out    : pointer to joint config
 * Return : -
 */
 CNC_JOINT_CFG EXP2DF * __stdcall CncGetJointCfg(int jointIndex);

/*
* Name   : CncGetToolData
* In     : -
* Out    : -
* Return : Pointer to tool data
*/
 CNC_TOOL_DATA EXP2DF __stdcall CncGetToolData(int index);

/*
* Name   : CncUpdateToolData
* In     : -
* Out    : -
* Return : Modify tool data
*          Data is made persistent when ini file is saved
*/
 CNC_RC EXP2DF __stdcall CncUpdateToolData(CNC_TOOL_DATA *pTool, int index);


/*
* Name   : CncLoadToolTable
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : After this call the new tool data is used by the interpreter
*/
 CNC_RC EXP2DF __stdcall CncLoadToolTable(void);

/*
* Name   : CncStoreIniFile
* In     : -
* Out    : -
* Return : -
* Descr  : Save all current configuration data to ini file
*          Use CncReInitialize to activate new configuration parameters
*          Save coordinate system info fixtures only when saveFixtures = 1
*/
CNC_RC EXP2DF __stdcall CncStoreIniFile(int saveFixtures);

/*
* Name   : CncGetControllerFrequencyIndex
* In     : -
* Out    : -
* Return : Get step rate index in frequency table 
* Descr  : 
*/
 unsigned int EXP2DF __stdcall CncGetControllerFrequencyIndex(void);

/*
* Name   : CncSetControllerFrequencyIndex
* In     : -
* Out    : -
* Return : Set Max step rate, is index in frequecy table 
* Descr  : 
*/
CNC_RC EXP2DF __stdcall CncSetControllerFrequencyIndex(unsigned int index);


/*
* Name   : CncGetControllerNumberOfFrequencyItems
* In     : -
* Out    : -
* Return : Get number of possible frequencies
* Descr  : 
*/
int EXP2DF __stdcall CncGetControllerNumberOfFrequencyItems(void);

/*
* Name   : CncGetControllerFrequencyItem
* In     : -
* Out    : -
* Return : Get a frequency given index = 
*          0 .. CncGetControllerNumberOfFrequencyItems() - 1
* Descr  : 
*/
double EXP2DF __stdcall CncGetControllerFrequencyItem(unsigned int index);

/*************************************************************************/
/*                            Status items                               */
/*************************************************************************/
 
/*
 * Name   : CncIsServerConnected
 * In     : -
 * Out    : -
 * Return : TRUE if connection with CNCSERVER established
 *          Only if this one is 
 */
 int EXP2DF __stdcall CncIsServerConnected(void);
 
/*
 * Name   : CncGetControllerConnectionItem
 * In     : char pointer to array of CNC_COMMPORT_NAME_LEN size
 * Out    : -
 * Return : the port connection string e.g. "COM1"
 */
 char EXP2DF * __stdcall CncGetControllerConnectionItem(int itemNumber);

/*
 * Name   : CncGetControllerConnectionNumberOfItems
 * In     : -
 * Out    : the port connection string e.g. COM1
 * Return : Number of controller connection items
 */
 int EXP2DF __stdcall CncGetControllerConnectionNumberOfItems(void);

/*
* Name   : CncGetNrOfAxesOnController
* In     : -
* Out    : -
* Return : Number of axes on CPU for GUI
*/
 int EXP2DF __stdcall CncGetNrOfAxesOnController(void);

 /*
 * Name   : CncGetAxisIsConfigured
 * In     : axis CNC_X_AXIS .. CNC_C_AXIS, includingSlaves if a axis is configured because of slave
 * Out    : -
 * Return : 1 if axis configured
 */
 int EXP2DF __stdcall CncGetAxisIsConfigured(int axis, bool includingSlaves);

/*
* Name   : CncGetSimulationMode
* In     : -
* Out    : -
* Return : TRUE if CNCSERVER is running in simulation mode
*/
 int EXP2DF __stdcall CncGetSimulationMode(void);

/*
* Name   : CncGetBlockDelete
* In     : -
* Out    : -
* Return : TRUE if block delete is active
* Descr  : 
*/
 int EXP2DF __stdcall CncGetBlockDelete(void);

/*
 * Name   : CncGetState
 * In     : -
 * Out    : -
 * Return : Get CNCSERVER state
 */
 CNC_IE_STATE EXP2DF __stdcall CncGetState(void);


 /*
 * Name   : CncGetTrafficLight
 * In     : -
 * Out    : -
 * Return : Get CNCSERVER state
 */
 void EXP2DF __stdcall CncGetTrafficLight(CNC_TRAFFIC_LIGHT_COLOR *color, BOOL *blink);

 /*
 * Name   : CncGetIsManActionRequired
 * In     : -
 * Out    : -
 * Return : 0=no manual action, 1=manual action
 * Descr  : Reason for PAUSE state
 */
 int EXP2DF __stdcall CncGetIsManActionRequired(void);


 /*
* Name   : CncGetCurInterpreterLine
* In     : -
* Out    : -
* Return : Current interpreter line
* Descr  : Interpreter runs ahead of execution
*/
 int EXP2DF __stdcall CncGetCurInterpreterLine(void);

 /*
 * Name   : CncGetCurInterpreterLineText
 * In     : -
 * Out    : -
 * Return : Current interpreter line text
 * Descr  : Interpreter runs ahead of execution
 */
 char EXP2DF * __stdcall CncGetCurInterpreterLineText(void);


  /*
 * Name   : CncGetSearchStatus
 * In     : -
 * Out    : -
 * Return : Search data before after or current depending on beforeAfterCurrent value
 * Descr  : Used after search to compare before search and after search and let user sychronize the differerences.
 */
 int EXP2DF __stdcall CncGetSearchStatus(CNC_SEARCH_STATUS_DATA *data, int beforeAfterCurrent /* 0,1,2 */);



/*
* Name   : CncGetCurExecLine
* In     : -
* Out    : -
* Return : Current execution line
* Descr  : Line number starting from 1 which is currently executed
*/
 int EXP2DF __stdcall CncGetCurExecLine(void);

/*
* Name   : CncGetStepMode
* In     : -
* Out    : -
* Return : 1 if setmode active, 0 otherwize
* Descr  : Line number starting from 1 which is currently executed
*/
 int EXP2DF __stdcall CncGetSingleStepMode(void);

/*
 * Name   : CncGetActualFeedOverride
 * In     : 
 * Out    :  
 * Return : Actual FeedOverride factor
 */
  double EXP2DF __stdcall CncGetActualFeedOverride(void);

/*
 * Name   : CncGetJointStatus
 * In     : joint index 0 .. CNC_MAX_JOINTS-1
 * Out    : pointer to joint (motor) status
 * Return : -
 */
 CNC_JOINT_STS EXP2DF * __stdcall CncGetJointStatus(int jointIndex);

 /*
* Name   : CncGetIOStatus
* In     : -
* Out    : -
* Return : Get pointer to IO status or the IO status as was before Pause,
*          this can be used to check if the spindle will start at resume
*/
 CNC_IO_PORT_STS EXP2DF * __stdcall CncGetIOStatus(CNC_IO_ID id);
 

/*
* Name   : CncGetFifoSize
* In     : -
* Out    : -
* Return : Actual CPU fifo size
*          for visualizing the fifo fullness
*/
 int EXP2DF __stdcall CncGetFifoSize(void);

/*
* Name   : CncGetFifoFreeSize
* In     : -
* Out    : -
* Return : Number of elements that can be placed in the fifo
*/
 int EXP2DF __stdcall CncGetFifoFreeSize(void);

 /*
* Name   : CncGetMotionEnabled
* In     : -
* Out    : -
* Return : TRUE if CPU motion is enabled, 
*          CPU is generating pulses if required
*          
*/
 int EXP2DF __stdcall CncGetMotionEnabled(void);

 /*
* Name   : CncIsCapturing
* In     : -
* Out    : -
* Return : TRUE if capture mode is active for homing or probing
*          A motion is executed that stops when home/probe 
*          input becomes active.
*/
 int EXP2DF __stdcall CncIsCapturing(void);

 /*
* Name   : CncGetIsCaptured
* In     : -
* Out    : -
* Return : TRUE if there position was captured by 
*          End Of Stroke switch or probe
*/
 int EXP2DF __stdcall CncGetIsCaptured(void);

 /*
 * Name   : CncGetCurrentGcodesText
 * In     : User supplied character buffer of 80 char size
 * Out    : Buffer filled with actual GCode set
 * Return : -
 */
void EXP2DF __stdcall CncGetCurrentGcodesText(char *activeGCodes);


/*
* Name   : CncGetCurrentMcodesText
* In     : User supplied character buffer of 80 char size
* Out    : Buffer filled with actual GCode set in text format
* Return : -
*/
void EXP2DF __stdcall CncGetCurrentMcodesText(char *activeMCodes);

/*
* Name   : CncSingleStepMode
* In     : singleStepMode value
* Out    : -
* Return : See CNC_RC values
* Descr  : Switch single step mode on or of, when on, CncRunJob will execute only
*          one line of the loaded job, for single stepping.
*/
 CNC_RC EXP2DF __stdcall CncSingleStepMode(int singleStepMode);

 /*
* Name   : CncGetCurrentGcodeSettings (FST)
* In     : user supplied char buffer of 80 chars size
* Out    : Current setting in text format
* Return : -
*/
 void EXP2DF __stdcall CncGetCurrentGcodeSettingsText(char *actualGCodeSettings);
 double EXP2DF __stdcall CncGetCurrentS(void);
 double EXP2DF __stdcall CncGetCurrentF(void);
 int EXP2DF __stdcall CncGetCurrentT(void);

/*
* Name   : CncGetJointPos
* In     : joint index
* Out    : Actual joint (motor) positions 
* Return : -
*/
double EXP2DF __stdcall CncGetJointPos(int joint);


/*
* Name   : CncGetJointPosRaw
* In     : joint index
* Out    : Actual joint (motor) positions including backlash
* Return : -
*/
double EXP2DF __stdcall CncGetJointPosRaw(int joint);


/*
* Name   : CncGetMachinePos
* In     : pointer to array of doubles CNC_MAX_JOINTS size
* Out    : Actual Cartesian machine position
* Return : -
*/
CNC_POSITION EXP2DF __stdcall CncGetMachinePos(void);
double EXP2DF __stdcall CncGetMachinePos2(int joint);
void EXP2DF __stdcall CncGetMachineZeroWorkPoint(CNC_POSITION *pos, int *rotationActive);

 /*
 * Name   : CncGetMachinePos
 * In     : void or axis id (X=0, Y=1, .. C=5)
 * Out    : Actual cartesian machine position + actual offset 
 *          This is the "WORK" position
 * Return : -
 */
CNC_POSITION EXP2DF __stdcall CncGetWorkPos(void);
double EXP2DF __stdcall CncGetWorkPos2(int axis);


 /*
 * Name   : CncGetMachinePos
 * In     : void or axis id (X=0, Y=1, .. C=5)
 * Out    : Actual cartesian machine position + actual offset 
 *          This is the "WORK" position
 * Return : -
 */
CNC_POSITION __stdcall CncGetProgramZero(void);

/*
* Name   : CncGetActualOriginOffset
* In     : -
* Out    : Actual offsets, does not include toolLenOffset for Z (axis 2)
*         
* Return : Actual offset
*/
 CNC_POSITION EXP2DF __stdcall CncGetActualOriginOffset(void);

/*
* Name   : CncGetActualToolZOffset
* In     : -
* Out    : -
* Return : Actual tool Z offset
*/
 double EXP2DF __stdcall CncGetActualToolZOffset(void);

/*
* Name   : CncGetActualToolXOffset
* In     : -
* Out    : -
* Return : Actual tool X offset
*/
 double EXP2DF __stdcall CncGetActualToolXOffset(void);


 /*
 * Name   : CncGetActualG68Rotation
 * In     : -
 * Out    : -
 * Return : Actual tool X offset
 */
 double EXP2DF __stdcall CncGetActualG68Rotation(void);


 /*
 * Name   : CncGetActualFeed
 * In     : 
 * Out    :  
 * Return : Actual Feed
 */
 double EXP2DF __stdcall CncGetActualFeed(void);

/*
* Name   : CncGetRePos
* In     : pointer to array of doubles CNC_MAX_AXES=6 size
* Out    : Repos position (position at pause) to move back to at resume
*          valid = TRUE when there is an actual re-pos position stored
* Return : -
*/
 void EXP2DF __stdcall CncGetPausePos(CNC_POSITION *pos, int *spindleOutput, int *FloodOutput, int *mistOutput, 
	 int *lineNumber, int *valid, int* doArray, int *arrayX, int *arrayY);

/*
* Name   : CncGetSwLimitError
* In     : -
* Out    : -
* Return : TRUE if there is a software limit error
*/
 int EXP2DF __stdcall CncGetSwLimitError(void);

/*
* Name   : CncGetFifoError
* In     : -
* Out    : -
* Return : TRUE if there is a fifo underflow
*/
 int EXP2DF __stdcall CncGetFifoError(void);


/*
* Name   : CncGetEMStopActive
* In     : -
* Out    : -
* Return : TRUE if there is emergency stop was triggered
*/
 int EXP2DF __stdcall CncGetEMStopActive(void);


/*
* Name   : CncGetVariable
* In     : -
* Out    : -
* Return : Get # variables [1..5399]
*/
 double EXP2DF __stdcall CncGetVariable(int varIndex);

/*
* Name   : CncSetVariable
* In     : -
* Out    : -
* Return : Get # variables [1..5399]
*/
 void EXP2DF __stdcall CncSetVariable(int varIndex, double value);


/*
* Name   : CncInMillimeterMode
* In     : -
* Out    : -
* Return : TRUE if millimeter mode (G21), FALSE if not (G20)
* Descr  : Reinitialize, CNCSERVER after modified ini file
*/
 int EXP2DF __stdcall CncInMillimeterMode(void);

/*
* Name   : CncGetToolChangeHalt
* In     : -
* Out    : -
* Return : TRUE if cnc is not halted for tool change, 
*          if FALSE cnc stops for tool change.
* Descr  : 
*/
 int EXP2DF __stdcall CncGetToolChangeNoHalt(void);

 
/*
* Name   : CncGetOutput
* In     : io id
* Out    : -
* Return : The actual value of an output
* Descr  : 
*/
 int EXP2DF __stdcall CncGetOutput(CNC_IO_ID id);

 /*
* Name   : CncGetInput
* In     : io id
* Out    : -
* Return : The actual value of an input logic or Raw
* Descr  : Logic takes inversion into account, Raw gives the value from the CPU directly.
*/
 int EXP2DF __stdcall CncGetInput(CNC_IO_ID);
 int EXP2DF __stdcall CncGetInputRaw(CNC_IO_ID);

 /*
 * Name   : CncGetHandwheelCount
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get value of handwheel counter.
 */
 int EXP2DF __stdcall CncGetHandWheelCount1(void);
 int EXP2DF __stdcall CncGetHandWheelCount2(void);


 /*
 * Name   : CncGetSyncPulseAvailable
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get value of spindle sync pulse counter.
 */
 int EXP2DF __stdcall CncGetSyncPulseAvailable(void);


 /*
 * Name   : CncGetSyncCount
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get value of spindle sync pulse counter.
 */
 int EXP2DF __stdcall CncGetSyncCount(void);
 
 /*
 * Name   : CncGetSpindleSpeed
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get spindle speed
 */
 double EXP2DF __stdcall CncGetSpindleSpeed(void);

 /*
 * Name   : CncGetAllAxesHomed
 * In     : -
 * Out    : -
 * Return : 1 if all axes are homed, 0 if not
 * Descr  : Check if all axes are homed.
 */
 int  EXP2DF __stdcall CncGetAllAxesHomed(void);


/*
 * Name   : CncGetSafetyMode
 * In     : -
 * Out    : -
 * Return : 1 if all not all axes homed or safety input = 1
 * Descr  : If this returns 1 GUI will decide to use slow speed.
 */
 int  EXP2DF __stdcall CncGetSafetyMode(void);


 /*
 * Name   : CncGetJobRenderStatus
 * In     : -
 * Out    : -
 * Return : job render status
 * Descr  : total length, progress, collision etc.
 */
 CNC_JOB_RENDER_STATUS EXP2DF __stdcall CncGetJobRenderStatus(void);

 /*
 * Name   : CncLogFifoGet
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get log message from fifo, be sure to check this continuously
 *          and display the message to the operator of the machine.
 */
 CNC_RC EXP2DF __stdcall CncLogFifoGet(CNC_LOG_MESSAGE *data);

 /*
 * Name   : CncPosFifoGet
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get real-time position info for viewing the real-time graph.
 *          this consists of new values for x,y,z,a
 *          Draw a line to the new point.
 *          If a is rotation axis, rotate y/z plane with angle a.
 *          x remains the same.
 *
 */
 CNC_RC EXP2DF __stdcall CncPosFifoGet(CNC_POS_FIFO_DATA *data);

 /*
 * Name   : CncGraphFifoGet
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get graph data info from rendering current job
 *          trough interpreter without actually execution.
 *          For showing /checking current job file
 */
 CNC_RC EXP2DF __stdcall CncGraphFifoGet(CNC_GRAPH_FIFO_DATA *data);

 
/*************************************************************************/
/*                         Commands                                      */
/*************************************************************************/
/*
* Name   : CncConnectServer
* In     : inifile name, only file name
* Out    : -
* Return : See CNC_RC values
* Descr  : Starts CNC server and establish connection with it
*          This is the first command that the GUI should execute.
*/
 CNC_RC EXP2DF __stdcall CncConnectServer(char *iniFileName);

/*
* Name   : CncDisConnectServer
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Stops CNC server, to be called when GUI terminates.
*/
 CNC_RC EXP2DF __stdcall CncDisConnectServer(void);

/*
* Name   : CncEnableBlockDelete
* In     : Enable, if TRUE block delete will be switched on
* Out    : -
* Return : See CNC_RC values
* Descr  : 
*/
 CNC_RC EXP2DF __stdcall CncEnableBlockDelete(int enable);

/*
* Name   : CncSetToolChangeHalt
* In     : Enable, then cnc tool change is ignored, not halt for tool change
* Out    : -
* Return : See CNC_RC values
* Descr  : 
*/
 CNC_RC EXP2DF __stdcall CncSetToolChangeNoHalt(int enable);

/*
* Name   : CncStartRenderGraph
* In     : OutLineOnly, if 1, only the outline will be shown in the graph (performance for large files)
* Out    : -
* Return : See CNC_RC values
* Descr  : Run job through interpreter and send output to graph fifo for viewing
*          Interpreter context is saved before and restored after.
*          If this succeeds, job syntax is OK and will run without errors
*
*/
 CNC_RC EXP2DF __stdcall CncStartRenderGraph(int outLines, int contour);
 CNC_RC EXP2DF __stdcall CncStartRenderGraphToLine(int outLines, int contour, int line, int arrayX, int arrayY);


/*
* Name   : CncSetOutput
* In     : io id, value
* Out    : -
* Return : See CNC_RC values
* Descr  : Set an output to value
*/
 CNC_RC EXP2DF __stdcall CncSetOutput(CNC_IO_ID id, int value);
 
 /*
 * Name   : CncSetSpindleOutput
 * In     : io id, value
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Set an output to value
 */
 CNC_RC __stdcall CncSetSpindleOutput(int value);

/*
* Name   : CncAbortJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Stop motion (stepper motor will lose steps, re-homing required when moving), 
*          make IO safe
*/
 CNC_RC EXP2DF __stdcall CncAbortJob(void);

/*
* Name   : CncPauseJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Smooth stop in the middle of a job
*/
 CNC_RC EXP2DF __stdcall CncPauseJob(void);

/*
* Name   : CncRunOrResumeJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Start job or resume paused job
*/
 CNC_RC EXP2DF __stdcall CncRunOrResumeJob(void);

 /* Name   : CncSetJobArrayParameters
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Start/render job with given parameters for array execution
 */
 CNC_RC EXP2DF __stdcall CncSetJobArrayParameters(CNC_CMD_ARRAY_DATA *runJobData);
 CNC_RC EXP2DF __stdcall CncGetJobArrayParameters(CNC_CMD_ARRAY_DATA *runJobData);

/*
* Name   : CncRewindJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Rewind the job to beginning
*/
 CNC_RC EXP2DF __stdcall CncRewindJob(void);

/*
* Name   : CncSearchLine
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Set job position to given line number with expression TRUE
*          the latter is not yet implemented but would be usefully when a line
*          is running in a loop.
*
*/
 CNC_RC EXP2DF __stdcall CncSearchLine(int lineNr,char *pSubroutine);

/*
* Name   : CncReset
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Recover from errors
*          The reset also establishes a connection 
*          with the server if not already done
*/
 CNC_RC EXP2DF __stdcall CncReset(void);

 /*
 * Name   : CncStartLinJog
 * In     : axes[], if value is 0, axis will not move,
 *          if axes[i] > 0 movement is positive, if < 0 movement is negative
 *          if continuous is FALSE axis[i] determines stepSize.
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Start jog, multiple axes 
 *          velocity factor [-1.0 .. 1.0], sign determines direction
 *
 * Remark:  With this function the axes run 100% synchrounous, with joint jog 
 *          they do not.
 *          Disadvantage, when LinJog is active not second linJog can be requested
 *          first CncStop linJog has te be called.
 */
CNC_RC __stdcall CncStartLinJog(double axes[], double velocityFactor, BYTE continuous);

/*
* Name   : CncStopLinJog
* In     : 
* Out    : -
* Return : See CNC_RC values
* Descr  : Stop lin jog
*/
CNC_RC __stdcall CncStopLinJog(void);

/*
* Name   : CncStartJointJog
* In     : axes[CNC_MAX_AXES], if value is 0, axis will not move,
*          if axes[i] > 0 movement is positive, if < 0 movement is negative
*          if continuous is FALSE axis[i] determines stepSize.
* Out    : -
* Return : See CNC_RC values
* Descr  : Start jog, multiple axes 
*          velocity factor [-1.0 .. 1.0], sign determines direction
*        
* Remark: CNC_MAX_AXES is 6 (Currently only first 4 are really implemented       
*
* Example: 
*
*		Start continuous jog for x axis in positive direction with 50% of max velocity
*       ================================================================================
*		double axes[CNC_MAX_AXES] = {1.0,0,0,0,0,0}
*       CncStartJog(axes, 0.5, 1)
*       
*		Start continuous jog for y axis in negative direction with 50% of max velocity
*       ================================================================================
*		double axes[CNC_MAX_AXES] = {0,-1.0,0,0,0,0}
*       CncStartJog(axes, 0.5, 1)
*
*		Start step wise jog of 2 mm jog for y axis in negative direction with 100% of max velocity
*       ================================================================================
*		double axes[CNC_MAX_AXES] = {0,-2.0,0,0,0,0}
*       CncStartJog(axes, 0.5, 0)
*
*/
CNC_RC EXP2DF __stdcall CncStartJog(double axes[], 
	 double velocityFactor, 
	 int continuous);

/*
 * Idem for 1 joint
 */
CNC_RC EXP2DF __stdcall CncStartJog2(int axis, 
								     double step, 
									 double velocityFactor, 
									 int continuous);


/*
* Name   : CncStopJointJog
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Stop jog
*/
 CNC_RC EXP2DF __stdcall CncStopJog(int axis);

/*
* Name   : CncMoveTo
* In     : pos[i] position to move to for axis i,
*          move[i], if TRUE axis i will move, if false no move.
*          
* Out    : -
* Return : See CNC_RC values
* Descr  : Move joints/motors to given position
*/
 CNC_RC EXP2DF __stdcall CncMoveTo(CNC_POSITION pos, 
	                               int  move[], 
								   double velocityFactor);


/*
* Name   : CncStartHandweelOperation
* In     : multiplication handwheel factor for joint
*          factor = 1.0 will move 1 millimeter for one handwheel revolution.
*          factor = 2.0 will move 2 millimeter for one handwheel revolution.
*          n = handwheel number, turning may have 2 handwheels
*          
* Out    : -
* Return : See CNC_RC values
* Descr  : 
*/
 CNC_RC EXP2DF __stdcall CncStartHandweelOperation(double multiplication, double vMax, int axis, int velMode, int n);


/*
* Name   : CncStopHandweelOperation
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : 
*/
 CNC_RC EXP2DF __stdcall CncStopHandweelOperation(void);

/*
* Name   : CncSetFeedOverride/CncSetArcFeedOverride
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Change feed rate factor global and relative for arc's
*          for arc's the factor is less than 1.0
*/
 CNC_RC EXP2DF __stdcall CncSetFeedOverride(double factor);
 CNC_RC EXP2DF __stdcall CncSetArcFeedOverride(double factor);

 /*
 * Name   : CncSetSpeedOverride
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Change feed rate factor
 */
 CNC_RC EXP2DF __stdcall CncSetSpeedOverride(double factor);
 
/*
* Name   : CncRunSingleLine
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Start single line of interpreter text for MDI mode
*/
 CNC_RC EXP2DF __stdcall CncRunSingleLine(char *text);

/*
* Name   : CncLoadJob
* In     : -
* Out    : jobFileLength, macro file length, number of lines in job and macro file.
*          total job length is the sum of both.
* Return : See CNC_RC values
* Descr  : Load a job file
*/
 CNC_RC EXP2DF __stdcall CncLoadJob(const char *fileName, 
	 int        *jobFileLength, 
	 int        *macroFileLength,
	 int        *isLongJob,
	 int        *isSuperLongJob,
	 __int64    *sizeInBytes);
	 

 /*
 * Name   : GetMacroFileName/CncGetMacroFileNameWithoutPath
 * In     : -
 * Out    : macro file name including path/without path
 *          the name without path in  inside the cnc.ini file
 * Return : See CNC_RC values
 * Descr  : Get path of macro file for GUI.
 */
 CNC_RC __stdcall CncGetMacroFileName(char *name);
 CNC_RC __stdcall CncGetMacroFileNameWithoutPath(char *name);

 /*
 * Name   : CncSetMacroFileNameWithoutPath
 * In     : macrofile name without path, just the name.
 *          path is always the directory where cncserver.exe is located.
 * Out    : -
 *          
 * Return : See CNC_RC values
 * Descr  : set macro file name in configuration.
 *          ini file must be saved to activate this.
 */
 CNC_RC __stdcall CncSetMacroFileNameWithoutPath(char *name);



/*
* Name   : CncFindFirstJobLine
* In     : -
* Out    : text, a line of text
*          endOfJob, TRUE when last line
*          totNumLines, total number of job lines
*          gethandle, pass to CncFindNextJobLine
*
* Return : See CNC_RC values
* Descr  : Get first line of loaded job file
*/
 CNC_RC EXP2DF __stdcall CncFindFirstJobLine(char *text, int *endOfJob, int *totNumOfLines);
 CNC_RC EXP2DF __stdcall CncFindFirstJobLineF(char *text, int *endOfJob);


/*
* Name   : CncFindNextJobLine
* In     : -
* Out    : text, a line of text
*          endOfJob, TRUE when last line
*          totNumLines, total number of job lines
*          gethandle, pass to next call to CncFindNextJobLine
*
* Return : See CNC_RC values
* Descr  : Get next line of loaded job file
*/
 CNC_RC EXP2DF __stdcall CncFindNextJobLine(char *text, int *endOfJob);
 CNC_RC EXP2DF __stdcall CncFindNextJobLineF(char *text, int *endOfJob);

/*
* Name   : CncSetSimulationMode
* In     : sim value TRUE is on FALSE is Off.
* Out    : -
* Return : See CNC_RC values
* Descr  : Switch single step mode on or of, when on, CncRunJob will execute only
*          one line of the loaded job, for single stepping.
*/
 CNC_RC EXP2DF __stdcall CncSetSimulationMode(int sim);

/*
* Name   : CncReInitialize
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Reinitialize, CNCSERVER after modified ini file
*/
 CNC_RC EXP2DF __stdcall CncReInitialize(void);
 
 /*
 * Name   : CncGetActiveOptions
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get active software options, currently only number of axes for CPU5B
 */
 CNC_RC EXP2DF __stdcall CncGetActiveOptions(char *customerName, int *numberOfAxes, unsigned int *optionWord);

 /*
 * Name   : CncActivateOption
 * In     : numberOfAxes that should be enabled, optionWord (not yet in use).
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get request code for new options.
 *          Request code is send to Eding CNC.
 *          Eding CNC will send back an Activation Code.
 */
 CNC_RC EXP2DF __stdcall CncGetOptionRequestCode(char *customerName, int numberOfAxes, unsigned int enableFlags, char *requestCode);

  /*
 * Name   : CncActivateOption
 * In     : Activation key, retrieved from Eding CNC after payment
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Get active software options, currently only number of axes for CPU5B
 */
 CNC_RC EXP2DF __stdcall CncActivateOption(char *activationKey);
 
/*************************************************************************/
/*                         Utility items                                 */
/*************************************************************************/
/*
* Name   : CncGetSetupPassword
* In     : -
* Out    : -
* Return : Setup password
*/
char EXP2DF * __stdcall CncGetSetupPassword(void);

/*
* Name   : CncGetRCText
* In     : rc
* Out    : -
* Return : Text representing return code
*/
char EXP2DF * __stdcall CncGetRCText(CNC_RC rc);

 /*
 * Name   : CncGetStateText
 * In     : -
 * Out    : -
 * Return : Translate CNCSERVER state into text
 */
 char EXP2DF * __stdcall CncGetStateText(int state);

#ifdef __cplusplus
	}
#endif


#endif
