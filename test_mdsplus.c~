//Test of pulling magnetics data from tree
//T. Golfinopoulos, 29 Dec. 2017

#include <stdio.h>
#include <string.h>
#include <mdslib.h>

#define status_ok(status) (((status) & 1) == 1 )

int main(int argc, char *argv[]){
    /* local vars */
    int status;
    int null=0;
    int socket;
    float *data; /* Array of floats used for signal */
    float *timebase; /*array of floats used for timebase */
    int sigdesc; /* signal descriptor */
    int timedesc; /* descriptor for timebase */
    int size; /* length of signal */
    int i, len;
    int s=1160607001; //Shot number
    
    /* Connect to MDSplus */
    socket=MdsConnect("alcdata.psfc.mit.edu");
    
    if(socket==-1){
        fprintf(stderr,"Error connecting to alcdata.\n");
        return -1;
    }
    
    /* Open tree */
    status=MdsOpen("Magnetics",s);
    if( !status_ok(status) ){
        /* error */
        fprintf(stderr,"Error opening tree for shot %1.\n",s);
    }
    
    //Retrieve signal
    status=MdsValue("active_mhd.signals.bp1t_ghk", &sigdesc, &null, &len);
    if(!status_ok(status)){
        /* error */
        fprintf(stderr,"Error retrieving signal\n");
        return -1;
    }
    
    printf("Len=%d",len);
}
