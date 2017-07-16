#include <lib.h>
#include "../argoth.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("Argoth Town Hall");
    SetLong("This room is the lobby of the Argoth Town Hall.  The floor and "
    
    "walls are made of the same black marble that the other buildings in the "
    "town are made out of, and there are some dark brown leather chairs "
    "for people who are waiting to see the mayor to sit in.");
  SetDomain("Crystal Reaches");
    SetItems( ([
    ({ "floor", "walls", "marble", "black marble" }) :
    "The floor and walls are made of a shiny black marble.",
    ({ "dark brown leather chairs", "leather chairs", "chairs", "chair" }) :
    "The chairs are soft and comfortable, and quite shiny.",
    ({ "office", "mayor's office" }) :
    "The mayor's office lies to the east",
]) );
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd7.c",
    "east" : ARGOTH_ROOM + "mayor_office.c",
]) );
    SetSmell( ([ 
    "default" : "There is a strong odor of leather polish.",
]) );
    SetListen( ([
]) );
    SetInventory( ([
    ARGOTH_NPC + "guard.c" : 1,
    ARGOTH_OBJ + "poster.c" : 1,
    ARGOTH_NPC + "merchant_leader.c" : 1,
]) );
    SetClimate("indoors");
    SetAmbientLight(45);
}
