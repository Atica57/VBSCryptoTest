//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#pragma once

#include <windows.h>
#include <stdio.h>
#include <wil/resource.h>
#include <wil/result_macros.h>
#include <stdlib.h>
#include <fstream>

typedef struct SealDataInfo {
    PVOID ProtectedBolb;
    UINT32* ProtectedBolbSize;
}SealDataInfo;

typedef struct UnsealDataInfo {
	PVOID DecryptedData;
	UINT32* DecryptedDataSize;
}UnsealDataInfo;