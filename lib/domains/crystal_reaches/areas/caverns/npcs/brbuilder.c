/*  The Bridge Builder - Level #2 Caverns  */

#include <lib.h>
#include "../caves.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("bridge builder");
  SetId( ({ "bridge builder", "builder" }) );
  SetAdjectives( ({ "built" }) );
  SetShort("a bridge builder");

  SetLong("The Bridge Builder is used to the tedious work of working in such "
          "a harsh and unyielding environment.  After working so long he has "
          "a built body and seems very proficient with his hammer.  He looks "
          "very friendly, and would be happy to quit working and talk with "
          "anybody.");

  SetRace("human");
  SetClass("fighter");
  SetLevel(5);
  SetGender("male");
  SetMorality(250);
  SetDie("The bridge builder falls into the chasm as he dies.");

  SetAction(5, ({"The bridge builder works... on the bridge of course!",
                 "The bridge builder hammers something into the wall with his "
                 "hammer.",
                 "The bridge builder looks over his work with satisfaction",
                 "!say If you have any questions about the caverns feel free "
                 "to ask me.",
  }) );

  SetCombatAction(5, ({ "The bridge builder uses the narrow ledge to his "
                        "advantage.",
                        "As the bridge builder misses he hits the wall sends "
                        "chips of rock flying in all directions.",
  }) );

  SetTalkResponses( ([
    ({ "chasm" })  :
       "The chasm is wonder of these caverns, it is an impressive sight to "
       "see.  Speaking of wonderous sights you should check out the ledge to "
       "the north of here, during the day it is very impressive.  Anyways the "
       "chasm interupted my search of these caverns so I decide to build a "
       "bridge in order to complete my search.",
    ({ "ledge" })  :
       "Go and see for yourself, it's a sight so amazing that it can't be put "
       "into words.",
    ({ "caverns", "cavern", "caves", "cave" })  :
       "These caverns are rumored to run deep under the ground.  I came to "
       "see just how far down they go and to see what's down there.  Besides "
       "after seeing the sight from the top of the waterfall, I want to see "
       "sight from the bottom!",
    ({ "waterfall" })  :
       "What did you think that unrelenting racket is?!",
    ({ "bottom", "bottom of chasm" })  :
       "I'm not sure what's at the bottom of the chasm, but I expect that "
       "there'll be a large underground lake at the bottom of the waterfall.  "
       "Aside from that I'm not sure, and I'd like to find out myself.",
    ({ "lake", "large underground lake", "large lake", "underground lake" })  :
       "How am I supposed to know anything about that, I don't even know if "
       "that exists at all!!!",
    ({ "bridge" })  :
       "Work is on the bridge is coming along nicely, although it will take "
       "me a while working by myself.",
    ({ "work" })  :
       "Work is coming along nicely, but it gets pretty lonely sometimes.  I "
       "just have to see what's further on don't I?",
    ({ "old hag", "hag" })  :
       "The old hag is a good friend of mine, although sometimes I worry "
       "about her.  She's always cooking up some wierd concoction in that "
       "odd room of hers.",
    ({ "wierd concoction", "concoction" })  :
       "I'm not even sure, if you want to know about it ask her yourself.",
    ({ "gnome" })  :
       "The gnome up above is another good friend of mine.  Him and all of "
       "those books, I just wish I had the time to read like he does.",
    ({ "books" })  :
       "The gnome has a large assortment of books up in his burrow.  Watch "
       "out though he doesn't really like being interupted when he's gotten "
       "to a really good part.",
    ({ "kobold's lair", "kobolds", "kobold lair", "kobold" })  :
       "Nasty little creatures, I wish somebody'd go up there and clear that "
       "area out.  Actually, I think somebody already did that, but another "
       "clan moved in a few short days latter.",
  ]) );

  SetInventory( ([ OBJS + "/hammer_workers" : "wield hammer",
                   OBJS + "/shirt2" : "wear shirt",
                   OBJS + "/pants2" : "wear pants",
                   OBJS + "/boots1" : "wear boots",
                   OBJS + "/bastardsword1" : "wield sword",
  ]) );
}
