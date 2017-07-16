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
   SetShort("a large ogre");
   SetId( ({ "ogre" }) );
   SetAdjectives( ({ "large" }) );
   SetLong("The large ogre is a Urgesh that is a full two feet "
           "above normal ogre hieght.  He has huge muscles and "
           "looks very strong.  His facial features are big and "
           "dumb; his ears and nose are too big, his dark eyebrows "
           "are shaggy, and his mouth hangs open in a loose-lipped "
           "drool.  His hair is in a shaggy mop on his had that "
           "hasn't been tamed for as long as this ogre has lived.  "
           "Little sticks and leaves cling to his beard and the "
           "rest of him is covered in dirt.");
   SetStat("strength",130,1);
   SetStat("durability",100,1);
   SetRace("ogre");
   SetGender("male");
   SetClass("barbarian");
   SetLevel(25);
   SetInventory( ([
                    pirdir + "/tunic" : "wear tunic",
                    pirdir + "/pants" : "wear pants",
               ]) );
   SetAction(6, ({ "!say Me kill!","!say Die fuzzy!",
                   "!say Kill forest fuzzies!","!say "
                   "Smash it!","!say Me find thing to die",
                   "!attack first citizen","!attack first muezzin" }));
   SetCombatAction(10, ({ "!say die!","!say Me kill fuzzy!",
                          "!say Smash!","!say Bang!",
                          "!say You hurt now!","!say You die "
                          "soon!","!say Me hurt you!",
                          "!say Die fuzzies!" }) );
   SetCurrency("skins",10+random(5));
   SetWanderSpeed(3);
   SetWanderPath(wanderpathlist);
   SetMorality(-2000);
   SetReligion("Urgesh","Urgesh");
}
