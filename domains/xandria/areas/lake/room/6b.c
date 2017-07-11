//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a papyrus-covered bank");
  SetClimate("arid");
  SetLong(
    "This bank of Lake Rantera is completely covered with the tall "
    "gently waving papyrus plants used to make paper in the nearby "
    "workshop. Several plants are shorter than the rest, shorn off "
    "by the machetes carried by those who gather the papyrus, and "
    "other plants are in bloom, their blue-white flowers dipping "
    "gently into the waters of the lake. The lake stands to the "
    "east, while the papyrus workshop stands here to the west."
  );
  SetItems( ([
    ({ "bank" }) :
    (: SetLong :),
    ({ "plants", "plant", "papyrus" }) :
    "The papyrus plants wave slightly in the soft breeze. ",
    ({ "water", "waters", "lake" }) : 
    "The waters of the lake are calm and mostly clear.",
    ({ "flower", "flowers" }) : 
    "The papyrus lilies are china-blue in color.",
    ({ "workshop", "building" }) :
    "This here is the open door to the papyrus workshop.",
  ]) );
  SetItemAdjectives( ([
  "plants" : ({ "papyrus", "waving", "gently" }),
  "ring" : ({ "faerie" }),
  "flowers" : ({ "blue-white", "papyrus" }),
  "workshop" : ({ "papyrus" }),
  ]) );
  SetListen("The breeze rustles the plants.");
  SetSmell("The flowers exude a pleasant fragrance.");
  SetExits( ([
    "north"  : LAKE_ROOM "/5b",
    "east"  : LAKE_ROOM "/6c",
  ]) );
  SetEnters( ([
    ({"workshop", "building"})  : LAKE_ROOM "/6a",
  ]) );
  SetInventory( ([
    LAKE_NPC "gatherer" : 1,
    LAKE_NPC "ibis" : 2,
  ]) );
}
