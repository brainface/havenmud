#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

int PreventLeaveParva();

static void create() {
  ::create();
  SetExits( ([
    "northeast" : PARVA_ROOM "cemetery",
    ]) );
  AddExit("southwest", PARVA_PATH, (: PreventLeaveParva :) );
  SetShort("a rarely used path into the HavenWood");
  SetLong(
    "This lesser-used path of Parva runs from the quiet cemetery right "
    "into the HavenWood itself. Several old trees line the path as it "
    "recedes into the forest, and an opening in the underbrush seems to lead "
    "into a mostly forgotten, forlorn crypt beneath the forest floor."
  );
  SetItems( ([
    "crypt" : "This forlorn crypt does not seem to be abandoned.",
    ({ "tree", "trees" }) : "These old trees have seen better days.",
    ({ "forest", "havenwood", "HavenWood" }) : "The HavenWood is a "
       "large monster of wood and forest.",
    "underbrush" : "The underbrush is short bushes and other growth.",
    ]) );
  SetItemAdjectives( ([
    "crypt" : ({ "mostly", "forgotten", "forlorn" }),
    "tree" : ({ "old" }),
    ]) );
  SetEnters( ([
    "crypt" : PARVA_ROOM "necro",
    ]) );
  SetSmell("The scent of the wood is pleasant and enjoyable.");
  SetListen("This close to the cemetery, even Parva is quiet and reserved.");
  SetInventory( ([
    PARVA_NPC "ranger" : 1,
    ]) );
}

int PreventLeaveParva() {
    if (this_player()->id("parva_wander")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
    if (this_player()->GetProperty("parvanoleave")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
  return 1;
}
