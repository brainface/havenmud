#include <lib.h>
#include <damage_types.h>
#include "../cata.h"

inherit LIB_NPC;
int CheckEncounter();
static void create() {
  ::create();
  SetKeyName("imp");
  SetId( ({"imp", "cata_npc" }) );
  SetShort("a devilish imp");
  SetAdjectives( ({ "devilish" }) );
  SetLong("A devilish grin plays upon the mouth of this imp. He"
          " stands at ease swaying his tail back and forth. He is"
          " covered in pale grey skin and has eyes the color of coal.");
  SetGender("male");
  SetRace("devil", "imp");
  SetClass("rogue");
  SetSkill("accuracy", 250, 1);
  SetSkill("stealth", 250, 1);
  SetStat("luck", 70, 1);
  SetStat("coordination", 70, 1);
  SetStat("agility", 70, 1);
  AddLimb("tail","torso",5,({ }) );
  SetMorality(-500);
  SetLevel(95);
  SetInventory( ([
      CATA_OBJ "black_knife" : "wield knife",
  ]) );
  SetEncounter( (: CheckEncounter :) );
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(POISON, "immune");
}

int CheckEncounter() {

    if (this_player()->GetInvis()) return 0;
    eventForce("hide");
    if(this_player()->id("cata_npc") == 1) {
       return 0;
     }
     eventForce("backstab " + this_player()->GetKeyName());
     return 0;
  }

varargs int eventDie(object who) {
  object key;

  key = new(CATA_OBJ "casket_key");
  if(!random(10)) {
    key->eventMove(environment());
  }
  return npc::eventDie(who);
}
