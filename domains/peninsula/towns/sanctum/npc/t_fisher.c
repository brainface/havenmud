#include <lib.h>
#include "../rome.h"
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("martello");
  SetShort("Martello the Master Fisherman");
  SetRace("human");
  SetGender("male");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetId( ({ "martello", "master", "fisher", "fisherman" }) );
  SetAdjectives( ({ "master", }) );
  SetTown("Sanctum");
  SetTrainingSkills( ({ 
     "armour smithing", 
     "natural working",
     "weapon smithing", 
     "metal working",
     "textile working", 
     "leather working",
     "fishing", 
     "knife combat", 
     "navigation", 
    "sailing",
     "swimming", 
     "skinning",
    }) );
  SetLevel(1);
  SetLong("Martello is a man of advancing years. His main joy in life is "
          "standing along the wharf in Sanctum, quietly fishing his life "
          "away. He would be willing to teach anyone that wanted to learn.");
  SetAction(4, ({
    "!fish with pole",
    "!speak Here... fishy fishy fishy...",
    "!speak I'd teach you if you asked me.",
    "!speak So.  Fine day for fishing, yes?",
    }) );
  SetLimit(1);
  SetInventory( ([
    STD_FISH "pole" : "wield pole",
    ]) );
}
