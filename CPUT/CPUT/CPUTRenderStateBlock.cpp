/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////
#include "CPUTAssetLibrary.h"

#include "CPUTRenderStateBlock.h"
#ifdef CPUT_FOR_DX11
#include "CPUTRenderStateBlockDX11.h"
#elif (defined(CPUT_FOR_OGL) || defined (CPUT_FOR_OGLES))
    #include "CPUTRenderStateBlockOGL.h"
#else
    #error You must supply a target graphics API (ex: #define CPUT_FOR_DX11), or implement the target API for this file.
#endif


CPUTRenderStateBlock *CPUTRenderStateBlock::mpDefaultRenderStateBlock = NULL;

CPUTRenderStateBlock *CPUTRenderStateBlock::CreateRenderStateBlock( const cString &name, const cString &absolutePathAndFilename )
{
#ifdef CPUT_FOR_DX11
    CPUTRenderStateBlock *pRenderStateBlock = new CPUTRenderStateBlockDX11();
#elif (defined(CPUT_FOR_OGL) || defined (CPUT_FOR_OGLES))
    CPUTRenderStateBlock *pRenderStateBlock = new CPUTRenderStateBlockOGL();
#else
    #error You must supply a target graphics API (ex: #define CPUT_FOR_DX11), or implement the target API for this file.
#endif
    pRenderStateBlock->LoadRenderStateBlock( absolutePathAndFilename );

    // add to library
    CPUTAssetLibrary::GetAssetLibrary()->AddRenderStateBlock( absolutePathAndFilename, _L(""), _L(""), pRenderStateBlock );

    return pRenderStateBlock;
}