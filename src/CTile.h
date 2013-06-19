#ifndef CTILE_H
#define CTILE_H

#include "Defines.h"

enum {TILE_TYPE_NONE = 0, TILE_TYPE_NORMAL, TILE_TYPE_BLOCK};

class CTile {
public:
    CTile();
    ~CTile();

    int tileID;
    int typeID;

};

#endif // CTILE_H
