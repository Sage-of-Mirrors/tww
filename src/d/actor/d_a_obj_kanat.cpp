//
// Generated by dtk
// Translation Unit: d_a_obj_kanat.cpp
//

#include "d/actor/d_a_obj_kanat.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_mtx.h"
#include "d/d_com_inf_game.h"

Mtx daObjKanat::Act_c::M_tmp_mtx;
const char daObjKanat::Act_c::M_arcname[] = "Kanat";

enum KANAT_RES_FILE_ID { // IDs and indexes are synced
    /* BDL */
    KANAT_BDL_KANAT=0x4,
    
    /* DZB */
    KANAT_DZB_KANAT=0x7,
};

/* 00000078-0000012C       .text CreateHeap__Q210daObjKanat5Act_cFv */
int daObjKanat::Act_c::CreateHeap() {
    J3DModelData* model_data = (J3DModelData*)dComIfG_getObjectRes(M_arcname, KANAT_BDL_KANAT);
    JUT_ASSERT(79, model_data != 0);
    mpModel = mDoExt_J3DModel__create(model_data, 0, 0x11020203);
    return !!mpModel;
}

/* 0000012C-000001AC       .text Create__Q210daObjKanat5Act_cFv */
int daObjKanat::Act_c::Create() {
    fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
    init_mtx();
    fopAcM_setCullSizeBox(this, -500.0, -100.0f, -500.0f, 500.0f, 200.0f, 500.0f);
    m2F4 = 0;
    m2F5 = 1;
    m2D4.setRateOff(0);
    return TRUE;
}

/* 000001AC-000002EC       .text Mthd_Create__Q210daObjKanat5Act_cFv */
s32 daObjKanat::Act_c::Mthd_Create() {
    fopAcM_SetupActor(this, daObjKanat::Act_c);
    
    if (fopAcM_isSwitch(this, prm_get_swSave())) {
        return cPhs_UNK3_e;
    }
    
    s32 phase_state = dComIfG_resLoad(&mPhs, M_arcname);
    if (phase_state == cPhs_COMPLEATE_e) {
        phase_state = MoveBGCreate(M_arcname, KANAT_DZB_KANAT, NULL, 0x6440);
        JUT_ASSERT(126, (phase_state == cPhs_COMPLEATE_e) || (phase_state == cPhs_ERROR_e));
    }
    
    return phase_state;
}

/* 000002EC-0000031C       .text Delete__Q210daObjKanat5Act_cFv */
BOOL daObjKanat::Act_c::Delete() {
    m2D4.end();
    return TRUE;
}

/* 0000031C-00000374       .text Mthd_Delete__Q210daObjKanat5Act_cFv */
BOOL daObjKanat::Act_c::Mthd_Delete() {
    s32 result = MoveBGDelete();
    if (fpcM_CreateResult(this) != cPhs_UNK3_e) {
        dComIfG_resDelete(&mPhs, M_arcname);
    }
    return result;
}

/* 00000374-000003F4       .text set_mtx__Q210daObjKanat5Act_cFv */
void daObjKanat::Act_c::set_mtx() {
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::ZXYrotM(shape_angle);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
    cMtx_copy(mDoMtx_stack_c::get(), M_tmp_mtx);
}

/* 000003F4-00000430       .text init_mtx__Q210daObjKanat5Act_cFv */
void daObjKanat::Act_c::init_mtx() {
    mpModel->setBaseScale(mScale);
    set_mtx();
}

/* 00000430-00000590       .text Execute__Q210daObjKanat5Act_cFPPA3_A4_f */
BOOL daObjKanat::Act_c::Execute(Mtx** pMtx) {
    if (m2F4 == 0) {
        if (fopAcM_isSwitch(this, prm_get_swSave())) {
            m2F4 = 1;
            GXColor color;
            color.r = mTevStr.mColorC0.r;
            color.g = mTevStr.mColorC0.g;
            color.b = mTevStr.mColorC0.b;
            color.a = mTevStr.mColorC0.a;
            dComIfGp_particle_set(
                0x82A2, &current.pos, &current.angle, NULL, 0xFF,
                NULL, current.roomNo, &mTevStr.mColorK0, &color
            );
            dComIfGp_particle_setToon(
                0xA2A3, &current.pos, &current.angle, NULL, 0xB4,
                &m2D4, current.roomNo, &mTevStr.mColorK0, &color
            );
        }
    } else {
        m2F5 = 0;
        if (m2D4.isEnd()) {
            fopAcM_delete(this);
        }
    }
    set_mtx();
    *pMtx = &M_tmp_mtx;
    return TRUE;
}

/* 00000590-00000644       .text Draw__Q210daObjKanat5Act_cFv */
BOOL daObjKanat::Act_c::Draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &mTevStr);
    g_env_light.setLightTevColorType(mpModel, &mTevStr);
    if (m2F5 == 0) {
        return TRUE;
    }
    dComIfGd_setListBG();
    mDoExt_modelUpdateDL(mpModel);
    dComIfGd_setList();
    return TRUE;
}

namespace daObjKanat {
    namespace {
        s32 Mthd_Create(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Create();
        }
        
        BOOL Mthd_Delete(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Delete();
        }
        
        BOOL Mthd_Execute(void* i_this) {
            return static_cast<Act_c*>(i_this)->MoveBGExecute();
        }
        
        BOOL Mthd_Draw(void* i_this) {
            return static_cast<Act_c*>(i_this)->MoveBGDraw();
        }
        
        BOOL Mthd_IsDelete(void* i_this) {
            return static_cast<Act_c*>(i_this)->MoveBGIsDelete();
        }
        
        static actor_method_class Mthd_Kanat = {
            (process_method_func)Mthd_Create,
            (process_method_func)Mthd_Delete,
            (process_method_func)Mthd_Execute,
            (process_method_func)Mthd_IsDelete,
            (process_method_func)Mthd_Draw,
        };
    }
}

actor_process_profile_definition g_profile_Obj_Kanat = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 3,
    /* ListPrio     */ fpcLy_CURRENT_e,
    /* ProcName     */ PROC_Obj_Kanat,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daObjKanat::Act_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0079,
    /* Actor SubMtd */ &daObjKanat::Mthd_Kanat,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
