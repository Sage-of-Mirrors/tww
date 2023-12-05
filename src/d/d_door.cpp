//
// Generated by dtk
// Translation Unit: d_door.cpp
//

#include "d/d_door.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_player.h"

/* 8006B39C-8006B3A8       .text getSwbit__12dDoor_info_cFv */
u8 dDoor_info_c::getSwbit() {
    return fopAcM_GetParam(this) & 0xFF;
}

/* 8006B3A8-8006B3B4       .text getSwbit2__12dDoor_info_cFv */
u8 dDoor_info_c::getSwbit2() {
    return (fopAcM_GetParam(this) >> 0x14) & 0xFF;
}

/* 8006B3B4-8006B3C0       .text getType__12dDoor_info_cFv */
u8 dDoor_info_c::getType() {
    return (fopAcM_GetParam(this) >> 0x08) & 0xF;
}

/* 8006B3C0-8006B3EC       .text setType__12dDoor_info_cFUc */
void dDoor_info_c::setType(u8 type) {
    if (type >= 0x10)
        return;
    fopAcM_SetParam(this, fopAcM_GetParam(this) & ~(0xF << 0x08));
    fopAcM_SetParam(this, fopAcM_GetParam(this) | ((type << 0x08) & (0xFF << 0x08)));
}

/* 8006B3EC-8006B3F8       .text getEventNo__12dDoor_info_cFv */
u8 dDoor_info_c::getEventNo() {
    return (fopAcM_GetParam(this) >> 0x0C) & 0xFF;
}

/* 8006B3F8-8006B404       .text getFRoomNo__12dDoor_info_cFv */
u8 dDoor_info_c::getFRoomNo() {
    return orig.angle.x & 0x3F;
}

/* 8006B404-8006B410       .text getBRoomNo__12dDoor_info_cFv */
u8 dDoor_info_c::getBRoomNo() {
    return (orig.angle.x >> 0x06) & 0x3F;
}

/* 8006B410-8006B41C       .text getShipId__12dDoor_info_cFv */
u8 dDoor_info_c::getShipId() {
    return orig.angle.z & 0x3F;
}

/* 8006B41C-8006B428       .text getArg1__12dDoor_info_cFv */
u8 dDoor_info_c::getArg1() {
    return (orig.angle.z >> 0x08) & 0xFF;
}

/* 8006B428-8006B4C4       .text adjoinPlayer__12dDoor_info_cFv */
BOOL dDoor_info_c::adjoinPlayer() {
    int frontRoomNo = getFRoomNo();
    int backRoomNo = getBRoomNo();
    if (frontRoomNo == 0x3F || backRoomNo == 0x3F)
        return TRUE;
    if (dComIfGp_roomControl_checkRoomDisp(frontRoomNo) ||
        dComIfGp_roomControl_checkRoomDisp(backRoomNo))
    {
        return TRUE;
    }
    return FALSE;
}

/* 8006B4C4-8006B554       .text getViewRoomNo__12dDoor_info_cFv */
void dDoor_info_c::getViewRoomNo() {
    /* Nonmatching */
}

/* 8006B554-8006B5E4       .text frontCheckOld__12dDoor_info_cFv */
void dDoor_info_c::frontCheckOld() {
    /* Nonmatching */
}

/* 8006B65C-8006B6F4       .text frontCheck__12dDoor_info_cFv */
void dDoor_info_c::frontCheck() {
    /* Nonmatching */
}

/* 8006B6F4-8006B824       .text drawCheck_local__12dDoor_info_cFv */
void dDoor_info_c::drawCheck_local() {
    /* Nonmatching */
}

/* 8006B824-8006B8AC       .text drawCheck__12dDoor_info_cFi */
void dDoor_info_c::drawCheck(int) {
    /* Nonmatching */
}

/* 8006B8AC-8006B954       .text checkExecute__12dDoor_info_cFv */
void dDoor_info_c::checkExecute() {
    /* Nonmatching */
}

/* 8006B954-8006BA30       .text startDemoProc__12dDoor_info_cFv */
void dDoor_info_c::startDemoProc() {
    /* Nonmatching */
}

/* 8006BA30-8006BB5C       .text makeEventId__12dDoor_info_cFi */
void dDoor_info_c::makeEventId(int) {
    /* Nonmatching */
}

/* 8006BB5C-8006BBB0       .text initProc__12dDoor_info_cFi */
void dDoor_info_c::initProc(int) {
    /* Nonmatching */
}

/* 8006BBB0-8006BC50       .text initOpenDemo__12dDoor_info_cFi */
void dDoor_info_c::initOpenDemo(int) {
    /* Nonmatching */
}

/* 8006BC50-8006BDBC       .text checkArea__12dDoor_info_cFfff */
void dDoor_info_c::checkArea(f32, f32, f32) {
    /* Nonmatching */
}

/* 8006BDBC-8006BE94       .text openInitCom__12dDoor_info_cFi */
void dDoor_info_c::openInitCom(int) {
    /* Nonmatching */
}

/* 8006BE94-8006BF74       .text openProcCom__12dDoor_info_cFv */
void dDoor_info_c::openProcCom() {
    /* Nonmatching */
}

/* 8006BF74-8006C0A4       .text closeEndCom__12dDoor_info_cFv */
void dDoor_info_c::closeEndCom() {
    /* Nonmatching */
}

/* 8006C0A4-8006C0EC       .text getDemoAction__12dDoor_info_cFv */
void dDoor_info_c::getDemoAction() {
    /* Nonmatching */
}

/* 8006C0EC-8006C1D8       .text setGoal__12dDoor_info_cFv */
void dDoor_info_c::setGoal() {
    /* Nonmatching */
}

/* 8006C1D8-8006C200       .text setPlayerAngle__12dDoor_info_cFi */
void dDoor_info_c::setPlayerAngle(BOOL flip) {
    s16 angle = shape_angle.y;
    daPy_py_c* link = (daPy_py_c*)dComIfGp_getLinkPlayer();
    if (flip) {
        angle += 0x7FFF;
    }
    link->changeDemoMoveAngle(angle);
}

/* 8006C200-8006C2BC       .text setPosAndAngle__12dDoor_info_cFP4cXyzs */
void dDoor_info_c::setPosAndAngle(cXyz* pPos, s16 angle) {
    if (mEvtInfo.checkCommandDemoAccrpt() || mEvtInfo.checkCommandDoor()) {
        return;
    }
    if (pPos) {
        mAttentionInfo.mPosition = current.pos = *pPos;
        mAttentionInfo.mPosition.y += 150.0f;
        mEyePos = mAttentionInfo.mPosition;
    }
    current.angle.y = angle;
    shape_angle.y = current.angle.y;
    mAngleVec.set(cM_ssin(current.angle.y), 0.0f, cM_scos(current.angle.y));
}

/* 8006C2BC-8006C388       .text smokeInit__13dDoor_smoke_cFP12dDoor_info_c */
void dDoor_smoke_c::smokeInit(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006C388-8006C41C       .text smokeProc__13dDoor_smoke_cFP12dDoor_info_c */
void dDoor_smoke_c::smokeProc(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006C41C-8006C448       .text smokeEnd__13dDoor_smoke_cFv */
void dDoor_smoke_c::smokeEnd() {
    mSmokeCb.end();
}

/* 8006C448-8006C478       .text keyResLoad__12dDoor_key2_cFv */
void dDoor_key2_c::keyResLoad() {
    dComIfG_resLoad(&mPhs, "Key");
}

/* 8006C478-8006C4A8       .text keyResDelete__12dDoor_key2_cFv */
void dDoor_key2_c::keyResDelete() {
    dComIfG_resDelete(&mPhs, "Key");
}

/* 8006C4A8-8006C5E8       .text keyInit__12dDoor_key2_cFP12dDoor_info_c */
void dDoor_key2_c::keyInit(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006C5E8-8006C650       .text keyProc__12dDoor_key2_cFv */
void dDoor_key2_c::keyProc() {
    /* Nonmatching */
}

/* 8006C650-8006C764       .text keyCreate_Nkey__12dDoor_key2_cFv */
void dDoor_key2_c::keyCreate_Nkey() {
    /* Nonmatching */
}

/* 8006C764-8006C910       .text keyCreate_Bkey__12dDoor_key2_cFv */
void dDoor_key2_c::keyCreate_Bkey() {
    /* Nonmatching */
}

/* 8006C910-8006C948       .text keyCreate__12dDoor_key2_cFi */
void dDoor_key2_c::keyCreate(int) {
    /* Nonmatching */
}

/* 8006C948-8006C954       .text keyOn__12dDoor_key2_cFv */
void dDoor_key2_c::keyOn() {
    mbEnabled = true;
}

/* 8006C954-8006C960       .text keyOff__12dDoor_key2_cFv */
void dDoor_key2_c::keyOff() {
    mbEnabled = false;
}

/* 8006C960-8006CA10       .text calcMtx__12dDoor_key2_cFP12dDoor_info_c */
void dDoor_key2_c::calcMtx(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006CA10-8006CA78       .text draw__12dDoor_key2_cFP12dDoor_info_c */
void dDoor_key2_c::draw(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006CA78-8006CB28       .text calcMtx__12dDoor_stop_cFP12dDoor_info_c */
void dDoor_stop_c::calcMtx(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006CB28-8006CBFC       .text closeInit__12dDoor_stop_cFP12dDoor_info_c */
void dDoor_stop_c::closeInit(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006CBFC-8006CC80       .text closeProc__12dDoor_stop_cFP12dDoor_info_c */
void dDoor_stop_c::closeProc(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006CC80-8006CD50       .text openInit__12dDoor_stop_cFP12dDoor_info_c */
void dDoor_stop_c::openInit(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006CD50-8006CDD8       .text openProc__12dDoor_stop_cFP12dDoor_info_c */
void dDoor_stop_c::openProc(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006CDD8-8006CE8C       .text create__12dDoor_stop_cFv */
void dDoor_stop_c::create() {
    /* Nonmatching */
}

/* 8006CE8C-8006CEA8       .text init__11dDoor_msg_cFs */
void dDoor_msg_c::init(s16 param_1) {
    mA = param_1;
    m0 = -1;
    mMsg = 0;
    m8 = 0;
}

/* 8006CEA8-8006D0DC       .text proc__11dDoor_msg_cFP4cXyz */
void dDoor_msg_c::proc(cXyz*) {
    /* Nonmatching */
}

/* 8006D0DC-8006D11C       .text resLoad__12dDoor_hkyo_cFv */
s32 dDoor_hkyo_c::resLoad() {
    if (m11 == 0) {
        return 4;
    }
    dComIfG_resLoad(&mPhs, "Hkyo");
}

/* 8006D11C-8006D154       .text resDelete__12dDoor_hkyo_cFv */
void dDoor_hkyo_c::resDelete() {
    if (m11 == 0) {
        return;
    }
    dComIfG_resDelete(&mPhs, "Hkyo");
}

/* 8006D154-8006D2D4       .text create__12dDoor_hkyo_cFv */
void dDoor_hkyo_c::create() {
    /* Nonmatching */
}

/* 8006D2D4-8006D3A8       .text setAnm__12dDoor_hkyo_cFUc */
void dDoor_hkyo_c::setAnm(u8) {
    /* Nonmatching */
}

/* 8006D3A8-8006D3B4       .text init__12dDoor_hkyo_cFv */
void dDoor_hkyo_c::init() {
    mAnmIdx = 0;
}

/* 8006D3B4-8006D464       .text calcMtx__12dDoor_hkyo_cFP12dDoor_info_cf */
void dDoor_hkyo_c::calcMtx(dDoor_info_c*, f32) {
    /* Nonmatching */
}

/* 8006D464-8006D500       .text draw__12dDoor_hkyo_cFP12dDoor_info_c */
void dDoor_hkyo_c::draw(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006D500-8006D71C       .text proc__12dDoor_hkyo_cFP12dDoor_info_c */
void dDoor_hkyo_c::proc(dDoor_info_c*) {
    /* Nonmatching */
}

/* 8006D71C-8006D784       .text chkFirst__12dDoor_hkyo_cFv */
void dDoor_hkyo_c::chkFirst() {
    /* Nonmatching */
}

/* 8006D784-8006D7E8       .text onFirst__12dDoor_hkyo_cFv */
void dDoor_hkyo_c::onFirst() {
    /* Nonmatching */
}

/* 8006D7E8-8006D800       .text chkStart__12dDoor_hkyo_cFv */
BOOL dDoor_hkyo_c::chkStart() {
    return daPy_getPlayerActorClass()->getGrabUpEnd();
}
