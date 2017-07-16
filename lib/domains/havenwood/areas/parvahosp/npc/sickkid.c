#include <std.h>
#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("child");
  SetShort ("a sick child");
  SetId( ({ "child" }) );
  SetAdjectives( ({ "sick" }) );
  SetGender( ({ "male","female" })[random(2)] );
  SetLong(
    "Tired and weak, this sick child's skin is pale and moist.  "
    "A pained expression is on " + possessive(this_object()) + " face."
  );
  SetRace("human");
  SetClass("rogue");
  SetLevel(1);
  
  SetMorality(800);
  SetInventory( ([
    STD_GERMS + "pflu" : 1,
    PO + "/block" : 2,
   ]) );
   SetAction(1,({ 
     "!emote whimpers.",
     "!emote cries." 
   }) );
}
