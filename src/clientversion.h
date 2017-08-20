#ifndef CLIENTVERSION_H
#define CLIENTVERSION_H

//
// client versioning
//

//! Copyright string used in Windows .rc files
#define COPYRIGHT_STR "2009-"

// These need to be macros, as version.cpp's and bitcoin-qt.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR       3
#define CLIENT_VERSION_MINOR       6
#define CLIENT_VERSION_REVISION    3
#define CLIENT_VERSION_BUILD       0

// Converts the parameter X to a string after macro replacement on X has been performed.
// Don't merge these into one macro!
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

#endif // CLIENTVERSION_H
 
