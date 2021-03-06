/*
Copyright 2017 Microsoft
Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT 
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "stdafx.h"
#include "WifiCSP.h"
#include "MdmProvision.h"
#include "..\SharedUtilities\Logger.h"

using namespace std;

const wchar_t* WifeProfilePath = L"./Vendor/MSFT/WiFi/Profile/";

// Wifi CSP docs
// https://msdn.microsoft.com/en-us/windows/hardware/commercialize/customize/mdm/wifi-csp
//

void WifiCSP::AddProfile(const wstring& profileName, const wstring& profileXml)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/WlanXml";

    MdmProvision::RunAddData(path, profileXml);
}

void WifiCSP::DeleteProfile(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;

    MdmProvision::RunDelete(path);
}

wstring WifiCSP::GetProfile(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;

    wstring profileXml = MdmProvision::RunGetString(path);
    TRACEP(L" profile xml = ", profileXml.c_str());
    return profileXml;
}

void WifiCSP::SetProfile(const wstring& profileName, const wstring& profileXml)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/WlanXml";

    MdmProvision::RunSet(path, profileXml);
}

void WifiCSP::AddProxy(const wstring& profileName, const wstring& proxy)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/Proxy";

    MdmProvision::RunAddData(path, proxy);
}

void WifiCSP::DeleteProxy(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/Proxy";

    MdmProvision::RunDelete(path);
}

wstring WifiCSP::GetProxy(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/Proxy";

    wstring proxy = MdmProvision::RunGetString(path);
    TRACEP(L" proxy = ", proxy.c_str());
    return proxy;
}

void WifiCSP::SetProxy(const wstring& profileName, const wstring& proxy)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/Proxy";

    MdmProvision::RunSet(path, proxy);
}

void WifiCSP::AddDisableInternetConnectivityChecks(const wstring& profileName, bool disable)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/DisableInternetConnectivityChecks";

    MdmProvision::RunAddData(path, disable);
}

void WifiCSP::DeleteDisableInternetConnectivityChecks(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/DisableInternetConnectivityChecks";

    MdmProvision::RunDelete(path);
}

bool WifiCSP::GetDisableInternetConnectivityChecks(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/DisableInternetConnectivityChecks";

    wstring proxy = MdmProvision::RunGetString(path);
    TRACEP(L" proxy = ", proxy.c_str());
    return 0 == _wcsicmp(proxy.c_str(), L"True");
}

void WifiCSP::SetDisableInternetConnectivityChecks(const wstring& profileName, bool disable)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/DisableInternetConnectivityChecks";

    MdmProvision::RunSet(path, disable);
}

void AddProxyPacUrl(const wstring& profileName, const wstring& proxyPacUrl)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/ProxyPacUrl";

    MdmProvision::RunAddData(path, proxyPacUrl);
}

void WifiCSP::DeleteProxyPacUrl(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/ProxyPacUrl";

    MdmProvision::RunDelete(path);
}

wstring WifiCSP::GetProxyPacUrl(const wstring& profileName)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/ProxyPacUrl";

    wstring proxyPacUrl = MdmProvision::RunGetString(path);
    TRACEP(L" proxyPacUrl = ", proxyPacUrl.c_str());
    return proxyPacUrl;
}

void WifiCSP::SetProxyPacUrl(const wstring& profileName, const wstring& proxyPacUrl)
{
    TRACE(__FUNCTION__);

    wstring path = WifeProfilePath;
    path += profileName;
    path += L"/ProxyPacUrl";

    MdmProvision::RunSet(path, proxyPacUrl);
}
