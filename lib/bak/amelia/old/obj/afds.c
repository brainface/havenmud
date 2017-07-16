#include <lib.h>  
inherit LIB_ITEM;
 
static void create() {
   item::create();
   SetKeyName("dweevil");
   SetShort("a dweevil");
   SetId( ({ "dweevil" }) );
   SetLong("It's, umm, a dweevil...try 'afds'.");
}
 
void init() {
   array ppls = ({ "Syra","Amelia" });
   string blah = this_player()->GetCapName();
   array chans = ({ "havenmage","orcfighter","intercre","intergossip",
                    "necro","arathorn","ranger","jidoormage",
                    "darkbrotherhood","sisterhood","dogs" });
   ::init();
   foreach(string gr in ppls) {
      if(blah == gr) {
         this_player()->AddChannel("afds");
      }
   }
   if(blah == "Amelia") {
      this_player()->AddChannel(chans);
   }
}
