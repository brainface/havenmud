#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../goblin.h"

inherit LIB_NPC;

static void create() {
npc::create();
SetKeyName("soldier");
SetId( ({ "goblin", "soldier" }) );
SetAdjectives( ({ "goblin" }) );
SetShort("a goblin soldier");
SetLong("This is a small goblin soldier.  He is light green "
        "in color and is a dog-faced thing.  He appears to be very "
        "busy as he runs about trying to prepare for something.");
SetRace("goblin");
SetClass("fighter");
SetCombatAction(30, ({
        "!emote stumbles about in his attack.",
        "!emote swings his sword wildly about in an attack.",
	}) );
SetAction(10, ({
        "!emote runs about trying to move equipment.",
        "!emote moves about in a frenzy.",
	}) );
SetInventory( ([
        G_OBJ + "leather_armour" : "wear armour",
        G_OBJ + "short_sword" : "wield sword",
	]) );
SetLevel(30 + random(5));
SetGender("male");
SetCurrency("cuicui", 300 + random(100));
SetMorality(-350);
}

int eventDie(object agent) {
  object goblin_inv;
  if(!random(500)) {
    goblin_inv = new(DIR_INVASIONS + "/soleil_goblin/gis_inv");
    INVASION_D->eventRegisterInvasion(goblin_inv, agent);
  }
  return (npc::eventDie(agent));
  }