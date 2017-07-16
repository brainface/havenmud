//Illura@Haven
//Sept 2009
//irrigationworker
#include <lib.h>
#include "../fields.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("worker");
  SetShort("a young irrigation worker");
  SetId( ({ "worker", "elf" }) );
  SetAdjectives( ({ "young", "irrigation" }) );
  SetLong(
    "Sweat drips from the hair and ears of the worker, who "
    "does her best to make sure the canals run free of "
    "debris from river to field. Were she not so underfed "
    "and overworked, she would be a pretty young girl. "
    "Unfortunately, fate has dealt her a cruel hand and "
    "arduous task."
   );
  SetClass("fighter");
  SetLevel(20);
  SetGender("female");
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       FIELDS_OBJ "bucket" : "wield bucket"
         ]) );
  SetAction(6, ({
    "!say i can't talk now, sorry.",
    "!emote clears a bit of dirt out of the canal with her fingers.",
    "!say the lord shall renew my strength. I shall run, and not weary.",
    "!say may the Lord fulfill all your petitions.",
    "!say he giveth power to the faint; and to them that have no might he increaseth strength",
    "!say i shall mount up with wings as an eagle. I shall walk, and not faint..",
  }) );
}
