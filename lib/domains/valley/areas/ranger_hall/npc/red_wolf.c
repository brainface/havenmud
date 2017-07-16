//Red Wolf
//Davantalus 20040721
#include <lib.h>
#include "../ranger_hall.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("red wolf");
  SetId( ({ "wolf", "red wolf" }) );
  SetAdjectives( ({ "red" }) );
  SetShort("a red wolf");
  SetLong(
    	"This red wolf looks like a mix of grey wolf and coyote. "
    	"It is mostly brown with red shading around its ears, legs, "
    	"and muzzle. Its eyes appear quite intelligent, even while "
    	"it's mouth hangs open, tongue lolling. It looks ready to "
    	"protect its own if the need arose."
  		);
  SetRace("dog");
  SetClass("animal");
  SetLevel(3+random(2));
  SetMorality(20);
  SetGender("female");
  SetFriends( ({ "wolf" }) );
  SetCombatAction(random(15), ({
    	"!emote snarls fearsomely!",
    	"!emote howls!"
    	}) );
  SetAction(random(3), ({ 
    	"!emote howls, nose to the sky!" 
    	}) );
    SetDie("The red wolf whimpers as it dies.");
 }

varargs int eventDie(object killer) {
    object pelt;
    pelt = new(RH_OBJ "wolf_pelt.c");
    pelt->eventMove(this_object());
    npc::eventDie(killer);
}
