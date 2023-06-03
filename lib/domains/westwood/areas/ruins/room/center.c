// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
// Added descs + everything
// If you search the loose stone you will find a quest item
// Which will enable you to get that gem!


#include <lib.h> 
#include "../castle.h" 
       
inherit LIB_ROOM;       

string SearchStone();
int SearchComplete;       
 
static void create() {
::create();
SetShort("a center hallway");
SetLong("Four directions spread out in this hallway leaving "
        "access to different sections of the ruins. This "
        "hallway is slightly barren, metal sconces all remain "
        "empty except for one torch which burns brightly on the "
        "southeastern wall which leads eastward. Packed dirt "
        "and leaves litter the floor everywhere.");
SetListen( "default", "The hallway is silent with the times.");
SetSmell( "default", "It smells of rotted leaves.");
SetExits( ([
  "north" : RUINS_ROOMS + "guard",
  "south" : RUINS_ROOMS + "dining",
  "west"  : RUINS_ROOMS + "entry",
  "east"  : RUINS_ROOMS + "throne",
]) );
SetClimate("indoors");
SetAmbientLight(15);
SetItems( ([ 
    ({ "hallway","ruins" }) : (: GetLong :),
    ({ "floor","ground" }) : "The ground splits off into four "
                             "directions in this hallway. It is "
                             "made of the same stones as the wall "
                             "but it is covered in dirt and leaves.",
    ({ "ceiling","roof" }) : "The roof is flat and follows the hallway "
                             "into four different directions.",
     "walls" : "The walls have been made of drab square cut "
               "stones which have been stacked on top of eachother "
               "and then sealed together. They make up this hallway "
               "and spread out into four directions.",
     "northwestern wall" : "The northwestern wall has two sconces "
                           "which have been picked clean. It is made "
                           "of grey stones which have been sealed "
                           "together to form a wall leading west.",
     "northeastern wall" : "It leads east into a much larger room in "
                           "the ruins. A few sconces rest fastened "
                           "to the wall but they do not hold anything.",
     "southwestern wall" : "The southwestern wall has been formed with "
                           "grey stones. Along the floor a loose stone "
                           "is seen that juts out from the rest. It forms "
                           "the hallway which leads west in the ruins.",
     "southeastern wall" : "It is the only wall in this section which "
                           "seems to have been untouched. A wooden torch "
                           "burns dimly enough to provide decent lighting "
                           "in the hallway.",
     "torch" : "The torch is made of wood and wrapping. It has been "
               "placed in the southeastern wall to provide lighting.",
     "sconce" : "The sconce is made of metal and has been "
                "fastened to the wall to provide a resting "
                "place for a thin object.",
     "sconces" : "The sconces have been fastened to all of the "
                 "walls. The only one which remains untouched "
                 "is the southeastern wall.",
     "directions" : "There are four directions which lead to "
                    "different portions of these ruins.",
     "dirt" : "Some dirt rests on the floor of the hallway. Some "
              "dirt has adhered to itself to form small clumps "
              "which accompany the leaves which also litter the "
              "floor.",
     "leaves" : "The leaves litter the ground of this hallway. They "
                "seem to have entered here by wind and left here "
                "to rot. They are wet and cause a slippery hazard.",
     "leaf" : "The leaf looks it has entered here from "
              "the West Wood. It is a tiny beech leaf.",
     "loose stone" : "The loose stone juts out of the southwestern "
                     "wall. It seems as if something has knocked "
                     "it loose or it has decayed from age.",
     "fire" : "The fire dances and burns the wrapping on the torch. "
              "It seems to struggle for a decent fuel source as the "
              "flame seems small.",
     "flame" : "The flame burns slowly.",
     "wrapping" : "Burnt wrapping has been wrapped around the torch "
                  "to be used as a fuel source for the torch placed "
                  "on the southeastern wall.",
     "stones" : "Stones form this entire hallway. They have been made "
                "to form the walls, the floor and the ceiling.",
//     "" : ".",
//     "" : ".",
    ]) );
SetItemAdjectives( ([
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
    "" : ({ "","","","" }),
  ]) );
  SetSearch("loose stone", (: SearchStone :) );    
  SearchComplete = 0;
}

string SearchStone(object who) {
   object item = new(RUINS_OBJ + "histbook");
   
   send_messages("search", "$agent_name $agent_verb around a loose "+
   "stone.", who, 0, this_object());
   if (SearchComplete) {
    return "The stone reveals nothing of interest.";
   }
   if (!item->eventMove(who)) item->eventMove(this_object());
   SearchComplete = 1;
   return "You discover a hidden book in the loose stone!";
}