//       Created by Severen        //
//              bed.c              //
//         Nov. 14th 1998          //


#include <lib.h>
#include "../defs.h"

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("bed");
    SetId("bed","stone bed");
    SetShort("a stone bed");
    SetAdjectives( ({ "stone","grey","heavy" }) );
    SetLong("This is a small stone bed for the owner of the room. "
      "It looks very hard and not very comfortable. It has four legs "
      "and nothing underneath it. There are no markings on it and no "
      "bedding on it.");
    SetPreventGet("Its legs are built into the floor.");
}
