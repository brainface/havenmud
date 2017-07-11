// Inn Place
// Updated by Ranquest 29th Jan 1999

#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the Weary Traveler Inn");
  SetInventory( ([
    SOUTHERN_COAST_AREAS "wtraveller/npc/pjack" : 1,
    SOUTHERN_COAST_AREAS "wtraveller/npc/wtpatron" : random(3)+1 ])
    );
  SetSmell( ([
    "default" : "The Inn smells of beer and stew, with a hint of freshly baked bread.",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(40);
  SetExits( ([
    "out" : SOUTHERN_COAST_VIRTUAL + "havenroad/0,0",
     ]) );
  SetNewsgroups( ({ "player.general" }) );
  SetDayLong(
    "Sunlight shines in through the square windows of the  "
    "inn, glinting off the rack of mugs over the bar.  A "
    "number of rectangular, heavy oaken tables are set up "
    "about the room, most of them looking a bit worn.  On "
    "the west wall there is a fireplace with a couple of "
    "half burnt logs in it along with a large volume of "
    "ashes."
    );
  SetNightLong(
    "A roaring, crackling fire in the fireplace on the  "
    "west wall sheds light throughout the inn and casts "
    "odd shadows about.  A half-filled rack of mugs hangs "
    "above the bar, and a number of heavy oaken tables "
    "are placed about the room.  The windows show only "
    "darkness outside, and the "
    "inn, though fairly quiet, has a cheery atmosphere "
    "tonight."
    );
  SetItems( ([
    ({"fireplace"}) :
                 "The fireplace is made of red brick and is "
                 "set about a foot back into the wall. "
                 " A brick ledge extends out above the "
                 "fireplace with an old clock sitting on "
                 "it.  An old, cast-iron poker leans up "
                 "against the wall nearby.",
    ({"clock"}) : 
                 "The clock is made of hickory wood with a "
                 "glass face and two rusted metal hands "
                 "behind that.  It's stopped at two forty.",
    ({"face"}) : 
                 "The glass face of the clock is quite "
                 "dirty.",
    ({"hands","clock hand","hand"}) :
                 "The clock hands are straight, simple pieces of "
                 "iron, though they're nearly rusted through.",
    ({"poker" }) :
                 "The poker is a straight piece of black metal "
                 "with a pointed tip and a cylindrical handle.",
    ({"handle"}) :
                 "It's a rounded piece of metal joined to the poker.",
    ({"mug","mugs", "construct"}) :
                 "This simple wooden construct is attached to the "
                 "ceiling above the bar.  It is a long piece of wood "
                 "with numerous pegs attached, "
                 "with a number of mugs hanging from them.",
    ({"windows","window","holes","hole","square"}) :
                 "The windows are simple, square holes in the wall with "
                 "a single pane of glass set in them.  Despite "
                 "this, though, they seem to insulate well.",
    ({"pane","glass"}) :
                 "The glass in the windows is a bit dirty and contains "
                 "a number of warps and bubbles.",
    ({"warps and bubbles", "bubbles and warps","bubbles","warps"}) :
                 "A number of warps and bubbles clearly show that "
                 "the glass was not made by an expert.",
    ({"tables","table"}) :          
                 "The tables are sturdy, if a bit worn, simple "
                 "constructions of heavy oak wood.  A number "
                 "of stains and carvings cover their surfaces.",
    ({"stains and carvings","carvings and stains","stains","carvings"}) :
                 "The stains are mostly circular, probably caused "
                 "by the bottom of beer mugs, though the "
                 "carvings are a bit more varied.  Most are straight "
                 "cuts, but the occasional heart and "
                 "initials can be seen, along with similar carvings.",
    ({"counter"}) :
                  "The bar is made of the same heavy oak as the tables."
                  "  It is a simple straight counter with rounded edges.",
    ({"pegs","peg"}) :
                  "The pegs are made of small, round pieces of wood, "
                  "extending downward from the rack.",
    ({"shadows","shadow"}) :
                  "Like most shadows, they are rather dark and are more "
                  "numerous around the tables.",
    ({"mugs","mug"}) :
                  "The mugs hanging from the rack look spotless and bear"
                  " the trademark shapes of the Weary Traveler Inn: "
                  "short and heavy.",
    ({"ledge"}) :
                  "The ledge extends roughly two inches out from above "
                  "the fireplace and is made of red brick.",
    ({"brick", "bricks"}) :
                  "The bricks at the Weary Traveler Inn are all made "
                  "of a reddish stone.  They look quite "
                  "sturdy, despite their obvious age.",
    ({"wall"}) :
                  "The west wall is made of oak wood, as is the rest "
                   "of the inn.  It is flat and rather "
                   "featureless except for the fireplace inset in it.",
    ({"log","logs"}) :
                  "These logs look to have once been the trunk of a "
                  "great pine tree, but they have been "
                  "burned in the fire for quite a while, and now "
                  "only about half of them remains.",
    ({"ashes"}) :
                  "A large pile of ashes rests under the logs of the "
                  "fireplace, evidence of many days of a roaring fire. "
                  " It doesn't look like anyone has bothered to clean "
                  "them up in quite some time.",
    ({"fire"}) :
                  "From the amount of ashes in the fireplace, it "
                  "would seem that the Inn has a roaring fire every "
                  "night to keep the patrons warm.  In the day, though, "
                  "it is extinguished to save wood.",
    "inn" : (: GetLong :)

    ]) );

    SetItemAdjectives( ([
        "fireplace"    :  ({"red", "brick"}),
        "clock"        :  ({"old", "dirty"}),
        "face"         :  ({"glass", "dirty"}),
        "hands"        :  ({"clock", "metal", "rusted"}),
        "poker"        :  ({"old", "cast", "iron", "metal"}),
        "handle"       :  ({"cylindrical", "rounded", "peice", "metal"}),
        "rack"         :  ({"wooden", "mug", "mugs", "half-filled", "half", "filled"}),
        "window"       :  ({"square", "holes", "hole"}),
        "pane"         :  ({"glass", "damp"}),
        "counter"      :  ({"straight"}),
        "pegs"         :  ({"small", "round", "wood", "wooden"}),
        "shadows"      :  ({"odd", "dark"}),
        "mugs"         :  ({"heavy", "stout", "short"}),
        "ledge"        :  ({"red", "brick"}),
        "brick"        :  ({"red"}),
        "wall"         :  ({"west", "wood", "wooden"}),
        "logs"         :  ({"half", "half-burnt", "burnt"}),
        "table"        :  ({"heavy", "oaken", "sturdy", "wood", "wooden"}),
        "ashes"        :  ({"dark", "pile", "pile of"}),
        "fire"         :  ({"roaring", "crackling"}),
        ]) );
}
/* Approved by Balishae on Wed Jul  2 15:58:14 1997. */
