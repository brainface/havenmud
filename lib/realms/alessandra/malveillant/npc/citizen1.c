/*  Portia  11-6-98
    A citizen of Malveillant.
 */

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("citizen");
  SetShort("a citizen of Malveillant");
  SetId( ({"citizen"}) );
  SetGender("female");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetClass("rogue");
  SetLevel(17);
  SetLong("This gorgeous woman is very much your typical dark-elf "
          "Her dark hair and almost white skin contrast in a strikingly "
          "beautiful way, leaving one almost hypnotized by her beauty.");
  SetAction(10,
      "!flirt guard");
  SetCurrency("roni",random(20) + 20);
  SetInventory( ([
      MAL_OBJ + "/clothing/leggings"  : "wear leggings",
      MAL_OBJ + "/clothing/medallion" : "wear medallion",
      MAL_OBJ + "/clothing/tunic"     : "wear tunic",
      ]) );
  }
