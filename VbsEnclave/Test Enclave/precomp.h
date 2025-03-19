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

#include <winenclave.h>
#include <wchar.h>
//[24.07.30]
#include <bcrypt.h>
#include <string.h>
#include <stdlib.h>

//[25.03.17]
typedef struct SealDataInfo {
    PVOID ProtectedBolb;
    UINT32* ProtectedBolbSize;
}SealDataInfo;