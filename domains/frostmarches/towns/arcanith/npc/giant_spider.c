/* A giant spider */

#include <lib.h>
#include "../ruins.h"
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("spider");
  SetId( ({ "spider" }) );
  SetAdjectives( ({ "giant" }) );
  SetShort("a giant spider");
  SetLong("The giant spider is large and hairy.  Large bristles stick out of "
          "her plated black body.  Eight red eyes stare above its hard "
          "mandables.");

  
  SetRace("arachnid");
  SetTown("all");
  SetClass("animal");
  SetGender("female");
  SetLevel(3);
  SetMorality(0);

  SetAction(5,
     ({ "The spider clicks her mandables.",
        "The spider raises and lowers her many legs." }) );
  SetMeleeAttackString("dripping black fangs");
  SetMeleeDamageType(POISON);
  SetDie("The spider's legs give a final twitch as the creature dies.");

}
