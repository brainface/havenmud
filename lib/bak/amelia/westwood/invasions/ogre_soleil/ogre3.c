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
   SetShort("a confused ogre");
   SetId( ({ "ogre" }) );
   SetAdjectives( ({ "confused" }) );
   SetLong("A confused look is formed in the dumb, oversized features "
           "of this ogre's face.  His large eye brows droop sadly "
           "of his eyes, and his mouth pouts.  He is still large "
           "and dangerous, however, and will probably be more "
           "likely to hurt another in his confusion.");
   SetRace("ogre");
   SetGender("male");
   SetClass("valkyr");
   SetSkill("blunt attack",1,1);
   SetSkill("blunt defense",1,1);
   SetLevel(30);
   SetInventory( ([
                    pirdir + "/tunic" : "wear tunic",
                    pirdir + "/pants" : "wear pants",
                    pirdir + "/club" : "wield club in right hand",
               ]) );
   SetAction(6, ({ "!emote looks dumb.","!emote looks confused.",
                   "!emote 's mouth hangs open stupidly.", 
                   "!attack firstcitizen","!attack first muezzin" }));
   SetCombatAction(10, ({ "!say Smash!","!say Bang!",
                          "!thump","!thump","!thump" }) );
   SetCurrency("skins",5+random(5));
   SetWanderSpeed(3);
   SetWanderPath(wanderpathlist);
   SetMorality(-2000);
   SetReligion("Urgesh","Urgesh");
}
