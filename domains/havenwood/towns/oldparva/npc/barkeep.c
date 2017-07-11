#include <lib.h>
#include "parva.h"
inherit LIB_BARKEEP;

static void create() {
   barkeep::create();
   SetKeyName("Minkin");
   SetShort("Minkin, the owner of the Inn");
   SetId( ({ "minkin","owner","inn" }) );
   SetProperty("parvanoleave",1);
   SetTown("Parva");
   SetAdjectives( ({ "minkin","of","the","owner" }) );
   SetLong("Minkin is a fat halfling with milky blue-green "
           "eyes.  His chubby fingers twitch constantly, "
           "and the smell of the sea seems to make him "
           "nervous.  He is a shrewd business-owner and "
           "his inn has become quite a success.");
   SetGender("male");
   SetRace("halfling");
   SetClass("merchant");
   SetLevel(35);
   SetSkill("melee combat",7,1);
   SetLocalCurrency("oros");
   SetMenuItems( ([
                    "beer" : P_OBJ + "/beer",
                    "matelote" : P_OBJ + "/matelote",
                    "calamari" : P_OBJ + "/calamari",
                    "lomi-lomi" : P_OBJ + "/lomi",
                    "fillet" : P_OBJ + "/fillet",
                    "clams" : P_OBJ + "/clams",
               ]) );
   SetMorality(10);
   SetInventory( ([
                    P_OBJ + "/shirt_barkeep" : "wear shirt",
                    P_OBJ + "/pants_barkeep" : "wear pants",
                    P_OBJ + "/boots_barkeep" : "wear boots",
                    P_OBJ + "/belt_barkeep"  : "wear belt",
               ]) );
   SetAction(1, ({ "!speak I have great calamari!  You ever "
                    "tried it?  I buy my squid fresh from " 
                    "next door, and then cook and prepare "
                    "it for you all!","!speak My matelote "
                    "is simply scrumptious.  The red wine "
                    "sauce--you've never tasted better, I "
                    "gaurentee it!","!speak Lomi-lomi "
                    "is a traditional dish in some of those "
                    "islands way off in the ocean.  I learned "
                    "it from one of the sailors.  Only the "
                    "freshest!","!speak I pick up the best of "
                    "all the king salmon, from next door, and "
                    "and then fillet it for you all and put "
                    "a tasty sauce on top!  It's delicious!",
                    "!speak Buy some of my beer!  Comes in a good, "
                    "strong mug for a good, strong brew!",
                    "!speak I steam clams fresh from next door, "
                    "and I never run out like any restaurant "
                    "in the rest of Kailie, cause my source is "
                    "just next door, and we've a wharf full of "
                    "boats just waiting to sell us more!",
                    "!speak You'll never get sick from my foods.  "
                    "The raw food next door, though, if you don't "
                    "know how to pick it, can be dangerous." }) );
   SetCombatAction(10, ({ "!yell Help!  Help me!","!speak "
                    "What are you trying to do, you jerk!",
                    "!speak What is the meaning of this?  I'm "
                    "a decent, law-abiding citizen!","!speak "
                    "I never should have moved so near the ocean!",
                    "!speak Help!  Heeelllppp!!!","!yell Help me!  "
                    "I'm being attacked!" }) );
   SetLanguage("Enlan",100,1);
   RemoveLanguage("Eltherian");
   SetFriends( ({"minkin","drunk","pecunia","arpachshad","citizen"}) );
}


/* Approved by Ukla on Mon Oct 19 02:57:31 1998. */
/* Modified to add friends by Gabriel@Haven      */
