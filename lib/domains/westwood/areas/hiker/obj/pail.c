#include <lib.h>
inherit LIB_STORAGE;

static void create() {
   storage::create();
   SetShort("a grey pail");
   SetKeyName("grey pail");
   SetId( ({ "pail","bucket" }) );
   SetAdjectives( ({ "grey","gray","metal" }) );
   SetLong("The grey bucket is very simple.  It has a metal handle "
           "going up from its circular sides, and the bottom is as "
           "plain as the rest of it.");
   SetMass(10);
   SetValue(4);
   SetCanClose(0);
   SetClosed(0);
   SetMaxCarry(90);
   SetDamagePoints(100);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "metal working" : 1,
                  ]) );
}
