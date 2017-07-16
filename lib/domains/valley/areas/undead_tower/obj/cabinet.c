//       Created by Severen        //
//           cabinet.c             //
//         Nov. 12th 1998          //


#include <lib.h>
#include "../defs.h"

inherit LIB_STORAGE;

static void create() {
    storage::create();
    SetKeyName("cabinet");
    SetId("cabinet","large cabinet","large stone cabinet");
    SetShort("a large stone cabinet");
    SetAdjectives( ({ "stone","grey","heavy","large" }) );
    SetLong("This is a large stone cabinet. It has etchings of "
      "basically a bunch of scribbling on it, but the hint that "
      "they are magical symbols is quite evident. The cabinet "
      "stands about 6 feet high and has a door that can be opened. "
      "There doesn't seem to be a lock on it.");

    SetCanClose(1);
    SetClosed(1);
    SetPreventGet("It looks to have been carved out of the floor "
      "itself.");

}
