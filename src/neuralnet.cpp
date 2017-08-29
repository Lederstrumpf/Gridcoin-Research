 #include "neuralnet.h"
#include "util.h"
#include "version.h"
#include "sync.h"

#include <boost/filesystem/path.hpp>
#include <boost/algorithm/string.hpp>

#include <functional>
#include <future>
#include <fstream>
#include <map>
#include <array>
#include <cstdio>

// Old VB based NeuralNet.
extern std::string qtGetNeuralHash(std::string data);
extern std::string qtGetNeuralContract(std::string data);
extern double qtExecuteGenericFunction(std::string function,std::string data);
extern std::string qtExecuteDotNetStringFunction(std::string function,std::string data);
extern void qtSyncWithDPORNodes(std::string data);

// While transitioning to dotnet the NeuralNet implementation has been split
// into 3 implementations; Win32 with Qt, Win32 without Qt and the rest.
// After the transition both Win32 implementations can be removed.
namespace NN
{
    // Win32 with Qt enabled.
#if defined(WIN32) && defined(QT_GUI)
    bool IsEnabled()
    {
        return GetArgument("disableneuralnetwork", "false") == "false";
    }

    std::string GetNeuralVersion()
    {
        int neural_id = static_cast<int>(IsNeural());
        return = std::to_string(MINOR_VERSION) + "." + std::to_string(neural_id());
    }

    std::string GetNeuralHash()
    {
        return qtGetNeuralHash("");
    }

    std::string GetNeuralContract()
    {
        return qtGetNeuralContract("");
    }

    bool SetTestnetFlag(bool onTestnet)
    {
        return qtExecuteGenericFunction("SetTestNetFlag", onTestnet ? "TESTNET" : "MAINNET") != 0;
    }

    bool SynchronizeDPOR(const std::string& data)
    {
        qtSyncWithDPORNodes(data);
        return true;
    }

    std::string ExecuteDotNetStringFunction(std::string function, std::string data)
    {
        qtExecuteDotNetStringFunction(std::string function, std::string data);
    }

#else
    bool IsEnabled()
    {
        return false;
    }

    std::string GetNeuralVersion()
    {
        return "0";
    }

    std::string GetNeuralHash()
    {
        return std::string();
    }

    std::string GetNeuralContract()
    {
        return std::string();
    }

    bool SetTestnetFlag(bool onTestnet)
    {
        return false;
    }

    bool SynchronizeDPOR(const std::string& data)
    {
        return false;
    }

    std::string ExecuteDotNetStringFunction(std::string function, std::string data)
    {
        return std::string();
    }
#endif
}
