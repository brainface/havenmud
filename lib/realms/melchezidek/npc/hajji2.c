#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;


static void create() {
  sentient::create();
  SetKeyName("hajji");
  SetShort("Hajji the Sidekick");
  SetId( ({ "hajji" }) );
  SetAdjectives( ({ "sidekick" }) );
  SetRace("human");
  SetClass("fighter");
  SetLevel(30 + random(10) );
  SetGender("male");
  SetLong("This is Hajji. He's a little brown skinned fellow who helps"
          " Melchezidek out. He's really dirty and smells like curry"
          " and roasted lamb.");
  SetCurrency( ([
    "imperials" : random(300),
    "rupies"    : random(100),
    "rounds"    : random(80),
     ]) );
  SetInventory( ([
      STD_POLE + "staff" : "wield staff",
      "/realms/melchezidek/obj/thobe.c" : "wear thobe",
      "/realms/melchezidek/obj/bisht.c" : "wear bisht",
      "/realms/melchezidek/obj/turban.c" : "wear turban",
     ]) );
  }
