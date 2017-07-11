//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in a papyrus workshop");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetLong(
    "This is the inside of a busy workshop devoted to making paper "
    "from the long stems of papyrus that grow on the lake. Piles "
    "of beaten papyrus fibers and buckets full of the plants stand "
    "here, waiting to be made into sheets and scrolls. There is an "
    "exit out to the lakeside here as well as an open doorway "
    "leading northward. "
  );
  SetItems( ([
    ({ "workshop" }) :
    (: SetLong :),
    ({ "stems", "fibers", "papyrus" }) :
    "Freshly picked papyrus is beaten here to extract the fibrous "
    "insides used to make paper. ",
    ({ "bucket", "buckets", "plants" }) : 
    "Still more papyrus stands in these shallow buckets of water, "
    "just begging to be pounded and plaited together.",
    "doorway" : "The doorway to the north leads into another "
    "busy room of this papermaking workshop.",
  ]) );
  SetItemAdjectives( ([
  "plants" : ({ "papyrus", "waving", "gently" }),
  "fibers" : ({ "beaten" }),
  "stems" : ({ "long" }),
  "workshop" : ({ "papyrus", "busy" }),
  ]) );
  SetListen("A constant pounding is heard here.");
  SetSmell("The papyrus exudes a pungent smell as it is beaten.");
  SetExits( ([
    "north"  : LAKE_ROOM "/5a",
    "out"  : LAKE_ROOM "/6b",
  ]) );
  SetInventory( ([
    LAKE_NPC "papyrusmaker" : 2,
  ]) );
}
