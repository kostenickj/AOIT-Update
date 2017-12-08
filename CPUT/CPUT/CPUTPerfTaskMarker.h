/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CPUTPERFTASKMARKER_H__
#define __CPUTPERFTASKMARKER_H__



#include "CPUT.h"


#ifdef CPUT_GPA_INSTRUMENTATION

// GPA instrumentation helper class - only available in profile build
// Allows you to easily add 'task markers' to certain events
//-----------------------------------------------------------------------------
class CPUTPerfTaskMarker
{
public:
    CPUTPerfTaskMarker(DWORD color, wchar_t *pString);
    ~CPUTPerfTaskMarker();
private:

};
#endif

#endif // #ifndef __CPUTPERFTASKMARKER_H__