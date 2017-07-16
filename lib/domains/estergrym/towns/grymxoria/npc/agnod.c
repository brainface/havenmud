#include <lib.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("agnod");
  SetShort("Agnod Anthrax, the necromancer");
  SetId( ({
    "agnod anthrax",
    "necromancer",
    "nosferatu",
    "anthrax",
    "agnod",
  }) );
  SetLong(
    "Agnod radiates power. His tall, muscular frame is covered with a "
    "long flowing black robe. It is he one must seek out if one seeks to "
    "become a practitioner of the dark arts."  
  );
  SetClass("necromancer");
  SetSkill("enchantment", 1);
  SetLevel(35);
  SetRace("nosferatu");
  SetTown("Grymxoria");
  SetGender("male");
  SetReligion("Aberach", "Aberach");
  SetMorality(-2000);
  SetSpellBook(  ([
    "acid blast" : 100,
    "wound" : 100,
    "hunger" : 100,
    "necromantic shield" : 100,
    "telepathy" : 100,
    "mage's bane" : 100,
    "create magic reserve" : 100,
  	]) );
  SetPlayerTitles( ([
    "newbie" : "the Wayward Aspiring Theurgist",
    "mortal" : "the Baneful Conjurer",  
    "hm" 		 : "Lord $N the Wraithful Diabolist",
    "legend" : "Shade $N the Master of the Black Arts",
    "avatar" : "Wraith $N, Death Incarnate", 
    "cavalier" : "DeathKnight $N the Malevolent Spectre", 
    "fighter" : "Count $N the Infernal Collector"
  ]) );
 SetInventory( ([
    G_OBJ + "/nosf_staff" : "wield staff",
    G_OBJ + "/nosf_armor" : "wear armor",
  ]) );
 SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
  ]) );

  SetFriends( ({ "karn", "guard"  }) );
  SetCombatAction(70, ({
    "!cast wound",
    "!cast necromantic shield",
    "!cast acid blast",
    "!cast hunger",
	  }) );
}
