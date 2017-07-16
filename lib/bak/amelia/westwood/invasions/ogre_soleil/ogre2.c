#include <lib.h>
inherit LIB_INVADER;
#define pirdir "/domains/westwood/invasions/ogre_soleil"

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
   SetFriends("urgesh shaman");
   SetShort("a mean ogre");
   SetId( ({ "ogre" }) );
   SetAdjectives( ({ "mean" }) );
   SetLong("This ogre is scowling underneath the shaggy beard "
           "that covers his face.  Leaves and twigs cling to "
           "all the hair on him, anywhere they can possibly find "
           "purchase.  The ogre is just a big dumb brute with a "
           "lot of strength and size.");
   SetRace("ogre");
   SetGender("male");
   SetClass("valkyr");
   SetSkill("blunt attack",1,1);
   SetSkill("blunt defense",1,1);
   SetLevel(25);
   SetInventory( ([
                    pirdir + "/tunic" : "wear tunic",
                    pirdir + "/pants" : "wear pants",
                    pirdir + "/club" : "wield club in right hand",
               ]) );
   SetAction(6, ({ "!say Me kill!","!say Die fuzzy!",
                   "!say Kill forest fuzzies!","!say "
                   "Smash it!","!say Me find thing to die",
                   "!attack first citizen","!attack first muezzin",
                   "!say Me bash fuzzy heads!" }));
   SetCombatAction(10, ({ "!say die!","!say Me kill fuzzy!",
                          "!say Smash!","!say Bang!",
                          "!say You hurt now!","!say You die "
                          "soon!","!say Me hurt you!",
                          "!say Die fuzzies!","!say Bash fuzzy!",
                          "!thump","!thump","!thump" }) );
   SetCurrency("skins",20+random(5));
   SetWanderSpeed(3);
   SetWanderPath(wanderpathlist);
   SetMorality(-2000);
   SetReligion("Urgesh","Urgesh");
}
