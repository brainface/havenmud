//Illura@Haven
//Sept 2009
//nkuku
#include <lib.h>
#include "../fields.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("nkuku");
  SetShort("nkuku, master of the fields");
  SetId( ({ "nkuku", "gnoll", "master" }) );
  SetAdjectives( ({ "fields" }) );
  SetLong(
    "Nkuku is a minor official in charge of growing crops, "
    "keeping the fields well irrigated, and managing the many "
    "workers under his watch. He has one working eye, the other "
    "filmy-white under what appears to be a cataract. To make "
    "up for his disability, he has grown snarky and shrewd "
    "with age and has a keen sense of his duties. "
   );
  SetClass("fighter");
  SetLevel(30);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       FIELDS_OBJ "cudgel" : "wield cudgel"
         ]) );
  SetAction(6, ({
    "!say i like to think I have a keen eye for detail.",
    "!say there's nothing wrong with this weird eye!",
    "!say arapapa, you're the apple of my eye.",
    "!say arapapa, I need you to cross all the Ts and dot all the...lowercase Js.",
    "!say get to work! I have my eye on you!",
    "!emote mutters under his breath about some farming particulars.",
  }) );
}
