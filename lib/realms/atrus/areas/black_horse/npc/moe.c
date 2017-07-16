/* moe.c for Black Horse Inn
   Atrus@Haven
   19MAY2013
*/

#include <lib.h> 
#include <std.h>
#include "../bhi.h"
#include <vendor_types.h>
inherit LIB_OLD_VENDOR;

static void create() {
    ::create();
    SetKeyName("maurice");
    SetShort("Maurice a tenant of the Black Horse Inn");
    SetId( ({ "maurice", "tenant", "moe" }) );
    SetAdjectives( ({ "maurice", "tenant", "moe" }) );
    SetLong(
       "Maurice spends most of his time sitting down as an old war wound took "
       "the use of both of his legs. His spirit is still young and full of "
       "life though, and he never hesitates to help if he is able. His arms are "
       "powerfully built with creased muscles, though his legs are thin and "
       "frail. His eyes are bloodshot and mildly squinted. His hair is neatly "
       "brushed and pulled back into a pony tail."
       );
    SetRace("wild-elf");
    SetGender("male");
    SetClass("nightreveller");
    SetReligion("Eclat");
    SetLevel(random(15) + 60);
    SetCurrency("imperials", random(100) + 25);
    SetInventory( ([
         BHI_OBJ "bl_shirt" : "wear shirt",
         BHI_OBJ "sock" : 2,         
         BHI_OBJ "bl_pants" : "wear pants",
         BHI_OBJ "bl_hat" : "wear hat",
         BHI_OBJ "cane" : "wield cane",
      ]) ); 

    SetMorality(2000);

    SetSongBook( ([
            "aural shield" : 100,
            "aria of ice"  : 100,
            "melodic allure" : 100,
            "magical lullaby" : 100,
            "tavernsong" : 100,
            "aria of midnight" : 100,
       ]) );
    
    SetSpellBook( ([
            "embodiment of wind" : 100,
            "create natural herbs" : 100,
       ]) );
    

    SetAction(random(3) + 2, ({ 
            "!smile",
            "!emote looks longingly out the window.",
            "!speak Do you need my help?",
            "!cast create natural herbs",
            "!sing aural shield",
            "!sing magical lullaby",
            "!sing melodic allure",
            "!sing tavernsong",
            "!light a sprig",
            "!smoke a sprig",
            "!cast embodiment of wind",
            "!sing aria of midnight",
            "!yell No!",
            "!speak you can call me Moe if you'd like.",
            "!speak It was an axe... Damned orc. I got him though, threw a "
            "spear from the ground and hit him in the face.",
            "!speak I spent hours screaming and blacking out from the pain "
            "after I got hit with that axe. Missed most of the battle...",
            "!speak I kept waking up... In a field of bodies.",
            "!sigh",
       }) );

    SetCombatAction(20, ({ 
            "!sing aria of midnight",
            "!sing aria of ice",
            "!cast embodiment of wind",
            "!get all from cane",
            "!wield epee",
       }) );
  SetFirstCommands( ({ "wear a sock on left foot", 
                       "wear a sock on right foot",
       }) );
  SetVendorType(VT_ALL);
  SetLocalCurrency("shrydes");
  SetStorageRoom(BHI_ROOM "moe_store");
  SetMaxSingleItem(5);
  SetMaxItems(15);
}
