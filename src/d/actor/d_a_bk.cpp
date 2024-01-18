//
// Generated by dtk
// Translation Unit: d_a_bk.cpp
//

#include "d/actor/d_a_bk.h"
#include "f_op/f_op_actor_mng.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_obj_search.h"
#include "d/actor/d_a_item.h"
#include "d/d_item_data.h"
#include "d/actor/d_a_boko.h"
#include "d/actor/d_a_bomb.h"
#include "d/d_bg_s_lin_chk.h"
#include "m_Do/m_Do_mtx.h"
#include "d/actor/d_a_player.h"
#include "d/d_s_play.h"
#include "d/d_path.h"

static u8 hio_set;
static u8 another_hit;
static u32 ken;
static u8 search_sp;
static bkHIO_c l_bkHIO;

enum BK_RES_FILE_ID { // IDs and indexes are synced
    /* BAS */
    BK_BAS_BK_AOMUKE=0x8,
    BK_BAS_BK_ATTACK1=0x9,
    BK_BAS_BK_ATTACK2=0xA,
    BK_BAS_BK_ATTACK3=0xB,
    BK_BAS_BK_BOKKURI=0xC,
    BK_BAS_BK_CATCH=0xD,
    BK_BAS_BK_HAKKEN=0xE,
    BK_BAS_BK_IATTACK1=0xF,
    BK_BAS_BK_JATTACK2=0x10,
    BK_BAS_BK_JATTACK3=0x11,
    BK_BAS_BK_JUMP1=0x12,
    BK_BAS_BK_JUMP2=0x13,
    BK_BAS_BK_KERI1=0x14,
    BK_BAS_BK_KERI2=0x15,
    BK_BAS_BK_KYORO1=0x16,
    BK_BAS_BK_KYORO2=0x17,
    BK_BAS_BK_NIGERU=0x18,
    BK_BAS_BK_NOBI=0x19,
    BK_BAS_BK_NOMWAIT=0x1A,
    BK_BAS_BK_OKIRUA=0x1B,
    BK_BAS_BK_OKIRUU=0x1C,
    BK_BAS_BK_OTISOU1=0x1D,
    BK_BAS_BK_OTISOU2=0x1E,
    BK_BAS_BK_RUN=0x1F,
    BK_BAS_BK_SLEEP=0x20,
    BK_BAS_BK_SUWARI=0x21,
    BK_BAS_BK_TUTUKU1=0x22,
    BK_BAS_BK_UTUBUSE=0x23,
    BK_BAS_BK_WAIT=0x24,
    BK_BAS_BK_WALK=0x25,
    BK_BAS_BK_WALK2=0x26,
    
    /* BCK */
    BK_BCK_BK_AOMUKE=0x29,
    BK_BCK_BK_ATTACK1=0x2A,
    BK_BCK_BK_ATTACK2=0x2B,
    BK_BCK_BK_ATTACK3=0x2C,
    BK_BCK_BK_BIKKURI=0x2D,
    BK_BCK_BK_BOUGYO1=0x2E,
    BK_BCK_BK_BOUGYO2=0x2F,
    BK_BCK_BK_CATCH=0x30,
    BK_BCK_BK_HAKKEN=0x31,
    BK_BCK_BK_HAKOBI=0x32,
    BK_BCK_BK_HIDARIROT=0x33,
    BK_BCK_BK_JATTACK1=0x34,
    BK_BCK_BK_JATTACK2=0x35,
    BK_BCK_BK_JATTACK3=0x36,
    BK_BCK_BK_JUMP1=0x37,
    BK_BCK_BK_JUMP2=0x38,
    BK_BCK_BK_KERI1=0x39,
    BK_BCK_BK_KERI2=0x3A,
    BK_BCK_BK_KIME=0x3B,
    BK_BCK_BK_KOUKA=0x3C,
    BK_BCK_BK_KYORO1=0x3D,
    BK_BCK_BK_KYORO2=0x3E,
    BK_BCK_BK_MIGIROT=0x3F,
    BK_BCK_BK_NIGERU=0x40,
    BK_BCK_BK_NOBI=0x41,
    BK_BCK_BK_NOMWAIT=0x42,
    BK_BCK_BK_NOZOKU=0x43,
    BK_BCK_BK_OKIRUA=0x44,
    BK_BCK_BK_OKIRUU=0x45,
    BK_BCK_BK_OTISOU1=0x46,
    BK_BCK_BK_OTISOU2=0x47,
    BK_BCK_BK_RUN=0x48,
    BK_BCK_BK_SLEEP=0x49,
    BK_BCK_BK_SUWARI=0x4A,
    BK_BCK_BK_TATAKU=0x4B,
    BK_BCK_BK_TUTUKU1=0x4C,
    BK_BCK_BK_TUTUKU2=0x4D,
    BK_BCK_BK_TUTUKU3=0x4E,
    BK_BCK_BK_TYAKU=0x4F,
    BK_BCK_BK_UTUBUSE=0x50,
    BK_BCK_BK_WAIT=0x51,
    BK_BCK_BK_WALK=0x52,
    BK_BCK_BK_WALK2=0x53,
    
    /* BDLM */
    BK_BDL_BK=0x56,
    BK_BDL_BOUEN=0x57,
    
    /* BMD */
    BK_BMD_BK_KB=0x5A,
    BK_BMD_BK_TATE=0x5B,
    
    /* BMT */
    BK_BMT_BK_BOKO=0x5E,
    BK_BMT_BK_KEN=0x5F,
    BK_BMT_GREEN=0x60,
    BK_BMT_PINK=0x61,
    
    /* BTP */
    BK_BTP_TMABATAKI=0x64,
};

/* 000000EC-00000234       .text anm_init__FP8bk_classifUcfi */
static void anm_init(bk_class* i_this, int bckFileIdx, f32 morf, u8 loopMode, f32 speed, int soundFileIdx) {
    if (i_this->mDamageReaction.mState == 0x13 && bckFileIdx != BK_BCK_BK_OTISOU1 && bckFileIdx != BK_BCK_BK_OTISOU2) {
        return;
    }
    if (soundFileIdx >= 0) {
        void* soundAnm = dComIfG_getObjectRes("Bk", soundFileIdx);
        J3DAnmTransform* bckAnm = (J3DAnmTransform*)dComIfG_getObjectRes("Bk", bckFileIdx);
        i_this->mpMorf->setAnm(bckAnm, loopMode, morf, speed, 0.0f, -1.0f, soundAnm);
    } else {
        J3DAnmTransform* bckAnm = (J3DAnmTransform*)dComIfG_getObjectRes("Bk", bckFileIdx);
        i_this->mpMorf->setAnm(bckAnm, loopMode, morf, speed, 0.0f, -1.0f, NULL);
    }
}

/* 00000234-000005A8       .text yari_off_check__FP8bk_class */
static void yari_off_check(bk_class* i_this) {
    if (i_this->m0B34 == 0) {
        return;
    }
    
    daBoko_c* boko = (daBoko_c*)fopAcM_SearchByID(i_this->m1200);
    if (boko) {
        daPy_py_c* player = (daPy_py_c*)dComIfGp_getPlayer(0);
        fopAcM_cancelCarryNow(boko);
        
        if (i_this->m0B34 != 2) {
            boko->setRotAngleSpeed(cM_rndFX(2000.0f));
            s16 angleY = i_this->shape_angle.y + 0x8000 + (s16)cM_rndFX(8000.0f);
            f32 speedY = 20.0f + cM_rndF(20.0f);
            f32 speedForward = 20.0f + cM_rndF(10.0f);
            boko->moveStateInit(speedForward, speedY, angleY);
        }
        boko->current.angle.y = player->shape_angle.y;
        
        dBgS_LinChk linChk;
        linChk.Set(&i_this->mEyePos, &boko->current.pos, i_this);
        if (dComIfG_Bgsp()->LineCross(&linChk)) {
            MtxP mtx = i_this->mpMorf->getModel()->getAnmMtx(0x10); // mune (chest) joint
            cMtx_copy(mtx, *calc_mtx);
            boko->setMatrix(*calc_mtx);
            cXyz offset;
            offset.set(0.0f, 0.0f, 0.0f);
            MtxPosition(&offset, &boko->current.pos);
        }
    }
    
    i_this->m121F = 1;
    i_this->m0B34 = 0;
    i_this->m0B30 = 0;
}

/* 00000A1C-00000EE8       .text smoke_set_s__FP8bk_classf */
static void smoke_set_s(bk_class* i_this, f32 rate) {
    dBgS_LinChk linChk;
    s32 attribCode;
    attribCode = 0;
    cXyz startPos = i_this->m0338;
    startPos.y += 100.0f;
    cXyz endPos = i_this->m0338;
    endPos.y -= 100.0f;
    linChk.Set(&startPos, &endPos, i_this);
    
    dBgS* bgs = dComIfG_Bgsp(); // Fakematch? fixes regalloc
    if (bgs->LineCross(&linChk)) {
        endPos = linChk.GetCross();
        i_this->m0338.y = endPos.y;
        attribCode = bgs->GetAttributeCode(linChk);
    } else {
        i_this->m0338.y -= 20000.0f;
    }
    
    if (i_this->m034F != 0 && attribCode != dBgS_Attr_GRASS_e) {
        return;
    }
    
    i_this->m034F++;
    
    switch (attribCode) {
    case dBgS_Attr_NORMAL_e:
    case dBgS_Attr_DIRT_e:
    case dBgS_Attr_WOOD_e:
    case dBgS_Attr_STONE_e:
    case dBgS_Attr_SAND_e:
        i_this->m0350.end();
        JPABaseEmitter* emitter1 = dComIfGp_particle_setToon(
            0x2022, &i_this->m0338, &i_this->m0344, NULL, 0xB9,
            &i_this->m0350, fopAcM_GetRoomNo(i_this)
        );
        if (emitter1) {
            emitter1->setRate(rate);
            emitter1->setSpread(1.0f);
            JGeometry::TVec3<f32> scale;
            scale.x = scale.y = scale.z = 1.2f;
            emitter1->setGlobalScale(scale);
            scale.x = scale.y = scale.z = 1.5f + g_regHIO.mChild[0].mFloatRegs[16];
            emitter1->setGlobalParticleScale(scale);
        }
        break;
    case dBgS_Attr_GRASS_e:
        JPABaseEmitter* emitter2 = dComIfGp_particle_set(0x24, &i_this->m0338, &i_this->m0344);
        if (emitter2) {
            emitter2->setRate(rate * 0.5f);
            emitter2->setMaxFrame(3);
        }
        break;
    }
}

/* 00000EE8-000011F0       .text ground_smoke_set__FP8bk_class */
static void ground_smoke_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 000011F0-00001454       .text nodeCallBack__FP7J3DNodei */
static BOOL nodeCallBack(J3DNode*, int) {
    /* Nonmatching */
}

/* 00001454-00001564       .text nodeCallBack_P__FP7J3DNodei */
static BOOL nodeCallBack_P(J3DNode*, int) {
    /* Nonmatching */
}

/* 00001564-000019A4       .text search_check_draw__FP8bk_class */
static void search_check_draw(bk_class* i_this) {
    /* Nonmatching */
}

/* 000019A8-00001B88       .text br_draw__FP8bk_class */
static void br_draw(bk_class* i_this) {
    /* Nonmatching */
}

/* 00001B88-00001CD0       .text daBk_shadowDraw__FP8bk_class */
static BOOL daBk_shadowDraw(bk_class* i_this) {
    /* Nonmatching - regalloc */
    J3DModel* model = i_this->mpMorf->getModel();
    if (!fopAcM_checkCarryNow(i_this)) {
        cXyz shadowPos(
            i_this->current.pos.x,
            i_this->current.pos.y + 150.0f + g_regHIO.mChild[8].mFloatRegs[18],
            i_this->current.pos.z
        );
        f32 temp = 800.0f + g_regHIO.mChild[8].mFloatRegs[19];
        f32 shadowSize = 40.0f + g_regHIO.mChild[8].mFloatRegs[17];
        i_this->mShadowId = dComIfGd_setShadow(
            i_this->mShadowId, 1, model, &shadowPos, temp, shadowSize,
            i_this->current.pos.y, i_this->mDamageReaction.mAcch.GetGroundH(),
            i_this->mDamageReaction.mAcch.m_gnd, &i_this->mTevStr,
            0, 1.0f, dDlst_shadowControl_c::getSimpleTex()
        );
    }
    
    if (i_this->mShadowId) {
        daBoko_c* boko = (daBoko_c*)fopAcM_SearchByID(i_this->m1200);
        if (boko) {
            dComIfGd_addRealShadow(i_this->mShadowId, boko->model);
        }
        if (i_this->m02D4) {
            dComIfGd_addRealShadow(i_this->mShadowId, i_this->m02D0);
        }
        if (i_this->m02DC) {
            dComIfGd_addRealShadow(i_this->mShadowId, i_this->m02D8);
        }
    }
}

/* 00001CD0-00001F60       .text daBk_Draw__FP8bk_class */
static BOOL daBk_Draw(bk_class* i_this) {
    /* Nonmatching */
}

/* 00001F60-00002404       .text way_pos_check__FP8bk_classP4cXyz */
static void way_pos_check(bk_class* i_this, cXyz*) {
    /* Nonmatching */
}

/* 0000259C-00002864       .text ground_4_check__FP8bk_classisf */
static void ground_4_check(bk_class* i_this, int, s16, f32) {
    /* Nonmatching */
}

/* 00002864-00002C4C       .text daBk_other_bg_check__FP8bk_classP10fopAc_ac_c */
static void daBk_other_bg_check(bk_class* i_this, fopAc_ac_c*) {
    /* Nonmatching */
}

static fopAc_ac_c* target_info[10];
static s32 target_info_count;

/* 00002C4C-00002CD4       .text s_w_sub__FPvPv */
static void* s_w_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && fopAcM_GetName(param_1) == PROC_BOKO) {
        daBoko_c* boko = (daBoko_c*)param_1;
        // TODO: enum for boko type
        if (fopAcM_GetParam(boko) != 4 && !fopAcM_checkCarryNow(boko)) {
            if (target_info_count < (s32)ARRAY_SIZE(target_info)) {
                target_info[target_info_count] = boko;
                target_info_count++;
            }
        }
    }
    return NULL;
}

/* 00002CD4-00002FB0       .text search_wepon__FP8bk_class */
static u32 search_wepon(bk_class* i_this) {
    /* Nonmatching */
}

/* 00002FB0-0000302C       .text s_b_sub__FPvPv */
static void* s_b_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && fopAcM_GetName(param_1) == PROC_BOMB) {
        daBomb_c* bomb = (daBomb_c*)param_1;
        // TODO: why is it checking the bomb's params as a single field instead of just one param? bug?
        if (fopAcM_GetParam(bomb) != 0) {
            if (target_info_count < (s32)ARRAY_SIZE(target_info)) {
                target_info[target_info_count] = bomb;
                target_info_count++;
            }
        }
    }
    return NULL;
}

/* 0000302C-000033BC       .text search_bomb__FP8bk_classi */
static fopAc_ac_c* search_bomb(bk_class* i_this, int) {
    /* Nonmatching */
}

/* 000033BC-00003438       .text daBk_wepon_view_check__FP8bk_class */
static BOOL daBk_wepon_view_check(bk_class* i_this) {
    if (i_this->m02CC != 0) {
        return FALSE;
    }
    i_this->m1200 = search_wepon(i_this);
    if (i_this->m1200 != fpcM_ERROR_PROCESS_ID_e) {
        if (fopAcM_SearchByID(i_this->m1200)) {
            return TRUE;
        }
    }
    return FALSE;
}

/* 00003438-00003478       .text daBk_bomb_view_check__FP8bk_class */
static BOOL daBk_bomb_view_check(bk_class* i_this) {
    i_this->m11F8 = search_bomb(i_this, 1);
    return i_this->m11F8 != NULL ? TRUE : FALSE;
}

/* 00003478-000034B8       .text daBk_bomb_check__FP8bk_class */
static BOOL daBk_bomb_check(bk_class* i_this) {
    i_this->m11F8 = search_bomb(i_this, 0);
    if (i_this->m11F8) {
        return TRUE;
    }
    return FALSE;
}

/* 000034B8-0000385C       .text daBk_player_bg_check__FP8bk_classP4cXyz */
static void daBk_player_bg_check(bk_class* i_this, cXyz*) {
    /* Nonmatching */
}

/* 0000385C-00003A18       .text daBk_player_view_check__FP8bk_classP4cXyzss */
static void daBk_player_view_check(bk_class* i_this, cXyz*, s16, s16) {
    /* Nonmatching */
}

/* 00003A18-00003A5C       .text daBk_player_way_check__FP8bk_class */
static BOOL daBk_player_way_check(bk_class* i_this) {
    fopAc_ac_c* player = dComIfGp_getPlayer(0);
    s16 angleDiff = i_this->current.angle.y - player->shape_angle.y;
    if (angleDiff < 0) {
        angleDiff = -angleDiff;
    }
    if ((u16)angleDiff < 0x4000) {
        return FALSE;
    }
    return TRUE;
}

/* 00003A5C-00003B2C       .text wait_set__FP8bk_class */
static void wait_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 00003B2C-00003C34       .text walk_set__FP8bk_class */
static void walk_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 00003C34-00003C74       .text fight_run_set__FP8bk_class */
static void fight_run_set(bk_class* i_this) {
    anm_init(i_this, BK_BCK_BK_RUN, 10.0f, J3DFrameCtrl::LOOP_REPEAT_e, l_bkHIO.m070, BK_BAS_BK_RUN);
}

/* 00003C74-00004104       .text path_check__FP8bk_classUc */
static void path_check(bk_class* i_this, u8) {
    /* Nonmatching */
}

/* 00004104-0000488C       .text jyunkai__FP8bk_class */
static void jyunkai(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000488C-000048E4       .text ken_s_sub__FPvPv */
static void* ken_s_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && fopAcM_GetName(param_1) == PROC_ITEM) {
        daItem_c* item = (daItem_c*)param_1;
        if (item->getItemNo() == DROPPED_SWORD) {
            return param_1;
        }
    }
    return NULL;
}

/* 000048E4-000053E0       .text stand__FP8bk_class */
static void stand(bk_class* i_this) {
    /* Nonmatching */
}

/* 000053E0-000054E0       .text s_s_sub__FPvPv */
static void s_s_sub(void*, void*) {
    /* Nonmatching */
}

/* 000054E0-00005D40       .text stand2__FP8bk_class */
static void stand2(bk_class* i_this) {
    /* Nonmatching */
}

/* 00005D40-00006218       .text path_run__FP8bk_class */
static void path_run(bk_class* i_this) {
    /* Nonmatching */
}

/* 00006218-0000647C       .text attack_set__FP8bk_classUc */
static void attack_set(bk_class* i_this, u8) {
    /* Nonmatching */
}

u16 learn_check;

/* 0000647C-000064D8       .text shot_s_sub__FPvPv */
static void* shot_s_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && learn_check & 0x400 && fopAcM_GetName(param_1) == PROC_HIMO2) {
        return param_1;
    }
    return NULL;
}

/* 000064D8-000073B8       .text fight_run__FP8bk_class */
static void fight_run(bk_class* i_this) {
    /* Nonmatching */
}

/* 000073B8-000075E8       .text yari_hit_check__FP8bk_class */
static void yari_hit_check(bk_class* i_this) {
    /* Nonmatching */
}

/* 000075E8-00007EF4       .text fight__FP8bk_class */
static void fight(bk_class* i_this) {
    /* Nonmatching */
}

/* 00007EF4-00008108       .text p_lost__FP8bk_class */
static void p_lost(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008108-00008470       .text b_nige__FP8bk_class */
static void b_nige(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008470-00008580       .text defence__FP8bk_class */
static void defence(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008580-00008654       .text oshi__FP8bk_class */
static void oshi(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008654-00008C38       .text hukki__FP8bk_class */
static void hukki(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008C38-00008D1C       .text aite_miru__FP8bk_class */
static void aite_miru(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008D1C-00008ECC       .text fail__FP8bk_class */
static void fail(bk_class* i_this) {
    /* Nonmatching */
}

/* 00008ECC-000090E0       .text yogan_fail__FP8bk_class */
static void yogan_fail(bk_class* i_this) {
    /* Nonmatching */
}

/* 000090E0-0000924C       .text water_fail__FP8bk_class */
static void water_fail(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000924C-00009944       .text wepon_search__FP8bk_class */
static void wepon_search(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009944-00009AFC       .text d_dozou__FP8bk_class */
static void d_dozou(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009AFC-00009B0C       .text carry__FP8bk_class */
static void carry(bk_class* i_this) {
    i_this->speed.y = 0.0f;
}

/* 00009B0C-00009DF0       .text carry_drop__FP8bk_class */
static void carry_drop(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009DF0-00009F1C       .text d_mahi__FP8bk_class */
static void d_mahi(bk_class* i_this) {
    /* Nonmatching */
}

/* 00009F1C-0000A350       .text tubo_wait__FP8bk_class */
static void tubo_wait(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000A350-0000A630       .text z_demo_1__FP8bk_class */
static void z_demo_1(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000A630-0000A9BC       .text b_hang__FP8bk_class */
static void b_hang(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000A9BC-0000AC6C       .text rope_on__FP8bk_class */
static void rope_on(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000AC6C-0000AC84       .text search_target__FP8bk_class */
static BOOL search_target(bk_class* i_this) {
    i_this->mDamageReaction.m714 = dComIfGp_getPlayer(0);
    return FALSE;
}

/* 0000AC84-0000B25C       .text Bk_move__FP8bk_class */
static void Bk_move(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000B25C-0000B324       .text bk_eye_tex_anm__FP8bk_class */
static void bk_eye_tex_anm(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000B324-0000BC98       .text damage_check__FP8bk_class */
static void damage_check(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000BCD4-0000BD30       .text s_s2_sub__FPvPv */
static void* s_s2_sub(void* param_1, void*) {
    if (fopAc_IsActor(param_1) && fopAcM_GetName(param_1) == PROC_OBJ_SEARCH) {
        if (daObj_Search::Act_c::getFindFlag()) {
            return param_1;
        }
    }
    return NULL;
}

/* 0000BD30-0000C2D0       .text waki_set__FP8bk_class */
static void waki_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000C2D0-0000CC68       .text demo_camera__FP8bk_class */
static void demo_camera(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000CC68-0000CD00       .text tate_mtx_set__FP8bk_class */
static void tate_mtx_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000CD00-0000CE18       .text bou_mtx_set__FP8bk_class */
static void bou_mtx_set(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000CE18-0000DD1C       .text daBk_Execute__FP8bk_class */
static BOOL daBk_Execute(bk_class* i_this) {
    /* Nonmatching */
}

/* 0000DD1C-0000DD24       .text daBk_IsDelete__FP8bk_class */
static BOOL daBk_IsDelete(bk_class* i_this) {
    return TRUE;
}

/* 0000DD24-0000DDD8       .text daBk_Delete__FP8bk_class */
static BOOL daBk_Delete(bk_class* i_this) {
    dComIfG_resDelete(&i_this->mPhs, "Bk");
    if (i_this->heap) {
        i_this->mpMorf->stopZelAnime();
    }
    if (i_this->m121D) {
        hio_set = 0;
        mDoHIO_root.mDoHIO_deleteChild(l_bkHIO.mChildID);
    }
    i_this->m0350.end();
    i_this->mDamageReaction.mParticleCallBack.end();
    enemy_fire_remove(&i_this->mEnemyFire);
    return TRUE;
}

/* 0000DDD8-0000E2C8       .text useHeapInit__FP10fopAc_ac_c */
static BOOL useHeapInit(fopAc_ac_c* i_this) {
    /* Nonmatching */
}

/* 0000E310-0000EA2C       .text daBk_Create__FP10fopAc_ac_c */
static s32 daBk_Create(fopAc_ac_c* i_actor) {
    /* Nonmatching - data */
    fopAcM_SetupActor(i_actor, bk_class);
    bk_class* i_this = (bk_class*)i_actor;
    
    s32 phase_state = dComIfG_resLoad(&i_this->mPhs, "Bk");
    if (phase_state == cPhs_COMPLEATE_e) {
        i_this->mGbaName = 1;
        
        if (strcmp(dComIfGp_getStartStageName(), "ITest63") == 0 ||
            strcmp(dComIfGp_getStartStageName(), "GanonJ") == 0)
        {
            search_sp = 1;
        } else {
            search_sp = 0;
        }
        
        i_this->mType = fopAcM_GetParam(i_this) & 0xF;
        i_this->m02B9 = fopAcM_GetParam(i_this) & 0x10;
        i_this->m02D4 = fopAcM_GetParam(i_this) & 0x20;
        if (i_this->mType == 0xB) {
            i_this->m02D4 = 0;
            i_this->m02DC = 1;
            i_this->mType = 4;
        }
        i_this->m02D5 = fopAcM_GetParam(i_this) & 0xC0;
        i_this->m02B5 = fopAcM_GetParam(i_this) >> 8 & 0xFF;
        i_this->m02B6 = fopAcM_GetParam(i_this) >> 16 & 0xFF;
        i_this->m02B7 = fopAcM_GetParam(i_this) >> 24 & 0xFF;
        i_this->m02B8 = i_this->current.angle.z;
        i_this->current.angle.z = 0;
        i_this->current.angle.x = 0;
        if (i_this->m02B8 == 0xFF) {
            i_this->m02B8 = 0;
        }
        
        if (i_this->m02B8 != 0) {
            if (dComIfGs_isSwitch(i_this->m02B8, fopAcM_GetRoomNo(i_this))) {
                return cPhs_ERROR_e;
            }
        }
        if (i_this->m02B9 != 0) {
            if (dComIfGs_isSwitch(i_this->m02B7, fopAcM_GetRoomNo(i_this))) {
                return cPhs_ERROR_e;
            }
            i_this->m02B7 = 0xFF;
        }
        
        i_this->mItemTableIdx = dComIfGp_CharTbl()->GetNameIndex("Bk", 0);
        
        if (!fopAcM_entrySolidHeap(i_this, useHeapInit, 0x17B20)) {
            return cPhs_ERROR_e;
        }
        
        if (!hio_set) {
            l_bkHIO.mChildID = mDoHIO_root.mDoHIO_createChild("ボコちゃん", &l_bkHIO);
            i_this->m121D = 1;
            hio_set = 1;
        }
        
        ken = 0;
        
        if (!i_this->mpMorf || !i_this->mpMorf->getModel()) {
            return cPhs_ERROR_e;
        }
        
        fopAcM_SetMin(i_this, -200.0f, -50.0f, -100.0f);
        fopAcM_SetMax(i_this, 125.0f, 250.0f, 250.0f);
        fopAcM_SetMtx(i_this, i_this->mpMorf->getModel()->getBaseTRMtx());
        i_this->mpMorf->getModel()->setUserArea((u32)i_this);
        i_this->initBt(162.5f, 125.0f);
        
        i_this->mDamageReaction.m70C = 1;
        i_this->mDamageReaction.mSpawnY = i_this->current.pos.y;
        i_this->mDamageReaction.mMaxFallDistance = 1000.0f;
        
        if (i_this->m02B6 != 0xFF) {
            i_this->m1218 = dPath_GetRoomPath(i_this->m02B6, fopAcM_GetRoomNo(i_this));
            if (i_this->m1218 == NULL) {
                return cPhs_ERROR_e;
            }
            i_this->m1215 = i_this->m02B6 + 1;
            i_this->m1217 = 1;
        }
        
        if (i_this->mType == 4 || i_this->mType == 0xA) {
            i_this->mDamageReaction.mState = 1;
            if (i_this->mType == 0xA) {
                i_this->mDamageReaction.m004 = -0x14;
                fopAcM_OnStatus(i_this, fopAcStts_BOSS_e);
            } else {
                i_this->mDamageReaction.m004 = -1;
            }
            i_this->m0302 = 1000.0f + cM_rndF(1000.0f);
        } else if (i_this->mType == 6) {
            i_this->mDamageReaction.mState = 2;
            i_this->mDamageReaction.mMaxFallDistance = 300.0f;
        } else if (i_this->mType == 7) {
            i_this->mDamageReaction.mState = 0x1D;
            i_this->mDamageReaction.mMaxFallDistance = 300.0f;
        } else if (i_this->mType == 5) {
            anm_init(i_this, BK_BCK_BK_HAKOBI, 1.0f, J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, -1);
            i_this->mDamageReaction.mState = 0x1E;
            i_this->mDamageReaction.mMaxFallDistance = 100000.0f;
        } else if (i_this->mType == 2 || i_this->mType == 3) {
            i_this->m02BA = 0xFF;
            i_this->mDamageReaction.mState = 0xF;
            i_this->m030E = 0xA;
        } else if (i_this->mType == 9) {
            i_this->mDamageReaction.mState = 3;
            i_this->m1216 = i_this->current.angle.z;
            i_this->m1217 = i_this->current.angle.y;
            i_this->current.angle.z = 0;
            i_this->current.angle.y = 0;
        }
        
        if (i_this->m02B7 != 0xFF) {
            if (i_this->mType != 6) {
                i_this->m02BA = i_this->m02B7 + 1;
            }
        }
        
        if (i_this->mType == 0xF) {
            i_this->mDamageReaction.mState = 0x17;
            i_this->m02BA = 0;
        }
        
        if (i_this->mType != 8 && i_this->m02DC == 0 &&
            strcmp(dComIfGp_getStartStageName(), "A_mori") != 0)
        {
            u32 weaponType; // TODO enum
            if (i_this->m02D5 & 0x40) {
                weaponType = 1;
            } else if (i_this->m02D5 & 0x80) {
                weaponType = 7;
            } else {
                weaponType = 0;
            }
            i_this->m1200 = fopAcM_create(PROC_BOKO, weaponType, &i_this->current.pos, fopAcM_GetRoomNo(i_this));
            i_this->m1214 = 1;
            i_this->m02D5 &= 0x40;
        } else {
            i_this->m11F3 = 1;
        }
        
        i_this->mDamageReaction.mAcch.Set(
            fopAcM_GetPosition_p(i_this), fopAcM_GetOldPosition_p(i_this),
            i_this, 1, &i_this->mDamageReaction.mAcchCir,
            fopAcM_GetSpeed_p(i_this)
        );
        i_this->mDamageReaction.mAcchCir.SetWall(40.0f, 40.0f);
        i_this->mDamageReaction.mAcch.ClrRoofNone();
        i_this->mDamageReaction.mAcch.SetRoofCrrHeight(80.0f + g_regHIO.mChild[0].mFloatRegs[7]);
        i_this->mDamageReaction.mAcch.OnLineCheck();
        i_this->mDamageReaction.mInvincibleTimer = 5;
        
        if (i_this->m02D4 != 0) {
            i_this->mMaxHealth = i_this->mHealth = 7;
        } else {
            i_this->mMaxHealth = i_this->mHealth = 5;
        }
        
        i_this->mDamageReaction.mStts.Init(200, 0xFF, i_this);
        static dCcD_SrcCyl co_cyl_src = {}; // TODO
        i_this->m0B88.Set(co_cyl_src);
        i_this->m0B88.SetStts(&i_this->mDamageReaction.mStts);
        static dCcD_SrcCyl tg_cyl_src = {}; // TODO
        i_this->m0CB8.Set(tg_cyl_src);
        i_this->m0CB8.SetStts(&i_this->mDamageReaction.mStts);
        static dCcD_SrcSph head_sph_src = {}; // TODO
        i_this->m0DE8.Set(head_sph_src);
        i_this->m0DE8.SetStts(&i_this->mDamageReaction.mStts);
        static dCcD_SrcSph wepon_sph_src = {}; // TODO
        i_this->m1040.Set(wepon_sph_src);
        i_this->m1040.SetStts(&i_this->mDamageReaction.mStts);
        static dCcD_SrcSph defence_sph_src = {}; // TODO
        i_this->m0F14.Set(defence_sph_src);
        i_this->m0F14.SetStts(&i_this->mDamageReaction.mStts);
        
        i_this->m02CC = 5;
        i_this->model = i_this->mpMorf->getModel();
        
        i_this->mEnemyIce.mpActor = i_this;
        i_this->mEnemyIce.mWallRadius = 50.0f + g_regHIO.mChild[0].mFloatRegs[4];
        i_this->mEnemyIce.mCylHeight = 180.0f + g_regHIO.mChild[0].mFloatRegs[5];
        i_this->mEnemyIce.mDeathSwitch = i_this->m02B8;
        
        i_this->mEnemyFire.mpMcaMorf = i_this->mpMorf;
        i_this->mEnemyFire.mpActor = i_this;
        static u8 fire_j[10] = {
            // TODO
        };
        static f32 fire_sc[10] = {
            // TODO
        };
        for (int i = 0; i < ARRAY_SIZE(i_this->mEnemyFire.mFlameJntIdxs); i++) {
            i_this->mEnemyFire.mFlameJntIdxs[i] = fire_j[i];
            i_this->mEnemyFire.mParticleScale[i] = fire_sc[i];
        }
        
        i_this->mItemStealLeft = 3;
        
        daBk_Execute(i_this);
    }
    
    return phase_state;
}

static actor_method_class l_daBk_Method = {
    (process_method_func)daBk_Create,
    (process_method_func)daBk_Delete,
    (process_method_func)daBk_Execute,
    (process_method_func)daBk_IsDelete,
    (process_method_func)daBk_Draw,
};

actor_process_profile_definition g_profile_BK = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_BK,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(bk_class),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x00B0,
    /* Actor SubMtd */ &l_daBk_Method,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e | fopAcStts_UNK80000_e,
    /* Group        */ fopAc_ENEMY_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
