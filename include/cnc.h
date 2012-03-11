#ifndef CNC_H
#define CNC_H

#include "cncapi/cnc_types.h"
#include <QMainWindow>

struct TOOL_POS
{
    double x,y,z;
    int angle;
};
struct OFFSET
{
    double x,y,z;
};


class CNC : public QMainWindow
{
    Q_OBJECT
public:
    explicit CNC(QWidget *parent = 0);
    
signals:

public slots:
    //Return the actual tool position
    TOOL_POS ToolPos();

    //Continuous tool movement
    void StartMoveCont(int Axis);
    void StopMoveCont();

    //Move Tool to coordinates
    bool SetToolPos(TOOL_POS NewPosition);

    bool SetToolLength(double ToolLenght);

private:

    double ToolLenght;

    //Limit of the available space in x, y and z
    TOOL_POS SpaceLimits;

    //Actual CNC Position as used by USBCNC
    CNC_POSITION CNCPos;

    //Offset between the ToolTip and CNCPos
    OFFSET Offset;

    //Tool Position is CNCPos with offset defined by the design of the Toolhead
    TOOL_POS ToolTipPosition;

    //Calculate the Tooltip position based on CNCPos and ToolLenght
    TOOL_POS ToolPosFromCNCPos();
    CNC_POSITION CNCPosFromToolPos();

    
};

#endif // CNC_H
