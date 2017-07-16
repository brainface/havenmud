//Illura@Haven
//Sept 2009
//elfworker
#include <lib.h>
#include "../fields.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("worker");
  SetShort("an elvish field worker");
  SetId( ({ "worker", "elf" }) );
  SetAdjectives( ({ "field", "elvish" }) );
  SetLong(
    "This sweaty elf looks like he could use a week off. "
    "His calloused hands show the work of many days, "
    "and his back shows the thready, overlapping scars "
    "of many lashes. Still, he labors almost robotically. "
   );
  SetClass("fighter");
  SetLevel(25);
  SetGender("male");
  SetRace("elf");
  SetBaseLanguage("Alatherian");
  SetCurrency("deben",random(100));
  SetInventory( ([
    FIELDS_OBJ "rake" : 1,
         ]) );
  SetFirstCommands( ({"wield rake"}) );
  SetAction(6, ({
    "!say lord on high, can you hear your people cry...",
    "!say deliver us, hear our call. Deliver us, Lord of All...",
    "!say Remember us, here in this burning sand...",
    "!say send a shepherd to shepherd us...",
    "!say river, o river, flow gently for me...do you know somewhere that we can live free...",
  }) );
}
