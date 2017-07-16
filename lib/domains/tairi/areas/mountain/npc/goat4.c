//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("she goat");
  SetId( ( "goat" ) );
  SetAdjectives( ({"she", "mountain"}) );
  SetShort("a mountain she goat");
  SetLong(
    "This is a feminine goat, who dwells in the mountains "
    "with her kin. She keeps her brown fur tidy and even "
    "polishes her hooves and stubby gray horns on boulders "
    "from time to time. The male goats simply cannot get "
    "enough of her.");            
  SetRace("horse", "goat");
  SetClass("animal");
  SetGender("female");
  SetLevel(10);
  SetMorality(0);
  SetAction(6, ({ "!bah seductively", "!hop adorably"}));
}
