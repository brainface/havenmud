// Aerelus
#include <lib.h>
#include <domains.h>
#include "../averath.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("in the tower in the Church of Aetarin");
  SetLong(
    "Here, at the top of the tower in the church, is the home of the Duke. "
    "Church and state matters are, for the most part, the same thing in "
    "Averath, so it is by tradition that this tower serves as both his home "
    "and office. A large oak desk rests against the eastern wall, almost "
    "entirely covered with papers, while a huge comfortable-looking bed lies "
    "directly opposite."
  );
  SetItems( ([
    ({ "tower", "home" }) : (: GetLong :),
    ({ "desk" }) : "This large desk, made of polished oak, is where the Duke "
      "does most of his work. It is almost entirely covered with papers.",
    ({ "papers" }) : "These papers are scattered all over the Duke's desk. "
      "None of them look like they could be of any interest.",
    ({ "bed" }) : "This huge bed looks very comfortable, almost fit for a "
      "Duke.",
  ]) );
  SetItemAdjectives( ([
    "desk" : ({ "large", "oak" }),    
    "bed" : ({ "huge", "comfortable", "comfortable-looking" }),
  ]) );
  SetInventory( ([
    AVERATH_NPC "duke" : 1,
    AVERATH_NPC "guard" : 1,
    AVERATH_NPC "mayor" : 1,
 // AVERATH_NPC "juego_trainer" : 1,
  ]) );
  SetListen( ([
     "default" : "Sounds of general worship come from beneath the tower.",
  ]) );
  SetSmell( ([
     "default" : "The room smells sweet, as if someone has been burning "
       "incense.",
  ]) );  
  SetExits( ([    
    "down" : AVERATH_ROOM "church",    
  ]) );    
}
