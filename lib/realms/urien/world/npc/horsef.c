// A newbie level npc to slay
// To add to the world roadmap package
// Urien 5/29/23

#include <lib.h>
inherit LIB_NPC;
static void create(){
  ::create();
  SetId(({"horse"}));    
  SetShort("a wild horse");
  SetLong("The horse appears to be a much larger variety "
           "of equine however more clumsy in stature. She "
           "has broad and vascular muscles that compliment her "
           "massive brown frame. Due to its slightly muddy "
           "and ungroomed appearance it is unlikely "
           "it has had an owners care last few years of "
           "her life. The long black mane rests pressed "
           "mid neck of the beast with loose bits of "
           "grass blades stuck in it show no particular "
           "signs of grooming.");
  SetRace("horse");
  SetGender("female");
  SetClass("animal");
  SetKeyName("horse");
  SetLevel(random(4) + 2);
}
