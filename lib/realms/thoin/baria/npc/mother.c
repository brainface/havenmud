//
//  the mother for the small dwelling.
//     kyla 11-2-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/14/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("mother");
  SetId( ({"mother", "woman"}) );
  SetAdjectives( ({ "motherly", "kind" })  );
  SetShort("a motherly looking woman");
  SetLong(
     "This young woman has the looks of a woman whom has taken care of her image. "
     "Her long dark hair flows down her slender athletic body. Her tanned skin has "
     "the softness of that of a young child. Although she has good looks, she appears "
     "to be one whom has seen a lot of manual labor in her life time. Unlike her face, "
     "her hands and feet appear to be bruised, cut, and thickened over the years. She "
     "looks like a kind person, for even though she is stuck doing labor, she still appears "
     "to be happy and content with the place that she resides in. "
  );
  SetInventory( ([
     BARIA_OBJ + "axe" : "wield axe",
     BARIA_OBJ + "old_dress" : "wear dress",
  ]) );
  SetMorality(200);
  SetCurrency( ([
     "chits" : 20 + random(15),
  ]) );
  SetFriends( ({"child"}) );
  SetRace("human");
  SetClass("fighter");
  SetLevel(14);
  SetGender("female");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetAction(2, ({
     "!smile child",
     "!say I love my child with all my heart.",
     "!say Welcome to my humble home.",
     "!smile child",
  }) );
}

