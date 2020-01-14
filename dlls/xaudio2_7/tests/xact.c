/*
 * Copyright (c) 2020 Alistair Leslie-Hughes
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

#include <windows.h>
#include <math.h>

#define COBJMACROS
#include "wine/test.h"

#include "xact3.h"

#include "initguid.h"
DEFINE_GUID(IID_IXACT3Engine301, 0xe72c1b9a, 0xd717, 0x41c0, 0x81, 0xa6, 0x50, 0xeb, 0x56, 0xe8, 0x06, 0x49);

struct xact_interfaces
{
    REFGUID clsid;
    REFIID iid;
    HRESULT expected;
    BOOL todo;
} xact_interfaces[] =
{
    {&CLSID_XACTEngine30, &IID_IXACT3Engine301, E_NOINTERFACE, TRUE },
    {&CLSID_XACTEngine30, &IID_IXACT3Engine,    E_NOINTERFACE, TRUE },

    /* Version 3.1 to 3.4 use the same inteface */
    {&CLSID_XACTEngine31, &IID_IXACT3Engine301, S_OK },
    {&CLSID_XACTEngine32, &IID_IXACT3Engine301, S_OK },
    {&CLSID_XACTEngine33, &IID_IXACT3Engine301, S_OK },
    {&CLSID_XACTEngine34, &IID_IXACT3Engine301, S_OK },

    /* Version 3.5 to 3.7 use the same inteface */
    {&CLSID_XACTEngine35, &IID_IXACT3Engine301, E_NOINTERFACE },
    {&CLSID_XACTEngine35, &IID_IXACT3Engine,    S_OK },

    {&CLSID_XACTEngine36, &IID_IXACT3Engine301, E_NOINTERFACE },
    {&CLSID_XACTEngine36, &IID_IXACT3Engine,    S_OK },

    {&CLSID_XACTEngine37, &IID_IXACT3Engine301, E_NOINTERFACE },
    {&CLSID_XACTEngine37, &IID_IXACT3Engine,    S_OK },
    {&CLSID_XACTEngine37, &IID_IUnknown,        S_OK },
};

static void test_interfaces(void)
{
    IUnknown *unk;
    HRESULT hr;
    int i;

    for (i = 0; i < ARRAY_SIZE(xact_interfaces); i++)
    {
        hr = CoCreateInstance(xact_interfaces[i].clsid, NULL, CLSCTX_INPROC_SERVER,
                    xact_interfaces[i].iid, (void**)&unk);
        if (hr == REGDB_E_CLASSNOTREG || (hr != xact_interfaces[i].expected &&
                                            xact_interfaces[i].todo))
        {
            trace("%d not registered. Skipping\n", wine_dbgstr_guid(xact_interfaces[i].clsid) );
            continue;
        }
        ok(hr == xact_interfaces[i].expected, "%d, Unexpected value 0x%08x\n", i, hr);
        if (hr == S_OK)
            IUnknown_Release(unk);
    }
}

START_TEST(xact)
{
    CoInitialize(NULL);

    test_interfaces();

    CoUninitialize();
}
