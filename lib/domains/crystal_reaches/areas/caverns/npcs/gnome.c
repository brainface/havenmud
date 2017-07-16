/*  Gnome of the Caverns  -  Level #1 Caverns  */

#include <lib.h>
#include <std.h>
#include "../caves.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("gnome");
  SetId( ({ "gnome" }) );
  SetAdjectives( ({ "proud", "old" }) );
  SetShort("a proud old gnome");

  SetLong("Looking much like a thin dwarf the old gnome posseses a beard, "
          "which he is obviously proud of as it is cut short and neatly "
          "trimmed.  Also, the gnome takes great pride in the large nose that "
          "is his race's distinguishing feature.  The gnome is otherwise "
          "pretty ordinary with a dark tan complextion and a hint of grey, "
          "eyes the color of blue-grey slate, and sandy brown hair.");

  SetRace("gnome");
  SetClass("evoker");
  SetLevel(9);
  SetGender("male");
  SetMorality(250);
  SetDie("The Gnome spends his last breath defending his burrow.");

  SetAction(12, ({ "The Gnome is totally absorbed by the book he is reading.",
                   "The Gnome glances over to the fire then goes back to "
                   "reading his book.",
                   "The Gnome snickers at something in the book and mumbles "
                   "something to himself.",
  }) );

  SetSpellBook( ([
    "aura"     :  100,
    "ice ball" :  100,
    "buffer"   :  100,
    "missile"  :  100,
    ]) );

  SetCombatAction(60, ({ 
  	"!cast aura",
    "!cast ice ball",
    "!cast buffer",
    "!cast missile",
    }) );

  SetTalkResponses( ([
    ({ "chasm" })  :
       "All I know about the chasm is that it has a beautiful view from a "
       "ledge along it during the day.  If you want to know more you should "
       "probably ask the bridge builder there.",
    ({ "caves", "cave", "caverns", "cavern" })  :
       "I don't really know much about the caverns, I haven't really tried "
       "or want to explore them.  If you want to know more about them you "
       "could try the bridge builder, I understand he wants to explore the "
       "full length of them eventually.",
    ({ "hag" })  :
       "Oh her, she's always too busy writing this or that about her dumb "
       "potions.  I think it's a big waste of time myself, who's going to "
       "care what happens when you mix and heat different liquids together?.",
    ({ "potions", "potion", "liquid", "liquids" })  :
       "Potions!!! What am I supposed to know about potions!  Ask the Old "
       "Hag and let me be with my book.",
    ({ "kobold", "kobolds" })  :
       "I have plenty of trouble with those bastards, always trying to come "
       "in and get me in my own burrow.  Of course they're too stupid to "
       "realize that they're no match for me and I slaughter them.  I would "
       "go and totally clear out their lair, but I would rather sit here and "
       "read.",
    ({ "burrow" })  :
       "How do you like it?  I think it's all I'll ever want or need with my "
       "books and all.",
    ({ "lair" })  :
       "The Kobold Lair is just a little ways away off of the cavern closest "
       "to my burrow.  If you want to go and kill them I'd be most "
       "grateful.",
    ({ "builder" })  :
       "Oh he's down deeper into the caverns by the chasm building a bridge.  "
       "Some nonsense about wanting to explore the depths of them.  "
       "Personally I think he's barmy, but that's my opinion.",
    ({ "book" })  :
       "The book that I'm currently reading is about an old wizard, tweleve "
       "dwarves, and a halfling theif.  It's pretty good too, you should "
       "read it if you get the chance.",
    ({ "books" })  :
       "Oh, my books, I have too many to remember them all but I have read "
       "each one in my bookcase.  Then I always go back and reread them so "
       "I can experience each one all over again.",
  ]) );
  SetInventory( ([ OBJS + "/book"   : 1,
                   OBJS + "/shirt1" : "wear shirt",
                   OBJS + "/pants1" : "wear pants",
                   OBJS + "/belt1"  : "wear belt",
                   STD_KNIFE + "small_knife" : "wield knife",
              
  ]) );
}
