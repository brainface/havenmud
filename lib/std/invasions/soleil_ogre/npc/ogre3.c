// Ogre invasion of Soleil
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../ois.h"
inherit LIB_INVADER;

static void create() {
   string array wanderpathlist = ({
                          ({ "attack first guard" }),
                          ({ "attack second guard" }),
                          ({ "go up","enter townhall",
                             "attack fossis" }),
                          ({ "go up","enter townhall",
                             "attack aegri" }),
                          ({ "go up","enter townhall",
                             "attack miserum" }),
                          ({ "go up","go south","go down",
                             "attack foret" }),
                          ({ "go up","go south","go down",
                             "attack nascima" }),
                          ({ "go up","go south","go down",
                             "go southwest","attack oppugno" }),
                          ({ "go up","go south","go down",
                             "enter inn","attack barkeep" }),
                          ({ "go up","go south","go southeast"
                             "attack acclima" }),
                          ({ "go up","go south","go southeast"
                             "go up","attack sorgan" }),
                          ({ "go up","go south","go southeast"
                             "go up","attack dulcae" }),
                          ({ "go up","go south","attack tia" }),
                          ({ "go up","go south","go southeast",
                             "go east","attack kiee" }),
                          ({ "go up" })
                       })[random(15)];

  invader::create();
  SetKeyName("ogre");
  SetShort("a confused ogre");
  SetId( ({ "ogre", "ogre_inv" }) );
  SetAdjectives( ({ "confused" }) );
  SetLong(
    "A confused look is formed in the dumb, oversized features "
    "of this ogre's face. His large eyebrows droop sadly "
    "over his eyes, and his mouth pouts. He is still large "
    "and dangerous, however, and will probably be more "
    "likely to hurt another in his confusion."
  );
  SetRace("ogre");
  RemoveLanguage("Shangtai");
  SetLanguage("Uruk", 100, 1);
  SetGender("male");
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(30);
  SetReligion("Kuthar","Kuthar");
  SetMorality(-200);
  SetInventory( ([
    OIS_OBJ + "tunic" : "wear tunic",
    OIS_OBJ + "pants" : "wear pants",
    OIS_OBJ + "club"  : "wield club in right hand",
  ]) );
  SetCurrency("skins",5+random(5));
  SetAction(6, ({ 
    "!emote looks dumb.",
    "!emote looks confused.",
    "Ogre's mouth hangs open stupidly.", 
    "!attack first citizen",
    "!attack first muezzin" 
  }));
  SetCombatAction(10, ({ 
    "!say Smash!",
  }) );
  SetFriends( ({ "ogre_inv" }) );
  SetWanderSpeed(3);
  SetWanderPath(wanderpathlist);
}
