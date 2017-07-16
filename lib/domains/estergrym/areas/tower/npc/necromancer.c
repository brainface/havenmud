#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_SENTIENT;
void eventSummon();

static void create() {
  ::create();
  SetRace("human");
  SetGender("male");
  SetKeyName("kilwrath");
  SetId( ({ "necromancer", "kilwrath" }) );
  SetClass("necromancer");
  AddSkill("blunt combat",1);
  SetLevel(random(7)+80);
  SetShort("Kilwrath, the conjurer of souls");
  SetAdjectives( ({ "conjurer","necromancer" }) );
  SetLong("This necromancer is emitting a black fog from his very "
          "being. Behind the bandana that covers his eyes are two "
          "evident scars that are underneath them which entrail to "
          "where his eyes would be. His lips are covered in a black "
          "makeup and he shows complete disdain. Large red daemon-like hands "
          "protrude from his torso in a clear but visible flame. "
          "Although he is human, he appears to have come close to "
          "one of the highest results someone in his magic could "
          "achieve, a Lich.");
  SetUndead(1);
  SetMorality(-1250);
  SetSpellBook( ([
    "necromantic shield" : 100,
    "wound" : 100,
    "asphyxiation" : 100,
    "acid rain" : 100,
    "vampiric touch" : 100,
    "curse" : 100,
    "hunger" : 100,
        ]) );
  SetInventory( ([
    TOWER_OBJ + "nmace"   : "wield mace",
    TOWER_OBJ + "ncloak"  : "wear cloak",
    TOWER_OBJ + "namulet" : "wear amulet",
    ]) );
  SetStat("charisma", 350, 1);
  SetFirstCommands( ({
    "cast necromantic shield",
    "cast necromantic shield",
    "cast necromantic shield",
    }) );
  SetFriends(({
               TOWER_NPC+"skel"
               TOWER_NPC+"shrieker"
    }));
  SetCombatAction(50, (: eventSummon :) );
  SetDie("Kilwrath clasps his amulet as he dies.");
}

void eventSummon() {
  object buddy;
  eventForce("%^RED%^emote conjures a skeleton to aid him!%^RESET%^");
  buddy = new(TOWER_NPC "skel");
  buddy->eventMove(environment());
  buddy->SetFriends( ({ "necromancer" }) );
  message("system", "%^RED%^Kilwrath uses his necromancy to raise a "
                    "corpse from the ground!!%^RESET%^",
    environment());

  SetCombatAction(50, ({
    "!cast wound",
    "!cast asphyxiation",
    "!cast acid rain",
    "!cast hunger",
    "!cast vampiric touch",
    "!cast curse",
    "!cackle",
    }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
      eventForce("cast necromantic shield");
 }
}

