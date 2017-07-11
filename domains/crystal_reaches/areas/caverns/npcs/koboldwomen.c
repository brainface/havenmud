/*  Kobold Chief's Women - Level #1 Caverns  */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold woman");
  SetId( ({ "kobold", "woman", "kobold woman" }) );
  SetAdjectives( ({ "kobold", "woman" }) );
  SetShort("a kobold woman");

  SetLong("The Kobold Woman is supposedly one of the best looking women in the "
          "tribe.  However, one kobold looks generally like another just with "
          "different clothes.  She is wearing a fairly nice red dress, it is "
          "torn and tattered in spots though.  She looks disappointed that the "
          "chief isn't with her instead of on his throne.");

  SetRace("kobold");
  SetClass("rogue");
  SetLevel(2);
  SetGender("female");
  SetMorality(-50);
  SetDie("The Kobold Woman screeches as she dies.");

  SetAction(10, ({ "The Kobold Woman lies on the bed looking pretty.",
                   "The Kobold Woman trys to get as comfortable as possible.",
                   "The Kobold Woman looks lustfully at the kobold chief.",
  }) );

  SetCombatAction(10, ({ "The Kobold Woman screams with rage.",
                         "The Kobold Woman bares her fang teeth and growls.",
                         "The Kobold Woman sets eyes of pure hatred on you.",
  }) );

  SetInventory( ([ OBJS + "/dress1" : "wear dress",
                   OBJS + "/bracelet1" : "wear plain bracelet on right hand",
  ]) );
}
