#ifndef D_A_SITEM_H
#define D_A_SITEM_H

#include "f_op/f_op_actor.h"

class sitem_class : public fopAc_ac_c {
public:
    /* Place member variables here */
    char buf[0x24];
    J3DModel* mModel;
    char buf_2[0x28];
    cXyz mPos;
    s16 mXRot;
    s16 mYRot;
    s16 mZRot;
};

#endif /* D_A_SITEM_H */
