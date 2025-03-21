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
#include <bcrypt.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 4'096

//enclave.c 쪽 헤더파일

typedef struct SealDataInfo {
    PVOID ProtectedBolb;
	BYTE PB[BUFFER_SIZE];
    UINT32* ProtectedBolbSize;
	HRESULT hr;
}SealDataInfo;

typedef struct UnsealDataInfo {
	PVOID DecryptedData;
	UINT32* DecryptedDataSize;
	HRESULT hr;
}UnsealDataInfo;