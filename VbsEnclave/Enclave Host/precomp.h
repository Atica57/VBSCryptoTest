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

#define BUFFER_SIZE 1024

typedef struct SealDataInfo {
	HRESULT hr;
	unsigned char* ProtectedBolb;
	//PVOID ProtectedBolb;
	UINT32* ProtectedBolbSize;
}SealDataInfo;

typedef struct UnsealDataInfo {
	HRESULT hr;
	unsigned char* DecryptedData;
	//PVOID DecryptedData;
	UINT32* DecryptedDataSize;
}UnsealDataInfo;