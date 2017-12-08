/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __CPUTLight_H__
#define __CPUTLight_H__

#include "CPUT.h"
#include "CPUTRenderNode.h"
#include "CPUTConfigBlock.h"

enum LightType
{
    CPUT_LIGHT_DIRECTIONAL,
    CPUT_LIGHT_POINT,
    CPUT_LIGHT_SPOT,
};

struct CPUTLightParams
{
    LightType   nLightType;
    float       pColor[3];
    float       fIntensity;
    float       fInnerAngle;
    float       fOuterAngle;
    float       fDecayStart;
    bool        bEnableNearAttenuation;
    bool        bEnableFarAttenuation;
    float       fNearAttenuationStart;
    float       fNearAttenuationEnd;
    float       fFarAttenuationStart;
    float       fFarAttenuationEnd;
	bool		bCastShadows;
};

class CPUTLight:public CPUTRenderNode
{
protected:
    CPUTLightParams mLightParams;
public:
    CPUTLight() {}
    virtual ~CPUTLight() {}

    CPUT_NODE_TYPE GetNodeType() { return CPUT_NODE_LIGHT;};

    void             SetLightParameters(CPUTLightParams &lightParams);
    CPUTLightParams *GetLightParameters() {return &mLightParams; }
    CPUTResult       LoadLight(CPUTConfigBlock *pBlock, int *pParentID);
};

#endif //#ifndef __CPUTLight_H__