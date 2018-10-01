#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("turkey");
  SetRace("bird");
  SetGender("male");
  SetShort("angry crazy ghost turkey");
  SetId( ({ "turkey", "ghost",  }) );
  SetAdjectives( ({ "angry", "crazy", "ghost", }) );
  SetLong(
    "The turkey looks like he has had enough of you and your "
    "thanksgivings and you sanity. His eyes are dark whorls "
    "and he's wearing a straight jacket that's way too big for a turkey. "
    "You can kind of see through him because he totes a ghost."
  );

  SetClass("rogue");
  SetLevel(10);

  SetAction(5, ({
    "!emote hangs from the ceiling, waiting to spook you.",
    "!emote flies angrily after you, turkey feathers going everywhere!",
    "!say GOBBLE GOBBLE! GOOOOOBBBBBLLLLEEE!",
    "!emote sits facing the corner, waiting for you to walk towards him so he can turn around and scare you.",
    "!emote flickers in and out of existance.",
    "!emote puts on a surgeon's mask. It doesn't really fit.",
    "!emote 's mouth opens impossibly wide, for a turkey. So like it's like, six inches, top."
    }) );
}

