#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a cabin");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "The cabin has the air of a place that is visited frequently. "
    "A large mahogany desk rests under a large bay window with a "
    "unobscured view of the rolling ocean. The bay window has a "
    "flowing set of fine elf skin curtains, centering the cabin is "
    "a large gnoll hide rug. A large four-poster bed is against the "
    "right hand wall draped in finest muezzin fur. The left hand wall "
    "is lined with a five tiered shelf which holds many nautical tools and devices."
   );
  SetItems( ([
    "desk" : "This desk is large and made of mahogany.",
    "window" : "This window looks out over the island.",
   ({ "curtain", "curtains" }) : "The curtains appear to have been made of elf skin!",
    "rug" : "This rug was made from the hides of Xandrian gnolls.",
    "bed" : "This is a large four-poster bed. It is draped in muezzin fur.",
    "fur" : "This bed covering is made of muezzin fur.",
    "shelf" : "This is a five tiered shelf.",
   ({ "tool", "tools", "device", "devices" }) : "These are instruments for sailors.",
   ]) );
  SetItemAdjectives( ([
    "desk" : ({ "mahogany" }),
    "window" : ({ "bay" }),
    "curtain" : ({ "elf", "elven", "skin" }),
    "rug" : ({ "gnoll", "hide", "large" }),
    "bed" : ({ "four", "poster", }),
    "fur" : ({ "muezzin" }),
    "shelf" : ({ "five", "tier", "tiered" }),
    "tool" : ({ "various", "nautical" }),
    ]) );
  SetSmell("A breeze comes in off the beach.");
  SetListen("Tropical birds caw outside.");   
  SetExits( ([
    "out" : "path1",
  ]) );
  SetDoor( "out", ISLANDS_AREAS "assassin/obj/door_001");
  SetInventory( ([
    ISLANDS_AREAS "assassin/obj/chest" : 1,
    ]) );
}