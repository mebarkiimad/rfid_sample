#include <stdio.h>
#include <stdlib.h>
#include "twn4.sys.h"
#include "apptools.h"
#include "prs.h"
int main()
{
    TCOMParameters COMParameters;
    COMParameters.BaudRate = 115200;
  	COMParameters.WordLength = COM_WORDLENGTH_8;
	COMParameters.Parity = COM_PARITY_NONE;
  	COMParameters.StopBits = COM_STOPBITS_1;
	COMParameters.FlowControl = COM_FLOWCONTROL_NONE;
		int HostChannel = GetHostChannel();
    printf("Hello World !\n");
    return 0;
}
