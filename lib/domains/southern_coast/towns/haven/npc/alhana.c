#include <lib.h>
#include <daemons.h>

inherit LIB_LEADER;



static void create() {
  leader::create();
  SetKeyName("alhana");
  SetId( ({ "alhana", "alhana valen", "valen", "lady", "librarian" }) );
  SetRace("elf");
  SetGender("female");
  SetClass("evoker");
  SetSkill("fire magic",1,2);
  SetLevel(150);
  SetShort("Alhana Valen, Lady of Haven Library");
  SetLong("Alhana Valen is a small elven woman with a fragile looking \n"
    			"body.  Upon closer look though, one can see that she has a \n"
    			"certain aura of power about her.");
  SetReligion("Kylin");
  SetSpellBook( ([
    "energy wall"        : 100,
    "disintegrate"       : 100,
    "fireball"           : 100,
    "temperature shield" : 100,
    "planar stength"     : 100,
    "planar durability"  : 100,
    "lava storm"         : 100,
    "chain lightning"    : 100,
    "flamestrike"        : 100,
    "dimension door"     : 100,
    "dimensional rift"   : 100,
    ]) );
  SetAction(5, ({
    "!cast energy wall",
    "!cast temperature shield",
    "!cast planar strength",
    "!cast planar durability",
    }) );
  SetCombatAction(75, ({
    "!cast flamestrike",
    "!cast disintegrate",
    "!cast fireball",
    "!cast chain lightning",
    "!cast temperature shield",
    "!cast disintegrate",
    "!cast lava storm",
    "!cast energy wall",
   	}) );
  SetPlayerTitles( ([
    "newbie"  : "the Aspiring Adeptus",
    "mortal"  : "the Adeptus",
    "hm"      : "the Greater Adeptus",
    "legend"  : "the Master Adeptus",
    "avatar"  : "the Supreme Adeptus",
    "fighter" : "the Sorceror of Haven Town",
  	]) );
  SetTown("Haven");
  SetMorality(350);
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
  	]) );
  SetInventory( ([
    "/std/weapon/pole/staff" : "wield staff",
  	]) );
  SetCurrency("imperials",6000);
  AddChannel("havenmage");
  SetNoJoin(1);
  SetTaughtSpheres( ({
  	"magical",
  	"magical evokation",
    "magical enchantment" 
    }) );
  SetFirstCommands( ({
  	"cast temperature shield",
  	"cast temparature shield",
  	"cast energy wall"
  	}) );
}


	