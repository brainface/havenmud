// Headquarters for the Invasions of Kailie
// Urien@Haven 13

#include <lib.h>
#include <daemons.h>
#include "../invas.h"

#define WIZDIR  "/domains/staff/"

#define MEAT_GRINDER      INVAS_NPC "meat_grinder"
#define HAVEN_PIRATES     INVAS_NPC "haven_pirates"
#define HAVEN_DEMON       INVAS_NPC "haven_demon"
#define HAVEN_UNDEAD      INVAS_NPC "haven_undead"
#define JIDOOR_LIZARDMEN  INVAS_NPC "jidoor_lizardmen"
#define JIDOOR_ORC        INVAS_NPC "jidoor_orc"
#define JIDOOR_TEMPLAR    INVAS_NPC "jidoor_templar"
#define LLORYK_LIZARDMEN  INVAS_NPC "lloryk_lizardmen"
#define PARVA_BANDIT      INVAS_NPC "parva_bandit"
#define PARVA_PIRATE      INVAS_NPC "parva_pirate"
#define PARVA_TEMPLAR     INVAS_NPC "parva_templar"
#define PARVA_UNDEAD      INVAS_NPC "parva_undead"
#define SANCTUM_BANDIT    INVAS_NPC "sanctum_bandit"
#define SOLEIL_DEMON      INVAS_NPC "soleil_demon"
#define SOLEIL_GOBLIN     INVAS_NPC "soleil_goblin"
#define SOLEIL_OGRE       INVAS_NPC "soleil_ogre"
#define TAIRI_NINJA       INVAS_NPC "tairi_ninja"

 
inherit LIB_ROOM; 

static void create() {
::create();
SetShort("a square foyer covered in blood");
SetLong("\n"
        "    * Read Sign for Instructions *               \n"
        " * Read Manual for Invasion Listing *            \n"
        "                                                 \n"
        "All of what lies in this square foyer is complete carnage. "
        "Small pieces of flesh lay in pools of blood which cover "
        "the floor and have spattered a majority of the ceiling. An "
        "open chute juts out from the ceiling, leading off into the "
        "unknown. An obvious gateway leads out into the Immortal "
        "realm." 
        );
 SetInventory( ([ INVAS_NPC "meat_grinder" : 1,
                  INVAS_OBJ "manual" : 1,
                  ]) );
 SetExits( ([
     "out" : WIZDIR "staffroom",
              ]) );
 SetListen("default","The buzzing noise from the grinder is astounding.");
 SetSmell("default","It smells of fresh cut rotten flesh, blood and sinew.");
 SetClimate("indoors");
 SetAmbientLight(30);
 SetItems( ([ 
    ({ "room","square room" }) : (: GetLong :),
    ({ "walls","wall" }) : "All covered in black and red chunky blood.",
    ({ "ground","floor" }) : "It is covered in intestines, blood, bone "
                             "and flesh.",
    "ceiling" : "It is covered in a range of black to red blood. An "
                "open chute rests directly in the center.",
    "blood" : "The blood covers everything in sight.",
    "flesh" : "Flesh of unknown beasts lie everywhere.",
    "bone" : "Bone pieces rest on the floor freshly dripping.",
    "chute" : "The chute is metal and leads in from the unknown.",
    "sign"  : "There is a sign with words written on it.",
    "exit" : "An exit leads north, into the Immortal realm.",    
    ]) );
 SetRead( ([
    "sign" : "Please read the Manual for target names: \n"
             "summon <host town> <invader>\n"           
             " Ex. summon haven pirates\n"
             "     default is the meat grinder.",
    ]) ); 
 SetItemAdjectives( ([
    "blood" : ({ "black","red","chunky" }),
    "chute" : ({ "open" }),
    ]) );
}
void init() {
  ::init();  
  add_action("summon", "summon");
}
//Enables the 'summon' command in this room only
int summon(string args) {
   object thing;
  if (!args) args = MEAT_GRINDER;
  if (args == "haven pirate") args = HAVEN_PIRATES;
  if (args == "haven demon") args = HAVEN_DEMON;
  if (args == "haven undead") args = HAVEN_UNDEAD;
  if (args == "jidoor lizardmen") args = JIDOOR_LIZARDMEN;
  if (args == "jidoor orc") args = JIDOOR_ORC;
  if (args == "jidoor templar") args = JIDOOR_TEMPLAR;
  if (args == "lloryk lizardmen") args = LLORYK_LIZARDMEN;
  if (args == "parva bandit") args = PARVA_BANDIT;
  if (args == "parva pirate") args = PARVA_PIRATE;
  if (args == "parva templar") args = PARVA_TEMPLAR;
  if (args == "parva undead") args = PARVA_UNDEAD;
  if (args == "sanctum bandit") args = SANCTUM_BANDIT;
  if (args == "soleil demon") args = SOLEIL_DEMON;
  if (args == "soleil goblin") args = SOLEIL_GOBLIN;
  if (args == "soleil ogre") args = SOLEIL_OGRE;
  if (args == "tairi ninja") args = TAIRI_NINJA;
  thing = new(args);
  if (!thing) {
     this_player()->eventPrint("Read the Manual for targets.");
     return 1;
   }
  eventPrint("A weary humanoid body falls from the chute.");
  thing->eventMove(this_object());
  thing->eventForce("speak By your will!");
  return 1;
}
/*
int CanReceive(object ob) {
  if (!musep(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
*/
