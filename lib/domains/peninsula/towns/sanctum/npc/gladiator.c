/* The Gladiator for the Arena. */
#include <lib.h>
#include "../rome.h"
inherit LIB_NPC;

object hired;

object SetHired(object who) { return hired = who; }
object GetHired()           { return hired; }

int MeDie(object);

static void create() {
  ::create();
  SetKeyName("gladiator");
  SetShort("an intense looking gladiator");
  SetId( ({ "gladiator" }) );
  SetAdjectives( ({ "intense", "looking" }) );
  SetRace("human");
  SetBaseLanguage("Imperial");
  SetClass("fighter");
  SetLevel(1);
  SetGender("male");
  SetLong(
    "This gladiator is a stern looking fellow with a firm desire to "
    "teach the proper arts of combat to those who seek him out."
    );
  SetDie( (: MeDie :) );
  SetNoCorpse(1);
  SetCombatAction(10, ({
    "!disarm",
    "!disorient",
    "!disarm",
  }) );
}

int MeDie(object who) {  
  if (who) {
    eventForce("yell I yield to you, " + capitalize(who->GetKeyName()) + "!");
    who->eventEnemyDied(this_object());
  }
  environment()->eventPrint("The gladiator stalks angrily out of the Arena.");
  eventDestruct();
  return 0;
}

void heart_beat() {
  ::heart_beat();
  if (!hired) {
    eventDestruct();
    return;
  }
  if (!(base_name(environment(hired)) == ROME_ROOM + "arena1" || base_name(environment(hired)) == ROME_ROOM + "arena2")) {
    eventDestruct();
    return;
  }
}

int ContinueHeart() { return 1; }
