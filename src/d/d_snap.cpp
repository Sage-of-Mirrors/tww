//
// Generated by dtk
// Translation Unit: d_snap.cpp
//

#include "d/d_snap.h"
#include "dolphin/types.h"

void (dSnap_packet::*dSnap_packet::m_judge_tbl[])() = {
    NULL,
    &dSnap_packet::JudgePost,
    &dSnap_packet::JudgeBikutsuki,
    &dSnap_packet::JudgeCoupleLook,
    &dSnap_packet::JudgeGF,
    &dSnap_packet::JudgeGenzo,
    &dSnap_packet::JudgeObasan4,
    &dSnap_packet::JudgeGene,
    &dSnap_packet::JudgeGene,
    &dSnap_packet::JudgeGene,
    &dSnap_packet::JudgeTestM,
};
dSnap_packet l_snap;

/* 800CCF6C-800CCFE4       .text dSnap_PhotoIndex2TableIndex__Fi */
void dSnap_PhotoIndex2TableIndex(int) {
    /* Nonmatching */
}

/* 800CCFE4-800CD00C       .text dSnap_GetFigRoomId__Fi */
void dSnap_GetFigRoomId(int) {
    /* Nonmatching */
}

/* 800CD00C-800CD068       .text __ct__9dSnap_ObjFv */
dSnap_Obj::dSnap_Obj() {
    mBsPcId = -1;
    field_0x18 = 0;
    field_0x19 = 4;
    field_0x1a = -1;
    field_0x1b = 0;
    field_0x1c = 0x7fff;
    field_0x1e = 0;
    field_0x20 = 0;
    field_0x24 = 0.0f;
    field_0x28 = 0;
    field_0x2a = 0;
    field_0x2c = 0;
    field_0x2e = 0;
}

/* 800CD068-800CD6D0       .text CalcArea2D__9dSnap_ObjFv */
void dSnap_Obj::CalcArea2D() {
    /* Nonmatching */
}

/* 800CD6D0-800CDAF8       .text draw__9dSnap_ObjFv */
void dSnap_Obj::draw() {
    /* Nonmatching */
}

/* 800CDAF8-800CDB2C       .text SetGeo__9dSnap_ObjFRC3Vecffs */
void dSnap_Obj::SetGeo(const Vec&, f32, f32, s16) {
    /* Nonmatching */
}

/* 800CDB2C-800CDB68       .text SetGeoSph__9dSnap_ObjFRC3Vecf */
void dSnap_Obj::SetGeoSph(const Vec&, f32) {
    /* Nonmatching */
}

/* 800CDB68-800CDB94       .text SetInf__9dSnap_ObjFUcPC10fopAc_ac_cUcUcs */
void dSnap_Obj::SetInf(u8, const fopAc_ac_c*, u8, u8, s16) {
    /* Nonmatching */
}

/* 800CDB94-800CDBB0       .text SetAreaClear__9dSnap_ObjFv */
void dSnap_Obj::SetAreaClear() {
    /* Nonmatching */
}

/* 800CDBB0-800CDC04       .text SetArea__9dSnap_ObjFss */
void dSnap_Obj::SetArea(s16, s16) {
    /* Nonmatching */
}

/* 800CDC04-800CDC18       .text ChkPhoto__9dSnap_ObjFi */
void dSnap_Obj::ChkPhoto(int) {
    /* Nonmatching */
}

/* 800CDC18-800CDC40       .text ChkSuccess__9dSnap_ObjFlf */
void dSnap_Obj::ChkSuccess(s32, f32) {
    /* Nonmatching */
}

/* 800CDC40-800CDCD8       .text ChkCamCull__9dSnap_ObjCFv */
void dSnap_Obj::ChkCamCull() const {
    /* Nonmatching */
}

/* 800CDCD8-800CDCDC       .text Init__18dSnap_RegistObjElmFv */
void dSnap_RegistObjElm::Init() {}

/* 800CDCDC-800CDD70       .text Regist__18dSnap_RegistObjElmFRC9dSnap_Obj */
void dSnap_RegistObjElm::Regist(const dSnap_Obj&) {
    /* Nonmatching */
}

/* 800CDD70-800CDD84       .text Create__12dSnap_packetFv */
void dSnap_packet::Create() {
    /* Nonmatching */
}

/* 800CDD84-800CDD94       .text ReleaseShutter__12dSnap_packetFv */
void dSnap_packet::ReleaseShutter() {
    /* Nonmatching */
}

/* 800CDD94-800CDDA0       .text ChkReleaseShutter__12dSnap_packetFv */
void dSnap_packet::ChkReleaseShutter() {
    /* Nonmatching */
}

/* 800CDDA0-800CDE20       .text Execute__12dSnap_packetFv */
void dSnap_packet::Execute() {
    /* Nonmatching */
}

/* 800CDE20-800CDF98       .text Regist__12dSnap_packetFRC9dSnap_Obj */
void dSnap_packet::Regist(const dSnap_Obj&) {
    /* Nonmatching */
}

/* 800CDF98-800CE118       .text dSnap_MatDl__Fv */
void dSnap_MatDl() {
    /* Nonmatching */
}

/* 800CE118-800CE298       .text dSnap_AlphaClearDL__Fv */
void dSnap_AlphaClearDL() {
    /* Nonmatching */
}

/* 800CE298-800CE374       .text draw__12dSnap_packetFv */
void dSnap_packet::draw() {
    /* Nonmatching */
}

/* 800CE374-800CE4A8       .text ClearAlphaBuffer__12dSnap_packetFv */
void dSnap_packet::ClearAlphaBuffer() {
    /* Nonmatching */
}

/* 800CE4A8-800CE610       .text Judge__12dSnap_packetFv */
void dSnap_packet::Judge() {
    /* Nonmatching */
}

/* 800CE610-800CE6A4       .text FindPhoto__12dSnap_packetFii */
void dSnap_packet::FindPhoto(int, int) {
    /* Nonmatching */
}

/* 800CE6A4-800CE70C       .text JudgePost__12dSnap_packetFv */
void dSnap_packet::JudgePost() {
    /* Nonmatching */
}

/* 800CE70C-800CE77C       .text JudgeBikutsuki__12dSnap_packetFv */
void dSnap_packet::JudgeBikutsuki() {
    /* Nonmatching */
}

/* 800CE77C-800CE83C       .text JudgeCoupleLook__12dSnap_packetFv */
void dSnap_packet::JudgeCoupleLook() {
    /* Nonmatching */
}

/* 800CE83C-800CE8AC       .text JudgeGF__12dSnap_packetFv */
void dSnap_packet::JudgeGF() {
    /* Nonmatching */
}

/* 800CE8AC-800CE96C       .text JudgeGenzo__12dSnap_packetFv */
void dSnap_packet::JudgeGenzo() {
    /* Nonmatching */
}

/* 800CE96C-800CEA08       .text JudgeObasan4__12dSnap_packetFv */
void dSnap_packet::JudgeObasan4() {
    /* Nonmatching */
}

/* 800CEA08-800CEA10       .text JudgeTestM__12dSnap_packetFv */
void dSnap_packet::JudgeTestM() {
    /* Nonmatching */
}

/* 800CEA10-800CEA80       .text JudgeGene__12dSnap_packetFv */
void dSnap_packet::JudgeGene() {
    /* Nonmatching */
}

/* 800CEA80-800CEB80       .text JudgeFigure__12dSnap_packetFi */
void dSnap_packet::JudgeFigure(int) {
    /* Nonmatching */
}

/* 800CEB80-800CED0C       .text SetResult__12dSnap_packetFv */
void dSnap_packet::SetResult() {
    /* Nonmatching */
}

/* 800CED0C-800CED34       .text dSnap_Create__Fv */
void dSnap_Create() {
    /* Nonmatching */
}

/* 800CED34-800CED5C       .text dSnap_ReleaseShutter__Fv */
void dSnap_ReleaseShutter() {
    /* Nonmatching */
}

/* 800CED5C-800CED84       .text dSnap_Execute__Fv */
void dSnap_Execute() {
    /* Nonmatching */
}

/* 800CED84-800CED94       .text dSnap_GetResult__Fv */
void dSnap_GetResult() {
    /* Nonmatching */
}

/* 800CED94-800CEDA4       .text dSnap_GetResultDetail__Fv */
void dSnap_GetResultDetail() {
    /* Nonmatching */
}

/* 800CEDA4-800CEDD0       .text dSnap_RegistSnapObj__FR9dSnap_Obj */
void dSnap_RegistSnapObj(dSnap_Obj&) {
    /* Nonmatching */
}

/* 800CEDD0-800CEDF8       .text dSnap_RegistFig__FUcP10fopAc_ac_cfff */
void dSnap_RegistFig(u8, fopAc_ac_c*, f32, f32, f32) {
    /* Nonmatching */
}

/* 800CEDF8-800CEFD4       .text dSnap_RegistFig__FUcP10fopAc_ac_cRC3Vecsfff */
void dSnap_RegistFig(u8, fopAc_ac_c*, const Vec&, s16, f32, f32, f32) {
    /* Nonmatching */
}

/* 800CEFD4-800CF054       .text dSnap_DebugDraw__Fv */
void dSnap_DebugDraw() {
    /* Nonmatching */
}

/* 800CF054-800CF058       .text dSnap_Delete__Fv */
void dSnap_Delete() {}

/* 800CF058-800CF0DC       .text __dt__12dSnap_packetFv */
dSnap_packet::~dSnap_packet() {}

/* 800CF0DC-800CF138       .text __dt__18dSnap_RegistObjElmFv */
dSnap_RegistObjElm::~dSnap_RegistObjElm() {}

/* 800CF2E0-800CF31C       .text __ct__18dSnap_RegistObjElmFv */
dSnap_RegistObjElm::dSnap_RegistObjElm() {}
