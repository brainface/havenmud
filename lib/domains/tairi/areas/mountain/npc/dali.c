#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_STAT_TRAINER;

static void create() {
  ::create();
  SetKeyName("dali");
  SetShort("Dali of the Mountain");
  SetRace("human");
  SetBaseLanguage("Tai");
  SetTown("Tairi");
  SetId( ({ "dali" }) );
  SetFriends( ({ "llama" }) );
  SetLong("Dali of the Mountain is a legendary trainer. His knowledge can bend the "
          "rules that races must live by, and with his training, one could expand "
          "the horizon for normal development to include untapped powers.");
  SetGender("male");
  SetAction(5, ({
    "!speak Approach and be enlightened in the way!",
    "!speak Do you seek to improve your development?",
    "!speak You could ask me to train you.",
    "!cast aetheric rift", "!cast aetheric rift",
    "!cast temporal barrier", "!cast temporal barrier",
  }) );
  SetInventory( ([
    STD_POLE "staff" : "wield staff",
    STD_CLOTHING "body/green_robe" : "wear robe",
    ]) );
  SetClass("evoker");
  SetLevel(299);
  SetMorality(5000);
  SetSpellBook( ([
    "temporal barrier" : 100,
    "disintegrate"   : 100,
    "chain lightning" : 100,
    "death"          : 100,
    "aetheric rift" : 100,
    ]) );
  SetCombatAction(50, ({
    "!speak It would be wise of you to flee.",
    "!cast aetheric rift", "!cast aetheric rift", "!cast aetheric rift", "!cast aetheric rift",
    "!cast death", "!cast chain lightning", "!cast disintegrate", "!cast death",
  }) );
  SetFirstCommands( ({
    "cast aetheric rift", "cast aetheric rift",  "cast temporal barrier", "cast temporal barrier", "cast temporal barrier",
    "guard llama", "cast aetheric rift on llama", "cast aetheric rift on llama",
  }) );
  SetLimit(1);
}

          