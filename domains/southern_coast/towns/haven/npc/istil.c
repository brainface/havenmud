#include <lib.h>
#include <daemons.h>
#include "haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("istil");
  SetId( ({ "istil", "ranger" }) );
  SetTown("Haven");
  SetShort("Istil Anavarian the Master Ranger of Haven Town");
  SetRace("elf");
  SetClass("ranger");
  SetLevel(48);
  SetReligion("Kylin");
  SetMorality(1000);
  SetCurrency("imperials",random(100)+50);
  SetLong("Istil Anavarian is a rogueish looking elf that appears \n"
          "to be an infrequent guest in cities and towns.  His \n"
          "clothing is lightly dusted, and leaves and other attire \n"
          "are scattered about his person");
  SetGender("male");
  SetInventory( ([
      ]) );
  SetPlayerTitles( ([
    "newbie"  : "the Forester of Haven Town",
    "mortal"  : "the Ranger of Haven Town",
    "hm"      : "the Master Ranger of Haven Town",
    "avatar"  : "the Forest Lord of Haven Town",
    ]) );
  SetFreeEquip( ([
     "/std/weapon/projectile/bow_long_newbie" : 1,
     ]) );
  SetTaughtSpheres( ({ 
  	"natural evokation",
    "natural", 
    "natural enchantment", 
    "religion kylin",
    "natural healing",
    }) );
  SetSpellBook( ([
    "natural veil"   : 100,
    "thicken skin"   : 100,
    "freeze"         : 100,
    "heat"           : 100,
    "cleanse flesh"  : 100,
    "vine wall"      : 100,
    "natural charge" : 100,
    "tend wounds"    : 100,
    "summon animal"  : 100,
    "tangle"         : 100,
    "condense air"   : 100,
    ]) );
  SetCombatAction(20, ({
  	"!cast vine wall",
  	"!cast heat",
  	"!cast freeze",
  	"!cast tangle",
    "!cast summon animal",
  	}) );
  }
