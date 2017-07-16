#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("slave");
  SetShort("an elven slave");
  SetAdjectives( ({ "elf", "elven" }) );
  SetId( ({ "elf", "slave" }) );
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetGender(random(2) ? "male" : "female");
  SetAction(6, ({
    "!say Please Lord on High... Deliver us!",
    "!say There's a land that was promised us.",
    "!say Some day he will deliver us.",
    "!say Salt, sweat, toil, and mud is my lot.",
    "A slave bows " + possessive(this_object()) + " head and sighs.",
    "A slave bows " + possessive(this_object()) + " head and mutters a prayer.",
    }) );
  SetClass("merchant");
  SetLevel(4);
  SetLong(
    "This elf is a slave.  A dejected, humiliated person held in bondage "
    "within the Xandrian Dynasty. Ripped, worn clothing and useless tools "
    "are the hallmark of this lowly creature."
    );
  SetMorality(300);
  SetInventory( ([
    ]) );
  SetWander(3);
  SetLimit(5);
}