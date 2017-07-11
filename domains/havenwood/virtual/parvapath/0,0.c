#include <lib.h>
#include <domains.h>
inherit "/domains/havenwood/virtual/parvapath.c";
int DomainCheck();

static void create(int x, int y) {
  ::create(0,0);
  AddLong(" A square wooden building sits to the north of the road, surrounded "
    "by orderly piles of animal carcasses. ");
  AddItem( ({"cabin","workshop","tannery","building","wooden building"}),
    "This practical looking building seems to be a workshop of "
    "some sort. Whatever trade it involves requires quite a few "
    "carcasses.");
  AddItem( ({"carcasses","animal carcasses"}),
    "They appear to be the remains of large game animals, stripped of meat and fur.");
  SetSmell("It stinks like a rotten garbage heap.");
  SetEnters( ([
    ({ "building","cabin","tannery","workshop","wooden building"}) :
      HAVENWOOD_AREAS "nat_store/room/cabin"
  ]) );
  SetInventory( ([
    HAVENWOOD_VIRTUAL "sign/parvapath00" : 1,
  ]) );
}

