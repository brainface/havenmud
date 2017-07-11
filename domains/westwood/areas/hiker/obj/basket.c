#include <lib.h>

inherit LIB_STORAGE;

static void create() {
  ::create();
   SetKeyName("picnic basket");
   SetShort("a picnic basket");
   SetId( ({ "picnic","basket" }) );
   SetAdjectives( ({ "picnic" }) );
   SetLong("The basket looks like it was woven from wood.  It might "
           "contain a really yummy picnic lunch, if one is lucky.");
   SetMass(15);
   SetValue(15);
   SetCanClose(1);
   SetClosed(1);
   SetMaxCarry(120);
   SetDamagePoints(25);
   SetMaterial("wood" );
   SetRepairDifficulty(10);
   SetRepairSkills( ([
      "wood working" : 2,
                  ]) );
}
