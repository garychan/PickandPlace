#ifndef CNC_TYPES_H_INCLUDED
#define CNC_TYPES_H_INCLUDED

#ifndef USBCNC_VERSION
#define USBCNC_VERSION "USBCNC V4.00.08"
#endif

#ifndef CNC_EPSILON
#define CNC_EPSILON (0.00001)
#endif

#ifndef CNC_DOUBLES_ARE_EQUAL
#define CNC_DOUBLES_ARE_EQUAL(x,y)  (int)(fabs( (double)((x)-(y)) ) < CNC_EPSILON )
#endif

#ifndef CNC_DOUBLES_ARE_EQUAL_E
#define CNC_DOUBLES_ARE_EQUAL_E(x,y,e)  (int)(fabs( (double)((x)-(y)) ) < e )
#endif

#ifndef CNC_ROUND_TO_INT
#define CNC_ROUND_TO_INT(a) (a > 0) ? (int)(a + 0.5) : ((a < 0) ? (int) (a - 0.5) : (int)0)
#endif

#ifndef CNC_ROUND_TO_DECIMAL3
#define CNC_ROUND_TO_DECIMAL3(x) ((double)((int)(x * 10000.0))/10000)
#endif

#ifndef CNC_ROUND_TO_DECIMAL4
#define CNC_ROUND_TO_DECIMAL4(x) ((double)((int)(x * 100000.0))/100000)
#endif

#define CNC_MAX_FREQENCY_TABLE_LEN 20

#define CNC_X_AXIS 0
#define CNC_Y_AXIS 1
#define CNC_Z_AXIS 2
#define CNC_A_AXIS 3
#define CNC_B_AXIS 4
#define CNC_C_AXIS 5

//shared Enums
typedef enum CNC_MACHINE_TYPE
{
	CNC_MACHINE_TYPE_MILLING = 0,
	CNC_MACHINE_TYPE_TURNING = 1,
	CNC_MACHINE_TYPE_TURNING_BACK_X = 2,
	CNC_MACHINE_TYPE_4AXES_FOAMCUTTER = 3
};


typedef enum CNC_ROT_AXIS_OPTION
{
	CNC_ROT_OPT_ROT = 0,
	CNC_ROT_OPT_SLAVE_TO_X = 1,
	CNC_ROT_OPT_SLAVE_TO_Y = 2,
	CNC_ROT_OPT_SLAVE_TO_Z = 3,
	CNC_ROT_OPT_LIN = 4,
	CNC_ROT_OPT_4AX_MILLING = 5,
	CNC_ROT_OPT_TAN_KNIFE = 6,
	CNC_ROT_OPT_LAST
};

//shared Enums
typedef enum CNC_KIN_MODE
{
	CNC_KIN_MODE_UKNOWN = 0,
	CNC_KIN_MODE_LIN = 1,
	CNC_KIN_MODE_LIN_FOAMCUT = 2,
	CNC_KIN_MODE_ROT = 3,
	CNC_KIN_MODE_4AX_MILLING = 4,
	CNC_KIN_MODE_TAN_KNIFE = 5,
	CNC_KIN_MODE_LAST = 6
};


typedef enum CONSTANTS
{
	//Max joints (motors) and max kinematic axes (x,y,z,a,b)
	CNC_MAX_CUSTOMER_NAME = 44,
	CNC_MAX_JOINTS =  6,
	CNC_MAX_AXES   =  6,
	CNC_MAX_NAME_LENGTH = 32,
	CNC_MAX_PATH = 260,
	CNC_MAX_FNAME_LENGTH = 32,
	CNC_MAX_LOGGING_TEXT = 120,
	CNC_MAX_SOURCE_INFO_TEXT = 30,
	CNC_MAX_FUNCTION_NAME_TEXT = 30,
	CNC_MAX_MESSAGE_TEXT = 150,
	CNC_MAX_VARS = 5800,
	CNC_MAX_TOOLS = 99,
	CNC_MAX_CURRENT_GCODE_TEXT = 60,
	CNC_MAX_CURRENT_MCODE_TEXT = 20,
	CNC_MAX_EXPRESSION_TEXT = 80,
	CNC_MAX_INTERPRETER_LINE = 255,
	CNC_POS_FIFO_SIZE = 100,
	CNC_POS_FIFO_MARGIN = 2,
	CNC_GRAPH_FIFO_SIZE = 100,
	CNC_GRAPH_FIFO_MARGIN  = 2,
	CNC_LOG_FIFO_SIZE = 25,
	CNC_LOG_FIFO_MARGIN = 2,
	CNC_MAX_INTERPRETER_LOOKAHEAD = 500,
	CNC_MAX_VERSION_TEXT = 50,
	CNC_COMMPORT_NAME_LEN = 20,
	CNC_MAX_COMM_PORTS = 50,
	CNC_MAX_OUTPUT_PORTS = 18,
	CNC_MAX_INPUT_PORTS  = 32,
	CNC_MAX_GPIO_OUTPUT_PORTS = 16,
	CNC_MAX_GPIO_INPUT_PORTS = 16,
	CNC_MAX_GPIO_ANIN_PORTS = 8,
	CNC_MAX_GPIO_PWM_OUT_PORTS = 4,
	CNC_MAX_IO_PORTS = (CNC_MAX_OUTPUT_PORTS + 
                        CNC_MAX_INPUT_PORTS + 
                        CNC_MAX_GPIO_OUTPUT_PORTS + 
                        CNC_MAX_GPIO_INPUT_PORTS + 
                        CNC_MAX_GPIO_PWM_OUT_PORTS +
                        CNC_MAX_GPIO_ANIN_PORTS + 1), 

	CNC_MAX_PRECISION_TEXT = 32,
	CNC_TOOL_DIAMETER_INDEX = 5500,		//First var index of tool diameter
	CNC_TOOL_ZOFFSET_INDEX = 5400,		//First var index of tool z-offset
	CNC_TOOL_XOFFSET_INDEX = 5600,		//First var index of tool x-offset
	CNC_TOOL_ORIENTATION_INDEX = 5700   //First var index of tool orientation

};


enum CNC_RC
{
    CNC_RC_OK            =  0,       /* success */
    CNC_RC_BUF_EMPTY     =  1,       /* buffer empty */
    CNC_RC_TRACE         =  2,       /* trace info */
    CNC_RC_USER_INFO     =  3,       /* User message */
    CNC_RC_SHUTDOWN      =  4,       /* returned by process request after CMD_CLOSE */
	CNC_RC_EXISTING      =  5,       /* if shared mem already exists */
	CNC_RC_ALREADY_RUNS  =  6,       /* if server already running */
    CNC_RC_ERR           = -1,       /* no data in fifo */
    CNC_RC_ERR_PAR       = -2,       /* wrong parameter or parameter value, see text */
    CNC_RC_ERR_STATE     = -3,       /* wrong state, not allowed, see text */
    CNC_RC_ERR_INT       = -4,       /* interpreter error, see interpreter error status */
    CNC_RC_ERR_CE        = -5,       /* command envelope error */
    CNC_RC_ERR_EXE       = -6,       /* execution error */
    CNC_RC_ERR_PIC       = -7,       /* CPU error, see sub code, text, restart required */
    CNC_RC_ERR_MOT       = -8,       /* trajectory generator error, see sub code, text */
    CNC_RC_ERR_SYS       = -9,       /* server system error, see text */
    CNC_RC_ERR_TIMEOUT   = -10,      /* general timeout error */
    CNC_RC_EXE_CE        = -11,      /* Error executing command envelope */
    CNC_RC_ERR_FILEOPEN  = -12,      /* file open error */
	CNC_RC_ERR_COLLISION = -13	     /* collision */
};


typedef enum CNC_ERROR_CLASS
{
    CNC_EC_INFO = 0,  //Info, no user action
    CNC_EC_DIALOG,    //For user interaction with partprogram
	CNC_EC_USERACTION, // user action required
    CNC_EC_WARNING,   //Warning eventual user action
    CNC_EC_STOP,      //Stopped on path
    CNC_EC_QSTOP,     //Stop immediate, path not maintained
    CNC_EC_ABORT,     //Emergency stop
    CNC_EC_BUG,       //SW bug report to supplier
    CNC_EC_FATAL      //unrecoverable system failure

};

typedef enum CNC_IO_ID
{
    CNC_IOID_NONE = 0,           //No IO defined
    CNC_IOID_MACHINE_ON_OUT,     //Machine ON output
    CNC_IOID_DRIVE_ENABLE_OUT,   //Amplifier enable
    CNC_IOID_TOOL_OUT,           //Tool on
    CNC_IOID_COOLANT1_OUT,       //Flood
    CNC_IOID_COOLANT2_OUT,       //Mist
	CNC_IOID_TOOLDIR_OUT,        //Tool direction output
	CNC_IOID_AUX1_OUT,           //Aux1 output
	CNC_IOID_AUX2_OUT,           //Aux1 output
	CNC_IOID_AUX3_OUT,           //Aux1 output
	CNC_IOID_AUX4_OUT,           //Aux1 output
	CNC_IOID_AUX5_OUT,           //Aux1 output
	CNC_IOID_AUX6_OUT,           //Aux1 output
	CNC_IOID_AUX7_OUT,           //Aux1 output
	CNC_IOID_AUX8_OUT,           //Aux1 output
	CNC_IOID_AUX9_OUT,           //Aux1 output
	CNC_IOID_PWM_VAL1_OUT,       //PWM value output 0..100%
	CNC_IOID_PWM_VAL2_OUT,       //PWM value output 0..100%
	CNC_IOID_PWM_VAL3_OUT,       //PWM value output 0..100%
    
    CNC_IOID_EMSTOP1_IN,         //Emergency stop input
    CNC_IOID_EMSTOP2_IN,         //Emergency stop input
    CNC_IOID_EXTERR_IN,          //Ext error input
	CNC_IOID_PROBE_IN,           //Probe
	CNC_IOID_SYNC_IN,            //Spindle Sync pulse
	CNC_IOID_RUN_IN,             //Run Button
	CNC_IOID_PAUSE_IN,           //Pause Button
	CNC_IOID_HOME_X_IN,          //Home sensor
	CNC_IOID_HOME_Y_IN,          //idem
	CNC_IOID_HOME_Z_IN,          //idem
	CNC_IOID_HOME_A_IN,          //idem
	CNC_IOID_HOME_B_IN,          //idem
	CNC_IOID_HOME_C_IN,          //idem
	CNC_IOID_HOME_1_IN,          //Home sensor
	CNC_IOID_HOME_2_IN,          //idem
	CNC_IOID_HOME_3_IN,          //idem
	CNC_IOID_HOME_4_IN,          //idem
	CNC_IOID_HOME_5_IN,          //idem
	CNC_IOID_HOME_6_IN,          //idem
    CNC_IOID_HW1A_IN,            //Handwheel 1
    CNC_IOID_HW1B_IN,            //Handwheel 1
    CNC_IOID_HW2A_IN,            //Handwheel 2
    CNC_IOID_HW2B_IN,            //Handwheel 2
    CNC_IOID_ANA1_IN,            //Analog1
    CNC_IOID_ANA2_IN,            //Analog2
    CNC_IOID_ANA3_IN,            //Analog3
	CNC_IOID_AUX1_IN,            //Aux1 input
	CNC_IOID_AUX2_IN,            //Aux1 input
	CNC_IOID_AUX3_IN,            //Aux1 input
	CNC_IOID_AUX4_IN,            //Aux1 input
	CNC_IOID_AUX5_IN,            //Aux1 input
	CNC_IOID_AUX6_IN,            //Aux1 input

	//General purpose IO
	CNC_IOID_GPIO_OUT_0,          //Ext io card output
	CNC_IOID_GPIO_OUT_1,          //Ext io card output
	CNC_IOID_GPIO_OUT_2,          //Ext io card output
	CNC_IOID_GPIO_OUT_3,          //Ext io card output
	CNC_IOID_GPIO_OUT_4,          //Ext io card output
	CNC_IOID_GPIO_OUT_5,          //Ext io card output
	CNC_IOID_GPIO_OUT_6,          //Ext io card output
	CNC_IOID_GPIO_OUT_7,          //Ext io card output
	CNC_IOID_GPIO_OUT_8,          //Ext io card output
	CNC_IOID_GPIO_OUT_9,          //Ext io card output
	CNC_IOID_GPIO_OUT_10,         //Ext io card output
	CNC_IOID_GPIO_OUT_11,         //Ext io card output
	CNC_IOID_GPIO_OUT_12,         //Ext io card output
	CNC_IOID_GPIO_OUT_13,         //Ext io card output
	CNC_IOID_GPIO_OUT_14,         //Ext io card output
	CNC_IOID_GPIO_OUT_15,         //Ext io card output
	
    CNC_IOID_GPIO_IN_0,           //Ext io card input
	CNC_IOID_GPIO_IN_1,           //Ext io card input
	CNC_IOID_GPIO_IN_2,           //Ext io card input
	CNC_IOID_GPIO_IN_3,           //Ext io card input
	CNC_IOID_GPIO_IN_4,           //Ext io card input
	CNC_IOID_GPIO_IN_5,           //Ext io card input
	CNC_IOID_GPIO_IN_6,           //Ext io card input
	CNC_IOID_GPIO_IN_7,           //Ext io card input
	CNC_IOID_GPIO_IN_8,           //Ext io card input
	CNC_IOID_GPIO_IN_9,           //Ext io card input
	CNC_IOID_GPIO_IN_10,          //Ext io card input
	CNC_IOID_GPIO_IN_11,          //Ext io card input
	CNC_IOID_GPIO_IN_12,          //Ext io card input
	CNC_IOID_GPIO_IN_13,          //Ext io card input
	CNC_IOID_GPIO_IN_14,          //Ext io card input
	CNC_IOID_GPIO_IN_15,          //Ext io card input

    CNC_IOID_GPIO_PWMOUT_0,         //Ext io card output
	CNC_IOID_GPIO_PWMOUT_1,         //Ext io card output
	CNC_IOID_GPIO_PWMOUT_2,         //Ext io card output
	CNC_IOID_GPIO_PWMOUT_3,         //Ext io card output

    CNC_IOID_GPIO_ANIN_0,          //Ext io card analogue input
	CNC_IOID_GPIO_ANIN_1,          //Ext io card analogue input
	CNC_IOID_GPIO_ANIN_2,          //Ext io card analogue input
	CNC_IOID_GPIO_ANIN_3,          //Ext io card analogue input
	CNC_IOID_GPIO_ANIN_4,          //Ext io card analogue input
	CNC_IOID_GPIO_ANIN_5,          //Ext io card analogue input
	CNC_IOID_GPIO_ANIN_6,          //Ext io card analogue input
	CNC_IOID_GPIO_ANIN_7,          //Ext io card analogue input

    CNC_IOID_LAST                  //Serves as last

}; 

typedef enum CNC_IE_STATE
{
    CNC_IE_POWERUP_STATE        = 0, /* no interpreter threads running yet */
    CNC_IE_IDLE_STATE,               /* thread is started but IE not initialized */
    CNC_IE_READY_STATE,              /* ready to load/run */
	CNC_IE_EXEC_ERROR_STATE,         /* Execution error */
	CNC_IE_INT_ERROR_STATE,          /* interpreter error */
	CNC_IE_ABORTED_STATE,            /* job was aborted */

	/* Running states from which Pause is possible */
	CNC_IE_RUNNING_JOB_STATE,        /* Job running */
	CNC_IE_RUNNING_LINE_STATE,       /* single line running */
	CNC_IE_RUNNING_SUB_STATE,        /* single subroutine running */
	CNC_IE_RUNNING_SUB_SEARCH_STATE, /* single subroutine running from search */
	CNC_IE_RUNNING_LINE_SEARCH_STATE,/* single line running from search*/
		
	/* the belonging paused states */
	CNC_IE_PAUSED_LINE_STATE,        /* single line paused, by pause command */
	CNC_IE_PAUSED_JOB_STATE,         /* paused running job, by pause command */
	CNC_IE_PAUSED_SUB_STATE,         /* paused running sub , by pause command */
	CNC_IE_PAUSED_LINE_SEARCH_STATE, /* paused running line search line running from search*/
	CNC_IE_PAUSED_SUB_SEARCH_STATE,  /* paused running sub search subroutine running from search */

	/* special Running states, no pause possible */
	CNC_IE_RUNNING_HANDWHEEL_STATE,  /* handwheel operation */
	CNC_IE_RUNNING_LINE_HANDWHEEL_STATE,/* single line running from handwheel mode, can only be G92... */
	CNC_IE_RUNNING_LINE_PAUSED_STATE,/* single line running from handwheel mode, can only be G92... */
	CNC_IE_RUNNING_AXISJOG_STATE,     /* running joint jog */
	CNC_IE_RUNNING_IPJOG_STATE,     /* running joint jog */
	
	/* Rendering and searching states */
	CNC_IE_RENDERING_GRAPH_STATE,    /* running interpreter for graph view only */
	CNC_IE_SEARCHING_STATE,          /* searching line */
	CNC_IE_SEARCHED_DONE_STATE,      /* searched line found */

    CNC_IE_LAST_STATE                /* keep last */
};


typedef enum CNC_JOINT_STATE
{
    CNC_JOINT_POWER_UP            = 0,
    CNC_JOINT_MOVING_STATE        = 1,
    CNC_JOINT_READY_STATE         = 2,
    CNC_JOINT_READY_STOPPED_STATE = 3,
    CNC_JOINT_FREE_STATE          = 4,
    CNC_JOINT_ERROR_STATE         = 5, 
    CNC_JOINT_LAST_STATE          = 6
};

typedef enum CNC_LANG_T
{
	CNC_LANG_ENGLISH  = 0,
	CNC_LANG_GERMAN   = 1,
	CNC_LANG_DUTCH    = 2,
	CNC_LANG_ITALIAN  = 3,
	CNC_LANG_FRENCH   = 4,
	CNC_LANG_SPANISH  = 5,
	CNC_LANG_PORTUGESE = 6,
	CNC_LANG_TURKISH   = 7,
	CNC_LANG_JAPANESE  = 8,
	CNC_LANG_GRC       = 9,
	CNC_LANG_HUN       = 10,
	CNC_LANG_NEW1      = 11,
	CNC_LANG_NEW2      = 12,
	CNC_LANG_NEW3      = 13,
	CNC_LANG_NEW4      = 14,
	CNC_LANG_LAST      = 15,		//Keep last

};

//Move types used for graphics in GUI
typedef enum CNC_MOVE_TYPE
{
	CNC_MOVE_TYPE_UNKNOWN = 0,
    CNC_MOVE_TYPE_G0  = 1,
    CNC_MOVE_TYPE_G1  = 2,
    CNC_MOVE_TYPE_ARC = 3,
	CNC_MOVE_TYPE_PROBE = 4,
    CNC_MOVE_TYPE_JOG = 5,
	CNC_MOVE_TYPE_HOME = 6,
    CNC_MOVE_TYPE_ORIGIN_OFFSET = 7,
    CNC_MOVE_TYPE_TOOL_OFFSET = 8,
	CNC_MOVE_TYPE_START_POSITION = 9,
	CNC_MOVE_TYPE_SET_GRAPH_START_POINT = 10,
	CNC_MOVE_TYPE_OUT_LINE = 11,
    CNC_MOVE_TYPE_END = 12,
	CNC_MOVE_TYPE_END_COLLISION = 13
};

typedef enum CNC_TRAFFIC_LIGHT_COLOR
{
	CNC_TRAFFIC_LIGHT_COLOR_OFF = 0,
	CNC_TRAFFIC_LIGHT_COLOR_GREEN = 1,
	CNC_TRAFFIC_LIGHT_COLOR_YELLOW = 2,
	CNC_TRAFFIC_LIGHT_COLOR_RED = 3,
};


/* CNC software options */   
#define CNC_OPT_USB			(1 << 0)
#define CNC_OPT_ETHERNET  	(1 << 1)
#define CNC_OPT_TOOLCHANGE  (1 << 2)
#define CNC_OPT_TANDEMAXES  (1 << 3)
#define CNC_OPT_TANKNIFE  	(1 << 4)
#define CNC_OPT_HANDWHEEL  	(1 << 5)
/* plenty of room for more options */

//Use a packing/alignmnt of 1 byte
#pragma pack(1)

struct CNC_POSITION
{
	double x,y,z,a,b,c;
};

struct CNC_VECTOR
{
    double x,y,z;
};

/* CNC_CMD_ARRAY_PARAMETERS */
typedef struct 
{
    //A job may be executed multiple
	int			 doArray;				//1 if nesting switched on
	double		 arrayStartOffsetX;     //All objects are offset by this
	double		 arrayStartOffsetY;     //All objects are offset by this
	double		 arrayDX;				//Shift (mm) for X
	double		 arrayDY;				//Shift (mm) for y
	int          arrayNX;				//Number in x
	int          arrayNY;				//Number in y

	double       materialSizeX;         //Only used with GetJobArrayParameters
	double       materialSizeY;         //Only used with GetJobArrayParameters

} CNC_CMD_ARRAY_DATA;


typedef struct 
{
	int xPresent;
	int yPresent;
	int zPresent;
	int aPresent;
	int bPresent;
	int cPresent;
	CNC_POSITION position; //mm, work
	int activePlane; //XY=1, YZ=2, XZ=3
	int spindleOn; //0 is off, -1 is CCW, 1 is CW
	double speed;
	int mist;
	int flood;
	int tool;
	double feed;
	int inchMode;

} CNC_SEARCH_STATUS_DATA;

/* CNC_CMD_RUN_JOB, Prolog, for starting after search to line */
typedef struct 
{
	//Before execution a prolog may be executed
	int			 prologEnable;				//0=no prolog, 1=prolog
	int			 prologChangeTool;			//Perform change tool with given tool before start of job
	CNC_POSITION prologMoveToPlanePosition; //Perform XY positioning with Z at safe height (G17)
	int			 prologFlood;               //1=flood on, 0-flood off, -1 leave as is
	int          prologMist;                //Idem for mist
	int          prologSpindle;             //3 turn right, 4 turn left
	double       prologSpeed;				//Spindle speed
	int			 prologPlungeFeed;          //Feed for Z down (G17)
	double       prologPlungePos;           //Z down position
	double       prologFeed;				//Feed after plunge.
} CNC_CMD_JOB_PROLOG_DATA;


struct CNC_LOG_MESSAGE
{
    /* code where the error or what kind of message did occur, see CNC_RC */
    CNC_RC code;          

    /* the error class */
    CNC_ERROR_CLASS errorClass;

    /* subcode is only relevant when code specifies a subcode */
    int subCode;

    /* textual error or dialog description */
    char text[CNC_MAX_LOGGING_TEXT];

    /* parameter names */
    char par1Name[CNC_MAX_NAME_LENGTH];
    char par2Name[CNC_MAX_NAME_LENGTH];
    char par3Name[CNC_MAX_NAME_LENGTH];
    char par4Name[CNC_MAX_NAME_LENGTH];
    char par5Name[CNC_MAX_NAME_LENGTH];
    char par6Name[CNC_MAX_NAME_LENGTH];
	char par7Name[CNC_MAX_NAME_LENGTH];
	char par8Name[CNC_MAX_NAME_LENGTH];
	char par9Name[CNC_MAX_NAME_LENGTH];
	char par10Name[CNC_MAX_NAME_LENGTH];
	char par11Name[CNC_MAX_NAME_LENGTH];
	char par12Name[CNC_MAX_NAME_LENGTH];

    /* parameter numbers to set, 1..MAX_VARS -1 */
    int par1Number;
    int par2Number;
    int par3Number;
    int par4Number;
    int par5Number;
	int par6Number;
	int par7Number;
	int par8Number;
	int par9Number;
	int par10Number;
	int par11Number;
	int par12Number;


    /* textual description of c-source and line number,
     * this extra is debug information to see where the error
     * occured in the server.
     */
    char sourceInfo[CNC_MAX_SOURCE_INFO_TEXT];
    char functionName[CNC_MAX_FUNCTION_NAME_TEXT];

	_int64 timeStamp;

    /* number */
    int n; 
    
};



/*
  __joint_configuration_type_definitions__() 
*/
struct CNC_JOINT_CFG
{
    /* logical name of the joint, used in GUI, one character */
    char name;
	int isVissible; //True if axis vissible in GUI

    /* Axis resolution nuber of increments for one application unit */
    double resolution;
    double positiveLimit;
    double negativeLimit;

    /* max values for velocity, acceleration, AU  */
    double maxVelocity;
    double maxAcceleration;

    /* homing parameters, AU  */
    double homeVelocity; //Sign is direction
    double homePosition; //Position at home sensor

	/* backlash parameters */
	double backLash;

	/* jogspeed percentages */
	double lowSpeedJogPercent;
	double medSpeedJogPercent;
	double highSpeedJogPercent;

};

/* kinematics configuration, all related to XYZABC axes */
struct CNC_KIN_CFG
{
	int isVissible[CNC_MAX_AXES]; //True if axis vissible in GUI
	CNC_KIN_MODE axisMode[CNC_MAX_AXES];

    /* max values for velocity, acceleration, AU  */
    double maxVelocity[CNC_MAX_AXES];
    double maxAcceleration[CNC_MAX_AXES];
    double positiveLimit[CNC_MAX_AXES];
    double negativeLimit[CNC_MAX_AXES];

	/* allowed tool length with z completely down */
	double zDownToolLength;

	/* prohibited area for tool changer */
	double positiveLimitTCA[CNC_MAX_AXES];
	double negativeLimitTCA[CNC_MAX_AXES];

    /* for run time loading of user kins */
    char kinematicsDLLName[CNC_MAX_PATH];
    int  isTrivial; //1 if trivial, 0 if not

	/* disable guard in Z if 1, enable if 0 */
	int disableZCollisionGuard;

};

struct CNC_CAMERA_CONFIG
{
	int    cameraOn;	     //o=off, 1=on
	int    cameraIndex;      //0 is first, 1 is second etc.
	double toolTipOffsetX;   //Offset camera - tooltip
	double toolTipOffsetY;	 //Offset camera - tooltip
	double toolTipOffsetZ;   //Offset camera - tooltip
	double calibrationOffsetZ; //Hight at which calibration was done
	double  mmPixelRatio;     //mm to pixel

};


//Note that the tool length/diameter
//Are stored into user variables 
//Index of variable given by lenghtIndex and
//diameter index
struct CNC_TOOL_DATA_INTERNAL
{
    int     id;
    char    description[80];
    int     diameterIndex;	    //Variable index 5400 .. 5499
    int     zOffsetIndex;	    //Variable index 5500 .. 5599
    int     xOffsetIndex;	    //Variable index 5600 .. 5699
    int     orientationIndex;   //Variable index 5700 .. 5799
};

//Note that the tool length/diameter
//Are stored into user variables 
//Index of variable given by lenghtIndex and
//diameter index
struct CNC_TOOL_DATA
{
    int     id;
    char    description[80];
    double  diameter;	//Variable index 5400 .. 5499
    double  zOffset;    //Variable index 5500 .. 5599  (Length)
    double  xOffset;    //Variable index 5600 .. 5699  (width, for turning)
    int     orientation;
};


struct CNC_MACHINE_CONFIG
{
    //Server version
    char serverVersion[CNC_MAX_NAME_LENGTH];
    char lastKnownServerVersion[CNC_MAX_NAME_LENGTH];
    char lastKnownFirmwareVersion[CNC_MAX_NAME_LENGTH];


    //0: Milling, 1 :turning 
    CNC_MACHINE_TYPE machineType;
    int diameterProgramming; //Special for turning
    int absoluteCenterCoords; //if 1, circle center coordinates are absolute
    int simpleZeroing; //id 1, no pop up dialog while zeroing.
	int useOpenGL; //If 1 GUI uses OpenGL
	double openGlPenScaleFactor; //Scale factor for openGL drawing pen
	double timeEstimateFactor; //correction factor for job time estimation
	int adjustEstimation; //adjust estimation runtime based on average speed and distToGo
	int shutdownOnFatal; //Shut down on fatal, GUI takes action.
	int orthogonalView; //OpenGL shows ortogonal

	//Password for entering setup page
	char setupPassword[80];

	//The language -1=eng, 0=duits. 1=ned, 2=italy, 3=fr 4=spanje 5=portugal
	CNC_LANG_T language;

    //Name of com port e.g. "COM3"
    char comPortName[CNC_COMMPORT_NAME_LEN];

	//Find Ethernet devices also
	int  scanEthernet;

	//Editor use for edit .cnc files
	char favoriteEditor[CNC_MAX_PATH];

	//Directory where user GUI icons are loaded from
	char iconDirectory[CNC_MAX_PATH];

	//User logo file name
	char logoFileName[CNC_MAX_PATH];
	
    /* number of physical joints in the mechanism*/
    int nrOfJoints;

    /* end of stroke sense level, used for homing */
    int endOfStrokeInputSenseLevel;

    /* use end of stroke switch as emergency stop after homing */
    int useXHomeinputForAllAxes;

	/* use mist output for tool direction if tool direction is not present */
	int useMistForToolDir;

    /* switch on estop function on home sensors if all axes are homed */
    int homeIsEstopAfterHomingAllAxes;

    /* emergency stop sense level */
	int EStopInputSenseLevel1;
	int EStopInputSenseLevel2;

    /* ext error input sense level */
    int extErrorInputSenseLevel;

	/* safety input number, <= 0 none, 1 .. MAX-AUX = on, only normally input 1=safeMode, input 0=nonSafeMode */
	int safetyInputNumber;

	/* output numbers for traffic light */
	int trafficLightGreenIOID;
	int trafficLightYellowIOID;
	int trafficLightRedIOID;

	/* max feed in safety mode */
	double safetyFeed;
    
	/* Option for A,B,C   0=standard, 1=linear, 2=4axismilling */
	CNC_ROT_AXIS_OPTION abcAxisOption[3];

    /* additional for Tan Knife */
    double tanKnifeAngleForLiftUp;
    double tanKnifeLiftUpDistance;

    /* g64 active=1 or not=0 and its p-value  */
    double g64pvalue;
    int    g64Active; 

	/* G0 without start-stop delay */
	int fastG0;

	/* INCH mode active */
	int		inchModeActive;
    
    /* configuration for each joint */
    CNC_JOINT_CFG jointCfg[CNC_MAX_JOINTS];

    /* kinematics-Cartesian configuration */
    CNC_KIN_CFG kinCfg;

    /* trajectory interpolation time in seconds e.g. 0.01 second */
	double interpolationTime;
	double minCircleSegmentSize;

	/* The GUI automatically loads and runs this job file */
	char watchLoadFileName[CNC_MAX_PATH];
	int  watchFileChanged;
	int  watchAutoLoad;
	int  watchAutoRun;


	char macroFile[CNC_MAX_PATH];

    char initialString[CNC_MAX_INTERPRETER_LINE];
	int  g4InMilliseconds;

	int invertJogKeysX;
	int invertJogKeysY;
	int invertJogKeysZ;

    CNC_TOOL_DATA_INTERNAL toolTable[CNC_MAX_TOOLS + 1];
	
	/* do not halt program on tool change request */
	int noHaltForToolChange;
	/* time to wait after spindle on, before moving */
	double spindleRampUpTime;
	/* if TRUE rampuptime is proportional with speed */
	int proportionalRampUpTime;
	/* max/min spindle revolutions/sec five 100% PWM output */
	double spindleNmax;
	double spindleNmin;
	/* if true, PWM value is programmed according to spindle speed */
	int spindleUseRPMSensor;
	/* if true show spindle RPM in GUI if there is a spindle sync input on the connected CPU */
	int spindleShowRPM;

	/* show raw joint pos value, including backlash */
	int showRawJointPos;

    /* show terms if not already shown */
    int showTerms;

    /* show startup screen */
    int showStartupScreen;

	/* show graph buttons for zooming etc */
	int showGraphZoomButtons;

	/* choose max step rate of controller */
	int controllerTimerDividerIndex;

	/* choose polarity of step pulse output */
	int stepPulsePolarity;

	/* 1 if height probe is present, 0 if not */
	int heightProbePresent;

	/* Offset for height probe */
	double heightProbeOffset;

    /* handwheel encoder count for one revolution */
    int handwheelCountPerRev;
	/* vel limit for handwheel percentage of selected axis max vel */
	int handweelVPercent;
	/* acc limit for handwheel percentage of selected axis max acc */
	int handwheelAPercent;

	/* velocity mode for 1x scale */
	int handwheelX1VelMode;
	/* velocity mode for 10x scale */
	int handwheelX10VelMode;
	/* velocity mode for 100x scale */
	int handwheelX100VelMode;
	/* if TRUE, use handwheel for feedOV control */
	int useHandWheelForFeedOverride; 
 
	/* if 1, probe touch points are stored in digitize file name */
	int storeProbeTouchPoints;
	/* file name to store probe touch points */
    char probeTouchPointFileName[CNC_MAX_PATH];
	/* beep if probe triggers */
	int probeBeep;
	/* probe input */
	int probeUseHomeInput4;
	/* analog probing using analog input 3 of CPU */
	double probeVoltIncToMM;

    /* if TRUE, the lookahead feed trajectory generator is used */
    int useLAF;

    /* look ahead feed angle in degrees, connecting lines with 
       angle between this value and 180 are considered straight */
    double lafAngle;

    /* Homing mandatory or not, 1=mandatory */
    int mandatoryHoming;

	/* long file mode criterion in bytes, GUI switches to low memory usage */
	int longFileModeCriterion;

	/* super long file mode criterion in bytes, Server runs job from file in stead of memory */
	int superLongFileModeCriterion;

    /* GPIO */
    int gpioNrOffOutputs;
    int gpioUsePullUp;

	/* config parameters of USB camera */
	CNC_CAMERA_CONFIG cameraCfg;
};


struct CNC_IO_PORT_STS
{
    CNC_IO_ID      ioId;	//The ID
	int			   invert;	//Actually configuration item
	int            lvalue;	//the current logic value, active/on = 1, inactive/off = 0
	int            rvalue;	//the current raw value
    int            present;	//1 if present
};


struct CNC_JOINT_STS
{    
    /* joint index starting from 0 */
    char            jointIndex;
    CNC_JOINT_STATE state;
    int             errorWord;
	double          position; 
	double          positionRaw; 
    double          maxPositionError ;
    int             isHomed;
    int             homeSensorStatus;
};


struct CNC_JOB_RENDER_STATUS
{    
	/* 0 if job needs rendering, 1 if rendered */
	int jobIsRendered;

	/* total job length in mm */
	double totalJobLength;

	/* length of job done */
	double jobProgress;

	/* actual running time */
    double jobActualRunningTime;

	/* Estimated remaining running time */
    double jobRemainingRunningTime;

    /* Estimated total Time */
    double jobEstimatedTime;

	/* job collision status */
	int TCACollision;
	int MCACollision;
	int xCollision;
	int yCollision;
	int zCollision;

    /* render progress */
    int jobRenderLine;
    double jobRenderProgressPercentage;
};




struct CNC_MACHINE_STS
{
	
	//List of connections for Gui, depending on detected CPU BULK or COMM port
	int  comPortListSize;
	char comPortList[CNC_MAX_COMM_PORTS][CNC_COMMPORT_NAME_LEN];
	int  connectedViaEtherNet;
	int  connectedViaUSB;
	int  connectedViaSimulation;
	int  cpuIsEnabled; //if False, a g-code program cannot be run
	int  safeMode; //1 if safemode active

	CNC_TRAFFIC_LIGHT_COLOR trafficLightColor;
	int trafficLightBlink;//True if blink
	char traficLightReason[CNC_MAX_LOGGING_TEXT];

	/* Controller firmware version, max axes, lathe capability */
	char controllerFirmwareVersion[CNC_MAX_NAME_LENGTH];
    int  controllerMaxAxes; 
    /* axis that are visible or slave, and remaining axes of CPU */
    int  cncAxisAvailable[CNC_MAX_AXES];

	/* 1 if firmware has SW options */
	int  firmwareHasOptions;


    /* only axes that are configured as visible and or slave */
    int  cncAxisConfigured[CNC_MAX_AXES];
    int  syncIOPresent; 

    /* controller frequency table */
    double controllerFrequencies[CNC_MAX_FREQENCY_TABLE_LEN];
    int    controllerFrequencyTimerValues[CNC_MAX_FREQENCY_TABLE_LEN];
    int    controllerNumberOfFrequencies;

	/* Job file name*/
    char jobName[CNC_MAX_PATH];

	/* filename for macro's, e.g. tool change */
    char subroutineName[CNC_MAX_PATH];

	/* 0 if real mode, 1 and 2 are simulation mode, 1 normal, 2 fast */
	int simulationMode;


	/* 0 block delete is off, 1 block delete is on */
	int blockDelete;

    /* state of the interpreter/execution task */
    CNC_IE_STATE state;

    /* state before ABORT */
    CNC_IE_STATE stateBeforeAbort;        

    /* state before INT_ERROR EXE_ERROR */
    CNC_IE_STATE stateBeforeError;          

    /* state before manual operation command */
    CNC_IE_STATE stateBeforeManOp;      

	/* 1 if paused for manual action, like manual tool change */
	int pauseManualActionRequired;

    /* current interpreter line number starting from 1*/
    int curIpLine;

	/* current interpreter text */
	char curIpLineText[CNC_MAX_INTERPRETER_LINE+1];

	/* current character index of line */
	int curIpCol;

    /* current execution line number starting from 1*/
    int curExLine;

    /* TRUE when single stepping mode active */
    int stepMode;

	/* feed override set by GUI */
	double userFeedOverride;

    int abortRequest;                 /* abort request is set asynchronously  */
    int jointHoming[CNC_MAX_JOINTS];  /* true for the joints that are homing  */
    int jointJogging[CNC_MAX_JOINTS]; /* true for the joints that are jogging */

    CNC_LOG_MESSAGE  lastIntError;   /* last interpreter error info, a sync */
    CNC_LOG_MESSAGE  lastExeError;   /* last execution error, a sync */
    CNC_LOG_MESSAGE  lastCmdError;   /* last command error, sync */
    
    /************************************************/

    /* physical status of joints and IO */
    CNC_JOINT_STS jointSts[CNC_MAX_JOINTS];
    CNC_IO_PORT_STS ioSts[CNC_MAX_IO_PORTS];

    /* free size in CPU motion fifo */
    unsigned char cpuFifoFreeSize;

    /* filled size in CPU motion fifo */
    unsigned char cpuFifoFilledSize;

    /* motion enabled status */
    int motionEnabled;

    /* homing or probing is active */
    int capturing;

    /* position captured */
    int isCaptured;
	double capturePosition[CNC_MAX_JOINTS];

    /* motion error word */
    int errorWord;

    /* active G-code for each of the G-code groups, the value contains the active gcode in the group multiplied by 10  */
    int  ActiveGCodes[16];

    /* idem for M-code for each of the M groups */
    int  ActiveMCodes[10];

    /* settings lineNumber, current Feed, current Speed, current Tool (LFST)*/
    double ActiveGSettings[4];
    
    /* position relative to machine zero point */
    CNC_POSITION machineCartesianPosition;
    /* active coordinate system offset G54 ... + G92 */
    /* with this and above machine position, the program position is to be calculated */
    CNC_POSITION activeCoordinateSystemOffset;
	CNC_POSITION xy_rotationPoint;
	int          xy_rotationIsOn;
	double xy_rotationDegrees;
	double activeToolZOffset;
	double activeToolXOffset;

    /* the current one, for G code see G10 L2 P#*/
    int  current; 

     /* actual feed in X-Y plane, traveled distance / time * 60 [mm/minute]*/
	double actualFeed;
    
	/* TRUE if tangential knife mode is active, C-Axis follows X,Y direction */
	int tanKnifeIsOn;

     /* position which is stored after pause */
    CNC_POSITION pausePosition;
    int pausePositionValid;
	int pausePositionLine;
	int pauseSpindleIOValue;
	int pauseFloodIOValue;
	int pauseMistIOValue;

	int pauseArrayIndexX; //1 based, needed for UI
	int pauseArrayIndexY; //1 based, needed for UI
	int pauseDoArray;

    /* error status of execution, interpreter and command */
    CNC_RC errorNumber;

    /* handwheel count */
    int handWheelCount1;
    int handWheelCount2;

    /* sync count, spindle pulse */
    int syncCount;

    /* spindle rate, rev/sec */
    double spindleRate;

    /* job render status */
    CNC_JOB_RENDER_STATUS jobRenderStatus;

	/* job array status */
	int doArray;
	int arrayNX;
	int arrayNY;
	double arrayDX;
	double arrayDY;
	double arrayStartOffsetX;
	double arrayStartOffsetY;
	double arrayMaterialSizeX;
	double arrayMaterialSizeY;
	int arrayCurXIndex;
	int arrayCurYIndex;
	double arrayCurXOffset;
	double arrayCurYOffset;


    /* incremented every motion update cycle */
    int heartBeat;
    
};



struct CNC_TIME_STAMP
{
    _int64 startTime; 
    _int64 timeStamp;
};

struct CNC_POS_FIFO_DATA
{
	CNC_POSITION   pos;         /* x,y,z position vector  */
	CNC_MOVE_TYPE  type;    /* see GRAPH type         */
};

struct CNC_GRAPH_FIFO_DATA
{
    int            lineNumber;
	CNC_POSITION   pos;     /* end position, origin offset, start pos, tool offset, depending on type */
	CNC_MOVE_TYPE  type;    /* see GRAPH type         */
};


struct CNC_RENDER_DATA
{
	int            lineNr;  /* job line number */
	CNC_MOVE_TYPE  type;    /* see GRAPH type         */
	CNC_POSITION   pos;     /* end position, origin offset, start pos, tool offset, depending on type */
    CNC_VECTOR     center;  /* center for arc */
    CNC_VECTOR     normal;  /* for arc */
	int	turn;				/* for arc direction & n of turns */
	double         toolZOffset;
	double		   toolXOffset;
	double         rotationDegrees;
	CNC_POSITION   rotationPoint;
	bool           rotationIsOn;
	double		   velocity;
    double		   acceleration;
	bool		   linearIsLeading;

};

//Fool compiler to think a variable is used
#define CNC_UNUSED( ident )  (void) (ident = ident)

    
#pragma pack()






#endif //already included
