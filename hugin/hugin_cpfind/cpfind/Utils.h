/*
* Copyright (C) 2007-2008 Anael Orlinski
*
* This file is part of Panomatic.
*
* Panomatic is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* Panomatic is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Panomatic; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __utils_h
#define __utils_h

#ifdef WIN32
#include <vigra/windows.h>
#include <process.h>
#else
//#include <pthread.h>
#include <sys/time.h>
#endif

#include <zthread/Condition.h>
#include <zthread/FastMutex.h>
#include <zthread/Guard.h>



#define TIMETRACE(TEXT, CODE) { utils::os_TIME t1,t2; utils::os_GetTime(&t1); CODE; \
        utils::os_GetTime(&t2); std::cout << TEXT << " took " << utils::os_TimeDiff(&t2,&t1)/1000.0 << " seconds." << std::endl; }


namespace utils
{

//extern "C" {

#ifdef WIN32
typedef DWORD os_TIME;
#else
typedef struct timeval os_TIME;
#endif

inline void os_GetTime(os_TIME* time)
{
#ifdef WIN32
    *time = GetTickCount();
#else
    struct timezone tz;
    gettimeofday(time, &tz);
#endif
}

inline int os_TimeDiff(os_TIME* time1, os_TIME* time2)
{
#ifdef WIN32
    return *time1 - *time2;
#else
    return (int)((double)time1->tv_sec*1000 + ((double)time1->tv_usec)*1e-3 -
                 (double)time2->tv_sec*1000 - ((double)time2->tv_usec)*1e-3);
#endif
}

/** returns the total memory in byte */
unsigned long long getTotalMemory();

}

#endif // __utils_h
