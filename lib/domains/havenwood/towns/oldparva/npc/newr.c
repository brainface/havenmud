#include <lib.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetTown("Parva");
   SetProperty("parvanoleave",1);
   SetKeyName("Arpachshad");
   SetShort("Arpachshad, the Ranger of Parva");
   SetId( ({ "arpachshad","ranger","parva" }) );
   SetAdjectives( ({ "arpachshad","ranger","parva","parvan","of","the" }) );
   SetLong("Arpachshad has deeply tanned skin and strong muscles.  "
           "His keen blue eyes search the world around him, seeking "
           "out the hidden.  He looks like he would be willing to help "
           "someone without a class become an evil ranger.");
   SetGender("male");
   SetRace("human");
   SetClass("ranger");
   SetLevel(50);
   SetFreeEquip( ([
                    "/std/weapon/projectile/bow_long_newbie" : 1,
               ]) );
   SetPlayerTitles( ([
                       "newbie" : "the Scout of the Forest",
                       "mortal" : "the Shadow in the Woods",
                       "hm" : "the Evil Forester",
                       "legend" : "the Corrupt and Sinsister Woodlander",
                       "avatar" : "the Malign HavenWood Creature",
                       "nomad" : "the Base Brute of the HavenWood",
                  ]) );
   SetMorality(-1000);
   SetAction(2,({ "!grin evilly","!emote smiles with a sinsister twinkle "
                  "in his deep blue eyes.","!say The forest makes a good "
                  "hiding place after having stolen something.","!say "
                  "I love the HavenWood, and protect it dearly, but "
                  "I find it important to use the fruits of the forest "
                  "as well as keep the forest around.","!say I can teach "
                  "those without a class to be rangers, and the best "
                  "kind there is!  Just ask me to join rangers." }) );
  SetCombatAction(40, ({ "!slice","!slice","!slice","!cast thicken "
                         "skin","!cast enhanced natural shield",
                         "!cast freeze","!cast heat","!cast summon "
                         "animal","!say Get out of Parva!  You "
                         "blasphemous scum!" }) );
   SetTaughtSpheres( ({ "natural evokation","natural","natural healing" }) );
   SetFriends( ({"citizen","minkin","pecunia","drunk","arpachshad"}) );
   SetSpellBook( ([
                    "thicken skin" : 100,
                    "enhanced natural shield" : 100,
                    "freeze" : 100,
                    "heat" : 100,
                    "summon animal" : 100,
               ]) );
}
