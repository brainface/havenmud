#include <lib.h>
#include "../fence.h"

inherit LIB_NPC;

static void create() {
  ::create();

  //descriptive text
  SetKeyName("brash fencing student");
  SetId( ({ 
    "brash fencing student","fencer","student","kobold","kobold student" 
  }) );
  SetShort("a brash fencing student");
  SetAdjectives( ({"brash", "fencing"}) );
  SetLong(
    "Short and scrawny, this student's adventuring days are not yet come "
    "to pass. However, his face is set in grim mask of determination, and "
    "he is standing as proudly as cloven feet will allow."
  );
  SetRace("kobold");
  SetClass("cavalier");
  SetGender("male");
  SetLevel(FENCE_STUDENT_LEVEL); 

  //These will *most likely* occur outside the practice field.
  SetAction(30, ({
    "!say School needs wood for heater.",
    "!emote breaks some limbs off a stunted pine tree.",
    "!say Master of fences might let you practice too. You must ask "
      "fencemaster for help.",
  }) );

  //These *most likely* occur on practice field.
  SetCombatAction(50, ({
    "!say We become excellent guards of City of Lights!",
    "!say All magic one day ours be.",
    "!say Grove tenders counting on we!",
    "!emote performs a clumsy sweep with his foil that leaves him wide "
      "open.",
    "!emote nearly skewers everyone with a wild swing.",
    "!emote barks happily as his blow nearly lands.",
   }) );

  // miscellaneous stuff.
  SetCurrency("senones",random(25));
  SetDie(
    "The fencing student falls backward, a surprised look on his face."
  );

  // fencing students duel each other.
  SetEncounter( ({"cowardly fencing student"}) );
  SetInventory( ([
    FENCE_OBJ "practice_foil.c" : "wield foil",
    FENCE_OBJ "fencing_jacket.c" : "wear jacket",
  ]) );

 // brash student is brash.
  SetSkill("combat rage",FENCE_STUDENT_LEVEL * 2,1);
}

