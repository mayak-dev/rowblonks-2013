#include "pch.h"
#include "Config.h"
#include "Patches.h"
#include "RBXCookieJar.h"

// imported functions will be patched to include this, forcing the DLL to be loaded
void __declspec(dllexport) nothing() {}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        try
        {
            Config::init();
            Patches::init();
        }
        catch (const std::runtime_error& error)
        {
            (void)error;

#ifdef _DEBUG
            MessageBox(nullptr, error.what(), nullptr, MB_OK | MB_ICONERROR);
#endif

            ExitProcess(EXIT_FAILURE);
        }

        // errors from reading cookies should not be fatal
        try
        {
            RBXCookieJar::setRobloSecurity();
        }
        catch (const std::runtime_error& error)
        {
            std::string message = "Failed to read Roblox cookies: ";
            message += error.what();
            MessageBox(nullptr, message.c_str(), nullptr, MB_OK | MB_ICONWARNING);
        }
    }

    return TRUE;
}
