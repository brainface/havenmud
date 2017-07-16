/*  A diviner leader, since there is not one. */
#include <lib.h>
#include "haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("eustice");
  SetId( ({ "eustice", "eustice ranagip", "diviner" }) );
  SetRace("human");
  SetGender("male");
  SetTown("Haven");
  SetClass("evoker");
  SetSkill("blunt combat",1,1);
  SetLevel(30);
  SetMorality(250);
  SetShort("Eustice Ranagip, a diviner");
  SetLong("Eustice Ranagip is the oldest diviner in the Haven Library. "
    			"His keen wit and sharp sense of things makes him an invaluable "
    			"ally in the world of mages.");
  SetAdjectives( ({ }) );
  SetTown("Haven");
  RemoveLanguage("Enlan");
  SetLanguage("Eltherian", 100, 1);
  SetPlayerTitles( ([
    "newbie" : "the Aspiring Diviner",
    "mortal" : "the Diviner of Haven Town",
    "hm"     : "the Master Diviner of Haven Town",
    "avatar" : "the All Seeing of Haven Town",
  	]) );
  SetFreeEquip( ([
    "/std/weapon/blunt/mace" : 1,
  	]) );
  SetInventory( ([
    "/std/weapon/blunt/war-hammer" : "wield hammer",
  	]) );
  SetCurrency("imperials",2000);
  SetSpellBook( ([
    "blindness" : 100,
    "paralysis" : 100,
    "sphere"    : 100,
    "fireball"  : 100,
    "shock"     : 100,
    ]) );
  SetAction(5, ({
    "!cast sphere",
		 }) );
  SetCombatAction(65, ({
    "!cast blindness",
    "!cast paralysis",
    "!cast sphere",
    "!cast fireball",
    "!cast shock",
    }) );
  SetTaughtSpheres( ({
  	"magical",
  	"magical necromancy",
    "magical divination" }) );
  SetNoJoin(1);
}
