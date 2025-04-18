//
// Generated by dtk
// Translation Unit: f_pc_leaf.cpp
//

#include "f_pc/f_pc_leaf.h"

/* 8003DC78-8003DC9C       .text fpcLf_GetPriority__FP14leafdraw_class */
s16 fpcLf_GetPriority(leafdraw_class* i_leaf) {
    return fpcDwPi_Get(&i_leaf->mDwPi);
}

/* 8003DC9C-8003DCC0       .text fpcLf_DrawMethod__FP21leafdraw_method_classPv */
BOOL fpcLf_DrawMethod(leafdraw_method_class* i_methods, void* i_data) {
    return fpcMtd_Method(i_methods->mpDrawFunc, i_data);
}

/* 8003DCC0-8003DCF8       .text fpcLf_Draw__FP14leafdraw_class */
BOOL fpcLf_Draw(leafdraw_class* i_leaf) {
    BOOL ret = FALSE;
    if (i_leaf->mbUnk0 == 0)
        ret = fpcLf_DrawMethod(i_leaf->mpDrawMtd, i_leaf);
    return ret;
}

/* 8003DCF8-8003DD20       .text fpcLf_Execute__FP14leafdraw_class */
BOOL fpcLf_Execute(leafdraw_class* i_leaf) {
    return fpcMtd_Execute(&i_leaf->mpDrawMtd->base, i_leaf);
}

/* 8003DD20-8003DD48       .text fpcLf_IsDelete__FP14leafdraw_class */
BOOL fpcLf_IsDelete(leafdraw_class* i_leaf) {
    return fpcMtd_IsDelete(&i_leaf->mpDrawMtd->base, i_leaf);
}

/* 8003DD48-8003DD8C       .text fpcLf_Delete__FP14leafdraw_class */
BOOL fpcLf_Delete(leafdraw_class* i_leaf) {
    BOOL ret = fpcMtd_Delete(&i_leaf->mpDrawMtd->base, i_leaf);
    if (ret == TRUE) {
        i_leaf->base.mSubType = 0;
    }
    return ret;
}

int g_fpcLf_type;

/* 8003DD8C-8003DE00       .text fpcLf_Create__FP14leafdraw_class */
cPhs_State fpcLf_Create(leafdraw_class* i_leaf) {
    leaf_process_profile_definition* profDef;
    if (i_leaf->base.mInitState == 0) {
        profDef = (leaf_process_profile_definition*)i_leaf->base.mpProf;
        i_leaf->mpDrawMtd = profDef->sub_method;
        i_leaf->base.mSubType = fpcBs_MakeOfType(&g_fpcLf_type);
        fpcDwPi_Init(&i_leaf->mDwPi, profDef->mPriority);
        i_leaf->mbUnk0 = 0;
    }
    return fpcMtd_Create(&i_leaf->mpDrawMtd->base, i_leaf);
}

leafdraw_method_class g_fpcLf_Method = {
    (process_method_func)fpcLf_Create,
    (process_method_func)fpcLf_Delete,
    (process_method_func)fpcLf_Execute,
    (process_method_func)fpcLf_IsDelete,
    (process_method_func)fpcLf_Draw,
};
