#ifndef D_A_DAIOCTA_H
#define D_A_DAIOCTA_H

#include "m_Do/m_Do_ext.h"
#include "d/d_cc_d.h"
#include "f_op/f_op_actor.h"

class J3DNode;
class mDoExt_bckAnm;
class mDoExt_btkAnm;
class mDoExt_brkAnm;

class daDaiocta_c : public fopAc_ac_c {
public:
    enum Proc_e {
        proc_ZERO_e
    };

    enum Mode_e {
        mode_ZERO_e,
        mode_ONE_e,
        mode_TWO_e,
        mode_THREE_e,
        mode_FOUR_e
    };

    u8 getSw() { return mSwitchNo; }

    void _coHit(fopAc_ac_c*);
    void _nodeControl(J3DNode*, J3DModel*);
    bool _createHeap();
    BOOL createAwaHeap();
    BOOL createSuikomiHeap();
    BOOL createBodyHeap();
    BOOL createArrowHitHeap();
    void setMtx();
    void setSuikomiMtx();
    void setAwaMtx();
    void initMtx();
    void setEffect(unsigned short);
    void setAwaRandom(int);
    void initAwa();
    void execAwa();
    void isLivingEye();
    void isDead();
    void isDamageEye();
    void isDamageBombEye();
    void setRotEye();
    void setCollision();
    void modeHideInit();
    void modeHide();
    void modeAppearInit();
    void modeAppear();
    void modeWaitInit();
    void modeWait();
    void modeDamageInit();
    void modeDamage();
    void modeDamageBombInit();
    void modeDamageBomb();
    void modeDemoInit();
    void modeDemo();
    void modeDeleteInit();
    void modeDelete();
    void modeProc(Proc_e, Mode_e);
    void setAnm();
    void setWater();
    BOOL _execute();
    void drawAwa();
    void drawSuikomi();
    void drawDebug();
    BOOL _draw();
    void getArg();
    void createInit();
    s32 _create();
    BOOL _delete();

    static const int m_heapsize;
    static const char m_arc_name[];
    static const dCcD_SrcSph m_sph_src;
    static const dCcD_SrcCps m_cps_src;

public:
    /* 0x290 */ cXyz m290[0x25];
    /* 0x44C */ u8 field_0x290[0x56C - 0x44C];
    /* 0x56C */ int m056C;
    /* 0x570 */ int m0570;
    /* 0x574 */ int m0574;
    /* 0x574 */ u8 mSwitchNo;

    /* 0x575 */ u8 data[0x588 - 0x575];

    /* 0x588 */ mDoExt_McaMorf* mBodyMorf;
    /* 0x58C */ mDoExt_brkAnm mBodyBrk;

    /* 0x590 */ u8 data2[0x21A0 - 0x5A4];

    /* 0x21A0 */ cXyz m21A0;
    /* 0x21AC */ cXyz m21AC;
    /* 0x21B8 */ cXyz m21B8;
    /* 0x21C4 */ cXyz m21C4;
    /* 0x21D0 */ cXyz m21D0;
    /* 0x21DC */ cXyz m21DC;
    /* 0x21E8 */ cXyz m21E8;

    /* 0x21F4 */ u8 data3[0x2434 - 0x21F4];

    /* 0x2434 */ cXyz m2434;

    /* 0x2440 */ u8 data4[0x26C8 - 0x2440];

    /* 0x26C8 */ JntHit_c* mJntHit;

    /* 0x26CC */ J3DModel* mSuikomiModel;
    /* 0x26D0 */ mDoExt_brkAnm mSuikomiBrk;
    /* 0x26E8 */ mDoExt_btkAnm mSuikomiBtk;

    /* 0x26FC */ J3DModel* mModels[0x1E];
    /* 0x2774 */ mDoExt_bckAnm mBcks[0x1E];
    /* 0x2954 */ mDoExt_btkAnm mBtks[0x1E];
    /* 0x2BAC */ mDoExt_brkAnm mBrks[0x1E];
};

#endif /* D_A_DAIOCTA_H */
