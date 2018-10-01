/* A spiffy example NPC that summons stuff. */
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

void eventSummon();

static void create() {
  ::create();
  SetKeyName("wicked monkey");
  SetShort("a wicked looking monkey");
  SetId( ({ "monkey" }) );
  SetAdjectives( ({ "wicked", "looking" }) );
  SetRace("primate");
  SetClass("animal");
  SetLevel(5);
  SetLong("This is a wicked looking monkey. The "
           "gleam in his eye suggests he knows "
           "something you do not.");
  SetGender("male");
  SetAction(5, (: eventSummon :) );
}

void eventSummon() {
  object buddy;

  eventForce("emote %^BLUE%^BOLD%^whistles "
              "%^RESET%^a high pitched squeek!");
  buddy = new(STD_NPC "summoner");
  buddy->eventMove(environment());
  buddy->SetFriends( ({ "monkey" }) );
  message("system", "A new monkey arrives.", environment());
}
