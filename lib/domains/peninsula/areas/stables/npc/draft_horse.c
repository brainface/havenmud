#include <lib.h>
inherit LIB_NPC;
inherit LIB_MOUNT;

static void create() {
  ::create();
  SetKeyName("horse");
  SetRace("horse");
  SetGender("male");
  SetShort("a restless draft horse");
  SetId( ({ "horse" }) );
  SetAdjectives( ({ "draft", "restless" }) );
  SetLong(
    "This piebald horse was bred for endurance and strength, though obviously "
    "not for appearance and certainly not personality. He has a strange gleam "
    "in his wide eyes that suggest that he'll get you where you want to go "
    "perhaps before you even want to be there."
  );
  SetAction(2, ({
    "!emote stamps his hoof impatiently.",
    "!emote kicks randomly behind him.",
    "!emote tries to eat something off the ground.",
    "!emote flicks his tail agitatedly.",
  }) );
  SetClass("animal");
  SetStat("strength", 100, 1);
  SetLevel(1);
}

