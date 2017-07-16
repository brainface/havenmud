#include <lib.h>
#include <domains.h>

inherit LIB_ROOM;

varargs mixed eventDig(object who, string what);

static void create() {
  ::create();
  SetShort("in the barren Yozrath Desert");
  SetClimate("arid");
  SetLong("The Yozrath Desert is a massive expanse of sand and barren waste"
          " that seems to go off into the horizon without end. Far off in the"
          " distance to the east, the faint outlines of the Estergrym mountains"
          " stand against the sky, while far off to the west the FrostMarches"
          " taint the horizon. To the southwest lie the Crystal Reaches. The"
          " desert seems to end here, trailing off into the plains that make"
          " up the Southern Coast and the HavenWood. Further travel east is"
          " limited by the lack of paths over the land. Two large palm trees"
          " cross together at their midsections creating what appears to be an"
          " X over a small dune of sand."
          );
  SetItems( ([
      ({ "palm", "tree", "trees", "palm trees" }) : "The palm trees are very large."
                                                    " Their trunks are roughly two"
                                                    " feet in diameter and they are"
                                                    " about thirty feet tall. They"
                                                    " cross at their midsection to"
                                                    " create an X over a small dune"
                                                    " of sand.",
      ({ "dune", "sand dune", "dune of sand" }) : "This small sand dune looks like"
                                                  " it has been here for some time."
                                                  " It has quite a few palm branches"
                                                  " strewn about it, perhaps to conceal"
                                                  " it.",
     ]) );
  SetItemAdjectives( ([
     "palm" : "large",
     "dune" : ({ "small", "sand" }),
    ]) );
  SetExits( ([
         "north" : "/domains/yozrath/virtual/desert/100,-94",
         "south" : "/domains/yozrath/virtual/desert/100,-96",
         "west"  : "/domains/yozrath/virtual/desert/99,-95",
        ]) );

  SetSmell( ([
    "default" : "The desert air is remarkably clean and crisp.",
    ]) );
  SetListen( ([
    "default" : "Sand shifts and occasionally a deep rumble comes from the desert sands.",
    ]) );
}

varargs mixed eventDig(object who, string what) {
  object chest = new("/std/mission_obj/treasure/treasure_chest1");

  
  if ((who->GetProperty("mission")) == "/std/missions/special/treasure1") {
     send_messages( ({ "dig", "hit" }),
          "$agent_name $agent_verb into the sand dune and $agent_verb something"
          " buried underneath.", who, 0, environment(who) );
     chest->eventMove(environment(who));
     message("success", "You discover a chest buried under the sand!", this_player() );
     return 1;
    }

   send_messages( ({"dig", "uncover" }),
          "$agent_name $agent_verb at the sand, but $agent_verb nothing of value.",
             who, 0, environment(who) );
    return 1;
}
