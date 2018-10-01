// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
// Added Everything

#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h" 

static void create() {
::create();
SetShort("a barred armoury");
SetLong("Old barren weapon racks and shelves line the walls in this "
        "square room inside the ruins. In the direct center of the "
        "armoury a section has been made next to some makeshift "
        "straw mats. Along the western wall a rug sits among the "
        "ash, coals and debris that is covered in dust. A stone "
        "fire pit looks rather new in the center of this square room "
        "and it seems to provide some decent lighting.");
  SetExits( ([
        "east" : RUINS_ROOMS + "guard",
        ]) );
  SetInventory( ([ 
                    RUINS_NPC "muezzin01" : 1,
                    RUINS_NPC "muezzin02" : 1,
                    RUINS_OBJ "campfire" : 1,
                     ]) );
  SetListen("default", "The walls and shelves creak from the heat.");
  SetSmell("default", "Heavy thick smoke lies dormant here.");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetItems( ([ 
    ({ "armoury","room","ruins" }) : (: GetLong :),
     "racks" : "Old weapon racks line the walls corner to "
               "corner. It seems they used to hold numerous "
               "belongings due to how they are strongly "
               "fastened to the walls.",
    ({ "rug","linen rug" }) : "Dressed along the western wall "
               "a plush rectangular linen rug can be seen. It "
               "is dirty and has seen better days.",
    ({ "ceiling","up" }) : "The ceiling is quite high and "
               "would suit any species comfort if they "
               "were in here. It is made of slightly yellowed "
               "stones and it is flat from wall to wall. "
               "Along the north wall the holes in the "
               "ceiling can be seen letting in lighting.",
    ({ "floor","ground" }) : "The ground is made of yellowed "
               "stones which also form the walls. A linen rug "
               "sits on the ground along the western wall. It "
               "is flat from wall to wall and it is stained "
               "with blood and dirt.",
     "shelves" : "The shelves are barren but strong to support "
                 "a good amount of weight.",
     "center" : "The center of the room has a little section "
                "wish ash surrounded by linen mats and rubble.",
     "lighting" : "The lighting beams in through the smoke "
                  "enough to illuminate this room any time "
                  "of day.",
     "walls" : "The walls are made of yellowed stones which "
               "form this square environment. They form "
               "flat walls which lead to a doorway east.",
     "western wall" : "The western wall has a window in it "
                      "that pulls the smoke out the armoury.",
     "wall" : "The wall is made of yellow stone.",
     "mats" : "Straw mats rest in the center of the room "
              "surrounding a little section. They look "
              "suitable for sleeping, if you were a slave.",
     "straw" : "straw mats rest in the center of the room.",
     "stone" : "The stone looks yellowed from age, it almost "
               "looks incredibly close .",
     "stones" : "The stones make up the walls, ceiling and on "
                "the ground they make up the floor covered in "
                "dirt. A section also sits in the middle of the "
                "armoury on the floor that serves as a little "
                "fire pit.",
     "dirt" : "Dirt lines the floor, it is packed and looks "
              "incredibly black and sticky.",
     "drawers" : "The drawers line the cabinets. They are empty "
                 "and some are missing from the cabinets.",
     "hinges" : "Loose hinges hold the drawers in place. If they "
                "were connected.",
     "rubble" : "Rubble lies abundantly in this armoury. It "
                "seems to have suffered some siege damage before "
                "it was looted properly.",
     "doorway" : "The doorway leads east into the ruins. It "
                 "is framed and has been built in the eastern "
                 "wall.",
     "window" : "The window is merely an open slit through "
                "the western wall. With a strong force it is "
                "pulling in the thick smoke from this room.",
     "section" : "A little section has been placed where "
                 "a campfire would rest in the center of the "
                 "armoury.",
     "smoke" : "Thick smoke lingers about, it is not difficult "
               "to breathe.",
     "cabinets" : "The cabinets have all been looted, some are "
                  "even missing. Hinges cover the cabinets to "
                  "secure the drawers in place.",
     "eastern wall" : "The eastern wall has a doorway that is "
                      "made of stone. It looks as if this is the "
                      "primary means of exiting and entering this "
                      "armoury.",
     "holes" : "Some holes in the ceiling let in natural "
               "light and exhume some of the smoke. During "
               "climate change it would not cause any "
               "discomfort to those who occupied these ruins.",
     "ash" : "Ash lies completely everywhere.",
     "coal" : "Coal lies in the center of the section near "
              "the straw mats.",
     "dust" : "Dust rests on every horizontal surface in this "
              "dump.",
     "blood" : "In some areas of the floor some small blood can "
               "be seen stained with the dirt.",
    ]) );
 SetItemAdjectives( ([
    "mats" : ({ "straw" }),
    "room" : ({ "square" }),
    "racks" : ({ "weapon" }),
    "stones" : ({ "rectangular","cut","aged","yellow" }),
  ]) );
}

void heart_beat() {
  string fire;
  ::heart_beat();
  switch(random(5)) {
    case 0:
      fire = "The campfire burns slowly.";
    break;
    case 1:
      fire = "A snap and hiss can be heard as the campfire brightens.";
    break;
    case 2:
      fire = "Wooden logs slowly collapse in the campfire.";
    break;
    case 3:
      fire = "An ember pops from the campfire wildly!";
    break;
    case 4:
      fire = "The campfire flares up slightly illuminating the old ruined walls.";
    break;
   }
  eventPrint(fire);
}
