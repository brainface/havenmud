// Monastery
// Aerelus
// 07/05/2006


#include <lib.h>
#include "../monastery.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("cook");
  SetShort("a short cook");
  SetId( ({ "cook" }) );
  SetAdjectives( ({ "short" }) );
  SetLong(
    "The cook is responsible for preparing and serving meals for the "
    "monks. She is short, has long black hair and a permanent frown "
    "on her face. She seems tired of her job, which must not pay very "
    "well."
  );  
  SetRace("human");
  SetClass("rogue");
  SetLevel(20);
  SetGender("female");
  SetReligion("Kylin");
  SetBaseLanguage("Padashi");
  SetMorality(50);
  SetFriends ( ({ "monk", "imam", "warrior_monk", "guard" }) );
  SetDie("!sob");
  SetSmell( ([ "default" : "The cook smells a lot like tomatoes.", ]) );
  SetInventory( ([
    AREA_OBJ "apron" : "wear apron",
    AREA_OBJ "knife" : "wield knife",
  ]) );
  SetAction(6, ({
    "!emote mutters under her breath.",
    "!say I really don't get paid enough for this.",
  }) );
 }
