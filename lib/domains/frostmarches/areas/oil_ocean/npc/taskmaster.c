//Illura@haven
//Nov 2010
#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../oil.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("snarky goblin taskmaster");
  SetShort("a snarky goblin taskmaster");
  SetId( ({ "goblin", "taskmaster","master" }) );
  SetAdjectives( ({ "goblin", "snarky","task" }) );
  SetRace("goblin");
  SetBaseLanguage("Gobyshkin");
  SetClass("fighter");
  SetLevel(60);
  SetLong(
    "This fellow makes his living off the backs of the other factory "
    "workers. He doesn't do a whole lot of heavy lifting, but he does "
    "make sure the place runs smoothly, most of the time. The rest "
    "of his time is spent daydreaming or planting welts on the backs "
    "of the drudges around him, which he feels are most deserved."
    );
  SetGender("male");
  SetInventory( ([
    OIL_OBJ "rod" : "wield rod",
    OIL_OBJ "hat2" : "wear hat",
    ]) );
  SetCurrency("rounds", random(200));
  SetAction(20, ({
    "!say Get back to work, you."
    "!say It's all about improving the process!",
    "!emote slaps one of the workers aimlessly.",
    "!say Someday I'll earn enough to get a big tent back in Kresh.",
    "!emote pretends to do something important."
  }) );
  SetCombatAction(30, ({
    "!emote raises his rod with a baleful glare."
    "!say Get back to work!",
    "!say You're ruining my quota!"
    }) );
    
}
