// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// 12.7.12 Urien@Haven
/* 
SetShort("a wizard's room");
SetLong("Upon entering this room, a person is surrounded with "
     "tables is lab equipment. There is glassware on all the "
     "tables and strange liquids boiling over small flames.  "
     "In the far corner is a small bed with a nightstand and "
     "nothing else.  There are no decorations in this room and "
     "apperantly whoever works here also lives here.");
*/

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h"          

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(15);
  SetObviousExits("south");
  SetShort("an illuminated study");
  SetLong(
          "This large rectangular study once was decorated "
          "with sturdy wooden tables and chairs. Broken glass "
          "lies all over the floor and furniture. A bed that "
          "was once functional sits accompanied by a wooden "
          "stand tipped on its side. A yellow and brown carpet "
          "lines this room to the doorway south. This study "
          "resonates in a former functional glory.");
SetInventory( ([ 
        RUINS_NPC "ghostwiz" : 1
                   ]) );
SetExits( ([
        "south" : RUINS_ROOMS "throne",
        ]) );
SetSmell( ([
            "default" : "Stagnant burned wax lingers heavily.",
           ]) );
SetListen( ([
            "default" : "A noticeable hum can be heard."
           ]) );
SetAmbientLight(5);
SetItems( ([ 
    ({ "study","illuminated study" }) : (: GetLong :),
    ({ "ground","floor" }) : "The ground is covered "
           "in pieces of glass and wood on the carpet. "
           "A malfunctional bed sits tucked away in the "
           "corner, with straw ripped out of it.",
     "glass" : "Splinters of shattered glass litter the "
               "floor in this square study. Some pieces "
               "have retained some damage, appearing "
               "like various ampoules and beakers. Nothing "
               "worth any value.",
     "bed" : "A single bed which is slightly used and "
             "covered in dust rests on its side. It "
             "appears made of hay and string with "
             "primitive props to hold it level. Most of "
             "the wood pieces of the frame have been "
             "broken and been used elsewhere.",
     "walls" : "The walls are made of flat yellow aged "
               "brick. They form a doorway to the south "
               "which absolves the lighting in the room. "
               "They are bare and there is no windows.",
     "wall" : "Free of any decor, the wall is made of "
              "square cut yellow aged stone. To the "
              "south it forms a crude doorway.",
     "ceiling" : "The ceiling is flat and borders off "
                 "the natural elements with square "
                 "cut stones.",
     "carpet" : "The yellow and brown carpet lines the "
                "floor wall to wall. The colors have "
                "been sewn together to mesh and form "
                "an entirely new color of yellow and "
                "brown. It is not impressive however the "
                "attempted craft looks decent.",
     "doorway" : "A doorway leads south out of the study "
                 "covered slightly in shadow.",
     "furniture" : "What once was furniture in this tiny "
                   "study sits in ruin. It rests along "
                   "the floor with no function with "
                   "shattered bits of glass.",
     "tables" : "Tables lie along the ground useless and "
                "battered. A single table stands to have "
                "survived whatever happened here.",
     "chairs" : "All of the chairs in this study have "
                "succumbed to mistreatment and lie "
                "broken on the floor.",
     "chair" : "What once was a chair sits in pieces "
               "strewn with glass along the floor.",
     "table" : "Other tables in this study have been "
               "bashed to pieces except one. A sturdy "
               "oak table which has crude muezzin heads "
               "along the legs. It is made of an impressive "
               "thickness and appears quite sturdy.",
     "stand" : "The stand which rests next to the bed "
               "is not serviceable. It is missing a peg "
               "and the top has been bashed in completely.",
     "stones" : "The square cut stones are somewhat porous "
                "and appear yellowed from age.",
     "stone" : "The stone is weathered and seem yellowed from "
               "time.",
    ]) );
SetItemAdjectives( ([
    "stones" : ({ "square","cut" }),
    "walls" : ({ "yellow","aged","brick" }),
    "carpet" : ({ "yellow","brown" }),
    "table" : ({ "sturdy","oak","table" }),
    "bed" : ({ "single" }),
    "glass" : ({ "shattered" }),
    "stone" : ({ "yellow","aged" }),
  ]) );
 }

 