//Illura@Haven
//Sept 2009
//snowseer
#include "../taiga.h"
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("snowseer");
  SetId( ({ "snowseer" }) );
  SetAdjectives( ({ "ancient" }) );
  SetShort("snowseer, the ancient");
  SetLong(
    "Snowseer seems all shimmering crystals and ephemeral "
    "snowdrifts. Her form underneath is perhaps stone or "
    "skymetal. A beautiful set of ebon black eyes framed by "
    "impossible lashes are set in her ageless face. The long "
    "lashes are flecked with snowflakes."
  );
  SetClass("priest");
  SetGender("female");
  SetLevel(110);
  SetRace("gargoyle");
  SetAction(5, ({
    "!emote flutters her eyelashes at you, shedding sparkling snowflakes.",
    "!emote laughs with a silver tinkling noise.",
    "!emote nods at you with great solemnity.",
                })  );
  SetCombatAction(50, ({
    "!cast holy fury",
    "!cast purify",
    }) );
  SetInventory( ([
    TAIGA_OBJ "staff" : "wield staff",
      ]) );
  SetDie("A distant star crashes into the ocean as the ancient falls.");
}
