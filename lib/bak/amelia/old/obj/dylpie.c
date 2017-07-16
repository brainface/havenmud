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
   SetKeyName("pie");
   SetShort("a huge slice of lemon meringue pie");
   SetId( ({ "slice","meringue","lemon","pie" }) );
   SetAdjectives( ({ "huge","slice of","slice","lemon","pie",
                     "meringue" }) );
   SetLong("Everything about this pie is perfect.  Even the "
           "normally soggy and gross crust is just right, "
           "perfectly complementing the lemon filling and "
           "meringue top.  It looks positively delectable.  "
           "It almost radiates a feeling of goodness and "
           "happiness and yumminess and wonderfulness.  "
           "It is Dylanthalus's birthday present.  Hey, "
           "wait, are you Dyl?  If you aren't, you shure "
           "better give it back to him.");
   SetTouch("The meringue is slightly stiff and sticky, "
            "with a white fuzziness of residue left on your "
            "finger.  The lemon filling smoth and soft, nicely "
            "chilled like it is supposed to be.  The crust is "
            "flakey and perfect like the rest.  Now hands "
            "off you!  This is for eating.  Unless you're "
            "Dylanthalus.  He's allowed.  It's his present.");
   SetSmell("Yummm!!!  Lemon sugar pie smells waft around your "
            "nose and make you drool with delight just thinking "
            "about it.  Just don't drool on the pie.  Dylanthalus "
            "drool soaks in, since only Dylanthalus can really "
            "eat it.  Non-dyl drool kinda dissolves.");
   SetListen("You hear nothing.  This is good.  If you can hear "
             "your pie, I'm worrying about you, m'dear, and "
             "I certainly hope you don't plan to eat it.");
}

void init() {
   ::init();
   add_action("eat","eat");
}

int eat(string args) {
   if(!args) return 0;
   if(args != "pie") return 0;
   if(this_player()->GetKeyName() != "dylanthalus") {
      message("pie","You fool!  This is NOT your birthday present.  "
              "This is Dylanthalus's present.  Now, as soon as you "
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
   message("pie","YUMMMM.  That was the Most Delicious and "
           "Wonderous pie you've EVER tasted!  It makes you "
           "feel like jumping up and down and running around "
           "and hurraying and dancing and having loads of "
           "fun.  It's your birthday Dyl!  Enjoy yourself!",
           this_player());
   message("pie","Dylanthalus eats his super-duperly yummy birthday pie.",
           environment(this_player()),this_player());
   message("pie","%^BLUE%^The little crumbs left on your hands and "
           "mouth (you're an awfully dirty eater, dyl) grow "
           "into a new slice!  Wooooo!%^RESET%^",this_player());
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}

string GetListen(string str) {
   return listen::GetListen(str);
}