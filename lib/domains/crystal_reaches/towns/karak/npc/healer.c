// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("nothleus");
  SetId( ({ "nothleus", "healer", "orc"}) );
  SetShort("Nothleus the healer");
  SetLong(
    "Nothelus is truly massive, even for an orc. All of her limbs are corded "
    "with muscle and her neck is so wide it blends in to her shoulders making "
    "it appear her head is directly attached to her torso. Her eyes are dark "
    "and mysterious, with a suggestion of power swirling in their depths. "
    "Combined with her obvious physical prowess, this suggests she would be a "
    "formitable opponent."
  );
  SetGender("female");
  SetRace("orc");
  SetClass("fighter");
  SetLevel(40);
  SetTown("Karak"); 
  SetCurrency("orcteef",random(500));
  SetInventory( ([
    KARAK_OBJ + "axe" : "wield axe",
  ]) );
  SetLocalCurrency("orcteef");
  SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
  ]) );
}
