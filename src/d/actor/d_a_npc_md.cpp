//
// Generated by dtk
// Translation Unit: d_a_npc_md.cpp
//

#include "d/actor/d_a_npc_md.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "JSystem/JKernel/JKRHeap.h"

// Needed for the .data section to match.
static f32 dummy1[3] = {1.0f, 1.0f, 1.0f};
static f32 dummy2[3] = {1.0f, 1.0f, 1.0f};
static u8 dummy3[4] = {0x02, 0x00, 0x02, 0x01};
static f64 dummy4[2] = {3.0, 0.5};

static char* l_arc_name = "Md";
static char* l_arc_name_ship = "Md_ship";
static char* l_staff_name = "Md1";

static char* event_name_tbl[] = {
    "Md_ItemGet",
    "Md_RopeGet",
    "MD_FLY",
    "md_cliff",
    "Md_Fly2",
    "Md_Tact",
    "Md_TactTrue",
    "Md_HarpTalk",
    "OPTION_CHAR_END",
    "DEFAULT_TALK_XY",
};

static dCcD_SrcCyl l_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ ~(AT_TYPE_BOOMERANG | AT_TYPE_LEAF_WIND | AT_TYPE_LIGHT),
        /* SrcObjTg SPrm     */ 0x05,
        /* SrcObjCo SPrm     */ 0x75,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0x04,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 30.0f,
        /* Height */ 80.0f,
    },
};

static dCcD_SrcCyl l_light_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ AT_TYPE_LIGHT,
        /* SrcObjTg SPrm     */ 0x03,
        /* SrcObjCo SPrm     */ 0,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0x04,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 30.0f,
        /* Height */ 80.0f,
    },
};

static dCcD_SrcCps l_fan_light_cps_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ AT_TYPE_LIGHT,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0x0F,
        /* SrcObjTg Type     */ 0,
        /* SrcObjTg SPrm     */ 0,
        /* SrcObjCo SPrm     */ 0,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0x02,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGCpsS
    {
        /* Start  */ 0.0f, 0.0f, 0.0f,
        /* End    */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 70.0f,
    },
};

static dCcD_SrcCyl l_wind_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ AT_TYPE_LEAF_WIND,
        /* SrcObjTg SPrm     */ 0x03,
        /* SrcObjCo SPrm     */ 0,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0x04,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 30.0f,
        /* Height */ 80.0f,
    },
};

static char* hairName[] = {
    "hair1",
    "hair2",
    "hair3",
    "hair4",
    "hair5",
    "hair6",
    "hair7",
};


/* 000000EC-0000013C       .text __ct__15daNpc_Md_HIO6_cFv */
daNpc_Md_HIO6_c::daNpc_Md_HIO6_c() {
    m04 = 500.0f;
    m08 = 430;
    m0A = 9000;
    m0C = -5000;
    m0E = -9000;
    m10 = 0;
    m12 = 0;
    m14 = 0;
    m16 = 0;
}

/* 0000013C-00000164       .text __ct__15daNpc_Md_HIO5_cFv */
daNpc_Md_HIO5_c::daNpc_Md_HIO5_c() {
    m4 = 16.0f;
    m8 = 0.6f;
}

/* 00000164-00000188       .text __ct__15daNpc_Md_HIO4_cFv */
daNpc_Md_HIO4_c::daNpc_Md_HIO4_c() {
    /* Nonmatching */
    m4 = 86.0f;
    m8 = 0;
}

/* 00000188-000001F4       .text __ct__15daNpc_Md_HIO3_cFv */
daNpc_Md_HIO3_c::daNpc_Md_HIO3_c() {
    m04 = 0.8f;
    m08 = 0.2f;
    m0C = -5.0f;
    m10 = -5.0f;
    m14 = 0.0f;
    m18 = 0;
    m1A = 0;
    m1C = 0;
    m1E = 3800;
    m20 = 5800;
    m22 = 0x7FFF;
    m24 = -0x7FFF;
}

/* 000001F4-00000274       .text __ct__15daNpc_Md_HIO2_cFv */
daNpc_Md_HIO2_c::daNpc_Md_HIO2_c() {
    m26 = 0x19;
    m28 = 0x7FFF;
    m2A = 1;
    m04 = 5.0f;
    m08 = 17.0f;
    m0C = 7.0f;
    m10 = 6.0f;
    m14 = 0.7f;
    m20 = 3300;
    m22 = 2900;
    m24 = 5;
    m18 = 2.6f;
    m1C = 0.6f;
}

/* 00000274-00000574       .text __ct__14daNpc_Md_HIO_cFv */
daNpc_Md_HIO_c::daNpc_Md_HIO_c() {
    m08C.m04 = -25.0f;
    m08C.m08 = 0x2328;
    m08C.m0C = 0x2328;
    m08C.m0A = 0x0;
    m08C.m0E = 0x1F40;
    m08C.m10 = -0x2328;
    m08C.m14 = -0x2328;
    m08C.m12 = 0x0;
    m08C.m16 = -0x1F40;
    m08C.m18 = 0x1000;
    m08C.m1A = 0x800;
    m08C.m1C = 130.0f;
    m08C.m20 = 0x4000;
    m08C.m22 = 0x0;
    m08C.m24 = 150.0f;
    m0B4 = 0x0;
    m0B8 = 770.0f;
    m0BC = 250.0f;
    m0C0 = -450.0f;
    m0C4 = 90.0f;
    m0C8 = 400.0f;
    m0CC = 600.0f;
    m0D0 = 0.05;
    m0D4 = 17.0f;
    m0D8 = 0.0f;
    m0DC = 0.5;
    m0E0 = 0.3;
    m0E4 = 0.9;
    m0E8 = 15.0f;
    m0EC = 22.0f;
    m0F0 = 9.0f;
    m0F4 = 4.0f;
    m0F8 = -1.51367;
    m0FC = -1.09863;
    m100 = -0.56152;
    m104 = 0.1;
    m108 = 0.2;
    m10C = 10.0f;
    m110 = -50.0f;
    m114 = 1.3;
    m128 = 1200.0f;
    m12C = 1500.0f;
    m118 = 1.0f;
    m11C = 1.5;
    m120 = 2.0f;
    m124 = 1.6;
    m130 = 3.0f;
    m134 = 1.25;
    m138 = 0.2;
    m13C = 100.0f;
    m140 = 50.0f;
    m144 = 9.0f;
    m1B4 = 0x17;
    m1B6 = 0x14;
    m1C7 = 0x0;
    m148 = 0.9;
    m1C6 = 0x1;
    m14C = 6.0f;
    m1B8 = 0x4000;
    m150 = 10.0f;
    m1BA = 0x78;
    m1BC = 0x1F4;
    m154 = 5.0f;
    m158 = 2.2;
    m15C = -11.681;
    m160 = 1.3;
    m164 = 88.692;
    m168 = 57.066;
    m16C = 179.286;
    m1C8 = 0x0;
    m170 = 0.0f;
    m174 = 1.0f;
    m178 = 1.5;
    m17C = -100.0f;
    m180 = 100.0f;
    m184 = 10.0f;
    m188 = 1.0f;
    m18C = -10.0f;
    m1BE = 0x46;
    m1C0 = 0x5;
    m1C2 = 0x1C2;
    m1C4 = 0x96;
    m190 = 43.0f;
    m194 = 14.65;
    m198 = 13.99;
    m19C = 0.0f;
    m1A0 = -98.0f;
    m1A4 = 0.0f;
    m1A8 = 3.0f;
    m1AC = 1000.0f;
    m1B0 = 1000.0f;
    mChildID = -0x1;
}

/* 000006DC-000006FC       .text daNpc_Md_XyCheckCB__FPvi */
static void daNpc_Md_XyCheckCB(void* i_this, int param_1) {
    return static_cast<daNpc_Md_c*>(i_this)->XyCheckCB(param_1);
}

/* 000006FC-000007FC       .text XyCheckCB__10daNpc_Md_cFi */
void daNpc_Md_c::XyCheckCB(int) {
    /* Nonmatching */
}

/* 000007FC-0000081C       .text daNpc_Md_XyEventCB__FPvi */
static void daNpc_Md_XyEventCB(void* i_this, int param_1) {
    return static_cast<daNpc_Md_c*>(i_this)->XyEventCB(param_1);
}

/* 0000081C-00000864       .text XyEventCB__10daNpc_Md_cFi */
void daNpc_Md_c::XyEventCB(int) {
    /* Nonmatching */
}

/* 00000864-00000884       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c* i_this) {
    return static_cast<daNpc_Md_c*>(i_this)->createHeap();
}

/* 00000884-00000D80       .text create__10daNpc_Md_cFv */
s32 daNpc_Md_c::create() {
    /* Nonmatching */
    fopAcM_SetupActor(this, daNpc_Md_c);
}

/* 000012C0-00001444       .text nodeCallBack__FP7J3DNodei */
static int nodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 00001444-0000154C       .text waistNodeCallBack__FP7J3DNodei */
static int waistNodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 0000154C-0000160C       .text armNodeCallBack__FP7J3DNodei */
static int armNodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 0000160C-00001C60       .text hairCross__FP4cXyzP4cXyzP4cXyz */
static void hairCross(cXyz*, cXyz*, cXyz*) {
    /* Nonmatching */
}

/* 00001CBC-00001D0C       .text hairTopNodeCallBack__FP7J3DNodei */
static int hairTopNodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 00001D0C-00001F5C       .text vecChange__FP4cXyzP4cXyzs */
static void vecChange(cXyz*, cXyz*, short) {
    /* Nonmatching */
}

/* 00001F5C-0000240C       .text hairNodeCallBack__FP7J3DNodei */
static int hairNodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 0000240C-00002F80       .text createHeap__10daNpc_Md_cFv */
BOOL daNpc_Md_c::createHeap() {
    /* Nonmatching */
    char wait_anim_name[32];
    char arm_wait_anim_name[32];
    if (m3138 == 7) {
        strcpy(wait_anim_name, "md_shipwait.bck");
        strcpy(arm_wait_anim_name, "mdarm_shipwait.bck");
    } else {
        strcpy(wait_anim_name, "md_wait01.bck");
        strcpy(arm_wait_anim_name, "mdarm_wait01.bck");
    }
    
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes(mModelArcName, "md.bdl");
    JUT_ASSERT(1995, modelData != 0);
    
    mpMorf = new mDoExt_McaMorf2(
        modelData,
        NULL, NULL,
        (J3DAnmTransformKey*)dComIfG_getObjectRes(mModelArcName, wait_anim_name),
        NULL,
        J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, 1,
        NULL,
        0x00080000,
        0x11020022
    );
    if (!mpMorf || !mpMorf->getModel()) {
        return FALSE;
    }
    
    m_backbone1_jnt_num = modelData->getJointName()->getIndex("backbone1");
    JUT_ASSERT(2013, m_backbone1_jnt_num >= 0);
    m_backbone2_jnt_num = modelData->getJointName()->getIndex("backbone2");
    JUT_ASSERT(2016, m_backbone2_jnt_num >= 0);
    m_armR_jnt_num = modelData->getJointName()->getIndex("armR");
    JUT_ASSERT(2019, m_armR_jnt_num >= 0);
    m_armL_jnt_num = modelData->getJointName()->getIndex("armL");
    JUT_ASSERT(2022, m_armL_jnt_num >= 0);
    m_neck_jnt_num = modelData->getJointName()->getIndex("neck");
    JUT_ASSERT(2025, m_neck_jnt_num >= 0);
    
    s16 neck_jnt_num = modelData->getJointName()->getIndex("neck");
    if (neck_jnt_num >= 0) {
        modelData->getJointNodePointer(neck_jnt_num)->setCallBack(nodeCallBack);
    }
    modelData->getJointNodePointer(m_backbone1_jnt_num)->setCallBack(waistNodeCallBack);
    m_hair_jnt_nums[0] = modelData->getJointName()->getIndex(hairName[0]);
    if (m_hair_jnt_nums[0] >= 0) {
        modelData->getJointNodePointer(m_hair_jnt_nums[0])->setCallBack(hairTopNodeCallBack);
    }
    for (int i = 1; i < 8; i++) {
        m_hair_jnt_nums[i] = modelData->getJointName()->getIndex(hairName[i]);
        if (m_hair_jnt_nums[i] >= 0) {
            modelData->getJointNodePointer(m_hair_jnt_nums[i])->setCallBack(hairNodeCallBack);
        }
    }
    
    mpMorf->getModel()->setUserArea((u32)this);
    
    modelData = (J3DModelData*)dComIfG_getObjectRes(mModelArcName, "md.bdl");
    JUT_ASSERT(2051, modelData != 0);
    
    mpArmMorf = new mDoExt_McaMorf2(
        modelData,
        NULL, NULL,
        (J3DAnmTransformKey*)dComIfG_getObjectRes(mModelArcName, arm_wait_anim_name),
        NULL,
        J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, 0,
        NULL,
        0x00000000,
        0x11020203
    );
    if (!mpArmMorf || !mpArmMorf->getModel()) {
        return FALSE;
    }
    
    m_armRloc_jnt_num = modelData->getJointName()->getIndex("armRloc");
    JUT_ASSERT(2065, m_armRloc_jnt_num >= 0);
    m_armLloc_jnt_num = modelData->getJointName()->getIndex("armLloc");
    JUT_ASSERT(2068, m_armLloc_jnt_num >= 0);
    m_handL_jnt_num = modelData->getJointName()->getIndex("handL");
    JUT_ASSERT(2071, m_handL_jnt_num >= 0);
    
    modelData->getJointNodePointer(m_armRloc_jnt_num)->setCallBack(armNodeCallBack);
    modelData->getJointNodePointer(m_armLloc_jnt_num)->setCallBack(armNodeCallBack);
    
    mpArmMorf->getModel()->setUserArea((u32)this);
    
    if (m3138 != 7) {
        modelData = (J3DModelData*)dComIfG_getObjectRes(mModelArcName, "mdwing.bdl");
        JUT_ASSERT(2077, modelData != 0);
        
        mpWingMorf = new mDoExt_McaMorf(
            modelData,
            NULL, NULL,
            (J3DAnmTransformKey*)dComIfG_getObjectRes(mModelArcName, "mdwing_wait01.bck"),
            J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, 0,
            NULL,
            0x00000000,
            0x11020203
        );
        if (!mpWingMorf || !mpWingMorf->getModel()) {
            return FALSE;
        }
        
        m_wingRloc_jnt_num = modelData->getJointName()->getIndex("wingRloc");
        JUT_ASSERT(2097, m_wingRloc_jnt_num >= 0);
        m_wingLloc_jnt_num = modelData->getJointName()->getIndex("wingLloc");
        JUT_ASSERT(2100, m_wingLloc_jnt_num >= 0);
        m_wingR2_jnt_num = modelData->getJointName()->getIndex("wingR2");
        JUT_ASSERT(2103, m_wingR2_jnt_num >= 0);
        m_wingL2_jnt_num = modelData->getJointName()->getIndex("wingL2");
        JUT_ASSERT(2106, m_wingL2_jnt_num >= 0);
        m_wingR3_jnt_num = modelData->getJointName()->getIndex("wingR3");
        JUT_ASSERT(2109, m_wingR3_jnt_num >= 0);
        m_wingL3_jnt_num = modelData->getJointName()->getIndex("wingL3");
        JUT_ASSERT(2112, m_wingL3_jnt_num >= 0);
        
        modelData->getJointNodePointer(m_wingRloc_jnt_num)->setCallBack(armNodeCallBack);
        modelData->getJointNodePointer(m_wingLloc_jnt_num)->setCallBack(armNodeCallBack);
        
        mpWingMorf->getModel()->setUserArea((u32)this);
    }
    
    modelData = (J3DModelData*)dComIfG_getObjectRes(mModelArcName, "mdharp.bdl");
    mpHarpModel = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    if (!mpHarpModel) {
        return FALSE;
    }
    
    modelData = (J3DModelData*)dComIfG_getObjectRes(mModelArcName, "ymdhp00.bdl");
    mpHarpLightModel = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    if (!mpHarpLightModel) {
        return FALSE;
    }
    
    if (!initLightBtkAnm(false)) {
        return FALSE;
    }
    if (!initTexPatternAnm(0, 0)) {
        return FALSE;
    }
    
    mAcchCir[0].SetWall(20.0f, 20.0f);
    mAcchCir[1].SetWall(60.0f, 20.0f);
    mAcch.Set(&current.pos, &next.pos, this, ARRAY_SIZE(mAcchCir), mAcchCir, &speed, NULL, NULL);
    mAcch.ClrRoofNone();
    mAcch.SetRoofCrrHeight(120.0f);
    mAcch.OnLineCheck();
    mAcch.ClrWaterNone();
    
    return TRUE;
}

/* 00002F80-00003050       .text setAction__10daNpc_Md_cFPM10daNpc_Md_cFPCvPvPv_iM10daNpc_Md_cFPCvPvPv_iPv */
BOOL daNpc_Md_c::setAction(ActionFunc* pCurrActionFunc, ActionFunc newActionFunc, void* arg) {
    if (*pCurrActionFunc != newActionFunc) {
        if (*pCurrActionFunc) {
            mActionStatus = ACTION_ENDING;
            (this->**pCurrActionFunc)(arg);
        }
        *pCurrActionFunc = newActionFunc;
        mActionStatus = ACTION_STARTING;
        m3144 = 0;
        m3146 = 0;
        m3148 = 0;
        m314A = 0;
        m3150 = 0.0f;
        (this->**pCurrActionFunc)(arg);
    }
    return TRUE;
}

/* 00003050-00003124       .text npcAction__10daNpc_Md_cFPv */
void daNpc_Md_c::npcAction(void* arg) {
    if (!mCurrNpcActionFunc) {
        speedF = 0.0f;
        if (m3104 == 0x20) {
            setNpcAction(&mwaitNpcAction, NULL);
        } else {
            setNpcAction(&waitNpcAction, NULL);
        }
    }
    
    (this->*mCurrNpcActionFunc)(arg);
}

/* 00003124-00003194       .text setNpcAction__10daNpc_Md_cFM10daNpc_Md_cFPCvPvPv_iPv */
void daNpc_Md_c::setNpcAction(ActionFunc actionFunc, void* arg) {
    m_flying = false;
    mCurrPlayerActionFunc = NULL;
    setAction(&mCurrNpcActionFunc, actionFunc, arg);
}

/* 00003194-00003360       .text playerAction__10daNpc_Md_cFPv */
void daNpc_Md_c::playerAction(void* arg) {
    /* Nonmatching */
    if (!mCurrPlayerActionFunc) {
        speedF = 0.0f;
        setPlayerAction(&waitPlayerAction, NULL);
    }
    
    if (mAcch.ChkGroundHit() && isOldLightBodyHit()) {
        dComIfGp_setRStatusForce(0x07); // Show "Return" on the R button
        if (chkPlayerAction(mkamaePlayerAction)) {
            dComIfGp_setDoStatus(0x00); // Show the A button without anything on it
            dComIfGp_setAStatus(0x08); // TODO
        } else {
            dComIfGp_setDoStatus(0x2E); // TODO
            dComIfGp_setAStatus(0x3E); // Do not display the B button icon at all
            if (!m3140) {
                dComIfGp_getVibration().StartShock(4, -0x21, cXyz(0.0f, 1.0f, 0.0f));
            }
        }
    } else {
        dComIfGp_setDoStatus(0x23); // Show "Fly" on the A button
        if (chkPlayerAction(flyPlayerAction)) {
            dComIfGp_setRStatusForce(0x3E); // TODO
            dComIfGp_setAStatus(0x06); // Show "Let Go" on the B button icon
        } else {
            dComIfGp_setRStatusForce(0x07); // Show "Return" on the R button
            dComIfGp_setAStatus(0x3E); // Do not display the B button icon at all
        }
    }
    
    (this->*mCurrPlayerActionFunc)(arg);
}

/* 00003360-000033C4       .text setPlayerAction__10daNpc_Md_cFM10daNpc_Md_cFPCvPvPv_iPv */
void daNpc_Md_c::setPlayerAction(ActionFunc actionFunc, void* arg) {
    /* Nonmatching */
}

/* 000033C4-00003430       .text getStickAngY__10daNpc_Md_cFi */
void daNpc_Md_c::getStickAngY(int) {
    /* Nonmatching */
}

/* 00003430-00003588       .text calcStickPos__10daNpc_Md_cFsP4cXyz */
void daNpc_Md_c::calcStickPos(short, cXyz*) {
    /* Nonmatching */
}

/* 00003588-0000362C       .text flyCheck__10daNpc_Md_cFv */
void daNpc_Md_c::flyCheck() {
    /* Nonmatching */
}

/* 0000362C-00003648       .text mirrorCancelCheck__10daNpc_Md_cFv */
void daNpc_Md_c::mirrorCancelCheck() {
    /* Nonmatching */
}

/* 00003648-00003674       .text setWingEmitter__10daNpc_Md_cFv */
void daNpc_Md_c::setWingEmitter() {
    /* Nonmatching */
}

/* 00003674-000036C0       .text setHane02Emitter__10daNpc_Md_cFv */
void daNpc_Md_c::setHane02Emitter() {
    /* Nonmatching */
}

/* 000036C0-000036FC       .text deleteHane02Emitter__10daNpc_Md_cFv */
void daNpc_Md_c::deleteHane02Emitter() {
    /* Nonmatching */
}

/* 000036FC-00003748       .text setHane03Emitter__10daNpc_Md_cFv */
void daNpc_Md_c::setHane03Emitter() {
    /* Nonmatching */
}

/* 00003748-00003784       .text deleteHane03Emitter__10daNpc_Md_cFv */
void daNpc_Md_c::deleteHane03Emitter() {
    /* Nonmatching */
}

/* 00003784-000037C4       .text returnLinkPlayer__10daNpc_Md_cFv */
void daNpc_Md_c::returnLinkPlayer() {
    /* Nonmatching */
}

/* 000037C4-00003824       .text shipRideCheck__10daNpc_Md_cFv */
void daNpc_Md_c::shipRideCheck() {
    /* Nonmatching */
}

/* 00003824-00003908       .text isFallAction__10daNpc_Md_cFv */
void daNpc_Md_c::isFallAction() {
    /* Nonmatching */
}

/* 00003908-00003958       .text returnLinkCheck__10daNpc_Md_cFv */
void daNpc_Md_c::returnLinkCheck() {
    /* Nonmatching */
}

/* 00003958-00003D20       .text lightHitCheck__10daNpc_Md_cFv */
void daNpc_Md_c::lightHitCheck() {
    /* Nonmatching */
}

/* 00003D20-00003D68       .text wallHitCheck__10daNpc_Md_cFv */
void daNpc_Md_c::wallHitCheck() {
    /* Nonmatching */
}

/* 00003D68-00003E74       .text NpcCall__10daNpc_Md_cFPi */
void daNpc_Md_c::NpcCall(int*) {
    /* Nonmatching */
}

/* 00003E74-00003FE0       .text checkCollision__10daNpc_Md_cFi */
void daNpc_Md_c::checkCollision(int) {
    /* Nonmatching */
}

/* 00003FE0-00004040       .text restartPoint__10daNpc_Md_cFs */
void daNpc_Md_c::restartPoint(short) {
    /* Nonmatching */
}

/* 00004040-00004174       .text isTagCheckOK__10daNpc_Md_cFv */
BOOL daNpc_Md_c::isTagCheckOK() {
    /* Nonmatching */
}

/* 00004174-00004230       .text setMessageAnimation__10daNpc_Md_cFUc */
void daNpc_Md_c::setMessageAnimation(unsigned char) {
    /* Nonmatching */
}

/* 00004230-0000433C       .text waitGroundCheck__10daNpc_Md_cFv */
void daNpc_Md_c::waitGroundCheck() {
    /* Nonmatching */
}

/* 0000433C-000043D4       .text chkAdanmaeDemoOrder__10daNpc_Md_cFv */
void daNpc_Md_c::chkAdanmaeDemoOrder() {
    /* Nonmatching */
}

/* 000043D4-00004B04       .text waitNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::waitNpcAction(void*) {
    /* Nonmatching */
}

/* 00004B04-00004CFC       .text harpWaitNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::harpWaitNpcAction(void*) {
    /* Nonmatching */
}

/* 00004CFC-00004D40       .text XYTalkCheck__10daNpc_Md_cFv */
void daNpc_Md_c::XYTalkCheck() {
    /* Nonmatching */
}

/* 00004D40-0000504C       .text talkNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::talkNpcAction(void*) {
    /* Nonmatching */
}

/* 0000504C-000051FC       .text shipTalkNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::shipTalkNpcAction(void*) {
    /* Nonmatching */
}

/* 000051FC-00005308       .text kyohiNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::kyohiNpcAction(void*) {
    /* Nonmatching */
}

/* 00005308-00005534       .text shipNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::shipNpcAction(void*) {
    /* Nonmatching */
}

/* 00005534-000057B0       .text mwaitNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::mwaitNpcAction(void*) {
    /* Nonmatching */
}

/* 000057B0-000058E0       .text squatdownNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::squatdownNpcAction(void*) {
    /* Nonmatching */
}

/* 000058E0-00005A74       .text sqwait01NpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::sqwait01NpcAction(void*) {
    /* Nonmatching */
}

/* 00005A74-00005AB0       .text changeCaught02__10daNpc_Md_cFv */
void daNpc_Md_c::changeCaught02() {
    /* Nonmatching */
}

/* 00005AB0-000061A8       .text carryNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::carryNpcAction(void*) {
    /* Nonmatching */
}

/* 000061A8-00006450       .text throwNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::throwNpcAction(void*) {
    /* Nonmatching */
}

/* 00006450-00006764       .text glidingNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::glidingNpcAction(void*) {
    /* Nonmatching */
}

/* 00006764-00006B24       .text windProc__10daNpc_Md_cFv */
void daNpc_Md_c::windProc() {
    /* Nonmatching */
}

/* 00006B24-00006C80       .text fallNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::fallNpcAction(void*) {
    /* Nonmatching */
}

/* 00006C80-00006F70       .text fall02NpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::fall02NpcAction(void*) {
    /* Nonmatching */
}

/* 00006F70-000071E4       .text wallHitNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::wallHitNpcAction(void*) {
    /* Nonmatching */
}

/* 000071E4-000073BC       .text land01NpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::land01NpcAction(void*) {
    /* Nonmatching */
}

/* 000073BC-000074C0       .text land02NpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::land02NpcAction(void*) {
    /* Nonmatching */
}

/* 000074C0-000075C4       .text land03NpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::land03NpcAction(void*) {
    /* Nonmatching */
}

/* 000075C4-00007824       .text piyo2NpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::piyo2NpcAction(void*) {
    /* Nonmatching */
}

/* 00007824-0000786C       .text deleteNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::deleteNpcAction(void*) {
    /* Nonmatching */
}

/* 0000786C-00007A98       .text demoFlyNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::demoFlyNpcAction(void*) {
    /* Nonmatching */
}

/* 00007A98-00007B64       .text routeAngCheck__10daNpc_Md_cFR4cXyzPs */
void daNpc_Md_c::routeAngCheck(cXyz&, short*) {
    /* Nonmatching */
}

/* 00007B64-00007DC8       .text routeWallCheck__10daNpc_Md_cFR4cXyzR4cXyzPs */
void daNpc_Md_c::routeWallCheck(cXyz&, cXyz&, short*) {
    /* Nonmatching */
}

/* 00007DC8-00008054       .text checkForwardGroundY__10daNpc_Md_cFs */
void daNpc_Md_c::checkForwardGroundY(short) {
    /* Nonmatching */
}

/* 000081EC-000082C0       .text checkWallJump__10daNpc_Md_cFs */
void daNpc_Md_c::checkWallJump(short) {
    /* Nonmatching */
}

/* 000082C0-00008858       .text routeCheck__10daNpc_Md_cFfPs */
void daNpc_Md_c::routeCheck(float, short*) {
    /* Nonmatching */
}

/* 00008858-00008CEC       .text searchNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::searchNpcAction(void*) {
    /* Nonmatching */
}

/* 00008CEC-00008E54       .text hitNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::hitNpcAction(void*) {
    /* Nonmatching */
}

/* 00008E54-00008FFC       .text setNormalSpeedF__10daNpc_Md_cFfffff */
void daNpc_Md_c::setNormalSpeedF(float, float, float, float, float) {
    /* Nonmatching */
}

/* 00008FFC-000090EC       .text setSpeedAndAngleNormal__10daNpc_Md_cFfs */
void daNpc_Md_c::setSpeedAndAngleNormal(float, short) {
    /* Nonmatching */
}

/* 000090EC-00009180       .text walkProc__10daNpc_Md_cFfs */
void daNpc_Md_c::walkProc(float, short) {
    /* Nonmatching */
}

/* 00009180-000092E0       .text jumpNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::jumpNpcAction(void*) {
    /* Nonmatching */
}

/* 000092E0-000095C8       .text escapeNpcAction__10daNpc_Md_cFPv */
int daNpc_Md_c::escapeNpcAction(void*) {
    /* Nonmatching */
}

/* 000095C8-00009894       .text waitPlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::waitPlayerAction(void*) {
    /* Nonmatching */
}

/* 00009894-00009B08       .text walkPlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::walkPlayerAction(void*) {
    /* Nonmatching */
}

/* 00009B08-00009CCC       .text hitPlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::hitPlayerAction(void*) {
    /* Nonmatching */
}

/* 00009CCC-00009E7C       .text jumpPlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::jumpPlayerAction(void*) {
    /* Nonmatching */
}

/* 00009E7C-0000A534       .text flyPlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::flyPlayerAction(void*) {
    /* Nonmatching */
}

/* 0000A534-0000A698       .text landPlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::landPlayerAction(void*) {
    /* Nonmatching */
}

/* 0000A698-0000A8D0       .text mkamaePlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::mkamaePlayerAction(void*) {
    /* Nonmatching */
}

/* 0000A8D0-0000A9BC       .text carryPlayerAction__10daNpc_Md_cFPv */
int daNpc_Md_c::carryPlayerAction(void*) {
    /* Nonmatching */
}

/* 0000A9BC-0000AC80       .text eventProc__10daNpc_Md_cFv */
void daNpc_Md_c::eventProc() {
    /* Nonmatching */
}

/* 0000AC80-0000AC84       .text initialDefault__10daNpc_Md_cFi */
void daNpc_Md_c::initialDefault(int) {
}

/* 0000AC84-0000ACB4       .text actionDefault__10daNpc_Md_cFi */
void daNpc_Md_c::actionDefault(int) {
    /* Nonmatching */
}

/* 0000ACB4-0000AD9C       .text initialWaitEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialWaitEvent(int) {
    /* Nonmatching */
}

/* 0000AD9C-0000ADCC       .text actionWaitEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionWaitEvent(int) {
    /* Nonmatching */
}

/* 0000ADCC-0000AEB8       .text initialLetterEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialLetterEvent(int) {
    /* Nonmatching */
}

/* 0000AEB8-0000AFB0       .text initialMsgSetEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialMsgSetEvent(int) {
    /* Nonmatching */
}

/* 0000AFB0-0000AFFC       .text actionMsgSetEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionMsgSetEvent(int) {
    /* Nonmatching */
}

/* 0000AFFC-0000B070       .text actionMsgEndEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionMsgEndEvent(int) {
    /* Nonmatching */
}

/* 0000B070-0000B728       .text initialMovePosEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialMovePosEvent(int) {
    /* Nonmatching */
}

/* 0000B728-0000B79C       .text initialFlyEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialFlyEvent(int) {
    /* Nonmatching */
}

/* 0000B79C-0000B870       .text actionFlyEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionFlyEvent(int) {
    /* Nonmatching */
}

/* 0000B870-0000B890       .text initialGlidingEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialGlidingEvent(int) {
    /* Nonmatching */
}

/* 0000B890-0000B934       .text actionGlidingEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionGlidingEvent(int) {
    /* Nonmatching */
}

/* 0000B934-0000B99C       .text initialLandingEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialLandingEvent(int) {
    /* Nonmatching */
}

/* 0000B99C-0000B9E0       .text actionLandingEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionLandingEvent(int) {
    /* Nonmatching */
}

/* 0000B9E0-0000B9F8       .text initialWalkEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialWalkEvent(int) {
    /* Nonmatching */
}

/* 0000B9F8-0000BCC4       .text actionWalkEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionWalkEvent(int) {
    /* Nonmatching */
}

/* 0000BCC4-0000BF1C       .text actionDashEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionDashEvent(int) {
    /* Nonmatching */
}

/* 0000BF1C-0000C12C       .text initialEndEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialEndEvent(int) {
    /* Nonmatching */
}

/* 0000C12C-0000C250       .text actionTactEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionTactEvent(int) {
    /* Nonmatching */
}

/* 0000C250-0000C288       .text initialTakeOffEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialTakeOffEvent(int) {
    /* Nonmatching */
}

/* 0000C288-0000C2C4       .text actionTakeOffEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionTakeOffEvent(int) {
    /* Nonmatching */
}

/* 0000C2C4-0000C360       .text initialOnetimeEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialOnetimeEvent(int) {
    /* Nonmatching */
}

/* 0000C360-0000C3C4       .text actionOnetimeEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionOnetimeEvent(int) {
    /* Nonmatching */
}

/* 0000C3C4-0000C48C       .text initialQuake__10daNpc_Md_cFi */
void daNpc_Md_c::initialQuake(int) {
    /* Nonmatching */
}

/* 0000C48C-0000C4DC       .text setHarpPlayNum__10daNpc_Md_cFi */
void daNpc_Md_c::setHarpPlayNum(int) {
    /* Nonmatching */
}

/* 0000C4DC-0000C500       .text initialHarpPlayEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialHarpPlayEvent(int) {
    /* Nonmatching */
}

/* 0000C500-0000C554       .text actionHarpPlayEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionHarpPlayEvent(int) {
    /* Nonmatching */
}

/* 0000C554-0000C570       .text initialOffLinkEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialOffLinkEvent(int) {
    /* Nonmatching */
}

/* 0000C570-0000C58C       .text initialOnLinkEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialOnLinkEvent(int) {
    /* Nonmatching */
}

/* 0000C58C-0000C654       .text initialTurnEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialTurnEvent(int) {
    /* Nonmatching */
}

/* 0000C654-0000C7CC       .text actionTurnEvent__10daNpc_Md_cFi */
void daNpc_Md_c::actionTurnEvent(int) {
    /* Nonmatching */
}

/* 0000C7CC-0000CA5C       .text initialSetAnmEvent__10daNpc_Md_cFi */
void daNpc_Md_c::initialSetAnmEvent(int) {
    /* Nonmatching */
}

/* 0000CA5C-0000CA80       .text initialLookDown__10daNpc_Md_cFi */
void daNpc_Md_c::initialLookDown(int) {
    /* Nonmatching */
}

/* 0000CA80-0000CAA4       .text initialLookUp__10daNpc_Md_cFi */
void daNpc_Md_c::initialLookUp(int) {
    /* Nonmatching */
}

/* 0000CAA4-0000CB8C       .text actionLookDown__10daNpc_Md_cFi */
void daNpc_Md_c::actionLookDown(int) {
    /* Nonmatching */
}

/* 0000CB8C-0000CC10       .text talk_init__10daNpc_Md_cFv */
void daNpc_Md_c::talk_init() {
    /* Nonmatching */
}

/* 0000CC10-0000CDCC       .text talk__10daNpc_Md_cFi */
void daNpc_Md_c::talk(int) {
    /* Nonmatching */
}

/* 0000CDCC-0000CDF4       .text getAnmType__10daNpc_Md_cFUc */
void daNpc_Md_c::getAnmType(unsigned char) {
    /* Nonmatching */
}

/* 0000CDF4-0000CF18       .text initTexPatternAnm__10daNpc_Md_cFUcb */
BOOL daNpc_Md_c::initTexPatternAnm(unsigned char, bool) {
    /* Nonmatching */
}

/* 0000CF18-0000CFCC       .text playTexPatternAnm__10daNpc_Md_cFv */
void daNpc_Md_c::playTexPatternAnm() {
    /* Nonmatching */
}

/* 0000CFCC-0000D0B8       .text initLightBtkAnm__10daNpc_Md_cFb */
BOOL daNpc_Md_c::initLightBtkAnm(bool) {
    /* Nonmatching */
}

/* 0000D0B8-0000D0DC       .text playLightBtkAnm__10daNpc_Md_cFv */
void daNpc_Md_c::playLightBtkAnm() {
    /* Nonmatching */
}

/* 0000D0DC-0000D4CC       .text setAnm__10daNpc_Md_cFi */
void daNpc_Md_c::setAnm(int) {
    /* Nonmatching */
}

/* 0000D4CC-0000D5E4       .text dNpc_Md_setAnm__10daNpc_Md_cFP15mDoExt_McaMorf2fiffPcPcPCc */
void daNpc_Md_c::dNpc_Md_setAnm(mDoExt_McaMorf2*, float, int, float, float, char*, char*, const char*) {
    /* Nonmatching */
}

/* 0000D5E4-0000D614       .text dNpc_Md_setAnm__10daNpc_Md_cFP14mDoExt_McaMorfiffPcPCc */
void daNpc_Md_c::dNpc_Md_setAnm(mDoExt_McaMorf*, int, float, float, char*, const char*) {
    /* Nonmatching */
}

/* 0000D614-0000D82C       .text chkAttention__10daNpc_Md_cF4cXyzsi */
void daNpc_Md_c::chkAttention(cXyz, short, int) {
    /* Nonmatching */
}

/* 0000D82C-0000D8FC       .text chkArea__10daNpc_Md_cFP4cXyz */
void daNpc_Md_c::chkArea(cXyz*) {
    /* Nonmatching */
}

/* 0000D8FC-0000D950       .text carryCheck__10daNpc_Md_cFv */
void daNpc_Md_c::carryCheck() {
    /* Nonmatching */
}

/* 0000D950-0000DAD4       .text eventOrder__10daNpc_Md_cFv */
void daNpc_Md_c::eventOrder() {
    /* Nonmatching */
}

/* 0000DAD4-0000DC14       .text checkOrder__10daNpc_Md_cFv */
void daNpc_Md_c::checkOrder() {
    /* Nonmatching */
}

/* 0000DC14-0000DCB0       .text checkCommandTalk__10daNpc_Md_cFv */
void daNpc_Md_c::checkCommandTalk() {
    /* Nonmatching */
}

/* 0000DCB0-0000E410       .text next_msgStatus__10daNpc_Md_cFPUl */
void daNpc_Md_c::next_msgStatus(unsigned long*) {
    /* Nonmatching */
}

/* 0000E410-0000E64C       .text getMsg__10daNpc_Md_cFv */
void daNpc_Md_c::getMsg() {
    /* Nonmatching */
}

/* 0000E64C-0000E95C       .text setCollision__10daNpc_Md_cFv */
void daNpc_Md_c::setCollision() {
    /* Nonmatching */
}

/* 0000E95C-0000E9F0       .text setAttention__10daNpc_Md_cFb */
void daNpc_Md_c::setAttention(bool) {
    /* Nonmatching */
}

/* 0000E9F0-0000EB28       .text lookBack__10daNpc_Md_cFiii */
void daNpc_Md_c::lookBack(int, int, int) {
    /* Nonmatching */
}

/* 0000EB28-0000EC38       .text lookBack__10daNpc_Md_cFP4cXyzii */
void daNpc_Md_c::lookBack(cXyz*, int, int) {
    /* Nonmatching */
}

/* 0000EC38-0000EDD0       .text lookBackWaist__10daNpc_Md_cFsf */
void daNpc_Md_c::lookBackWaist(short, float) {
    /* Nonmatching */
}

/* 0000EDD0-0000F100       .text setBaseMtx__10daNpc_Md_cFv */
void daNpc_Md_c::setBaseMtx() {
    /* Nonmatching */
}

/* 0000F100-0000F160       .text deletePiyoPiyo__10daNpc_Md_cFv */
void daNpc_Md_c::deletePiyoPiyo() {
    /* Nonmatching */
}

/* 0000F160-0000F4E0       .text init__10daNpc_Md_cFv */
void daNpc_Md_c::init() {
    /* Nonmatching */
}

/* 0000F4E0-0000F8EC       .text draw__10daNpc_Md_cFv */
BOOL daNpc_Md_c::draw() {
    /* Nonmatching */
}

/* 0000F8EC-0000FC18       .text animationPlay__10daNpc_Md_cFv */
void daNpc_Md_c::animationPlay() {
    /* Nonmatching */
}

/* 0000FC18-0000FC58       .text checkPlayerRoom__10daNpc_Md_cFv */
void daNpc_Md_c::checkPlayerRoom() {
    /* Nonmatching */
}

/* 0000FC58-000108B0       .text execute__10daNpc_Md_cFv */
BOOL daNpc_Md_c::execute() {
    /* Nonmatching */
}

/* 000108B0-00010948       .text particle_set__10daNpc_Md_cFPP14JPABaseEmitterUs */
void daNpc_Md_c::particle_set(JPABaseEmitter**, unsigned short) {
    /* Nonmatching */
}

/* 00010948-000109A0       .text emitterTrace__10daNpc_Md_cFP14JPABaseEmitterPA4_fP5csXyz */
void daNpc_Md_c::emitterTrace(JPABaseEmitter*, float(*)[4], csXyz*) {
    /* Nonmatching */
}

/* 000109A0-000109DC       .text emitterDelete__10daNpc_Md_cFPP14JPABaseEmitter */
void daNpc_Md_c::emitterDelete(JPABaseEmitter**) {
    /* Nonmatching */
}

/* 000109DC-000110BC       .text __dt__10daNpc_Md_cFv */
daNpc_Md_c::~daNpc_Md_c() {
    /* Nonmatching */
}

/* 000110BC-000110DC       .text daNpc_Md_Create__FP10fopAc_ac_c */
static s32 daNpc_Md_Create(fopAc_ac_c* i_this) {
    return static_cast<daNpc_Md_c*>(i_this)->create();
}

/* 000110DC-00011104       .text daNpc_Md_Delete__FP10daNpc_Md_c */
static BOOL daNpc_Md_Delete(daNpc_Md_c* i_this) {
    i_this->~daNpc_Md_c();
    return TRUE;
}

/* 00011104-00011124       .text daNpc_Md_Execute__FP10daNpc_Md_c */
static BOOL daNpc_Md_Execute(daNpc_Md_c* i_this) {
    return i_this->execute();
}

/* 00011124-00011144       .text daNpc_Md_Draw__FP10daNpc_Md_c */
static BOOL daNpc_Md_Draw(daNpc_Md_c* i_this) {
    return i_this->draw();
}

/* 00011144-0001114C       .text daNpc_Md_IsDelete__FP10daNpc_Md_c */
static BOOL daNpc_Md_IsDelete(daNpc_Md_c* i_this) {
    return TRUE;
}

/* 0001114C-0001119C       .text execute__26daNpc_Md_followEcallBack_cFP14JPABaseEmitter */
void daNpc_Md_followEcallBack_c::execute(JPABaseEmitter*) {
    /* Nonmatching */
}

/* 0001119C-000111A4       .text setup__26daNpc_Md_followEcallBack_cFP14JPABaseEmitterPC4cXyzPC5csXyzSc */
void daNpc_Md_followEcallBack_c::setup(JPABaseEmitter*, const cXyz*, const csXyz*, signed char) {
    /* Nonmatching */
}

/* 000111A4-000111D8       .text end__26daNpc_Md_followEcallBack_cFv */
void daNpc_Md_followEcallBack_c::end() {
    /* Nonmatching */
}

static actor_method_class l_daNpc_Md_Method = {
    (process_method_func)daNpc_Md_Create,
    (process_method_func)daNpc_Md_Delete,
    (process_method_func)daNpc_Md_Execute,
    (process_method_func)daNpc_Md_IsDelete,
    (process_method_func)daNpc_Md_Draw,
};

actor_process_profile_definition g_profile_NPC_MD = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcLy_CURRENT_e,
    /* ProcName     */ PROC_NPC_MD,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daNpc_Md_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0175,
    /* Actor SubMtd */ &l_daNpc_Md_Method,
    /* Status       */ 0x08 | fopAcStts_SHOWMAP_e | fopAcStts_CULL_e | fopAcStts_FREEZE_e | fopAcStts_UNK4000_e | fopAcStts_UNK40000_e | fopAcStts_UNK2000000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
