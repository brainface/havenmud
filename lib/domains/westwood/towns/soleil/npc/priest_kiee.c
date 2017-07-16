#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Kiee");
   SetShort("Kiee, High Priest of Eclat");
   SetId( ({ "kiee","priest","eclat",}) );
   SetAdjectives( ({ "high","priest","of","eclatish","kiee"}) );
   SetLong("Soft white fur covers the ceremonious Kiee, who has "
           "a reverent look upon her face, as if communicating with "
           "her Goddess, Amelia.  A peaceful sense of power radiates "
           "out of her.");
   SetGender("female");
   SetRace("muezzin");
   SetClass("priest");
   SetUniqueSkills( ([
                  ]) );
   SetLevel(45);
   SetSpellBook( ([
                    "regenerate limb" : 100,
                    "sanctify" : 100,
                    "empower" : 100,
               ]) );
   SetTown("Soleil");
   SetReligion("Eclat","Eclat");
   SetPlayerTitles( ([
                       "newbie"      : "the Bringer of Goodness",
                       "mortal"      : "the Virtuous Soleil Chaplain",
                       "hm"          : "the Benevolent and Devout Priest",
                       "legend"      : "the Amiable and Pious Eclat",
                       "avatar"      : "the Sacred Priest of Eclat",
                       "monk"        : "the Strong Eclatish Warrior",
                       "paladin"     : "the Virtuous Eclatish Paladin",
                       "evangelist"  : "the Righteous Peddlar",
                       "crusader"    : "the Mighty Proselytizer",
                  ]) );
   SetFreeEquip( ([
               ]) );
   SetMorality(1400);
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "knight","guard","Acclima","Trill","Kiee",

                  "entrance guard","Iuvo","Fossis","Miserum" }) );
   SetAction(2, ({ "!cast sphere of happiness","!cast guardian "
                   "angel" }) );
   SetCombatAction(75, ({ "!cast sanctify", }) );
}
