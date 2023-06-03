// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
/*
SetLong("In this room, there are shelves lining the walls.  The "
     "shelves filled with treasures of all varieties.  The floor "
     "is covered with a white carpet and the room is lit by a "
     "gem embedded in the ceiling.  To the north is the exit "
     "into a throne room.");
*/
#define CRAFTING_DIR "/std/crafting/natural/"

#include <lib.h>        
#include "../castle.h" 

inherit LIB_ROOM;       

string SearchShards();
int SearchComplete;   

static void create() {
::create();
SetShort("an empty square room");
SetLong("Shelves line the walls which have been mounted to the "
        "walls with thick iron bars. The floor is covered with "
        "a stained carpet covered in ooze. Broken "
        "chests and pots lay smashed throughout the floor. A "
        "broken iron door rests on the floor toppled over on "
        "some furniture debris. It looks to have been previously "
        "looted thoroughly.");
SetExits( ([
        "north" : RUINS_ROOMS "throne",
        ]) );
SetRadiantLight(1);
SetListen("default","It is unusually quiet in this room.");
SetSmell("default","It smells of decay and mildew.");
SetClimate("indoors");
SetItems( ([ 
    ({ "room","square room" }) : (: GetLong :),
    ({ "bars","iron bars" }) : "The iron bars secure the "
       "shelves in place. They seem aged but in definitive "
       "function.",
    ({ "floor","ground" }) : "The ground has been lined wall to "
          "wall and appears ruined. Large chunks of wood lie "
          "everywhere. The surface of the carpet has a thick "
          "black stain which appears like an ooze.",
    ({ "ruins" }) : "The inside of the ruins here is rather "
                    "decorative and contrasts the rest of this "
                    "structure.",
    ({ "furniture","debris" }) : "Wooden chair fragments lie "
                 "about, probably used for heat than rest.",
     "ceiling" : "The ceiling is flat and composed of yellowed "
                 "stone. In the direct centre a hole can be "
                 "seen which releases a rather mysterious glow.",
     "shelves" : "A wooden board secured by iron bars mounted "
                 "to the walls shelve this entire room. Some "
                 "wooden pieces are missing.",
     "door" : "The door rests on its face buckled and mangled "
              "but in one solid piece. Iron bars secure a small "
              "hole through the center.",
     "iron" : "The iron on the door is similar to the iron "
              "securing the shelves on the wall. It is rusted "
              "somewhat in patches along the edges and do not "
              "seem to be frail.",
     "chest" : "Pieces of what could be a chest lie on the "
               "floor in pieces.",
     "chests" : "Wooden shards litter the ground of what could have "
                "held some sort of treasure.",
     "triangles" : "Three shiny metal triangles hold nothing "
                   "in place.",
     "glow" : "A mysterious glow ebbs from a hole in the ceiling.",
     "rust" : "Tiny bits of rust can be seen on the iron surfaces "
              "in this abandoned treasure room.",
     "wood" : "An old wooden board is fastened to the walls. Some "
              "wood shards and fragments remain in the surrounding area.",
     "shards" : "Wooden shards rest on the floor as useless trash. They "
                "cover a good portion of the ground.",
     "fragments" : "Wooden fragments rest on the ground as useless trash.",
     "chair" : "Fragments of solid wooden chair fragments litter "
               "the ground.",
     "ooze" : "The black ooze appears gelatinous, not sentient. It "
              "is spread all about the surface of the carpet.",
     "surface" : "The surface of the ground has fragments of wood "
                 "all around, the surface of the shelves are barren.",
     "hole" : "A hole in the ceiling glows mysteriously. It provides "
              "a soft light in this abandoned treasure room.",
     "carpet" : "A carpet, which is covered from years of mistreatment "
                "rests on the ground. A testament of bodily fluids "
                "pools on the surface creating an ooze.",
     ]) );
SetItemAdjectives( ([
    "ooze" : ({ "black" }),
    "fragments" : ({ "wood" }),
    "shards" : ({ "wood" }),
    "glow" : ({ "mysterious" }),
    "carpet" : ({ "stained" }),
  ]) );
  SetSearch( ([
             "fragments"   : (: SearchShards :),
             "shards"    : (: SearchShards :),
             ]) );  
  SearchComplete = 0;
}

//Tucking in some existing crafting stuff
//for fun

string SearchShards(object who) {
   object item = new(CRAFTING_DIR + "glass_red");
   send_messages("search", "$agent_name $agent_verb finds "+
   "something in the wood fragments.", who, 0, this_object());
   if (SearchComplete) {
    return "The search yields nothing of value.";
   }
   if (!item->eventMove(who)) item->eventMove(this_object());
   SearchComplete = 1;
   return "You discover a broken shard of glass.";
}