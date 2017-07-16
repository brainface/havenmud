#include <lib.h>
#include <daemons.h>
inherit LIB_ITEM;   
inherit LIB_PRESS;  

void DoPress();

static void create() {
        item::create();  
        SetShort("a button of dzames fixing.");
        SetKeyName("button");             
        SetId( ({ "button" }) );          
        SetAdjectives( ({ "small", "silver" }) );
        SetLong("This is a small silver button. Press it.");
        SetPress("default", (: DoPress :) );                
        SetPreventGet("This button may unfuck dzames!");
        SetInvis(0);                                                    
}      

void DoPress() {
  object dzames = this_player();
  object dagger = all_inventory(dzames)[0];
  dzames->eventRemoveItem(dagger);
  dagger->SetWorn(0);
}
