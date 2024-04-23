#ifndef RES_BTD_H
#define RES_BTD_H

enum BTD_RES_FILE_ID { // IDs and indexes are synced
    /* BCK */
    BTD_BCK_BTD_POSE=0x8,
    BTD_BCK_DAMAGE1=0x9,
    BTD_BCK_DAMAGE2=0xA,
    BTD_BCK_DAMAGE3=0xB,
    BTD_BCK_DEAD=0xC,
    BTD_BCK_FATTACK1=0xD,
    BTD_BCK_FATTACK2=0xE,
    BTD_BCK_FATTACK3=0xF,
    BTD_BCK_FATTACK4=0x10,
    BTD_BCK_HASAMI_ATTACK=0x11,
    BTD_BCK_HIT_L=0x12,
    BTD_BCK_HIT_M=0x13,
    BTD_BCK_HIT_R=0x14,
    BTD_BCK_KYORO=0x15,
    BTD_BCK_LATTACK1=0x16,
    BTD_BCK_LATTACK2=0x17,
    BTD_BCK_LATTACK3=0x18,
    BTD_BCK_LATTACK4=0x19,
    BTD_BCK_LATTACK5=0x1A,
    BTD_BCK_LJAB1=0x1B,
    BTD_BCK_LJAB2=0x1C,
    BTD_BCK_LJAB3=0x1D,
    BTD_BCK_MOTIAGE1=0x1E,
    BTD_BCK_MOTIAGE2=0x1F,
    BTD_BCK_MOTIAGE3=0x20,
    BTD_BCK_RATTACK1=0x21,
    BTD_BCK_RATTACK2=0x22,
    BTD_BCK_RATTACK3=0x23,
    BTD_BCK_RATTACK4=0x24,
    BTD_BCK_RATTACK5=0x25,
    BTD_BCK_RJAB1=0x26,
    BTD_BCK_RJAB2=0x27,
    BTD_BCK_RJAB3=0x28,
    BTD_BCK_SIZUMU=0x29,
    BTD_BCK_SIZUMU1=0x2A,
    BTD_BCK_SIZUMU2=0x2B,
    BTD_BCK_SIZUMU3=0x2C,
    BTD_BCK_SSTART=0x2D,
    BTD_BCK_START_LOOP=0x2E,
    BTD_BCK_UEMUKI_WAIT=0x2F,
    BTD_BCK_UE_KAEN1=0x30,
    BTD_BCK_UE_KAEN2=0x31,
    BTD_BCK_UE_KAEN3=0x32,
    BTD_BCK_WAIT1=0x33,
    BTD_BCK_WARERU1=0x34,
    BTD_BCK_WARERU2=0x35,
    BTD_BCK_YOKO_KAEN1=0x36,
    BTD_BCK_YOKO_KAEN2=0x37,
    BTD_BCK_YOKO_KAEN3=0x38,
    BTD_BCK_YOKO_WAIT=0x39,
    
    /* BMD */
    BTD_BMD_HAHENA=0x3C,
    BTD_BMD_KAMENA=0x3D,
    
    /* BMDM */
    BTD_BMD_BTD=0x40,
    BTD_BMD_NAMAKUBI=0x41,
    BTD_BMD_SOTAI=0x42,
    
    /* BMT */
    BTD_BMT_DEADA=0x45,
    
    /* BRK */
    BTD_BRK_BTD=0x48,
    BTD_BRK_DEADA=0x49,
    BTD_BRK_DEADB=0x4A,
    BTD_BRK_HIBI01=0x4B,
    BTD_BRK_HIBI02=0x4C,
    BTD_BRK_HIBI03=0x4D,
    BTD_BRK_NAMAKUBI=0x4E,
    BTD_BRK_SOTAI=0x4F,
    
    /* BTK */
    BTD_BTK_BTD=0x52,
    BTD_BTK_DEADA=0x53,
    BTD_BTK_DEADB=0x54,
    BTD_BTK_NAMAKUBI=0x55,
    BTD_BTK_SOTAI=0x56,
};

#endif /* RES_BTD_H */