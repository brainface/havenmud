/*  Necromancer until someone else has one */
#include <lib.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("jaffar");
  SetId( ({ "jaffar", "necromancer", "man" }) );
  SetAdjectives( ({ "old", "withered" }) );
  SetRace("human");
  SetGender("male");
  SetClass("necromancer");
  SetTown("Yozrath");
  SetShort("a withered old man");
  SetLong("This withered old man has a foul, bedeviled appearance, "
          "almost as if he has been touched by madness from wandering "
          "too long under the Yozrath sun."
         );
  SetMorality(-200);
  SetLevel(250);
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
    "newbie" : "the Shadow of the Sands",
    "mortal" : "the Scourge of the Desert",
    "hm"     : "the Foul Deceiver",
    "legend" : "the Sacrificer of Souls",
    "avatar" : "the Plague of Yozrath",
    ]) );
  SetFreeEquip( ([
    "/std/weapon/pole/staff" : 1,
    ]) );
  SetCurrency("dinar", 3000);
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
