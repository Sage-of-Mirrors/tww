//
// Generated by dtk
// Translation Unit: d_a_kanban.cpp
//

#include "JSystem/JKernel/JKRHeap.h"
#include "f_op/f_op_actor_mng.h"
#include "d/d_com_inf_game.h"
#include "d/d_kankyo.h"
#include "d/d_procname.h"
#include "d/d_bg_s_acch.h"
#include "d/d_cc_d.h"
#include "d/d_particle.h"
#include "m_Do/m_Do_hostIO.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

#include "dolphin/types.h"


class kanban_class : public fopAc_ac_c {
public:
    bool mb0290;

    int m0294;
    bool m0298;
    u8 m0299;
    bool m029A;
    bool m029B;
    bool m029C;

    float m02A0;
    float m02A4;
    float m02A8;

    csXyz m02AC;
    short m02B2;
    short m02B4;

    short m02B6;

    short m02BA;
    short m02BC;
    short m02BE;
    short m02C0;
    short m02C2;
    short m02C4;
    short m02C6;

    s32 mParentProcID;

    cXyz m02CC;
    cXyz m02D8;
    cXyz m02E4;

    short m02F0;
    short m02F2;
    short m02F4;

    cXyz m02F8;
    cXyz m0304;

    dBgS_AcchCir mAcchCir;
    dBgS_Acch mAcch;

    dPa_rippleEcallBack mRippleCB;
    cXyz m0528;

    int m0534; // TODO: Does this do anything?
    int m0538; // TODO: Does this do anything?

    request_of_phase_process_class mPhs;
    J3DModel* mModels[10];

    int m056C; // TODO: Does this do anything?

    int m0570;

    dCcD_Stts mColStatus;
    dCcD_Cyl mColCylinder;
};

class daKanban_HIO_c : public mDoHIO_entry_c {
public:
    daKanban_HIO_c();
    virtual ~daKanban_HIO_c() { };

    float m0004;
    short m0008;
    short m000A;
    float m000C;
};

static u32 l_msgId = 0xFFFFFFFF;

/* 000000EC-0000012C       .text __ct__14daKanban_HIO_cFv */
daKanban_HIO_c::daKanban_HIO_c() {
    m0004 = 0.0f;
    m0008 = 0;
    m000A = 0;
    m000C = 0.8f;
}

/* 00000174-0000047C       .text daKanban_Draw__FP12kanban_class */
s32 daKanban_Draw(kanban_class*) {
    /* Nonmatching */
}

/* 0000047C-0000055C       .text shibuki_set__FP12kanban_class4cXyzf */
void shibuki_set(kanban_class*, cXyz, float) {
    /* Nonmatching */
}

/* 0000055C-00000884       .text sea_water_check__FP12kanban_class */
void sea_water_check(kanban_class*) {
    /* Nonmatching */
}

/* 00000884-00000940       .text bom_search_sub__FPvPv */
void bom_search_sub(void*, void*) {
    /* Nonmatching */
}

/* 00000940-00000B84       .text shock_damage_check__FP12kanban_class */
void shock_damage_check(kanban_class*) {
    /* Nonmatching */
}

/* 00000B84-00000E6C       .text cut_point_check__FP12kanban_class */
void cut_point_check(kanban_class*) {
    /* Nonmatching */
}

/* 00000E6C-000012B8       .text mother_move__FP12kanban_class */
void mother_move(kanban_class*) {
    /* Nonmatching */
}

/* 000012B8-0000134C       .text mother_water_swim__FP12kanban_class */
void mother_water_swim(kanban_class*) {
    /* Nonmatching */
}

/* 0000134C-00001580       .text ret_keisan_move__FP12kanban_class */
void ret_keisan_move(kanban_class*) {
    /* Nonmatching */
}

/* 00001580-00001770       .text mother_return_move__FP12kanban_class */
void mother_return_move(kanban_class*) {
    /* Nonmatching */
}

/* 00001770-00001B50       .text parts_move__FP12kanban_class */
void parts_move(kanban_class*) {
    /* Nonmatching */
}

/* 00001B50-00001D58       .text chield_parts_move__FP12kanban_class */
void chield_parts_move(kanban_class*) {
    /* Nonmatching */
}

/* 00001D58-00001DEC       .text chield_water_swim__FP12kanban_class */
void chield_water_swim(kanban_class*) {
    /* Nonmatching */
}

/* 00001DEC-000022A8       .text daKanban_Execute__FP12kanban_class */
s32 daKanban_Execute(kanban_class*) {
    /* Nonmatching */
}

/* 000022A8-000022B0       .text daKanban_IsDelete__FP12kanban_class */
s32 daKanban_IsDelete(kanban_class*) {
    return TRUE;
}

/* 000022B0-00002300       .text daKanban_Delete__FP12kanban_class */
s32 daKanban_Delete(kanban_class* i_this) {
    /* Nonmatching */
    dComIfG_resDelete(&i_this->mPhs, "Kanban");
    i_this->mRippleCB.end();

    l_msgId = 0xFFFFFFFF;
    return TRUE;
}

/* 00002300-0000249C       .text setTex__FP12J3DModelData */
void setTex(J3DModelData*) {
    /* Nonmatching */
}

/* 0000249C-00002614       .text useHeapInit__FP10fopAc_ac_c */
void useHeapInit(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 00002614-00002A5C       .text daKanban_Create__FP10fopAc_ac_c */
s32 daKanban_Create(fopAc_ac_c* i_this) {
    /* Nonmatching */
    kanban_class* kan = static_cast<kanban_class*>(i_this);

    fopAcM_SetupActor(kan, kanban_class);
}

static actor_method_class l_daKanban_Method = {
    (process_method_func)daKanban_Create,
    (process_method_func)daKanban_Delete,
    (process_method_func)daKanban_Execute,
    (process_method_func)daKanban_IsDelete,
    (process_method_func)daKanban_Draw,
};

extern actor_process_profile_definition g_profile_KANBAN = {
    fpcLy_CURRENT_e,
    3,
    fpcPi_CURRENT_e,
    PROC_KANBAN,
    &g_fpcLf_Method.mBase,
    sizeof(kanban_class),
    0,
    0,
    &g_fopAc_Method.base,
    0x06E0,
    &l_daKanban_Method,
    0x00040100,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};

// /* 00002A5C-00002B28       .text __dt__8dCcD_CylFv */
// dCcD_Cyl::~dCcD_Cyl() {
//     /* Nonmatching */
// }

// /* 00002B28-00002B70       .text __dt__8cM3dGCylFv */
// cM3dGCyl::~cM3dGCyl() {
//     /* Nonmatching */
// }

// /* 00002B70-00002BCC       .text __dt__14cCcD_ShapeAttrFv */
// cCcD_ShapeAttr::~cCcD_ShapeAttr() {
//     /* Nonmatching */
// }

// /* 00002BCC-00002C14       .text __dt__8cM3dGAabFv */
// cM3dGAab::~cM3dGAab() {
//     /* Nonmatching */
// }

// /* 00002C14-00002C70       .text __dt__18dPa_levelEcallBackFv */
// dPa_levelEcallBack::~dPa_levelEcallBack() {
//     /* Nonmatching */
// }

// /* 00002C70-00002CB8       .text __dt__34JPACallBackBase<P14JPABaseEmitter>Fv */
// JPACallBackBase<JPABaseEmitter*>::~JPACallBackBase() {
//     /* Nonmatching */
// }

// /* 00002CB8-00002D28       .text __dt__12dBgS_ObjAcchFv */
// dBgS_ObjAcch::~dBgS_ObjAcch() {
//     /* Nonmatching */
// }

// /* 00002D28-00002D38       .text GetShapeAttr__8dCcD_CylFv */
// void dCcD_Cyl::GetShapeAttr() {
//     /* Nonmatching */
// }

// /* 00002D38-00002D40       .text GetCoCP__12cCcD_CylAttrFv */
// void cCcD_CylAttr::GetCoCP() {
//     /* Nonmatching */
// }

// /* 00002D40-00002D48       .text GetCoCP__12cCcD_CylAttrCFv */
// void cCcD_CylAttr::GetCoCP() const {
//     /* Nonmatching */
// }

// /* 00002D48-00002D50       .text CrossAtTg__12cCcD_CylAttrCFRC12cCcD_AabAttrP4cXyz */
// void cCcD_CylAttr::CrossAtTg(const cCcD_AabAttr&, cXyz*) const {
//     /* Nonmatching */
// }

// /* 00002D50-00002D58       .text CrossAtTg__12cCcD_CylAttrCFRC12cCcD_PntAttrP4cXyz */
// void cCcD_CylAttr::CrossAtTg(const cCcD_PntAttr&, cXyz*) const {
//     /* Nonmatching */
// }

// /* 00002D58-00002D90       .text CrossAtTg__12cCcD_CylAttrCFRC14cCcD_ShapeAttrP4cXyz */
// void cCcD_CylAttr::CrossAtTg(const cCcD_ShapeAttr&, cXyz*) const {
//     /* Nonmatching */
// }

// /* 00002D90-00002D98       .text CrossCo__12cCcD_CylAttrCFRC12cCcD_AabAttrPf */
// void cCcD_CylAttr::CrossCo(const cCcD_AabAttr&, float*) const {
//     /* Nonmatching */
// }

// /* 00002D98-00002DA0       .text CrossCo__12cCcD_CylAttrCFRC12cCcD_TriAttrPf */
// void cCcD_CylAttr::CrossCo(const cCcD_TriAttr&, float*) const {
//     /* Nonmatching */
// }

// /* 00002DA0-00002DA8       .text CrossCo__12cCcD_CylAttrCFRC12cCcD_PntAttrPf */
// void cCcD_CylAttr::CrossCo(const cCcD_PntAttr&, float*) const {
//     /* Nonmatching */
// }

// /* 00002DA8-00002DE0       .text CrossCo__12cCcD_CylAttrCFRC14cCcD_ShapeAttrPf */
// void cCcD_CylAttr::CrossCo(const cCcD_ShapeAttr&, float*) const {
//     /* Nonmatching */
// }

// /* 00002DE0-00002DE4       .text GetGObjInf__12cCcD_GObjInfCFv */
// void cCcD_GObjInf::GetGObjInf() const {
//     /* Nonmatching */
// }

// /* 00002DE4-00002DEC       .text GetShapeAttr__8cCcD_ObjCFv */
// void cCcD_Obj::GetShapeAttr() const {
//     /* Nonmatching */
// }

// /* 00002DEC-00002DF4       .text CrossAtTg__14cCcD_ShapeAttrCFRC14cCcD_ShapeAttrP4cXyz */
// void cCcD_ShapeAttr::CrossAtTg(const cCcD_ShapeAttr&, cXyz*) const {
//     /* Nonmatching */
// }

// /* 00002DF4-00002DFC       .text CrossCo__14cCcD_ShapeAttrCFRC14cCcD_ShapeAttrPf */
// void cCcD_ShapeAttr::CrossCo(const cCcD_ShapeAttr&, float*) const {
//     /* Nonmatching */
// }

// /* 00002DFC-00002E08       .text GetCoCP__14cCcD_ShapeAttrFv */
// void cCcD_ShapeAttr::GetCoCP() {
//     /* Nonmatching */
// }

// /* 00002E08-00002E14       .text GetCoCP__14cCcD_ShapeAttrCFv */
// void cCcD_ShapeAttr::GetCoCP() const {
//     /* Nonmatching */
// }

// /* 00002E14-00002E18       .text draw__34JPACallBackBase<P14JPABaseEmitter>FP14JPABaseEmitter */
// void JPACallBackBase<JPABaseEmitter*>::draw(JPABaseEmitter*) {
//     /* Nonmatching */
// }

// /* 00002E18-00002E1C       .text executeAfter__34JPACallBackBase<P14JPABaseEmitter>FP14JPABaseEmitter */
// void JPACallBackBase<JPABaseEmitter*>::executeAfter(JPABaseEmitter*) {
//     /* Nonmatching */
// }

// /* 00002E1C-00002E20       .text execute__34JPACallBackBase<P14JPABaseEmitter>FP14JPABaseEmitter */
// void JPACallBackBase<JPABaseEmitter*>::execute(JPABaseEmitter*) {
//     /* Nonmatching */
// }

// /* 00002E20-00002E24       .text init__34JPACallBackBase<P14JPABaseEmitter>FP14JPABaseEmitter */
// void JPACallBackBase<JPABaseEmitter*>::init(JPABaseEmitter*) {
//     /* Nonmatching */
// }

// /* 00002E24-00002E80       .text __dt__14daKanban_HIO_cFv */
// daKanban_HIO_c::~daKanban_HIO_c() {
//     /* Nonmatching */
// }

// /* 00002EBC-00002EC4       .text @32@__dt__12dBgS_ObjAcchFv */
// void @32@__dt__12dBgS_ObjAcchFv {
//     /* Nonmatching */
// }

// /* 00002EC4-00002ECC       .text @20@__dt__12dBgS_ObjAcchFv */
// void @20@__dt__12dBgS_ObjAcchFv {
//     /* Nonmatching */
// }

// /* 00002ECC-00002ED4       .text @280@__dt__8dCcD_CylFv */
// void @280@__dt__8dCcD_CylFv {
//     /* Nonmatching */
// }

// /* 00002ED4-00002EDC       .text @248@__dt__8dCcD_CylFv */
// void @248@__dt__8dCcD_CylFv {
//     /* Nonmatching */
// }

// /* 00002EDC-00002EF8       .text getSwordTopPos__9daPy_py_cCFv */
// void daPy_py_c::getSwordTopPos() const {
//     /* Nonmatching */
// }
