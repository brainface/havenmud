#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("agnod");
  SetShort("Agnod Anthrax, the necromancer");
  SetId( ({ 
    "agnod anthrax", "necromancer", "nosferatu",
    "anthrax", "agnod",
  }) );
  SetLong("Agnod radiates power. His tall, muscular frame "
    "is covered with a long flowing black robe. It is he one "
    "must seek out if one seeks to become a practitioner of "
    "the dark arts."  
  );
  SetRace("nosferatu");
  SetGender("male");
  SetTown("Grymxoria");
  SetMorality(-200);
  SetClass("necromancer");
  SetLevel(35);
  SetInventory(  ([
    G_OBJ + "nosf_staff" : "wield staff",
    G_OBJ + "nosf_armor" : "wear armor",
  ]) );
  SetFreeEquip(  ([
    STD_POLE + "staff" : 1,
  ]) );
  SetSpellBook(  ([
    "chill touch" : 100,
    "splash" : 100,
    "wither" : 100,
    "transfusion" : 100,
    "wound" : 100,
    "hunger" : 100,
    "wards of protection" : 100,
    "create dark globe" : 100,
    "dispel protections" : 100,
    "telepathy" : 100,
    "hellfire" : 100,
    "mage's bane" : 100,
    "create magic reserve" : 100,
    "reckoning" : 100,
  ]) );
  SetCombatAction(10, ({
    "!cast wound",
    "!cast wards of protection",
    "!cast reckoning",
    "!cast dark flame",
    "!cast wither",
    "!cast splash",
  }) );
  SetFriends( ({ "karn", "guard"  }) );
  SetPlayerTitles(  ([
    "newbie" : "the Aspiring Necromancer",
    "mortal" : "the Necromancer",
    "hm" : "the Dark Mage",
    "legend" : "the Master of the Black Arts",
    "avatar" : ", Death Incarnate",
    "cavalier" : "the DeathKnight",
  ]) );
}
