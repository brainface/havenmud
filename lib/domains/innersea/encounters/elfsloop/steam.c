//mahkefel '11: kobold helper for goden warship
#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <domains.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetRace("elemental");
  SetGender("female");
  SetClass("sailor");
  AddSkill("brawling",1);
  SetLevel(1);
  SetKeyName("elemental");
  SetId( ({ "elemental" }) );
  SetShort("a whispy steam elemental");
  SetAdjectives( ({ "whispy", "steam" }) );
  SetLong(
    "A motive tower of condensed steam billows around here. In its midst, "
    "the vague outline of a feminine form can be seen."
  );
  SetAction(10, ({
    "!emote fumes.",
    "!whistle",
  }) );
  SetCombatAction(10, ({
    "!emote billows about angrily.",
    "!emote fumes.",
    "!emote whistles furiously.",
    "!punch",
  }) );

  SetMeleeAttackString("%^BOLD%^WHITE%^boiling%^RESET%^ knuckles");
  SetMeleeDamageType(HEAT);

  SetCaptainAggressiveness(80);
  SetResistance(COLD, "weakness");
  SetResistance(HEAT,"immune");
  SetProperty("pirate", "haven");
  SetShipWander(1);

  SetTown("Haven");
  SetMinLevel(1);
  SetMaxLevel(180);

}

