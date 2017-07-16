#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(1,-1,-2);

  SetLong("The darkened tunnels are off to the north, leaving this "
     "room as a little nook. The curved walls block out almost all light "
     "the torches in the tunnels give off, the darkness of the stones "
     "making it only darker. The south wall has a dirty cloth secured "
     "to it, covering something, the other walls as slimy and wet as "
     "the rest of the tunnel. A small pile of trash litters the corner "
     "of the room.");
  SetItems( ([
     ({"wall","walls"}) : "The curved walls are made completely of the "
       "large dark stones that make up the rest of the sewers. A large "
       "soiled cloth covers part of the southern wall.",
     ({"stone","stones"}) : "These large dark stones are fairly smooth "
       "and are covered in filth and muck from the sewers.",
     ({"cloth"}) : "This large dirty cloth is fixed to the southern wall "
       "and flaps a bit as though a breeze flows through it. It appears "
       "to be covering a small hole that could be entered.",
     ({"trash","pile"}) : "A small pile of trash from the sewers has been "
       "gathered here and shoved into the corner.",
     ({"hole"}) : "This small hole is about the right size for a goblin "
       "to squeeze through.",
     ]) );
  SetItemAdjectives( ([
     "wall" : ({"curved","stone"}),
     "cloth" : ({"dirty","soiled","large"}),
     "stone" : ({"large","dark"}),
     "pile" : ({"small"}),
     "hole" : ({"small"}),
     ]) );
  SetEnters( ([
     "hole" : AVERATH_ISLAND "goblin_dir/gbarrack",
     ]) );
  SetInventory( ([
     AVERATH_NPC "fgoblin" : 1,
     ]) );
  RemoveExit("south");
  RemoveExit("west");
  RemoveExit("east");
}
