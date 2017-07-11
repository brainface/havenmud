#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("leader");
SetId( ({ "orc","leader" }) );
SetShort("an orc leader");
SetAdjectives( ({ "orc" }) );
SetLong("This orc is very tall.  Standing about seven feet tall, he has to "
        "hunch down inside this tent.  His skin is brown in color and he "
        "has no hair.  He is very impressive standing there looking over "
        "maps and planning strategies.");
SetRace("orc");
SetClass("fighter");
SetCombatAction(30, ({
        "!say Traitors to the cause must die!",
        "!yell GUARDS!",
	}) );
SetAction(10, ({
        "!emote takes a few practice thrusts.",
        "!emote waits for some action.",
        "!emote intently studies maps.",
        "!emote furrows his brow in concentration.",
	}) );
SetInventory( ([
        G_OBJ + "leader_armour" : "wear chainmail",
        G_OBJ + "leader_sword"  : "wield sword",
        G_OBJ + "backpack"      : 1,
	]) );
SetLevel(30 + random(10));
SetGender("male");
SetCurrency("cuicui", 1000 + random(500));
SetMorality(-600);
}

int eventDie(object agent) {
  object goblin_inv;
   if(!random(250)) {
    goblin_inv = new(DIR_INVASIONS + "/soleil_goblin/gis_inv");
    INVASION_D->eventRegisterInvasion(goblin_inv, agent);
   }
  return (npc::eventDie(agent));
  }
