#ifndef RES_KWOOD_00_H
#define RES_KWOOD_00_H

enum KWOOD_00_RES_FILE_ID {
    /* BAS */
    KWOOD_00_BAS_BREAK=0x0,
    KWOOD_00_BAS_SWING=0x1,
    KWOOD_00_BAS_SWING02=0x8,
    
    /* BCK */
    KWOOD_00_BCK_BREAK=0x2,
    KWOOD_00_BCK_SWING=0x3,
    KWOOD_00_BCK_SWING02=0x7,
    
    /* BMDC */
    KWOOD_00_BMD_WB=0x5,
    KWOOD_00_BMD_WS=0x6,
};

enum KWOOD_00_RES_FILE_INDEX {
    /* BAS */
    KWOOD_00_INDEX_BAS_BREAK=0x5,
    KWOOD_00_INDEX_BAS_SWING=0x6,
    KWOOD_00_INDEX_BAS_SWING02=0x7,
    
    /* BCK */
    KWOOD_00_INDEX_BCK_BREAK=0xA,
    KWOOD_00_INDEX_BCK_SWING=0xB,
    KWOOD_00_INDEX_BCK_SWING02=0xC,
    
    /* BMDC */
    KWOOD_00_INDEX_BMD_WB=0xF,
    KWOOD_00_INDEX_BMD_WS=0x10,
};

#endif /* RES_KWOOD_00_H */