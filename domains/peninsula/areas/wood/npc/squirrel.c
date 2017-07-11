/*  5/03 Libitina / squirrel for newbie area / wooded vale  */


#include <lib.h>
#include "../wood.h";
inherit LIB_NPC;
static void create() {
    npc::create();
    SetKeyName("squirrel");
    SetShort("a brown squirrel");
    SetId( ({"squirrel"}) );
    SetAdjectives( ({ "brown" }) );
    SetRace("rodent");
    SetGender("female");
    SetClass("animal");
    SetLevel(1);
    SetLong("Round black eyes look out from a cute face of brown fur. "
      "She flicks her tail back and forth while chittering a "
      "warning. When she sits up on her hind feet, it's obvious "
      "why she's so distressed. She must have young to nurse and "
      "protect.");
    SetAction(2, ({
			"!emote chitters angrily.",
			"!emote runs back and forth, quite distressed."
      }) );
    SetCombatAction(2, ({
			"!emote chitters and screams at you.",
			"!emote bites at you with her sharp teeth.",
			"!emote claws at you."
      }) );
   
}
varargs int eventDie(object killer) {
    object pelt;
    pelt = new(WOOD_OBJ "sqpelt.c");
    pelt->eventMove(this_object());
    npc::eventDie(killer);
}
