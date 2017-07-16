#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("in a brown tent");
   SetDomain("WestWood");
   SetLong("The brown tent canvas casts a strange perspective on "
           "everything as it tints a nice brown color to all the "
           "objects inside.  There are six sleeping bags lain "
           "across the ground, sprawled out with generous space "
           "give each.  The tent is open, so can be left by going "
           "out.");
   SetItems( ([
                ({ "brown tent","tent" }) :
                   (: GetLong :),
                ({ "sleeping bags","bag","bags","piles","pile" }) :
                   "The sleeping bags are blankets sewn together "
                   "into a sleeve-like object, then sewn up at the "
                   "bottom.  They come in a variety of colors, but "
                   "all look rather brown right now.  They are "
                   "scattered all over the tent floor, and are "
                   "ruffled up into messy piles.",
                ({ "tent floor","floor","ground" }) :
                   "The floor of the tent is brown like the rest of it, "
                   "and seems mostly flat.  There is a lump in it that "
                   "probably comes from some root going under the tent, "
                   "or a rock.  At any rate, none of the sleeping bags "
                   "go even close to that area of the tent, avoiding "
                   "it like the plague so they don't have a bad night's "
                   "sleep.",
                ({ "icky lump","lump","root","rock" }) :
                   "The lump looks like it would be very uncomfortable "
                   "to sleep on, which is probably why none of the "
                   "sleeping bags are near it.",
                ({ "brown tent canvas","wall","walls","material" }) :
                   "The 'walls' of the tent are made of a brown "
                   "material, as well as the floor, giving the entire "
                   "area a brown hue.  It is a thick, rough material, "
                   "and would probably be very uncomfortable in clothing.",
           ]) );
   SetItemAdjectives( ([
                         "lump" : ({ "icky" }),
                         "bag" : ({ "sleeping","messy" }),
                         "canvas" : ({ "brown","tent","thick","rough" }),
                    ]) );
   SetListen( ([
                 "default" : "Boisterous noise comes from outside.",
            ]) );
   SetSmell( ([
                "default" : "The tent smells sleepy.",
           ]) );
   SetExits( ([
                "out" : H_ROOM + "campfire",
           ]) );
   SetInventory( ([
                    H_NPC + "camp_sl" : 2,
                    H_NPC + "camp_ex" : random(3),
               ]) );
}
