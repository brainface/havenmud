/* This is the twenty-second room of the beach coded by Lynna on  
        January 28, 1998 
*/ 
 
#include <lib.h> 
#include "../beach.h" 
inherit LIB_ROOM; 
static void create() { 
        room::create(); 
        SetShort("the trees of the woods"); 
        SetInventory( ([ 
                BEACH_NPC + "squirrel" : 1, 
                "/std/obj/tai_portal" :1, 
                ]) ); 
        SetSmell( ([ "default" : "The smell of dirt and leaves is strong " 
                                 "here." ]) ); 
        SetListen( ([ "default" : "The sea sounds can be heard softly in " 
                                  "the distance." ]) ); 
        SetLong( "The path that trails along the beach lies to the east. " 
                 "The trees here are tall and shade the entire area, with " 
                 "very little visible light being seen from above. Going " 
                 "towards the west, more of the woods are found." ); 
        SetItems( ([ 
                ( { "trees", "tree", "woods" } ) : "These are the tall shady " 
                                                   "trees of the HavenWood.", 
                ( { "dirt", "leaves", "leaf" } ) : "The dirt and leaves " 
                                                   "cover this path.", 
                ]) ); 
        SetClimate("temperate"); 
        SetExits( ([ 
                "east"        :  BEACH_ROOM "beach17", 
                "south"       :  BEACH_ROOM "beach21", 
                "southwest"   :  BEACH_ROOM "beach23" 
                ]) ); 
} 
 
