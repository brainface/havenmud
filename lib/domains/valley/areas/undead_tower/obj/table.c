//       Created by Severen        //
//            table.c              //
//         Nov. 11th 1998          //


#include <lib.h>
#include "../defs.h"

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("table");
    SetId("table","stone table");
    SetShort("a stone table");
    SetAdjectives( ({ "stone","grey","heavy" }) );
    SetLong("This is a stone table. It is grey and looks very heavy. "
      "It has four legs and it looks to have been chiseled out of a much "
      "larger piece of stone.");
    SetPreventGet("It won't fit through the doorway.");
}

