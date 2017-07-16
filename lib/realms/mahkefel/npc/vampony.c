#include <lib.h>
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("vampire pony");
  SetRace("horse", "pony");
  SetGender("male");
  SetShort("an improbable vampire pony");
  SetId( ({ "pony", "vampire" }) );
  SetAdjectives( ({ "improbable", "vampire" }) );
  SetLong(
    "This pale white pony has dubiously long canines and... normally sized bat wings. "
    "Really, thats like a six inch wingspan there pony. What are you going to do with that? "
    "Seriously though, he just looks like he needs a friend."
  );
  AddLimb("right tiny bat wing","torso",2);
  AddLimb("left tiny bat wing","torso",2);
  
  SetClass("animal");
  SetUndead(1);
  SetUndeadType("vampire");
  SetStat("strength", 100, 1);
  SetLevel(25);
  
  SetAction(5, ({
    "!emote futilely flaps his wings, generating no lift at all.",
    "!emote makes an ominious sucking noise while staring at you suggestively.",
    "!say I'm a little long in the tooth.",
    "!emote gallops diminutively out of the shadows.",
     "!emote really does %^BOLD%^MAGENTA%^F%^RESET%^CYAN%^U%^RESET%^YELLOW%^C%^RESET%^BOLD%^RED%^K%^RESET%^BLUE%^I%^RESET%^MAGENTA%^N%^RESET%^BOLD%^CYAN%^G%^RESET%^ sparkle.",
  }) );
}
