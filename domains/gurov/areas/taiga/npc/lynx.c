//Illura@Haven
//lynx
#include <lib.h>
#include "../taiga.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lynx");
  SetId( ({ "lynx" }) );
  SetAdjectives( ({ "arctic" }) );
  SetShort("an arctic lynx");
  SetLong(
    "This is an arctic lynx, white-furred from nose to tail, "
    "except a buttercream tinge to his snout and ear tufts. "
    "His retractable claws measure several deadly inches, "
    "and some of his teeth hang out of the front of his mouth "
    "like dual sabers, ready to rend the flesh of any prey."
    );
  SetGender("male");
  SetClass("animal");
  SetLevel(25);
  SetRace("cat");
    SetAction(5, ({
    "!emote licks a five-clawed paw nonchalantly.",
    "!emote growls deep in his throat.",
    "!emote wiggles his shoulders, as if about to spring.",
                })  );
  SetCombatAction(10, ({
    "The lynx takes a swipe at you.",
    "The lynx roars!",
    }) );
}
