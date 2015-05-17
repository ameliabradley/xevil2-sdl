/*
 *  XEvil(TM) Copyright (C) 1994,1999  Steve Hardt and Michael Judge
 *  
 *  The file, license.txt, distributed along with this source code contains
 *  the license agreement for the XEvil source code and executable.
 *  If you do not have this file, obtain a copy from 
 *  http://www.xevil.com/docs/license.txt
 * 
 *  http://www.xevil.com
 *  satan@xevil.com
 */

// "role.cpp"


#ifndef NETH_H
#define NETH_H

#include "utils.h"

// Just used to get all the network headers.
// Should only be included by .cpp files.

#if X11
#include <unistd.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/signal.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#endif

// For recvfrom() and accept, fucking AIX 2.4
#ifdef USE_ULONG_NET_LENGTH
typedef unsigned long CMN_NET_LENGTH;
// Red Hat Linux likes unsigned int
#elif defined USE_UINT_NET_LENGTH
typedef unsigned int CMN_NET_LENGTH;
#else
typedef int CMN_NET_LENGTH;
#endif


#if X11
#ifdef SELECT_NEEDS_PROTOTYPES
extern "C" {
int select(int,
	   fd_set *,
	   fd_set *,
	   fd_set *,
	   struct timeval *);
}
#endif
#ifdef USE_SELECT_H
extern "C" {
#include <sys/select.h>
}
#endif

#endif


#if WIN32
#include <sys/utime.h>
#include <signal.h>
#endif


// Stuff that might be useful
#if 0
struct sockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
};
#endif



#ifdef SELECT_TAKES_INTP
  #define CMN_SELECT(sockNum,readSock,writeSock,exceptSock,timeout) \
  select(sockNum,((int *)readSock),((int *)writeSock),((int *)exceptSock),timeout)
#else
  #define CMN_SELECT(sockNum,readSock,writeSock,exceptSock,timeout) \
  select(sockNum,readSock,writeSock,exceptSock,timeout)
#endif



#if X11
#define CLOSE_SOCKET(sck) close(sck)
#endif
#if WIN32
#define CLOSE_SOCKET(sck) closesocket(sck)
#endif

#endif

