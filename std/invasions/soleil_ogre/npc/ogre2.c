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
  SetShort("a mean ogre");
  SetId( ({ "ogre", "ogre_inv" }) );
  SetAdjectives( ({ "mean" }) );
  SetLong(
    "This ogre is scowling underneath the shaggy beard "
    "that covers his face. Leaves and twigs cling to "
    "all the hair on him, anywhere they can possibly find "
    "purchase. The ogre is just a big dumb brute with a "
    "lot of strength and size."
  );
  SetRace("ogre");
  RemoveLanguage("Shangtai");
  SetLanguage("Uruk", 100, 1);
  SetReligion("Kuthar","Kuthar");
  SetGender("male");
  SetClass("fighter");
  SetLevel(25);
  SetMorality(-200);
  SetInventory( ([
    OIS_OBJ + "tunic" : "wear tunic",
    OIS_OBJ + "pants" : "wear pants",
    OIS_OBJ + "club" : "wield club in right hand",
  ]) );
  SetCurrency("skins",20+random(5));
  SetAction(6, ({ 
    "!say Me kill!",
    "!yell Die fuzzy!",
    "!say Kill forest fuzzies!",
    "!say Smash it!",
    "!say Me find thing to die",
    "!attack first citizen",
    "!attack first muezzin",
    "!say Me bash fuzzy heads!" 
  }));
  SetCombatAction(10, ({ 
    "!say die!",
    "!say Me kill fuzzy!",
    "!say Smash!",
    "!say You hurt now!",
    "!say You die soon!",
    "!say Me hurt you!",
    "!say Die fuzzies!",
    "!say Bash fuzzy!",
    "!thump",
  }) );
  SetFriends( ({ "ogre_inv" }) );
  SetWanderSpeed(3);
  SetWanderPath(wanderpathlist);
}
