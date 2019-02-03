// probably duuk coded
// mahkefel 2018: made kylin, removed lolwisdom stat
// made healers heal anyone from same religion, town, race, or good rep.

#include <lib.h>
#include "../haven.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("quelthon");
  SetShort("Quelthon the Mendicant of Kylin");
  SetId( ({ "quelthon", "mendicant", "healer" }) );
  SetAdjectives( ({ "quelthon", "healer" }) );
  SetRace("elf");
  SetGender("male");
  SetClass("priest");
  SetSkill("fire magic",1,2);
  SetLevel(90);
  SetReligion("Kylin");
  SetCurrency("imperials", 10);
  SetLong("Quelthon is the local healer.  His abilities range "
          "from both the mundane healing of minor wounds to the full "
          "resurrection of the dead. Of course, he reserves the right "
          "to be richly compensated for his services.");
  SetLocalCurrency("imperials");
  SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
  SetTown("Haven");
  SetMorality(1200);
  SetSpellBook( ([
        "wall of force" : 100,
        "kylin touch"   : 100,
        "smite"         : 100,
        ]) );
  SetCombatAction(40, ({
        "!cast wall of force",
        "!cast kylin touch",
        "!cast smite",
        }) );
  SetLimit(1);
}

