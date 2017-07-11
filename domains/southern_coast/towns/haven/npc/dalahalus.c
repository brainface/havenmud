#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "haven.h"
inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Dalahalus");
  SetFriends( ({ "quelthon" }) );
  SetRace("elf");
  SetClass("priest");
  SetReligion("Kylin", "Kylin");
  SetSkill("fire magic",1,1);
  SetLevel(60);
  SetGender("male");
  SetShort("Dalahalus, High Priest of Kylin");
  SetId( ({ "dalahalus","priest" }) );
  SetLong("Dalahalus is a large elven male that has a regal \n"
          "air about him.  His very being radiates holiness.\n"
          "The air stills to permit him to talk and noise \n"
          "stops when he passes by.");
  SetUniqueSkills( ([
    ]) );
  SetTaughtSpheres( ({
    "clerical",
    "religion kylin",
    "clerical evokation",
    "clerical enchantment",
    "clerical healing",
    }) );
  SetSpellBook( ([
    "kylin touch"   : 100,
    "wall of force" : 100,
    "wrath"         : 100,
    "smite"         : 100,
    "heal"          : 100,
    "turn undead"   : 100,
     ]) );
  SetAction(20, ({
    "!speak With the grace of our Lord, we will exterminate the heathen!",
    "!cast wall of force",
    "!speak Our Lord watches over our town with diligence now.",
    "!speak Convert to the true faith, save your soul!",
    "!speak Ours is the glory of the Heavens, not the vileness of "
    "Kailie!",
    "!emote stares into the Heavens with awe on his face.",
    }) );
  SetCombatAction(16, ({
    "!cast heal",
    "!cast wall of force",
    "!cast wrath",
    "!cast kylin touch",
    }) );
  SetTown("Haven");
  SetMorality(1500);
  SetPlayerTitles( ([
     "newbie"   : "the Mendicant of Kylin",
     "mortal"   : "the Priest of Kylin",
     "hm"       : "the Templar of Kylin",
     "legend"   : "the Legendary Priest of Kylin",
     "avatar"   : "the Supreme Priest of Kylin",
     "cavalier" : "the Paladin of Kylin",
     "fighter"  : "the Monk of Kylin",
     ]) );
  SetFreeEquip( ([
     STD_ARMOUR "shirt/studded_leather" : 1,
     "/std/weapon/blunt/mace" : 1,
     "/domains/southern_coast/towns/haven/obj/kylin_book" : 1,
     ]) );
  SetInventory( ([
     "/std/weapon/blunt/war-hammer" : "wield hammer",
     ]) );
  }
