/*  Necromancer until someone else has one */
#include <lib.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Muertan");
  SetId( ({ "muertan", "necromancer", "colom" }) );
  SetRace("human");
  SetGender("male");
  SetClass("necromancer");
  SetTown("Parva");
  SetShort("Muertan Colom the Necromancer");
  SetLong(
    "Muertan Colom is the most feared necromancer in Parva. "
    "His residency under the crypt is known but avoided due to "
    "his powers of evil. Those seeking to learn from him need only "
    "<ask> him to begin their path to evil."
    );
  SetMorality(-500);
  SetLevel(40);
  SetSpellBook( ([
    "wound" 				  	 : 100,
    "cloud kill" 				 : 100,
    "chain lightning" 	 : 100,
    "acid splash" 			 : 100,
    "acid blast"     	 	 : 100,
    "acid rain" 				 : 100,
    "necromantic shield" : 100,
    "fireball" 					 : 100,
    "drain soul" 			   : 100,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Crypt Dweller",
    "mortal" : "the Dark Walker of the Crypts",
    "hm"     : "the Grand Defiler",
    "legend" : "the Destroyer of Souls",
    "avatar" : "the Enslaver of the Dead",
  	]) );
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
  	]) );
  SetInventory( ([
  	"/std/weapon/pole/staff" : "wield staff",
  	]) );
  SetCurrency("oros", random(300) + 10);
  SetAction(15, ({
    "!cast necromantic shield",
  	}) );
  SetCombatAction(65, ({
    "!cast wound",
    "!cast cloud kill",
    "!cast acid splash",
    "!cast necromantic shield",
    "!cast acid blast",
    "!cast acid rain",
    "!cast drain soul",
    "!cast fireball",
    "!cast chain lightning",
    }) );
}
