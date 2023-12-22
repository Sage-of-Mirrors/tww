//
// Generated by dtk
// Translation Unit: d_vibration.cpp
//

#include "d/d_vibration.h"
#include "m_Do/m_Do_controller_pad.h"

namespace {
    void makedata(u16*, u32, s32) {
        /* Nonmatching */
    }
    void rollshift(u32, s32, s32) {
        /* Nonmatching */
    }
    void makebits(u32, s32, s32) {
        /* Nonmatching */
    }
    void randombit(s32, s32) {
        /* Nonmatching */
    }
};

/* 8009C73C-8009CCCC       .text Run__12dVibration_cFv */
int dVibration_c::Run() {
    /* Nonmatching */
}

/* 8009CCCC-8009CD6C       .text StartShock__12dVibration_cFii4cXyz */
bool dVibration_c::StartShock(int, int, cXyz) {
    /* Nonmatching */
}

/* 8009CD6C-8009CE1C       .text StartQuake__12dVibration_cFii4cXyz */
bool dVibration_c::StartQuake(int, int, cXyz) {
    /* Nonmatching */
}

/* 8009CE1C-8009CF84       .text StartQuake__12dVibration_cFPCUcii4cXyz */
bool dVibration_c::StartQuake(const unsigned char*, int, int, cXyz) {
    /* Nonmatching */
}

/* 8009CF84-8009CFEC       .text StopQuake__12dVibration_cFi */
int dVibration_c::StopQuake(int) {
    /* Nonmatching */
}

/* 8009CFEC-8009D044       .text Kill__12dVibration_cFv */
void dVibration_c::Kill() {
    g_mDoCPd_gamePad[0]->stopMotorWaveHard();
    g_mDoCPd_gamePad[0]->stopMotorHard();
    setDefault();
}

/* 8009D044-8009D06C       .text CheckQuake__12dVibration_cFv */
bool dVibration_c::CheckQuake() {
    return field_0x24 != -1 || field_0x60 != -1;
}

/* 8009D06C-8009D0AC       .text setDefault__12dVibration_cFv */
void dVibration_c::setDefault() {
    field_0x48 = -1;
    field_0x0 = -1;
    field_0x60 = -1;
    field_0x24 = -1;
    field_0x58 = -99;
    field_0x20 = -99;
    field_0x70 = -99;
    field_0x44 = -99;
    field_0x74 = -99;
    field_0x5c = -99;
    field_0x7c = 0;
    field_0x78 = 0;
}

/* 8009D0AC-8009D0CC       .text Init__12dVibration_cFv */
void dVibration_c::Init() {
    setDefault();
}

/* 8009D0CC-8009D188       .text Pause__12dVibration_cFv */
void dVibration_c::Pause() {
    /* Nonmatching */
}

/* 8009D188-8009D1C4       .text __ct__12dVibration_cFv */
dVibration_c::dVibration_c() {
    setDefault();
}

/* 8009D1C4-8009D220       .text __dt__12dVibration_cFv */
dVibration_c::~dVibration_c() {
    Kill();
}
