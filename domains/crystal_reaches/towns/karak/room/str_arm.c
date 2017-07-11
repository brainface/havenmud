// Karak Rewrite
// Laoise
// 2007

#include "../karak.h"
#include <lib.h>
inherit LIB_STOREROOM;

static void create() {
  ::create();
  SetShort("Karak Armoury");
  SetInventory( ([
    KARAK_OBJ + "smallshield" : 2,
    KARAK_OBJ + "largeshield" : 2,   	
    KARAK_OBJ + "lwallshield" : 2,    	     	 	 	   
    KARAK_OBJ + "chainboots" : 1,     
    KARAK_OBJ + "chaincuisse" : 1, 
    KARAK_OBJ + "chaingauntlet" : 2, 
    KARAK_OBJ + "chainhelm" : 1,  	
    KARAK_OBJ + "chainvest" : 1,       	   	    	
    KARAK_OBJ + "hsteelboots" : 1,   
    KARAK_OBJ + "hsteelbreastplate" : 1,  
    KARAK_OBJ + "hsteelcuisse" : 1, 
    KARAK_OBJ + "hsteelgauntlet" : 2,     	   
    KARAK_OBJ + "hsteelhelm" : 1,          	
    KARAK_OBJ + "steelboots" : 1,
    KARAK_OBJ + "steelbreastplate" : 1,     	   
    KARAK_OBJ + "steelcuisse" : 1, 
    KARAK_OBJ + "steelgauntlet" : 2, 
    KARAK_OBJ + "steelhelm" : 1,
    KARAK_OBJ + "steelsuit" : 1,    	 	 	   
  ]) );
}
