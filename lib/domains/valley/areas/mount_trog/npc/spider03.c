#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("rat");
  SetRace("rodent");
  SetGender("female");
  SetShort("a large grey rat");
  SetId( ({ "rat" }) );
  SetAdjectives( ({ "large", "grey" }) );
  SetLong(
    "This large rat has fur of a greyish color. It is overly large "
    "for a tunnel-dwelling rat."
    );
  SetClass("animal");
  SetLevel(2);
  SetAction(5, "!emote scratches at the walls of the tunnel.");
  SetMeleeAttackString("claws");
  SetMeleeDamageType(SLASH);
}
