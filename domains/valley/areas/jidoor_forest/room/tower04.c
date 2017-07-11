/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: tower04.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is the kitchen in the tower.
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
  SetDayLight(40); /* from the window */
  SetNightLight(30); /* from a candle */
  SetShort("a kitchen in the tower of P'alirith's keep");
  SetDayLong(
            "This floor obviously serves the purpose of the dining cooking "
            "room of the tower. A small table with two chairs sits a short "
            "distance from a stove of some sort. The countertop is very "
            "clean and filled with several items you'd normally see in a "
            "kitchen. The stone steps continue up into the tower and back "
            "down to the living area.  A small window over the sink allows "
            "a moderate amount of sunlight to enter the room."
            );
  SetNightLong(
            "At first glance, it's not hard to tell this is the kitchen and "
            "eating area of the tower. A small table and two chairs rests "
            "a short distance from a countertop and not far from a stove. "
            "Just above the sink a small window allows some moonlight into "
            "the room.  A candle mounted on the wall between the stone "
            "steps leading up into the tower and back down to the living "
            "area."
              );
  SetItems( ([ 
          ({"forest"}) : "The western part the forest stretches out as far "
               "as you can see.",
          ({"food"}) : "Strangely, there doesn't appear to be much the way "
               "of food anywhere.",
          ({"items","utensils"}) : "These are just various cooking utensils "
               "and are not really interesting.",
          ({"countertop"}) : "The countertop contains a bunch of utensils "
               "used for preparing food. It is clean and tidy.",
          ({"stove"}) : "This wierd little contraption doesn't have any "
               "place to put wood.  The only way you can tell it's a stove "
               "is by the cooking plates on top of it.",
          ({"cooking plates"}) : "These are just used to set pots on the "
               "stove.",
          ({"vase"}) : "The vase contains an ensemble of yellow "
               "wildflowers",
          ({"flower","wildflower"}) : "The wildflowers in the vase are "
               "mostly yellow in color and add to the atmosphere of the "
               "room.",
          ({"flowers","wildflowers"}) : "The wildflowers in the vase are "
               "mostly yellow in color and add to the atmosphere of the "
               "room.",
          ({"chair"}) : "This chair looks comfortable and old.",
          ({"chair"}) : "This chair looks comfortable and old.",
          ({"table"}) : "The table is clean and has a vase filled with "
               "wildflowers on it. It is accompanied by two chairs.",
          ({"sink"}) : "The sink is clean and spotless just like the rest "
               "of the room.",
          ({"side"}) : "The sides of the tower are rounded and they "
               "contains stone steps leading up and down from here.",
          ({"window"}) : "A small glass window over the sink overlooks the "
               "forest west of the keep.",
          ({"candle"}) : "A small candle is mounted on the wall just "
               "between the steps leading up and the ones leading down. "
               "It keeps the area somewhat lit at night.",
          ({"steps"}) : "The stone steps lead up into the tower and down "
               "to the living room and appear safe and sturdy.",
          ({"stone", "stones"}) : "The stones used to build the tower "
               "appears just as the ones used to build the keep except "
               "the ones inside the tower are not nearly as dark as the "
               "ones outside.",
          ({"air"}) : "The air? No one can see that!",
          ({"wall", "walls"}) : "The stone walls of the tower are made of "
               "aged stone and are clean.",
          ({"floor","ceiling"}) : "The floor and ceiling are both made out "
               "of the same stone as the walls.", 
          ({"tower"}) : "This inside of the tower is made from an aged "
               "stone an dark but not nearly as bad as the walls of the "
               "keep or the outside walls of the tower."
          ]) );
  SetItemAdjectives( ([ 
            "forest" : ({"jidoor"}),
            "countertop" : ({"clean"}),
            "table" : ({"small"}),
            "sink" : ({"clean","spotless"}),
            "window" : ({ "small","glass" }),
            "steps" : ({ "stone","safe","sturdy","set of", "set of stone" }),
            "stones" : ({ "aged" }),
            "stone" : ({ "aged" }),
            "walls" : ({ "stone","aged" }),
            "wall" : ({ "stone","aged","circular" })
          ]) );
  SetListen( ([ 
            "default" : "It is quiet here." 
           ]) );
  SetSmell( ([ 
            "default" : "Although it appears clean, the kitchen is "
               "definately the source of the musty odor.",
            "air" : "The source of the musty odor in the air is the "
               "kitchen."
          ]) );
  SetInventory( ([
             d_npc + "/lauranna" : 1,
              ]) );
  SetExits( ([
            "down" : d_room + "/tower03",
            "up" : d_room + "/tower05" 
          ]) );
  }
