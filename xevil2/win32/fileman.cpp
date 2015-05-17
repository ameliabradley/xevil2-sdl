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

#include "stdafx.h"


#include "fileman.h"


#define TEMP_DEFAULT_PREPEND "~xtmp"
#define DELTA_SIZE 5
#define MAX_TEMP_FILES_DIGITS 3
#define MAX_TEMP_FILES 100


TempFileManager::TempFileManager()
:directoryname(NULL),tempfiles(NULL), 
numtempfiles(0),buffersize(0)
{
}



TempFileManager::~TempFileManager()
{
    cleanup();
    if (directoryname)
        free(directoryname);
}



/**************************
public methods
**************************/

/*
windows specific implementations
*/
void
TempFileManager::attachDirectory(const char *dirname)
{
    if (!dirname)
        return;
    if (directoryname) {
        cleanup();
        free(directoryname);
    }
    directoryname = strdup(dirname);
    
    CString t_string=directoryname;
    t_string += TEMP_DEFAULT_PREPEND;
    t_string += '*';
    WIN32_FIND_DATA c_file;
    /* find first .c file in current directory */
    HANDLE t_handle;
    if (INVALID_HANDLE_VALUE != (t_handle=FindFirstFile( t_string.GetBuffer(0), &c_file)) )
    {
        CString t_newfile;
        if (c_file.cFileName) {
           t_newfile =  directoryname;
           t_newfile += c_file.cFileName;
        }
        addName(strdup(t_newfile.GetBuffer(0)));
        t_newfile.ReleaseBuffer();
        /* Find the rest of the xtm files */
        while( FindNextFile( t_handle,&c_file )  )
        {
           if (c_file.cFileName) {
               t_newfile= directoryname;
               t_newfile += '\\';
               t_newfile+= c_file.cFileName;
           }
            addName(strdup(t_newfile.GetBuffer(0)));
            t_newfile.ReleaseBuffer();
        }
    }

}



const char *
TempFileManager::getTempFileByIndex( int index )
{
    if ((index < numtempfiles) && (index >=0)) {
        return tempfiles[index];
    }
    return NULL;
}



/*
delete all files in tempfiles list
leave directory name alone.
*/
void
TempFileManager::cleanup()
{
    for (int i=0;i < numtempfiles; i++)
    {
        try
        {
            CFile::Remove(tempfiles[i]);
        }
        catch (CFileException*)
        {
//            assert(0);  commented hardts
        }
        free (tempfiles[i]);
    }
    if (tempfiles)
        free (tempfiles);
    tempfiles = NULL;
    numtempfiles = 0;
    buffersize = 0;
}



const char *
TempFileManager::newTempFileName(const char *ext)
{
    if (!directoryname || !ext)
        return NULL;

    CString buffer;
    UINT t_result = GetTempFileName(directoryname,TEMP_DEFAULT_PREPEND, TRUE, buffer.GetBuffer(MAX_PATH));
    buffer.ReleaseBuffer();
    buffer = buffer.Left(buffer.ReverseFind('.')+1);
    buffer += ext;
    if (!t_result)
        return NULL;
    addName(strdup(buffer.GetBuffer(0)));
    return tempfiles[numtempfiles-1];
}






/**************************
helper methods
**************************/
void
TempFileManager::addName( char *name )
{
    if (!tempfiles)
    {
        tempfiles = (char **) malloc(DELTA_SIZE * (sizeof (char *)));
        if (!tempfiles)
            return;
        buffersize = DELTA_SIZE;
    }
    else if (numtempfiles >= buffersize)
    {
        char **t_tempfiles = (char **) realloc(tempfiles,(buffersize+DELTA_SIZE) * (sizeof (char *)));
        if (!t_tempfiles)
            return;
        tempfiles = t_tempfiles;
        buffersize += DELTA_SIZE;
    }
    if (numtempfiles > MAX_TEMP_FILES)
    {
        cleanup();
        return;
    }
    tempfiles[numtempfiles ++] = name;
}


