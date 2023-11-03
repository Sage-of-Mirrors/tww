//
// Generated by dtk
// Translation Unit: d_a_andsw2.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "dolphin/types.h"

enum {
    ACT_ON_ALL,
    ACT_TIMER,
    ACT_ORDER,
    ACT_EVENT,
    ACT_OFF,
    ACT_WAIT,
};

enum {
    TYPE_ONE_OFF,
    TYPE_CONTINUOUS,
};

struct daAndsw2_c : public fopAc_ac_c {
public:
    u8 getEventNo();
    u8 getSwbit();
    u8 getSwbit2();
    u8 getType();
    u8 getTimer();
    u8 getNum();
    u8 getTopSw();
    BOOL chkAllSw2();
    
    inline BOOL execute();
    inline s32 create();

public:
    u8 mAction;
    s16 mTimer;
    s16 mEventIdx;
};

/* 00000078-00000084       .text getEventNo__10daAndsw2_cFv */
u8 daAndsw2_c::getEventNo() {
    return (orig.angle.x & 0x00FF) >> 0;
}

/* 00000084-00000090       .text getSwbit__10daAndsw2_cFv */
u8 daAndsw2_c::getSwbit() {
    // Switch to set.
    return (mBase.mParameters & 0x00FF0000) >> 16;
}

/* 00000090-0000009C       .text getSwbit2__10daAndsw2_cFv */
u8 daAndsw2_c::getSwbit2() {
    // First switch to check.
    return (mBase.mParameters & 0xFF000000) >> 24;
}

/* 0000009C-000000A8       .text getType__10daAndsw2_cFv */
u8 daAndsw2_c::getType() {
    return (mBase.mParameters & 0x0000FF00) >> 8;
}

/* 000000A8-000000B4       .text getTimer__10daAndsw2_cFv */
u8 daAndsw2_c::getTimer() {
    return (orig.angle.z & 0x00FF) >> 0;
}

/* 000000B4-000000C0       .text getNum__10daAndsw2_cFv */
u8 daAndsw2_c::getNum() {
    // Number of switches to check.
    return (mBase.mParameters & 0x000000FF) >> 0;
}

/* 000000C0-00000130       .text getTopSw__10daAndsw2_cFv */
u8 daAndsw2_c::getTopSw() {
    // Swbit2 is the first switch to check.
    // If unspecified, start checking from the next switch after the switch to set (Swbit) instead.
    if (getSwbit2() != 0xFF) {
        return getSwbit2();
    }
    if (getSwbit() != 0xFF) {
        return getSwbit() + 1;
    }
    return 0xFF;
}

/* 00000130-000001D8       .text chkAllSw2__10daAndsw2_cFv */
BOOL daAndsw2_c::chkAllSw2() {
    int topSw = getTopSw();
    int num = getNum();
    if (num == 0xFF || num == 0 || topSw == 0xFF) {
        return false;
    }
    for (int i = 0; i < num; i++) {
        if (!dComIfGs_isSwitch(topSw+i, current.roomNo)) {
            return false;
        }
    }
    return TRUE;
}

/* 000001D8-000002B0       .text daAndsw2_actionOnAll__FP10daAndsw2_c */
static BOOL daAndsw2_actionOnAll(daAndsw2_c* i_this) {
    if (i_this->chkAllSw2()) {
        if (i_this->getTimer() != 0xFF) {
            i_this->mTimer = i_this->getTimer()*15;
            i_this->mAction = ACT_TIMER;
        } else if (i_this->mEventIdx != -1) {
            i_this->mAction = ACT_ORDER;
        } else {
            int room = i_this->current.roomNo;
            int sw = i_this->getSwbit();
            dComIfGs_onSwitch(sw, room);

            if (i_this->getType() == TYPE_CONTINUOUS) {
                i_this->mAction = ACT_OFF;
            } else {
                i_this->mAction = ACT_WAIT;
            }
        }
    }
    return TRUE;
}

/* 000002B0-00000380       .text daAndsw2_actionTimer__FP10daAndsw2_c */
static BOOL daAndsw2_actionTimer(daAndsw2_c* i_this) {
    if (i_this->getType() == TYPE_CONTINUOUS && !i_this->chkAllSw2()) {
        i_this->mAction = ACT_ON_ALL;
    } else if (i_this->mTimer > 0) {
        i_this->mTimer -= 1;
    } else if (i_this->mEventIdx != -1) {
        i_this->mAction = ACT_ORDER;
    } else {
        int room = i_this->current.roomNo;
        int sw = i_this->getSwbit();
        dComIfGs_onSwitch(sw, room);
        
        if (i_this->getType() == TYPE_CONTINUOUS) {
            i_this->mAction = ACT_WAIT;
        }
    }
    return TRUE;
}

/* 00000380-00000438       .text daAndsw2_actionOrder__FP10daAndsw2_c */
static BOOL daAndsw2_actionOrder(daAndsw2_c* i_this) {
    if (i_this->mEvtInfo.checkCommandDemoAccrpt()) {
        i_this->mAction = ACT_EVENT;
        int room = i_this->current.roomNo;
        int sw = i_this->getSwbit();
        dComIfGs_onSwitch(sw, room);
    } else if (i_this->getType() == TYPE_CONTINUOUS && !i_this->chkAllSw2()) {
        i_this->mAction = ACT_ON_ALL;
    } else {
        fopAcM_orderOtherEventId(i_this, i_this->mEventIdx, i_this->getEventNo(), 0xFFFF, 0, 1);
    }
    return TRUE;
}

/* 00000438-000004BC       .text daAndsw2_actionEvent__FP10daAndsw2_c */
static BOOL daAndsw2_actionEvent(daAndsw2_c* i_this) {
    if (dComIfGp_evmng_endCheck(i_this->mEventIdx)) {
        if (i_this->getType() == TYPE_CONTINUOUS) {
            i_this->mAction = ACT_OFF;
        } else {
            i_this->mAction = ACT_WAIT;
        }
        dComIfGp_event_reset();
    }
    return TRUE;
}

/* 000004BC-00000528       .text daAndsw2_actionOff__FP10daAndsw2_c */
static BOOL daAndsw2_actionOff(daAndsw2_c* i_this) {
    if (!i_this->chkAllSw2()) {
        i_this->mAction = ACT_ON_ALL;
        int room = i_this->current.roomNo;
        int sw = i_this->getSwbit();
        dComIfGs_offSwitch(sw, room);
    }
    return TRUE;
}

/* 00000528-00000530       .text daAndsw2_actionWait__FP10daAndsw2_c */
static BOOL daAndsw2_actionWait(daAndsw2_c* i_this) {
    return TRUE;
}

BOOL daAndsw2_c::execute() {
    static BOOL (*l_action[6])(daAndsw2_c*) = {
        daAndsw2_actionOnAll,
        daAndsw2_actionTimer,
        daAndsw2_actionOrder,
        daAndsw2_actionEvent,
        daAndsw2_actionOff,
        daAndsw2_actionWait,
    };
    l_action[mAction](this);
    return TRUE;
}

s32 daAndsw2_c::create() {
    int sw = getSwbit();
    
    fopAcM_SetupActor(this, daAndsw2_c);
    
    switch (getType()) {
    case TYPE_ONE_OFF:
        if (sw == 0xFF || dComIfGs_isSwitch(sw, current.roomNo)) {
            // Switch invalid or already set.
            mAction = ACT_WAIT;
        } else {
            // Switch not yet set, check for the condition to be met.
            mAction = ACT_ON_ALL;
        }
        mEventIdx = dComIfGp_evmng_getEventIdx(NULL, getEventNo());
        break;
    case TYPE_CONTINUOUS:
        if (sw == 0xFF) {
            // Switch invalid.
            mAction = ACT_WAIT;
        } else if (dComIfGs_isSwitch(sw, current.roomNo)) {
            // Switch already set, wait for the condition to no longer be met.
            mAction = ACT_OFF;
        } else {
            // Switch not yet set, check for the condition to be met.
            mAction = ACT_ON_ALL;
        }
        mEventIdx = dComIfGp_evmng_getEventIdx(NULL, getEventNo());
        break;
    default:
        // Invalid type, do nothing.
        mAction = ACT_WAIT;
        break;
    }
    
    // Clear the parameters out of the current rotation.
    shape_angle.z = 0;
    shape_angle.x = 0;
    current.angle.z = 0;
    current.angle.x = 0;
    
    return cPhs_COMPLEATE_e;
}

/* 00000530-00000538       .text daAndsw2_Draw__FP10daAndsw2_c */
static BOOL daAndsw2_Draw(daAndsw2_c* i_this) {
    return TRUE;
}

/* 00000538-00000574       .text daAndsw2_Execute__FP10daAndsw2_c */
static BOOL daAndsw2_Execute(daAndsw2_c* i_this) {
    return i_this->execute();
}

/* 00000574-0000057C       .text daAndsw2_IsDelete__FP10daAndsw2_c */
static BOOL daAndsw2_IsDelete(daAndsw2_c* i_this) {
    return TRUE;
}

/* 0000057C-000005AC       .text daAndsw2_Delete__FP10daAndsw2_c */
static BOOL daAndsw2_Delete(daAndsw2_c* i_this) {
    i_this->~daAndsw2_c();
    return TRUE;
}

/* 000005AC-00000724       .text daAndsw2_Create__FP10fopAc_ac_c */
static s32 daAndsw2_Create(fopAc_ac_c* ac) {
    return ((daAndsw2_c*)ac)->create();
}

static actor_method_class l_daAndsw2_Method = {
    (process_method_func)daAndsw2_Create,
    (process_method_func)daAndsw2_Delete,
    (process_method_func)daAndsw2_Execute,
    (process_method_func)daAndsw2_IsDelete,
    (process_method_func)daAndsw2_Draw,
};

actor_process_profile_definition g_profile_ANDSW2 = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_ANDSW2,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daAndsw2_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0136,
    /* Actor SubMtd */ &l_daAndsw2_Method,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_6_e,
};
