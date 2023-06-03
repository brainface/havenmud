// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:
// Urien@Haven 12.8.12
/*
SetLong("This kitchen is very quaint and well equipped for this "
     "area.  There are two furnaces along the north wall and "
     "cabinets line the southern wall.  Running down the middle "
     "of the room is a long table used mostly to prepare food "
     "on.  This room is designed for functional use only and "
     "therefore has no decorations.  To the east is the exit "
     "back to the dining room.");
*/

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h"          
 
static void create() {
::create();
SetShort("a small dusty kitchen");
SetLong("Two furnaces along the north wall which rest side to "
        "side, complete with metal chutes lie broken and "
        "ruined. Pantry cabinets which line the south wall have been "
        "kicked in and looted throughly. A table which rests in "
        "the center of the room has been flipped upside down "
        "and black dirt lies literally everywhere. An obvious "
        "doorway leads east to a much larger room in the ruins. "
        "This square room would be fit for banquets if it wasnt "
        "completely destroyed and looted.");
SetSmell("default","Something rotten or sour lingers here.");
SetExits( ([
        "east" : RUINS_ROOMS "dining",
        ]) );
SetClimate("indoors");
SetItems( ([ 
    ({ "kitchen","" }) : (: GetLong :),
    ({ "western wall","west wall" }) : "The western wall is "
    "somewhat barren. A flat stone wall which prevents travel "
    "and lacks any decor rests slightly aged.",
    ({ "eastern wall","east wall" }) : "The eastern wall is "
    "simplistic. It has been made of grey stone slabs which "
    "form the wall. A doorway has been crafted in the wall "
    "to allow access to a much larger room eastern in these "
    "ruins.",
    ({ "ceiling","roof" }) : "The ceiling is flat and has been "
    "built to lead two metal pipes from the furnaces to "
    "protrude to the outside. It has been built with grey "
    "stone cut slabs which have been sealed together to "
    "prevent anyone to enter through it.",
    ({ "floor","ground" }) : "It is littered with clumps of "
    "black dirt and soot. Two large furnaces sit on the floor "
    "near the north wall, directly south of it is an upside "
    "down table. Cabinets which also sit on the floor "
    "near the south wall remain open.",
     "furnace" : "The furnace has been made of a fine sturdy "
     "steel which has been coated with a dull black paint. "
     "A large rack rests on the inside covered in old food "
     "and grease. A large pipe forms from the top of the "
     "furnace and leads upward toward the ceiling into the "
     "unknown. An opening appears on the front.",
     "furnaces" : "Two large furnaces rest near the northern "
     "wall. They appear untouched despite their age. They differ "
     "from anything seen to cook modern food and appear archaic.",
     "pantry" : "Pantry cabinets rest on the floor near the southern "
     "wall. There are several sections accompanied by doors which "
     "have seen better times. Most of them are shattered and "
     "broken and few remain intact.",
     "cabinet" : "The cabinet is made of a light oak wood and stands "
     "roughly waist high on any average male human. Along the top of "
     "the cabinet is a flat top.",
     "cabinets" : "Several cabinets rest on the southern wall.",
     "table" : "The flipped table seems to have been placed here for "
     "utility at some time. The legs are missing and black dirt covers "
     "most of the exterior of this broken furniture.",
     "dirt" : "Black dirt covers this kitchen in a thin layer. It is "
     "evident that this soot had come from some creatures attempting "
     "to operate the furnace and leaving a big mess.",
     "stone" : "The gray stone has been fashioned in squares and "
     "have been fashioned to eachother to form the walls.",
     "doorway" : "A doorway which allows access to the a room "
     "to the east can be seen in the eastern wall.",
     "rack" : "The rack is made of a hard iron, some leftover "
     "grease and grime can be seen adhered to the surface.",
     "racks" : "Two iron racks can be seen inside the furnaces.",
     "steel" : "The steel has been painted black, it has been used "
     "to make the furnaces, the pipes and the iron racks.",
     "pipe" : "The pipe is wide enough to let large amounts of "
     "heat outside the ruins with ease. It is made of a black "
     "steel which leads up to the ceiling.",
     "pipes" : "Two solid pipes lead from the large furnace to the "
     "ceiling above. They have been painted black and have been "
     "sealed together to prevent smoke leakage.",
     "openings" : "The openings of the furnaces have been cut into "
     "the furnaces in a square shape. Racks which have been placed "
     "into the furnaces can be seen inside the opening.",
     "opening" : "The opening of the furnace is square and displays "
     "an easy access to the rack on the inside.",
     "top" : "The top of the cabinets are bare and some soot layers "
     "it.",
     "doors" : "Some cabinet doors remain, the others are broken "
     "and leave splinters of wood strewn about the floor.",
     "chute" : "The chute leads from the furnace out this kitchen.",
     "chutes" : "The chutes lead from the furnaces out this kitchen.",
    ]) );
}