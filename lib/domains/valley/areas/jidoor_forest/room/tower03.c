/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: tower03.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is the living area of the tower.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"
  static void create()
  {
  room::create();
  SetDomain("Valley");
  SetClimate("indoors");
  SetDayLight(55); /* from the window */
  SetNightLight(20); /* from a candle */
  SetShort("a living room in the tower of P'alirith's Keep");
  SetDayLong(
            "This living room is plainly decorated except for a few "
            "paintings which are mounted on the stone steps around the "
            "circular wall of the tower. A candle mounted on the wall "
            "between the steps leading up and the steps leading down keeps "
            "the room lit at night but during the daytime, sunlight flows "
            "in from a large window on the northern section of the wall."
            );
  SetNightLong(
            "This living room is plainly decorated except for a few "
            "paintings which are mounted on the stone steps around the "
            "circular wall of the tower. A candle mounted on the wall just "
            "between the steps leading up and steps leading down burns "
            "furiously trying to cast some light into the room but "
            "moonlight filters in from a large window in the northern wall "
            "helping light the room."
              );
  SetItems( ([ 
          ({"paintings"}) : "Several incredible works of art hang on the "
               "circular wall of the tower.",
          ({"painting"}): "This is a picture of a wizard fighting a "
               "magnificient green dragon. As you look at it, you feel "
               "compelled to pay close attention to the beauty of the "
               "painting.  It is truly a work of art.",
          ({"painting"}): "This is a picture of the keep painted from "
               "somewhere east of it. The painting depicts the building of "
               "the keep and shows many gelflings working on various pieces "
               "of it.",
          ({"painting"}): "The painting is abstract and hard to discern "
               "anything from it.",
          ({"painting"}): "The painting is a beatiful view of Jidoor from "
               "above.   The heart of painting is the detail spent in the "
               "church of the Magildans.",
          ({"painting"}): "The painting is a portrait of a young female "
               "sprite dressed in a dark red robe. She has a very cute "
               "smile and looks very friendly.",
          ({"painting"}): "The painting is a portrait of a young male "
               "sprite dressed in a dark red robe.  His face is stern but "
               "he does not appear aggressive.",
          ({"side"}) : "The sides of the tower are rounded and they "
               "contains stone steps leading up and down from here.",
          ({"shadows"}) : "Shadows are dancing on the wall from a candle "
               "mounted on the wall.",
          ({"window"}) : "A large glass window overlooks the forest north "
               "of the keep.",
          ({"candle"}) : "A small candle is mounted on the wall just "
               "between the steps leading up and the ones leading down. It "
               "keeps the area somewhat lit at night.",
          ({"floor","ceiling"}) : "The floor and ceiling are both made out "
               "of the same stone as the walls.",
          ({"steps"}) : "The stone steps lead up into the tower and down to "
               "the greeting room and appear safe and sturdy.",
          ({"stone", "stones"}) : "The stones used to build the tower "
               "appears just as the ones used to build the keep except the "
               "ones inside the tower are not nearly as dark as the ones "
               "outside.",
          ({"air"}) : "The air? No one can see that.",
          ({"wall", "walls"}) : "The stone walls of the tower are made of "
               "aged stone and are clean.",
          ({"norther wall", "northern section of the wall"}) : "The "
               "northern part of the wall contains a large glass window.",
          ({"tower"}) : "This inside of the tower is made from an aged "
               "stone an dark but not nearly as bad as the walls of the "
               "keep or the outside walls of the tower."
          ]) );
  SetItemAdjectives( ([ 
            "window" : ({ "large","glass" }),
            "steps" : ({ "stone","safe","sturdy","set of","set of stone" }),
            "stones" : ({ "aged" }),
            "stone" : ({ "aged" }),
            "walls" : ({ "stone","aged" }),
            "wall" : ({ "stone","aged","circular" }),
            "northern wall" : ({ "stone","aged" }),
                   ]) );
  SetListen( ([ 
            "default" : "Very little sound is noticeable in the room."
           ]) );
  SetSmell( ([ 
            "default" : "The musty smell of the tower is stronger here but "
               "not overbearing.",
            "air" : "The musty smell in the air is definately coming from "
               "the room above this one."
          ]) );
  SetExits( ([
            "down" : d_room + "/tower02",
            "up" : d_room + "/tower04" 
          ]) );
  }
