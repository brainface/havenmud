#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;
inherit LIB_LISTEN;

static void create() {
   item::create();
   smell::create();
   touch::create();
   listen::create();
   SetKeyName("licorice");
   SetShort("a large piece of red licorice");
   SetId( ({ "piece","licorice" }) );
   SetAdjectives( ({ "large","piece","of","red" }) );
   SetLong("Delectably red and yummy, this piece of "
           "licorice is one of the biggest in all "
           "existence.  It radiates a feeling of deliciousness "
           "and yumminess.  It is Davantalus's birthday present.");
   SetTouch("The licorice is solid and real.  You aren't dreaming, "
            "after all!");
   SetSmell("Licorice doesnt have any distinctive sort of smell, "
            "but if I were to label the smell of this piece, it "
            "would be along the lines of 'tasty' and 'perfect'.");
   SetListen("You hear nothing.  This is good.  if you can hear "
             "your licorice, I'm worried about you, m'dear, and I "
             "certainly hope you wouldnt plan to eat it.");
}

void init() {
   ::init();
   add_action("eat","eat");
}

int eat(string args) {
   if(!args) return 0;
   if(args != "licorice") return 0;
   if(this_player()->GetKeyName() != "davantalus") {
      message("pie","You fool!  This is NOT your birthday present.  "
              "This is Davantalus's present.  Now, as soon as you "
              "get over dying because of trying to eat something "
              "that is VERY not yours, GIVE IT BACK TO HIM or "
              "you'll die AGAIN!  Got that?",this_player());
      if(this_player()->eventDie()) this_player()->eventDie(this_object());
      else {
         object who = this_player();
         object ob = new(LIB_CORPSE);
         ob->SetCorpse(who);
         ob->SetStrength(2000000);
         ob->SetRace("balrog");
         who->eventPrint("%^RED%^Oops.  You die.%^RESET%^");
         who->eventForce("title $N the undead immortal");
         ob->eventMove(environment(who));
         this_player()->eventPrint("Haha.  They died.");
         message("blah","%^RED%^" + who->GetCapName() + " dies."
                 "%^RESET%^",environment(who),({ who }));
         return 1;
      }
      return 1;
   }
   message("licorice","YUMMMM.  That was the Most Delicious and "
           "Wonderous licorice you've EVER tasted!  It makes you "
           "feel like jumping up and down and running around "
           "and hurraying and dancing and having loads of "
           "fun.  It's your birthday Dav!  Enjoy yourself!",
           this_player());
   message("licorice","Davantalus eats his super-duperly yummy birthday licorice.",
           environment(this_player()),this_player());
   message("licorice","%^BLUE%^The residue remaining on your hands and "
           "mouth (you're an awfully dirty eater, dav) grows "
           "into a new piece of licorice!  Wooooo!%^RESET%^",this_player());
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}

string GetListen(string str) {
   return listen::GetListen(str);
}
