// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
// Added Everything

#include <lib.h>
#include <domains.h>
#include "../castle.h"          

#define WESTWOOD "/domains/westwood/virtual/westwood/"
     
inherit LIB_FISHING;       
 
static void create() 
{
fishing::create();
SetShort("an abandoned dining hall");
SetLong(
 "This rectangular room is enormous and quite spacious. "
 "A very large oak table which runs the length of the "
 "hall has been tipped on its side and chopped in "
 "numerous sections. Chairs which were once well crafted "
 "now rest in pieces and lay covered in dust. A framed "
 "painting rests on the western wall above the piles of "
 "wood. The eastern wall proudly displays a hand woven "
 "rug which illustrates a story. The west and north "
 "doorways provide exits into the further reaches "
 "of the ruins. A giant gaping hole in the south wall "
 "exposes a section of this hall to the elements outside "
 "overlooking the ruined moat.");
 
SetItems( ([ 
    ({ "room","hall" }) : (: GetLong :),
    ({ "ceiling","roof" }) : "It is flat and stretches to the "
                             "four walls which create any travel "
                             "upward. It is made of the same "
                             "grey stone as the walls.",
    ({ "floor","ground" }) : "The flat floor is obstructed by "
                             "piles of wood, shattered chairs and "
                             "a table.",

     "table" : "The large oak table which was probably used "
               "to plate numerous troops has been toppled over "
               "and beaten into pieces for its lumber.",
     "chairs" : "Several chairs have been smashed to pieces "
                "and lie strewn about the hall. Some wood "
                "from the chairs have been thrown in a pile "
                "near the upside down table.",
     "chair" : "Peering at the remains of the chair it was "
               "of average make, with a padded straw seat.",
     "painting" : "The painting is of a square looking castle "
                  "with a lifted drawbridge. The grass in the "
                  "painting looks well trimmed and the moat "
                  "that surrounds the castle is clear and well "
                  "kept. The bright sky is doused out by the "
                  "forest of trees that surround the entire "
                  "landscape.",
     "western wall" : "The western wall is flat in shape and "
                      "has a doorway built in it leading to "
                      "another room in these ruins. A framed "
                      "painting remains untouched which hangs "
                      "to the east of the doorway. The wall "
                      "itself is made of grey rectangular stone "
                      "slabs which have been sealed to eachother.",
     "walls" : "The walls have been constructed with grey "
               "rectangular stone slabs which have been "
               "sealed on top of eachother. They reach "
               "up a ways leaving this dining hall very spacious. "
               "There is a giant hole in the south wall which "
               "overlooks the moat and the elements of the "
               "Westwood.",
     "piles" : "Scattered piles of wood rest in disheveled places "
               "everywhere in this hall. Two distinct piles rest near "
               "the table and the other rests near the western wall.",
     "pile" : "The pile of wood has been collected from the remains "
              "of the chairs or the busted table.",
     "south wall" : "The southern wall is made of grey rectangular stone "
                    "slabs which have been sealed together. A hole which "
                    "seems to have been pierced in from the outside exposes "
                    "the Westwood exterior.",
     "eastern wall" : "It is made with rectangular stone cut slabs which "
                      "are grey in colour and sealed together. A rather "
                      "large hand woven rug with numerous figures which "
                      "has been embroidered on its surface.",
"rug" : "It hangs on the eastern wall and almost covers the complete surface "
     "of the rectangular wall. It is made of thin strands of cloth "
     "which have been pulled together for the background and embroidered "
     "along the surface to designate designs and patterns to illustrate "
     "a story.",
"story" : "The story is simplistic but a little difficult to discern from "
"age and archaic design. A large entity of white thread becomes brighter while the other "
"coloured circles wane. White destroys many similar entities of different colours. "
"A green entity is seen leading small brown bear shaped beings into the "
"woods. There are many colours in the beginning of the story, but few "
"remain at the end.",
//This is the First GodsWar. Duuk kills Immortals, Amelia leads Muezzins
//to the trees. Green for forest God. White for Kylin.
  "west doorway" : "The west doorway frame juts out slightly distinguishing "
              "itself from the wall. It is made of the same material as "
              "the wall, grey stone but these stones are larger and more "
              "square shape. It leads to a much smaller room westward. Along "
              "the doorway there is evidence that there used to be a door "
              "which hung on the wall, but it appears to be missing.",
 "north doorway" : "It has been composed of the same materials as the wall. "
              "Square stone grey slabs distinguish the doorway from the "
              "similar colour wall. It seems as if it has been untouched "
              "since it was created.",
     "ruins" : "You are inside the ruins.",
     "hole" : "The hole in the wall is large enough to fit any large giant "
              "through with ease. The moat would have to be jumped over regardless "
              "of size, if escape through conventional means was no option.",
     "moat" : "It lies dormant and stale in this section. The surface of the "
          "moat has milky bubbles along the surface and overgrown seaweed "
          "which permeate through the surface. Fish occasionally break the "
          "surface to grab any nourishment that happens to befall their "
          "domicile.",
     "exits" : "From this hall three exits seem possible. The north into "
               "a hallway, west toward a smaller room in the ruins or "
               "outside through the hole in the southern wall.",
     "stone" : "The stone is a nuetral grey colour and has some archaic "
               "elements of construction on the surface. Pieces of grit "
               "break the surface and appear to be unique in shape.",
     "stones" : "The stones have been stacked atop eachother and sealed "
                "together to form these ruin walls.",
     "frame" : "The wooden frame compliments the painting on the western "
               "wall. It is made with average quality, but looks like it "
               "was used with leftover wood as knots and creases can be "
               "seen along the surface.",
     "seaweed" : "Overgrown seaweed breeches the surface of the moat.",
//     "" : ".",
    ]) );
SetItemAdjectives( ([
    "room" : ({ "rectangular" }),
    "moat" : ({ "ruined" }),
    "hole" : ({ "gaping","exposed","giant" }),
    "table" : ({ "busted","oak" }),
    "chair" : ({ "broken","shattered" }),
 //   "" : ({ "","","","" }),
  ]) );
SetListen("default","Echoes of the wildlife of the Westwood can be heard.");
SetSmell("default","The ruined moat smell from outside lingers heavily.");
SetExits( ([
        "north" : RUINS_ROOMS + "center",
        "west" : RUINS_ROOMS + "kitchen",
        "south" : WESTWOOD "27,27"
        ]) );
SetClimate("indoors");
SetAmbientLight(15);
/* Fishing stuffs*/
SetChance(40);
SetMaxFishing(15);
SetSpeed(8);
SetFish( ([
         RUINS_OBJ "muddling" : 100,
         RUINS_OBJ "malling" : 20,
         RUINS_OBJ "amalling" : 2, //Special for fishing in _this_ spot
     ]) );
}
