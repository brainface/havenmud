#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("fuzzy's wiztoy<tm>");
   SetShort("Fuzzy's wiztoy<tm>");
   SetId( ({ "wiztoy<tm>","toy","wiztoy" }) );
   SetAdjectives( ({ "fuzzy's","wiz","toy" }) );
   SetLong("This is Fuzzy's wiztoy.  Fuzzy can do the following with "
           "it:  vis, invis, clone, goto, healme.");
   SetMass(1);
}

void init() {
   ::init();
   add_action("invis","invis");
   add_action("vis","vis");
   add_action("clone","clone");
   add_action("goto","goto");
   add_action("level","level");
   add_action("healme","healme");
}

int healme() {
   if(environment(this_object())->GetKeyName()!="fuzzy") {
      return 0;
   }
   return 0;
}

int level(int arg) {
   if(environment(this_object())->GetKeyName()!="fuzzy") {
      return 0;
   }
   find_living("fuzzy")->SetLevel(arg);
   return 1;
}

int goto(string arg) {
   if(environment(this_object())->GetKeyName()!="fuzzy") {
      return 0;
   }
   find_living("fuzzy")->eventMove(arg);
   return 1;
}

int clone(string arg) {
   object newitem;
   if(environment(this_object())->GetKeyName()!="fuzzy") {
      return 0;
   }
   if(!arg) return 0;
   newitem = new(arg);
   newitem->eventMove(find_living("fuzzy"));
   return 1;
}   

int vis() {
   if(environment(this_object())->GetKeyName()!="fuzzy") {
      return 0;
   }
   find_living("fuzzy")->SetInvis(0);
   return 0;
}

int invis() {
   if(environment(this_object())->GetKeyName()!="fuzzy") {
      return 0;
   }
   find_living("fuzzy")->SetInvis(1);
   return 1;
}
