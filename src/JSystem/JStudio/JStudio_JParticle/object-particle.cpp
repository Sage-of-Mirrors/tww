//
// Generated by dtk
// Translation Unit: object-particle.cpp
//

#include "JSystem/JStudio/JStudio_JParticle/object-particle.h"
#include "JSystem/JParticle/JPAEmitterManager.h"
#include "JSystem/JStudio/JStudio/jstudio-math.h"
#include "dolphin/types.h"

namespace JStudio_JParticle {

/* 80279878-80279954       .text __ct__Q217JStudio_JParticle17TAdaptor_particleFP17JPAEmitterManagerPCQ26JStage7TSystem */
TAdaptor_particle::TAdaptor_particle(JPAEmitterManager* emitterManager, const JStage::TSystem* system)
    : mEmitterManager(emitterManager)
    , mEmitter(NULL)
    , mCallback(this)
    , _188(-1)
    , _18C(0)
    , _190(0)
    , _194(0)
    , mSystem(system)
    , _19C(NULL)
    , _1A0(0xFFFFFFFF)
    , _1A4(0)
{
}

/* 802799B0-80279A50       .text __dt__Q217JStudio_JParticle17TAdaptor_particleFv */
TAdaptor_particle::~TAdaptor_particle() {
    if (mEmitter != NULL) {
        mEmitterManager->forceDeleteEmitter(mEmitter);
    }
}

/* 80279A50-80279BD4       .text adaptor_do_prepare__Q217JStudio_JParticle17TAdaptor_particleFPCQ27JStudio7TObject */
void TAdaptor_particle::adaptor_do_prepare(const JStudio::TObject* param_1) {
    static TSetVariableValue_immediate aoData[18] = {
        TSetVariableValue_immediate(0, 0.0f),    TSetVariableValue_immediate(1, 0.0f),    TSetVariableValue_immediate(2, 0.0f),
        TSetVariableValue_immediate(3, 0.0f),    TSetVariableValue_immediate(4, 0.0f),    TSetVariableValue_immediate(5, 0.0f),
        TSetVariableValue_immediate(6, 1.0f),    TSetVariableValue_immediate(7, 1.0f),    TSetVariableValue_immediate(8, 1.0f),
        TSetVariableValue_immediate(9, 255.0f),  TSetVariableValue_immediate(10, 255.0f), TSetVariableValue_immediate(11, 255.0f),
        TSetVariableValue_immediate(12, 255.0f), TSetVariableValue_immediate(13, 255.0f), TSetVariableValue_immediate(14, 255.0f),
        TSetVariableValue_immediate(15, 255.0f), TSetVariableValue_immediate(16, 255.0f), TSetVariableValue_immediate(0xFFFFFFFF, NAN)
    };
    adaptor_setVariableValue_immediate(aoData);
    mVariableValues[18].setOutput(&TAdaptor_particle::soVVOOn_BEGIN_FADE_IN_);
    mVariableValues[19].setOutput(&TAdaptor_particle::soVVOOn_END_FADE_OUT_);
    mCallback.mObject = param_1;
}

TAdaptor_particle::TVVOOn_BEGIN_FADE_IN_ TAdaptor_particle::soVVOOn_BEGIN_FADE_IN_;
TAdaptor_particle::TVVOOn_END_FADE_OUT_ TAdaptor_particle::soVVOOn_END_FADE_OUT_;

/* 80279BD4-80279BD8       .text adaptor_do_end__Q217JStudio_JParticle17TAdaptor_particleFPCQ27JStudio7TObject */
void TAdaptor_particle::adaptor_do_end(const JStudio::TObject*) {}

/* 80279BD8-80279C2C       .text adaptor_do_update__Q217JStudio_JParticle17TAdaptor_particleFPCQ27JStudio7TObjectUl */
void TAdaptor_particle::adaptor_do_update(const JStudio::TObject* param_1, u32 param_2) {
    if (_190 == 0) {
        return;
    }
    if (_194 >= _190) {
        return;
    }
    _194 += param_2;
    if (_194 < _190) {
        return;
    }
    switch (_18C) {
    case 2:
        break;
    default:
        _18C     = 0;
        break;
    }
    _190 = 0;
    _194 = 0;
}

/* 80279C2C-80279C40       .text adaptor_do_PARTICLE__Q217JStudio_JParticle17TAdaptor_particleFQ37JStudio4data15TEOperationDataPCvUl */
void TAdaptor_particle::adaptor_do_PARTICLE(JStudio::data::TEOperationData operation, const void* r5, u32) {
    switch (operation) {
    case JStudio::data::UNK_0x19:
        _188 = *(int*)r5;
        break;
    }
}

/* 80279C40-80279CA4       .text adaptor_do_PARENT__Q217JStudio_JParticle17TAdaptor_particleFQ37JStudio4data15TEOperationDataPCvUl */
void TAdaptor_particle::adaptor_do_PARENT(JStudio::data::TEOperationData operation, const void* param_2, u32) {
    switch (operation) {
    case JStudio::data::UNK_0x18:
        if (mSystem != NULL) {
            _19C = (JStage::TObject*)mSystem->JSGFindObject((const char*)param_2, JStage::TOBJ_ACTOR_UNK);
            if (_19C == 0) {
                // Fakematch, just need something in here to stop the compiler from optimizing out the cmplwi
                *(f32*)NULL = *(f32*)NULL;
            }
        }
        break;
    }
}

/* 80279CA4-80279D24       .text adaptor_do_PARENT_NODE__Q217JStudio_JParticle17TAdaptor_particleFQ37JStudio4data15TEOperationDataPCvUl */
void TAdaptor_particle::adaptor_do_PARENT_NODE(JStudio::data::TEOperationData operation, const void* param_2, u32) {
    switch (operation) {
    case JStudio::data::UNK_0x18:
        if (_19C != NULL) {
            _1A0 = _19C->JSGFindNodeID((const char*)param_2);
            if (_1A0 == 0xFFFFFFFF) {
                return;
            }
        }
        break;
    case JStudio::data::UNK_0x19:
        _1A0 = *(u32*)param_2;
        break;
    }
}

/* 80279D24-80279D40       .text adaptor_do_PARENT_ENABLE__Q217JStudio_JParticle17TAdaptor_particleFQ37JStudio4data15TEOperationDataPCvUl */
void TAdaptor_particle::adaptor_do_PARENT_ENABLE(JStudio::data::TEOperationData operation, const void* param_2, u32 param_3) {
    switch (operation) {
    case JStudio::data::UNK_0x2:
        _1A4 = *(u32*)param_2;
        break;
    }
}

/* 80279D40-80279E2C       .text __cl__Q317JStudio_JParticle17TAdaptor_particle21TVVOOn_BEGIN_FADE_IN_CFfPQ27JStudio8TAdaptor */
void TAdaptor_particle::TVVOOn_BEGIN_FADE_IN_::operator()(float, JStudio::TAdaptor*) const {
    /* Nonmatching */
}

/* 80279E2C-80279F08       .text __cl__Q317JStudio_JParticle17TAdaptor_particle20TVVOOn_END_FADE_OUT_CFfPQ27JStudio8TAdaptor */
void TAdaptor_particle::TVVOOn_END_FADE_OUT_::operator()(float, JStudio::TAdaptor*) const {
    /* Nonmatching */
}

/* 80279F08-8027A2B8       .text execute__Q317JStudio_JParticle17TAdaptor_particle13TJPACallback_FP14JPABaseEmitter */
void TAdaptor_particle::TJPACallback_::execute(JPABaseEmitter* emitter) {
    if (emitter->isEnableDeleteEmitter()) {
        mAdaptor->_18C     = 0;
        mAdaptor->_190     = 0;
        mAdaptor->_194     = 0;
        mAdaptor->mEmitterManager->forceDeleteEmitter(emitter);
        mAdaptor->mEmitter = NULL;
        return;
    }
    
    f64 alpha = 1.0;
    f64 val1 = mAdaptor->_190; // u32 stored as f64
    switch (mAdaptor->_18C) {
    case 1:
        if (mAdaptor->_190 != 0) {
            f64 val2 = mAdaptor->_194; // u32 stored as f64
            alpha = val2 / val1;
        }
        break;
    case 2:
        if (mAdaptor->_190 == 0) {
            alpha = 0.0;
            if (emitter != NULL) {
                emitter->stopCreateParticle();
                emitter->setMaxFrame(1);
            } else {
                f64 val2 = mAdaptor->_190 - mAdaptor->_194; // u32 stored as f64
                alpha = val2 / val1;
            }
        }
        break;
    }

    const JStudio::TControl* ctrl = static_cast<const JStudio::TControl*>(mObject->getControl()); // r28

    emitter->stopDrawParticle();

    Vec srts[2]; // 0x64
    Vec sp0C;
    mAdaptor->adaptor_getVariableValue_Vec(&srts[0], sauVariableValue_3_TRANSLATION_XYZ);
    mAdaptor->adaptor_getVariableValue_Vec(&srts[1], sauVariableValue_3_ROTATION_XYZ);
    mAdaptor->adaptor_getVariableValue_Vec(&sp0C, sauVariableValue_3_SCALING_XYZ);

    Vec* pos; // r29

    if (!mAdaptor->_1A4) {
        if (!ctrl->transformOnSet_isEnabled()) {
            pos = srts;
        } else {
            Vec outVec[2];
            MTXMultVec(ctrl->transformOnSet_getMatrix(), &srts[0], &outVec[0]);
            outVec[1].x = srts[1].x;
            outVec[1].y = ctrl->transformOnSet_getRotationY() + srts[1].y;
            outVec[1].z = srts[1].z;
            pos         = outVec;
        }
        emitter->setGlobalTranslation(pos[0]);

        int angleX = 65536.0 * (pos[1].x / 360.0);
        int angleY = 65536.0 * (pos[1].y / 360.0);
        int angleZ = 65536.0 * (pos[1].z / 360.0);
        emitter->setGlobalRotation(JGeometry::TVec3<s16>(angleX, angleY, angleZ));
        emitter->setGlobalScale(sp0C);
    } else {
        if (mAdaptor->_19C == NULL) {
            return;
        }
        Mtx spA8;
        Mtx sp78;
        Mtx sp48;
        if (mAdaptor->_19C->JSGGetNodeTransformation(mAdaptor->_1A0, spA8) == 0) {
            return;
        }
        JStudio::math::getTransformation_SRxyzT(sp78, sp0C, srts[1], srts[0]);
        MTXConcat(spA8, sp78, sp48);
        emitter->setGlobalSRTMatrix(sp48);
    }

    GXColor color;
    mAdaptor->adaptor_getVariableValue_GXColor(&color, sauVariableValue_4_COLOR_RGBA);
    emitter->setGlobalPrmColor(color.r, color.g, color.b);

    alpha *= (f64)color.a;
    u8 emitAlpha = 255;
    if (alpha < 255.0) {
        emitAlpha = (u8)alpha;
    }

    emitter->setGlobalAlpha(emitAlpha);

    mAdaptor->adaptor_getVariableValue_GXColor(&color, sauVariableValue_4_COLOR1_RGBA);
    emitter->setGlobalEnvColor(color.r, color.g, color.b);
    emitter->playDrawParticle();
}

}; // namespace JStudio_JParticle
