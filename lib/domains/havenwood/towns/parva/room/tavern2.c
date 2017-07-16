#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a softly lit and well appointed room above the tavern");
  SetExits( ([
    "down" : PARVA_ROOM "tavern",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong(
    "This chamber is lavishly furnished with several sturdy endtables "
    "of varying heights, velvety upholstered armchairs, and soft "
    "luscious rugs. A large, comfortable bed swathed in dark red velvets "
    "and silks stands in one corner of the room. Perfectly placed candelabrae "
    "studded with long white tapers cast a soft glow into the room."
    );
  SetSmell("The candles burn a delightful scent into the air.");
  SetListen("Soft music seems to be enchanted to play in the chamber.");
  SetItems( ([
    ({ "table", "tables", "endtables", "endtable" }) : "The sturdy endtables "
        "vary in height.",
    ({ "chair", "chairs", "armchairs", "armchair" }) : "The armchairs are "
       "velvety and appear very comfortable.",
    ({ "rug", "rugs" }) : "The rugs appear large and comfortable enough to "
       "sleep on. If sleeping was something one wished to do here.",
    ({ "bed" }) : "The bed is swathed in silk and velvets.",
    ({ "candle", "candles", "candelabra", "candelabrae" }) : "The candles "
       "give off a pleasant scent as they burn.",
    ]));
  SetInventory( ([
    PARVA_NPC "aria_whore" : 1,
    ]) );
  SetWarmth(50);
}