#include <lib.h>
#include "../parva.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetTown("Parva");
   SetMorality(-150);
   SetKeyName("Pecunia");
   SetShort("Pecunia the Barmaid");
   SetId( ({ "pecunia", "barmaid", "maid" }) );
   SetAdjectives( ({ "bar" }) );
   SetLong("Pecunia is a cute young barmaid who works for Minkin. "
           "Her hair is a pretty blond color, and is cropped close "
           "her head in a nice style.  She smiles sweetly and "
           "innocently at the world.  She might have something to "
           "teach, if one were interested in rogue skills.");
   SetClass("rogue");
   SetGender("female");
   SetRace("human");
   SetLevel(10);
   SetInventory( ([
     PARVA_OBJ "rogue_knife" : "wield knife",
     ]) );
   SetAction(1,({ 
      "!say If someone asked, I might know something about rogues.",
      "Pecunia tosses a knife into the air and back.",
       }) );
   SetCombatAction(2,({ 
   		"!say Hey!  Stop that!",
   		"!say Get away from me!",
   		"!say Someone help me!",
   		"!say I lead the rogues in this town, you can't kill me!",
   		"!shout Help me!","!say Help!  Help!",
      "!say Get out of here!",
      "!say Someone, please, I need help!" 
      }) );
   SetFreeEquip( ([
     PARVA_OBJ "rogue_freeknife" : 2,
     ]) );
   SetPlayerTitles( ([
     "newbie" : "the Shadowy Lurker",
     "mortal" : "the Night Runner",
     "hm"     : "the Silent Mover",
     "legend" : "the Master of Thieves",
     "avatar" : "the Great Walker of the Crooked Path",
     "necromancer" : "the Soul Stealer",
     "merchant" : "the Swindler",
     "fighter" : "the Scheming Combatant",
     "evoker"  : "the Vagabond Mage",
     ]) );
   SetFriends( ({"minkin","citizen","drunk","arpachshad","pecunia"}) );
}
