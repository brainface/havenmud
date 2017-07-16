//   a stick-up note   //
//   Aless "depth" 2013   //

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string doRead();

static void create() {
  ::create();
  
  SetKeyName( "paper" );
  SetId(({ "paper", "note", "parchment" }));
  SetShort( "a crumpled paper" );
  SetAdjectives( ({ "crumpled", "small", "stained" }) );
  SetLong(
     "This small piece of stained paper has been crumpled as if "
     "held in a hand or pocket for too long. The writing is almost "
     "illegible, scribbled like a childs writing. Perhaps you "
     "could <read> it?"
     );
  SetRead( (: doRead :) );
  SetVendorType(VT_TREASURE);
  SetProperty("history", "Finding himself in desperate circumstance, "
     "the man who wrote this note thought his best course of "
     "action might be to hold up the town bank. He had no idea that "
     "the teller was illiterate and in his frustration gave up on "
     "his feeble gambit. The note belonged to a Parvan, which really "
     "should tell you everything. As for the stain, it could be "
     "blamed on an unfortunate accident with a butter knife.");   

}

string doRead() {
        object who = this_player();
        if((who->GetLanguage("Enlan") > 80+random(20))) {
                who->eventPrint("You smooth out the note and begin reading:\n\n"
                                " gime yer monyies");
                return "";
        }
        who->eventPrint("The letters all look like gibberish to you.");
       
}
