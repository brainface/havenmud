#include <lib.h>
#include "../../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : GUROV_ROOM "cr2",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("inside a cozy house");
  SetLong(
    "The house is small but cozy, with a single room serving as all manner "
    "of living space. The floor is covered with thick bearskin rugs lying "
    "near a fireplace that also serves as cooking space. Arranged around the "
    "room are various chairs and tables, but nothing of wealth is displayed. "
    "The wooden walls are covered with thick skins to help keep the heat inside "
    "the house."
    );
  SetItems( ([
    "floor" : "The floor is wooden and covered in areas by bearskin rugs.",
    "fireplace" : "The fireplace is thick stone and also serves as cookspace.",
    ({ "chair", "chairs" }) : "The chairs are crude and wooden, but functional.",
    ({ "table", "tables" }) : "The tables are crude and wooden, but functional.",
    "walls" : "The walls are covered with skins.",
    ({ "rug", "rugs", "skin", "skins", "bearskin", }) : "The skins are thick bearskin.",
    ]) );
  SetItemAdjectives( ([
    "walls" : ({ "wooden" }),
    "rug" : ({ "thick", "bear", "bearskin", "skin" }),
    ]) );
  SetInventory( ([
    GUROV_NPC "newbie" : 1,
    ]) );
  SetSmell( ([
    "default" : "The fireplace leaves a hint of ash in the air.",
    ]) );
  SetListen( ([
    "default" : "The crackle of the fire is inviting.",
    ]) );
  SetWarmth(60);
}