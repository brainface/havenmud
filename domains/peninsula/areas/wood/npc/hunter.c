/* 5/03 Libitina  / hunter for newbie area / wooded vale  */


#include <lib.h>
#include "../wood.h"
inherit LIB_SENTIENT;
static void create() {
    sentient::create();
    SetKeyName("hunter");
    SetShort("an old hunter");
    SetId( ({"hunter"}) );
    SetAdjectives( ({"man", "old"}) );
    SetRace("human");
    SetGender("male");
    SetClass("ranger");
    SetLevel(3);
    RemoveLanguage("Human");
    SetLanguage("Imperial", 100, 1);
    SetLong("Grey hair pokes out of a crooked hat and frames a rather old, "
      			"leathered face. His tanned skin bears many scars from him "	
      			"past hunting adventures. He stoops slightly, but moves "
      			"silently through the forest."
    				);
   
    SetWanderPath( ({ 
    	"go northwest", 
    	"go south", 
    	"go south", 
			"go northeast"
			}) );
    SetWander(10);
    SetWanderRecurse(1);
    SetLimit(1);
    SetInventory( ([
			WOOD_OBJ "knife" : "wield knife",
      ]) );
    SetCurrency("imperials", 4);
    SetAction(2, ({
			"!emote turns his head at a slight noise.",
			"!emote takes a silent step forward.",
			"!emote cocks his head, listening to something.",
			"!emote looks off in the distance.",
      }) );
    SetCombatAction(2, ({
			"!emote snarls at you.",
			"!say This is my hunting ground! Find your own!",
      "!say Think you can take me, you little twerp?",
      }) );
}
