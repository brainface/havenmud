/*  Duhoc - '99  mayor of Glimmerdin */
#include <lib.h>
#include "../glim.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetShort("Gracchus the High Thane of Glimmerdin");
  SetId( ({ "gracchus", "thane" }) );
  SetAdjectives( ({ "high" }) );
  SetKeyName("gracchus");
  SetLong("This is the High Thane of the dwarven town "
     "of Glimmerdin.  If one pays the required taxes, he will permit "
     "even non-dwarven folk residency. He seems quite young, "
     "and has only been Thane for a short time .");
  SetGender("male");
  SetRace("dwarf");
  SetReligion("Kylin");
  SetCurrency( ([
      "glims" : random(50),
    ]) );
  SetLocalCurrency("glims");
  SetTax(10);
  SetTown("Glimmerdin");
  SetClass("cleric");
  SetSkill("healing", 1, 1);
  SetLevel(80);
  SetSpellBook( ([
    "wall of force" : 100,
    "smite" : 100,
    "touch of death" : 100,
    ]) );
  SetAction(5, ({
      "!speak Speak with me if you desire residency in Glimmerdin.",
      "!speak Under Kylin, all are welcome.",
    }) );
  SetMorality(200);
  SetCombatAction(10, ({
     "!cast wall of force",
     "!cast touch of death",
     "!cast smite",    
    }) );
}
