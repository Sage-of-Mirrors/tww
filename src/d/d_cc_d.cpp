//
// Generated by dtk
// Translation Unit: d_cc_d.cpp
//

#include "d/d_cc_d.h"
#include "f_op/f_op_actor_mng.h"
#include "dolphin/types.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 800AB2AC-800AB328       .text GetAc__22dCcD_GAtTgCoCommonBaseFv */
fopAc_ac_c* dCcD_GAtTgCoCommonBase::GetAc() {
    if (mApid == fpcM_ERROR_PROCESS_ID_e) {
        return NULL;
    }
    if (mAc == NULL) {
        mAc = fopAcM_SearchByID(mApid);
        if (mAc == NULL) {
            mApid = fpcM_ERROR_PROCESS_ID_e;
        }
    }
    return mAc;
}

/* 800AB328-800AB334       .text SetEffCounterTimer__22dCcD_GAtTgCoCommonBaseFv */
void dCcD_GAtTgCoCommonBase::SetEffCounterTimer() {
    mEffCounter = 5;
}

/* 800AB334-800AB384       .text __ct__10dCcD_GSttsFv */
dCcD_GStts::dCcD_GStts() {
    mAtSpl = 0;
    mTgSpl = 0;
    mRoomId = 0;
    field_0x08 = -1;
    mAtApid = -1;
    mAtOldApid = -1;
    mTgApid = -1;
    mTgOldApid = -1;
    field_0x1C = 0;
}

/* 800AB384-800AB3BC       .text Ct__10dCcD_GSttsFv */
void dCcD_GStts::Ct() {
    mAtSpl = 0;
    mTgSpl = 0;
    mRoomId = 0;
    field_0x08 = -1;
    mAtApid = -1;
    mAtOldApid = -1;
    mTgApid = -1;
    mTgOldApid = -1;
    field_0x1C = 0;
}

/* 800AB3BC-800AB3DC       .text Move__10dCcD_GSttsFv */
void dCcD_GStts::Move() {
    mAtOldApid = mAtApid;
    mAtApid = NULL;
    mTgOldApid = mTgApid;
    mTgApid = NULL;
}

/* 800AB3DC-800AB46C       .text Init__9dCcD_SttsFiiP10fopAc_ac_c */
void dCcD_Stts::Init(int param_0, int param_1, fopAc_ac_c* pActor) {
    u32 procId;
    if (pActor) {
        procId = fpcM_GetID(pActor);
    } else {
        procId = fpcM_ERROR_PROCESS_ID_e;
    }
    cCcD_Stts::Init(param_0, param_1, pActor, procId);
    
    s32 roomNo;
    if (pActor) {
        roomNo = pActor->current.roomNo;
    } else {
        roomNo = 0;
        OnNoActor();
    }
    if (roomNo != -1) {
        SetRoomId(roomNo);
    } else {
        SetRoomId(0);
    }
}

/* 800AB46C-800AB4A0       .text Ct__9dCcD_SttsFv */
void dCcD_Stts::Ct() {
    cCcD_Stts::Ct();
    dCcD_GStts::Ct();
}

/* 800AB4A0-800AB4D0       .text Set__11dCcD_GObjAtFRC14dCcD_SrcGObjAt */
void dCcD_GObjAt::Set(const dCcD_SrcGObjAt& src) {
    dCcD_GAtTgCoCommonBase::Set(src.mBase);
    mSe = src.mSe;
    mMtrl = 0;
    mHitMark = src.mHitMark;
    mSpl = src.mSpl;
}

/* 800AB4D0-800AB520       .text Set__11dCcD_GObjTgFRC14dCcD_SrcGObjTg */
void dCcD_GObjTg::Set(const dCcD_SrcGObjTg& src) {
    dCcD_GAtTgCoCommonBase::Set(src.mBase);
    mSe = src.mSe;
    mMtrl = 0;
    mHitMark = src.mHitMark;
    mSpl = src.mSpl;
    mHitPos = cXyz::Zero;
    mShieldFrontRangeYAngle = NULL;
}

/* 800AB520-800AB63C       .text __ct__12dCcD_GObjInfFv */
dCcD_GObjInf::dCcD_GObjInf() {
    /* Nonmatching */
}

dCcD_GObjInf::~dCcD_GObjInf() {
    /* Nonmatching */
}

/* 800AB7C0-800AB7C4       .text GetGObjInf__12dCcD_GObjInfFv */
cCcD_GObjInf* dCcD_GObjInf::GetGObjInf() {
    return (cCcD_GObjInf*)this;
}

/* 800AB7C4-800AB81C       .text ClrAtHit__12dCcD_GObjInfFv */
void dCcD_GObjInf::ClrAtHit() {
    cCcD_Obj::ClrAtHit();
    mGObjAt.ClrHit();
    OffAtShieldHit();
    OffAtHitNoActor();
    SubtractAtEffCounter();
}

#if VERSION != VERSION_JPN
/* 800AB81C-800AB874       .text ChkAtHit__12dCcD_GObjInfFv */
u32 dCcD_GObjInf::ChkAtHit() {
    if (!cCcD_ObjHitInf::ChkAtHit())
        return 0;

    if (!ChkAtHitNoActor() && !GetAtHitAc())
        return 0;
    else
        return 1;
}
#endif

/* 800AB874-800AB8B4       .text ResetAtHit__12dCcD_GObjInfFv */
void dCcD_GObjInf::ResetAtHit() {
    ClrAtHit();
    ClrAtEffCounter();
}

/* 800AB8B4-800AB904       .text GetAtHitObj__12dCcD_GObjInfFv */
cCcD_Obj* dCcD_GObjInf::GetAtHitObj() {
    if (!ChkAtHitNoActor() && !GetAtHitAc())
        return NULL;

    return cCcD_ObjHitInf::GetAtHitObj();
}

/* 800AB904-800AB938       .text GetAtHitGObj__12dCcD_GObjInfFv */
cCcD_GObjInf* dCcD_GObjInf::GetAtHitGObj() {
    cCcD_Obj* atHitObj = GetAtHitObj();
    if (atHitObj == NULL) {
        return NULL;
    }
    return dCcD_GetGObjInf(atHitObj);
}

/* 800AB938-800AB958       .text ChkAtNoGuard__12dCcD_GObjInfFv */
u8 dCcD_GObjInf::ChkAtNoGuard() {
    return GetAtSpl() >= 8;
}

/* 800AB958-800AB9B0       .text ClrTgHit__12dCcD_GObjInfFv */
void dCcD_GObjInf::ClrTgHit() {
    cCcD_ObjHitInf::ClrTgHit();
    mGObjTg.ClrHit();
    OffTgHitNoActor();
    OffTgShieldHit();
    SubtractTgEffCounter();
}

#if VERSION != VERSION_JPN
/* 800AB9B0-800ABA08       .text ChkTgHit__12dCcD_GObjInfFv */
u32 dCcD_GObjInf::ChkTgHit() {
    if (!cCcD_ObjHitInf::ChkTgHit())
        return 0;

    if (!ChkTgHitNoActor() && !GetTgHitAc())
        return 0;
    else
        return 1;
}
#endif

/* 800ABA08-800ABA48       .text ResetTgHit__12dCcD_GObjInfFv */
void dCcD_GObjInf::ResetTgHit() {
    ClrTgHit();
    ClrTgEffCounter();
}

/* 800ABA48-800ABA98       .text GetTgHitObj__12dCcD_GObjInfFv */
cCcD_Obj* dCcD_GObjInf::GetTgHitObj() {
    if (!ChkTgHitNoActor() && !GetTgHitAc())
        return NULL;
    return cCcD_ObjHitInf::GetTgHitObj();
}

/* 800ABA98-800ABACC       .text GetTgHitGObj__12dCcD_GObjInfFv */
dCcD_GObjInf* dCcD_GObjInf::GetTgHitGObj() {
    cCcD_Obj * pHitObj = GetTgHitObj();
    if (pHitObj == NULL)
        return NULL;
    return dCcD_GetGObjInf(pHitObj);
}

/* 800ABACC-800ABB00       .text GetTgHitObjSe__12dCcD_GObjInfFv */
u8 dCcD_GObjInf::GetTgHitObjSe() {
    dCcD_GObjInf * pHitInf = GetTgHitGObj();
    if (pHitInf == NULL)
        return 0;
    return pHitInf->GetAtSe();
}

/* 800ABB00-800ABB4C       .text ClrCoHit__12dCcD_GObjInfFv */
void dCcD_GObjInf::ClrCoHit() {
    cCcD_ObjHitInf::ClrCoHit();
    mGObjCo.ClrHit();
    OffCoHitNoActor();
    SubtractCoEffCounter();
}

#if VERSION != VERSION_JPN
/* 800ABB4C-800ABBA4       .text ChkCoHit__12dCcD_GObjInfFv */
u32 dCcD_GObjInf::ChkCoHit() {
    if (!cCcD_ObjHitInf::ChkCoHit())
        return 0;

    if (!ChkCoHitNoActor() && !GetCoHitAc())
        return 0;
    else
        return 1;
}
#endif

/* 800ABBA4-800ABBF4       .text GetCoHitObj__12dCcD_GObjInfFv */
cCcD_Obj* dCcD_GObjInf::GetCoHitObj() {
    if (!ChkCoHitNoActor() && !GetCoHitAc())
        return NULL;

    return cCcD_ObjHitInf::GetCoHitObj();
}

/* 800ABBF4-800ABC54       .text Set__12dCcD_GObjInfFRC15dCcD_SrcGObjInf */
void dCcD_GObjInf::Set(const dCcD_SrcGObjInf& src) {
    cCcD_Obj::Set(src.mObj);
    mGObjAt.Set(src.mGObjAt);
    mGObjTg.Set(src.mGObjTg);
    mGObjCo.Set(src.mGObjCo);
}

/* 800ABC54-800ABCC4       .text dCcD_GetGObjInf__FP8cCcD_Obj */
dCcD_GObjInf* dCcD_GetGObjInf(cCcD_Obj* pobj) {
    JUT_ASSERT(531, pobj != 0);
    return (dCcD_GObjInf*)pobj->GetGObjInf();
}

/* 800ABCC4-800ABD34       .text Set__8dCcD_CpsFRC11dCcD_SrcCps */
void dCcD_Cps::Set(const dCcD_SrcCps& src) {
    dCcD_GObjInf::Set(src.mObjInf);
    cCcD_CpsAttr::Set(src.mCpsAttr);
}

/* 800ABD34-800ABD54       .text Set__8dCcD_TriFRC11dCcD_SrcTri */
void dCcD_Tri::Set(const dCcD_SrcTri& src) {
    dCcD_GObjInf::Set(src.mObjInf);
}

/* 800ABD54-800ABDCC       .text Set__8dCcD_CylFRC11dCcD_SrcCyl */
void dCcD_Cyl::Set(const dCcD_SrcCyl& src) {
    dCcD_GObjInf::Set(src.mObjInf);
    cCcD_CylAttr::Set(src.mCylAttr);
}

/* 800ABDCC-800ABE18       .text StartCAt__8dCcD_CylFR4cXyz */
void dCcD_Cyl::StartCAt(cXyz& pos) {
    cXyz vel = cXyz::Zero;
    SetAtVec(vel);
    SetC(pos);
}

/* 800ABE18-800ABE64       .text StartCTg__8dCcD_CylFR4cXyz */
void dCcD_Cyl::StartCTg(cXyz& pos) {
    cXyz vel = cXyz::Zero;
    SetTgVec(vel);
    SetC(pos);
}

/* 800ABE64-800ABEE0       .text MoveCAtTg__8dCcD_CylFR4cXyz */
void dCcD_Cyl::MoveCAtTg(cXyz& pos) {
    cXyz vel = pos - GetC();
    SetAtVec(vel);
    SetTgVec(vel);
    SetC(pos);
}

/* 800ABEE0-800ABF50       .text MoveCAt__8dCcD_CylFR4cXyz */
void dCcD_Cyl::MoveCAt(cXyz& pos) {
    cXyz vel = pos - GetC();
    SetAtVec(vel);
    SetC(pos);
}

/* 800ABF50-800ABFC0       .text MoveCTg__8dCcD_CylFR4cXyz */
void dCcD_Cyl::MoveCTg(cXyz& pos) {
    cXyz vel = pos - GetC();
    SetTgVec(vel);
    SetC(pos);
}

/* 800ABFC0-800AC02C       .text Set__8dCcD_SphFRC11dCcD_SrcSph */
void dCcD_Sph::Set(const dCcD_SrcSph& src) {
    dCcD_GObjInf::Set(src.mObjInf);
    cCcD_SphAttr::Set(src.mSphAttr);
}

/* 800AC02C-800AC078       .text StartCAt__8dCcD_SphFR4cXyz */
void dCcD_Sph::StartCAt(cXyz& pos) {
    cXyz atVec = cXyz::Zero;
    SetAtVec(atVec);
    SetC(pos);
}

/* 800AC078-800AC0E8       .text MoveCAt__8dCcD_SphFR4cXyz */
void dCcD_Sph::MoveCAt(cXyz& pos) {
    cXyz atVec = pos - *GetCP();
    SetAtVec(atVec);
    SetC(pos);
}
