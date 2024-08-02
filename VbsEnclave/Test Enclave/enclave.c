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
/*
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
*/

void* 
CALLBACK
CallCryptoEnclaveTest(
    _In_ void* Context
)
{   
    BCRYPT_ALG_HANDLE algHandle = NULL;
    BCRYPT_KEY_HANDLE keyHandle= NULL;
    ULONG keySize = 512; //key size will be defined in constants file
    WCHAR String[32];

    if (!BCryptOpenAlgorithmProvider(algHandle, "BCRYPT_RSA_ALGORITHM", NULL, 0)) {
        return (void*) NULL;
    }
    if (!BCryptGenerateKeyPair(algHandle, keyHandle, keySize, 0, 0)) {
        return (void*) NULL;
    }

    swprintf_s(String, ARRAYSIZE(String), L"%s\n", L"Generate Key Pair");
    //printf("Generate Key Pair\n");

    //end
    if (!BCryptCloseAlgorithmProvider(algHandle, 0)) {
        return (void*) NULL;
    }

    return (void*)((ULONG_PTR)100);
}
