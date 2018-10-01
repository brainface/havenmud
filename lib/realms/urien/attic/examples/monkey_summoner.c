// This evil bastard summons some wicked vipers
// Yes, They poison you.

#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

void eventSummon();

static void create() {
  ::create();
  SetKeyName("cultist");
  SetShort("a shady cultist");
  SetId( ({ "cultist" }) );
  SetAdjectives( ({ "shady" }) );
  SetRace("elf");
  SetClass("priest");
  SetLevel(40);
  SetLong("The cultist is surrounded by a small blue hue all around "
          "his body. His exposed skeleton reveals some sun bleach, "
          "as if in the sun for a long time. His rounded eyes have "
          "been shaded out from his skin peeling over them and his "
          "exposed bottom half of his face reveals the rot and decay "
          "of this undead being.");
  SetGender("male");
  SetUndead(1);
  SetMorality(-250);
  SetAction(5, (: eventSummon :) );
}

void eventSummon() {
  object buddy;

  eventForce("emote %^BLUE%^BOLD%^waves %^RESET%^his skeleton hands "
             "and smoke appears!");
  buddy = new(STD_NPC "summoner");
  buddy->eventMove(environment());
  buddy->SetFriends( ({ "viper" }) );
  message("system", "Something appears from the smoke cloud!", environment());
}
