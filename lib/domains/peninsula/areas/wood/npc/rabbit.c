/* 5/03 Libitina / rabbit for newbie area / wooded vale  */


#include <lib.h>
#include "../wood.h";
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("rabbit");
    SetShort("a beautiful white rabbit");
    SetId( ({ "rabbit" }) );
    SetAdjectives( ({ "beautiful", "white" }) );
    SetRace("rodent");
  	SetClass("animal");
    SetGender("male");
    SetLevel(2);
    SetLong("White and furry, this rabbit is very cute. He has "
      "long ears that stand straight up, and dark red eyes. "
      "His size is quite average for a rabbit, and is fur "
      "looks almost too perfect.");
    SetAction(2, ({
			"!emote hops around.",
			"!emote wiggles his nose.",
      }) );
    SetCombatAction(2, ({
			"!emote screams at you fiercely.",
			"!emote bites at you with his sharp teeth.",
			"!emote darts around quickly."
      }) );
}
varargs int eventDie(object killer) {
object pelt;
pelt = new(WOOD_OBJ "rabpelt.c");
pelt->eventMove(this_object());
npc::eventDie(killer);
}
