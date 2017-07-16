// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("dryad");
   SetShort("an aging dryad");
   SetId( ({ "dryad" }) );
   SetAdjectives( ({ "aging" }) );
   SetLong("Signs of age and wisdom show in this ancient dryad, but kindness is "
           "in her eyes.");
   SetGender("female");
   SetRace("dryad");
   SetSkill("melee attack",1,1);
   SetSkill("melee defense",1,1);
   SetLevel(7);
   SetInventory( ([
                    FOREST_OBJ + "dryadring" : "wear ring on right hand",
               ]) );
}
