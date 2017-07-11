//Selket@Haven
//2006
#include <lib.h>
#include "../mastaba.h"
inherit LIB_ROOM;
int GuardTest();

static void create() {
  room::create();
  SetClimate("underground");
  SetWarmth(30);
  SetAmbientLight(15);
  SetShort("in an antechamber");
  SetLong(
    "This antechamber used to be filled with treasure. Now little "
    "remains from what was once a vast supply of wealth. Most of the "
    "jewelry and valuables have been stolen, leaving empty spaces in "
    "the dust behind, but the old rotted furniture and foodstuffs "
    "remain. An opening leads back out of the mastaba and another "
    "tiny hole continues downward into a final small chamber."
    );
  SetSmell( ([
    "default" : "The scent of decay here is overwhelming.",
    ]) );
  SetListen( ([
    "default" : "Oddly enough, it is as silent as the grave.",
    ]) );
  SetProperty("no teleport",1);
  SetItems( ([
    ({ "treasure", "wealth", "jewelry", "valuables", "spaces" }) :
      "There isn't anything left. It's all been pilfered away. ",
    ({ "floor", "dust" }) :
      "The stone floor is thickly covered with the dust of ages. ",
  ({ "food", "foodstuffs", "foodstuff" }) :
    "The food is ancient and decayed, and hardly worth taking "
    "with you or eating. Most of it is moldy enough to give you "
    "the worst tummyache of your life.",
  "furniture" : "The furniture consists of rotted away masses "
    "that may once have been chairs, chariots, and beds."
      "None of it is worth inspecting or taking with you. ",
    ({ "hole" })  :
      "There seems to be another room down there. ",
    ]) );
  SetItemAdjectives( ([
    "furniture"    : ({ "rotted" }),
    "foodstuffs"    : ({ "rotted" }),
    "hole"     : ({ "tiny" }),
    ]) );
  SetExits( ([
    "up" : MASTABA_ROOM "mastaba1",
    ]) );
  SetInventory( ([
    MASTABA_NPC "statue" : 2,
  ]) );
  AddEnter("hole", MASTABA_ROOM + "mastaba3", (: GuardTest :) );
}
int GuardTest() {
   object guard;
   object who;
   who = this_player();
  guard = present("statue", this_object());
  if (this_player()->id("statue")) return 1;
  if ( (guard) && (living(guard)) ) {
     guard->eventForce("speak Leave this place or die!");
    guard->eventForce("scream "+who->GetKeyName());
    return 0;
   }
   return 1;
  }
