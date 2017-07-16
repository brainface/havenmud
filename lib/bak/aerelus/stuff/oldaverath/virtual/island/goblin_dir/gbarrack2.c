#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("a general's quarters");
  SetLong("This room is quite large and the walls are covered in racks "
     "that hold many swords and other equipment. Although obviously a "
     "weapons room, it serves as quarters for the goblin general. An old "
     "wooden table sits in the middle of the room with a large candle "
     "to afford a bit of light. The floors and walls are dirty and behind "
     "the racks faded images of goblin battles can barely be seen. The "
     "only way out is through a small hole to the west.");
  SetListen( ([
     "default" : "The sounds of goblins bickering comes from the west."
     ]) );
  SetSmell( ([
     "default" : "The smell of dirt and sweaty goblins is stiffling."
     ]) );
  SetItems( ([
     ({"wall","walls"}) : "These stone walls are dark and dirty, showing "
       "the age of the tunnels and muck that has passed through them. "
       "Faded images of great goblin wars are mostly obstructed by the "
       "wood racks that line wall.",
     ({"rack","racks"}) : "These wooden racks are old but seem fairly "
      "sturdy, as they hold all sorts of heavy weapons and armour for "
       "the goblins to arm themselves.",
     ({"sword","swords","equipment","weapons","armour","armours"}) : "Hung "
       "in slight disarray, weapons and armours of various types line "
       "the racks which are set on the walls here. Swords, clubs of all "
       "sizes, axes and knives fill one side of the rack while crude "
       "shields and leather body armours are hung on the other.",
     ({"table"}) : "This wooden table has seen better days. Old and nearly "
       "in a heap, it rests in the middle of the room holding a large "
       "candle to provide light. ",
     ({"candle"}) : "This candle is large and the wax is slightly twisted "
       "giving it a wierd shape. A small flickering flame casts odd "
       "shadows on the walls.",
     ({"floor","ground"}) : "The stone floor is filthy from the trackings "
       "of goblins in and out of this chamber, carrying in muck from the "
       "sewer tunnels.",
     ({"hole"}) : "This fairly small hole has been dug out of the wall "
       "and provides passage to the west, back into the main room of the "
       "goblin barracks.",
     ]) );
  SetInventory( ([
     AVERATH_NPC "hgoblin" : 1,
     ]) );
  SetExits( ([
     "west" : AVERATH_ISLAND "goblin_dir/gbarrack",
     ]) );
}
