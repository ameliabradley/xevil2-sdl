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

// "xetp_basic.cpp"

#if X11
	#ifndef NO_PRAGMAS
	#pragma implementation "xetp_basic.h"
	#endif
#endif

#include "stdafx.h"


#include "xetp_basic.h"


char *XETPBasic::versionStr = "XETP1.00";
// 0.10 released with special RedHat version
// 0.12 for 2.0b5
// 0.15 for 2.0b6
// 0.16 for 2.0b7
// 1.00 for 2.0



void XETPBasic::check_sizes() {
  // If this ever fails, we'll have to put in a bunch of cross-platform 
  // typedefs.
  assert(sizeof(int) == 4);
  assert(sizeof(short) == 2);
  assert(sizeof(char) == 1);
  assert(sizeof(float) == 4);
  assert(sizeof(u_int) == 4);
  assert(sizeof(u_short) == 2);
  assert(sizeof(u_char) == 1);

  // If we get to 256, need more than one byte to determine the method.
  assert(XETP_METHOD_MAX <= 256);
}



Boolean XETPBasic::receive_header(InStreamP inStream,
                             u_short &method,u_int &length) {
  method = (u_short)inStream->read_char();
  length = (u_int)inStream->read_short();

  return inStream->alive();
}



void XETPBasic::send_header(OutStreamP out,u_short method,u_int length) {
  // <method:1><length:4>

  assert(method <= UCHAR_MAX);
  out->write_char((u_char)method);
  assert(length <= USHRT_MAX);
  out->write_short((u_short)length);
}



void XETPBasic::send_generic(OutStreamP out,u_short method) {
  if (out->get_protocol() == GenericStream::UDP) {
    ((UDPOutStreamP)out)->prepare_packet(XETPBasic::add_header(0));
  }
  send_header(out,method,0);
  if (out->get_protocol() == GenericStream::UDP) {
    ((UDPOutStreamP)out)->done_packet();
  }
}



void XETPBasic::send_int(OutStreamP out,u_short method,u_int val) {
  int len = sizeof(int);
  if (out->get_protocol() == GenericStream::UDP) {
    ((UDPOutStreamP)out)->prepare_packet(XETPBasic::add_header(len));
  }
  send_header(out,method,len);
  out->write_int(val);
  if (out->get_protocol() == GenericStream::UDP) {
    ((UDPOutStreamP)out)->done_packet();
  }
}



void XETPBasic::send_string(OutStreamP out,u_short method,char *msg) {
  assert(msg);
  int len = Utils::get_string_write_length(msg);
  if (out->get_protocol() == GenericStream::UDP) {
    ((UDPOutStreamP)out)->prepare_packet(XETPBasic::add_header(len));
  }
  send_header(out,method,len);
  Utils::string_write(out,msg);
  if (out->get_protocol() == GenericStream::UDP) {
    ((UDPOutStreamP)out)->done_packet();
  }
}



const CMN_PORT XETPBasic::DEFAULT_PORT = 6066;
