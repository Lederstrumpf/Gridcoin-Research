#include <string>
#include "grcrestarter.h"

// Old VB based NeuralNet.
double qtPushGridcoinDiagnosticData(std::string data);
void qtUpdateConfirm(std::string txid);
int RestartClient();
int RebootClient();
void CheckForUpgrade();
int DownloadBlocks();
// While transitioning to dotnet the NeuralNet implementation has been split
// into 3 implementations; Win32 with Qt, Win32 without Qt and the rest.
// After the transition both Win32 implementations can be removed.
namespace Restarter
{
    // Win32 with Qt enabled.
#if defined(WIN32) && defined(QT_GUI)
    double PushGridcoinDiagnosticData(std::string)
    {
        return qtPushGridcoinDiagnosticData(std::string)
    }

    int RestartGridcoin()
    {
        return RestartClient();
    }

    int RebootGridcoin()
    {
        return int RebootClient();
    }

    void CheckUpgrade()
    {
        return void CheckForUpgrade();
    }

    int DownloadGridcoinBlocks()
    {
        return int DownloadBlocks();
    }

    int ReindexGridcoinWallet()
    {
        return int ReindexWallet();
    }

    int CreateGRidcoinRestorePoint()
    {
        return int CreateRestorePoint();
    }

    void UpdateConfirm(std::string txid)
    {
        qtUpdateConfirm(std::string txid);
    }

#else
    double PushGridcoinDiagnosticData(std::string)
    {
        return 0;
    }

    int RestartGridcoin()
    {
        return 0;
    }

    int RebootGridcoin()
    {
        return 1;
    }

    void CheckUpgrade()
    {
        return;
    }

    int DownloadGridcoinBlocks()
    {
        return -1;
    }

    int ReindexGridcoinWallet()
    {
        return 0;
    }

    int CreateGridcoinRestorePoint()
    {
        return -1;
    }

    void UpdateConfirm(std::string txid)
    {
        return;
    }

#endif
}
