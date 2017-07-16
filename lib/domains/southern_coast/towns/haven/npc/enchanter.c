/*  An enchanter leader for Haven Town */
#include <lib.h>
#include "haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Tazza");
  SetId( ({ "tazza", "tazza banewulf", "enchanter" }) );
  SetRace("elf");
  SetGender("female");
  SetClass("enchanter");
  SetLevel(30);
  SetTown("Haven");
  SetShort("Tazza Banewulf, an enchanter");
  SetLong("Tazza is a fun loving elf that is known through the land "
    			"for defying her father's wishes and becoming a mage instead "
    			"of being a warrior.");
  SetPlayerTitles( ([
    "newbie" : "the Aspiring Enchanter",
    "mortal" : "the Enchanter of Haven Town",
    "hm"     : "the Master Enchanter of Haven Town",
    "legend" : "the Revisionist of Haven Town",
    "avatar" : "the Truly Godlike Reality Alterer of Haven Town",
  	]) );
  SetMorality(100);
  SetAdjectives( ({ }) );
  SetSpellBook( ([
    "haste"        : 100,
    "shield area"  : 100,
    "paralysis"    : 100,
    "sphere"       : 100,
    "missile"      : 100,
    "create water" : 100,
    "create food"  : 100,
    "create light" : 100,
    "channeling"   : 100,
    "paralysis"    : 100,
    "shock"        : 100,
    "fireball"     : 100,
  	]) );
  SetAction( 5, ({
    "!cast haste",
    "!cast sphere",
    "!cast haste",
  	}) );
  SetCombatAction( 60,({
    "!cast paralysis",
    "!cast fireball",
    "!cast missile",
    "!cast sphere",
    "!cast shock",
  	}) );
  SetFriends( ({ "alhana", "eustice", "cathanus" }) );
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
  	]) );
  SetInventory( ([
    "/std/weapon/pole/staff" : "wield staff",
  	]) );
  SetCurrency("imperials",1000);
  SetTaughtSpheres( ({
  	"magical",
  	"magical evokation",
    "magical enchantment"
    }) );
}
