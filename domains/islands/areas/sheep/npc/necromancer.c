/*  the Lady of the Manor */
#include <std.h>
#include <lib.h>
#include <position.h>
#include "../sheep.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Lady Gladia d'Elban");
  SetShort("Lady Gladia d'Elban");
  SetId( ({ "gladia", "lady", }) );
  SetRace("human");
  SetGender("female");
  SetBaseLanguage("Avera");
  SetClass("necromancer");
  SetLong(
    "Lady Gladia d'Elban is a medium-height human with long golden-blonde hair. Her smile has a sinister "
    "gleam which does not in any way appear friendly. Her long fingers casually pick at the golden threads of "
    "her robe as she glares coolly around the library."
    );
  SetLevel(15);
  SetInventory( ([
    SHEEP_OBJ "gladia_knife" : "wield knife",
    SHEEP_OBJ "gladia_robe"  : "wear robe",
    SHEEP_OBJ "gladia_slippers": "wear slippers",
    ]) );
  SetFirstCommands( ({
    "cast shroud",
    "cast shroud",
    "cast shroud",
  }) );
  SetCombatAction(10, ({
    "!cast shroud",
    "!cast acid blast",
    "!cast acid splash",
  }) );
  SetAction(5, ({
    "!cast shroud",
    "!say Why have you come here?",
  }) );
  SetMorality(-1500);
  SetCurrency("ducats", 500);
  SetLimit(1);
  SetPosition(POSITION_SITTING);
  
}

varargs int eventDie(object agent) {
  if (agent) {
    if (!agent->GetQuestCompleted("Liberated Elban Isle")) {
      agent->AddQuest("the Liberator of Sheep", "Liberated Elban Isle");
      agent->AddDevelopmentPoints(2);
      agent->eventPrint("You have liberated the sheep of Elban Isle from the cruel Lady Gladia!");
    }
  }
  return ::eventDie(agent);
}