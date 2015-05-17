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

#ifndef _FILEMAN_H
#define _FILEMAN_H


class TempFileManager
{
    char *directoryname; //stores the temp directory name 
    char **tempfiles;    //array of temporary files
    int numtempfiles;    //number of temporary files
    int buffersize;      //size of buffer for temp file array
    void addName(char *);//private method that adds a name to the temp file array
public:
    TempFileManager(); 
    ~TempFileManager();

    const char *newTempFileName(const char *ext); //returns a new name prepended with ~xtmp

    int getNumTempFiles(){return numtempfiles;} //returns number of temporary files
    const char *getTempFileByIndex(int index);  //returns filename from the index into the array
    void cleanup();                             //deletes the files from the temp file list.

    /*attachDirecetory goes through passed in directory and adds all appropriate files to the 
      temp file array */
    void attachDirectory(const char *dirname);  
};

#endif //_FILEMAN_H
