#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("cyrvrakis");
  SetShort("Cyrvrakis the Shadowed");
  SetRace("human");
  SetBaseLanguage("Enlan");
  SetTown("Averath");
  SetId( ({ "Cyrvrakis" }) );
  SetLong("Cyrvrakis is covered by shadows slowly bending around his body. The shadows cover his form but "
          "he appears to be human and quite old, older then any human. The shadows cover the rest of his features "
          "but an intense magical energy and power radiates from him.");
  SetGender("male");
  SetAction(5, ({
    "!speak The ways of the shadow are not for you, leave now!",
    "!speak Leave me, I do not wish company!",
  }) );
  SetInventory( ([
    STD_POLE "staff" : "wield staff",
    STD_CLOTHING "body/green_robe" : "wear robe",
    ]) );
  SetClass("evoker");
  SetClass("rogue");
  SetLevel(200);
  SetMorality(-5000);
  SetSpellBook( ([
    "temporal barrier" : 100,
    "disintegrate"   : 100,
    "chain lightning" : 100,
    "death"          : 100,
    "aetheric rift" : 100,
    ]) );
  SetCombatAction(10, ({
    "!speak It would be wise of you to flee.",
    "!cast death", "!cast chain lightning", "!cast disintegrate", "!cast chain lightning",
  }) );
  SetFirstCommands( ({
    "cast temporal barrier", "cast temporal barrier",  "cast temporal barrier", 
    "cast temporal barrier", "cast temporal barrier",
  }) );
  SetLimit(1);
}

int eventDie(object agent) {
  object scroll;

  scroll = new(AVERATH_OBJ + "scroll");
  scroll->eventMove(this_object());
  return (npc::eventDie(agent));
  }
