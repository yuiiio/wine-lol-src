/*
 * Copyright 2019 Alistair Leslie-Hughes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */
#define COBJMACROS

#include "windows.h"
#include "ole2.h"
#include "rpcproxy.h"

#include "initguid.h"
#include "dsdmo_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(dsdmo);

static HINSTANCE dsdmo_instance;

/******************************************************************
 *     DllMain
 */
BOOL WINAPI DllMain(HINSTANCE inst, DWORD reason, void *reserved)
{
    TRACE("(%p %d %p)\n", inst, reason, reserved);

    switch(reason)
    {
    case DLL_WINE_PREATTACH:
        return FALSE;  /* prefer native version */
    case DLL_PROCESS_ATTACH:
        dsdmo_instance = inst;
        DisableThreadLibraryCalls(dsdmo_instance);
        break;
    }

    return TRUE;
}

static HRESULT WINAPI ClassFactory_QueryInterface(IClassFactory *iface, REFIID riid, void **ppv)
{
    *ppv = NULL;

    if(IsEqualGUID(&IID_IUnknown, riid) || IsEqualGUID(&IID_IClassFactory, riid)) {
        *ppv = iface;
    }

    if(*ppv) {
        IUnknown_AddRef((IUnknown*)*ppv);
        return S_OK;
    }

    WARN("(%p)->(%s %p)\n", iface, debugstr_guid(riid), ppv);
    return E_NOINTERFACE;
}

static ULONG WINAPI ClassFactory_AddRef(IClassFactory *iface)
{
    TRACE("(%p)\n", iface);
    return 2;
}

static ULONG WINAPI ClassFactory_Release(IClassFactory *iface)
{
    TRACE("(%p)\n", iface);
    return 1;
}

static HRESULT WINAPI ClassFactory_LockServer(IClassFactory *iface, BOOL fLock)
{
    TRACE("(%p)->(%x)\n", iface, fLock);
    return S_OK;
}

static const IClassFactoryVtbl EchoFactoryVtbl = {
    ClassFactory_QueryInterface,
    ClassFactory_AddRef,
    ClassFactory_Release,
    EchoFactory_CreateInstance,
    ClassFactory_LockServer
};

static const IClassFactoryVtbl ChrousFactoryVtbl = {
    ClassFactory_QueryInterface,
    ClassFactory_AddRef,
    ClassFactory_Release,
    ChrousFactory_CreateInstance,
    ClassFactory_LockServer
};

static const IClassFactoryVtbl CompressorFactoryVtbl = {
    ClassFactory_QueryInterface,
    ClassFactory_AddRef,
    ClassFactory_Release,
    CompressorFactory_CreateInstance,
    ClassFactory_LockServer
};

static IClassFactory echofx_factory = { &EchoFactoryVtbl };
static IClassFactory chorusfx_factory = { &ChrousFactoryVtbl };
static IClassFactory compressorfx_factory = { &CompressorFactoryVtbl };

/***********************************************************************
 *      DllGetClassObject
 */
HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID *ppv)
{
    TRACE("%s %s %p\n", debugstr_guid(rclsid), debugstr_guid(riid), ppv);

    if(IsEqualGUID(&GUID_DSFX_STANDARD_ECHO, rclsid))
    {
        TRACE("GUID_DSFX_STANDARD_ECHO\n");
        return IClassFactory_QueryInterface(&echofx_factory, riid, ppv);
    }
    else if(IsEqualGUID(&GUID_DSFX_STANDARD_CHORUS, rclsid))
    {
        TRACE("GUID_DSFX_STANDARD_CHORUS\n");
        return IClassFactory_QueryInterface(&chorusfx_factory, riid, ppv);
    }
    else if(IsEqualGUID(&GUID_DSFX_STANDARD_COMPRESSOR, rclsid))
    {
        TRACE("GUID_DSFX_STANDARD_COMPRESSOR\n");
        return IClassFactory_QueryInterface(&compressorfx_factory, riid, ppv);
    }

    FIXME("%s %s %p\n", debugstr_guid(rclsid), debugstr_guid(riid), ppv);
    return CLASS_E_CLASSNOTAVAILABLE;
}

/***********************************************************************
 *      DllCanUnloadNow
 */
HRESULT WINAPI DllCanUnloadNow(void)
{
    return S_FALSE;
}

/***********************************************************************
 *      DllRegisterServer
 */
HRESULT WINAPI DllRegisterServer(void)
{
    TRACE("()\n");
    return __wine_register_resources(dsdmo_instance);
}

/***********************************************************************
 *      DllUnregisterServer
 */
HRESULT WINAPI DllUnregisterServer(void)
{
    TRACE("()\n");
    return __wine_unregister_resources(dsdmo_instance);
}
