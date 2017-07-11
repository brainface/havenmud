//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_FISHING;

static void create() {
  fishing::create();
  SetShort("in the woolcarding area");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetLong(
    "This is a musty room within the weaving workshop devoted to "
    "carding out wool shorn from sheep. This thankless, boring job "
    "takes place in a rather boring room empty of anything except "
    "bales upon bales of fluffy white wool. The only exit from "
    "the tedium is north, through an open doorway. "
  );
  SetItems( ([
    ({ "room", "area" }) : (: GetLong :),
    ({ "bale", "bales" "wool" }) :
    "The bales are of wool in various stages of production into "
    "fabric, and there sure are a lot of them. ",
    ({ "doorway" }) :
    "The doorway leads north.",
  ]) );
  SetItemAdjectives( ([
  "room" : ({ "musty", "boring" }),
  "area" : ({ "woolcarding" }),
  "wool" : ({ "fluffy", "white" }),
  "doorway" : ({ "open" }),
  ]) );
  SetListen("There is a constant scraping noise here.");
  SetSmell("The air smells musty and sheep-like.");
  SetExits( ([
    "north" : LAKE_ROOM "/1h",
  ]) );
  SetInventory( ([
    LAKE_NPC "carder" : 3,
  ]) );
}
