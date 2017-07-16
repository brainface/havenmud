//Selket@Haven
//2006
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("ibis");
  SetId( ({"bird", "ibis"}) );
  SetShort("an ibis");
  SetClass("animal");
  SetLevel(6);
  SetRace("bird");
  SetGender("female");
  SetLong("This is a small brightly plumed ibis, who is an "
    "expert at jabbing her long curved beak into the dirt to "
    "find insects.");
  SetAction(5, ({
    "!emote pecks at the ground.",
    "!emote twitters prettily.",
  }) );
}

