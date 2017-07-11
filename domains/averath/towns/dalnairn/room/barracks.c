// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("inside the Dalnairn barracks");
  SetLong(
    "The interior of the barracks is simple, with practicality favored above "
    "looks. To one side is a row of bunks where the off-duty guards sleep. In "
    "the center of the barracks is an open training area, with crude wooden "
    "training dummies positioned throughout which the members of the guard "
    "frequently practice their weapon skills against."    
  );
  SetItems( ([
  ({ "interior", "barracks" }) : (: GetLong :),
  ({ "bunks", "row" }) : 
    "The bunks are neatly made, each with a single pillow and a warm cotton "
    "blanket.",
  ({ "area", "center" }) :
    "The training area in the center of the barracks is home to some training "
    "dummies which the guards practice with frequently.",
  ({ "dummies" }) : 
    "The wooden training dummies are made to resemble a human form. They are "
    "all chipped and scored by years of contact with various weapons.",  
  ]) );
  SetItemAdjectives( ([
    "bunks" : ({ "row", "of" }),
    "area" : ({ "training", "open" }),
    "dummies" : ({ "wooden", "training" }),    
  ]) );
  SetInventory( ([
    DAL_NPC "guard" : 4,
    DAL_NPC "jolich" : 1,  
    DAL_NPC "combat_trainer" : 1, 
  ]) );
  SetListen( ([
    "default" : "The sound of weapons bashing against wood comes from the "
      "dummies as the guards train.",
  ]) );
  SetSmell( ([
    "default" : "The barracks noticeably smell of sweat.",
  ]) );
  SetExits( ([    
    "out" : DAL_ROOM "road3",      
  ]) );   
}
