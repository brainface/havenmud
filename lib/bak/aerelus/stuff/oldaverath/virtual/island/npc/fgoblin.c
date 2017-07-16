#include <lib.h>
#include <damage_types.h>
#include <domains.h>

inherit LIB_NPC;

static void create() {
  ::create();

  SetKeyName("fat goblin");
  SetId( ({"goblin"}) );
  SetAdjectives( ({"fat"}) );
  SetShort("a fat goblin");
  SetLong("This goblin looks as if it hasn't missed a meal "
     "in quite awhile. It stands about 4 feet tall and is "
     "extremely fat. It's eyes hungrily look you over for "
     "it's next meal.");
  SetRace("goblin");
  SetClass("fighter");
  SetGender("male");
  SetLevel(8);
  AddCurrency("ducats", random(10));
  SetCombatAction(3, ({
     "!emote spits in your face.",
     "!emote screams loudly and runs straight for you.",
    }) );
  SetAction(3, ({
     "!emote wombles slowly around the room.",
     "!emote grins toothlessly at you.",
    }) );
  SetInventory( ([
     AVERATH_OBJ "twohandsword" : "wield sword",
     AVERATH_OBJ "tlarmour" : "wear armour",
     ]) );
  SetEncounter(0);
  SetMorality(-20);
}
