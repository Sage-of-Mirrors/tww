#ifndef M_DO_EXT_H
#define M_DO_EXT_H

#include "JSystem/J3DGraphAnimator/J3DAnimation.h"
#include "JSystem/J3DGraphAnimator/J3DMaterialAnm.h"
#include "JSystem/J3DGraphAnimator/J3DModel.h"
#include "JSystem/JUtility/JUTFont.h"
#include "d/d_kankyo.h"

class JKRArchive;
class JKRAssertHeap;
class JKRExpHeap;
class JKRHeap;
class JKRSolidHeap;
struct ResTIMG;
class Z2Creature;
class J3DTexMtxAnm;

class mDoExt_baseAnm {
public:
    mDoExt_baseAnm() { mFrameCtrl = NULL; }
    virtual ~mDoExt_baseAnm() {}

    int initPlay(s16 i_frameMax, int i_attribute, f32 i_rate, s16 i_startF, s16 i_endF, bool);
    int play();

    J3DFrameCtrl* getFrameCtrl() { return mFrameCtrl; }
    f32 getPlaySpeed() { return mFrameCtrl->getRate(); }
    void setPlaySpeed(f32 speed) { mFrameCtrl->setRate(speed); }
    f32 getFrame() { return mFrameCtrl->getFrame(); }
    f32 getEndFrame() { return mFrameCtrl->getEnd(); }
    void setFrame(f32 frame) { mFrameCtrl->setFrame(frame); }
    void setPlayMode(int i_mode) { mFrameCtrl->setAttribute(i_mode); }
    void setLoopFrame(f32 i_frame) { mFrameCtrl->setLoop(i_frame); }
    bool isStop() {
        bool stopped = true;
        if (!mFrameCtrl->checkState(1) && mFrameCtrl->getRate() != 0.0f) {
            stopped = false;
        }
        return stopped;
    }

private:
    /* 0x4 */ J3DFrameCtrl* mFrameCtrl;
};  // Size: 0x08

class mDoExt_btkAnm : public mDoExt_baseAnm {
public:
    mDoExt_btkAnm() { mpTexMtxAnm = NULL; }
    int init(J3DMaterialTable* i_matTable, J3DAnmTextureSRTKey* i_btk, int i_anmPlay,
             int i_attribute, f32 i_rate, s16 i_start, s16 i_end, bool i_modify, int i_entry);
    void entry(J3DMaterialTable* i_matTable, f32 i_frame);
    void entry(J3DModelData *i_modelData, f32 i_frame);

    void entry(J3DModelData* i_modelData) { entry(i_modelData, getFrame()); }
    int init(J3DModelData* i_modelData, J3DAnmTextureSRTKey* i_btk, int i_anmPlay, int i_attribute,
             f32 i_rate, s16 i_start, s16 i_end, bool i_modify, int i_entry);

    int remove(J3DModelData* i_modelData) { return i_modelData->removeTexMtxAnimator(mpAnm); }
    void entryFrame() { entryFrame(getFrame()); }
    void entryFrame(f32 frame) { mpAnm->setFrame(frame); }

    J3DAnmTextureSRTKey* getBtkAnm() const { return mpAnm; }

private:
    /* 0x08 */ J3DAnmTextureSRTKey* mpAnm;
    /* 0x0C */ J3DTexMtxAnm* mpTexMtxAnm;
    /* 0x10 */ u16 mUpdateMaterialNum;
};  // Size: 0x14

STATIC_ASSERT(sizeof(mDoExt_btkAnm) == 0x14);

class J3DTevColorAnm;
class J3DTevKColorAnm;
class mDoExt_brkAnm : public mDoExt_baseAnm {
public:
    mDoExt_brkAnm() {
        mpCRegAnm = NULL;
        mpKRegAnm = NULL;
    }
    int init(J3DMaterialTable* i_matTable, J3DAnmTevRegKey* i_brk, int i_anmPlay,
                            int i_attribute, f32 i_rate, s16 i_start, s16 i_end, bool i_modify, int i_entry);
    void entry(J3DMaterialTable* i_matTable, f32 i_frame);

    void entry(J3DModelData* i_modelData) { entry(i_modelData, getFrame()); }
    void entry(J3DModelData* i_modelData, f32 i_frame);

    int init(J3DModelData* i_modelData, J3DAnmTevRegKey* i_brk, int i_anmPlay, int i_attribute,
             f32 i_rate, s16 i_start, s16 i_end, bool i_modify, int i_entry);

    int remove(J3DModelData* i_modelData) { return i_modelData->removeTevRegAnimator(mpAnm); }
    void entryFrame() { entryFrame(getFrame()); }
    void entryFrame(f32 frame) { mpAnm->setFrame(frame); }

    J3DAnmTevRegKey* getBrkAnm() const { return mpAnm; }

private:
    /* 0x08 */ J3DAnmTevRegKey* mpAnm;
    /* 0x0C */ J3DTevColorAnm* mpCRegAnm;
    /* 0x10 */ J3DTevKColorAnm* mpKRegAnm;
    /* 0x14 */ u16 mCRegUpdateMaterialNum;
    /* 0x16 */ u16 mKRegUpdateMaterialNum;
};  // Size: 0x18

STATIC_ASSERT(sizeof(mDoExt_brkAnm) == 0x18);

class mDoExt_bckAnm : public mDoExt_baseAnm {
public:
    mDoExt_bckAnm() { mpMtxCalc = NULL; }
    int init(J3DModelData * i_model, J3DAnmTransform* i_bck, int i_play, int i_attr,
                            f32 i_rate, s16 i_startF, s16 i_endF1, bool i_modify);
    void changeBckOnly(J3DAnmTransform* i_bck);
    void entry(J3DModelData* i_modelData, f32 i_frame);
    void entryJoint(J3DModelData* i_modelData, u16 i_jntNo, f32 i_frame);

    void entry(J3DModelData* i_modelData) { entry(i_modelData, getFrame()); }

    void remove(J3DModelData* i_modelData) { i_modelData->getJointNodePointer(0)->setMtxCalc(NULL); }

    J3DAnmTransform* getBckAnm() { return mAnm; }

    void removeJoint(J3DModelData* i_modelData, u16 i_idx) {
        J3DJoint* mpJnt = i_modelData->getJointNodePointer(i_idx);
        mpJnt->setMtxCalc(0);
    }

private:
    /* 0x08 */ J3DAnmTransform* mAnm;
    /* 0x0C */ J3DMtxCalcMayaAnm* mpMtxCalc;
};  // Size: 0x10

STATIC_ASSERT(sizeof(mDoExt_bckAnm) == 0x10);

class mDoExt_btpAnm : public mDoExt_baseAnm {
public:
    mDoExt_btpAnm() { field_0xc = NULL; }
    int init(J3DMaterialTable* i_matTable, J3DAnmTexPattern* i_btk, int i_anmPlay,
                            int i_attribute, f32 i_rate, s16 i_start, s16 param_6);
    int init(J3DModelData*, J3DAnmTexPattern*, int, int, float, short, short, bool, int);
    int init(J3DMaterialTable*, J3DAnmTexPattern*, int, int, float, short, short, bool, int);
    void entry(J3DModelData* i_modelData, s16 i_frame);
    void entry(J3DMaterialTable* i_matTable, s16 i_frame);

    void entry(J3DModelData* i_modelData) { entry(i_modelData, getFrame()); }

    int init(J3DModelData* i_modelData, J3DAnmTexPattern* i_btk, int i_anmPlay, int i_attribute,
             f32 i_rate, s16 i_start, s16 param_6) {
        return init(&i_modelData->getMaterialTable(), i_btk, i_anmPlay, i_attribute, i_rate,
                    i_start, param_6);
    }

    int remove(J3DModelData* i_modelData) { return i_modelData->removeTexNoAnimator(mpAnm); }

private:
    /* 0x08 */ J3DAnmTexPattern* mpAnm;
    /* 0x0C */ J3DTexNoAnm* field_0xc;
    /* 0x10 */ u16 mUpdateMaterialNum;
};

class mDoExt_blkAnm : public mDoExt_baseAnm {
public:
    int init(J3DDeformData* i_deformData, J3DAnmCluster* i_blk, int i_anmPlay,
                            int i_attribute, f32 i_rate, s16 i_start, s16 param_6);

    J3DAnmCluster* getBlkAnm() { return mpAnm; }

private:
    /* 0x14 */ J3DAnmCluster* mpAnm;
};

class mDoExt_bpkAnm : public mDoExt_baseAnm {
public:
    int init(J3DModelData*, J3DAnmColor*, int, int, float, short, short, bool, int);
    int init(J3DMaterialTable*, J3DAnmColor*, int, int, float, short, short, bool, int);

    void entry(J3DModelData*, float);
    void entry(J3DMaterialTable*, float);

private:
    /* 0x08 */ J3DAnmColor* mpAnm;
    /* 0x0C */ J3DMatColorAnm* field_0xc;
    /* 0x10 */ u16 mUpdateMaterialNum;
};

class mDoExt_bvaAnm : public mDoExt_baseAnm {
public:
    int init(J3DModel*, J3DAnmVisibilityFull*, int, int, float, short, short, bool, int);
    void entry(J3DModel*, short);

    int init(J3DModelData*, J3DAnmTransform*, int, int, float, short, short, bool);

private:
    /* 0x08 */ J3DAnmVisibilityFull* mpAnm;
    /* 0x0C */ J3DVisibilityManager* field_0xc;
};

class mDoExt_AnmRatioPack {
public:
    ~mDoExt_AnmRatioPack();
    mDoExt_AnmRatioPack();

    void setRatio(f32 ratio) { mRatio = ratio; }
    f32 getRatio() { return mRatio; }
    J3DAnmTransform* getAnmTransform() { return mAnmTransform; }
    void setAnmTransform(J3DAnmTransform* anm) { mAnmTransform = anm; }

private:
    /* 0x0 */ f32 mRatio;
    /* 0x4 */ J3DAnmTransform* mAnmTransform;
};  // Size: 0x8

class mDoExt_transAnmBas : public J3DAnmTransformKey {
public:
    mDoExt_transAnmBas(void* bas) { mBas = bas; }
    virtual ~mDoExt_transAnmBas();

    void* getBas() { return mBas; }

private:
    /* 0x2C */ void* mBas;
};

class mDoExt_MtxCalcOldFrame {
public:
    void initOldFrameMorf(f32, u16, u16);
    void decOldFrameMorfCounter();

    f32 getOldFrameRate() { return mOldFrameRate; }
    J3DTransformInfo* getOldFrameTransInfo(int i) { return &mOldFrameTransInfo[i]; }
    u16 getOldFrameStartJoint() { return mOldFrameStartJoint; }
    Quaternion* getOldFrameQuaternion(int i_no) { return &mOldFrameQuaternion[i_no]; }

private:
    /* 0x00 */ bool mOldFrameFlg;
    /* 0x04 */ f32 mOldFrameMorfCounter;
    /* 0x08 */ f32 field_0x8;
    /* 0x0C */ f32 mOldFrameRate;
    /* 0x10 */ f32 field_0x10;
    /* 0x14 */ f32 field_0x14;
    /* 0x18 */ u16 mOldFrameStartJoint;
    /* 0x1A */ u16 mOldFrameEndJoint;
    /* 0x1C */ J3DTransformInfo* mOldFrameTransInfo;
    /* 0x20 */ Quaternion* mOldFrameQuaternion;
};  // Size: 0x24

struct mDoExt_MtxCalcAnmBlendTblOld : public J3DMtxCalcMaya {
    virtual ~mDoExt_MtxCalcAnmBlendTblOld();
    virtual void calc(u16);

    /* 0x4 */ int mNum;
    /* 0x8 */ mDoExt_AnmRatioPack* mAnmRatio;
};  // Size: 0xC

struct mDoExt_MtxCalcAnmBlendTbl : public mDoExt_MtxCalcAnmBlendTblOld {
    J3DAnmTransform* getAnm(int);

    virtual ~mDoExt_MtxCalcAnmBlendTbl();
    virtual void calc(u16);

    /* 0xC */ mDoExt_MtxCalcOldFrame* mOldFrame;
};

class mDoExt_McaMorfCallBack1_c {
public:
    virtual void execute(u16, J3DTransformInfo*) = 0;
};

class mDoExt_McaMorfCallBack2_c {
public:
    virtual void execute(u16, J3DTransformInfo*) = 0;
};

class JAIAnimeSound;

class mDoExt_McaMorf : public J3DMtxCalcMaya {
public:
    mDoExt_McaMorf(J3DModelData*, mDoExt_McaMorfCallBack1_c*, mDoExt_McaMorfCallBack2_c*, J3DAnmTransform*, int, float, int, int, int, void*, unsigned long, unsigned long);
    virtual ~mDoExt_McaMorf();

    void calc();
    void calc(u16);
    void setAnm(J3DAnmTransform* bckAnm, int loopMode, f32 morf, f32 speed, f32, f32, void* soundAnm);
    void setMorf(f32);
    J3DModel* getModel() { return mpModel; }
    void setFrame(f32 frame) { mFrameCtrl.setFrame(frame); }
    f32 getFrame() { return mFrameCtrl.getFrame(); }
    bool isStop() const { //regswap somewhere here
        bool stopped = true;
        if (!mFrameCtrl.checkState(1) && mFrameCtrl.getRate() != 0.0f) {
            stopped = false;
        }

        return stopped;
    }

    void update();
    void updateDL();
    void updateDL(J3DMaterialTable*);
    void entry();
    void entryDL();
    void entryDL(J3DMaterialTable*);
    void play(Vec *, u32, s8);
    void stopZelAnime();

    /* 0x50 */ J3DModel* mpModel;
    /* 0x54 */ J3DAnmTransform* mpAnm;
    /* 0x58 */ J3DFrameCtrl mFrameCtrl;
    /* 0x6C */ J3DTransformInfo* mpTransformInfo;
    /* 0x70 */ Quaternion* mpQuats;
    /* 0x74 */ f32 mCurMorf;
    /* 0x78 */ f32 mPrevMorf;
    /* 0x7C */ f32 mMorfStep;
    /* 0x80 */ JAIAnimeSound * mpSound;
    /* 0x84 */ mDoExt_McaMorfCallBack1_c * mpCallBack1;
    /* 0x88 */ mDoExt_McaMorfCallBack2_c * mpCallBack2;
};

class mDoExt_McaMorf2 {
public:
    mDoExt_McaMorf2(J3DModelData*, mDoExt_McaMorfCallBack1_c*, mDoExt_McaMorfCallBack2_c*, J3DAnmTransform*, J3DAnmTransform*, int, f32, int, int, int, void*, u32, u32);
    ~mDoExt_McaMorf2();

    void ERROR_EXIT();
    void calc(u16);
    void setAnm(J3DAnmTransform*, J3DAnmTransform*, f32, int, f32, f32, f32, f32, void*);
    void setMorf(f32);
    void play(Vec*, u32, s8);
    void entryDL();
    void calc();
    void stopZelAnime();
};

class mDoExt_3DlineMat_c {
public:
    /* 0x0 */ void* field_0x0;
    /* 0x4 */ mDoExt_3DlineMat_c* field_0x4;
};

class mDoExt_3DlineMatSortPacket : public J3DPacket {
public:
    mDoExt_3DlineMatSortPacket() { mp3DlineMat = NULL; }

    void reset() { mp3DlineMat = NULL; }

    void setMat(mDoExt_3DlineMat_c*);
    virtual void draw();
    virtual ~mDoExt_3DlineMatSortPacket();

private:
    /* 0x10 */ mDoExt_3DlineMat_c* mp3DlineMat;
};

class mDoExt_backupMatBlock_c {
public:
    mDoExt_backupMatBlock_c();
    ~mDoExt_backupMatBlock_c();

    void store(J3DMaterial*);
    void restore(J3DMaterial*);

private:
    /* 0x000 */ J3DGXColor mMatColor[2];
    /* 0x008 */ u8 mColorChanNum;
    /* 0x00A */ J3DColorChan mColorChan[4];
    /* 0x012 */ J3DGXColor mAmbColor[2];
    /* 0x01C */ u32 mTexGenNum;
    /* 0x020 */ J3DTexCoord mTexCoord[8];
    /* 0x040 */ J3DTexMtx mTexMtx[8];
    /* 0x660 */ u8 mTevStageNum;
    /* 0x662 */ u16 mTexNo[8];
    /* 0x672 */ J3DGXColorS10 mTevColor[4];
    /* 0x692 */ J3DGXColor mTevKColor[4];
    /* 0x6A2 */ J3DTevStage mTevStage[8];
    /* 0x6E4 */ J3DIndTevStage mIndTevStage[8];
    /* 0x704 */ J3DTevOrder mTevOrder[4];
    /* 0x714 */ u8 mTevKColorSel[4];
    /* 0x718 */ u8 mTevKAlphaSel[4];
    /* 0x71C */ J3DTevSwapModeTable mTevSwapModeTable[4];
    /* 0x720 */ u8 mIndTexStageNum;
    /* 0x721 */ J3DIndTexOrder mIndTexOrder[4];
    /* 0x734 */ J3DIndTexMtx mIndTexMtx[3];
    /* 0x788 */ J3DIndTexCoordScale mIndTexCoordScale[4];
    /* 0x798 */ J3DFog mFog;
    /* 0x7C4 */ J3DAlphaComp mAlphaComp;
    /* 0x7C8 */ J3DBlend mBlend;
    /* 0x7CC */ J3DZMode mZMode;
    /* 0x7CE */ u8 mZCompLoc;
    /* 0x7D0 */ J3DMaterialAnm* mMaterialAnm;
    /* 0x7D4 */ u32 mMaterialMode;
};

class mDoExt_backupMaterial_c {
public:
    bool create(J3DModelData*);
    bool create(u16);
    void restore(J3DModelData*);

private:
    /* 0x00 */ mDoExt_backupMatBlock_c* mBackupMatBlock;
    /* 0x04 */ J3DTexture* mTexture;
    /* 0x08 */ JUTNameTab* mTextureName;
};

class mDoExt_invJntPacket : public J3DPacket {
public:
    mDoExt_invJntPacket() {}
    ~mDoExt_invJntPacket() {}

    void draw();

    void setJoint(J3DModel* i_model, u16 param_1) {
        mModel = i_model;
        field_0x14 = param_1;
    }

    J3DModel* mModel;
    u16 field_0x14;
};

class mDoExt_invisibleModel {
public:
    bool create(J3DModel*);

    void entry();
    void entryMaskOff();

    void updateDL(J3DModel*);
    void updateDL(mDoExt_McaMorf*);

    J3DModel* mModel;
    mDoExt_invJntPacket* mpPackets;
};

class mDoExt_offCupOnAupPacket : public J3DPacket {
public:
    ~mDoExt_offCupOnAupPacket();

    void draw();
};

class mDoExt_onCupOffAupPacket : public J3DPacket {
public:
    ~mDoExt_onCupOffAupPacket();

    void draw();
};

class mDoExt_3Dline_c {
public:
    mDoExt_3Dline_c();
    ~mDoExt_3Dline_c();

    int init(u16, int, int);
};

class mDoExt_3DlineMat0_c {
public:
    int init(u16, u16, int);
    void setMaterial();
    void draw();
    void update(u16, f32, GXColor&, u16, dKy_tevstr_c*);
    void update(u16, GXColor&, dKy_tevstr_c*);
    int getMaterialID();
};

class mDoExt_3DlineMat1_c {
public:
    int init(u16, u16, ResTIMG*, int);
    void setMaterial();
    void draw();
    void update(u16, f32, GXColor&, u16, dKy_tevstr_c*);
    void update(u16, GXColor&, dKy_tevstr_c*);
    int getMaterialID();
};

J3DModel* mDoExt_J3DModel__create(J3DModelData* i_modelData, u32 i_modelFlag, u32 i_differedDlistFlag);

void mDoExt_modelUpdate(J3DModel* i_model);
void mDoExt_modelUpdateDL(J3DModel* i_model);
void mDoExt_modelEntryDL(J3DModel* i_model);

void mDoExt_modelTexturePatch(J3DModelData*);

JKRExpHeap* mDoExt_getCommandHeap();
JKRExpHeap* mDoExt_getZeldaHeap();
JKRExpHeap* mDoExt_getGameHeap();
JKRExpHeap* mDoExt_getArchiveHeap();
JKRExpHeap* mDoExt_createCommandHeap(u32 heapSize, JKRHeap* i_heap);
JKRExpHeap* mDoExt_createArchiveHeap(u32 heapSize, JKRHeap* i_heap);
JKRExpHeap* mDoExt_createZeldaHeap(u32 heapSize, JKRHeap* i_heap);
JKRExpHeap* mDoExt_createGameHeap(u32 heapSize, JKRHeap* i_heap);

s32 mDoExt_getSafeArchiveHeapSize();
s32 mDoExt_getSafeGameHeapSize();
s32 mDoExt_getSafeZeldaHeapSize();
s32 mDoExt_getSafeCommandHeapSize();

s32 mDoExt_resIDToIndex(JKRArchive*, u16);

JKRSolidHeap * mDoExt_createSolidHeapFromGameToCurrent(u32 size, u32 align);
JKRSolidHeap * mDoExt_createSolidHeapToCurrent(u32, JKRHeap *, u32 align);
void mDoExt_restoreCurrentHeap();
u32 mDoExt_adjustSolidHeap(JKRSolidHeap * pHeap);
void mDoExt_destroySolidHeap(JKRSolidHeap * pHeap);
JKRHeap* mDoExt_setCurrentHeap(JKRHeap*);

extern JKRExpHeap* zeldaHeap;
extern JKRExpHeap* gameHeap;
extern JKRExpHeap* commandHeap;
extern JKRExpHeap* archiveHeap;

//inline void mDoMtx_concat(const Mtx a, const Mtx b, Mtx ab) { MTXConcat(a, b, ab); }

#endif
