#ifndef D_A_BST_H
#define D_A_BST_H

#include "f_op/f_op_actor.h"
#include "m_Do/m_Do_hostIO.h"
#include "d/d_cc_d.h"
#include "d/d_bg_s_acch.h"
#include "d/d_particle.h"

class mDoExt_McaMorf;
class mDoExt_btkAnm;
class mDoExt_brkAnm;
class J3DModel;

class bst_class : public fopAc_ac_c {
public:
    bst_class();
    /* 0x0290 */ u8 m0290[0x1C];

    /* 0x02AC */ request_of_phase_process_class mPhs;

    /* 0x02B4 */ u8 mBodyType;
    /* 0x02B8 */ mDoExt_McaMorf* mpBodyAnm;
    /* 0x02BC */ mDoExt_btkAnm* mpBodyTexAnm;
    /* 0x02C0 */ mDoExt_brkAnm* mpBodyRegAnm;
    /* 0x02C4 */ bool mbPlayBodyAnms;

    /* 0x02C8 */ J3DModel* mpSeatMdl;
    /* 0x02CC */ mDoExt_btkAnm* mpSeatTexAnm;
    /* 0x02D0 */ mDoExt_brkAnm* mpSeatRegAnm;
    /* 0x02D4 */ bool mbPlaySeatAnms;

    /* 0x02D8 */ dKy_tevstr_c mTevStr;
    /* 0x0388 */ J3DModel* mpBodyMdl;

    /* 0x038C */ s32 mShadowId;

    /* 0x0390 */ J3DModel* mpBeamMdls[10];
    /* 0x03B8 */ cXyz mBeamPosArray[10];
    /* 0x0430 */ cXyz mBeamVecArray_0430[10];
    /* 0x04A8 */ csXyz mBeamSVecArray_04A8[10];
    /* 0x04E4 */ s8 mBeamS8Array[10];
    /* 0x04F0 */ dCcD_Sph mBeamColSphArray[10];

    /* 0x109C */ u8 m109C[0x34];

    /* 0x10D0 */ float m10D0;
    /* 0x10D4 */ short m10D4;

    // ...
    /* 0x10E4 */ u8 m10D6[0x1130 - 0x10E4];

    /* 0x1130 */ dBgS_AcchCir mAcchCir;
    /* 0x1170 */ dBgS_ObjAcch mAcch;
    /* 0x1334 */ dCcD_Stts mColStts;
    /* 0x1370 */ dCcD_Cyl mColCyl_1370;
    /* 0x14A0 */ dCcD_Cyl mColCyl_14A0;

    /* 0x15D0 */ dCcD_Sph mHandColSphArray[19];
    /* 0x2C14 */ dCcD_Sph mColSphArray_2C14[2];
    
    /* 0x2E6C */ s16 mSArray_2E6C[6];
    /* 0x2E78 */ s16 m2E78;
    /* 0x2E7A */ s16 m2E7A;

    // ...
    /* 0x2E7C */ u8 m2E7C[0x2E90 - 0x2E7C];

    /* 0x2E90 */ int mAttProcIds[2];

    /* 0x2E98 */ u8 m2E98[0x2F00 - 0x2E98];

    /* 0x2F00 */ dPa_smokeEcallBack mSmokeCB;
    /* 0x2F20 */ dKy_tevstr_c mTevStr_2F20;

    /* 0x2FD0 */ J3DModel* mpFloorMdl;
    /* 0x2FD4 */ mDoExt_btkAnm* mpFloorTexAnm;
    /* 0x2FD8 */ mDoExt_brkAnm* mpFloorRegAnm;

    /* 0x2FDC */ J3DModel* mpWallMdl;
    /* 0x2FE0 */ mDoExt_brkAnm* mpWallRegMdl;

    /* 0x2FE4 */ bool mb2FE4;
    /* 0x2FE5 */ bool mbHioSet;

    // /* 0x0000 */ f32 z;
    // /* 0x0004 */ u8 m0004[0x0028 - 0x0004];
    // /* 0x02B8 */ mDoExt_McaMorf* m02B8;
    // /* 0x02BC */ mDoExt_baseAnm* m02BC;
    // /* 0x02C0 */ mDoExt_baseAnm* m02C0;
    // /* 0x00F8 */ u16 m00F8;
    // /* 0x00FA */ u16 m00FA;
    // /* 0x00FC */ u8 m00FC[0x01C4 - 0x00FC];
    // /* 0x01C4 */ u32 m01C4;
    // /* 0x01C8 */ u8 m01C8[0x01D0 - 0x01C8];
    // /* 0x01D0 */ f32 m01D0;
    // /* 0x01D4 */ f32 m01D4;
    // /* 0x01D8 */ f32 m01D8;
    // /* 0x01DC */ s16 m01DC;
    // /* 0x01DE */ s16 m01DE;
    // /* 0x01E0 */ s16 m01E0;
    // /* 0x01E2 */ u8 m01E2[0x01F8 - 0x01E2];
    // /* 0x01F8 */ f32 m01F8;
    // /* 0x01FC */ f32 m01FC;
    // /* 0x0200 */ f32 m0200;
    // /* 0x0204 */ u8 m0204[0x020A - 0x0204];
    // /* 0x020A */ s8 m020A;
    // /* 0x020B */ u8 m020B[0x020C - 0x020B];
    // /* 0x020C */ s16 m020C;
    // /* 0x020E */ s16 m020E;
    // /* 0x0210 */ s16 m0210;
    // /* 0x0212 */ u8 m0212[0x0214 - 0x0212];
    // /* 0x0214 */ u32 m0214;
    // /* 0x0218 */ u32 m0218;
    // /* 0x021C */ u32 m021C;
    // /* 0x0220 */ u8 m0220[0x0254 - 0x0220];
    // /* 0x0254 */ u32 m0254;
    // /* 0x0258 */ u8 m0258[0x0260 - 0x0258];
    // /* 0x0260 */ u32 m0260;
    // /* 0x0264 */ u32 m0264;
    // /* 0x0268 */ u32 m0268;
    // /* 0x026C */ u8 m026C[0x0274 - 0x026C];
    // /* 0x0274 */ u32 m0274;
    // /* 0x0278 */ u32 m0278;
    // /* 0x027C */ u32 m027C;
    // /* 0x0280 */ u32 m0280;
    // /* 0x0284 */ u8 m0284[0x0285 - 0x0284];
    // /* 0x0285 */ s8 m0285;
    // /* 0x0286 */ u8 m0286[0x02B4 - 0x0286];
    // /* 0x02B4 */ s8 m02B4;
    // /* 0x02B5 */ u8 m02B5[0x02B8 - 0x02B5];
    // /* 0x02C4 */ s8 m02C4;
    // /* 0x02C5 */ u8 m02C5[0x02C8 - 0x02C5];
    // /* 0x02C8 */ int m02C8;
    // /* 0x02CC */ mDoExt_baseAnm* m02CC;
    // /* 0x02D0 */ mDoExt_baseAnm* m02D0;
    // /* 0x02D4 */ s8 m02D4;
    // /* 0x02D5 */ u8 m02D5[0x0388 - 0x02D5];
    // /* 0x0388 */ int m0388;
    // /* 0x038C */ u32 m038C;
    // /* 0x0390 */ u8 m0390[0x1410 - 0x0390];
    // /* 0x15D0 */ dCcD_Sph mHitInfo[19];
    // /* 0x2E9C */ u8 msFrameCount;
    // /* 0x2E9D */ u8 m2E9D[0x32E4 - 0x2E9D];
    // s16 mYRot0;
    // s16 mYRot1;
};

class daBst_HIO_c : public JORReflexible {
public:
    daBst_HIO_c();
    virtual ~daBst_HIO_c() { }

    s8 m0004;
    u8 m0005;
    u8 m0006;
};

#endif /* D_A_BST_H */
