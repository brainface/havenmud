

/* Created by Ohtar
 *  A simple Chest
 */

#include <lib.h>
#include "../sf.h"


inherit LIB_STORAGE;

static void create() {
    storage::create();
    SetKeyName("chest");
    SetId( ({ "chest" }) );
    SetAdjectives( ({ "wooden", "small"}) );
    SetShort("a small wooden chest");
    SetLong("The chest is a square wooden box with several bands of "
            "a metal substance wrapped around it. They come together "
            "in the front of the chest forming a rather solid looking "
            "lock. The top of the chest comes to a rounded point almost "
            "in the form of a tent. ");
    SetMass(450);
    SetCanClose(1);
    SetClosed(1);
    SetCanLock(1);      
    SetLocked(1);
    SetKey("pkey");
    SetInventory(([SF_OBJ + "/clothing/princess_dress" : 1,
                   SF_OBJ + "/armour/princess_shoe" : 1,
                ]));    
    SetPreventGet("It is bolted solidly in place!");
    SetMaxCarry(1500);
}


