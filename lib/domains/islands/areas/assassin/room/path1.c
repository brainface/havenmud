#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_ROOM;

static void  create() {
  ::create();
  SetExits( ([
    "east" : "bay",
    ]) );
  SetClimate("sub-tropical");
  SetShort("along the sandy trail");
  SetLong(
    "The trail continues leading west and up away from the beach. To "
    "the east lies the beach itself, but the palm and cococut trees that "
    "line this sandy path seem to make for an inviting and pleasant "
    "island experience. There is a small and well-tended cabin here."
    );
  SetSmell("The pleasant smells of the beach mix with the smells of fruits and trees.");
  SetListen("Birds caw in the treetops.");
  SetItems( ([
    ({ "tree", "trees" }) : "The trees are both coconut and palm types. Some of the "
                            "coconuts look ripe enough to fall.",
    "cabin" : "This cabin seems sturdy and well-tended.",
    ]) );
  SetItemAdjectives( ([
    "tree" : ({ "palm", "coconut" }),
    ]) );
  SetEnters( ([
    "cabin" : ISLANDS_AREAS "assassin/room/cabin",
    ]) );
  SetDoor("cabin", ISLANDS_AREAS + "assassin/obj/door_001");
  SetInventory( ([
    ]) );
}

void heart_beat() {
  object date;
  ::heart_beat();
  if (!random(20)) {
      date = new(ISLANDS_AREAS "assassin/obj/coconut");
      if (!date) return;
      eventPrint("With a thump, a coconut falls from a tree.");
      date->eventMove(this_object());
  }
}
