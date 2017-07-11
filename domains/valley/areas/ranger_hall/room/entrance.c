//Outside the Ranger Guildhall
//Original text by Davantalus, coded by Sabrielle 199810
//Updated Davantalus 20040721

#include <lib.h>
#include "../ranger_hall.h"
#include <damage_types.h>

inherit LIB_ROOM;

int PreExit(string dir);

static void create() {
  room::create();
  SetShort("a small clearing");
  SetClimate("temperate");
  SetProperty("no bump",1);
  SetDayLong(
      "In the middle of the clearing there is a large boulder surrounded by "
      "underbrush and several large trees which seem to watch the "
      "clearing. It is possible to see the sky because the foliage is thinner. "
      "The forest has a very powerful imposing, yet embracing feeling. The air "
      "pulses with a natural energy. A small path leads off through the forest "
      "eastward."
  );
  SetNightLong(
      "The forest looms into the clearing like giant skeletal fingers. Only the "
      "very center of the glen is exposed to the night sky. A large boulder "
      "resides under large, trees which almost seem to watch the clearing. The "
      "forest emanates a very powerful feeling, as if the woods are manifesting "
      "their essence into the clearing."
  );
  SetItems( ([  
      ({ "clearing"})        : "This small clearing, off the main "
                               "road, is surrounded by lush forest.",
      ({ "foliage" })        : "The foliage is not as thick here, making "
                               "it possible to see the sky.",
      ({ "path" })           : "The small path leads eastward towards "
                               "the main road.",
      ({"forest" , "woods", "glen"}) : "The surrounding forest is comprised "
                               "of plants and trees of all varieties.",
      ({"boulder","center"}) : "This boulder has a large crack in it. "
                               "The tall trees seem to stand guard over "
                               "it.",
      ({"crack", "crevice"}) : "The large crack in the boulder descends "
                               "down into the ground in a natural way.",
      ({"underbrush"})       : "The underbrush is hiding a small crack.",
      ({"bush"})             : "The untamed bush hides a small crack.",
      ({"tree", "trees"})    : "The trees have almost sentient qualities.",
      ({"moon", "stars"})    : "The moon and stars are fairly visible from "
                               "the clearing.",
      ({"rock"}) : "Hidden behind the bushes is a crevice in the rock.", 
      ({ "fingers" })        : "Tree branches appear almost skeletal during "
                               "the night.",
      ({"branches"})         : "To the east the forest grows thinner "
                               "as it nears the main road."  ]) );
  SetItemAdjectives( ([ 
      "path"   : ({"small"}),
      "boulder": ({"large"}),
      "crack"  : ({"strange", "large"}),
      "crevice": ({ "large" }),
      "fingers": ({ "skeletal", "giant" }),
      "tree"   : ({ "several", "large"}),
      "trees"  : ({ "several", "large"}),
  ]) );
  SetListen( ([
      "default" : "The forest crackles with energy!"
  ]) );
  SetSmell( ([ 
      "default" : "The wind smells heavily of ozone."
  ]) );
  SetInventory( ([ 
      RH_NPC + "red_wolf" : 1,
      RH_NPC + "hummingbird" : 1+random(2)
  ]) );
  AddEnter(
      "crevice", RH_ROOM + "ranger_guildhall", (: PreExit :) 
  );
  SetExits( ([
      "east" : RH_ROOM + "path",
      "south": RH_ROOM + "streambank",
  ]) );
}

int PreExit(string dir)
{
  int spawned = 0;
  int attempts = 0;

  if ( (this_player()->GetGuild() == "ranger") ||
       (creatorp(this_player() ) ) )
       return 1;
  else {
       attempts = attempts + 1;
       if( attempts > 4 )
       {
//         spawn dude
           spawned = 1;
       }
       message("my_action",
           "%^MAGENTA%^The large trees swat you away with "
            "their powerful branches!%^RESET%^",
            this_player() );
       this_player()->eventReceiveDamage(0, BLUNT, random(10)+1, 0);
       this_player()->eventCollapse();
       this_player()->eventParalyze(random(4)); 
       message("other_action",
            this_player()->GetCapName() + " is pushed by the "
                                          "large tree when "
                                          "trying to enter the "
                                          "crevace.",
                   this_object(), this_player() );
       return 0;
       }
}
