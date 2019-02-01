/*
 * A mausoleum in Arcanith. AKA Necrohome
 *  - mel 2019-01-31
 */ 

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort("a well-kept mausoleum");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetExits( ([
    "out"  : ROOM "/cemetary",
  ]) );

  SetLong("This mausoleum sits in stark constrast to the rest of the"
          " ruins in this place. The masonry is dark grey and smooth"
          " in appearance without a hint of decay or cracking. On the"
          " three walls across from the entrance the masonry recedes"
          " to create benches within the stonework that have small"
          " windows above them covered with cast-iron grates. The"
          " center of the room houses a sarcophagus that is adorned"
          " with a variety of potentially mystical objects including"
          " candles, chalk, vials of various fluids and other more"
          " esoteric and less easily identifiable things.");

  SetItems( ([
    ({ "mausoleum" }):
       (: GetLong :),
    ({ "walls", "stones", "masonry", "stonework" }):
       "The walls are made of a dark grey stone and is free of any signs"
       " of decay or cracking. The three walls opposite the entrance have"
       " small recessions creating benches with small windows covered by"
       " cast-iron grates.",
    ({ "grates", "windows" }):
       "The windows are small and covered with cast-iron grates. The grates"
       " are in a crosshatch pattern which prevents anything larger than a"
       " small mouse from passing through them.",
    ({ "entrance", "door" })  :
       "The entrance is on the south side of the building. It has a stone"
       " slab for a door which hangs open. The size of the door suggests"
       " it is not easily opened or closed.",
    ({ "sarcophagus", "coffin" })  :
       "The sarcophagus in the middle of the room is made of a smooth dark"
       " gray stone that matches the walls. With the exception of the items"
       " on top of it, it is undecorated and beautiful in its simple austerity.",
    ({ "objects", "candles", "chalk", "vials", "fluids", "things" })  :
       "Various mystical and arcane objects adorn the sarophagus in the middle"
       " of the mausoleum. These objects include candles, chalk, vials of"
       " unnamed fluids and other more esoteric and unidentifiable objects.",
    ({ "ruins" }):
       "The ruins of Arcanith can be seen outside.",
  ]) );
  SetItemAdjectives( ([
    "walls":
      ({ "grey", "dark", "dark grey", "gray", "smooth" }),
    "grates":
      ({ "cast-iron", "metal", "iron", "crosshatch" }),
    "door":
      ({ "stone", "slab", "open" }),
    "sarcophagus":
      ({ "stone", "smooth", "austere", "grey", "gray" }),
    "objects":
      ({ "mystical", "esoteric" }),

   ]) );
  SetSmell( ([
    "default"  : "The earthy scent of cemetary dirt permeates the area.",
  ]) );
  SetInventory( ([
     NPC "/necro" : 1,
     NPC "/skeleton" : 1,
  ]) );

}
