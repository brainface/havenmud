#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
  ::create();
  
  SetKeyName("slave");
  SetShort("an elven slave");
  SetAdjectives( ({ "elf", "elven" }) );
  SetId( ({ "elf", "slave" }) );
  SetLong(
     "This elf is a slave. A dejected, humiliated person held in bondage "
     "within the Xandrian Dynasty. Though thin and weary this elf is "
     "clean and clothed due to their position within the Palace."
     );
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetGender(random(2) ? "male" : "female");
  SetAction(6, ({
     "A slave bows " + possessive(this_object()) + " head and sighs.",
     "A slave hefts " + possessive(this_object()) + " fan higher.",
     }) );
  SetInventory( ([
     LISHT_OBJ "palmfan" :1,
     ]) );
  SetClass("merchant");
  SetLevel(10);
  SetMorality(500);

}
