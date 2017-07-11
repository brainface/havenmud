/*  A new evoker leader */
#include <lib.h>
#include <std.h>
#include "../haven.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("parsenon");
  SetId( ({ "parsenon", "evoker", "parsenon the evoker" }) );
  SetRace("elf");
  SetGender("male");
  SetShort("Parsenon the Evoker");
  SetLong("Parsenon is a wisened old elf. His thin frame leaves "
                        "most people unfamiliar with magic a feeling of his "
                        "being weak, but those skilled in the Art can see the "
                        "aura of power surrounding him.");
  SetClass("evoker");
  SetSkill("fire magic",1,2);
  SetTown("Haven");
  SetMorality(20);
  SetLevel(40);
  SetSpellBook( ([
    "fireball"                                           : 100,
    "bolt"                               : 100,
    "energy field"                       : 100,
    "chain lightning"                    : 100,
    "haste"                                                              : 100,
    "create magic reserve" : 100,
    "planar durability"    : 100,
    "planar strength"      : 100,
    ]) );
  SetPlayerTitles( ([
    "newbie"   : "the Apprentice Evoker of Haven Town",
    "mortal"   : "the Evoker of Haven Town",
    "hm"       : "the Great Evoker of Haven Town",
    "legend"   : "the Legendary Evoker of Haven Town",
    "avatar"   : "the Godlike Evoker of Haven Town",
    "cavalier" : "the Noble Mage of Haven Town",
    "fighter"  : "General $N the Adroit Tactician of Haven Town",
    ]) );
  SetFreeEquip( ([
    STD_POLE + "baton" : 1,
    ]) );
  SetCurrency("imperials", 3000);
  SetAction(10, ({
    "!cast energy field",
    "!cast haste",
    "!cast planar strength",
    "!cast planar durability",
          }) );
  SetCombatAction(50, ({
    "!cast fireball",
    "!cast chain lightning",
    "!cast bolt",
    "!cast energy field",
    }) );
  SetTaughtSpheres( ({
    "magical",
    "magical evokation",
    "magical enchantment" 
  }) );
}

