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
  SetClass("necromancer");
  AddSkill("blunt combat",1);
  SetLevel(random(5)+75);
  SetKeyName("apprentice");
  SetId( ({ "necromancer", "apprentice"}) );
  SetShort("a stout necromancer apprentice");
  SetAdjectives( ({ "stout" }) );
  SetLong("This wide shouldered human appears to have been turned "
          "recently. His eyes are pure white and his skin is pale "
          "as an eggshell. His long black hair is tied behind his "
          "oval face displaying his distinct jaw and showing a "
          "gruesome scar across his neck stitched with thread.");
  SetUndead(1);
  SetMorality(-250);
  SetSpellBook( ([
    "necromantic shield" : 100,
    "wound" : 100,
    "asphyxiation" : 100,
    "acid rain" : 100,
    "vampiric touch" : 100,
    "curse" : 100,
    "hunger" : 100,
        ]) );
  SetCurrency("imperials", 40);
  SetInventory( ([
    TOWER_OBJ + "acloak"   : "wear cloak",
    TOWER_OBJ + "astaff"   : "wield staff",
    ]) );
  SetStat("charisma", 201, 1);
  SetFriends(({
    TOWER_NPC+"sumskeleton",
    TOWER_NPC+"wcorpse",
    TOWER_NPC+"zombie"
  }));
  SetAction(5, ({
    "!cast necromantic shield",
    "!speak The Necromancers will rise again!",
	"!speak Those fools would rid us all...",
	"!speak If you are here to kill me, make it quick.",
     }) );
  SetFirstCommands( ({ "cast necromantic shield",
                       "cast necromantic shield",
                       "cast necromantic shield" }) );

  SetDie("The apprentice emits a bright flash he dies and leaks more black "
         "fog into the study.");
  SetCombatAction(10, (: eventSummon :) );
}

//  Mahkefel breaks ur file
//  so this eventSummon will fire once, summing a skelly,
//  then the
//  SetCombatAction will override the existing
//  combat queue, replacing it with cool spells.

void eventSummon() {
  object buddy;
  eventForce("%^RED%^emote conjures a skeleton by his side!%^RESET%^");
  buddy = new(TOWER_NPC "sumskeleton");
  buddy->eventMove(environment());
  buddy->SetFriends( ({ "apprentice" }) );
  message("system", "%^RED%^The Apprentice uses his necromancy to raise a "
                    "corpse from the ground!!%^RESET%^",
  environment());

  SetCombatAction(35, ({
    "!cast wound",
    "!cast asphyxiation",
    "!cast acid rain",
    "!cast hunger",
    "!cast vampiric touch",
    "!cast curse",
    }) );
}

