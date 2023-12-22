//
// Generated by dtk
// Translation Unit: d_a_lamp.cpp
//

#include "d/actor/d_a_lamp.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_mtx.h"

// RW data
static dCcD_SrcSph sph_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt  Type    */ 0,
        /* SrcObjAt  Atp     */ 0,
        /* SrcObjAt  SPrm    */ 0,
        /* SrcObjTg  Type    */ AT_TYPE_FIRE | AT_TYPE_UNK20000 | AT_TYPE_FIRE_ARROW | AT_TYPE_LEAF_WIND | AT_TYPE_UNK400000,
        /* SrcObjTg  SPrm    */ TG_SPRM_SET | TG_SPRM_UNK8,
        /* SrcObjCo  SPrm    */ 0,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt SPrm    */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg SPrm    */ 0,
        /* SrcGObjCo SPrm    */ 0,
    },
    // cM3dGSphS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 30.0f,
    },
};
static u8 padding[76];

// Need to break these out to get the rodata ordered right
static const float partHeightOffset = 20.0f;
static const float partMaxFlickerPerTick = 0.02f;

/* 000000EC-00000158       .text daLamp_Draw__FP10lamp_class */
static BOOL daLamp_Draw(lamp_class* i_this) {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &i_this->current.pos, &i_this->mTevStr);
    J3DModel* pModel = i_this->mModel;
    g_env_light.setLightTevColorType(pModel, &i_this->mTevStr);
    mDoExt_modelUpdateDL(pModel);
    return TRUE;
}

/* 00000158-000005C8       .text daLamp_Execute__FP10lamp_class */
static BOOL daLamp_Execute(lamp_class* i_this) {
    i_this->mCycleCtr += 1;
    MtxTrans(i_this->current.pos.x, i_this->current.pos.y, i_this->current.pos.z, 0);
    mDoMtx_YrotM(*calc_mtx, i_this->current.angle.GetY());
    if (i_this->mParameters == 0) {
        i_this->mLength = 0.1f;
    } else {
        if (dComIfGp_getVibration().CheckQuake() || fopAcM_otoCheck(i_this, 1000.0f) > 400) {
            i_this->mOto = 0x14;
        }
        if (i_this->mOto) {
            i_this->mOto--;
            cLib_addCalc2(&i_this->mLength, 0.15f, 1.0f, 0.015f);
        } else {
            cLib_addCalc2(&i_this->mLength, 0.01f, 1.0f, 0.0005f);
        }
    }
    f32 oppDist = cM_ssin(i_this->mCycleCtr * 0x320) * i_this->mLength;
    MtxRotX(oppDist, 1);
    f32 adjDist = cM_scos(i_this->mCycleCtr * 0x2bc) * i_this->mLength;
    MtxRotZ(adjDist, 1);
    MtxScale(0.4f, 0.4f, 0.4f, 1);
    i_this->mModel->setBaseTRMtx(*calc_mtx);
    MtxTrans(10.0f, -140.0f, -15.0f, 1);

    cXyz pos;
    pos.z = 0.0f;
    pos.y = 0.0f;
    pos.x = 0.0f;
    MtxPosition(&pos, &i_this->mPos);

    if (!i_this->mParticleInit) {
        static cXyz fire_scale(0.5f, 0.5f, 0.5f);

        dComIfGp_particle_set(0x1ea, &i_this->mPos, NULL, &fire_scale, 0xFF, &i_this->mPa);
        i_this->mParticleInit = 1;
        i_this->mParticlePower = 1.0f;
    }

    if (i_this->mPa.getEmitter()) {
        cXyz whitePartPos = i_this->mPos;
        whitePartPos.y += partHeightOffset;
        dComIfGp_particle_setSimple(0x4004, &whitePartPos, 0xFF, g_whiteColor, g_whiteColor, 0);
        cLib_addCalc2(&i_this->mParticlePower, cM_rndF(0.2f) + 1.0f, 0.5f, partMaxFlickerPerTick);
    } else {
        i_this->mParticlePower = 0.0f;
    }
    i_this->mInf.mPos = i_this->mPos;
    i_this->mInf.mColor.r = 600;
    i_this->mInf.mColor.g = 400;
    i_this->mInf.mColor.b = 120;

    s16 power = i_this->mParticlePower * 150.0f;
    i_this->mInf.mPower = power;
    i_this->mInf.mFluctuation = 250.0f;

    i_this->mSph.SetC(i_this->mPos);
    dComIfG_Ccsp()->Set(&i_this->mSph);
    if (!i_this->mHitTimeoutLeft) {
        if (i_this->mSph.ChkTgHit()) {
            cCcD_Obj* pHitObj = i_this->mSph.GetTgHitObj();
            if (pHitObj && pHitObj->ChkAtType(AT_TYPE_LEAF_WIND | AT_TYPE_UNK400000)) {
                i_this->mHitAngle = dComIfGp_getPlayer(0)->shape_angle.y;
                i_this->mHitTimeoutLeft = 0x28;
            }
        }
    } else {
        i_this->mHitTimeoutLeft--;
        if (i_this->mPa.mpEmitter) {
            float tgtZ;
            if (i_this->mHitTimeoutLeft > 10) {
                tgtZ = 4.0f;
            } else {
                tgtZ = 0.0f;
            }
            cLib_addCalc2(&i_this->mHitReactCurZ, tgtZ, 1.0f, 0.5f);
            cMtx_YrotS(*calc_mtx, i_this->mHitAngle);
            cXyz localPos;
            localPos.set(0.0f, 1.0f, i_this->mHitReactCurZ);
            cXyz globalPos;
            MtxPosition(&localPos, &globalPos);
            float y = globalPos.y;
            float z = globalPos.z;
            float x = globalPos.x;
            i_this->mPa.mpEmitter->mEmitterDir.set(x, y, z);
        }
    }

    return TRUE;
}

/* 00000604-00000634       .text daLamp_IsDelete__FP10lamp_class */
static BOOL daLamp_IsDelete(lamp_class* i_this) {
    i_this->mPa.end();
    return TRUE;
}

/* 00000634-00000678       .text daLamp_Delete__FP10lamp_class */
static BOOL daLamp_Delete(lamp_class* i_this) {
    dComIfG_resDelete(&i_this->mPhs, "Lamp");
    dKy_plight_cut(&i_this->mInf);
    return TRUE;
}

/* 00000678-0000073C       .text useHeapInit__FP10lamp_class */
static BOOL useHeapInit(lamp_class* i_this) {
    J3DModelData* modelData = static_cast<J3DModelData*>(dComIfG_getObjectRes("Lamp", 3));
    JUT_ASSERT(0x170, modelData != 0);

    i_this->mModel = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    if (i_this->mModel == 0) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/* 0000073C-0000075C       .text daLamp_solidHeapCB__FP10fopAc_ac_c */
static BOOL daLamp_solidHeapCB(fopAc_ac_c* i_ac) {
    return useHeapInit((lamp_class*)i_ac);
}

/* 0000075C-00000914       .text daLamp_Create__FP10fopAc_ac_c */
static int daLamp_Create(fopAc_ac_c* i_ac) {
    fopAcM_SetupActor(i_ac, lamp_class);
    lamp_class* i_this = (lamp_class*)i_ac;

    s32 phase_state = dComIfG_resLoad(&i_this->mPhs, "Lamp");
    if (phase_state == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(i_this, &daLamp_solidHeapCB, 0x6040)) {
            i_this->mParameters = fopAcM_GetParam(i_this);
            if (i_this->mParameters == 0xFF) {
                i_this->mParameters = 0;
            }
            i_this->mStts.Init(0xff, 0xff, i_this);
            i_this->mSph.Set(sph_src);
            i_this->mSph.SetStts(&i_this->mStts);

            i_this->mCycleCtr = cM_rndFX(32768.0f);

            for (int i = 0; i < 2; i++) {
                daLamp_Execute(i_this);
            }

            dKy_plight_set(&i_this->mInf);
        } else {
            phase_state = cPhs_ERROR_e;
        }
    }

    return phase_state;
}

static actor_method_class l_daLamp_Method = {
    (process_method_func)daLamp_Create,
    (process_method_func)daLamp_Delete,
    (process_method_func)daLamp_Execute,
    (process_method_func)daLamp_IsDelete,
    (process_method_func)daLamp_Draw,
};

actor_process_profile_definition g_profile_LAMP = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcLy_CURRENT_e,
    /* ProcName     */ PROC_LAMP,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(lamp_class),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x00AE,
    /* Actor SubMtd */ &l_daLamp_Method,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
