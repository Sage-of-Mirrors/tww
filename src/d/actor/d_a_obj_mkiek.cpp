//
// Generated by dtk
// Translation Unit: d_a_obj_mkiek.cpp
//

#include "d/actor/d_a_obj_mkiek.h"
#include "d/d_procname.h"

/* 00000078-00000240       .text CreateHeap__Q210daObjMkiek5Act_cFv */
BOOL daObjMkiek::Act_c::CreateHeap() {
    /* Nonmatching */
}

/* 00000240-00000314       .text Create__Q210daObjMkiek5Act_cFv */
BOOL daObjMkiek::Act_c::Create() {
    /* Nonmatching */
}

/* 00000314-000004F8       .text Mthd_Create__Q210daObjMkiek5Act_cFv */
cPhs_State daObjMkiek::Act_c::Mthd_Create() {
    /* Nonmatching */
}

/* 00000754-0000075C       .text Delete__Q210daObjMkiek5Act_cFv */
BOOL daObjMkiek::Act_c::Delete() {
    /* Nonmatching */
}

/* 0000075C-000007B4       .text Mthd_Delete__Q210daObjMkiek5Act_cFv */
BOOL daObjMkiek::Act_c::Mthd_Delete() {
    /* Nonmatching */
}

/* 000007B4-00000848       .text set_mtx__Q210daObjMkiek5Act_cFv */
void daObjMkiek::Act_c::set_mtx() {
    /* Nonmatching */
}

/* 00000848-000008A0       .text init_mtx__Q210daObjMkiek5Act_cFv */
void daObjMkiek::Act_c::init_mtx() {
    /* Nonmatching */
}

/* 000008A0-00000940       .text check__Q210daObjMkiek5Act_cFv */
void daObjMkiek::Act_c::check() {
    /* Nonmatching */
}

/* 00000940-00000B28       .text demo_wait__Q210daObjMkiek5Act_cFv */
void daObjMkiek::Act_c::demo_wait() {
    /* Nonmatching */
}

/* 00000B28-00000C1C       .text demo__Q210daObjMkiek5Act_cFv */
void daObjMkiek::Act_c::demo() {
    /* Nonmatching */
}

/* 00000C1C-00000D00       .text Execute__Q210daObjMkiek5Act_cFPPA3_A4_f */
BOOL daObjMkiek::Act_c::Execute(Mtx**) {
    /* Nonmatching */
}

/* 00000D00-00000E1C       .text Draw__Q210daObjMkiek5Act_cFv */
BOOL daObjMkiek::Act_c::Draw() {
    /* Nonmatching */
}

namespace daObjMkiek {
namespace {
/* 00000E1C-00000E3C       .text Mthd_Create__Q210daObjMkiek27@unnamed@d_a_obj_mkiek_cpp@FPv */
cPhs_State Mthd_Create(void*) {
    /* Nonmatching */
}

/* 00000E3C-00000E5C       .text Mthd_Delete__Q210daObjMkiek27@unnamed@d_a_obj_mkiek_cpp@FPv */
BOOL Mthd_Delete(void*) {
    /* Nonmatching */
}

/* 00000E5C-00000E7C       .text Mthd_Execute__Q210daObjMkiek27@unnamed@d_a_obj_mkiek_cpp@FPv */
BOOL Mthd_Execute(void*) {
    /* Nonmatching */
}

/* 00000E7C-00000EA8       .text Mthd_Draw__Q210daObjMkiek27@unnamed@d_a_obj_mkiek_cpp@FPv */
BOOL Mthd_Draw(void*) {
    /* Nonmatching */
}

/* 00000EA8-00000ED4       .text Mthd_IsDelete__Q210daObjMkiek27@unnamed@d_a_obj_mkiek_cpp@FPv */
BOOL Mthd_IsDelete(void*) {
    /* Nonmatching */
}

static actor_method_class Mthd_Table = {
    (process_method_func)Mthd_Create,
    (process_method_func)Mthd_Delete,
    (process_method_func)Mthd_Execute,
    (process_method_func)Mthd_IsDelete,
    (process_method_func)Mthd_Draw,
};
}; // namespace
}; // namespace daObjMkiek

actor_process_profile_definition g_profile_Obj_Mkiek = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Mkiek,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjMkiek::Act_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0037,
    /* Actor SubMtd */ &daObjMkiek::Mthd_Table,
    /* Status       */ fopAcStts_NOCULLEXEC_e | fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
