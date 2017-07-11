#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;
#include "../castle.h"
int CheckVale();

static void create() {
   sentient::create();
   SetKeyName("chilling spook");
   SetShort("a chilling spook");
   SetId( ({ "spook" }) );
   SetAdjectives( ({ "chilling" }) );
   SetLong("No legs poke out of the floating apparation, and "
           "no real solid body hangs on to the ghost-like creature.  "
           "Chilling blue eyes peer out from its face.");
   SetRace("wraith");
   DestLimb("left foot");
   SetProperty("vale_undead", 1);
    SetFriends( ({ "shade", "skeleton", "ghost", "zombie", "spook", "ghoul", "phantom" }) );
   DestLimb("right foot");
   DestLimb("left leg");
   DestLimb("right leg");
   SetGender("male");
   SetClass("rogue");
   SetLevel(13);
   SetLimit(3);
   SetWander(25);
   SetEncounter( (: CheckVale :) );
   SetMeleeDamageType(COLD|BLUNT);
   SetNoCorpse(1);
   SetUndead(1);
   SetMorality(-80);
   SetInventory( ([
                    VC_OBJ + "/c_gem_s" : 1,
                    VC_OBJ + "/c_gem_g" : 1+random(2),
               ]) );
}
int CheckVale() {
  object who = this_player();
  if (!(who->GetProperty("vale_undead"))) {
    SetAttack(who);
  return 1;
  }
return 0;
}
