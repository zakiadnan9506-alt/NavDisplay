/**************************************************************************
 *
 * NavDisplay Framework v1.0
 *
 * File : globals.cpp
 *
 * Description:
 * Global object definitions.
 *
 **************************************************************************/

#include "globals.h"

//
// ==========================================================
// GLOBAL OBJECTS
// ==========================================================
//
// Semua object global hanya dideklarasikan satu kali
// pada file ini.
//
// Inisialisasi dilakukan menggunakan default member
// initializer yang telah didefinisikan pada globals.h,
// sehingga tidak diperlukan constructor tambahan.
//
// ==========================================================
//

NavigationData navData{};

BatteryData batteryData{};

SystemStatus systemStatus{};
