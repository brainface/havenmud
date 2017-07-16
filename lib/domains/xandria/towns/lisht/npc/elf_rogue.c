#include <lib.h>
#include "../lisht.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Lisht");
  SetLimit(1);
  SetRace("elf");
  SetRestrictRace(1);
  SetBaseLanguage("Alatherian");
  SetGender("male");
  SetClass("rogue");
  SetLevel(50);
  SetKeyName("abidan");
  SetId( ({ "abidan" }) );
  SetShort("Abidan the Vile");
  SetLong(
    "Abidan the Vile has a reputation as a disgusting creature that "
    "lives off the filth and refuse of the slave areas of Lisht. His "
    "redeeming trait is that his training in sneaky ways can help "
    "young elves to hide from danger."
    );
  SetAction(1, ({
    "!emote sniffles.",
    "!emote wipes his nose on his sleeve.",
    "!emote belches.",
    }) );
  SetPlayerTitles( ([
    "newbie" : "the Hiding Elfling",
    "mortal" : "the Steathly Shadow",
    "hm"     : "the Shadow of Lisht",
    "legend" : "the Completely Hidden",
    "avatar" : "the Green Hand",
    ]) );
  SetCurrency("deben", 1000 + random(3000) );
  SetInventory( ([
    STD_WEAPON + "knife/stiletto" : "wield stiletto",
    ]) );
  SetFreeEquipment( ([
    STD_WEAPON "knife/freeknife" : 2,
    DIR_STD    "lockpicks/newbiepicks" : 1,
    ]) );
}
