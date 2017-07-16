//       Created by Severen        //
//           l_table.c             //
//         Nov. 11th 1998          //


#include <lib.h>
#include "../defs.h"

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("table");
    SetId("table","large table","large stone table");
    SetShort("a large stone table");
    SetAdjectives( ({ "stone","grey","heavy","large" }) );
    SetLong("This is a large stone table. It has four legs and is "
      "grey in color. Upon it are various notes and things that a mage "
      "would find useful in the ancient art of whatever they practiced "
      "in this tower. It is large enough to seat about ten people.");
    SetPreventGet("The legs seem to be part of the floor.");
}
