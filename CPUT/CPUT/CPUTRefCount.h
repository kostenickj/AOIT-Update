/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __CPUTREFCOUNT_H__
#define __CPUTREFCOUNT_H__

#include "CPUT.h"

// Reference counting class
//-----------------------------------------------------------------------------
class CPUTRefCount
{
private:
    mutable UINT mRefCount;

protected:
    virtual ~CPUTRefCount(){} // Destructor is not public.  Must release instead of delete.

public:
    CPUTRefCount():mRefCount(1){}
    int AddRef() const { return ++mRefCount; }
    int GetRefCount() const { return mRefCount; }
    int Release() const
    {
        UINT u = --mRefCount;
        if(0==mRefCount)
        {
            delete this;
        }
        return u;
    }
};

#endif // __CPUTREFCOUNT_H__

