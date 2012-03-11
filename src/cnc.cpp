#include "cnc.h"
#include "cncapi.h"

CNC::CNC(QWidget *parent) :
    QMainWindow(parent)
{
    CNC_RC RES = CncConnectServer("cnc.ini");

    int jobFileLength, macroFileLength, isLongJob, isSuperLongJob;
    qint64 sizeInBytes;

    CncLoadJob("makro.cnc", &jobFileLength, &macroFileLength, &isLongJob, &isSuperLongJob, &sizeInBytes);
    RES = CncReset();
    RES = CncSetOutput(CNC_IOID_DRIVE_ENABLE_OUT,1);
    printf("%s\n",CncGetStateText(CncGetState()));
    printf("%s\n",CncGetControllerFirmwareVersion());
    printf("Error: %i\n",RES);


}
bool CNC::SetToolPos(TOOL_POS NewPosition){

    CNC_POSITION Pos;
    int move[6]         = {1,1,1,0,0,0};

    if(NewPosition.x >= SpaceLimits.x) return false;
    if(NewPosition.y >= SpaceLimits.y) return false;
    if(NewPosition.z >= SpaceLimits.z) return false;
    if(NewPosition.angle >= SpaceLimits.angle) return false;


    Pos.x =   ToolTipPosition.x - (ToolTipPosition.x - NewPosition.x);
    Pos.y =   ToolTipPosition.y - (ToolTipPosition.y - NewPosition.y);
    Pos.z =   ToolTipPosition.z - (ToolTipPosition.z - NewPosition.z);

    Pos.a = 0;
    Pos.b = 0;
    Pos.c = 0;

    CncMoveTo(Pos,move,1.0);
    return true;
}



void CNC::StartMoveCont(int Axis){
    double Ax[4] = {0,0,0,0};

    if(Axis < 0){
        Ax[(Axis*(-1))-1]    =   -1;
    }
    else{
        Ax[Axis-1]        =     1;
    }

    double Velocity = 1;
 //   if(Direction==true){ Velocity = -Velocity; }
   CNC_RC RC = CncStartJog(Ax,Velocity,1);
 //   CncStartJog2(int axis,
 //                                        double step,
 //                                        double velocityFactor,
 //                                        int continuous);
}

void CNC::StopMoveCont(){
    CncStopJog(0);
    CncStopJog(1);
    CncStopJog(2);
    CncStopJog(3);
    //CncStopJog(0);
}

TOOL_POS CNC::ToolPos(){

    return ToolTipPosition;
}

bool CNC::SetToolLength(double NewToolLenght){
    double ToolTipZPosition =   ToolTipPosition.z - (ToolLenght - NewToolLenght);
    if(ToolTipZPosition <= SpaceLimits.z){
        ToolTipPosition.z =   ToolTipZPosition;
        ToolLenght  =   NewToolLenght;
        return true;
    }
    else{
        return false;
    }
}

TOOL_POS CNC::ToolPosFromCNCPos(){

    TOOL_POS TempToolPos;
    TempToolPos.x     =   CNCPos.x + Offset.x;
    TempToolPos.y     =   CNCPos.y + Offset.y;
    TempToolPos.z     =   CNCPos.z + Offset.z;
    TempToolPos.angle =   ToolTipPosition.angle;
    return TempToolPos;

}

CNC_POSITION CNC::CNCPosFromToolPos(){

    CNC_POSITION TempCNCPos;
    TempCNCPos.x = ToolTipPosition.x - Offset.x;
    TempCNCPos.y = ToolTipPosition.y - Offset.y;
    TempCNCPos.z = ToolTipPosition.z - Offset.z;
    TempCNCPos.a = 0;
    TempCNCPos.b = 0;
    TempCNCPos.c = 0;
    return TempCNCPos;
}
