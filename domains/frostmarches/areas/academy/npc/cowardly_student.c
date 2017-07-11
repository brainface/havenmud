/*
 * Kobold fencing student.
 * low mortal opponent
 * is coward.
 */
#include <lib.h>
#include "../fence.h"

inherit LIB_NPC;

static void create() {
  ::create();

  //descriptive text
  SetKeyName("cowardly fencing student");
  SetId( ({
    "cowardly fencing student","fencer","student","kobold",
    "kobold student","coward"
  }) );
  SetShort("a cowardly fencing student");
  SetAdjectives( ({"cowardly","coward","kobold","fencing"}) );
  SetLong("Short and scrawny, this student looks as if she'd rather be "
    "somewhere else. Her hooves stick awkwardly out of her breeches, and "
    "her snout is keeping her fencing helmet from fitting right."
  );
  SetRace("kobold");
  SetClass("cavalier");
  SetLevel(FENCE_STUDENT_LEVEL - 2);
  SetGender("female");

  //additional settings
  //most likely occurs off practice field.
  SetAction(30, ({
    "!say We hopes not to fight again soon.",
    "!sit down",
    "!say Master of fences scaring us.",
    "!say Wishing we were druids.",
    "!emote startles at a noise, then looks around sheepishly.",
    "!stand up"
 }) );
  
  //most likely to occur on practice field
  SetCombatAction(50, ({
    "!say Tree guarders never get stuck with pointy sticks.",
    "!emote whimpers in fear.",
    "!emote leaps away from the oncoming blow.",
    "!emote whines pathetically.",
    "!stabs halfheartedly with her foil, then scampers backward.",
    "!flee"
  }) );
  SetCurrency("senones",random(25));
  SetDie(
    "The fencing student falls backward, a surprised look on her face."
  );

  // fencing students duel each other.
  SetEncounter( ({"brash fencing student"}) );
  SetInventory( ([
    FENCE_OBJ "fencing_jacket.c" : "wear fencing jacket",
    FENCE_OBJ "practice_foil.c" : "wield foil",
  ]) );

  // cowardly student is cowardly
  SetSkill("dodge", (FENCE_STUDENT_LEVEL-2) *2,1); 
}

