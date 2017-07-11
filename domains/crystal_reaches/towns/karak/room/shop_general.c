// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Karak General Store");
  SetLong(
    "An elaborate and somewhat haphazard system of shelves and bins "
    "lines the walls and floors of this room. A dizzying array of "
    "items rests on the shelves and nearly bursts from the bins. The "
    "room itself is simple but sturdy in construction, made from local "
    "wood, created to be durable rather than decorative. A doorway "
    "is excised from the southern wall and connects this general store "
    "to the armoury."
  );
  SetItems( ([
    ({ "shelves", "shelf", "bins", "bin", "wall", "walls", "floor" }) :
    "Bins are haphazardly scattered across the floor and shelves are "
    "strewn across the wall in an equally random pattern. A perfusion "
    "of items occupies all avaliable space, with no particular "
    "organization or theme.",
    ({ "items", "item", "goods", "wares" }) : "The goods are of no "
    "particular type, but are instead a general selection of items "
    "which an adventurer might find useful.",
    ({ "room", "store" }) : (: GetLong :),
    ({ "wood" }) : "The wood which forms this room appears to be from "
    "trees harvested locally.",
    ({ "doorway", "way" }) : "An opening is cut into the southern wall "
    "of the general store and through it can be seen the Karak armoury.",
  ]) );
  SetItemAdjectives( ([
    "shelves" : ({ "elaborate", "haphazard", "haphazardly", "system", 
    "lining", "scattered", "random", "pattern", "strewn" }),
    "items" : ({ "array", "dizzying", "perfusion", "bursting", "general" }),
    "room" : ({ "general" }),
    "wood" : ({ "local", "wall", "floor" }),
    "doorway" : ({ "door" }),
  ]) );
  SetSmell( ([
    "default" : "There is an odor of smoke, leather, and wood.",
  ]) );
  SetListen( ([
    "default" : "The quiet hum of commerce fills the air.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "shop_gen" : 1,
  ]) );
  SetExits( ([
    "south" : KARAK_ROOM + "shop_armoury",
    "out"   : KARAK_ROOM + "rd4",
  ]) );
}
