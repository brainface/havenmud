//       Created by Severen        //
//          sarcophagus.c          //
//          Late December          //


#include <lib.h>
#include "../defs.h"

inherit LIB_STORAGE;

static void create() {
    storage::create();
    SetKeyName("sarcophagus");
    SetId("sarcophagus","large sarcophagus");
    SetShort("a large sarcophagus");
    SetAdjectives( ({ "large","stone" }) );
    SetLong("This is a large ceremonial coffin of some once "
      "wealthy person. It stands about seven feet tall and is in "
      "the shape of a human form. It is made of stone and the paint "
      "which decorated it is long faded.");

    SetCanClose(1);
    SetClosed(1);
    SetPreventGet("It is too heavy to lift.");

}
