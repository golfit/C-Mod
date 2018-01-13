/*
 ============================================================================
 Name        : mode_survey_c.c
 Author      : Theodore Golfinopoulos
 Version     :
 Copyright   : 2018, All rights reserved, MIT License
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <mdslib.h> //To resolve this for C, need to go to Project -> Properties -> C/C++ Build -> Settings -> Tool Settings -> GCC C Compiler -> Includes and add /usr/local/mdsplus/include

//using namespace MDSplus; //Import MDSplus namespace
//For this to work in Eclipse:
//1. Project -> Properties -> C/C++ Build -> Settings -> Tool Settings -> GCC C Compiler -> Includes and add /usr/local/mdsplus/include
//2. Project -> Properties -> C/C++ Build -> Settings -> Tool Settings -> GCC Linker -> Libraries -> Add MdsLib to libraries (-l option)
//3. Project -> Properties -> C/C++ Build -> Settings -> Tool Settings -> GCC C Linker -> Libraries -> Add /usr/local/mdsplus/lib to search paths

/* Define a macro to check status of MDSplus functions */
#define status_ok(status) (((status) & 1) == 1)

int get_signal_length(const char *signal){
  /* local vars */
  int dtype_long = DTYPE_LONG;
  char buf[1024];
  int size;
  int null = 0;
  int idesc = descr(&dtype_long, &size, &null);
  int status;

  /* init buffer */
  memset(buf,0,sizeof(buf));

  /* put SIZE() TDI function around signal name */
  snprintf(buf,sizeof(buf)-1,"SIZE(%s)",signal);

  printf("Getting signal length...");
  printf("%s",buf);

  /* use MdsValue to get the signal length */
  status = MdsValue(buf, &idesc, &null, 0);
  if ( !status_ok(status) )
  {
    fprintf(stderr,"Unable to get length of %s.\n",signal);
    return EXIT_FAILURE;
  }
  printf("...done - size=%d\n",size);

  /* return signal length */
  return size;

}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	 /* local vars */
//	int dtype_float = DTYPE_FLOAT;
	int null = 0;
	int status;
	int socket;
	float *data;     /* array of floats used for signal */
	//float data[]; //Array of floats - explicit array notation, rather than pointer.
//	float *timebase; /* array of floats used for timebase */
	int sigdesc;     /* signal descriptor */
//	int timedesc;    /* descriptor for timebase */
	int size;        /* length of signal */
	int i, len;
//	int shot = 100;  /* just an example shot number */

	//char node_path[]="\\MAGNETICS::TOP.ACTIVE_MHD.SIGNALS:BP5T_ABK";
	char node_path[]="ACTIVE_MHD.SIGNALS:BP5T_ABK";

	/* Connect to MDSplus */
	socket = MdsConnect("alcdata.psfc.mit.edu");
	if ( socket == -1 ) {
	  fprintf(stderr,"Error connecting to data system.\n");
	  return -1;
	}
	printf("Done opening connection, socket=%d.  Opening tree next...\n",socket);

	//Open Tree
	int shot=1140807001;
	status = MdsOpen("MAGNETICS", &shot);
	if ( !status_ok(status) ){
	  fprintf(stderr,"Error opening tree for shot %l.\n",shot);
	  return -1;
	}
	printf("Done opening tree, shot=%d.  Getting size next...\n",shot);

	/* use get_signal_length to get size of signal */
	size = get_signal_length(node_path);
	if ( size < 1 )
	{
	  /* error */
	  fprintf(stderr,"Error retrieving length of signal\n");
	  return EXIT_FAILURE;
	}
	printf("Done getting size, size=%d.  Allocating memory next...\n",size);
//
	//Allocate memory for signal
	/* use malloc() to allocate memory for the signal */
	data = (float *)malloc(size * sizeof(float));
	if ( !data )
	{
	  fprintf(stderr,"Error allocating memory for data\n");
	  return EXIT_FAILURE;
	}
	printf("Done allocating memory.  Retrieving signal next...\n");

	/* retrieve signal */
	status = MdsValue(node_path,&sigdesc, &null, &len );
	if ( !status_ok(status) )
	{
	  /* error */
	  fprintf(stderr,"Error retrieving signal\n");
	  free( (void *)data );
	  return EXIT_FAILURE;
	}
	printf("len=%d\n",len);

//	printf("Socket=%d\n",socket);
	printf("Done.");

	return EXIT_SUCCESS;
}

