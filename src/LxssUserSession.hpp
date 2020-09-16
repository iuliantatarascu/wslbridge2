/* 
 * This file is part of wslbridge2 project.
 * Licensed under the terms of the GNU General Public License v3 or later.
 * Copyright (C) 2020 Biswapriyo Nath.
 */

/*
 * LxssUserSession.hpp: Declaration of LxssUserSession COM interface.
 */

#ifndef LXSSUSERSESSION_H
#define LXSSUSERSESSION_H

/* As winsock.h and sys/socket.h can not coexist */
#ifndef SOCKET
#define SOCKET size_t
#endif

/* Class indentifier */
static const GUID CLSID_LxssUserSession = {
    0x4F476546,
    0xB412,
    0x4579,
    { 0xB6, 0x4C, 0x12, 0x3D, 0xF3, 0x31, 0xE3, 0xD6 } };

/* Interface identifier */
static const GUID IID_ILxssUserSession = {
    0x536A6BCF,
    0xFE04,
    0x41D9,
    { 0xB9, 0x78, 0xDC, 0xAC, 0xA9, 0xA9, 0xB5, 0xB9 } };

typedef struct _LXSS_STD_HANDLE
{
    ULONG Handle;
    ULONG Pipe;
} LXSS_STD_HANDLE, *PLXSS_STD_HANDLE;

typedef struct _LXSS_STD_HANDLES
{
    LXSS_STD_HANDLE StdIn;
    LXSS_STD_HANDLE StdOut;
    LXSS_STD_HANDLE StdErr;
} LXSS_STD_HANDLES, *PLXSS_STD_HANDLES;

/* Unused COM methods are ignored with void parameters */
typedef struct _ILxssUserSession ILxssUserSession;

struct _ILxssUserSessionVtbl
{
    /* IUnknown methods */
    HRESULT(STDMETHODCALLTYPE *QueryInterface)(
        ILxssUserSession *This,
        GUID *riid,
        PVOID *ppv);

    ULONG(STDMETHODCALLTYPE *AddRef)(
        ILxssUserSession *This);

    ULONG(STDMETHODCALLTYPE *Release)(
        ILxssUserSession *This);

    void *CreateInstance;
    void *RegisterDistribution;
    void *RegisterDistributionPipe;

    HRESULT(STDMETHODCALLTYPE *GetDistributionId)(
        ILxssUserSession *This,
        PCWSTR DistroName,
        ULONG EnableEnumerate,
        GUID *DistroId);

    void *TerminateDistribution;
    void *UnregisterDistribution;
    void *ConfigureDistribution;
    void *GetDistributionConfiguration;

    HRESULT(STDMETHODCALLTYPE *GetDefaultDistribution)(
        ILxssUserSession *This,
        GUID *DistroId);

    void *SetDefaultDistribution;
    void *EnumerateDistributions;

    HRESULT(STDMETHODCALLTYPE *CreateLxProcess)(
        /*_In_*/ ILxssUserSession *This,
        /*_In_opt_*/ GUID *DistroId,
        /*_In_opt_*/ PCSTR CommandLine,
        /*_In_opt_*/ ULONG ArgumentCount,
        /*_In_opt_*/ PCSTR *Arguments,
        /*_In_opt_*/ PCWSTR CurrentDirectory,
        /*_In_opt_*/ PCWSTR SharedEnvironment,
        /*_In_opt_*/ PCWSTR ProcessEnvironment,
        /*_In_opt_*/ SIZE_T EnvironmentLength,
        /*_In_opt_*/ PCWSTR LinuxUserName,
        /*_In_opt_*/ USHORT WindowWidthX,
        /*_In_opt_*/ USHORT WindowHeightY,
        /*_In_*/ ULONG ConsoleHandle,
        /*_In_*/ PLXSS_STD_HANDLES StdHandles,
        /*_Out_*/ GUID *InitiatedDistroId,
        /*_Out_*/ GUID *LxInstanceId,
        /*_Out_*/ PHANDLE LxProcessHandle,
        /*_Out_*/ PHANDLE ServerHandle,
        /*_Out_*/ SOCKET *InputSocket,
        /*_Out_*/ SOCKET *OutputSocket,
        /*_Out_*/ SOCKET *ErrorSocket,
        /*_Out_*/ SOCKET *ControlSocket);

    void *SetVersion;
    void *RegisterLxBusServer;
    void *ExportDistribution;
    void *ExportDistributionPipe;
    void *Shutdown;
};

struct _ILxssUserSession
{
    struct _ILxssUserSessionVtbl *lpVtbl;
};

#endif /* LXSSUSERSESSION_H */