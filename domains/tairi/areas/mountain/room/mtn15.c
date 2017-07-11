//Selket@Haven
//2006

#include <lib.h>
#include "../mtn.h"

inherit LIB_ROOM;

int TriggerQuest(string);

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("on a steep path up the side of Shatadru Mountain");
  SetLong(
    "The snow here stands in small heaps, untouched by winds "
    "in this oddly still place. In the briskly cold air shines "
    "a heavenly light that reflects upon the clouds so close "
    "that they seem touchable. The summit of the mountain is "
    "just above."
  );
  SetItems( ([
    ({ "snow", "heap", "heaps" }) : 
    "The lack of wind here keeps the snow from distributing "
    "evenly, but it is still white and pure.",
    ({ "light", "clouds", "cloud" }) : 
    "The heavens hang just overhead, as if they might be "
    "reachable from this quiet place.",
    ({ "summit" }) :
    "The mountain peak is just above.",
  ]) );
  SetItemAdjectives( ([
    "heaps" : ({ "small" }),
    "light" : ({ "heavenly" }),
    "summit" : ({ "mountain" }),
  ]) );
  SetExits( ([
    "southeast" : MTN_ROOM "/mtn14",
  ]) );
  AddExit("up", MTN_ROOM "/mtn16", 0, (: TriggerQuest :) );
  SetListen("The snowy mountainside is bathed in silence.");
}

int TriggerQuest(string dir) {
  if (!(this_player()->GetQuestCompleted("Mount Shatadru"))) {
    this_player()->AddQuest("the Enlightened Climber", "Mount Shatadru");
    this_player()->eventPrint("%^BOLD%^GREEN%^You have reached the peak of Mount Shatadru!%^RESET%^");
    this_player()->AddDevelopmentPoints(2);
    }
  return 0;
}
