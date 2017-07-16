//Illura@haven
//Nov 2010
#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../oil.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("sturdy goblin worker");
  SetShort("a sturdy goblin worker");
  SetId( ({ "goblin", "worker" }) );
  SetAdjectives( ({ "goblin", "worker" }) );
  SetRace("goblin");
  SetBaseLanguage("Gobyshkin");
  SetClass("fighter");
  SetLevel(50);
  SetLong(
    "This factory worker lives a life of industry. His days are filled "
    "with heaving slag and fixing the nuts and bolts of the factory. "
    "He wears a tired expression on his furrowed brow, which is "
    "speckled with oil."
    );
  SetGender("male");
  SetCurrency("rounds", random(100));
  SetInventory( ([
    OIL_OBJ "wrench" : "wield wrench",
    ]) );
  SetAction(20, ({
    "!say You don't work here, do you?",
    "!say The faster we work, the sooner we get out of here, lads.",
    "!emote bangs his wrench on something with purpose.",
    "!say This place really stinks worse than Ungkh!",
    "!say Work, work, work. They never let us have fun.",
    "!emote wipes his brow and gets back to toiling."
  }) );
  SetCombatAction(20, ({
    "!emote comes at you viciously with his wrench."
    "!say Get back to work!",
    "!say You're going to get me in trouble!"
    }) );
    
}

