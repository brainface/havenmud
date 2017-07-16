#include <lib.h>
#include "../ungkh.h"
inherit LIB_NPC;

static void create() {

  npc::create();
  SetKeyName("farmer");
  SetAdjectives( ({
    "dirty","ugly"
    }) );
  SetId( ({
    "goblin","farmer","citizen"
    }) );
  SetShort("a pig farmer");
  SetLong("Smelly, small and stupid, this goblin "
          "breeds pig live stock for Ungkh.  "
          "An odd look crosses his face as he keeps "
          "an eye on his pigs.");
  SetRace("goblin");
  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);
  SetClass("rogue");
  SetLevel(5);
  SetGender("male");
  SetInventory( ([
    U_OBJ + "gob_knife" : "wield knife",
    U_OBJ + "gob_loincloth" : "wear loincloth",
    ]) );
  SetFriends( ({"goblin"}) );
  SetAction(5, ({ "!emote runs after a pig.",
                  "!emote trips and falls in the mud.",
                  "!say no run from me stupid pig.",
                  }) );
  SetMorality(-50);
  SetCurrency("skins", random(20));
  SetDie("The goblin squeaks like a pig.");
}
