// A Muezzin Fisherbear?
// Urien@Haven 06JUN2023

#include <lib.h>
#include "../world.h"
inherit LIB_BARKEEP;

static void create() {
 ::create();
 SetKeyName("merchant");
 SetShort("a muezzin fisher merchant");
 SetId( ({ "muezzin","merchant","fisher"}) );
 SetAdjectives( ({ "fisher", "merchant" }) );
 SetRace("muezzin");
 SetBaseLanguage("Oiseau");
 SetGender("male");
 SetClass("merchant");
 SetLimit(1);
 SetLevel(random(10)+10);
 SetCurrency("cuicui", random(50)+5);
 SetWander(39);
 SetLimit(1); 
 SetLong(
    "A rather stout aged muezzin fisher with short and shaggy hair "
    "along his exposed limbs. He has a welcoming appearance despite "
    "looking like he prioritizes work over hygeine. His dim yellow "
    "eyes hide behind the flat pressed snout fur and brown triangle "
    "nose. His garb itself appear to have various mud stains along "
    "his fisher tools and makeshift merchant uniform."
  );
 SetAction(5, ({
    "!say I have fish for sale if you desire.",
    "!yell Delicious fresh fish hand picked daily!",
    "!say Expand your knowledge on Soliel cuisine for a small price.",
    "!gestures you to browse his wares",
    "!smile",
    "!beam",
  }) );
 SetMenuItems( ([
    "bass"   : WORLD_OBJ  "fish_fbss",
    ]) );
 SetLocalCurrency("cuicui");
 SetCurrency("cuicui",10);
 }
