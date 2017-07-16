
#include <lib.h>
#include <domains.h>
#include "../glim.h"
inherit LIB_CHAPEL;

static void create() {
    chapel::create();
    SetClimate("underground");
    SetAmbientLight(45);
    SetShort("a church of stone");
    SetLong("The church is a large, circular room with a high "
      "ceiling. An altar stands in the center and fires "
      "that burn along the wall provide dim, flickering light. "
      "The altar is an especially large granite block that dominates "
      "the rest of the room. A religious symbol is carved into the "
      "ceiling directly above the altar; it gleams faintly "
      "and partially illuminates the altar. An archway in the "
      "north part of the wall leads back into the town.");
    SetClasses( ({ "cleric" }) );
    SetReligion("Kylin");
    SetTown("Glistendin");
    SetListen( ([
      "default" : "Quiet chanting seems to echo from all directions.",
      ]) );
    SetSmell( ([
      "default" : "Smoke lingers faintly in the air.",
      ]) );
    SetItems( ([
      ({"church", "temple", "room"})  :  (: GetLong :),
      ({"altar", "block"}) :
        "The altar is tremendously large granite block in the center "
        "of the church. It dominates the rest of the room with its "
        "presence.",
      ({"wall", "floor", "surface", "surfaces"}) : 
        "The room was carved directly out of the mountain and all surfaces "
        "are of a polished, dark stone.",
      ({"ceiling"})  :
        "The ceiling is of a polished, dark stone. In its center, directly "
        "above the altar, is a religious symbol that gleams faintly in the "
        "dim light.",
      ({"symbol", "circle"})  : 
       "The Kylin symbol is a large balance, similiar to a set of scales, "
       "surrounded by a wiry red dragon.",
      ({"fire", "fires"})  :
        "Three fires that are at a slightly lower elevation than the rest of "
        "the church silently burn at three evenly spread points along the "
        "circular wall. They provide a dim, flickering light that "
        "illuminates the church.",
      ({"archway"}) :
        "A stone archway leads back to the town.",
      ({"stone", "rock"}) :
        "The temple is made from polished, dark stone.  It is faintly warm.",
      ({"smoke"})  :
        "The smoke is nearly completely invisible in the dark church, but "
        "it can vaguely be seen lingering in the air.",
       ]) );
    SetItemAdjectives( ([
      "church"  :  ({"large", "round", "stone", "dimly lit"}),
      "room"  :  ({"large", "round", "stone", "dimly lit"}),
      "temple"  :  ({"large", "round", "stone", "dimly lit"}),
      "altar"  :  ({"tremendous", "large", "granite", "huge", "center"}),
      "block"  :  ({"tremendous", "large", "granite", "huge"}),
      "wall"  :   ({"circular", "stone", "dark", "smooth"}),
      "surface"  :   ({"circular", "stone", "dark", "smooth"}),
      "surfaces"  :   ({"circular", "stone", "dark", "smooth", 
        "south part of the", "southern"}),
      "floor"  :  ({"circular", "stone", "dark", "smooth"}),
      "ceiling"  :  ({"circular", "stone", "dark", "smooth", "high"}),
      "symbol"  :  ({"religious", "large", "kylin", "carved", "gleaming"}),
      "fire"  :   ({"large", "flickering", "silent"}),
      "fires"  :  ({"large", "flickering", "silent"}),
      "archway"  :  ({"southern", "stone"}),
      "stone"  :  ({"polished", "dark", "warm", "faintly warm"}),
      "rock"  :  ({"polished", "dark", "warm", "faintly warm"}),
      "smoke"  :  ({"nearly completely invisible", "invisible", "lingering"}),
      ]) );
    SetInventory( ([
      G_NPC "priest" : 1,
      ]) );
    SetExits( ([
     "north" :  AVERATH_ISLAND "-8,-3,0",
     "down"  :  G_ROOM "cemetery",
    ]) );
}
