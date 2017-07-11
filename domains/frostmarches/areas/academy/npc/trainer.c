// Mahkefel 2011 january 28th or so
// Adding a trainer to this area, thematic to arcanith.
//  ALso this is the best angel area *EVER MADE*.
#include <lib.h>
#include "../fence.h"

inherit LIB_TRAINER;

static void create() {
  ::create();

  //descriptive text
  SetKeyName("setzil");
  SetId( ({ "setzil", "assistant" }) );
  SetShort("setzil, assistant to the fencemaster");
  SetAdjectives( ({"assistant"}) );
  SetLong(
    "This kobold is taller than his peers around him, and sports more muscle "
    "than your average kobold should really warrant. He looks at you expectantly, "
    "as if waiting for your greeting."
  );
  SetTrainingSkills( ({
    "multi-weapon",
    "projectile combat",
    "pierce combat",
    "slash combat",
    "hack combat",
    "blunt combat",
    "knife combat",
    "pole combat",
    "melee combat",
  }) );

  // base statistics
  SetRace("kobold");
  SetClass("cavalier");
  SetTown("Arcanith");
  SetLevel(15);

  // misc stuff
  SetAction(25, ({
    "!emote parries an imaginary blow from his shadow.",
    "!emote stabs the air repeatedly.",
    "!flex",
    "!say This one never as fast as me. But I could teach this one "
      "how not to embarrass itself.",
    "!say This one never as fast as me. But I could teach this one "
      "how not to embarrass itself.", // LAAAAZZZZYYYY
    "!say Fencemaster she is busy with things more important. I can "
      "teach you instead so you do not bother.",
  }) );
  SetBaseLanguage("Koblich");
  SetCurrency("senones",random(50));
  SetGender("male");
  SetInventory( ([
    FENCE_OBJ "practice_foil.c" : "wield foil",
    FENCE_OBJ "fencing_jacket.c" : "wear jacket",
  ]) );

}

