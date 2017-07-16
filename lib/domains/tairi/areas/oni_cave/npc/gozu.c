
#include <lib.h>
#include "../area.h"

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("oni");
  SetShort("a go-zu oni");
  SetId( ({ "oni" }) );
  SetAdjectives( ({ "gozu","go zu" }) );
  SetRace("devil","oni");
  SetClass("fighter");
  SetLevel(6 + random(5) );
  SetGender("male");
  SetLong("This oni is about nine feet tall and looks very strong with corded muscles "
    "in his arms.  He has the head of a bull, with a large snout, small ears, and two "
    "long horns.  His skin is dark orange.");
  SetCurrency( ([
    "koken" : random(350),
    ]) );
  SetInventory( ([
    OBJ + "greatsword" : "wield sword",
    ]) );
  SetAction(3, ({
    "!mutter",
    "!growl",
    }) );
  SetCombatStyleLevel("sword slinging", 40);
  SetMorality(-75); // torak 2013 oni are demons
  SetCombatStyle("sword slinging");
}
