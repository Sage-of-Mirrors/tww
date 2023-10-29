//
// Generated by dtk
// Translation Unit: c_bg_s.cpp
//

#include "SSystem/SComponent/c_bg_s.h"
#include "SSystem/SComponent/c_bg_w.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "dolphin/types.h"

s32 l_SetCounter = 0;

/* 80246440-8024645C       .text Init__11cBgS_ChkElmFv */
void cBgS_ChkElm::Init() {
    m_bgw_base_ptr = NULL;
    m_flags = 0;
    m_actor_ptr = NULL;
    m_actor_id = -1;
}

/* 8024645C-80246478       .text Regist2__11cBgS_ChkElmFP4cBgWUiPv */
void cBgS_ChkElm::Regist2(cBgW* bgw, unsigned int pid, void* actor) {
    m_flags |= 1;
    m_bgw_base_ptr = bgw;
    m_actor_id = pid;
    m_actor_ptr = (fopAc_ac_c*)actor;
}

/* 80246478-8024649C       .text Release__11cBgS_ChkElmFv */
void cBgS_ChkElm::Release() {
    m_flags &= ~1;
    m_bgw_base_ptr = NULL;
    m_actor_id = -1;
    m_actor_ptr = NULL;
}

/* 8024649C-80246600       .text Regist__4cBgSFP4cBgWUiPv */
bool cBgS::Regist(cBgW* bgw, unsigned int pid, void* actor) {
    if (bgw == NULL)
        return true;

    if (bgw->ChkUsed())
        return true;

    if (bgw->ChkMemoryError())
        return true;

    s32 i = l_SetCounter;
    JUT_ASSERT(0x97, 0 <= i && i < 256);

    while (true) {
        if (!m_chk_element[i].ChkUsed()) {
            m_chk_element[i].Regist2(bgw, pid, actor);
            bgw->SetId(i);
            l_SetCounter = i + 1;
            if (l_SetCounter >= 256)
                l_SetCounter = 0;
            return false;
        }

        i++;
        if (i >= 256)
            i = 0;
        if (l_SetCounter == i)
            break;
    }

    bgw->SetId(256);
    return true;
}

/* 80246600-8024669C       .text Release__4cBgSFP4cBgW */
int cBgS::Release(cBgW* bgw) {
    if (bgw == NULL)
        return true;

    if (bgw->ChkUsed() && bgw->GetId() >= 0 && bgw->GetId() < 0x100 && m_chk_element[bgw->GetId()].ChkUsed()) {
        m_chk_element[bgw->GetId()].Release();
        bgw->SetId(256);
        goto done;
    }

    return true;

done:
    return false;
}

/* 8024669C-802466F0       .text Ct__4cBgSFv */
void cBgS::Ct() {
    l_SetCounter = 0;
    for (s32 i = 0; i < (s32)ARRAY_SIZE(m_chk_element); i++)
        m_chk_element[i].Init();
}

/* 802466F0-8024676C       .text Dt__4cBgSFv */
void cBgS::Dt() {
    for (s32 i = 0; i < (s32)ARRAY_SIZE(m_chk_element); i++)
        if (m_chk_element[i].ChkUsed())
            m_chk_element[i].Release();
    for (s32 i = 0; i < (s32)ARRAY_SIZE(m_chk_element); i++)
        m_chk_element[i].Init();
}

/* 8024676C-802468E4       .text LineCross__4cBgSFP11cBgS_LinChk */
bool cBgS::LineCross(cBgS_LinChk*) {
    /* Nonmatching */
}

/* 802468E4-80246A14       .text GroundCross__4cBgSFP11cBgS_GndChk */
f32 cBgS::GroundCross(cBgS_GndChk*) {
    /* Nonmatching */
}

/* 80246A14-80246C98       .text ConvDzb__4cBgSFPv */
void* cBgS::ConvDzb(void* work) {
    cBgD_t * pbgd = (cBgD_t *)work;
    if (pbgd->flag & 0x80000000)
        return;

    pbgd->flag |= 0x80000000;
    JUT_ASSERT(0x214, ((int)pbgd->m_v_tbl % 4) == 0);
    JUT_ASSERT(0x215, ((int)pbgd->m_t_tbl % 2) == 0);
    JUT_ASSERT(0x216, ((int)pbgd->m_b_tbl % 2) == 0);
    JUT_ASSERT(0x217, ((int)pbgd->m_tree_tbl % 2) == 0);
    JUT_ASSERT(0x218, ((int)pbgd->m_g_tbl % 4) == 0);
    JUT_ASSERT(0x219, ((int)pbgd->m_ti_tbl % 4) == 0);

    if (pbgd->m_v_tbl != NULL)
        pbgd->m_v_tbl = (cBgD_Vtx_t*)((u32)pbgd->m_v_tbl + (u32)pbgd);

    pbgd->m_t_tbl = (cBgD_Tri_t*)((u32)pbgd->m_t_tbl + (u32)pbgd);
    pbgd->m_b_tbl = (cBgD_Blk_t*)((u32)pbgd->m_b_tbl + (u32)pbgd);
    pbgd->m_tree_tbl = (void*)((u32)pbgd->m_tree_tbl + (u32)pbgd);
    pbgd->m_g_tbl = (cBgD_Grp_t*)((u32)pbgd->m_g_tbl + (u32)pbgd);
    pbgd->m_ti_tbl = (void*)((u32)pbgd->m_ti_tbl + (u32)pbgd);

    for (s32 i = 0; i < pbgd->m_g_num; i++) {
        pbgd->m_g_tbl[i].m_name = (char*)((u32)pbgd + (u32)pbgd->m_g_tbl[i].m_name);
    }
    
    return pbgd;
}

/* 80246C98-80246D24       .text GetActorPointer__4cBgSCFi */
fopAc_ac_c* cBgS::GetActorPointer(int actor_index) const {
    JUT_ASSERT(0x237, 0 <= actor_index && actor_index < 256);
    return m_chk_element[actor_index].m_actor_ptr;
}

/* 80246D24-80246D5C       .text GetBgWPointer__4cBgSCFR13cBgS_PolyInfo */
cBgW* cBgS::GetBgWPointer(cBgS_PolyInfo& poly) const {
    s32 id = poly.GetBgIndex();
    if (!(0 <= id && id < 256) || !m_chk_element[id].ChkUsed())
        return NULL;
    return m_chk_element[id].m_bgw_base_ptr;
}

/* 80246D5C-80246DF8       .text ChkPolySafe__4cBgSFR13cBgS_PolyInfo */
bool cBgS::ChkPolySafe(cBgS_PolyInfo& poly) {
    if (!poly.ChkSetInfo())
        return false;

    int id = poly.GetBgIndex();
    if (!(0 <= id && id < 256))
        return false;

    if (!m_chk_element[id].ChkUsed())
        return false;

    return poly.ChkSafe(m_chk_element[id].m_bgw_base_ptr, m_chk_element[id].m_actor_id);
}

/* 80246DF8-80246F10       .text GetTriGrp__4cBgSCFii */
s32 cBgS::GetTriGrp(int bg_index, int poly_index) const {
    JUT_ASSERT(0x278, 0 <= bg_index && bg_index < 256);

    if (!m_chk_element[bg_index].ChkUsed())
        return -1;

    return m_chk_element[bg_index].m_bgw_base_ptr->GetTriGrp(poly_index);
}

/* 80246F10-80246FE4       .text GetGrpToRoomId__4cBgSCFii */
s32 cBgS::GetGrpToRoomId(int bg_index, int grp_id) const {
    JUT_ASSERT(0x289, 0 <= bg_index && bg_index < 256);

    if (!m_chk_element[bg_index].ChkUsed())
        return 0xFFFF;
    if (grp_id == 0xFFFF)
        return 0xFFFF;
    return m_chk_element[bg_index].m_bgw_base_ptr->GetGrpToRoomIndex(grp_id);
}

/* 80246FE4-802470B8       .text GetTriPla__4cBgSCFii */
cM3dGPla* cBgS::GetTriPla(int bg_index, int poly_index) const {
    if (!(0 <= bg_index && bg_index < 256))
        return NULL;

    if (!m_chk_element[bg_index].ChkUsed())
        return NULL;

    return m_chk_element[bg_index].m_bgw_base_ptr->GetTriPla(poly_index);
}

/* 802470B8-80247178       .text GetTriPnt__4cBgSCFR13cBgS_PolyInfoP4cXyzP4cXyzP4cXyz */
bool cBgS::GetTriPnt(cBgS_PolyInfo& poly, cXyz* p0, cXyz* p1, cXyz* p2) const {
    s32 id = poly.GetBgIndex();
    JUT_ASSERT(0x2f6, 0 <= id && id < 256);
    if (m_chk_element[id].ChkUsed())
        m_chk_element[id].m_bgw_base_ptr->GetTriPnt(poly.GetPolyIndex(), p0, p1, p2);
}

/* 80247178-8024717C       .text Move__4cBgSFv */
void cBgS::Move() {
}

/* 8024717C-802471E8       .text ShdwDraw__4cBgSFP13cBgS_ShdwDraw */
void cBgS::ShdwDraw(cBgS_ShdwDraw* shdw) {
    for (s32 i = 0; i < (s32)ARRAY_SIZE(m_chk_element); i++)
        if (m_chk_element[i].ChkUsed())
            m_chk_element[i].m_bgw_base_ptr->ShdwDrawGrpRp(shdw, m_chk_element[i].m_bgw_base_ptr->m_rootGrpIdx);
}

/* 802471E8-80247304       .text GetGrpInf__4cBgSCFR13cBgS_PolyInfoi */
s32 cBgS::GetGrpInf(cBgS_PolyInfo& poly, int grp_id) const {
    s32 bg_index = poly.GetBgIndex();
    JUT_ASSERT(0x37d, 0 <= bg_index && bg_index < 256);

    if (!m_chk_element[bg_index].ChkUsed())
        return -1;

    return m_chk_element[bg_index].m_bgw_base_ptr->GetGrpInf(grp_id);
}
