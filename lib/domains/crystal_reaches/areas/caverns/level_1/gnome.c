/*  A Gnome's Burrow */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(40);
  SetWarmth(20);
  SetShort("a gnome's burrow");

  SetLong("A single lantern lights up the entire burrow.  The single room "
          "seems divided up into sections by invisible walls and very well "
          "cleaned.  A bed off to one side, a table and some cabinets off to "
          "another.  The rest of the room is filled with a fireplace, a cosy "
          "chair, and several bookcases filled with books lining the walls.  "
          "There is also a nice rug in the center of the room, right in front "
          "of the fireplace.");

  SetSmell( ([
    "default"  :  "The smell of burnt wood radiates from the fireplace and "
                  "permeates the air.  Interwound is the smell of old paper "
                  "and leatherbound books."
  ]) );

  SetListen( ([
    "default"  :  "The fire crackles and pops from time to time to fill the "
                  "quiet of the burrow.",
    "fire"     :  "The fire snaps, crackles, and pops!",
  ]) );

  SetExits( ([
    "east"  :  ROOMLV1 + "/path2",
  ]) );
  SetObviousExits("east");

  SetItems( ([
    ({ "gnome's burrow", "burrow", "gnomes burrow", "room", "single room" })  :
       (: GetLong :),
    ({ "lantern", "single lantern" })  :
       "The single lantern provides all the light that is necessary to see "
       "about the entire room.  It hangs from a chain in the center of the "
       "room.",
    ({ "chain" })  :
       "The chain comes down from the ceiling in the center of the room.  "
       "From the chain hangs a lantern that provides light for the rest of "
       "the room.",
    ({ "ceiling", "unremarkable ceiling" })  :
       "The ceiling is quite unremarkable, a chain hangs down from it in the "
       "center of the room.",
    ({ "bed", "sturdy bed" })  :
       "A well made and sturdy bed, it has a wool blanket and a mattress of "
       "down to lay upon.",
    ({ "wool blanket", "mattress", "down mattress" })  :
       "A wool blanket and a down mattress lay upon the sturdy bed.  The "
       "mattress has been fluffed so there are no lumps in it, and the "
       "blanket has been tucked and smoothed over the mattress. It is almost "
       "too neat for one to sleep in.",
    ({ "table", "cabinets", "cabinet" })  :
       "Off in the corner is the burrows kitchen/dining room consisting of "
       "all of the necessary furniture and items to cook and eat a great "
       "meal.  This area of the room makes the entire burrow look cozy.",
    ({ "fireplace", "fire" })  :
       "A very well made fireplace with a mantle overhead.  The fire inside "
       "gives off the much needed heat to keep the chill and dampness from "
       "the burrow.",
    ({ "mantle", "wooden mantle" })  :
       "The mantle over the fireplace was caringly carved from one large "
       "piece of wood.  It has been carved with flowing designs and gentle "
       "curves.  Upon it sits some of the more recently read books.",
    ({ "books", "book", "bookcases", "bookcase", "several bookcases", "walls",
       "wall" })  :
       "The remaining walls of the burrow are covered with bookcases and, "
       "of course books.  The titles and content vary and it seems that "
       "there is a book on nearly every topic available.  On some of the "
       "shelves lie small tidbits that the gnome has gathered over the "
       "years.",
    ({ "nice rug", "rug" })  :
       "A very nice looking rug, it appears to be taken good care of by it's "
       "owner, as it looks brand new.",
    ({ "chair", "cozy chair", "cozy old chair", "old chair" })  :
       "This cozy old chair appears to be used often, as the cushions are "
       "all lumpy and there is a permanent impression left where the gnome "
       "usually sits.",
    ({ "cushions", "cushion", "lumpy cushions", "lumpy cushion" })  :
       "The lumpy cushions have a permanent impression where the gnome "
       "usually sits.  They rest on the cozy old chair.",
  ]) );

  SetInventory( ([ NPCS + "/gnome" : 1,
  ]) );
}
