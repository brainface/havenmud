#include <lib.h>
#include "parva.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetTown("Parva");
   SetProperty("parvanoleave",1);
   SetMorality(-150);
   SetKeyName("Pecunia");
   SetShort("Pecunia, a young barmaid");
   SetId( ({ "pecunia","barmaid","maid" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("Pecunia is a cute young barmaid who works for Minkin.  "
           "Her hair is a pretty blond color, and is cropped close "
           "her head in a nice style.  She smiles sweetly and "
            "innocently at the world.  She might have something to "
                "teach, if one were interested in the right skills.");
   SetClass("rogue");
   SetGender("female");
   SetRace("human");
   SetLevel(10);
   SetInventory( ([
                    P_OBJ + "/shirt_pec" : "wear shirt",
                    P_OBJ + "/skirt_pec" : "wear skirt",
                    P_OBJ + "/knife_pec" : "wield knife in right hand",
               ]) );
   SetAction(1,({ "!emote smiles sweetly.","!emote looks innocent.",
                  "!emote brings an order to a customer.",
                  "!giggle","!smile","!beam" }) );
   SetCombatAction(2,({ "!say Hey!  Stop that!","!say Get away from "
                        "me!","!say Someone help me!","!say I lead "
                        "the rogues in this town, you can't kill "
                        "me!","!shout Help me!","!say Help!  Help!",
                        "!say Get out of here!","!say Someone, "
                        "please, I need help!" }) );
   SetFreeEquip( ([
                    P_OBJ + "/freeknife" : 2,
               ]) );
   SetPlayerTitles( ([
                       "newbie" : "the Novice Lurker",
                       "mortal" : "the Lurker in the Shadows",
                       "hm"     : "the Master Cutpurse",
                       "legend" : "the Master Rogue",
                       "avatar" : "the Great Walker of the Crooked Path",
                       "necromancer" : "the Soul Stealer",
                       "merchant" : "the Swindler",
                       "diviner" : "the Seer Among the Shadows",
                       "fighter" : "the Scheming Combatant",
                       "evoker" : "the Vagabond Mage",
                  ]) );
   SetFriends( ({"minkin","citizen","drunk","arpachshad","pecunia"}) );
}
