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
//enclave.c 쪽 헤더파일
#define BUFFER_SIZE 4'096

typedef struct SealDataInfo {
	HRESULT hr;
	BYTE* ProtectedBolb;
    UINT32 ProtectedBolbSize;
}SealDataInfo;

typedef struct UnsealDataInfo {
	HRESULT hr;
	BYTE* DecryptedData;
	//PVOID DecryptedData;
	UINT32 DecryptedDataSize;
}UnsealDataInfo;