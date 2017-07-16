/*  Duhoc - '99  mayor of Glimmerdin */
#include <lib.h>
#include "../glim.h"
inherit LIB_MAYOR;

static void create() {
  ::create();
  SetShort("Gracchus the Magistrate of Glimmerdin");
  SetId( ({ "gracchus", "magistrate" }) );
  SetAdjectives( ({ "magistrate" }) );
  SetKeyName("gracchus");
  SetLong("This is the main magistrate of the dwarven town "
     "of Glimmerdin.  If one pays the required taxes, he will permit "
     "even non-dwarven folk residency.  He seems quite young, "
     "and was appointed through the military.");
  SetGender("male");
  SetRace("dwarf");
  SetReligion("Kylin", "Kylin");
  SetCurrency( ([
      "nuggets" : random(50),
    ]) );
  SetFriends( ({"tembeg", "rancor", "raal", "rallor", 
    "tabitha", "dwarf", "civak", "guard", "patrol", 
    "samik", "gracchus", "eredos", "dorscha", "bralor"}) );
  SetLocalCurrency("nuggets");
  SetTax(10);
  SetTown("Glimmerdin");
  SetClass("fighter");
  SetClass("cleric");
  SetSkill("evokation", GetLevel()*3, 1);
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
