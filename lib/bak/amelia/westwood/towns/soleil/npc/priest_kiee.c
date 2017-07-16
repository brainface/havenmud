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
           "her God, Gabriel.  A peaceful sense of power radiates "
           "out of her.");
   SetGender("female");
   SetRace("muezzin");
   SetClass("cleric");
   SetNoJoin(1);
   SetUniqueSkills( ([
				"healing" : 1,
				"melee attack" : 1,
				"enchantment" : 1,
			]) );
   SetLevel(45);
   SetSpellBook( ([
                    "regenerate limb" : 100,
                    "sanctify" : 100,
                    "guardian angel" : 100,
                    "empower" : 100,
                    "awakening" : 100,
                    "create detox potion" : 100,
                    "divine morality" : 100,
                    "divine good" : 100,
                    "divine evil" : 100,
                    "harm evil" : 100,
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
/*
                    S_OBJ + "/ironfist_newbie" : 1,
*/
               ]) );
   SetMorality(1400);
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Miserum" }) );
   SetAction(2, ({ "!cast sphere of happiness","!cast guardian "
                   "angel" }) );
   SetCombatAction(75, ({ "!cast sanctify","!cast harm evil", }) );
}
