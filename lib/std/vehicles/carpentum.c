#include <lib.h>
inherit LIB_WAGON;

static void create() {
  ::create();
  SetKeyName("carpentum");
  SetShort("an extravagant carpentum");
  SetId( ({ "carpentum" }) );
  SetAdjectives( ({ "fancy" }) );
  SetLong(
    "This Sanctum-style carriage is crafted of a bright heartwood with a fine "
    "light stain, the boards expertly set together without flaw. The steelshod "
    "wheels look like they can take a great deal of abuse, and the wooden "
    "slats forming the roof look mostly waterproof. An open doorway on one "
    "side allows access, "
    "with a window on the other for the passenger's scenic enjoyment. The "
    "driver's seat looks oddly like a wooden throne, two carved statues of "
    "snarling lions perched atop the rails flanking it."
  );
  SetBridgeDescription("Leather pads the two facing benches within this "
    "carpentum, and a fanciful woodcarving runs just below the ceiling, "
    "depicting many strange and likely imaginary beasts fighting mythical "
    "and likewise imaginary heroes of Sanctum. A doorway is open to the outside "
    "on the left, and a large square window-hole looks out the opposite side. "
    "A little bit of wiggle room in the seats suggests they can be taken up "
    "to allow a bit more storage room.");
  
  SetValue(100000);
  SetMaxSitters(1);
}

