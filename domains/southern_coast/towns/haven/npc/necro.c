/*  Necromancer until someone else has one */
#include <lib.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("cathanis");
  SetId( ({ "cathanis", "wistel", "necromancer" }) );
  SetRace("elf");
  SetGender("male");
  SetClass("necromancer");
  SetTown("Haven");
  SetShort("Cathanis Wistel, a necromancer");
  SetLong("Cathanis Wistel is a necromancer, a dark and evil "
          "type of mage that deals with the dead. He would be "
          "willing to teach people his arts for devotion.");
  SetMorality(-200);
  SetLevel(24);
  SetSpellBook( ([
    "wound" : 100,
    "acid splash" : 100,
    "spirit call" : 100,
    "mage's bane" : 100,
    "acid rain" : 100,
    "acid blast" : 100,
    "bone shell" : 100,
  	]) );
  SetPlayerTitles( ([
    "newbie" : "the Aspiring Necromancer of Haven Town",
    "mortal" : "the Necromancer of Haven Town",
    "hm"     : "the Adept Necromancer of Haven Town",
    "legend" : "the Legendary Necromancer of Haven Town",
    "avatar" : "the Supreme Necromancer of Haven Town",
    ]) );
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
    ]) );
  SetCurrency("imperials", 3000);
  SetAction(5, ({
    "!cast bone shell",
    }) );
  SetCombatAction(50, ({
    "!cast acid splash",
    "!cast wound",
    "!cast acid blast",
    "!cast acid rain",
    "!cast hunger",
    "!cast bone shell",
    }) );
  SetTaughtSpheres( ({
  	"magical", 
  	"magical necromancy"
  	}) );
}
