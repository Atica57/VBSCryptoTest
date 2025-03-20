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

/*
    Defines the code that will be loaded into the VBS enclave.
--*/

#include "precomp.h"

// VBS enclave configuration

const IMAGE_ENCLAVE_CONFIG __enclave_config = {
    sizeof(IMAGE_ENCLAVE_CONFIG),
    IMAGE_ENCLAVE_MINIMUM_CONFIG_SIZE,
    IMAGE_ENCLAVE_POLICY_DEBUGGABLE,    // DO NOT SHIP DEBUGGABLE ENCLAVES TO PRODUCTION
	//0,          //The enclave does not permit debugging
    0,
    0,
    0,
    { 0xFE, 0xFE },    // family id
    { 0x01, 0x01 },    // image id
    0,                 // version
    0,                 // SVN
    0x10000000,        // size
    16,                // number of threads
    IMAGE_ENCLAVE_FLAG_PRIMARY_IMAGE
};

ULONG InitialCookie;
char str[1024] = "[Enclave]This is example for Enclave memory dump.";

BOOL
DllMain(
    _In_ HINSTANCE hinstDLL,
    _In_ DWORD dwReason,
    _In_ LPVOID lpvReserved
)
{
    UNREFERENCED_PARAMETER(hinstDLL);
    UNREFERENCED_PARAMETER(lpvReserved);

    if (dwReason == DLL_PROCESS_ATTACH) {
        InitialCookie = 0xDADAF00D;
    }

    return TRUE;
}

void*
CALLBACK
CallEnclaveTest(
    _In_ void* Context
)
{
    WCHAR String[32];
    swprintf_s(String, ARRAYSIZE(String), L"%s\n", L"CallEnclaveTest started");
    OutputDebugStringW(String);

    return (void*)((ULONG_PTR)(Context) ^ InitialCookie);
}

void*
CALLBACK
SaveEnclaveDataTest(
    _In_ void* SealData
)
{
    WCHAR String[32];
    swprintf_s(String, ARRAYSIZE(String), L"%s\n", L"SaveEnclaveDataTest started");
    OutputDebugStringW(String);
	UINT32 BufferSize = BUFFER_SIZE;
    HRESULT hr = EnclaveSealData(
                    (void*)str, 
                    strlen(str), 
                    ENCLAVE_IDENTITY_POLICY_SEAL_SAME_FAMILY, 
                    ENCLAVE_RUNTIME_POLICY_ALLOW_FULL_DEBUG, 
                    ((SealDataInfo*)SealData)->ProtectedBolb,
                    BUFFER_SIZE,
                    ((SealDataInfo*)SealData)->ProtectedBolbSize
    );
    ((SealDataInfo*)SealData)->hr = hr;
	return SealData;
}

void* 
CALLBACK
LoadEnclaveDataTest(
    _In_ void* SealData
)
{
	WCHAR String[32];
	swprintf_s(String, ARRAYSIZE(String), L"%s\n", L"LoadEnclaveDataTest started");
	OutputDebugStringW(String);
    
    UnsealDataInfo* UnsealData = malloc(sizeof(UnsealDataInfo));
	UnsealData->DecryptedData = malloc(sizeof(char*) * 32'768);
    UnsealData->DecryptedDataSize = NULL;
    //PVOID DecryptedData = malloc(sizeof(char*) * 32'768);
	//UINT32 *DecryptedDataSize = NULL;
    ENCLAVE_IDENTITY *SealingIdentity = NULL;
    UINT32* UnsealingFlasgs = NULL;

	HRESULT hr = EnclaveUnsealData(
		            ((SealDataInfo*)SealData)->ProtectedBolb,
		            *(((SealDataInfo*)SealData)->ProtectedBolbSize),
                    UnsealData->DecryptedData,
                    sizeof(str),
		            UnsealData->DecryptedDataSize,
		            SealingIdentity,
		            UnsealingFlasgs
	);
	return (void*)UnsealData;
	//if (hr != S_OK)
	//{
 //       //free(DecryptedData);
	//	return hr;
	//}
	//else
	//{
	//	return (void *)UnsealData;
	//}
	////기존 str과 일치하는 지 확인
 //   if (!strcmp((char*)(DecryptedData), str)) {
 //       free(DecryptedData);
 //       return E_FAIL;
 //   }
 //   else {
 //       free(DecryptedData);
	//	return S_OK;
 //   }
}