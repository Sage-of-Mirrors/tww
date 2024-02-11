//
// Generated by dtk
// Translation Unit: d_bg_w.cpp
//

#include "d/d_bg_w.h"
#include "d/d_bg_s.h"
#include "d/d_bg_s_acch.h"

#define CHECK_FLOAT_CLASS(line, x) JUT_ASSERT(line, !(((sizeof(x) == sizeof(float)) ? __fpclassifyf((float)(x)) : __fpclassifyd((double)(x)) ) == 1));

/* 800A5C3C-800A5CA8       .text __ct__4dBgWFv */
dBgW::dBgW() {
    mRotYDelta = 0;
    mOldRotY = 0;
    m_crr_func = NULL;
    mpRideCb = NULL;
    mpPushPullCb = NULL;
    mFlag = 0;
    mRoomNo = 0xFFFF;
    mRoomNo2 = 0xFF;
}

/* 800A5CA8-800A5CD4       .text Move__4dBgWFv */
void dBgW::Move() {
    mFlag |= 0x01;
    cBgW::Move();
}

/* 800A5CD4-800A5E64       .text positionWallCorrect__4dBgWFP9dBgS_AcchfR8cM3dGPlaP4cXyzf */
void dBgW::positionWallCorrect(dBgS_Acch* acch, f32 dist, cM3dGPla& plane, cXyz* pupper_pos, f32 speed) {
    acch->SetWallHit();
    f32 move = speed * dist;
    pupper_pos->x += move * plane.mNormal.x;
    pupper_pos->z += move * plane.mNormal.z;
    CHECK_FLOAT_CLASS(0xd0, pupper_pos->x);
    CHECK_FLOAT_CLASS(0xd1, pupper_pos->z);
}

/* 800A5E64-800A6DF8       .text RwgWallCorrect__4dBgWFP9dBgS_AcchUs */
void dBgW::RwgWallCorrect(dBgS_Acch*, u16) {
    /* Nonmatching */
}

/* 800A6DF8-800A7004       .text WallCorrectRp__4dBgWFP9dBgS_Acchi */
void dBgW::WallCorrectRp(dBgS_Acch*, int) {
    /* Nonmatching */
}

/* 800A7004-800A7120       .text WallCorrectGrpRp__4dBgWFP9dBgS_Acchii */
bool dBgW::WallCorrectGrpRp(dBgS_Acch*, int, int) {
    /* Nonmatching */
}

/* 800A7120-800A72E0       .text RwgRoofChk__4dBgWFUsP12dBgS_RoofChk */
void dBgW::RwgRoofChk(u16, dBgS_RoofChk*) {
    /* Nonmatching */
}

/* 800A72E0-800A7514       .text RoofChkRp__4dBgWFP12dBgS_RoofChki */
void dBgW::RoofChkRp(dBgS_RoofChk*, int) {
    /* Nonmatching */
}

/* 800A7514-800A767C       .text RoofChkGrpRp__4dBgWFP12dBgS_RoofChkii */
bool dBgW::RoofChkGrpRp(dBgS_RoofChk*, int, int) {
    /* Nonmatching */
}

/* 800A767C-800A783C       .text RwgSplGrpChk__4dBgWFUsP14dBgS_SplGrpChk */
void dBgW::RwgSplGrpChk(u16, dBgS_SplGrpChk*) {
    /* Nonmatching */
}

/* 800A783C-800A7A74       .text SplGrpChkRp__4dBgWFP14dBgS_SplGrpChki */
void dBgW::SplGrpChkRp(dBgS_SplGrpChk*, int) {
    /* Nonmatching */
}

/* 800A7A74-800A7BDC       .text SplGrpChkGrpRp__4dBgWFP14dBgS_SplGrpChkii */
bool dBgW::SplGrpChkGrpRp(dBgS_SplGrpChk*, int, int) {
    /* Nonmatching */
}

/* 800A7BDC-800A7DCC       .text RwgSphChk__4dBgWFUsP11dBgS_SphChkPv */
void dBgW::RwgSphChk(u16, dBgS_SphChk*, void*) {
    /* Nonmatching */
}

/* 800A7DCC-800A8038       .text SphChkRp__4dBgWFP11dBgS_SphChkPvi */
void dBgW::SphChkRp(dBgS_SphChk*, void*, int) {
    /* Nonmatching */
}

/* 800A8038-800A8158       .text SphChkGrpRp__4dBgWFP11dBgS_SphChkPvii */
bool dBgW::SphChkGrpRp(dBgS_SphChk*, void*, int, int) {
    /* Nonmatching */
}

/* 800A8158-800A819C       .text positionWallCrrPos__4dBgWFR8cM3dGTriP11dBgS_CrrPosP4cXyzff */
void dBgW::positionWallCrrPos(cM3dGTri&, dBgS_CrrPos*, cXyz*, f32, f32) {
    /* Nonmatching */
}

/* 800A819C-800A8964       .text RwgWallCrrPos__4dBgWFUsP11dBgS_CrrPos */
bool dBgW::RwgWallCrrPos(u16, dBgS_CrrPos*) {
    /* Nonmatching */
}

/* 800A8964-800A8B70       .text WallCrrPosRp__4dBgWFP11dBgS_CrrPosi */
bool dBgW::WallCrrPosRp(dBgS_CrrPos* crr, int i) {
    cBgW_NodeTree* node = &pm_node_tree[i];
    if (!node->Cross(crr->GetCylP()))
        return false;

    bool ret = false;
    cBgD_Tree_t* tree = &pm_bgd->m_tree_tbl[i];
    if (tree->mFlag & 1) {
        if (pm_blk[tree->mBlock].wall != 0xFFFF && RwgWallCrrPos(pm_blk[tree->mBlock].wall, crr))
            ret = true;
        if (pm_blk[tree->mBlock].roof != 0xFFFF && RwgWallCrrPos(pm_blk[tree->mBlock].roof, crr))
            ret = true;
        return ret;
    } else {
        if (tree->mChild[0] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[0]))
            ret = true;
        if (tree->mChild[1] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[1]))
            ret = true;
        if (tree->mChild[2] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[2]))
            ret = true;
        if (tree->mChild[3] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[3]))
            ret = true;
        if (tree->mChild[4] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[4]))
            ret = true;
        if (tree->mChild[5] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[5]))
            ret = true;
        if (tree->mChild[6] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[6]))
            ret = true;
        if (tree->mChild[7] != 0xFFFF && WallCrrPosRp(crr, tree->mChild[7]))
            ret = true;
        return ret;
    }
}

/* 800A8B70-800A8C8C       .text WallCrrPosGrpRp__4dBgWFP11dBgS_CrrPosii */
bool dBgW::WallCrrPosGrpRp(dBgS_CrrPos* crr, int grp_id, int depth) {
    if (ChkGrpThrough(grp_id, crr->GetGrpPassChk(), depth))
        return false;

    cBgW_GrpElm* grp = &pm_grp[grp_id];

    if (!grp->aab.Cross(crr->GetCylP()))
        return false;

    bool ret = false;
    u32 tree_idx = pm_bgd->m_g_tbl[grp_id].m_tree_idx;
    if (tree_idx != 0xFFFF && WallCrrPosRp(crr, tree_idx))
        ret = true;

    s32 child_idx = pm_bgd->m_g_tbl[grp_id].m_first_child;
    while (true) {
        if (child_idx == 0xFFFF)
            break;
        if (WallCrrPosGrpRp(crr, child_idx, depth + 1))
            ret = true;
        child_idx = pm_bgd->m_g_tbl[child_idx].m_next_sibling;
    }

    return ret;
}

/* 800A8C8C-800A8CB4       .text WallCrrPos__4dBgWFP11dBgS_CrrPos */
bool dBgW::WallCrrPos(dBgS_CrrPos* crr) {
    return WallCrrPosGrpRp(crr, m_rootGrpIdx, 1);
}

/* 800A8CB4-800A8CF0       .text CrrPos__4dBgWFR13cBgS_PolyInfoPvbP4cXyzP5csXyzP5csXyz */
void dBgW::CrrPos(cBgS_PolyInfo& poly, void* user, bool accept, cXyz* pos, csXyz* angle, csXyz* shape_angle) {
    if (m_crr_func != NULL)
        m_crr_func(this, user, poly, accept, pos, angle, shape_angle);
}

/* 800A8CF0-800A8D2C       .text TransPos__4dBgWFR13cBgS_PolyInfoPvbP4cXyzP5csXyzP5csXyz */
void dBgW::TransPos(cBgS_PolyInfo& poly, void* user, bool accept, cXyz* pos, csXyz* angle, csXyz* shape_angle) {
    if (m_crr_func != NULL)
        m_crr_func(this, user, poly, accept, pos, angle, shape_angle);
}

/* 800A8D2C-800A9474       .text ChkPolyThrough__4dBgWFiP16cBgS_PolyPassChk */
bool dBgW::ChkPolyThrough(int poly_index, cBgS_PolyPassChk* chk) {
    /* Nonmatching */
    if (chk == NULL)
        return false;
    if (chk->mbObjThrough && GetPolyInf3(GetPolyInfId(poly_index)) & 0x02)
        return true;
    if (chk->mbCamThrough && GetPolyInf3(GetPolyInfId(poly_index)) & 0x01)
        return true;
    if (chk->mbLinkThrough && GetPolyInf3(GetPolyInfId(poly_index)) & 0x04)
        return true;
    if (chk->mbArrowThrough && GetPolyInf3(GetPolyInfId(poly_index)) & 0x08)
        return true;
    if (chk->mbBombThrough && GetPolyInf3(GetPolyInfId(poly_index)) & 0x20)
        return true;
    if (chk->mbBoomerangThrough && GetPolyInf3(GetPolyInfId(poly_index)) & 0x40)
        return true;
    if (chk->mbRopeThrough && GetPolyInf3(GetPolyInfId(poly_index)) & 0x80)
        return true;
    return false;
}

/* 800A9474-800A9684       .text ChkShdwDrawThrough__4dBgWFiP16cBgS_PolyPassChk */
bool dBgW::ChkShdwDrawThrough(int poly_index, cBgS_PolyPassChk* chk) {
    /* Nonmatching */
    if ((GetPolyInf0(GetPolyInfId(poly_index)) >> 27) & 1)
        return true;

    if (GetPolyInf3(GetPolyInfId(poly_index)) & 0x08)
        return true;

    return false;
}

/* 800A9684-800A974C       .text ChkGrpThrough__4dBgWFiP15cBgS_GrpPassChki */
bool dBgW::ChkGrpThrough(int grp_id, cBgS_GrpPassChk* _chk, int depth) {
    dBgS_GrpPassChk* chk = (dBgS_GrpPassChk*)_chk;
    if (depth != 2 || chk == NULL)
        return false;

    int info = pm_bgd->m_g_tbl[grp_id].m_info;
    if (!(info & 0x80700) && chk->MaskNormalGrp())
        return false;
    if ((info & 0x00100) && chk->MaskWaterGrp())
        return false;
    if ((info & 0x00200) && chk->MaskYoganGrp())
        return false;
    if ((info & 0x00400) && chk->MaskDokuGrp())
        return false;
    if ((info & 0x80000) && chk->MaskLightGrp())
        return false;
    return true;
}

/* 800A974C-800A97E4       .text ChangeAttributeCodeByPathPntNo__4dBgWFiUl */
void dBgW::ChangeAttributeCodeByPathPntNo(int, u32) {
    /* Nonmatching */
}

/* 800A97E4-800A986C       .text dBgW_NewSet__FP6cBgD_tUlPA3_A4_f */
dBgW* dBgW_NewSet(cBgD_t*, u32, f32(*)[3][4]) {
    /* Nonmatching */
}
