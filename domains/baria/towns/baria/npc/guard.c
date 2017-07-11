//
//  A guard for the village
//  kyla 11-2-97
//  Modified by Rhakz - Angel Cazares
//  Date: 10/14/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("guard");
  SetId( ({ "guard", "member" }) );
  SetAdjectives( ({ "barian" }) );
  SetShort("a member of the Barian Guard");
  SetLong(
     "This tall and intimidating individual presents himself as a "
     "guard of the town of Baria. He stands at attention, poised to "
     "strike out at the foes of the Town. His facial expression is that "
     "of calmness and confidence in his duty. "
  );
  SetMorality(30);
  SetGender(random(2) ? "male" : "female");
  SetRace("human");
  SetTown("Baria");
  SetClass("fighter");
  SetSkill("pierce combat", 1, 1);
  SetLevel(40 + random(10));
  SetInventory( ([
     BARIA_OBJ + "bronze_spear" : "wield spear",
     BARIA_OBJ + "vest" : "wear vest",
     BARIA_OBJ + "loincloth" : "wear loincloth",
  ]) );
  SetCurrency( ([
     "chits" : 10 + random(40),
  ]) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetAction(3, ({
     "!say Halt! Who goes into the town of Baria?",
     "!hmm",
     "!say Watch your step. ",
  }) );
}

