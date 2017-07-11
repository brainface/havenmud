#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("rat");
  SetRace("rodent");
  SetGender("male");
  SetShort("a large brown rat");
  SetId( ({ "rat" }) );
  SetAdjectives( ({ "large", "brown" }) );
  SetLong(
    "This large rat has fur of a brownish color. It is overly large "
    "for a tunnel-dwelling rat."
    );
  SetClass("animal");
  SetLevel(3);
  SetAction(5, "!emote scratches at the walls of the tunnel.");
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
}
