/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: tower05.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: This is the observatory/bedroom of the tower.
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
  SetAmbientLight(40);
  SetShort("p'alirith's Observatory");
  SetDayLong(
            "The top most level of the tower is obviously a bedroom but "
            "doubles as something much more wonderous. A large dome "
            "replaces the ceiling and even though it is daytime, no "
            "sunlight penetrates the strange glass it is made of. "
            "Millions and millions of stars are visible through it. A large "
            "bed and a old desk and chair are the only pieces of furniture "
            "in the room."
            );
  SetNightLong(
            "The top most level of the tower is obviously a bedroom but "
            "doubles as something much more wonderous. A large dome "
            "replaces the ceiling and no moonlight penetrates the strange "
            "glass it is made of. Millions and millions of stars are "
            "visible through it. A large bed and a old desk and chair are "
            "the only pieces of furniture in the room."
              );
  SetItems( ([ 
          ({"stars","star","constellations"}) : "The constellations visible "
               "through the glass dome are awe inspiring.  You could "
               "continue to look forever and never look at the same star or "
               "group of stars twice.  Several constellations stand out "
               "from the others.",
          ({"sheets"}) : "The sheets on the bed are a dark green color and "
               "look warm and inviting.",
          ({"pillows"}) : "They are resting at the top of the bed.",
          ({"bed"}) : "This large bed is big enough for two to sleep in and "
               "looks comfortable.",
          ({"constellation"}) : "It looks like a set of scales with a "
               "dragon circling it.",
          ({"constellation"}) : "It looks like an eight pointed star",
          ({"constellation"}) : "It could be concieved as an open "
               "spellbook.",
          ({"constellation"}) : "It looks like a flower of some kind.",
          ({"constellation"}) : "It looks like a dark cloaked figure "
               "wielding a scythe.",
          ({"sky"}) : "The sky is filled with millions and millions of "
               "stars", 
          ({"diagrams","diagrams on paper"}) : "The diagrams on the papers "
               "look like star charts.  Only an expert in astronomy or "
               "astrology would be able comprehend them fully.",
          ({"papers","paper"}) : "The papers on desk are diagrams of some "
               "sort.",
          ({"desk"}) : "The desk appears to be used for making notes and "
               "observations.  There are papers scattered about it's "
               "surface.",
          ({"chair"}) : "This chair looks comfortable and old.",
          ({"side"}) : "The sides of the tower are rounded and they "
               "contains stone steps leading up and down from here.",
          ({"candle"}) : "A small candle is mounted on the wall just "
               "before the steps leading down keeps the area somewhat lit.",
          ({"steps"}) : "The stone steps down to the kitchen and appear "
               "safe and sturdy.",
          ({"stone", "stones"}) : "The stones used to build the tower "
               "appears just as the ones used to build the keep except the "
               "ones inside the tower are not nearly as dark as the ones "
               "outside.",
          ({"wall", "walls"}) : "The stone walls of the tower are made of "
               "aged stone and are clean.",
          ({"floor"}) : "The floor is made out of the same stone as the "
               "walls.", 
          ({"air"}) : "The air? No one can see that.",
          ({"ceiling","dome","window"}) : "The ceiling is a massive window "
               "in the shape of a dome. It is made from a dark substance "
               "that seems to block out all light from the outside except "
               "for the stars. At anytime of day, one could look through "
               "this window and see only the constellations.",
          ({"tower"}) : "This inside of the tower is made from an aged "
               "stone an dark but not nearly as bad as the walls of the "
               "keep or the outside walls of the tower."
          ]) );
  SetItemAdjectives( ([ 
            "stars" : ({"millions and millions of"}),
            "floor" : ({"stone"}),
            "bed" : ({"large","comfortable"}),
            "sheets" : ({"dark", "green"}),
            "ceiling" : ({"glass","dome","dark"}),
            "window" : ({"glass","dome"}),
            "dome" : ({"glass","ceiling","dark"}),
            "forest" : ({"jidoor"}),
            "steps" : ({ "stone","safe","sturdy","set of","set of stone" }),
            "stones" : ({ "aged" }),
            "stone" : ({ "aged" }),
            "walls" : ({ "stone","aged" }),
            "wall" : ({ "stone","aged","circular" })
                  ]) );
  SetListen( ([ 
            "default" : "There is almost no noise in this room."
           ]) );
  SetSmell( ([ 
            "default" : "There is a musty smell here, but not overbearing.",
            "air" : "A musty smell enters this room from below."
          ]) );
  SetInventory( ([ 
            d_npc + "/palirith" : 1,
              ]) );
  SetExits( ([
             "down" : d_room + "/tower04"
          ]) );
  }



