#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("Baba Yaga");
  SetShort("Baba Yaga, a Practical Witch");
  SetId( ({ "baba", "yaga", "witch" }) );
  SetAdjectives( ({ "yaga", "baba", "practical" }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetTrainingSkills( ({
    "practical magic",
    }) );
  SetTown("all");
  SetGender("female");
  SetClass("enchanter");
  SetLevel(12);
  SetCurrency("rubles", 200);
  SetMorality(-50);
  SetLong(
    "Baba Yaga is a very practical witch. Her area of training deals with minor cantrips and small "
    "enchantments designed not so much to mystify as to make her own life easier."
    );
  SetAction(6, ({
    "!speak Did you need me to teach you?",
    "!speak And I fortunately know a little magic. It's a talent that I always have possessed.",
  }) );
  SetInventory( ([
    STD_POLE "staff" : 1,
    ]) );
  SetFirstCommands( ({ "wield all" }) );
  SetLimit(1);
}
