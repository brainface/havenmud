#include <lib.h>
#include "../area.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("skeleton");
  SetShort("a decayed skeleton");
  SetRace("human");
  SetUndead(1);
  SetUndeadType("skeleton");
  RemoveLanguage("Human");
  SetClass("fighter"); 
  SetLevel(4);
  SetMorality(-300);
  SetNoCorpse(1);
  SetInventory( ([
    AREA_OBJ "sword" : "wield sword",
    ]) );
  SetLong("This decayed skeleton still clings to a form of \"life\", "
          "although a hideous life by any standards. It shuffles about "
          "for eternity in vain, with no mind left to appreciate itself.");
  SetId( ({ "skeleton" }) );
  SetAdjectives( ({ "decayed" }) );
  SetAction(10, ({
    "!emote shuffles about.",
    "A strange red gleam faintly sparkles from the eyesockets of the skeleton.",
    }) );
 
}
